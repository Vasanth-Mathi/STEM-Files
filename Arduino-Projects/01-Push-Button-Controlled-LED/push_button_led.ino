/*
  Push Button Controlled LED
  Button: D2 to GND using INPUT_PULLUP
  LED: D8 through a 220 ohm resistor to GND
*/

const int BUTTON_PIN = 2;
const int LED_PIN = 8;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  const bool buttonPressed = digitalRead(BUTTON_PIN) == LOW;
  digitalWrite(LED_PIN, buttonPressed ? HIGH : LOW);
}
