void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  int light = analogRead(A0);

  if (light < 600) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }

  delay(50);
}
