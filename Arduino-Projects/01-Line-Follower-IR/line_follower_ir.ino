/*
  Line Follower Robot Using Two IR Sensors
  Board: Arduino Uno
*/

const int leftIR = 2;
const int rightIR = 3;

const int ENA = 5;
const int IN1 = 8;
const int IN2 = 9;

const int ENB = 6;
const int IN3 = 10;
const int IN4 = 11;

const int motorSpeed = 150;

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

  // Assumption: LOW = black line, HIGH = white surface
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
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, 80);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, 80);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
