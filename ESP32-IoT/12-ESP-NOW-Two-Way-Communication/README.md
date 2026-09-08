# ESP32 Two-Way Communication Using ESP-NOW

## Description
Lets two ESP32 boards exchange push-button states in both directions and control an LED on the opposite device.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 2 |
| Push Button | 2 |
| LED | 2 |
| 220 Ω Resistor | 2 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Each ESP32 GPIO 4 | Push button to GND |
| Each ESP32 GPIO 23 | LED anode through 220 Ω resistor |
| Each ESP32 GND | LED cathode and button GND |

> Set a different `DEVICE_ID` on each board and replace `peerMac` with the other ESP32 MAC address.

## Code
See [`espnow_two_way_communication.ino`](./espnow_two_way_communication.ino).

## Working Principle
1. Upload the same sketch to both ESP32 boards after changing `DEVICE_ID` and `peerMac`.
2. Each ESP32 sends its local button state to the other board.
3. The received button state controls the local LED.
4. Because both boards send and receive, communication is bidirectional.

## Use Cases
- Bidirectional wireless control
- ESP-NOW peer communication
- Interactive classroom demos
- Remote input/output experiments
