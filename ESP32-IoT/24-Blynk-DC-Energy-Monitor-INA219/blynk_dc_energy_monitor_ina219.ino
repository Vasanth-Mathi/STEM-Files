#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "DC Energy Monitor"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

Adafruit_INA219 ina219;
BlynkTimer timer;

float energyWh = 0.0;
unsigned long lastSampleMs = 0;

void updateEnergy() {
  unsigned long now = millis();
  float hours = (now - lastSampleMs) / 3600000.0;
  lastSampleMs = now;

  float busVoltage = ina219.getBusVoltage_V();
  float currentMa = ina219.getCurrent_mA();
  float powerMw = ina219.getPower_mW();

  energyWh += (powerMw / 1000.0) * hours;

  Blynk.virtualWrite(V0, busVoltage);
  Blynk.virtualWrite(V1, currentMa);
  Blynk.virtualWrite(V2, powerMw);
  Blynk.virtualWrite(V3, energyWh);
}

void setup() {
  Wire.begin(21, 22);
  ina219.begin();

  lastSampleMs = millis();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, updateEnergy);
}

void loop() {
  Blynk.run();
  timer.run();
}
