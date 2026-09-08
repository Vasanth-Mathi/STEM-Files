#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int LEFT_IN1 = 25;
const int LEFT_IN2 = 26;
const int RIGHT_IN1 = 27;
const int RIGHT_IN2 = 14;

void stopRobot() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
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
  digitalWrite(LEFT_IN2, HIGH);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void turnRight() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void setup() {
  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  stopRobot();
  SerialBT.begin("ESP32-Robot");
}

void loop() {
  if (!SerialBT.available()) {
    return;
  }

  char command = toupper(SerialBT.read());

  if (command == 'F') {
    moveForward();
  } else if (command == 'B') {
    moveBackward();
  } else if (command == 'L') {
    turnLeft();
  } else if (command == 'R') {
    turnRight();
  } else if (command == 'S') {
    stopRobot();
  }
}
