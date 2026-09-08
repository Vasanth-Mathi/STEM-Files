# Soil Moisture Based Irrigation Using Capacitive Soil Moisture Sensor

## Description
An automatic irrigation prototype that checks soil moisture using a capacitive sensor. When the soil becomes dry, Arduino starts a small water pump through an L298N motor driver and stops it when the soil becomes sufficiently moist.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Capacitive Soil Moisture Sensor | 1 |
| L298N Motor Driver Module | 1 |
| 6V Mini Water Pump | 1 |
| 7.4V Motor Battery Pack | 1 |
| Water Tube | As required |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Capacitive Soil Moisture Sensor VCC |
| GND | Sensor GND and Motor Driver GND |
| A0 | Sensor AOUT |
| D8 | Motor Driver IN1 |
| D9 | Motor Driver IN2 |

### Pump Connections

| Component | Connect To |
|---|---|
| 6V Mini Water Pump | Motor Driver OUT1 and OUT2 |

### Power Connections

| From | Connect To |
|---|---|
| Motor Battery + | Motor Driver Motor Power |
| Motor Battery - | Motor Driver GND |
| Arduino GND | Motor Driver GND |

> Keep the ENA jumper fitted on the L298N channel used for the pump.

> Calibrate the moisture thresholds using the actual soil and sensor before running the pump.

## Code
See [`soil_moisture_irrigation.ino`](./soil_moisture_irrigation.ino).

## Working Principle
1. The capacitive sensor measures soil moisture and sends an analog value to A0.
2. With many common modules, drier soil produces a higher reading.
3. When the reading reaches the dry threshold, Arduino starts the pump.
4. The pump remains ON until the reading falls below the wetter OFF threshold.
5. Using two thresholds prevents the pump from rapidly switching ON and OFF.

## Use Cases
- Automatic plant watering
- Smart agriculture models
- Soil moisture lessons
- Irrigation automation
