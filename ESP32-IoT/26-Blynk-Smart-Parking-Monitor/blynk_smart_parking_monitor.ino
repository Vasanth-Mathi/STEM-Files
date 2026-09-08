#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Parking"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

const int SLOT_1_SENSOR = 32;
const int SLOT_2_SENSOR = 33;
const int SLOT_1_LED = 23;
const int SLOT_2_LED = 22;

const int OCCUPIED_STATE = LOW;

BlynkTimer timer;

void updateParking() {
  bool slot1Occupied = digitalRead(SLOT_1_SENSOR) == OCCUPIED_STATE;
  bool slot2Occupied = digitalRead(SLOT_2_SENSOR) == OCCUPIED_STATE;

  int freeSpaces = 2 - slot1Occupied - slot2Occupied;

  digitalWrite(SLOT_1_LED, slot1Occupied ? HIGH : LOW);
  digitalWrite(SLOT_2_LED, slot2Occupied ? HIGH : LOW);

  Blynk.virtualWrite(V0, slot1Occupied);
  Blynk.virtualWrite(V1, slot2Occupied);
  Blynk.virtualWrite(V2, freeSpaces);
}

void setup() {
  pinMode(SLOT_1_SENSOR, INPUT);
  pinMode(SLOT_2_SENSOR, INPUT);
  pinMode(SLOT_1_LED, OUTPUT);
  pinMode(SLOT_2_LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L, updateParking);
}

void loop() {
  Blynk.run();
  timer.run();
}
