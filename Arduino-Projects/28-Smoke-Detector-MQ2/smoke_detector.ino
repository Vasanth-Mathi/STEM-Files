void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int smoke = analogRead(A0);
  Serial.println(smoke);

  if (smoke >= 450) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  delay(200);
}
