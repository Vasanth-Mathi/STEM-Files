/*
  Rain Detector Using Rain Sensor
  Board: Arduino Uno
*/

const int RAIN_PIN = 2;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;
const int RAIN_DETECTED_STATE = LOW;

void setup() {
  pinMode(RAIN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  bool rainDetected = digitalRead(RAIN_PIN) == RAIN_DETECTED_STATE;

  digitalWrite(LED_PIN, rainDetected ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, rainDetected ? HIGH : LOW);

  delay(100);
}
