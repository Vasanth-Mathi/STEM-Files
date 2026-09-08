#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <DHT.h>

#define DHT_TYPE DHT11

const bool SENSOR_NODE_MODE = true;
const int NODE_ID = 1;
const int ESPNOW_CHANNEL = 1;
const int DHT_PIN = 4;

uint8_t gatewayMac[] = {0x24, 0x6F, 0x28, 0x00, 0x00, 0x10};

DHT dht(DHT_PIN, DHT_TYPE);

struct SensorPacket {
  int nodeId;
  float temperature;
  float humidity;
};

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(SensorPacket)) {
    return;
  }

  SensorPacket packet;
  memcpy(&packet, data, sizeof(packet));

  Serial.print("Node ");
  Serial.print(packet.nodeId);
  Serial.print(" | ");
  Serial.print(packet.temperature, 1);
  Serial.print(" C | ");
  Serial.print(packet.humidity, 1);
  Serial.println(" %");
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW initialization failed.");
    return;
  }

  esp_now_register_recv_cb(onReceive);

  if (SENSOR_NODE_MODE) {
    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, gatewayMac, 6);
    peer.channel = ESPNOW_CHANNEL;
    peer.encrypt = false;

    esp_now_add_peer(&peer);
  }

  Serial.print("This ESP32 MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  if (!SENSOR_NODE_MODE) {
    delay(1000);
    return;
  }

  SensorPacket packet;
  packet.nodeId = NODE_ID;
  packet.temperature = dht.readTemperature();
  packet.humidity = dht.readHumidity();

  if (!isnan(packet.temperature) && !isnan(packet.humidity)) {
    esp_now_send(
      gatewayMac,
      (uint8_t*)&packet,
      sizeof(packet)
    );
  }

  delay(3000);
}
