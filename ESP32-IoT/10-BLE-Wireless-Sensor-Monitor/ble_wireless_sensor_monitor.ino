#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <DHT.h>

#define DHT_TYPE DHT11

const int DHT_PIN = 4;

const char* SERVICE_UUID = "7c04a001-2d32-4ef7-a123-000000000001";
const char* DATA_UUID = "7c04a002-2d32-4ef7-a123-000000000001";

DHT dht(DHT_PIN, DHT_TYPE);

BLECharacteristic* dataCharacteristic = nullptr;
bool deviceConnected = false;

class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* server) override {
    deviceConnected = true;
  }

  void onDisconnect(BLEServer* server) override {
    deviceConnected = false;
    server->startAdvertising();
  }
};

void setup() {
  Serial.begin(115200);
  dht.begin();

  BLEDevice::init("ESP32-Sensor");

  BLEServer* server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());

  BLEService* service = server->createService(SERVICE_UUID);

  dataCharacteristic = service->createCharacteristic(
    DATA_UUID,
    BLECharacteristic::PROPERTY_READ |
    BLECharacteristic::PROPERTY_NOTIFY
  );

  dataCharacteristic->addDescriptor(new BLE2902());

  service->start();
  server->getAdvertising()->start();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {
    String data = String(temperature, 1) + "," + String(humidity, 1);

    dataCharacteristic->setValue(data.c_str());

    if (deviceConnected) {
      dataCharacteristic->notify();
    }
  }

  delay(2000);
}
