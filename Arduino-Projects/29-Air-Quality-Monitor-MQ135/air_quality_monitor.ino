#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
  Air Quality Monitoring System Using MQ-135 Sensor
  Board: Arduino Uno
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int MQ135_PIN = A0;
const int MEDIUM_THRESHOLD = 350;
const int HIGH_THRESHOLD = 550;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int sensorValue = analogRead(MQ135_PIN);

  lcd.setCursor(0, 0);
  lcd.print("Raw: ");
  lcd.print(sensorValue);
  lcd.print("       ");

  lcd.setCursor(0, 1);
  lcd.print("Level: ");

  if (sensorValue >= HIGH_THRESHOLD) {
    lcd.print("HIGH   ");
  } else if (sensorValue >= MEDIUM_THRESHOLD) {
    lcd.print("MEDIUM ");
  } else {
    lcd.print("LOW    ");
  }

  delay(500);
}
