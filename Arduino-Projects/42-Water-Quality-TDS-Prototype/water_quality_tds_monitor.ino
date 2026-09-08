#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);const int TDS_PIN=A0,SAMPLE_COUNT=20;
void setup(){lcd.init();lcd.backlight();}
void loop(){long total=0;for(int i=0;i<SAMPLE_COUNT;i++){total+=analogRead(TDS_PIN);delay(20);}float raw=total/(float)SAMPLE_COUNT;float v=raw*(5.0/1023.0);float tds=(133.42*v*v*v-255.86*v*v+857.39*v)*0.5;if(tds<0)tds=0;lcd.setCursor(0,0);lcd.print("TDS Estimate:   ");lcd.setCursor(0,1);lcd.print(tds,0);lcd.print(" ppm        ");delay(1000);}
