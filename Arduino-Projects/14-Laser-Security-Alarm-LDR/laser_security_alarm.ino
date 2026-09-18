/*
  Laser Security Alarm Using LDR Sensor
  Board: Arduino Uno
*/

const int LDR_PIN = A0;
const int BUZZER_PIN = 9;
const int LASER_THRESHOLD = 600;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);

  if (lightValue < LASER_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(50);
}
