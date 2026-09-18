int lightState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    if (lightState == 0) {
      lightState = 1;
      digitalWrite(9, HIGH);
    } else {
      lightState = 0;
      digitalWrite(9, LOW);
    }

    while (digitalRead(2) == HIGH) {
      delay(10);
    }

    delay(200);
  }
}
