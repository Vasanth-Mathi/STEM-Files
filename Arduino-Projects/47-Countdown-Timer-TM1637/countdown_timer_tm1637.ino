#include <TM1637Display.h>
const int CLK_PIN=2,DIO_PIN=3,BUTTON_PIN=4;TM1637Display display(CLK_PIN,DIO_PIN);const int START_SECONDS=60;bool running=false;int remainingSeconds=START_SECONDS;unsigned long lastTick=0;
void showTime(int s){int value=(s/60)*100+(s%60);display.showNumberDecEx(value,0b01000000,true);}
void setup(){pinMode(BUTTON_PIN,INPUT_PULLUP);display.setBrightness(7);showTime(remainingSeconds);}
void loop(){if(!running&&digitalRead(BUTTON_PIN)==LOW){remainingSeconds=START_SECONDS;running=true;lastTick=millis();while(digitalRead(BUTTON_PIN)==LOW)delay(10);}if(running&&millis()-lastTick>=1000){lastTick+=1000;if(remainingSeconds>0){remainingSeconds--;showTime(remainingSeconds);}if(remainingSeconds==0)running=false;}}
