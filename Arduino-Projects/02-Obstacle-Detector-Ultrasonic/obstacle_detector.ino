/*
  Obstacle Detector Using HC-SR04
  Board: Arduino Uno
*/

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 7;
const int ledPin = 6;

const int obstacleDistance = 20; // centimetres

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  float distance = duration * 0.0343 / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (duration > 0 && distance <= obstacleDistance) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(100);
}
