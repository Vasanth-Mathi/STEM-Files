void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(A0);
  Serial.println(moisture);

  if (moisture >= 650) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }

  if (moisture <= 500) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  delay(500);
}
