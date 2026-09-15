/*
  Project 13 - ESP32 One-to-Many Wireless Control Using ESP-NOW
  ESP32 2 / ESP32 3 / ESP32 4: Receiver
  Upload this same receiver sketch to every receiver board.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PACKET_MAGIC = 0x13001300;

const int LED_PIN = 23;

struct ControlPacket {
  uint32_t magic;
  bool outputOn;
  uint32_t sequence;
};

portMUX_TYPE packetMux = portMUX_INITIALIZER_UNLOCKED;
volatile bool requestedState = false;
volatile bool stateUpdated = false;

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(ControlPacket)) {
    return;
  }

  ControlPacket incoming;
  memcpy(&incoming, data, sizeof(incoming));

  if (incoming.magic != PACKET_MAGIC) {
    return;
  }

  portENTER_CRITICAL(&packetMux);
  requestedState = incoming.outputOn;
  stateUpdated = true;
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
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  bool outputOn = false;
  bool update = false;

  portENTER_CRITICAL(&packetMux);
  if (stateUpdated) {
    outputOn = requestedState;
    stateUpdated = false;
    update = true;
  }
  portEXIT_CRITICAL(&packetMux);

  if (update) {
    digitalWrite(LED_PIN, outputOn ? HIGH : LOW);
  }

  delay(10);
}
