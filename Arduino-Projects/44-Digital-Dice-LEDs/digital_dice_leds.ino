/*
  Digital Dice Using LEDs
  Board: Arduino Uno
*/

const int ledPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int BUTTON_PIN = 9;

const byte patterns[6][7] = {
  {0, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 1},
  {1, 1, 0, 0, 0, 1, 1},
  {1, 1, 0, 1, 0, 1, 1},
  {1, 1, 1, 0, 1, 1, 1}
};

void showNumber(int number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], patterns[number - 1][i]);
  }
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  randomSeed(analogRead(A0));
  showNumber(1);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    showNumber(random(1, 7));

    while (digitalRead(BUTTON_PIN) == LOW) {
      delay(10);
    }

    delay(100);
  }
}
