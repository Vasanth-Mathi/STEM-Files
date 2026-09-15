/*
  Project 11 - ESP32 One-Way Sensor Communication Using ESP-NOW
  ESP32 2: Receiver
  Receives DHT11 data from ESP32 1 and prints it in Serial Monitor.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PACKET_MAGIC = 0x11001100;

struct SensorPacket {
  uint32_t magic;
  float temperature;
  float humidity;
  uint32_t sequence;
};

portMUX_TYPE packetMux = portMUX_INITIALIZER_UNLOCKED;
SensorPacket latestPacket;
volatile bool packetAvailable = false;

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(SensorPacket)) {
    return;
  }

  SensorPacket incoming;
  memcpy(&incoming, data, sizeof(incoming));

  if (incoming.magic != PACKET_MAGIC) {
    return;
  }

  portENTER_CRITICAL(&packetMux);
  latestPacket = incoming;
  packetAvailable = true;
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

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      delay(1000);
    }
  }

  Serial.print("Receiver MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  SensorPacket packet;
  bool hasPacket = false;

  portENTER_CRITICAL(&packetMux);
  if (packetAvailable) {
    packet = latestPacket;
    packetAvailable = false;
    hasPacket = true;
  }
  portEXIT_CRITICAL(&packetMux);

  if (hasPacket) {
    Serial.print("Packet #");
    Serial.print(packet.sequence);
    Serial.print("  Temperature: ");
    Serial.print(packet.temperature);
    Serial.print(" C  Humidity: ");
    Serial.print(packet.humidity);
    Serial.println(" %");
  }

  delay(10);
}
