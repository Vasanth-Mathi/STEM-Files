#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
  Digital Measuring Tape Using Ultrasonic Sensor
  Board: Arduino Uno
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int TRIG_PIN = 2;
const int ECHO_PIN = 3;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);

  if (duration == 0) {
    lcd.print("Out of range");
  } else {
    float distance = duration * 0.0343 / 2.0;
    lcd.print(distance, 1);
    lcd.print(" cm");
  }

  delay(300);
}
