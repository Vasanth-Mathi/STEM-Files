#include <TM1637Display.h>

TM1637Display display(2, 3);

void setup() {
  pinMode(4, INPUT_PULLUP);
  display.setBrightness(7);
  display.showNumberDecEx(100, 0b01000000, true);
}

void loop() {
  if (digitalRead(4) == LOW) {
    while (digitalRead(4) == LOW) {
      delay(10);
    }

    for (int seconds = 60; seconds >= 0; seconds--) {
      int value = (seconds / 60) * 100 + (seconds % 60);
      display.showNumberDecEx(value, 0b01000000, true);
      delay(1000);
    }
  }
}
