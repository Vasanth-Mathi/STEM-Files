/*
  Project 31 - ESP32 ESP-NOW Remote-Controlled-Drone - Quadcopter
  ESP32 2: Flight Receiver / Controller

  Receives commands from the remote, reads an MPU6050 IMU and mixes four
  PWM outputs for four brushed motors driven through MOSFET driver stages.

  Target: Arduino-ESP32 3.x

  IMPORTANT:
  - Never connect motors directly to ESP32 GPIO pins.
  - Test with propellers removed first.
  - PID values and motor directions require careful real-frame tuning.
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <Wire.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PACKET_MAGIC = 0x44524F4E;

const int MOTOR_1_PIN = 13;
const int MOTOR_2_PIN = 14;
const int MOTOR_3_PIN = 25;
const int MOTOR_4_PIN = 26;

const int SDA_PIN = 21;
const int SCL_PIN = 22;
const uint8_t MPU6050_ADDRESS = 0x68;

const uint32_t MOTOR_PWM_FREQUENCY = 20000;
const uint8_t MOTOR_PWM_RESOLUTION = 8;

const unsigned long FAILSAFE_MS = 350;
const uint8_t ARM_MAX_THROTTLE = 20;
const uint8_t MOTOR_START_THROTTLE = 25;
const uint8_t MAX_BASE_THROTTLE = 220;

const float MAX_TILT_ANGLE_DEG = 20.0f;
const float MAX_YAW_RATE_DPS = 90.0f;
const float COMPLEMENTARY_GYRO_WEIGHT = 0.98f;

const float ROLL_KP = 3.2f;
const float ROLL_KI = 0.02f;
const float ROLL_KD = 1.25f;
const float PITCH_KP = 3.2f;
const float PITCH_KI = 0.02f;
const float PITCH_KD = 1.25f;
const float YAW_RATE_KP = 0.8f;
const float MAX_PID_CORRECTION = 70.0f;
const float MAX_INTEGRAL = 80.0f;

struct ControlPacket {
  uint32_t magic;
  uint8_t throttle;
  int8_t roll;
  int8_t pitch;
  int8_t yaw;
  bool armed;
  uint32_t sequence;
};

portMUX_TYPE commandMux = portMUX_INITIALIZER_UNLOCKED;
ControlPacket latestCommand = {};
volatile unsigned long lastCommandTime = 0;

float gyroOffsetX = 0.0f;
float gyroOffsetY = 0.0f;
float gyroOffsetZ = 0.0f;
float rollAngle = 0.0f;
float pitchAngle = 0.0f;
float rollIntegral = 0.0f;
float pitchIntegral = 0.0f;
bool flightArmed = false;
unsigned long previousLoopMicros = 0;

bool writeMpuRegister(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(reg);
  Wire.write(value);
  return Wire.endTransmission(true) == 0;
}

bool readMpuRaw(int16_t& ax, int16_t& ay, int16_t& az, int16_t& gx, int16_t& gy, int16_t& gz) {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x3B);
  if (Wire.endTransmission(false) != 0) return false;

  const int received = Wire.requestFrom(static_cast<int>(MPU6050_ADDRESS), 14, true);
  if (received != 14) return false;

  ax = (Wire.read() << 8) | Wire.read();
  ay = (Wire.read() << 8) | Wire.read();
  az = (Wire.read() << 8) | Wire.read();
  Wire.read();
  Wire.read();
  gx = (Wire.read() << 8) | Wire.read();
  gy = (Wire.read() << 8) | Wire.read();
  gz = (Wire.read() << 8) | Wire.read();
  return true;
}

bool initializeMpu6050() {
  Wire.begin(SDA_PIN, SCL_PIN);
  delay(100);
  if (!writeMpuRegister(0x6B, 0x00)) return false;
  if (!writeMpuRegister(0x1A, 0x03)) return false;
  if (!writeMpuRegister(0x1B, 0x00)) return false;
  if (!writeMpuRegister(0x1C, 0x00)) return false;
  return true;
}

bool calibrateGyroscope() {
  const int sampleCount = 1000;
  int validSamples = 0;
  double sumX = 0.0;
  double sumY = 0.0;
  double sumZ = 0.0;

  Serial.println("Keep the drone completely still for gyro calibration.");

  for (int i = 0; i < sampleCount; i++) {
    int16_t ax, ay, az, gx, gy, gz;
    if (readMpuRaw(ax, ay, az, gx, gy, gz)) {
      sumX += gx;
      sumY += gy;
      sumZ += gz;
      validSamples++;
    }
    delay(2);
  }

  if (validSamples < sampleCount * 0.9f) return false;

  gyroOffsetX = sumX / validSamples;
  gyroOffsetY = sumY / validSamples;
  gyroOffsetZ = sumZ / validSamples;

  int16_t ax, ay, az, gx, gy, gz;
  if (!readMpuRaw(ax, ay, az, gx, gy, gz)) return false;

  rollAngle = atan2f(static_cast<float>(ay), static_cast<float>(az)) * RAD_TO_DEG;
  pitchAngle = atan2f(-static_cast<float>(ax), sqrtf(static_cast<float>(ay) * ay + static_cast<float>(az) * az)) * RAD_TO_DEG;
  return true;
}

bool initializeMotorPwm() {
  const bool m1 = ledcAttach(MOTOR_1_PIN, MOTOR_PWM_FREQUENCY, MOTOR_PWM_RESOLUTION);
  const bool m2 = ledcAttach(MOTOR_2_PIN, MOTOR_PWM_FREQUENCY, MOTOR_PWM_RESOLUTION);
  const bool m3 = ledcAttach(MOTOR_3_PIN, MOTOR_PWM_FREQUENCY, MOTOR_PWM_RESOLUTION);
  const bool m4 = ledcAttach(MOTOR_4_PIN, MOTOR_PWM_FREQUENCY, MOTOR_PWM_RESOLUTION);
  return m1 && m2 && m3 && m4;
}

void setMotor(int pin, float value) {
  const uint32_t duty = static_cast<uint32_t>(constrain(value, 0.0f, 255.0f));
  ledcWrite(pin, duty);
}

void stopAllMotors() {
  ledcWrite(MOTOR_1_PIN, 0);
  ledcWrite(MOTOR_2_PIN, 0);
  ledcWrite(MOTOR_3_PIN, 0);
  ledcWrite(MOTOR_4_PIN, 0);
}

void resetControllerState() {
  rollIntegral = 0.0f;
  pitchIntegral = 0.0f;
}

void disarmDrone() {
  flightArmed = false;
  resetControllerState();
  stopAllMotors();
}

void onReceive(const esp_now_recv_info_t* info, const uint8_t* data, int length) {
  if (length != sizeof(ControlPacket)) return;
  ControlPacket incoming;
  memcpy(&incoming, data, sizeof(incoming));
  if (incoming.magic != PACKET_MAGIC) return;

  portENTER_CRITICAL(&commandMux);
  latestCommand = incoming;
  lastCommandTime = millis();
  portEXIT_CRITICAL(&commandMux);
}

bool startEspNow() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  if (esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE) != ESP_OK) return false;
  if (esp_now_init() != ESP_OK) return false;
  return esp_now_register_recv_cb(onReceive) == ESP_OK;
}

void setup() {
  Serial.begin(115200);

  if (!initializeMotorPwm()) {
    Serial.println("Motor PWM setup failed.");
    while (true) delay(1000);
  }
  stopAllMotors();

  if (!initializeMpu6050()) {
    Serial.println("MPU6050 initialization failed.");
    while (true) { stopAllMotors(); delay(1000); }
  }

  if (!calibrateGyroscope()) {
    Serial.println("MPU6050 calibration failed.");
    while (true) { stopAllMotors(); delay(1000); }
  }

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) { stopAllMotors(); delay(1000); }
  }

  previousLoopMicros = micros();
  Serial.print("Drone receiver MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.println("Flight controller ready. Keep propellers removed for first tests.");
}

void loop() {
  const unsigned long nowMicros = micros();
  if (nowMicros - previousLoopMicros < 4000) {
    delayMicroseconds(200);
    return;
  }

  float dt = (nowMicros - previousLoopMicros) / 1000000.0f;
  previousLoopMicros = nowMicros;
  dt = constrain(dt, 0.001f, 0.02f);

  ControlPacket command;
  unsigned long commandTime = 0;
  portENTER_CRITICAL(&commandMux);
  command = latestCommand;
  commandTime = lastCommandTime;
  portEXIT_CRITICAL(&commandMux);

  if (commandTime == 0 || millis() - commandTime > FAILSAFE_MS) {
    disarmDrone();
    return;
  }
  if (!command.armed) {
    disarmDrone();
    return;
  }
  if (!flightArmed) {
    if (command.throttle > ARM_MAX_THROTTLE) {
      stopAllMotors();
      return;
    }
    flightArmed = true;
    resetControllerState();
    Serial.println("Drone armed.");
  }

  int16_t axRaw, ayRaw, azRaw, gxRaw, gyRaw, gzRaw;
  if (!readMpuRaw(axRaw, ayRaw, azRaw, gxRaw, gyRaw, gzRaw)) {
    disarmDrone();
    Serial.println("IMU read failed. Drone disarmed.");
    return;
  }

  const float ax = axRaw / 16384.0f;
  const float ay = ayRaw / 16384.0f;
  const float az = azRaw / 16384.0f;
  const float gx = (gxRaw - gyroOffsetX) / 131.0f;
  const float gy = (gyRaw - gyroOffsetY) / 131.0f;
  const float gz = (gzRaw - gyroOffsetZ) / 131.0f;

  const float accelRoll = atan2f(ay, az) * RAD_TO_DEG;
  const float accelPitch = atan2f(-ax, sqrtf(ay * ay + az * az)) * RAD_TO_DEG;
  rollAngle = COMPLEMENTARY_GYRO_WEIGHT * (rollAngle + gx * dt) + (1.0f - COMPLEMENTARY_GYRO_WEIGHT) * accelRoll;
  pitchAngle = COMPLEMENTARY_GYRO_WEIGHT * (pitchAngle + gy * dt) + (1.0f - COMPLEMENTARY_GYRO_WEIGHT) * accelPitch;

  if (command.throttle <= MOTOR_START_THROTTLE) {
    stopAllMotors();
    resetControllerState();
    return;
  }

  const float targetRoll = command.roll * MAX_TILT_ANGLE_DEG / 100.0f;
  const float targetPitch = command.pitch * MAX_TILT_ANGLE_DEG / 100.0f;
  const float targetYawRate = command.yaw * MAX_YAW_RATE_DPS / 100.0f;
  const float rollError = targetRoll - rollAngle;
  const float pitchError = targetPitch - pitchAngle;
  const float yawRateError = targetYawRate - gz;

  rollIntegral += rollError * dt;
  pitchIntegral += pitchError * dt;
  rollIntegral = constrain(rollIntegral, -MAX_INTEGRAL, MAX_INTEGRAL);
  pitchIntegral = constrain(pitchIntegral, -MAX_INTEGRAL, MAX_INTEGRAL);

  float rollCorrection = ROLL_KP * rollError + ROLL_KI * rollIntegral - ROLL_KD * gx;
  float pitchCorrection = PITCH_KP * pitchError + PITCH_KI * pitchIntegral - PITCH_KD * gy;
  float yawCorrection = YAW_RATE_KP * yawRateError;

  rollCorrection = constrain(rollCorrection, -MAX_PID_CORRECTION, MAX_PID_CORRECTION);
  pitchCorrection = constrain(pitchCorrection, -MAX_PID_CORRECTION, MAX_PID_CORRECTION);
  yawCorrection = constrain(yawCorrection, -MAX_PID_CORRECTION, MAX_PID_CORRECTION);

  const float baseThrottle = constrain(static_cast<float>(command.throttle), 0.0f, static_cast<float>(MAX_BASE_THROTTLE));

  const float motor1 = baseThrottle + pitchCorrection + rollCorrection - yawCorrection;
  const float motor2 = baseThrottle + pitchCorrection - rollCorrection + yawCorrection;
  const float motor3 = baseThrottle - pitchCorrection - rollCorrection - yawCorrection;
  const float motor4 = baseThrottle - pitchCorrection + rollCorrection + yawCorrection;

  setMotor(MOTOR_1_PIN, motor1);
  setMotor(MOTOR_2_PIN, motor2);
  setMotor(MOTOR_3_PIN, motor3);
  setMotor(MOTOR_4_PIN, motor4);
}
