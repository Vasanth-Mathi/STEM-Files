void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int sound = abs(analogRead(A0) - 512);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  if (sound >= 180) {
    digitalWrite(10, HIGH);
  } else if (sound >= 80) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(8, HIGH);
  }

  delay(20);
}
