#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

/*
  Greenhouse Temperature Monitor Using DHT11 Sensor
  Board: Arduino Uno
*/

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();

  lcd.init();
  lcd.backlight();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor error    ");

    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print(" C   ");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humidity, 0);
    lcd.print("%  ");
  }

  delay(2000);
}
