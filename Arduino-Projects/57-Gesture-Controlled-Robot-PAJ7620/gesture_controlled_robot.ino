#include <Wire.h>
#include "paj7620.h"

/*
  Gesture Controlled Robot Car Using PAJ7620
  Board: Arduino Uno
*/

const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

void stopRobot();
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();

void setup() {
  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  Wire.begin();
  paj7620Init();
  stopRobot();
}

void loop() {
  uint8_t gesture = 0;

  if (paj7620ReadReg(0x43, 1, &gesture) == 0) {
    if (gesture == GES_UP_FLAG) {
      moveForward();
    } else if (gesture == GES_DOWN_FLAG) {
      moveBackward();
    } else if (gesture == GES_LEFT_FLAG) {
      turnLeft();
    } else if (gesture == GES_RIGHT_FLAG) {
      turnRight();
    } else if (gesture == GES_WAVE_FLAG) {
      stopRobot();
    }
  }

  delay(100);
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
