#include <Servo.h>
Servo dispenserServo;const int TRIG_PIN=2,ECHO_PIN=3,SERVO_PIN=4,REST_ANGLE=0,PRESS_ANGLE=70,HAND_DISTANCE_CM=15;
long measureDistanceCm();
void setup(){pinMode(TRIG_PIN,OUTPUT);pinMode(ECHO_PIN,INPUT);dispenserServo.attach(SERVO_PIN);dispenserServo.write(REST_ANGLE);}
void loop(){long d=measureDistanceCm();if(d>0&&d<=HAND_DISTANCE_CM){dispenserServo.write(PRESS_ANGLE);delay(500);dispenserServo.write(REST_ANGLE);delay(1500);}else delay(100);}
long measureDistanceCm(){digitalWrite(TRIG_PIN,LOW);delayMicroseconds(2);digitalWrite(TRIG_PIN,HIGH);delayMicroseconds(10);digitalWrite(TRIG_PIN,LOW);unsigned long t=pulseIn(ECHO_PIN,HIGH,30000UL);return t==0?-1:(long)(t*0.0343/2.0);}
