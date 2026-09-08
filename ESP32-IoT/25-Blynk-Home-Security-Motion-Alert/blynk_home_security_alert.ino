#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Home Security"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const int PIR_PIN = 27;
const int REED_PIN = 33;
const int BUZZER_PIN = 23;

bool armed = false;
bool alertActive = false;

BlynkTimer timer;

BLYNK_WRITE(V0) {
  armed = param.asInt();

  if (!armed) {
    alertActive = false;
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void checkSecurity() {
  bool motion = digitalRead(PIR_PIN) == HIGH;
  bool doorOpen = digitalRead(REED_PIN) == HIGH;

  Blynk.virtualWrite(V1, motion);
  Blynk.virtualWrite(V2, doorOpen);

  bool intrusion = armed && (motion || doorOpen);

  digitalWrite(BUZZER_PIN, intrusion ? HIGH : LOW);

  if (intrusion && !alertActive) {
    alertActive = true;
    Blynk.logEvent("security_alert", "Motion or door activity detected.");
  }

  if (!intrusion) {
    alertActive = false;
  }
}

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L, checkSecurity);
}

void loop() {
  Blynk.run();
  timer.run();
}
