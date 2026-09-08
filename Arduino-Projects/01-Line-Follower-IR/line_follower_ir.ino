/*
  4-Wheel Line Follower Robot Using Two IR Sensors
  Board: Arduino Uno

  Motor arrangement:
  - Left front + left rear motors operate together through L298N channel A.
  - Right front + right rear motors operate together through L298N channel B.
*/

const int leftIR = 2;
const int rightIR = 3;

// Left-side motor group
const int ENA = 5;
const int IN1 = 8;
const int IN2 = 9;

// Right-side motor group
const int ENB = 6;
const int IN3 = 10;
const int IN4 = 11;

const int forwardSpeed = 170;
const int turnSpeed = 90;

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();
}

void loop() {
  int leftSensor = digitalRead(leftIR);
  int rightSensor = digitalRead(rightIR);

  // Assumption: LOW = black line, HIGH = light surface
  if (leftSensor == LOW && rightSensor == LOW) {
    moveForward();
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    turnLeft();
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    turnRight();
  } else {
    stopRobot();
  }
}

void moveForward() {
  setLeftForward(forwardSpeed);
  setRightForward(forwardSpeed);
}

void turnLeft() {
  setLeftForward(turnSpeed);
  setRightForward(forwardSpeed);
}

void turnRight() {
  setLeftForward(forwardSpeed);
  setRightForward(turnSpeed);
}

void stopRobot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setLeftForward(int speedValue) {
  analogWrite(ENA, speedValue);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void setRightForward(int speedValue) {
  analogWrite(ENB, speedValue);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
