/*
  Door Intrusion Alarm Using Magnetic Reed Switch
  Board: Arduino Uno
*/

const int REED_PIN = 2;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;

void setup() {
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  bool doorOpen = digitalRead(REED_PIN) == HIGH;

  digitalWrite(LED_PIN, doorOpen ? HIGH : LOW);
  digitalWrite(BUZZER_PIN, doorOpen ? HIGH : LOW);

  delay(50);
}
