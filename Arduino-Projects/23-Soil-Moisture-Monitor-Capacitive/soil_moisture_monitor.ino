void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(A0);
  Serial.println(moisture);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  if (moisture <= 400) {
    digitalWrite(8, HIGH);
  } else if (moisture >= 650) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(9, HIGH);
  }

  delay(500);
}
