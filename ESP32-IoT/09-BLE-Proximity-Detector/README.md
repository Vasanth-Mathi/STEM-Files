# ESP32 BLE Proximity Detection System

## Description
Uses one ESP32 as a BLE tag and another as a scanner that estimates proximity from received signal strength.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 2 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Scanner GPIO 23 | LED anode through 220 Ω resistor |
| Scanner GPIO 22 | Buzzer signal |
| Scanner GND | LED cathode and buzzer GND |

> RSSI is only an approximate indicator of distance and changes with walls, orientation, interference, and the environment. Calibrate `NEAR_RSSI` for the classroom setup.

## Code
See [`ble_proximity_detector.ino`](./ble_proximity_detector.ino).

## Working Principle
1. Set `TAG_MODE` to `true` and upload the sketch to the tag ESP32.
2. Set `TAG_MODE` to `false` and upload it to the scanner ESP32.
3. The scanner searches for the BLE name `ESP32-PROX-TAG`.
4. If the measured RSSI is stronger than the selected threshold, the LED and buzzer turn on.

## Use Cases
- BLE experiments
- RSSI demonstrations
- Proximity alarms
- Wireless-signal lessons
