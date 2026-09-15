/*
  Project 14 - ESP32 Many-to-One Wireless Sensor Network Using ESP-NOW
  Gateway ESP32 Receiver
  Receives readings from multiple sensor-node ESP32 boards.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PACKET_MAGIC = 0x14001400;
const uint8_t QUEUE_SIZE = 8;

struct SensorPacket {
  uint32_t magic;
  uint8_t nodeId;
  float temperature;
  float humidity;
  uint32_t sequence;
};

portMUX_TYPE queueMux = portMUX_INITIALIZER_UNLOCKED;
SensorPacket packetQueue[QUEUE_SIZE];
volatile uint8_t queueHead = 0;
volatile uint8_t queueTail = 0;
volatile uint8_t queueCount = 0;

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

  portENTER_CRITICAL(&queueMux);

  if (queueCount == QUEUE_SIZE) {
    queueHead = (queueHead + 1) % QUEUE_SIZE;
    queueCount--;
  }

  packetQueue[queueTail] = incoming;
  queueTail = (queueTail + 1) % QUEUE_SIZE;
  queueCount++;

  portEXIT_CRITICAL(&queueMux);
}

bool popPacket(SensorPacket& packet) {
  bool available = false;

  portENTER_CRITICAL(&queueMux);

  if (queueCount > 0) {
    packet = packetQueue[queueHead];
    queueHead = (queueHead + 1) % QUEUE_SIZE;
    queueCount--;
    available = true;
  }

  portEXIT_CRITICAL(&queueMux);
  return available;
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
}

void loop() {
  SensorPacket packet;

  while (popPacket(packet)) {
    Serial.print("Node ");
    Serial.print(packet.nodeId);
    Serial.print("  Temperature: ");
    Serial.print(packet.temperature);
    Serial.print(" C  Humidity: ");
    Serial.print(packet.humidity);
    Serial.print(" %  Sequence: ");
    Serial.println(packet.sequence);
  }

  delay(5);
}
