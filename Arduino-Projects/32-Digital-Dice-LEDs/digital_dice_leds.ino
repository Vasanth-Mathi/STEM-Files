void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT_PULLUP);

  randomSeed(analogRead(A0));
}

void loop() {
  if (digitalRead(9) == LOW) {
    int number = random(1, 7);

    for (int pin = 2; pin <= 8; pin++) {
      digitalWrite(pin, LOW);
    }

    if (number == 1) {
      digitalWrite(5, HIGH);
    }

    if (number == 2) {
      digitalWrite(2, HIGH);
      digitalWrite(8, HIGH);
    }

    if (number == 3) {
      digitalWrite(2, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(8, HIGH);
    }

    if (number == 4) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
    }

    if (number == 5) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
    }

    if (number == 6) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
    }

    while (digitalRead(9) == LOW) {
      delay(10);
    }

    delay(100);
  }
}
