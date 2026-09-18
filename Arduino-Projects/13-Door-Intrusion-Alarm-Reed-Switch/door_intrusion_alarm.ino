void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  delay(50);
}
