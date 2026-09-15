/*
  Project 16 - ESP32 Wireless Robot Remote Controller Using ESP-NOW
  ESP32 2: Robot Receiver
  Receives joystick data and drives four DC motors through two L298N modules.
  ENA and ENB jumpers remain fitted, so this version uses full-speed control.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PACKET_MAGIC = 0x16001600;

const int LEFT_IN1 = 25;
const int LEFT_IN2 = 26;
const int RIGHT_IN1 = 27;
const int RIGHT_IN2 = 14;

const int JOYSTICK_CENTER = 2048;
const int JOYSTICK_DEAD_ZONE = 500;
const unsigned long FAILSAFE_MS = 500;

struct JoystickPacket {
  uint32_t magic;
  uint16_t x;
  uint16_t y;
  uint32_t sequence;
};

portMUX_TYPE packetMux = portMUX_INITIALIZER_UNLOCKED;
JoystickPacket latestPacket;
volatile bool packetAvailable = false;
volatile unsigned long lastPacketTime = 0;

void stopRobot() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}

void moveForward() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void moveBackward() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void turnLeft() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void turnRight() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(JoystickPacket)) {
    return;
  }

  JoystickPacket incoming;
  memcpy(&incoming, data, sizeof(incoming));

  if (incoming.magic != PACKET_MAGIC) {
    return;
  }

  portENTER_CRITICAL(&packetMux);
  latestPacket = incoming;
  packetAvailable = true;
  lastPacketTime = millis();
  portEXIT_CRITICAL(&packetMux);
}

bool startEspNow() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  if (esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE) != ESP_OK) {
    return false;
  }

  if (esp_now_init() != ESP_OK) {
    return false;
  }

  return esp_now_register_recv_cb(onReceive) == ESP_OK;
}

void setup() {
  Serial.begin(115200);

  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);
  stopRobot();

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      stopRobot();
      delay(1000);
    }
  }
}

void loop() {
  JoystickPacket packet;
  bool hasPacket = false;
  unsigned long packetTime = 0;

  portENTER_CRITICAL(&packetMux);
  if (packetAvailable) {
    packet = latestPacket;
    packetAvailable = false;
    hasPacket = true;
  }
  packetTime = lastPacketTime;
  portEXIT_CRITICAL(&packetMux);

  if (millis() - packetTime > FAILSAFE_MS) {
    stopRobot();
    delay(10);
    return;
  }

  if (!hasPacket) {
    delay(5);
    return;
  }

  const int xOffset = static_cast<int>(packet.x) - JOYSTICK_CENTER;
  const int yOffset = static_cast<int>(packet.y) - JOYSTICK_CENTER;

  if (abs(yOffset) > abs(xOffset) && abs(yOffset) > JOYSTICK_DEAD_ZONE) {
    if (yOffset > 0) {
      moveForward();
    } else {
      moveBackward();
    }
  } else if (abs(xOffset) > JOYSTICK_DEAD_ZONE) {
    if (xOffset > 0) {
      turnRight();
    } else {
      turnLeft();
    }
  } else {
    stopRobot();
  }
}
