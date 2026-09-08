#include <Servo.h>

/*
  Obstacle Avoiding Robot Using Ultrasonic Sensor and Servo Motor
  Board: Arduino Uno
  Motors: 4
  Motor Drivers: 2 x L298N

  Keep ENA and ENB jumpers fitted on both L298N modules.
*/

Servo scannerServo;

const int trigPin = 2;
const int echoPin = 3;
const int servoPin = 4;

const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

const int obstacleDistance = 20; // cm

const int centerAngle = 90;
const int leftAngle = 150;
const int rightAngle = 30;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  scannerServo.attach(servoPin);
  scannerServo.write(centerAngle);
  delay(500);

  stopRobot();
}

void loop() {
  long frontDistance = measureDistance();

  if (frontDistance < 0) {
    stopRobot();
    delay(100);
    return;
  }

  if (frontDistance > obstacleDistance) {
    moveForward();
    delay(70);
    return;
  }

  stopRobot();
  delay(200);

  moveBackward();
  delay(400);

  stopRobot();
  delay(150);

  long leftDistance = lookAndMeasure(leftAngle);
  long rightDistance = lookAndMeasure(rightAngle);

  scannerServo.write(centerAngle);
  delay(400);

  if (leftDistance < 0 && rightDistance < 0) {
    stopRobot();
    return;
  }

  if (leftDistance >= 0 && rightDistance < 0) {
    turnLeft();
  } else if (rightDistance >= 0 && leftDistance < 0) {
    turnRight();
  } else if (leftDistance > rightDistance) {
    turnLeft();
  } else {
    turnRight();
  }

  delay(650);
  stopRobot();
  delay(150);
}

long lookAndMeasure(int angle) {
  scannerServo.write(angle);
  delay(450);

  long distance = measureDistance();
  delay(70);
  return distance;
}

long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);

  if (duration == 0) {
    return -1;
  }

  long distance = (long)(duration * 0.0343 / 2.0);

  if (distance < 2 || distance > 400) {
    return -1;
  }

  return distance;
}

void moveForward() {
  leftForward();
  rightForward();
}

void moveBackward() {
  leftBackward();
  rightBackward();
}

void turnLeft() {
  leftBackward();
  rightForward();
}

void turnRight() {
  leftForward();
  rightBackward();
}

void stopRobot() {
  leftStop();
  rightStop();
}

void leftForward() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
}

void leftBackward() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);
}

void rightForward() {
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void rightBackward() {
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void leftStop() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
}

void rightStop() {
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}
