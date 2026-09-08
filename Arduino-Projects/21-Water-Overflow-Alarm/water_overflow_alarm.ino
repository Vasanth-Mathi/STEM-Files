/*
  Water Overflow Alarm Using Water Level Sensor
  Board: Arduino Uno
*/

const int LEVEL_PIN = A0;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;
const int OVERFLOW_THRESHOLD = 650;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int waterLevel = analogRead(LEVEL_PIN);
  Serial.println(waterLevel);

  bool overflowDetected = waterLevel >= OVERFLOW_THRESHOLD;

  digitalWrite(LED_PIN, overflowDetected ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, overflowDetected ? HIGH : LOW);

  delay(200);
}
