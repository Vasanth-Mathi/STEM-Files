/*
  4-Wheel Obstacle Avoiding Robot Using HC-SR04
  Board: Arduino Uno
  Motors: 4 DC geared motors
  Motor Drivers: 2 x L298N

  Driver 1 controls the front motors.
  Driver 2 controls the rear motors.
  Both drivers share the same left/right control signals so that
  front and rear motors on each side move together.
*/

const int trigPin = 2;
const int echoPin = 3;

// Shared LEFT-side motor control for both L298N modules
const int LEFT_EN = 5;   // PWM
const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;

// Shared RIGHT-side motor control for both L298N modules
const int RIGHT_EN = 6;  // PWM
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

const int motorSpeed = 170;
const int obstacleDistance = 20; // centimetres

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LEFT_EN, OUTPUT);
  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);

  pinMode(RIGHT_EN, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  Serial.begin(9600);
  stopRobot();
}

void loop() {
  const float distance = measureDistance();

  if (distance < 0) {
    // Fail safe: invalid/timeout reading means stop, not "path clear".
    stopRobot();
    Serial.println("Ultrasonic reading invalid - robot stopped");
    delay(100);
    return;
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= obstacleDistance) {
    stopRobot();
    delay(200);

    moveBackward();
    delay(450);

    stopRobot();
    delay(150);

    turnRightInPlace();
    delay(650);

    stopRobot();
    delay(150);
  } else {
    moveForward();
  }

  // HC-SR04 documentation recommends spacing measurements by >60 ms.
  delay(70);
}

float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  const unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);

  if (duration == 0) {
    return -1.0;
  }

  return duration * 0.0343 / 2.0;
}

void setLeftForward(int speedValue) {
  analogWrite(LEFT_EN, constrain(speedValue, 0, 255));
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
}

void setLeftBackward(int speedValue) {
  analogWrite(LEFT_EN, constrain(speedValue, 0, 255));
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);
}

void setRightForward(int speedValue) {
  analogWrite(RIGHT_EN, constrain(speedValue, 0, 255));
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void setRightBackward(int speedValue) {
  analogWrite(RIGHT_EN, constrain(speedValue, 0, 255));
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void moveForward() {
  setLeftForward(motorSpeed);
  setRightForward(motorSpeed);
}

void moveBackward() {
  setLeftBackward(motorSpeed);
  setRightBackward(motorSpeed);
}

void turnRightInPlace() {
  setLeftForward(motorSpeed);
  setRightBackward(motorSpeed);
}

void stopRobot() {
  analogWrite(LEFT_EN, 0);
  analogWrite(RIGHT_EN, 0);

  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}
