/*
  Automatic Exhaust Fan Using MQ-2 Sensor
  Board: Arduino Uno
*/

const int MQ2_PIN = A0;
const int FAN_IN1 = 8;
const int FAN_IN2 = 9;
const int FAN_THRESHOLD = 450;

void startFan();
void stopFan();

void setup() {
  pinMode(FAN_IN1, OUTPUT);
  pinMode(FAN_IN2, OUTPUT);

  stopFan();
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(MQ2_PIN);
  Serial.println(sensorValue);

  if (sensorValue >= FAN_THRESHOLD) {
    startFan();
  } else {
    stopFan();
  }

  delay(200);
}

void startFan() {
  digitalWrite(FAN_IN1, HIGH);
  digitalWrite(FAN_IN2, LOW);
}

void stopFan() {
  digitalWrite(FAN_IN1, LOW);
  digitalWrite(FAN_IN2, LOW);
}
