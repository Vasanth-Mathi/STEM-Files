void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A0);
  float temperature = reading * (5.0 / 1023.0) * 100.0;

  Serial.println(temperature);

  if (temperature >= 30) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(500);
}
