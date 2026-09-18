void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

  while (digitalRead(2) == LOW) {
    delay(10);
  }

  delay(random(2000, 5001));

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(50);
  digitalWrite(9, LOW);

  unsigned long startTime = millis();

  while (digitalRead(2) == HIGH) {
  }

  unsigned long reactionTime = millis() - startTime;

  digitalWrite(8, LOW);

  Serial.print("Reaction time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  while (digitalRead(2) == LOW) {
    delay(10);
  }

  delay(1500);
}
