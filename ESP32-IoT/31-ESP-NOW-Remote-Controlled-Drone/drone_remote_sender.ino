/*
  Project 31 - ESP32 ESP-NOW Remote-Controlled Drone
  ESP32 1: Handheld Remote Sender

  Two joysticks control throttle, yaw, roll and pitch.
  A push button arms or disarms the drone only when throttle is low.

  IMPORTANT:
  - Both ESP32 boards must use the same ESPNOW_CHANNEL and PAIR_KEY.
  - Use ADC1 pins for joystick inputs because ESP-NOW uses the Wi-Fi radio.
  - Test the complete system with propellers removed first.
  - Target: Arduino-ESP32 3.x.
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PAIR_KEY = 0xD31A2026;
const uint8_t BROADCAST_ADDRESS[6] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

const int THROTTLE_PIN = 34;
const int YAW_PIN = 35;
const int ROLL_PIN = 32;
const int PITCH_PIN = 33;
const int ARM_BUTTON_PIN = 25;

const int ADC_MAX = 4095;
const int ADC_CENTER = 2048;
const int AXIS_DEAD_ZONE = 120;

const uint8_t ARM_MAX_THROTTLE = 20;
const unsigned long SEND_INTERVAL_MS = 20;
const unsigned long BUTTON_DEBOUNCE_MS = 50;

const bool REVERSE_THROTTLE = false;
const bool REVERSE_YAW = false;
const bool REVERSE_ROLL = false;
const bool REVERSE_PITCH = true;

struct __attribute__((packed)) ControlPacket {
  uint32_t pairKey;
  uint32_t sequence;
  uint8_t throttle;
  int8_t roll;
  int8_t pitch;
  int8_t yaw;
  uint8_t armed;
};

bool armed = false;
bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;
unsigned long lastButtonChangeTime = 0;
unsigned long lastSendTime = 0;
uint32_t sequenceNumber = 0;

int8_t readCenteredAxis(int pin, bool reverseDirection) {
  const int raw = analogRead(pin);
  int offset = raw - ADC_CENTER;

  if (abs(offset) <= AXIS_DEAD_ZONE) {
    return 0;
  }

  int value;

  if (offset < 0) {
    value = map(
      offset,
      -ADC_CENTER,
      -AXIS_DEAD_ZONE,
      -100,
      0
    );
  } else {
    value = map(
      offset,
      AXIS_DEAD_ZONE,
      ADC_MAX - ADC_CENTER,
      0,
      100
    );
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
    raw = ADC_MAX - raw;
  }

  const int value = map(raw, 0, ADC_MAX, 0, 255);
  return static_cast<uint8_t>(constrain(value, 0, 255));
}

bool addBroadcastPeer() {
  if (esp_now_is_peer_exist(BROADCAST_ADDRESS)) {
    return true;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, BROADCAST_ADDRESS, 6);
  peerInfo.channel = ESPNOW_CHANNEL;
  peerInfo.ifidx = WIFI_IF_STA;
  peerInfo.encrypt = false;

  return esp_now_add_peer(&peerInfo) == ESP_OK;
}

bool startEspNow() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  if (esp_wifi_set_channel(
        ESPNOW_CHANNEL,
        WIFI_SECOND_CHAN_NONE
      ) != ESP_OK) {
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
    lastButtonReading = reading;
    lastButtonChangeTime = millis();
  }

  if (millis() - lastButtonChangeTime < BUTTON_DEBOUNCE_MS) {
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

  Serial.print("Remote ESP32 MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.println("Remote ready.");
}

void loop() {
  const uint8_t throttle = readThrottle();
  updateArmButton(throttle);

  if (millis() - lastSendTime < SEND_INTERVAL_MS) {
    delay(1);
    return;
  }

  lastSendTime = millis();

  ControlPacket packet = {};
  packet.pairKey = PAIR_KEY;
  packet.sequence = sequenceNumber++;
  packet.throttle = throttle;
  packet.roll = readCenteredAxis(ROLL_PIN, REVERSE_ROLL);
  packet.pitch = readCenteredAxis(PITCH_PIN, REVERSE_PITCH);
  packet.yaw = readCenteredAxis(YAW_PIN, REVERSE_YAW);
  packet.armed = armed ? 1 : 0;

  const esp_err_t result = esp_now_send(
    BROADCAST_ADDRESS,
    reinterpret_cast<const uint8_t*>(&packet),
    sizeof(packet)
  );

  if (result != ESP_OK) {
    Serial.println("ESP-NOW send error.");
  }
}
