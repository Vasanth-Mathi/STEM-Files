#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);const int LM35_PIN=A0;
void setup(){lcd.init();lcd.backlight();}
void loop(){int raw=analogRead(LM35_PIN);float voltage=raw*(5.0/1023.0);float c=voltage*100.0;lcd.setCursor(0,0);lcd.print("Temperature:   ");lcd.setCursor(0,1);lcd.print(c,1);lcd.print(" C       ");delay(500);}
