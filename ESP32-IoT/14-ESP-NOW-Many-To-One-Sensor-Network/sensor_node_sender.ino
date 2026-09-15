/*
  Project 14 - ESP32 Many-to-One Wireless Sensor Network Using ESP-NOW
  ESP32 Sensor Node Sender
  Upload this sketch to each sensor node and give every node a unique NODE_ID.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <DHT.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint8_t BROADCAST_ADDRESS[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
const uint32_t PACKET_MAGIC = 0x14001400;

const uint8_t NODE_ID = 1;  // Change to 2, 3, 4... on other sensor nodes.
const int DHT_PIN = 4;
const int DHT_TYPE = DHT11;

DHT dht(DHT_PIN, DHT_TYPE);

struct SensorPacket {
  uint32_t magic;
  uint8_t nodeId;
  float temperature;
  float humidity;
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
  dht.begin();

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  const float temperature = dht.readTemperature();
  const float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 reading failed.");
    delay(2000);
    return;
  }

  SensorPacket packet;
  packet.magic = PACKET_MAGIC;
  packet.nodeId = NODE_ID;
  packet.temperature = temperature;
  packet.humidity = humidity;
  packet.sequence = sequenceNumber++;

  esp_now_send(
    BROADCAST_ADDRESS,
    reinterpret_cast<const uint8_t*>(&packet),
    sizeof(packet)
  );

  delay(2000);
}
