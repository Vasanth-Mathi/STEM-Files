#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
  Rainwater Tank Level Monitor Using Ultrasonic Sensor
  Board: Arduino Uno
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int TRIG_PIN = 2;
const int ECHO_PIN = 3;
const float TANK_DEPTH_CM = 100.0;

long measureDistanceCm();

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  long distance = measureDistanceCm();

  lcd.setCursor(0, 0);
  lcd.print("Tank Level:     ");

  lcd.setCursor(0, 1);

  if (distance < 0) {
    lcd.print("Sensor error    ");
  } else {
    int levelPercent = (int)((TANK_DEPTH_CM - distance) * 100.0 / TANK_DEPTH_CM);
    levelPercent = constrain(levelPercent, 0, 100);

    lcd.print(levelPercent);
    lcd.print("%            ");
  }

  delay(500);
}

long measureDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    return -1;
  }

  long distance = (long)(duration * 0.0343 / 2.0);

  if (distance < 2 || distance > 400) {
    return -1;
  }

  return distance;
}
