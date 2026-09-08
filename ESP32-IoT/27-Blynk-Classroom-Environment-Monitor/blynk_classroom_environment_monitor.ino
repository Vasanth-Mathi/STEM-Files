#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Classroom Monitor"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define DHT_TYPE DHT11

const int DHT_PIN = 4;
const int LIGHT_PIN = 34;
const int SOUND_PIN = 35;

DHT dht(DHT_PIN, DHT_TYPE);
BlynkTimer timer;

void sendEnvironmentData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int lightValue = analogRead(LIGHT_PIN);
  int soundValue = analogRead(SOUND_PIN);

  if (!isnan(temperature)) {
    Blynk.virtualWrite(V0, temperature);
  }

  if (!isnan(humidity)) {
    Blynk.virtualWrite(V1, humidity);
  }

  Blynk.virtualWrite(V2, lightValue);
  Blynk.virtualWrite(V3, soundValue);
}

void setup() {
  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendEnvironmentData);
}

void loop() {
  Blynk.run();
  timer.run();
}
