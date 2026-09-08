# ESP32 Blynk IoT Smart Parking Monitoring System

## Description
Uses two IR obstacle sensors to monitor two model parking spaces and sends slot occupancy and free-space count to Blynk.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| IR Obstacle Sensor Module | 2 |
| LED | 2 |
| 220 Ω Resistor | 2 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | Both IR sensor VCC pins |
| GND | Both sensor GND pins and LED cathodes |
| GPIO 32 | Parking Slot 1 sensor OUT |
| GPIO 33 | Parking Slot 2 sensor OUT |
| GPIO 23 | Slot 1 indicator LED through 220 Ω resistor |
| GPIO 22 | Slot 2 indicator LED through 220 Ω resistor |

> IR obstacle modules can use different output polarity. Change `OCCUPIED_STATE` if your module reports occupancy as HIGH.

## Code
See [`blynk_smart_parking_monitor.ino`](./blynk_smart_parking_monitor.ino).

## Working Principle
1. Each IR sensor detects whether a model vehicle is occupying its slot.
2. V0 and V1 show the occupancy of the two parking spaces.
3. V2 shows the number of free spaces.
4. The local LEDs mirror the occupied state.

## Use Cases
- Smart-city prototypes
- Parking automation
- Occupancy detection
- Blynk dashboards
