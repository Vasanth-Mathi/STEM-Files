#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "ESP-NOW Gateway"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define DHT_TYPE DHT11

const bool GATEWAY_MODE = true;
const int NODE_ID = 1;
const int DHT_PIN = 4;

const int ESPNOW_CHANNEL = 1;

uint8_t gatewayMac[] = {0x24, 0x6F, 0x28, 0x00, 0x00, 0x50};

DHT dht(DHT_PIN, DHT_TYPE);

struct SensorPacket {
  int nodeId;
  float temperature;
  float humidity;
};

volatile bool newPacket = false;
SensorPacket latestPacket;

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (!GATEWAY_MODE || length != sizeof(SensorPacket)) {
    return;
  }

  memcpy(&latestPacket, data, sizeof(latestPacket));
  newPacket = true;
}

void startEspNow() {
  if (!GATEWAY_MODE) {
    WiFi.mode(WIFI_STA);
    esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);
  }

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW initialization failed.");
    return;
  }

  esp_now_register_recv_cb(onReceive);

  if (!GATEWAY_MODE) {
    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, gatewayMac, 6);
    peer.channel = ESPNOW_CHANNEL;
    peer.encrypt = false;

    esp_now_add_peer(&peer);
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  if (GATEWAY_MODE) {
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

    uint8_t primaryChannel;
    wifi_second_chan_t secondaryChannel;
    esp_wifi_get_channel(&primaryChannel, &secondaryChannel);

    Serial.print("Gateway Wi-Fi channel: ");
    Serial.println(primaryChannel);
    Serial.print("Gateway MAC: ");
    Serial.println(WiFi.macAddress());

    if (primaryChannel != ESPNOW_CHANNEL) {
      Serial.println("Set ESPNOW_CHANNEL in sensor nodes to this Wi-Fi channel.");
    }
  }

  startEspNow();
}

void loop() {
  if (GATEWAY_MODE) {
    Blynk.run();

    if (newPacket) {
      noInterrupts();
      SensorPacket packet = latestPacket;
      newPacket = false;
      interrupts();

      Blynk.virtualWrite(V0, packet.nodeId);
      Blynk.virtualWrite(V1, packet.temperature);
      Blynk.virtualWrite(V2, packet.humidity);
    }

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
