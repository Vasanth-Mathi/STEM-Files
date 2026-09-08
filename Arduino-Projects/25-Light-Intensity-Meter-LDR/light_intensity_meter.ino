#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
  Light Intensity Meter Using LDR Sensor
  Board: Arduino Uno
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LDR_PIN = A0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  int lightPercent = map(lightValue, 0, 1023, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Raw: ");
  lcd.print(lightValue);
  lcd.print("     ");

  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(lightPercent);
  lcd.print("%   ");

  delay(300);
}
