/*
  Project 12 - ESP32 Two-Way Communication Using ESP-NOW
  ESP32 2
  Button on ESP32 2 controls the LED on ESP32 1, while ESP32 2 also receives
  the button state from ESP32 1.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint8_t BROADCAST_ADDRESS[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
const uint32_t PACKET_MAGIC = 0x12001200;
const uint8_t DEVICE_ID = 2;

const int BUTTON_PIN = 4;
const int LED_PIN = 23;

struct ButtonPacket {
  uint32_t magic;
  uint8_t senderId;
  bool pressed;
  uint32_t sequence;
};

portMUX_TYPE packetMux = portMUX_INITIALIZER_UNLOCKED;
volatile bool remoteButtonPressed = false;
volatile bool remoteStateUpdated = false;
uint32_t sequenceNumber = 0;

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(ButtonPacket)) {
    return;
  }

  ButtonPacket incoming;
  memcpy(&incoming, data, sizeof(incoming));

  if (incoming.magic != PACKET_MAGIC || incoming.senderId == DEVICE_ID) {
    return;
  }

  portENTER_CRITICAL(&packetMux);
  remoteButtonPressed = incoming.pressed;
  remoteStateUpdated = true;
  portEXIT_CRITICAL(&packetMux);
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

  if (esp_now_register_recv_cb(onReceive) != ESP_OK) {
    return false;
  }

  return addBroadcastPeer();
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
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
  const bool localPressed = digitalRead(BUTTON_PIN) == LOW;

  ButtonPacket packet;
  packet.magic = PACKET_MAGIC;
  packet.senderId = DEVICE_ID;
  packet.pressed = localPressed;
  packet.sequence = sequenceNumber++;

  esp_now_send(
    BROADCAST_ADDRESS,
    reinterpret_cast<const uint8_t*>(&packet),
    sizeof(packet)
  );

  bool remotePressed = false;

  portENTER_CRITICAL(&packetMux);
  remotePressed = remoteButtonPressed;
  remoteStateUpdated = false;
  portEXIT_CRITICAL(&packetMux);

  digitalWrite(LED_PIN, remotePressed ? HIGH : LOW);

  delay(50);
}
