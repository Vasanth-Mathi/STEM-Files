# ESP32 Blynk IoT Water Tank Level Monitoring System

## Description
Measures the distance from an ultrasonic sensor to the water surface and sends the estimated tank-fill percentage to Blynk.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 1 kΩ Resistor | 1 |
| 2 kΩ Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 5V / VIN | HC-SR04 VCC |
| GND | HC-SR04 GND |
| GPIO 5 | HC-SR04 TRIG |
| GPIO 18 | HC-SR04 ECHO through a voltage divider |
| HC-SR04 ECHO | 1 kΩ to GPIO 18 and 2 kΩ from GPIO 18 to GND |

> The HC-SR04 ECHO signal is 5 V. Use the resistor divider shown above before connecting it to the 3.3 V ESP32 GPIO.
> Set `TANK_DEPTH_CM` to the measured sensor-to-bottom distance of the actual tank.

## Code
See [`blynk_water_tank_level.ino`](./blynk_water_tank_level.ino).

## Working Principle
1. The ESP32 measures the distance between the sensor and the water surface.
2. The distance is converted to an estimated percentage using the configured tank depth.
3. The percentage is sent to Blynk virtual pin V0.
4. Invalid ultrasonic readings are ignored instead of being reported as false tank levels.

## Use Cases
- Water-tank monitoring
- Distance-sensor lessons
- Blynk gauges
- IoT water-management prototypes
