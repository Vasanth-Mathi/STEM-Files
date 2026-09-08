#include <SoftwareSerial.h>

/*
  Bluetooth Controlled 4-Wheel Car Using HC-05
  Board: Arduino Uno
*/

SoftwareSerial bluetooth(2, 3);

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

  bluetooth.begin(9600);
  stopRobot();
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();

    if (command == 'F' || command == 'f') {
      moveForward();
    } else if (command == 'B' || command == 'b') {
      moveBackward();
    } else if (command == 'L' || command == 'l') {
      turnLeft();
    } else if (command == 'R' || command == 'r') {
      turnRight();
    } else if (command == 'S' || command == 's') {
      stopRobot();
    }
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
