void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int water = analogRead(A0);
  Serial.println(water);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  if (water >= 650) {
    digitalWrite(10, HIGH);
  } else if (water >= 350) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(8, HIGH);
  }

  delay(200);
}
