# Temperature Controlled Fan Using LM35 Sensor

## Description
A temperature-controlled fan that uses an LM35 sensor. When the measured temperature reaches the set limit, Arduino turns ON a DC fan through an L298N motor driver.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| LM35 Temperature Sensor | 1 |
| L298N Motor Driver Module | 1 |
| 6V DC Fan | 1 |
| 7.4V Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | LM35 VCC |
| GND | LM35 GND and Motor Driver GND |
| A0 | LM35 OUT |
| D8 | Motor Driver IN1 |
| D9 | Motor Driver IN2 |

### Fan Connections

| Component | Connect To |
|---|---|
| 6V DC Fan | Motor Driver OUT1 and OUT2 |

### Power Connections

| From | Connect To |
|---|---|
| Motor Battery + | Motor Driver Motor Power |
| Motor Battery - | Motor Driver GND |
| Arduino GND | Motor Driver GND |

> Keep the ENA jumper fitted on the L298N channel used for the fan.

## Code
See [`temperature_controlled_fan.ino`](./temperature_controlled_fan.ino).

## Working Principle
1. The LM35 produces a voltage proportional to temperature.
2. Arduino converts the analog reading into degrees Celsius.
3. When the temperature reaches the ON threshold, the fan starts.
4. The fan stays ON until the temperature drops below the lower OFF threshold.
5. Using two thresholds prevents rapid ON/OFF switching.

## Use Cases
- Automatic cooling systems
- Temperature-control lessons
- Electronics cooling models
- Home automation projects
