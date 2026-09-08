/*
  Arduino Traffic Light Simulator Using LEDs
  Board: Arduino Uno
*/

const int RED_LED = 8;
const int YELLOW_LED = 9;
const int GREEN_LED = 10;

void setLights(bool redState, bool yellowState, bool greenState) {
  digitalWrite(RED_LED, redState);
  digitalWrite(YELLOW_LED, yellowState);
  digitalWrite(GREEN_LED, greenState);
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  setLights(LOW, LOW, HIGH);
  delay(5000);

  setLights(LOW, HIGH, LOW);
  delay(2000);

  setLights(HIGH, LOW, LOW);
  delay(5000);
}
