#include <BLEDevice.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

const bool TAG_MODE = false;

const int LED_PIN = 23;
const int BUZZER_PIN = 22;
const int NEAR_RSSI = -65;

BLEScan* scanner = nullptr;

bool tagSeen = false;
int tagRssi = -100;

class ScanCallbacks : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice device) override {
    if (device.haveName() && device.getName() == "ESP32-PROX-TAG") {
      tagSeen = true;
      tagRssi = device.getRSSI();
    }
  }
};

void setupTag() {
  BLEDevice::init("ESP32-PROX-TAG");
  BLEAdvertising* advertising = BLEDevice::getAdvertising();
  advertising->start();
}

void setupScanner() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  BLEDevice::init("");

  scanner = BLEDevice::getScan();
  scanner->setAdvertisedDeviceCallbacks(new ScanCallbacks());
  scanner->setActiveScan(true);
  scanner->setInterval(100);
  scanner->setWindow(99);
}

void setup() {
  Serial.begin(115200);

  if (TAG_MODE) {
    setupTag();
  } else {
    setupScanner();
  }
}

void loop() {
  if (TAG_MODE) {
    delay(1000);
    return;
  }

  tagSeen = false;
  tagRssi = -100;

  scanner->start(2, false);
  scanner->clearResults();

  bool nearTag = tagSeen && tagRssi >= NEAR_RSSI;

  digitalWrite(LED_PIN, nearTag ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, nearTag ? HIGH : LOW);

  Serial.print("Tag RSSI: ");
  Serial.println(tagSeen ? String(tagRssi) : "not found");

  delay(500);
}
