/*
  PIR Motion Indicator Using LED
  PIR OUT: D2
  LED: D8
*/

const int PIR_PIN = 2;
const int LED_PIN = 8;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  const bool motionDetected = digitalRead(PIR_PIN) == HIGH;
  digitalWrite(LED_PIN, motionDetected ? HIGH : LOW);
  delay(50);
}
