#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const bool TRANSMITTER_MODE = true;
const int ESPNOW_CHANNEL = 1;

const int BUTTON_PIN = 4;
const int LED_PIN = 23;
const int BUZZER_PIN = 22;

uint8_t receiverMac[] = {0x24, 0x6F, 0x28, 0x00, 0x00, 0x20};

struct DoorbellMessage {
  bool ring;
};

volatile bool ringRequested = false;

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(DoorbellMessage)) {
    return;
  }

  DoorbellMessage message;
  memcpy(&message, data, sizeof(message));

  if (message.ring) {
    ringRequested = true;
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);

  if (esp_now_init() != ESP_OK) {
    return;
  }

  esp_now_register_recv_cb(onReceive);

  if (TRANSMITTER_MODE) {
    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, receiverMac, 6);
    peer.channel = ESPNOW_CHANNEL;
    peer.encrypt = false;

    esp_now_add_peer(&peer);
  }
}

void loop() {
  if (TRANSMITTER_MODE) {
    if (digitalRead(BUTTON_PIN) == LOW) {
      DoorbellMessage message = {true};

      esp_now_send(
        receiverMac,
        (uint8_t*)&message,
        sizeof(message)
      );

      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
      }

      delay(100);
    }

    return;
  }

  if (ringRequested) {
    ringRequested = false;

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1500);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
}
