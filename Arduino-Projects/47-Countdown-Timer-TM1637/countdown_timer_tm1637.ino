#include <TM1637Display.h>

/*
  Countdown Timer Using TM1637 Display
  Board: Arduino Uno
*/

const int CLK_PIN = 2;
const int DIO_PIN = 3;
const int BUTTON_PIN = 4;

TM1637Display display(CLK_PIN, DIO_PIN);

const int START_SECONDS = 60;

bool running = false;
int remainingSeconds = START_SECONDS;
unsigned long lastTick = 0;

void showTime(int seconds) {
  int displayValue = (seconds / 60) * 100 + (seconds % 60);
  display.showNumberDecEx(displayValue, 0b01000000, true);
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  display.setBrightness(7);
  showTime(remainingSeconds);
}

void loop() {
  if (!running && digitalRead(BUTTON_PIN) == LOW) {
    remainingSeconds = START_SECONDS;
    running = true;
    lastTick = millis();

    while (digitalRead(BUTTON_PIN) == LOW) {
      delay(10);
    }
  }

  if (running && millis() - lastTick >= 1000) {
    lastTick += 1000;

    if (remainingSeconds > 0) {
      remainingSeconds--;
      showTime(remainingSeconds);
    }

    if (remainingSeconds == 0) {
      running = false;
    }
  }
}
