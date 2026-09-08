/*
  Obstacle Avoiding Robot Using Ultrasonic Sensor
  Board: Arduino Uno
  Motors: 4
  Motor Drivers: 2 x L298N

  Keep ENA and ENB jumpers fitted on both L298N modules.
*/

const int trigPin = 2;
const int echoPin = 3;

const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

const int obstacleDistance = 20; // cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  Serial.begin(9600);
  stopRobot();
}

void loop() {
  float distance = measureDistance();

  if (distance < 0) {
    stopRobot();
    delay(100);
    return;
  }

  if (distance <= obstacleDistance) {
    stopRobot();
    delay(200);

    moveBackward();
    delay(450);

    stopRobot();
    delay(150);

    turnRight();
    delay(650);

    stopRobot();
    delay(150);
  } else {
    moveForward();
  }

  delay(70);
}

float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);

  if (duration == 0) {
    return -1.0;
  }

  return duration * 0.0343 / 2.0;
}

void moveForward() {
  leftForward();
  rightForward();
}

void moveBackward() {
  leftBackward();
  rightBackward();
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
