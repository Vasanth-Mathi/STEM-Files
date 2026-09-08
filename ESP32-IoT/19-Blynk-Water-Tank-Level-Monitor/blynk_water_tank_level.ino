#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Tank Level"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const int TRIG_PIN = 5;
const int ECHO_PIN = 18;

const float TANK_DEPTH_CM = 100.0;

BlynkTimer timer;

float measureDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    return -1.0;
  }

  float distance = duration * 0.0343 / 2.0;

  if (distance < 2.0 || distance > 400.0) {
    return -1.0;
  }

  return distance;
}

void sendTankLevel() {
  float distance = measureDistanceCm();

  if (distance < 0) {
    return;
  }

  float level = (TANK_DEPTH_CM - distance) * 100.0 / TANK_DEPTH_CM;
  level = constrain(level, 0.0, 100.0);

  Blynk.virtualWrite(V0, level);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendTankLevel);
}

void loop() {
  Blynk.run();
  timer.run();
}
