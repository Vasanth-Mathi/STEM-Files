/*
  Soil Moisture Based Irrigation Using Capacitive Soil Moisture Sensor
  Board: Arduino Uno
*/

const int SOIL_PIN = A0;
const int PUMP_IN1 = 8;
const int PUMP_IN2 = 9;

const int PUMP_ON_THRESHOLD = 650;
const int PUMP_OFF_THRESHOLD = 500;

bool pumpOn = false;

void startPump();
void stopPump();

void setup() {
  pinMode(PUMP_IN1, OUTPUT);
  pinMode(PUMP_IN2, OUTPUT);

  stopPump();
  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(SOIL_PIN);
  Serial.println(moistureValue);

  if (!pumpOn && moistureValue >= PUMP_ON_THRESHOLD) {
    pumpOn = true;
  } else if (pumpOn && moistureValue <= PUMP_OFF_THRESHOLD) {
    pumpOn = false;
  }

  if (pumpOn) {
    startPump();
  } else {
    stopPump();
  }

  delay(500);
}

void startPump() {
  digitalWrite(PUMP_IN1, HIGH);
  digitalWrite(PUMP_IN2, LOW);
}

void stopPump() {
  digitalWrite(PUMP_IN1, LOW);
  digitalWrite(PUMP_IN2, LOW);
}
