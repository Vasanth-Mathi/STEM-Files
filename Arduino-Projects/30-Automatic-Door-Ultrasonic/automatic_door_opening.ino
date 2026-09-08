#include <Servo.h>

/*
  Automatic Door Opening System Using Ultrasonic Sensor
  Board: Arduino Uno
*/

Servo doorServo;

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

  doorServo.attach(SERVO_PIN);
  doorServo.write(CLOSED_ANGLE);
}

void loop() {
  long distance = measureDistanceCm();

  if (distance > 0 && distance <= OPEN_DISTANCE_CM) {
    doorServo.write(OPEN_ANGLE);
  } else {
    doorServo.write(CLOSED_ANGLE);
  }

  delay(100);
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

  long distance = (long)(duration * 0.0343 / 2.0);

  if (distance < 2 || distance > 400) {
    return -1;
  }

  return distance;
}
