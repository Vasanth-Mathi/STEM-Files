/*
  Clap Controlled Light Using Sound Sensor
  Board: Arduino Uno
*/

const int SOUND_PIN = 2;
const int LIGHT_PIN = 9;

bool lightOn = false;
int lastSoundState = LOW;

unsigned long lastClapTime = 0;
const unsigned long DEBOUNCE_MS = 300;

void setup() {
  pinMode(SOUND_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  int soundState = digitalRead(SOUND_PIN);

  if (soundState == HIGH &&
      lastSoundState == LOW &&
      millis() - lastClapTime > DEBOUNCE_MS) {
    lightOn = !lightOn;
    digitalWrite(LIGHT_PIN, lightOn ? HIGH : LOW);
    lastClapTime = millis();
  }

  lastSoundState = soundState;
}
