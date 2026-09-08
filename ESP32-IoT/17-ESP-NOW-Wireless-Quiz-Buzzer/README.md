# ESP32 Wireless Classroom Quiz Buzzer Using ESP-NOW

## Description
Lets multiple wireless ESP32 player buttons compete to register the first answer on one host ESP32.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 3 or more |
| Push Button | For each player |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer | 1 |
| Reset Push Button | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Each player GPIO 4 | Player push button to GND |
| Host GPIO 23 | Winner LED through 220 Ω resistor |
| Host GPIO 22 | Buzzer signal |
| Host GPIO 19 | Reset button to GND |

## Code
See [`espnow_wireless_quiz_buzzer.ino`](./espnow_wireless_quiz_buzzer.ino).

## Working Principle
1. Set `HOST_MODE` to `false` on player units and assign each a different `PLAYER_ID`.
2. Enter the host MAC address in every player unit.
3. The first player button packet received by the host becomes the winner.
4. The host ignores later presses until its reset button is pressed.

## Use Cases
- Classroom quiz systems
- Wireless competitions
- First-response logic
- ESP-NOW event networks
