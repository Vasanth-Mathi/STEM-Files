const int TRIG_PIN=2,ECHO_PIN=3,LEFT_IR=4,RIGHT_IR=5;
const int LEFT_IN1=8,LEFT_IN2=9,RIGHT_IN1=10,RIGHT_IN2=11;
const int IR_DETECTED_STATE=LOW,MIN_DISTANCE=15,MAX_DISTANCE=35;
long measureDistanceCm();void stopRobot();void moveForward();void moveBackward();void turnLeft();void turnRight();
void setup(){pinMode(TRIG_PIN,OUTPUT);pinMode(ECHO_PIN,INPUT);pinMode(LEFT_IR,INPUT);pinMode(RIGHT_IR,INPUT);pinMode(LEFT_IN1,OUTPUT);pinMode(LEFT_IN2,OUTPUT);pinMode(RIGHT_IN1,OUTPUT);pinMode(RIGHT_IN2,OUTPUT);stopRobot();}
void loop(){long d=measureDistanceCm();if(d<0)stopRobot();else if(d>MAX_DISTANCE)moveForward();else if(d<MIN_DISTANCE)moveBackward();else{bool l=digitalRead(LEFT_IR)==IR_DETECTED_STATE,r=digitalRead(RIGHT_IR)==IR_DETECTED_STATE;if(l&&!r)turnLeft();else if(r&&!l)turnRight();else stopRobot();}delay(70);}
long measureDistanceCm(){digitalWrite(TRIG_PIN,LOW);delayMicroseconds(2);digitalWrite(TRIG_PIN,HIGH);delayMicroseconds(10);digitalWrite(TRIG_PIN,LOW);unsigned long t=pulseIn(ECHO_PIN,HIGH,30000UL);if(t==0)return -1;long d=(long)(t*0.0343/2.0);return(d<2||d>400)?-1:d;}
void moveForward(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void moveBackward(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,HIGH);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,HIGH);}
void turnLeft(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void turnRight(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
void stopRobot(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
