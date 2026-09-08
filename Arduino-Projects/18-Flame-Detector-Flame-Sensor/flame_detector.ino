/*
  Flame Detector Using Flame Sensor
  Board: Arduino Uno
*/

const int FLAME_PIN = 2;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;
const int FLAME_DETECTED_STATE = LOW;

void setup() {
  pinMode(FLAME_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  bool flameDetected = digitalRead(FLAME_PIN) == FLAME_DETECTED_STATE;

  digitalWrite(LED_PIN, flameDetected ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, flameDetected ? HIGH : LOW);

  delay(50);
}
