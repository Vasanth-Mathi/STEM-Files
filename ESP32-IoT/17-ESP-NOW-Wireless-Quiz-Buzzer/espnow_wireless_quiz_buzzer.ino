#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const bool HOST_MODE = false;
const int PLAYER_ID = 1;
const int ESPNOW_CHANNEL = 1;

const int PLAYER_BUTTON_PIN = 4;
const int HOST_LED_PIN = 23;
const int HOST_BUZZER_PIN = 22;
const int HOST_RESET_PIN = 19;

uint8_t hostMac[] = {0x24, 0x6F, 0x28, 0x00, 0x00, 0x40};

struct BuzzerPacket {
  int playerId;
};

volatile int pendingPlayer = -1;
int winner = -1;

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (!HOST_MODE || length != sizeof(BuzzerPacket)) {
    return;
  }

  BuzzerPacket packet;
  memcpy(&packet, data, sizeof(packet));

  if (winner == -1 && pendingPlayer == -1) {
    pendingPlayer = packet.playerId;
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(PLAYER_BUTTON_PIN, INPUT_PULLUP);
  pinMode(HOST_LED_PIN, OUTPUT);
  pinMode(HOST_BUZZER_PIN, OUTPUT);
  pinMode(HOST_RESET_PIN, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);

  if (esp_now_init() != ESP_OK) {
    return;
  }

  esp_now_register_recv_cb(onReceive);

  if (!HOST_MODE) {
    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, hostMac, 6);
    peer.channel = ESPNOW_CHANNEL;
    peer.encrypt = false;

    esp_now_add_peer(&peer);
  }
}

void loop() {
  if (!HOST_MODE) {
    if (digitalRead(PLAYER_BUTTON_PIN) == LOW) {
      BuzzerPacket packet = {PLAYER_ID};

      esp_now_send(
        hostMac,
        (uint8_t*)&packet,
        sizeof(packet)
      );

      while (digitalRead(PLAYER_BUTTON_PIN) == LOW) {
        delay(10);
      }

      delay(100);
    }

    return;
  }

  if (pendingPlayer != -1 && winner == -1) {
    winner = pendingPlayer;
    pendingPlayer = -1;

    Serial.print("Winner: Player ");
    Serial.println(winner);

    digitalWrite(HOST_LED_PIN, HIGH);
    digitalWrite(HOST_BUZZER_PIN, HIGH);
    delay(300);
    digitalWrite(HOST_BUZZER_PIN, LOW);
  }

  if (digitalRead(HOST_RESET_PIN) == LOW) {
    winner = -1;
    pendingPlayer = -1;
    digitalWrite(HOST_LED_PIN, LOW);

    while (digitalRead(HOST_RESET_PIN) == LOW) {
      delay(10);
    }
  }
}
