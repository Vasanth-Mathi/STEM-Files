/*
  Motion Detector Using PIR Sensor
  Board: Arduino Uno
*/

const int PIR_PIN = 2;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  bool motionDetected = digitalRead(PIR_PIN) == HIGH;

  digitalWrite(LED_PIN, motionDetected ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, motionDetected ? HIGH : LOW);

  delay(50);
}
