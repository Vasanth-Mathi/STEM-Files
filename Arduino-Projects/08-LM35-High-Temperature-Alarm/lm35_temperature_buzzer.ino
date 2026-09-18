/*
  High Temperature Alarm Using LM35 and Buzzer
  LM35 OUT: A0
  Active buzzer signal: D8

  Assumes approximately 5V ADC reference on Arduino Uno.
*/

const int LM35_PIN = A0;
const int BUZZER_PIN = 8;
const float HIGH_TEMPERATURE_C = 30.0;

float readTemperatureC() {
  const int rawValue = analogRead(LM35_PIN);
  const float voltage = rawValue * (5.0 / 1023.0);
  return voltage * 100.0;
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  const float temperatureC = readTemperatureC();
  const bool temperatureHigh = temperatureC >= HIGH_TEMPERATURE_C;

  digitalWrite(BUZZER_PIN, temperatureHigh ? HIGH : LOW);

  Serial.print("Temperature: ");
  Serial.print(temperatureC, 1);
  Serial.println(" C");

  delay(500);
}
