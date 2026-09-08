#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int OUTPUT_PINS[4] = {23, 22, 21, 19};
bool outputStates[4] = {false, false, false, false};

void setAll(bool state) {
  for (int i = 0; i < 4; i++) {
    outputStates[i] = state;
    digitalWrite(OUTPUT_PINS[i], state ? HIGH : LOW);
  }
}

void toggleOutput(int index) {
  outputStates[index] = !outputStates[index];
  digitalWrite(OUTPUT_PINS[index], outputStates[index] ? HIGH : LOW);
}

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(OUTPUT_PINS[i], OUTPUT);
  }

  setAll(false);
  SerialBT.begin("ESP32-Home");
}

void loop() {
  if (!SerialBT.available()) {
    return;
  }

  char command = toupper(SerialBT.read());

  if (command >= '1' && command <= '4') {
    toggleOutput(command - '1');
  } else if (command == 'A') {
    setAll(true);
  } else if (command == 'S') {
    setAll(false);
  }
}
