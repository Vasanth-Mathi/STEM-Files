/*
  Project 17 - ESP32 Wireless Classroom Quiz Buzzer Using ESP-NOW
  Player ESP32 Sender
  Upload this sketch to each player unit and assign a unique PLAYER_ID.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint8_t BROADCAST_ADDRESS[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
const uint32_t PACKET_MAGIC = 0x17001700;

const uint8_t PLAYER_ID = 1;  // Change to 2, 3, 4... for other players.
const int BUTTON_PIN = 4;
const unsigned long DEBOUNCE_MS = 40;

struct BuzzerPacket {
  uint32_t magic;
  uint8_t playerId;
  bool pressed;
  uint32_t sequence;
};

bool lastButtonState = HIGH;
bool stableButtonState = HIGH;
unsigned long lastChangeTime = 0;
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

void sendBuzz() {
  BuzzerPacket packet;
  packet.magic = PACKET_MAGIC;
  packet.playerId = PLAYER_ID;
  packet.pressed = true;
  packet.sequence = sequenceNumber++;

  esp_now_send(
    BROADCAST_ADDRESS,
    reinterpret_cast<const uint8_t*>(&packet),
    sizeof(packet)
  );
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
  const bool currentState = digitalRead(BUTTON_PIN);

  if (currentState != lastButtonState) {
    lastChangeTime = millis();
    lastButtonState = currentState;
  }

  if (millis() - lastChangeTime >= DEBOUNCE_MS &&
      currentState != stableButtonState) {
    stableButtonState = currentState;

    if (stableButtonState == LOW) {
      sendBuzz();
      Serial.print("Player ");
      Serial.print(PLAYER_ID);
      Serial.println(" buzz sent.");
    }
  }

  delay(5);
}
