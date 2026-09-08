# Automatic Streetlight Prototype Using LDR / Photoresistor

## Description
This project demonstrates how an automatic streetlight control system works using an Arduino Uno, an LDR (photoresistor), and a single LED as the model streetlight.

The LDR senses the surrounding light level. When the environment becomes dark, Arduino switches the LED ON. When the environment becomes bright again, Arduino switches it OFF.

> This circuit is a **low-power educational prototype**. A real streetlight, mains lamp, or high-power LED must **not** be powered directly from an Arduino pin. Real lighting loads require a properly rated transistor/MOSFET, relay or driver stage, suitable power supply, and appropriate electrical-safety practices.

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

MODEL STREETLIGHT LED
Arduino D9 ---> 220 Ω Resistor ---> LED Anode (+)
LED Cathode (-) ---> Arduino GND
```

## Code
See [`automatic_streetlight.ino`](./automatic_streetlight.ino).

## Working Principle
1. The LDR changes resistance according to the amount of light falling on it.
2. The LDR and 10 kΩ resistor form a voltage divider.
3. Arduino reads the divider voltage through analog pin A0.
4. With the LDR connected toward 5V and the 10 kΩ resistor toward GND, brighter light normally produces a higher analog reading and darkness produces a lower reading.
5. The program uses two thresholds rather than one. This is called **hysteresis**.
6. When the reading falls below the ON threshold, the model streetlight turns ON.
7. Once ON, it stays ON until the reading rises above the higher OFF threshold.
8. The gap between the two thresholds prevents rapid ON/OFF flickering when the ambient light is close to the switching level.
9. The threshold values must be calibrated using the actual LDR and the classroom/environment lighting conditions.

## Calibration

Open the Arduino Serial Monitor and observe the sensor values in bright and dark conditions. Choose:

- `LIGHT_ON_THRESHOLD` below the normal room-light reading so the LED turns ON when it becomes sufficiently dark.
- `LIGHT_OFF_THRESHOLD` somewhat higher than the ON threshold so there is a stable switching gap.

The example code starts with values of 350 and 450, but these are starting points only and are not universal LDR values.

## Use Cases
- Automatic streetlight demonstrations
- Garden-lighting prototypes
- Automatic night lamps
- Energy-saving lighting concepts
- Smart-city classroom models
- Sensor-threshold and analog-input lessons
- Introduction to automatic control systems
