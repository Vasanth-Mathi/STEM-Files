#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
  Temperature Monitor Using LM35 Sensor
  Board: Arduino Uno
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LM35_PIN = A0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int rawValue = analogRead(LM35_PIN);

  float voltage = rawValue * (5.0 / 1023.0);
  float temperatureC = voltage * 100.0;

  lcd.setCursor(0, 0);
  lcd.print("Temperature:   ");

  lcd.setCursor(0, 1);
  lcd.print(temperatureC, 1);
  lcd.print(" C       ");

  delay(500);
}
