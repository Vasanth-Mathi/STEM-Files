#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Gas Alert"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const int MQ5_PIN = 34;
const int BUZZER_PIN = 23;
const int GAS_THRESHOLD = 2200;

bool alertActive = false;

BlynkTimer timer;

void checkGasLevel() {
  int gasValue = analogRead(MQ5_PIN);

  Blynk.virtualWrite(V0, gasValue);

  bool gasHigh = gasValue >= GAS_THRESHOLD;

  digitalWrite(BUZZER_PIN, gasHigh ? HIGH : LOW);

  if (gasHigh && !alertActive) {
    alertActive = true;
    Blynk.logEvent("gas_alert", "Gas-sensor level is above the set threshold.");
  }

  if (!gasHigh) {
    alertActive = false;
  }
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, checkGasLevel);
}

void loop() {
  Blynk.run();
  timer.run();
}
