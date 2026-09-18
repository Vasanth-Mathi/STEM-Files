/*
  Soil Moisture Dryness Indicator Using LED
  Capacitive soil moisture sensor AO: A0
  LED: D8

  Calibrate DRY_THRESHOLD for the actual sensor and soil.
*/

const int SOIL_SENSOR_PIN = A0;
const int LED_PIN = 8;
const int DRY_THRESHOLD = 650;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  const int moistureValue = analogRead(SOIL_SENSOR_PIN);
  const bool soilIsDry = moistureValue >= DRY_THRESHOLD;

  digitalWrite(LED_PIN, soilIsDry ? HIGH : LOW);

  Serial.print("Soil reading: ");
  Serial.println(moistureValue);

  delay(500);
}
