#include <Wire.h>
#include "paj7620.h"

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Wire.begin();
  paj7620Init();
}

void loop() {
  uint8_t gesture = 0;

  if (paj7620ReadReg(0x43, 1, &gesture) == 0) {
    if (gesture == GES_UP_FLAG) {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
    } else if (gesture == GES_DOWN_FLAG) {
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    } else if (gesture == GES_LEFT_FLAG) {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
    } else if (gesture == GES_RIGHT_FLAG) {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    } else if (gesture == GES_WAVE_FLAG) {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }
  }

  delay(100);
}
