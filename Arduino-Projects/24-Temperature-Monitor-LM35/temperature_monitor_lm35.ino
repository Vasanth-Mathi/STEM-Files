#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int reading = analogRead(A0);
  float temperature = reading * (5.0 / 1023.0) * 100.0;

  lcd.setCursor(0, 0);
  lcd.print("Temperature:   ");

  lcd.setCursor(0, 1);
  lcd.print(temperature, 1);
  lcd.print(" C       ");

  delay(500);
}
