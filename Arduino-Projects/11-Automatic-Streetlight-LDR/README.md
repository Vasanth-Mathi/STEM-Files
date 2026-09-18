# Automatic Streetlight Using LDR Sensor

## Description
A simple automatic light that turns ON when it becomes dark and turns OFF when the surroundings become bright. An LDR sensor measures the light level and the Arduino controls an LED used as a model streetlight.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| LDR / Photoresistor | 1 |
| LED | 1 |
| 10 kΩ Resistor | 1 |
| 220 Ω Resistor | 1 |
| Breadboard | 1 |
| USB Power Bank or 7-12V Arduino Power Supply | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | One side of LDR |
| A0 | Other side of LDR and one side of 10 kΩ resistor |
| GND | Other side of 10 kΩ resistor and LED cathode (-) |
| D9 | 220 Ω resistor ---> LED anode (+) |

### Power Connection

| Power Source | Connect To |
|---|---|
| USB Power Bank or 7-12V Arduino Supply | Arduino USB port or DC jack |

## Code
See [`automatic_streetlight.ino`](./automatic_streetlight.ino).

## Working Principle
1. The LDR senses the surrounding light level.
2. Arduino reads the LDR value through pin A0.
3. When the surroundings become dark, the LED turns ON.
4. When the surroundings become bright again, the LED turns OFF.
5. Two threshold values are used so the LED does not rapidly flicker near the switching point.

> This project uses a small LED as a model streetlight. Do not connect a real streetlight or high-power lamp directly to an Arduino pin.

## Use Cases
- Automatic streetlight models
- Garden light projects
- Automatic night lamps
- Light-sensing experiments
- Smart-city classroom models
