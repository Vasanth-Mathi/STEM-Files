#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Air Quality"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const int MQ135_PIN = 34;
const int ALERT_THRESHOLD = 2200;

bool alertActive = false;

BlynkTimer timer;

void checkAirQuality() {
  int airValue = analogRead(MQ135_PIN);

  Blynk.virtualWrite(V0, airValue);

  if (airValue >= ALERT_THRESHOLD && !alertActive) {
    alertActive = true;
    Blynk.logEvent("air_quality_alert", "Air-quality sensor level is high.");
  }

  if (airValue < ALERT_THRESHOLD) {
    alertActive = false;
  }
}

void setup() {
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, checkAirQuality);
}

void loop() {
  Blynk.run();
  timer.run();
}
