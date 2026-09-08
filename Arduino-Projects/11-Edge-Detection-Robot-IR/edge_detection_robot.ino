/*
  Edge Detection Robot Using IR Sensors
  Board: Arduino Uno
*/

const int LEFT_IR = 2;
const int RIGHT_IR = 3;

const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

const int FLOOR_STATE = LOW;

void stopRobot();
void moveForward();
void moveBackward();
void pivotLeft();
void pivotRight();

void setup() {
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);

  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  stopRobot();
}

void loop() {
  bool leftOnFloor = digitalRead(LEFT_IR) == FLOOR_STATE;
  bool rightOnFloor = digitalRead(RIGHT_IR) == FLOOR_STATE;

  if (leftOnFloor && rightOnFloor) {
    moveForward();
  } else {
    moveBackward();
    delay(350);

    if (!leftOnFloor && rightOnFloor) {
      pivotRight();
    } else if (leftOnFloor && !rightOnFloor) {
      pivotLeft();
    } else {
      pivotRight();
    }

    delay(450);
    stopRobot();
    delay(100);
  }
}

void moveForward() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void moveBackward() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void pivotLeft() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void pivotRight() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void stopRobot() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}
