#include <TM1637Display.h>

/*
  Digital Stopwatch Using TM1637 Display
  Board: Arduino Uno
*/

const int CLK_PIN = 2;
const int DIO_PIN = 3;
const int START_STOP_PIN = 4;
const int RESET_PIN = 5;

TM1637Display display(CLK_PIN, DIO_PIN);

bool running = false;

unsigned long accumulatedMs = 0;
unsigned long runStartMs = 0;

bool lastStartState = HIGH;
bool lastResetState = HIGH;

void showElapsed(unsigned long milliseconds) {
  unsigned long seconds = (milliseconds / 1000) % 6000;
  int displayValue = (seconds / 60) * 100 + (seconds % 60);

  display.showNumberDecEx(displayValue, 0b01000000, true);
}

void setup() {
  pinMode(START_STOP_PIN, INPUT_PULLUP);
  pinMode(RESET_PIN, INPUT_PULLUP);

  display.setBrightness(7);
  showElapsed(0);
}

void loop() {
  bool startState = digitalRead(START_STOP_PIN);
  bool resetState = digitalRead(RESET_PIN);

  if (startState == LOW && lastStartState == HIGH) {
    if (running) {
      accumulatedMs += millis() - runStartMs;
      running = false;
    } else {
      runStartMs = millis();
      running = true;
    }

    delay(30);
  }

  if (resetState == LOW && lastResetState == HIGH) {
    running = false;
    accumulatedMs = 0;
    showElapsed(0);

    delay(30);
  }

  unsigned long elapsed = accumulatedMs;

  if (running) {
    elapsed += millis() - runStartMs;
  }

  showElapsed(elapsed);

  lastStartState = startState;
  lastResetState = resetState;

  delay(20);
}
