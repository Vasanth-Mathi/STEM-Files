/*
  Smoke Detector Using MQ-2 Sensor
  Board: Arduino Uno
*/

const int SMOKE_PIN = A0;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;
const int SMOKE_THRESHOLD = 450;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int smokeValue = analogRead(SMOKE_PIN);
  Serial.println(smokeValue);

  bool smokeDetected = smokeValue >= SMOKE_THRESHOLD;

  digitalWrite(LED_PIN, smokeDetected ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, smokeDetected ? HIGH : LOW);

  delay(200);
}
