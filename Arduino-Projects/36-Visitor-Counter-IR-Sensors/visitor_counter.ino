#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int count = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Visitors:");
  lcd.setCursor(0, 1);
  lcd.print(count);
}

void loop() {
  if (digitalRead(2) == LOW && digitalRead(3) == HIGH) {
    while (digitalRead(2) == LOW) {
      delay(10);
    }

    unsigned long start = millis();

    while (digitalRead(3) == HIGH && millis() - start < 2000) {
      delay(10);
    }

    if (digitalRead(3) == LOW) {
      count++;

      lcd.setCursor(0, 1);
      lcd.print(count);
      lcd.print("               ");

      while (digitalRead(3) == LOW) {
        delay(10);
      }
    }
  }

  if (digitalRead(3) == LOW && digitalRead(2) == HIGH) {
    while (digitalRead(3) == LOW) {
      delay(10);
    }

    unsigned long start = millis();

    while (digitalRead(2) == HIGH && millis() - start < 2000) {
      delay(10);
    }

    if (digitalRead(2) == LOW) {
      if (count > 0) {
        count--;
      }

      lcd.setCursor(0, 1);
      lcd.print(count);
      lcd.print("               ");

      while (digitalRead(2) == LOW) {
        delay(10);
      }
    }
  }
}
