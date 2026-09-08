#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
  Visitor Counter Using IR Sensors
  Board: Arduino Uno
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int SENSOR_1 = 2;
const int SENSOR_2 = 3;
const int DETECTED_STATE = LOW;

int count = 0;
int sequenceState = 0;

unsigned long sequenceStart = 0;
const unsigned long SEQUENCE_TIMEOUT = 2000;

bool active(int pin) {
  return digitalRead(pin) == DETECTED_STATE;
}

void showCount() {
  lcd.setCursor(0, 0);
  lcd.print("Visitors:       ");

  lcd.setCursor(0, 1);
  lcd.print(count);
  lcd.print("               ");
}

void setup() {
  pinMode(SENSOR_1, INPUT);
  pinMode(SENSOR_2, INPUT);

  lcd.init();
  lcd.backlight();
  showCount();
}

void loop() {
  if (sequenceState == 0) {
    if (active(SENSOR_1) && !active(SENSOR_2)) {
      sequenceState = 1;
      sequenceStart = millis();
    } else if (active(SENSOR_2) && !active(SENSOR_1)) {
      sequenceState = 2;
      sequenceStart = millis();
    }
  } else if (sequenceState == 1) {
    if (active(SENSOR_2)) {
      count++;
      showCount();
      sequenceState = 3;
    }
  } else if (sequenceState == 2) {
    if (active(SENSOR_1)) {
      if (count > 0) {
        count--;
      }

      showCount();
      sequenceState = 3;
    }
  } else if (sequenceState == 3) {
    if (!active(SENSOR_1) && !active(SENSOR_2)) {
      sequenceState = 0;
    }
  }

  if ((sequenceState == 1 || sequenceState == 2) &&
      millis() - sequenceStart > SEQUENCE_TIMEOUT) {
    sequenceState = 0;
  }

  delay(20);
}
