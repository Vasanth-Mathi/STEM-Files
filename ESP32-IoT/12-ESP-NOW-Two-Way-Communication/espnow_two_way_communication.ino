#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const int DEVICE_ID = 1;
const int ESPNOW_CHANNEL = 1;

const int BUTTON_PIN = 4;
const int LED_PIN = 23;

uint8_t peerMac[] = {0x24, 0x6F, 0x28, 0x00, 0x00, 0x02};

struct Message {
  int deviceId;
  bool buttonPressed;
};

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(Message)) {
    return;
  }

  Message message;
  memcpy(&message, data, sizeof(message));

  digitalWrite(LED_PIN, message.buttonPressed ? HIGH : LOW);

  Serial.print("Message from device ");
  Serial.print(message.deviceId);
  Serial.print(" | Button: ");
  Serial.println(message.buttonPressed ? "PRESSED" : "RELEASED");
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

  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, peerMac, 6);
  peer.channel = ESPNOW_CHANNEL;
  peer.encrypt = false;

  esp_now_add_peer(&peer);

  Serial.print("This ESP32 MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  Message message;
  message.deviceId = DEVICE_ID;
  message.buttonPressed = digitalRead(BUTTON_PIN) == LOW;

  esp_now_send(peerMac, (uint8_t*)&message, sizeof(message));

  delay(200);
}
