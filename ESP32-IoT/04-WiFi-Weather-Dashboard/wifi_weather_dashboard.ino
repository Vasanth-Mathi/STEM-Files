#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

const char* WIFI_NAME = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const int DHT_PIN = 4;
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_BMP280 bmp;
WebServer server(80);

void showDashboard() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float pressure = bmp.readPressure() / 100.0F;

  String page = "<h1>ESP32 Weather Dashboard</h1>";

  if (isnan(temperature) || isnan(humidity)) {
    page += "<p>DHT11 sensor error</p>";
  } else {
    page += "<p>Temperature: " + String(temperature, 1) + " C</p>";
    page += "<p>Humidity: " + String(humidity, 0) + " %</p>";
  }

  page += "<p>Pressure: " + String(pressure, 1) + " hPa</p>";
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  Wire.begin(21, 22);

  if (!bmp.begin(0x76)) {
    Serial.println("BMP280 not found. Check address and wiring.");
  }

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println(WiFi.localIP());

  server.on("/", showDashboard);
  server.begin();
}

void loop() {
  server.handleClient();
}
