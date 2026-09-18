#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int light = analogRead(A0);
  int percent = map(light, 0, 1023, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Raw: ");
  lcd.print(light);
  lcd.print("     ");

  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(percent);
  lcd.print("%   ");

  delay(300);
}
