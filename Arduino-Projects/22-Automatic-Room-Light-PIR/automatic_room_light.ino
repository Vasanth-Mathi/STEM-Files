void setup() {
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    digitalWrite(9, HIGH);
    delay(10000);
  } else {
    digitalWrite(9, LOW);
  }

  delay(50);
}
