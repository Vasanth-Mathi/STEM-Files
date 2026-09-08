#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int TRIG_PIN=2,ECHO_PIN=3;
void setup(){pinMode(TRIG_PIN,OUTPUT);pinMode(ECHO_PIN,INPUT);lcd.init();lcd.backlight();}
void loop(){digitalWrite(TRIG_PIN,LOW);delayMicroseconds(2);digitalWrite(TRIG_PIN,HIGH);delayMicroseconds(10);digitalWrite(TRIG_PIN,LOW);unsigned long t=pulseIn(ECHO_PIN,HIGH,30000UL);lcd.clear();lcd.setCursor(0,0);lcd.print("Distance:");lcd.setCursor(0,1);if(t==0)lcd.print("Out of range");else{float d=t*0.0343/2.0;lcd.print(d,1);lcd.print(" cm");}delay(300);}
