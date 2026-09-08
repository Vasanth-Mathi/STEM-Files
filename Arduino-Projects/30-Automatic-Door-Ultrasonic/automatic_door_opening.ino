#include <Servo.h>
Servo doorServo;const int TRIG_PIN=2,ECHO_PIN=3,SERVO_PIN=4,CLOSED_ANGLE=0,OPEN_ANGLE=90,OPEN_DISTANCE_CM=20;
long measureDistanceCm();
void setup(){pinMode(TRIG_PIN,OUTPUT);pinMode(ECHO_PIN,INPUT);doorServo.attach(SERVO_PIN);doorServo.write(CLOSED_ANGLE);}
void loop(){long d=measureDistanceCm();doorServo.write((d>0&&d<=OPEN_DISTANCE_CM)?OPEN_ANGLE:CLOSED_ANGLE);delay(100);}
long measureDistanceCm(){digitalWrite(TRIG_PIN,LOW);delayMicroseconds(2);digitalWrite(TRIG_PIN,HIGH);delayMicroseconds(10);digitalWrite(TRIG_PIN,LOW);unsigned long t=pulseIn(ECHO_PIN,HIGH,30000UL);if(t==0)return -1;long d=(long)(t*0.0343/2.0);return(d<2||d>400)?-1:d;}
