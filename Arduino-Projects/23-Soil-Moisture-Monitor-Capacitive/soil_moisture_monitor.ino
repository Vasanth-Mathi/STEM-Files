/*
  Soil Moisture Monitor Using Capacitive Soil Moisture Sensor
  Board: Arduino Uno
*/

const int SOIL_PIN = A0;

const int GREEN_LED = 8;
const int YELLOW_LED = 9;
const int RED_LED = 10;

const int WET_THRESHOLD = 400;
const int DRY_THRESHOLD = 650;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(SOIL_PIN);
  Serial.println(moistureValue);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  if (moistureValue <= WET_THRESHOLD) {
    digitalWrite(GREEN_LED, HIGH);
  } else if (moistureValue >= DRY_THRESHOLD) {
    digitalWrite(RED_LED, HIGH);
  } else {
    digitalWrite(YELLOW_LED, HIGH);
  }

  delay(500);
}
