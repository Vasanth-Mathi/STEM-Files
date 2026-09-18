int winner = 0;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(11) == LOW) {
    winner = 0;
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);

    while (digitalRead(11) == LOW) {
      delay(10);
    }
  }

  if (winner == 0) {
    if (digitalRead(2) == LOW) {
      winner = 1;
    } else if (digitalRead(3) == LOW) {
      winner = 2;
    } else if (digitalRead(4) == LOW) {
      winner = 3;
    } else if (digitalRead(5) == LOW) {
      winner = 4;
    }

    if (winner == 1) {
      digitalWrite(6, HIGH);
    }

    if (winner == 2) {
      digitalWrite(7, HIGH);
    }

    if (winner == 3) {
      digitalWrite(8, HIGH);
    }

    if (winner == 4) {
      digitalWrite(9, HIGH);
    }

    if (winner > 0) {
      digitalWrite(10, HIGH);
      delay(300);
      digitalWrite(10, LOW);
    }
  }
}
