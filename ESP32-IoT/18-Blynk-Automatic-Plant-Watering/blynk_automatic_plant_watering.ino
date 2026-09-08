#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Plant Watering"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const int SOIL_PIN = 34;
const int PUMP_IN1 = 26;
const int PUMP_IN2 = 27;

const int DRY_THRESHOLD = 2600;

bool autoMode = true;
bool manualPump = false;

BlynkTimer timer;

void setPump(bool on) {
  digitalWrite(PUMP_IN1, on ? HIGH : LOW);
  digitalWrite(PUMP_IN2, LOW);
}

BLYNK_WRITE(V1) {
  autoMode = param.asInt();
}

BLYNK_WRITE(V2) {
  manualPump = param.asInt();

  if (!autoMode) {
    setPump(manualPump);
  }
}

void updateSystem() {
  int soilValue = analogRead(SOIL_PIN);

  Blynk.virtualWrite(V0, soilValue);

  if (autoMode) {
    setPump(soilValue >= DRY_THRESHOLD);
  } else {
    setPump(manualPump);
  }
}

void setup() {
  pinMode(PUMP_IN1, OUTPUT);
  pinMode(PUMP_IN2, OUTPUT);

  setPump(false);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, updateSystem);
}

void loop() {
  Blynk.run();
  timer.run();
}
