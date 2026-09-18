void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  int value = analogRead(A0);
  int brightness = map(value, 0, 1023, 0, 255);
  analogWrite(9, brightness);
  delay(10);
}
