#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int air = analogRead(A0);

  lcd.setCursor(0, 0);
  lcd.print("Raw: ");
  lcd.print(air);
  lcd.print("       ");

  lcd.setCursor(0, 1);
  lcd.print("Level: ");

  if (air >= 550) {
    lcd.print("HIGH   ");
  } else if (air >= 350) {
    lcd.print("MEDIUM ");
  } else {
    lcd.print("LOW    ");
  }

  delay(500);
}
