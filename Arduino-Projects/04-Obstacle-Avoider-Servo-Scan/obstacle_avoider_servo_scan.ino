#include <Servo.h>

/*
  4-Wheel Obstacle Avoiding Robot with Servo-Mounted HC-SR04
  Board: Arduino Uno

  Hardware:
  - 4 DC motors
  - 2 x L298N dual H-bridge motor drivers
  - 1 motor per L298N channel
  - HC-SR04 mounted on a servo

  Pin plan:
  HC-SR04 TRIG -> D2
  HC-SR04 ECHO -> D3
  Servo signal  -> D4
  Motor PWM     -> D5, D6
  Motor direction -> D8, D9, D10, D11
*/

Servo scannerServo;

const int trigPin = 2;
const int echoPin = 3;
const int servoPin = 4;

// Shared left-side motor control for both L298N modules
const int ENA = 5;
const int IN1 = 8;
const int IN2 = 9;

// Shared right-side motor control for both L298N modules
const int ENB = 6;
const int IN3 = 10;
const int IN4 = 11;

const int MOTOR_SPEED = 170;
const int OBSTACLE_DISTANCE_CM = 20;

const int CENTER_ANGLE = 90;
const int LEFT_ANGLE = 150;
const int RIGHT_ANGLE = 30;

const unsigned long SERVO_SETTLE_MS = 450;
const unsigned long REVERSE_TIME_MS = 450;
const unsigned long TURN_TIME_MS = 650;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);

  scannerServo.attach(servoPin);
  scannerServo.write(CENTER_ANGLE);
  delay(SERVO_SETTLE_MS);

  stopRobot();
}

void loop() {
  long frontDistance = measureDistanceCm();

  Serial.print("Front: ");
  printDistance(frontDistance);

  // Invalid reading: stop rather than assume the path is safe.
  if (frontDistance < 0) {
    stopRobot();
    delay(100);
    return;
  }

  if (frontDistance > OBSTACLE_DISTANCE_CM) {
    moveForward();
    delay(60);
    return;
  }

  // Obstacle detected.
  stopRobot();
  delay(200);

  moveBackward();
  delay(REVERSE_TIME_MS);
  stopRobot();
  delay(150);

  long leftDistance = scanDirection(LEFT_ANGLE);
  long rightDistance = scanDirection(RIGHT_ANGLE);

  scannerServo.write(CENTER_ANGLE);
  delay(SERVO_SETTLE_MS);

  Serial.print("Left: ");
  printDistance(leftDistance);
  Serial.print("Right: ");
  printDistance(rightDistance);

  // Choose only from valid measurements.
  if (leftDistance < 0 && rightDistance < 0) {
    stopRobot();
    delay(250);
    return;
  }

  if (leftDistance >= 0 && rightDistance < 0) {
    turnLeftInPlace();
    delay(TURN_TIME_MS);
  } else if (rightDistance >= 0 && leftDistance < 0) {
    turnRightInPlace();
    delay(TURN_TIME_MS);
  } else if (leftDistance > rightDistance) {
    turnLeftInPlace();
    delay(TURN_TIME_MS);
  } else {
    turnRightInPlace();
    delay(TURN_TIME_MS);
  }

  stopRobot();
  delay(150);
}

long scanDirection(int angle) {
  scannerServo.write(angle);
  delay(SERVO_SETTLE_MS);

  // Take two readings and keep the larger valid value.
  // This reduces the chance that one brief bad echo decides the turn.
  long first = measureDistanceCm();
  delay(70);
  long second = measureDistanceCm();

  if (first < 0) return second;
  if (second < 0) return first;
  return max(first, second);
}

long measureDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 30 ms timeout is roughly beyond the useful classroom range of HC-SR04.
  unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);

  if (duration == 0) {
    return -1; // No valid echo received.
  }

  // Distance = round-trip time x speed of sound / 2.
  long distance = (long)(duration * 0.0343 / 2.0);

  // Ignore values outside a practical HC-SR04 working range.
  if (distance < 2 || distance > 400) {
    return -1;
  }

  return distance;
}

void moveForward() {
  setMotorSpeed(MOTOR_SPEED, MOTOR_SPEED);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  setMotorSpeed(MOTOR_SPEED, MOTOR_SPEED);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeftInPlace() {
  setMotorSpeed(MOTOR_SPEED, MOTOR_SPEED);

  // Left wheels backward, right wheels forward.
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRightInPlace() {
  setMotorSpeed(MOTOR_SPEED, MOTOR_SPEED);

  // Left wheels forward, right wheels backward.
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setMotorSpeed(int leftSpeed, int rightSpeed) {
  analogWrite(ENA, constrain(leftSpeed, 0, 255));
  analogWrite(ENB, constrain(rightSpeed, 0, 255));
}

void printDistance(long distance) {
  if (distance < 0) {
    Serial.println("Invalid");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
}
