#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <DHT.h>

#define DHT_TYPE DHT11

const bool SENDER_MODE = true;
const int ESPNOW_CHANNEL = 1;
const int DHT_PIN = 4;

uint8_t receiverMac[] = {0x24, 0x6F, 0x28, 0x00, 0x00, 0x01};

DHT dht(DHT_PIN, DHT_TYPE);

struct SensorData {
  float temperature;
  float humidity;
};

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(SensorData)) {
    return;
  }

  SensorData received;
  memcpy(&received, data, sizeof(received));

  Serial.print("Temperature: ");
  Serial.print(received.temperature, 1);
  Serial.print(" C | Humidity: ");
  Serial.print(received.humidity, 1);
  Serial.println(" %");
}

void setupEspNow() {
  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW initialization failed.");
    return;
  }

  esp_now_register_recv_cb(onReceive);

  if (SENDER_MODE) {
    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, receiverMac, 6);
    peer.channel = ESPNOW_CHANNEL;
    peer.encrypt = false;

    if (esp_now_add_peer(&peer) != ESP_OK) {
      Serial.println("Could not add receiver peer.");
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setupEspNow();

  Serial.print("This ESP32 MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  if (!SENDER_MODE) {
    delay(1000);
    return;
  }

  SensorData data;
  data.temperature = dht.readTemperature();
  data.humidity = dht.readHumidity();

  if (!isnan(data.temperature) && !isnan(data.humidity)) {
    esp_now_send(receiverMac, (uint8_t*)&data, sizeof(data));
  }

  delay(2000);
}
