#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const bool CONTROLLER_MODE = true;
const int ESPNOW_CHANNEL = 1;

const int BUTTON_PIN = 4;
const int LED_PIN = 23;

uint8_t broadcastMac[] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

struct ControlMessage {
  bool outputOn;
};

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(ControlMessage)) {
    return;
  }

  ControlMessage message;
  memcpy(&message, data, sizeof(message));

  digitalWrite(LED_PIN, message.outputOn ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW initialization failed.");
    return;
  }

  esp_now_register_recv_cb(onReceive);

  if (CONTROLLER_MODE) {
    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, broadcastMac, 6);
    peer.channel = ESPNOW_CHANNEL;
    peer.encrypt = false;

    esp_now_add_peer(&peer);
  }
}

void loop() {
  if (!CONTROLLER_MODE) {
    delay(1000);
    return;
  }

  ControlMessage message;
  message.outputOn = digitalRead(BUTTON_PIN) == LOW;

  esp_now_send(
    broadcastMac,
    (uint8_t*)&message,
    sizeof(message)
  );

  delay(100);
}
