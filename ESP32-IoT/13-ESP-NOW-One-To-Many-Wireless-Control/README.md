# ESP32 One-to-Many Wireless Control Using ESP-NOW

## Description
Uses one controller ESP32 to broadcast an ON/OFF command to multiple receiver ESP32 boards at the same time.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 4 |
| Push Button | 1 |
| LED | 3 |
| 220 Ω Resistor | 3 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Controller GPIO 4 | Push button to GND |
| Each receiver GPIO 23 | LED anode through 220 Ω resistor |
| Each receiver GND | LED cathode |

## Code
See [`espnow_one_to_many_control.ino`](./espnow_one_to_many_control.ino).

## Working Principle
1. Set `CONTROLLER_MODE` to `true` on one ESP32 and `false` on the receivers.
2. The controller reads its push button.
3. It broadcasts the button state using the ESP-NOW broadcast MAC address.
4. All receiver boards on the same channel receive the command and change their LEDs together.

## Use Cases
- One-to-many communication
- Wireless classroom demonstrations
- Distributed LED control
- ESP-NOW broadcast experiments
