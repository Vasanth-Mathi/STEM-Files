/*
  4-Wheel Obstacle Avoiding Robot Using HC-SR04
  Board: Arduino Uno

  Motor arrangement:
  - Left front + left rear motors operate together through L298N channel A.
  - Right front + right rear motors operate together through L298N channel B.
*/

const int trigPin = 2;
const int echoPin = 3;

// Left-side motor group
const int ENA = 5;
const int IN1 = 8;
const int IN2 = 9;

// Right-side motor group
const int ENB = 6;
const int IN3 = 10;
const int IN4 = 11;

const int motorSpeed = 170;
const int obstacleDistance = 20; // centimetres

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
  stopRobot();
}

void loop() {
  float distance = measureDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= obstacleDistance) {
    stopRobot();
    delay(250);

    moveBackward();
    delay(500);

    stopRobot();
    delay(150);

    turnRightInPlace();
    delay(650);

    stopRobot();
    delay(150);
  } else {
    moveForward();
  }

  delay(50);
}

float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  return duration * 0.0343 / 2.0;
}

void moveForward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRightInPlace() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

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
