/*
  Automatic Streetlight Using LDR
  Board: Arduino Uno
*/

const int ldrPin = A0;
const int lightPin = 9;
const int darknessThreshold = 400; // Adjust after testing

void setup() {
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin);

  Serial.print("Light Sensor Value: ");
  Serial.println(lightValue);

  // With this voltage-divider arrangement:
  // Lower value = darker environment
  // Higher value = brighter environment
  if (lightValue < darknessThreshold) {
    digitalWrite(lightPin, HIGH);
  } else {
    digitalWrite(lightPin, LOW);
  }

  delay(200);
}
