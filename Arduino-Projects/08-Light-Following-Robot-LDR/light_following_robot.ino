/*
  Light Following Robot Using LDR Sensors
  Board: Arduino Uno
*/

const int LEFT_LDR = A0;
const int RIGHT_LDR = A1;

const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

const int DIFFERENCE = 60;

void stopRobot();
void moveForward();
void turnLeft();
void turnRight();

void setup() {
  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  stopRobot();
}

void loop() {
  int leftLight = analogRead(LEFT_LDR);
  int rightLight = analogRead(RIGHT_LDR);

  if (leftLight > rightLight + DIFFERENCE) {
    turnLeft();
  } else if (rightLight > leftLight + DIFFERENCE) {
    turnRight();
  } else {
    moveForward();
  }

  delay(50);
}

void moveForward() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void turnLeft() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void turnRight() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}

void stopRobot() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}
