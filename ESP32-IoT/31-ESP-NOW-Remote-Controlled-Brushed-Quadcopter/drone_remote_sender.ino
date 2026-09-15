/*
  Project 31 - ESP32 ESP-NOW Remote Controlled Brushed-Motor Quadcopter
  ESP32 1: Handheld Remote Sender

  Controls throttle, roll, pitch and yaw with two joysticks.
  The arm button toggles the armed state only when throttle is low.
  Target: Arduino-ESP32 3.x

  IMPORTANT:
  - Use ADC1 pins for joystick inputs because ESP-NOW uses Wi-Fi hardware.
  - Test the complete system with propellers removed first.
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint8_t BROADCAST_ADDRESS[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
const uint32_t PACKET_MAGIC = 0x44524F4E;

const int THROTTLE_PIN = 34;
const int YAW_PIN = 35;
const int PITCH_PIN = 32;
const int ROLL_PIN = 33;
const int ARM_BUTTON_PIN = 25;

const int ADC_CENTER = 2048;
const int AXIS_DEAD_ZONE = 120;
const uint8_t ARM_MAX_THROTTLE = 20;
const unsigned long SEND_INTERVAL_MS = 20;
const unsigned long BUTTON_DEBOUNCE_MS = 50;

const bool REVERSE_THROTTLE = false;
const bool REVERSE_ROLL = false;
const bool REVERSE_PITCH = true;
const bool REVERSE_YAW = false;

struct ControlPacket {
  uint32_t magic;
  uint8_t throttle;
  int8_t roll;
  int8_t pitch;
  int8_t yaw;
  bool armed;
  uint32_t sequence;
};

bool armed = false;
bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;
unsigned long lastButtonChange = 0;
unsigned long lastSendTime = 0;
uint32_t sequenceNumber = 0;

int8_t readCenteredAxis(int pin, bool reverseDirection) {
  const int raw = analogRead(pin);
  int offset = raw - ADC_CENTER;

  if (abs(offset) <= AXIS_DEAD_ZONE) {
    return 0;
  }

  offset = constrain(offset, -ADC_CENTER, 4095 - ADC_CENTER);

  int value;
  if (offset < 0) {
    value = map(offset, -ADC_CENTER, -AXIS_DEAD_ZONE, -100, 0);
  } else {
    value = map(offset, AXIS_DEAD_ZONE, 4095 - ADC_CENTER, 0, 100);
  }

  value = constrain(value, -100, 100);

  if (reverseDirection) {
    value = -value;
  }

  return static_cast<int8_t>(value);
}

uint8_t readThrottle() {
  int raw = analogRead(THROTTLE_PIN);

  if (REVERSE_THROTTLE) {
    raw = 4095 - raw;
  }

  const int value = map(raw, 0, 4095, 0, 255);
  return static_cast<uint8_t>(constrain(value, 0, 255));
}

bool addBroadcastPeer() {
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, BROADCAST_ADDRESS, 6);
  peerInfo.channel = ESPNOW_CHANNEL;
  peerInfo.ifidx = WIFI_IF_STA;
  peerInfo.encrypt = false;

  if (esp_now_is_peer_exist(BROADCAST_ADDRESS)) {
    return true;
  }

  return esp_now_add_peer(&peerInfo) == ESP_OK;
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

  return addBroadcastPeer();
}

void updateArmButton(uint8_t throttle) {
  const bool reading = digitalRead(ARM_BUTTON_PIN);

  if (reading != lastButtonReading) {
    lastButtonChange = millis();
    lastButtonReading = reading;
  }

  if (millis() - lastButtonChange < BUTTON_DEBOUNCE_MS) {
    return;
  }

  if (reading == stableButtonState) {
    return;
  }

  stableButtonState = reading;

  if (stableButtonState != LOW) {
    return;
  }

  if (armed) {
    armed = false;
    Serial.println("Remote disarmed.");
    return;
  }

  if (throttle <= ARM_MAX_THROTTLE) {
    armed = true;
    Serial.println("Remote armed.");
  } else {
    Serial.println("Lower throttle before arming.");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ARM_BUTTON_PIN, INPUT_PULLUP);
  analogReadResolution(12);

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      delay(1000);
    }
  }

  Serial.print("Remote MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  const uint8_t throttle = readThrottle();
  updateArmButton(throttle);

  if (millis() - lastSendTime < SEND_INTERVAL_MS) {
    delay(1);
    return;
  }

  lastSendTime = millis();

  ControlPacket packet;
  packet.magic = PACKET_MAGIC;
  packet.throttle = throttle;
  packet.roll = readCenteredAxis(ROLL_PIN, REVERSE_ROLL);
  packet.pitch = readCenteredAxis(PITCH_PIN, REVERSE_PITCH);
  packet.yaw = readCenteredAxis(YAW_PIN, REVERSE_YAW);
  packet.armed = armed;
  packet.sequence = sequenceNumber++;

  esp_now_send(
    BROADCAST_ADDRESS,
    reinterpret_cast<const uint8_t*>(&packet),
    sizeof(packet)
  );
}
