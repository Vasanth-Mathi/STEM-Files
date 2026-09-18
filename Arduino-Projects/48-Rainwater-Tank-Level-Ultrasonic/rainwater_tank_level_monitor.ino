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
  lcd.print("Tank Level:     ");
  lcd.setCursor(0, 1);

  if (duration == 0) {
    lcd.print("Sensor error    ");
  } else {
    int distance = duration * 0.0343 / 2;
    int level = (100 - distance) * 100 / 100;

    level = constrain(level, 0, 100);

    lcd.print(level);
    lcd.print("%            ");
  }

  delay(500);
}
