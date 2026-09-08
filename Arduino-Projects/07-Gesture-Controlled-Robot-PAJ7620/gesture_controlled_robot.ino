#include <Wire.h>
#include "paj7620.h"
const int LEFT_IN1=8,LEFT_IN2=9,RIGHT_IN1=10,RIGHT_IN2=11;
void stopRobot();void moveForward();void moveBackward();void turnLeft();void turnRight();
void setup(){pinMode(LEFT_IN1,OUTPUT);pinMode(LEFT_IN2,OUTPUT);pinMode(RIGHT_IN1,OUTPUT);pinMode(RIGHT_IN2,OUTPUT);Wire.begin();paj7620Init();stopRobot();}
void loop(){uint8_t g=0;if(paj7620ReadReg(0x43,1,&g)==0){if(g==GES_UP_FLAG)moveForward();else if(g==GES_DOWN_FLAG)moveBackward();else if(g==GES_LEFT_FLAG)turnLeft();else if(g==GES_RIGHT_FLAG)turnRight();else if(g==GES_WAVE_FLAG)stopRobot();}delay(100);}
void moveForward(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void moveBackward(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,HIGH);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,HIGH);}
void turnLeft(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void turnRight(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
void stopRobot(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
