/*
  Electronic Reaction Time Game Using LED and Push Button
  Board: Arduino Uno
*/

const int BUTTON_PIN = 2;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;

void waitForRelease() {
  while (digitalRead(BUTTON_PIN) == LOW) {
    delay(10);
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  waitForRelease();

  unsigned long waitTime = random(2000, 5001);
  unsigned long startWait = millis();

  while (millis() - startWait < waitTime) {
    if (digitalRead(BUTTON_PIN) == LOW) {
      Serial.println("Too early! Try again.");
      waitForRelease();
      delay(1000);
      return;
    }
  }

  digitalWrite(LED_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(50);
  digitalWrite(BUZZER_PIN, LOW);

  unsigned long startTime = millis();

  while (digitalRead(BUTTON_PIN) == HIGH) {
  }

  unsigned long reactionTime = millis() - startTime;

  digitalWrite(LED_PIN, LOW);

  Serial.print("Reaction time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  waitForRelease();
  delay(1500);
}
