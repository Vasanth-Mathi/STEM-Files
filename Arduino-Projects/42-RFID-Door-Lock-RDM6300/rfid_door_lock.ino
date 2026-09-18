#include <SoftwareSerial.h>
#include <Servo.h>
#include <string.h>

SoftwareSerial rfid(2, 3);
Servo lockServo;

char tag[11];

void setup() {
  rfid.begin(9600);
  Serial.begin(9600);

  lockServo.attach(6);
  lockServo.write(0);
}

void loop() {
  if (rfid.available() >= 14) {
    byte data[14];

    for (int i = 0; i < 14; i++) {
      data[i] = rfid.read();
    }

    if (data[0] == 0x02 && data[13] == 0x03) {
      for (int i = 0; i < 10; i++) {
        tag[i] = data[i + 1];
      }

      tag[10] = '\0';
      Serial.println(tag);

      if (strcmp(tag, "0000000000") == 0) {
        lockServo.write(90);
        delay(3000);
        lockServo.write(0);
      }
    }
  }
}
