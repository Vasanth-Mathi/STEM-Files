void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  int light = analogRead(A0);

  if (light < 350) {
    digitalWrite(9, HIGH);
  }

  if (light > 450) {
    digitalWrite(9, LOW);
  }

  delay(100);
}
