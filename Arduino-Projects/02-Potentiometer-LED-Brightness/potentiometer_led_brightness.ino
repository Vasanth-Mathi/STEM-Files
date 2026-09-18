/*
  Potentiometer Controlled LED Brightness
  Potentiometer wiper: A0
  LED: D9 through a 220 ohm resistor to GND
*/

const int POTENTIOMETER_PIN = A0;
const int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  const int sensorValue = analogRead(POTENTIOMETER_PIN);
  const int brightness = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(LED_PIN, brightness);
  delay(10);
}
