# RFID Door Lock Using RDM6300 RFID Reader

## Description
An RFID door-lock model using a 5 V RDM6300 RFID reader and a small servo. When Arduino receives an authorized RFID tag code, the servo temporarily moves to the unlock position.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| RDM6300 125 kHz RFID Reader | 1 |
| Compatible 125 kHz RFID Tag / Card | 1 or more |
| Small Hobby Servo Motor | 1 |
| Model Door / Lock Mechanism | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | RDM6300 VCC and Servo VCC |
| GND | RDM6300 GND and Servo GND |
| D2 | RDM6300 TX |
| D6 | Servo Signal |

> This beginner circuit powers one small hobby servo from Arduino 5V. Use a good USB power source. If the Arduino resets or the servo jitters under load, the servo needs a separate suitable 5V supply with common GND.

> Replace the example value in `AUTHORIZED_TAG` with the 10-character hexadecimal ID sent by your own RFID tag.

## Code
See [`rfid_door_lock.ino`](./rfid_door_lock.ino).

## Working Principle
1. The RDM6300 reads a compatible RFID tag and sends a 14-byte serial message to Arduino.
2. Arduino collects the tag message from the reader TX pin.
3. The tag data is compared with the authorized tag stored in the sketch.
4. If the tag matches, the servo moves to the unlocked position for a few seconds.
5. The servo then returns to the locked position.
6. Unknown tags do not unlock the model door.

## Use Cases
- RFID access-control models
- Smart door projects
- Identification-system lessons
- Home automation demonstrations
