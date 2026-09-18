#include <Servo.h>

Servo lidServo;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

  lidServo.attach(4);
  lidServo.write(0);
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH, 30000);
  int distance = duration * 0.0343 / 2;

  if (duration > 0 && distance <= 20) {
    lidServo.write(90);
    delay(2000);
    lidServo.write(0);
    delay(700);
  } else {
    delay(100);
  }
}
