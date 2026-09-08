#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);LiquidCrystal_I2C lcd(0x27,16,2);
void setup(){dht.begin();lcd.init();lcd.backlight();}
void loop(){float h=dht.readHumidity(),t=dht.readTemperature();if(isnan(h)||isnan(t)){lcd.setCursor(0,0);lcd.print("Sensor error    ");lcd.setCursor(0,1);lcd.print("                ");}else{lcd.setCursor(0,0);lcd.print("Temp: ");lcd.print(t,1);lcd.print(" C   ");lcd.setCursor(0,1);lcd.print("Humidity: ");lcd.print(h,0);lcd.print("%  ");}delay(2000);}
