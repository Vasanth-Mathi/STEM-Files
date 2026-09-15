/*
  Project 13 - ESP32 One-to-Many Wireless Control Using ESP-NOW
  ESP32 1: Controller Sender
  Broadcasts one push-button state to multiple receiver ESP32 boards.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint8_t BROADCAST_ADDRESS[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
const uint32_t PACKET_MAGIC = 0x13001300;

const int BUTTON_PIN = 4;

struct ControlPacket {
  uint32_t magic;
  bool outputOn;
  uint32_t sequence;
};

uint32_t sequenceNumber = 0;

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

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  ControlPacket packet;
  packet.magic = PACKET_MAGIC;
  packet.outputOn = digitalRead(BUTTON_PIN) == LOW;
  packet.sequence = sequenceNumber++;

  esp_now_send(
    BROADCAST_ADDRESS,
    reinterpret_cast<const uint8_t*>(&packet),
    sizeof(packet)
  );

  delay(50);
}
