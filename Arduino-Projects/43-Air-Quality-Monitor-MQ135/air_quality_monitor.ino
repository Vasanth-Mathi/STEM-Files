#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);const int MQ135_PIN=A0,MEDIUM_THRESHOLD=350,HIGH_THRESHOLD=550;
void setup(){lcd.init();lcd.backlight();}
void loop(){int v=analogRead(MQ135_PIN);lcd.setCursor(0,0);lcd.print("Raw: ");lcd.print(v);lcd.print("       ");lcd.setCursor(0,1);lcd.print("Level: ");if(v>=HIGH_THRESHOLD)lcd.print("HIGH   ");else if(v>=MEDIUM_THRESHOLD)lcd.print("MEDIUM ");else lcd.print("LOW    ");delay(500);}
