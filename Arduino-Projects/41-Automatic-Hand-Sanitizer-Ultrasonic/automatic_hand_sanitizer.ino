#include <Servo.h>

Servo dispenserServo;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

  dispenserServo.attach(4);
  dispenserServo.write(0);
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH, 30000);
  int distance = duration * 0.0343 / 2;

  if (duration > 0 && distance <= 15) {
    dispenserServo.write(70);
    delay(500);
    dispenserServo.write(0);
    delay(1500);
  } else {
    delay(100);
  }
}
