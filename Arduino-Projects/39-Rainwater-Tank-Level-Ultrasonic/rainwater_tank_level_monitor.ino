#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);const int TRIG_PIN=2,ECHO_PIN=3;const float TANK_DEPTH_CM=100.0;
long measureDistanceCm();
void setup(){pinMode(TRIG_PIN,OUTPUT);pinMode(ECHO_PIN,INPUT);lcd.init();lcd.backlight();}
void loop(){long d=measureDistanceCm();lcd.setCursor(0,0);lcd.print("Tank Level:     ");lcd.setCursor(0,1);if(d<0)lcd.print("Sensor error    ");else{int p=(int)((TANK_DEPTH_CM-d)*100.0/TANK_DEPTH_CM);p=constrain(p,0,100);lcd.print(p);lcd.print("%            ");}delay(500);}
long measureDistanceCm(){digitalWrite(TRIG_PIN,LOW);delayMicroseconds(2);digitalWrite(TRIG_PIN,HIGH);delayMicroseconds(10);digitalWrite(TRIG_PIN,LOW);unsigned long t=pulseIn(ECHO_PIN,HIGH,30000UL);if(t==0)return -1;long d=(long)(t*0.0343/2.0);return(d<2||d>400)?-1:d;}
