void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  int reading = analogRead(A0);
  float temperature = reading * (5.0 / 1023.0) * 100.0;

  if (temperature >= 30) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }

  if (temperature <= 28) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  delay(500);
}
