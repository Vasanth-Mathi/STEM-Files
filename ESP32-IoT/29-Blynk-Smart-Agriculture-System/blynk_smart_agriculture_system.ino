#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Agriculture"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define DHT_TYPE DHT11

const int DHT_PIN = 4;
const int SOIL_PIN = 34;
const int RAIN_PIN = 27;

const int PUMP_IN1 = 25;
const int PUMP_IN2 = 26;

const int DRY_THRESHOLD = 2600;
const int RAIN_DETECTED_STATE = LOW;

DHT dht(DHT_PIN, DHT_TYPE);
BlynkTimer timer;

bool autoMode = true;
bool manualPump = false;

void setPump(bool on) {
  digitalWrite(PUMP_IN1, on ? HIGH : LOW);
  digitalWrite(PUMP_IN2, LOW);
}

BLYNK_WRITE(V4) {
  autoMode = param.asInt();
}

BLYNK_WRITE(V5) {
  manualPump = param.asInt();

  if (!autoMode) {
    setPump(manualPump);
  }
}

void updateAgriculture() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int soilValue = analogRead(SOIL_PIN);
  bool raining = digitalRead(RAIN_PIN) == RAIN_DETECTED_STATE;

  if (!isnan(temperature)) {
    Blynk.virtualWrite(V0, temperature);
  }

  if (!isnan(humidity)) {
    Blynk.virtualWrite(V1, humidity);
  }

  Blynk.virtualWrite(V2, soilValue);
  Blynk.virtualWrite(V3, raining);

  if (autoMode) {
    bool drySoil = soilValue >= DRY_THRESHOLD;
    setPump(drySoil && !raining);
  } else {
    setPump(manualPump);
  }
}

void setup() {
  pinMode(RAIN_PIN, INPUT);
  pinMode(PUMP_IN1, OUTPUT);
  pinMode(PUMP_IN2, OUTPUT);

  dht.begin();
  setPump(false);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, updateAgriculture);
}

void loop() {
  Blynk.run();
  timer.run();
}
