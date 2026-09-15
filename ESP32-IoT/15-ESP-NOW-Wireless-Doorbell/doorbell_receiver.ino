/*
  Project 15 - ESP32 Wireless Doorbell Using ESP-NOW
  ESP32 2: Doorbell Receiver
  Activates an LED and active buzzer when a valid ring packet is received.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PACKET_MAGIC = 0x15001500;

const int LED_PIN = 23;
const int BUZZER_PIN = 22;
const unsigned long RING_TIME_MS = 1200;

struct DoorbellPacket {
  uint32_t magic;
  bool ring;
  uint32_t sequence;
};

portMUX_TYPE ringMux = portMUX_INITIALIZER_UNLOCKED;
volatile bool ringRequested = false;

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(DoorbellPacket)) {
    return;
  }

  DoorbellPacket incoming;
  memcpy(&incoming, data, sizeof(incoming));

  if (incoming.magic == PACKET_MAGIC && incoming.ring) {
    portENTER_CRITICAL(&ringMux);
    ringRequested = true;
    portEXIT_CRITICAL(&ringMux);
  }
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
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  bool shouldRing = false;

  portENTER_CRITICAL(&ringMux);
  if (ringRequested) {
    ringRequested = false;
    shouldRing = true;
  }
  portEXIT_CRITICAL(&ringMux);

  if (shouldRing) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(RING_TIME_MS);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  delay(5);
}
