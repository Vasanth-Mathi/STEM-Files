/*
  Gas Leakage Detector Using MQ-5 Sensor
  Board: Arduino Uno
*/

const int GAS_PIN = A0;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;
const int GAS_THRESHOLD = 450;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(GAS_PIN);
  Serial.println(gasValue);

  bool alarmActive = gasValue >= GAS_THRESHOLD;

  digitalWrite(LED_PIN, alarmActive ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, alarmActive ? HIGH : LOW);

  delay(200);
}
