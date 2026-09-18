/*
  IR Obstacle Indicator Using LED
  IR sensor DO: D2
  LED: D8
*/

const int IR_SENSOR_PIN = 2;
const int LED_PIN = 8;
const int OBJECT_DETECTED_STATE = LOW;

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  const bool objectDetected =
    digitalRead(IR_SENSOR_PIN) == OBJECT_DETECTED_STATE;

  digitalWrite(LED_PIN, objectDetected ? HIGH : LOW);
  delay(20);
}
