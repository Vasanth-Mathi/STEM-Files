/*
  Object Following Robot Using Ultrasonic and IR Sensors
  Board: Arduino Uno
*/

const int TRIG_PIN = 2;
const int ECHO_PIN = 3;
const int LEFT_IR = 4;
const int RIGHT_IR = 5;

const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

const int IR_DETECTED_STATE = LOW;
const int MIN_DISTANCE = 15;
const int MAX_DISTANCE = 35;

long measureDistanceCm();
void stopRobot();
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);

  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  stopRobot();
}

void loop() {
  long distance = measureDistanceCm();

  if (distance < 0) {
    stopRobot();
  } else if (distance > MAX_DISTANCE) {
    moveForward();
  } else if (distance < MIN_DISTANCE) {
    moveBackward();
  } else {
    bool leftDetected = digitalRead(LEFT_IR) == IR_DETECTED_STATE;
    bool rightDetected = digitalRead(RIGHT_IR) == IR_DETECTED_STATE;

    if (leftDetected && !rightDetected) {
      turnLeft();
    } else if (rightDetected && !leftDetected) {
      turnRight();
    } else {
      stopRobot();
    }
  }

  delay(70);
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
