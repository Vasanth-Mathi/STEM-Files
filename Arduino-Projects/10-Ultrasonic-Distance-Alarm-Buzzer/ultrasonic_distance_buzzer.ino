void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH, 30000);
  int distance = duration * 0.0343 / 2;

  if (duration > 0 && distance <= 20) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(100);
}
