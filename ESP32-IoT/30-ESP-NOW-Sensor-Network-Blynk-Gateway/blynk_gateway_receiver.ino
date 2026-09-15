/*
  Project 30 - ESP32 ESP-NOW Sensor Network with Blynk IoT Gateway
  Gateway ESP32 Receiver
  Receives ESP-NOW sensor packets and forwards them to Blynk over Wi-Fi.
  Target: Arduino-ESP32 3.x
*/

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "ESP-NOW Gateway"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <esp_now.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const uint32_t PACKET_MAGIC = 0x30003000;
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

bool startEspNowReceiver() {
  if (esp_now_init() != ESP_OK) {
    return false;
  }

  return esp_now_register_recv_cb(onReceive) == ESP_OK;
}

void setup() {
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.print("Gateway MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Gateway Wi-Fi channel: ");
  Serial.println(WiFi.channel());
  Serial.println(
    "Set ESPNOW_CHANNEL in every sensor-node sketch to this channel."
  );

  if (!startEspNowReceiver()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  Blynk.run();

  SensorPacket packet;

  while (popPacket(packet)) {
    Blynk.virtualWrite(V0, packet.nodeId);
    Blynk.virtualWrite(V1, packet.temperature);
    Blynk.virtualWrite(V2, packet.humidity);

    Serial.print("Node ");
    Serial.print(packet.nodeId);
    Serial.print("  Temperature: ");
    Serial.print(packet.temperature);
    Serial.print(" C  Humidity: ");
    Serial.print(packet.humidity);
    Serial.println(" %");
  }
}
