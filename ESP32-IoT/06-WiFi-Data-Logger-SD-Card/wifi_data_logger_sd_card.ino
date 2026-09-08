#include <WiFi.h>
#include <SPI.h>
#include <SD.h>
#include <DHT.h>
#include <time.h>

const char* WIFI_NAME = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const int DHT_PIN = 4;
const int SD_CS_PIN = 5;
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

unsigned long lastLogTime = 0;
const unsigned long LOG_INTERVAL = 60000;

String getTimestamp() {
  struct tm timeInfo;

  if (!getLocalTime(&timeInfo)) {
    return "time-not-ready";
  }

  char buffer[25];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeInfo);
  return String(buffer);
}

void logReading() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 read failed.");
    return;
  }

  File file = SD.open("/data.csv", FILE_APPEND);

  if (!file) {
    Serial.println("Could not open data.csv");
    return;
  }

  file.print(getTimestamp());
  file.print(",");
  file.print(temperature, 1);
  file.print(",");
  file.println(humidity, 1);
  file.close();

  Serial.println("Reading saved.");
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed.");
  }

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  configTime(19800, 0, "pool.ntp.org", "time.nist.gov");

  File file = SD.open("/data.csv", FILE_APPEND);

  if (file && file.size() == 0) {
    file.println("timestamp,temperature_c,humidity_percent");
  }

  file.close();
}

void loop() {
  if (millis() - lastLogTime >= LOG_INTERVAL) {
    lastLogTime = millis();
    logReading();
  }
}
