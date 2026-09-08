#include <Servo.h>

/*
  Touchless Automatic Dustbin Using Ultrasonic Sensor
  Board: Arduino Uno
*/

Servo lidServo;

const int TRIG_PIN = 2;
const int ECHO_PIN = 3;
const int SERVO_PIN = 4;

const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE = 90;
const int OPEN_DISTANCE_CM = 20;

long measureDistanceCm();

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lidServo.attach(SERVO_PIN);
  lidServo.write(CLOSED_ANGLE);
}

void loop() {
  long distance = measureDistanceCm();

  if (distance > 0 && distance <= OPEN_DISTANCE_CM) {
    lidServo.write(OPEN_ANGLE);
    delay(2000);

    lidServo.write(CLOSED_ANGLE);
    delay(700);
  } else {
    delay(100);
  }
}

long measureDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    return -1;
  }

  return (long)(duration * 0.0343 / 2.0);
}
