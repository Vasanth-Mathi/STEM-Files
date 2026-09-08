# Automatic Streetlight Using LDR / Photoresistor

## Description
This project automatically switches a streetlight ON when the surroundings become dark and switches it OFF when sufficient light is available. An LDR, also called a photoresistor, is used to sense the ambient light level.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| LDR / Photoresistor | 1 |
| LED | 1 |
| 10 kΩ Resistor | 1 |
| 220 Ω Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

## Circuit Connections

```text
LDR VOLTAGE DIVIDER
Arduino 5V ---> LDR
LDR ---> Arduino A0
Arduino A0 ---> 10 kΩ Resistor ---> Arduino GND

LED
Arduino D9 ---> 220 Ω Resistor ---> LED Anode (+)
LED Cathode (-) ---> Arduino GND
```

## Code
See [`automatic_streetlight.ino`](./automatic_streetlight.ino).

## Working Principle
1. The LDR changes resistance according to the amount of light falling on it.
2. The LDR and 10 kΩ resistor form a voltage divider.
3. Arduino reads the divider voltage through analog pin A0.
4. In this wiring arrangement, a brighter environment produces a higher analog reading and darkness produces a lower reading.
5. Arduino compares the reading with a preset darkness threshold.
6. When the reading falls below the threshold, the LED streetlight turns ON.
7. When the reading rises above the threshold, the LED turns OFF.
8. The threshold should be calibrated for the actual LDR and lighting conditions.

## Use Cases
- Automatic streetlights
- Garden lighting
- Corridor lights
- Outdoor security lights
- Energy-saving lighting
- Smart-city systems
- Automatic night lamps
