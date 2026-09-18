/*
  Rain Alert Using Buzzer
  Rain sensor DO: D2
  Active buzzer signal: D8
*/

const int RAIN_SENSOR_PIN = 2;
const int BUZZER_PIN = 8;
const int RAIN_DETECTED_STATE = LOW;

void setup() {
  pinMode(RAIN_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  const bool rainDetected =
    digitalRead(RAIN_SENSOR_PIN) == RAIN_DETECTED_STATE;

  digitalWrite(BUZZER_PIN, rainDetected ? HIGH : LOW);
  delay(50);
}
