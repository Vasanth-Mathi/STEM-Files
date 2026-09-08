#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Home"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const int OUTPUT_1 = 23;
const int OUTPUT_2 = 22;
const int OUTPUT_3 = 21;
const int OUTPUT_4 = 19;

BLYNK_WRITE(V0) {
  digitalWrite(OUTPUT_1, param.asInt() ? HIGH : LOW);
}

BLYNK_WRITE(V1) {
  digitalWrite(OUTPUT_2, param.asInt() ? HIGH : LOW);
}

BLYNK_WRITE(V2) {
  digitalWrite(OUTPUT_3, param.asInt() ? HIGH : LOW);
}

BLYNK_WRITE(V3) {
  digitalWrite(OUTPUT_4, param.asInt() ? HIGH : LOW);
}

void setup() {
  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  pinMode(OUTPUT_3, OUTPUT);
  pinMode(OUTPUT_4, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
