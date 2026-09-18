#include <TM1637Display.h>

TM1637Display display(2, 3);

int running = 0;
unsigned long startTime = 0;
unsigned long savedTime = 0;

void setup() {
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  display.setBrightness(7);
  display.showNumberDecEx(0, 0b01000000, true);
}

void loop() {
  if (digitalRead(4) == LOW) {
    if (running == 0) {
      running = 1;
      startTime = millis();
    } else {
      running = 0;
      savedTime = savedTime + millis() - startTime;
    }

    while (digitalRead(4) == LOW) {
      delay(10);
    }

    delay(50);
  }

  if (digitalRead(5) == LOW) {
    running = 0;
    savedTime = 0;

    while (digitalRead(5) == LOW) {
      delay(10);
    }

    delay(50);
  }

  unsigned long totalTime = savedTime;

  if (running == 1) {
    totalTime = savedTime + millis() - startTime;
  }

  unsigned long seconds = (totalTime / 1000) % 6000;
  int value = (seconds / 60) * 100 + (seconds % 60);

  display.showNumberDecEx(value, 0b01000000, true);
  delay(20);
}
