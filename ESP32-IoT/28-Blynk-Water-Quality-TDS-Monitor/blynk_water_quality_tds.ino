#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Water Quality"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const int TDS_PIN = 34;
const int SAMPLE_COUNT = 20;

BlynkTimer timer;

void updateTds() {
  long total = 0;

  for (int i = 0; i < SAMPLE_COUNT; i++) {
    total += analogRead(TDS_PIN);
    delay(10);
  }

  float raw = total / (float)SAMPLE_COUNT;
  float voltage = raw * 3.3 / 4095.0;

  float tds = (
    133.42 * voltage * voltage * voltage
    - 255.86 * voltage * voltage
    + 857.39 * voltage
  ) * 0.5;

  if (tds < 0) {
    tds = 0;
  }

  Blynk.virtualWrite(V0, tds);
  Blynk.virtualWrite(V1, voltage);
}

void setup() {
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, updateTds);
}

void loop() {
  Blynk.run();
  timer.run();
}
