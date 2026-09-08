/*
  Vibration Detector Using SW-420 Sensor
  Board: Arduino Uno
*/

const int VIBRATION_PIN = 2;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;
const int VIBRATION_STATE = HIGH;

void setup() {
  pinMode(VIBRATION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  bool vibrationDetected = digitalRead(VIBRATION_PIN) == VIBRATION_STATE;

  digitalWrite(LED_PIN, vibrationDetected ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, vibrationDetected ? HIGH : LOW);

  delay(20);
}
