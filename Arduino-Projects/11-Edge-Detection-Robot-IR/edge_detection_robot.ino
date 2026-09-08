const int LEFT_IR=2,RIGHT_IR=3;
const int LEFT_IN1=8,LEFT_IN2=9,RIGHT_IN1=10,RIGHT_IN2=11;
const int FLOOR_STATE=LOW;
void stopRobot();void moveForward();void moveBackward();void pivotLeft();void pivotRight();
void setup(){pinMode(LEFT_IR,INPUT);pinMode(RIGHT_IR,INPUT);pinMode(LEFT_IN1,OUTPUT);pinMode(LEFT_IN2,OUTPUT);pinMode(RIGHT_IN1,OUTPUT);pinMode(RIGHT_IN2,OUTPUT);stopRobot();}
void loop(){bool l=digitalRead(LEFT_IR)==FLOOR_STATE,r=digitalRead(RIGHT_IR)==FLOOR_STATE;if(l&&r)moveForward();else{moveBackward();delay(350);if(!l&&r)pivotRight();else if(l&&!r)pivotLeft();else pivotRight();delay(450);stopRobot();delay(100);}}
void moveForward(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void moveBackward(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,HIGH);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,HIGH);}
void pivotLeft(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,HIGH);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void pivotRight(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,HIGH);}
void stopRobot(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
