/*
  Temperature Controlled Fan Using LM35 Sensor
  Board: Arduino Uno
*/

const int LM35_PIN = A0;
const int FAN_IN1 = 8;
const int FAN_IN2 = 9;

const float FAN_ON_TEMP = 30.0;
const float FAN_OFF_TEMP = 28.0;

bool fanOn = false;

void startFan();
void stopFan();

void setup() {
  pinMode(FAN_IN1, OUTPUT);
  pinMode(FAN_IN2, OUTPUT);

  stopFan();
}

void loop() {
  int rawValue = analogRead(LM35_PIN);
  float temperatureC = rawValue * (5.0 / 1023.0) * 100.0;

  if (!fanOn && temperatureC >= FAN_ON_TEMP) {
    fanOn = true;
  } else if (fanOn && temperatureC <= FAN_OFF_TEMP) {
    fanOn = false;
  }

  if (fanOn) {
    startFan();
  } else {
    stopFan();
  }

  delay(500);
}

void startFan() {
  digitalWrite(FAN_IN1, HIGH);
  digitalWrite(FAN_IN2, LOW);
}

void stopFan() {
  digitalWrite(FAN_IN1, LOW);
  digitalWrite(FAN_IN2, LOW);
}
