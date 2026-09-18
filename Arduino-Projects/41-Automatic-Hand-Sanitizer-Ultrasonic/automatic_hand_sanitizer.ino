#include <Servo.h>

/*
  Automatic Hand Sanitizer Dispenser Using Ultrasonic Sensor
  Board: Arduino Uno
*/

Servo dispenserServo;

const int TRIG_PIN = 2;
const int ECHO_PIN = 3;
const int SERVO_PIN = 4;

const int REST_ANGLE = 0;
const int PRESS_ANGLE = 70;
const int HAND_DISTANCE_CM = 15;

long measureDistanceCm();

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dispenserServo.attach(SERVO_PIN);
  dispenserServo.write(REST_ANGLE);
}

void loop() {
  long distance = measureDistanceCm();

  if (distance > 0 && distance <= HAND_DISTANCE_CM) {
    dispenserServo.write(PRESS_ANGLE);
    delay(500);

    dispenserServo.write(REST_ANGLE);
    delay(1500);
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
