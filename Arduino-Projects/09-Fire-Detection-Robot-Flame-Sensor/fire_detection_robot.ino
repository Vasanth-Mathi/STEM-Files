/*
  Fire Detection Robot Using Flame Sensor
  Board: Arduino Uno
*/

const int FLAME_PIN = 2;
const int BUZZER_PIN = 4;

const int LEFT_IN1 = 8;
const int LEFT_IN2 = 9;
const int RIGHT_IN1 = 10;
const int RIGHT_IN2 = 11;

const int FLAME_DETECTED_STATE = LOW;

void stopRobot();
void moveForward();

void setup() {
  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  stopRobot();
}

void loop() {
  bool flameDetected = digitalRead(FLAME_PIN) == FLAME_DETECTED_STATE;

  if (flameDetected) {
    stopRobot();
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    moveForward();
  }

  delay(50);
}

void moveForward() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void stopRobot() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}
