#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);const int LDR_PIN=A0;
void setup(){lcd.init();lcd.backlight();}
void loop(){int v=analogRead(LDR_PIN);int p=map(v,0,1023,0,100);lcd.setCursor(0,0);lcd.print("Raw: ");lcd.print(v);lcd.print("     ");lcd.setCursor(0,1);lcd.print("Light: ");lcd.print(p);lcd.print("%   ");delay(300);}
