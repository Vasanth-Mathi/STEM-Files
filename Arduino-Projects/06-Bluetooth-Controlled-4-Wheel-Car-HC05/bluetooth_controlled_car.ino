#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3);
const int LEFT_IN1=8,LEFT_IN2=9,RIGHT_IN1=10,RIGHT_IN2=11;
void stopRobot();void moveForward();void moveBackward();void turnLeft();void turnRight();
void setup(){pinMode(LEFT_IN1,OUTPUT);pinMode(LEFT_IN2,OUTPUT);pinMode(RIGHT_IN1,OUTPUT);pinMode(RIGHT_IN2,OUTPUT);bluetooth.begin(9600);stopRobot();}
void loop(){if(bluetooth.available()){char c=bluetooth.read();if(c=='F'||c=='f')moveForward();else if(c=='B'||c=='b')moveBackward();else if(c=='L'||c=='l')turnLeft();else if(c=='R'||c=='r')turnRight();else if(c=='S'||c=='s')stopRobot();}}
void moveForward(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void moveBackward(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,HIGH);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,HIGH);}
void turnLeft(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void turnRight(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
void stopRobot(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
