#include <SoftwareSerial.h>
#include <Servo.h>
#include <string.h>

/*
  RFID Door Lock Using RDM6300 RFID Reader
  Board: Arduino Uno
*/

SoftwareSerial rfidSerial(2, 3);
Servo lockServo;

const int SERVO_PIN = 6;
const int LOCKED_ANGLE = 0;
const int UNLOCKED_ANGLE = 90;

const char AUTHORIZED_TAG[] = "0000000000";
char tagData[11];

bool readTag();

void setup() {
  rfidSerial.begin(9600);
  Serial.begin(9600);

  lockServo.attach(SERVO_PIN);
  lockServo.write(LOCKED_ANGLE);
}

void loop() {
  if (readTag()) {
    Serial.println(tagData);

    if (strcmp(tagData, AUTHORIZED_TAG) == 0) {
      lockServo.write(UNLOCKED_ANGLE);
      delay(3000);
      lockServo.write(LOCKED_ANGLE);
    }
  }
}

bool readTag() {
  if (rfidSerial.available() < 14) {
    return false;
  }

  byte frame[14];

  for (int i = 0; i < 14; i++) {
    frame[i] = rfidSerial.read();
  }

  if (frame[0] != 0x02 || frame[13] != 0x03) {
    return false;
  }

  for (int i = 0; i < 10; i++) {
    tagData[i] = (char)frame[i + 1];
  }

  tagData[10] = '\0';
  return true;
}
