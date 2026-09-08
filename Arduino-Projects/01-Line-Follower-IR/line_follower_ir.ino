/*
  4-Wheel Line Follower Robot Using Two IR Sensors
  Board: Arduino Uno
  Motors: 4 DC geared motors
  Motor Drivers: 2 x L298N

  Driver 1 controls the front motors.
  Driver 2 controls the rear motors.
  Both drivers share the same left/right control signals so that
  front and rear motors on each side move together.
*/

const int leftIR = 2;
const int rightIR = 3;

// Shared LEFT-side motor control for both L298N modules
const int LEFT_EN = 5;   // PWM
const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;

// Shared RIGHT-side motor control for both L298N modules
const int RIGHT_EN = 6;  // PWM
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

// Change to HIGH if your IR modules output HIGH on black.
const int BLACK_STATE = LOW;

const int forwardSpeed = 170;
const int correctionSpeed = 80;

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(LEFT_EN, OUTPUT);
  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);

  pinMode(RIGHT_EN, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  stopRobot();
}

void loop() {
  const int leftState = digitalRead(leftIR);
  const int rightState = digitalRead(rightIR);

  const bool leftOnBlack = (leftState == BLACK_STATE);
  const bool rightOnBlack = (rightState == BLACK_STATE);

  // Sensors are mounted so the line normally runs between them.
  if (!leftOnBlack && !rightOnBlack) {
    moveForward();
  } else if (leftOnBlack && !rightOnBlack) {
    steerLeft();
  } else if (!leftOnBlack && rightOnBlack) {
    steerRight();
  } else {
    // Both sensors on black: stop at a wide line/junction/end marker.
    stopRobot();
  }
}

void setLeftMotorsForward(int speedValue) {
  analogWrite(LEFT_EN, constrain(speedValue, 0, 255));
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
}

void setRightMotorsForward(int speedValue) {
  analogWrite(RIGHT_EN, constrain(speedValue, 0, 255));
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void moveForward() {
  setLeftMotorsForward(forwardSpeed);
  setRightMotorsForward(forwardSpeed);
}

void steerLeft() {
  setLeftMotorsForward(correctionSpeed);
  setRightMotorsForward(forwardSpeed);
}

void steerRight() {
  setLeftMotorsForward(forwardSpeed);
  setRightMotorsForward(correctionSpeed);
}

void stopRobot() {
  analogWrite(LEFT_EN, 0);
  analogWrite(RIGHT_EN, 0);

  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}
