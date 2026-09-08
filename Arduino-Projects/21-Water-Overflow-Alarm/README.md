# Water Overflow Alarm Using Water Level Sensor

## Description
A water-overflow alarm that uses an analog water level sensor near the top of a container. When the water reaches the chosen level, an LED and buzzer alert the user.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Water Level Sensor Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Water Level Sensor VCC and Buzzer Module VCC |
| GND | Water Level Sensor GND, Buzzer Module GND and LED cathode (-) |
| A0 | Water Level Sensor SIG |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

## Code
See [`water_overflow_alarm.ino`](./water_overflow_alarm.ino).

## Working Principle
1. The water level sensor is placed at the maximum safe water level.
2. Arduino reads the sensor value through A0.
3. When the reading rises above the overflow threshold, the LED and buzzer turn ON.
4. When the water falls below the threshold, the alarm turns OFF.
5. The threshold must be calibrated for the actual sensor placement.

## Use Cases
- Tank overflow alarms
- Water conservation projects
- Level sensor lessons
- Home automation prototypes
