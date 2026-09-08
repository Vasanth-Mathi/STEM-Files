/*
  Line Follower Robot Using IR Sensors
  Board: Arduino Uno
  Motors: 4
  Motor Drivers: 2 x L298N

  Keep ENA and ENB jumpers fitted on both L298N modules.
*/

const int leftIR = 2;
const int rightIR = 3;

// These four Arduino pins are connected to BOTH motor drivers.
// This makes the front and rear motors on the same side move together.
const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

// Change to HIGH if your IR sensor gives HIGH when it sees black.
const int BLACK_STATE = LOW;

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  stopRobot();
}

void loop() {
  bool leftOnBlack = digitalRead(leftIR) == BLACK_STATE;
  bool rightOnBlack = digitalRead(rightIR) == BLACK_STATE;

  if (!leftOnBlack && !rightOnBlack) {
    moveForward();
  } else if (leftOnBlack && !rightOnBlack) {
    turnLeft();
  } else if (!leftOnBlack && rightOnBlack) {
    turnRight();
  } else {
    stopRobot();
  }
}

void moveForward() {
  leftForward();
  rightForward();
}

void turnLeft() {
  leftStop();
  rightForward();
}

void turnRight() {
  leftForward();
  rightStop();
}

void stopRobot() {
  leftStop();
  rightStop();
}

void leftForward() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
}

void rightForward() {
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void leftStop() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
}

void rightStop() {
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}
