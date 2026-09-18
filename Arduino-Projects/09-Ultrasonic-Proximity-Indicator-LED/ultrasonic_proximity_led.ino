/*
  Ultrasonic Proximity Indicator Using LED
  HC-SR04 TRIG: D2
  HC-SR04 ECHO: D3
  LED: D8
*/

const int TRIG_PIN = 2;
const int ECHO_PIN = 3;
const int LED_PIN = 8;
const float ALERT_DISTANCE_CM = 20.0;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (duration == 0) {
    return -1.0;
  }

  return duration * 0.0343 / 2.0;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  const float distanceCm = readDistanceCm();
  const bool objectNear =
    distanceCm > 0.0 && distanceCm <= ALERT_DISTANCE_CM;

  digitalWrite(LED_PIN, objectNear ? HIGH : LOW);
  delay(100);
}
