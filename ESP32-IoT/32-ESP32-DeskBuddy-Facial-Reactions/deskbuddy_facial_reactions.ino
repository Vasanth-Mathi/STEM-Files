/*
  Project: ESP32 DeskBuddy - Facial Reactions
  Board: ESP32 Dev Module
  Display: SSD1306 128x64 I2C OLED
  Inputs: TTP223 touch sensor, push button
  Outputs: Two SG90 servo ears

  Libraries: Adafruit GFX, Adafruit SSD1306, ESP32Servo
  Power servos from a separate regulated 5V supply.
  Connect external supply GND to ESP32 GND. Never power servos
  from the ESP32 3.3V pin.
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C
const int SDA_PIN=21, SCL_PIN=22, BUTTON_PIN=4, TOUCH_PIN=5;
const int LEFT_SERVO_PIN=18, RIGHT_SERVO_PIN=19;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo leftEar, rightEar;

enum Mood { HAPPY, SAD, ANGRY, SURPRISED, SLEEPY, LOVE, MOOD_COUNT };
Mood currentMood=HAPPY, previousMood=HAPPY;
const int earAngles[MOOD_COUNT][2]={{70,110},{140,40},{125,125},{70,110},{135,45},{80,100}};
int leftNow=90, rightNow=90, leftTarget=70, rightTarget=110;
bool touchWasActive=false, touchReaction=false, wiggleSide=false;
bool buttonWasPressed=false, blinking=false;
unsigned long reactionUntil=0, lastWiggle=0, lastServo=0, lastMood=0;
unsigned long lastButton=0, blinkUntil=0, nextBlink=0;

void drawHeart(int x,int y,int s){
  display.fillCircle(x-s/4,y,s/4,SSD1306_WHITE);
  display.fillCircle(x+s/4,y,s/4,SSD1306_WHITE);
  display.fillTriangle(x-s/2,y,x+s/2,y,x,y+s/2,SSD1306_WHITE);
}
void eye(int x,int y,int r,bool closed){
  if(closed){display.drawFastHLine(x-r,y,2*r+1,SSD1306_WHITE);display.drawFastHLine(x-r+2,y+2,2*r-3,SSD1306_WHITE);}
  else {display.fillCircle(x,y,r,SSD1306_WHITE);display.fillCircle(x,y+1,max(1,r/3),SSD1306_BLACK);}
}
void drawFace(Mood m,bool blink){
  display.clearDisplay();
  display.drawRoundRect(2,2,124,60,8,SSD1306_WHITE);
  int y=25, r=(m==SURPRISED)?9:7;
  if(m==LOVE && !blink){drawHeart(39,y,16);drawHeart(89,y,16);}
  else if(m==SLEEPY){eye(39,y,8,true);eye(89,y,8,true);}
  else {eye(39,y,m==LOVE?8:r,blink);eye(89,y,m==LOVE?8:r,blink);}
  if(m==ANGRY){display.drawLine(26,12,48,18,SSD1306_WHITE);display.drawLine(80,18,102,12,SSD1306_WHITE);}
  if(m==SAD){display.drawLine(27,15,47,11,SSD1306_WHITE);display.drawLine(81,11,101,15,SSD1306_WHITE);}
  if(m==HAPPY||m==LOVE){display.drawLine(48,43,55,49,SSD1306_WHITE);display.drawLine(55,49,73,49,SSD1306_WHITE);display.drawLine(73,49,80,43,SSD1306_WHITE);}
  else if(m==SAD){display.drawLine(48,50,56,44,SSD1306_WHITE);display.drawLine(56,44,72,44,SSD1306_WHITE);display.drawLine(72,44,80,50,SSD1306_WHITE);}
  else if(m==ANGRY){display.drawLine(49,47,79,47,SSD1306_WHITE);display.drawLine(49,47,54,43,SSD1306_WHITE);display.drawLine(79,47,74,43,SSD1306_WHITE);}
  else if(m==SURPRISED)display.drawRoundRect(57,39,14,13,5,SSD1306_WHITE);
  else display.drawFastHLine(52,46,24,SSD1306_WHITE);
  if(m==SLEEPY){display.setTextSize(1);display.setTextColor(SSD1306_WHITE);display.setCursor(99,18);display.print("z");display.setCursor(107,10);display.print("z");}
  display.display();
}
void setMood(Mood m){
  currentMood=m;leftTarget=earAngles[m][0];rightTarget=earAngles[m][1];
  lastMood=millis();drawFace(m,false);
}
void updateEars(){
  if(millis()-lastServo<15)return;lastServo=millis();
  if(leftNow<leftTarget)leftNow++;else if(leftNow>leftTarget)leftNow--;
  if(rightNow<rightTarget)rightNow++;else if(rightNow>rightTarget)rightNow--;
  leftEar.write(leftNow);rightEar.write(rightNow);
}
void handleTouch(){
  bool touched=digitalRead(TOUCH_PIN)==HIGH;
  if(touched&&!touchWasActive&&!touchReaction){
    previousMood=currentMood;touchReaction=true;reactionUntil=millis()+1500;
    lastWiggle=millis();wiggleSide=false;setMood(LOVE);touchReaction=true;
  }
  touchWasActive=touched;
  if(!touchReaction)return;
  if(millis()-lastWiggle>=180){
    lastWiggle=millis();wiggleSide=!wiggleSide;
    if(wiggleSide){leftTarget=65;rightTarget=115;}
    else{leftTarget=105;rightTarget=75;}
  }
  if((long)(millis()-reactionUntil)>=0){touchReaction=false;setMood(previousMood);}
}
void handleButton(){
  if(touchReaction)return;
  bool pressed=digitalRead(BUTTON_PIN)==LOW;unsigned long now=millis();
  if(pressed&&!buttonWasPressed&&now-lastButton>=250){
    lastButton=now;setMood((Mood)((currentMood+1)%MOOD_COUNT));
  }
  buttonWasPressed=pressed;
}
void handleAutoMood(){
  if(touchReaction)return;
  if(millis()-lastMood>=10000){
    Mood next=(Mood)random(MOOD_COUNT);
    if(next==currentMood)next=(Mood)((currentMood+1)%MOOD_COUNT);
    setMood(next);
  }
}
void handleBlink(){
  unsigned long now=millis();
  if(!blinking&&(long)(now-nextBlink)>=0){blinking=true;blinkUntil=now+120;drawFace(currentMood,true);}
  if(blinking&&(long)(now-blinkUntil)>=0){blinking=false;drawFace(currentMood,false);nextBlink=now+random(2500,6001);}
}
void setup(){
  Serial.begin(115200);pinMode(BUTTON_PIN,INPUT_PULLUP);pinMode(TOUCH_PIN,INPUT);
  Wire.begin(SDA_PIN,SCL_PIN);
  if(!display.begin(SSD1306_SWITCHCAPVCC,OLED_ADDR)){Serial.println("OLED not found; check wiring/address.");while(true)delay(100);}
  leftEar.setPeriodHertz(50);rightEar.setPeriodHertz(50);
  leftEar.attach(LEFT_SERVO_PIN,500,2400);rightEar.attach(RIGHT_SERVO_PIN,500,2400);
  leftEar.write(leftNow);rightEar.write(rightNow);randomSeed(micros());
  nextBlink=millis()+random(2500,6001);
  display.clearDisplay();display.setTextColor(SSD1306_WHITE);display.setTextSize(1);
  display.setCursor(28,25);display.print("Hello, human!");display.display();delay(900);
  setMood(HAPPY);Serial.println("DeskBuddy ready.");
}
void loop(){
  handleTouch();
  if(!touchReaction){handleButton();handleAutoMood();}
  updateEars();handleBlink();
}
