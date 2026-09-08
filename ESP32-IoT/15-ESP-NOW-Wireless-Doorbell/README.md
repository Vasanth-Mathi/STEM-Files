# ESP32 Wireless Doorbell Using ESP-NOW

## Description
Creates a router-free wireless doorbell with one ESP32 push-button transmitter and one ESP32 buzzer receiver.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 2 |
| Push Button | 1 |
| Active Buzzer | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Transmitter GPIO 4 | Push button to GND |
| Receiver GPIO 23 | LED anode through 220 Ω resistor |
| Receiver GPIO 22 | Buzzer signal |
| Receiver GND | LED cathode and buzzer GND |

## Code
See [`espnow_wireless_doorbell.ino`](./espnow_wireless_doorbell.ino).

## Working Principle
1. Set `TRANSMITTER_MODE` to `true` for the button ESP32 and enter the receiver MAC address.
2. Set `TRANSMITTER_MODE` to `false` for the receiver ESP32.
3. Pressing the button sends a ring packet through ESP-NOW.
4. The receiver activates its LED and buzzer when a ring packet arrives.

## Use Cases
- Wireless doorbells
- Event-based communication
- ESP-NOW demonstrations
- Home-automation prototypes
