/*
  Automatic Streetlight Prototype Using LDR / Photoresistor
  Board: Arduino Uno

  This sketch controls a single low-power demonstration LED.
  Do not connect a real streetlight or high-power lamp directly
  to an Arduino output pin.
*/

const int ldrPin = A0;
const int lightPin = 9;

// Starting values only. Calibrate using Serial Monitor readings.
const int LIGHT_ON_THRESHOLD = 350;
const int LIGHT_OFF_THRESHOLD = 450;

bool lightIsOn = false;

void setup() {
  pinMode(lightPin, OUTPUT);
  digitalWrite(lightPin, LOW);

  Serial.begin(9600);
}

void loop() {
  const int lightValue = analogRead(ldrPin);

  Serial.print("LDR reading: ");
  Serial.print(lightValue);
  Serial.print(" | Streetlight: ");
  Serial.println(lightIsOn ? "ON" : "OFF");

  // Wiring used in this project:
  // 5V ---> LDR ---> A0 ---> 10k resistor ---> GND
  // Brighter light generally gives a higher ADC reading.

  if (!lightIsOn && lightValue <= LIGHT_ON_THRESHOLD) {
    lightIsOn = true;
    digitalWrite(lightPin, HIGH);
  }
  else if (lightIsOn && lightValue >= LIGHT_OFF_THRESHOLD) {
    lightIsOn = false;
    digitalWrite(lightPin, LOW);
  }

  delay(200);
}
