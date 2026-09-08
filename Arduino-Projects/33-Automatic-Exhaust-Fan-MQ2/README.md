# Automatic Exhaust Fan Using MQ-2 Sensor

## Description
An automatic exhaust-fan prototype that uses an MQ-2 sensor to detect increased smoke or gas levels. When the sensor reading exceeds the chosen threshold, Arduino turns ON a DC fan through an L298N motor driver.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| MQ-2 Smoke / Gas Sensor Module | 1 |
| L298N Motor Driver Module | 1 |
| 6V DC Fan | 1 |
| 7.4V Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | MQ-2 VCC |
| GND | MQ-2 GND and Motor Driver GND |
| A0 | MQ-2 AO |
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

> This is an educational prototype, not a certified gas or smoke safety system.

## Code
See [`automatic_exhaust_fan.ino`](./automatic_exhaust_fan.ino).

## Working Principle
1. The MQ-2 sensor produces an analog signal that changes with smoke and combustible gases.
2. Arduino reads the signal through A0.
3. When the reading rises above the set threshold, Arduino starts the fan through the motor driver.
4. When the reading falls below the threshold, the fan stops.
5. The threshold must be adjusted after the MQ-2 has warmed up.

## Use Cases
- Kitchen ventilation models
- Automatic exhaust systems
- Gas/smoke sensor lessons
- Home automation prototypes
