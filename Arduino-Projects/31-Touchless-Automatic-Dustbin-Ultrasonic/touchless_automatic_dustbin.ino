#include <Servo.h>
Servo lidServo;const int TRIG_PIN=2,ECHO_PIN=3,SERVO_PIN=4,CLOSED_ANGLE=0,OPEN_ANGLE=90,OPEN_DISTANCE_CM=20;
long measureDistanceCm();
void setup(){pinMode(TRIG_PIN,OUTPUT);pinMode(ECHO_PIN,INPUT);lidServo.attach(SERVO_PIN);lidServo.write(CLOSED_ANGLE);}
void loop(){long d=measureDistanceCm();if(d>0&&d<=OPEN_DISTANCE_CM){lidServo.write(OPEN_ANGLE);delay(2000);lidServo.write(CLOSED_ANGLE);delay(700);}else delay(100);}
long measureDistanceCm(){digitalWrite(TRIG_PIN,LOW);delayMicroseconds(2);digitalWrite(TRIG_PIN,HIGH);delayMicroseconds(10);digitalWrite(TRIG_PIN,LOW);unsigned long t=pulseIn(ECHO_PIN,HIGH,30000UL);return t==0?-1:(long)(t*0.0343/2.0);}
