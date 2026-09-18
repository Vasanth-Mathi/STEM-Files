void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(A0);
  Serial.println(moisture);

  if (moisture >= 650) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(500);
}
