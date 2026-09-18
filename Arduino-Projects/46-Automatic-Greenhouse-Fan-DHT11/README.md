# Automatic Greenhouse Fan Using DHT11 Sensor

## Description
An automatic greenhouse ventilation project using a DHT11 sensor. Arduino starts a DC fan when temperature or humidity becomes high and stops it after conditions return to a lower range.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| DHT11 Sensor Module | 1 |
| L298N Motor Driver Module | 1 |
| 6V DC Fan | 1 |
| 7.4V Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | DHT11 VCC |
| GND | DHT11 GND and Motor Driver GND |
| D2 | DHT11 DATA |
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
See [`automatic_greenhouse_fan.ino`](./automatic_greenhouse_fan.ino).

This sketch requires a **DHT sensor library**.

## Working Principle
1. The DHT11 measures greenhouse temperature and humidity.
2. If temperature or humidity reaches the ON limit, Arduino starts the fan.
3. The fan improves airflow in the model greenhouse.
4. The fan remains ON until both temperature and humidity fall below the lower OFF limits.
5. Two sets of thresholds prevent rapid switching.

## Use Cases
- Greenhouse ventilation
- Smart agriculture
- Climate-control lessons
- Automatic fan projects
