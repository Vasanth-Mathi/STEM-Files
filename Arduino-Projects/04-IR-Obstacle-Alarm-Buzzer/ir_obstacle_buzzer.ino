/*
  IR Obstacle Alarm Using Buzzer
  IR sensor DO: D2
  Active buzzer signal: D8
*/

const int IR_SENSOR_PIN = 2;
const int BUZZER_PIN = 8;
const int OBJECT_DETECTED_STATE = LOW;

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  const bool objectDetected =
    digitalRead(IR_SENSOR_PIN) == OBJECT_DETECTED_STATE;

  digitalWrite(BUZZER_PIN, objectDetected ? HIGH : LOW);
  delay(20);
}
