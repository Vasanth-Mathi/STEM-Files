#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH, 30000);

  lcd.setCursor(0, 0);
  lcd.print("Distance:       ");
  lcd.setCursor(0, 1);

  if (duration == 0) {
    lcd.print("Out of range    ");
  } else {
    float distance = duration * 0.0343 / 2.0;
    lcd.print(distance, 1);
    lcd.print(" cm       ");
  }

  delay(300);
}
