void setup() {
  pinMode(2, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(50);
}
