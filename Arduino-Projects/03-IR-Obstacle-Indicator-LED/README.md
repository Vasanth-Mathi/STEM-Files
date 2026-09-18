# IR Obstacle Indicator Using LED

## Description
A simple sensor-and-output project that uses an IR obstacle sensor and one LED. When an object is detected in front of the sensor, Arduino turns the LED ON.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| IR Obstacle Sensor Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | IR Sensor VCC |
| GND | IR Sensor GND and LED cathode (-) |
| D2 | IR Sensor DO |
| D8 | 220 Ω resistor ---> LED anode (+) |

> Many IR obstacle modules output LOW when an object is detected. Change `OBJECT_DETECTED_STATE` if your module uses the opposite logic.

## Code
See [`ir_obstacle_led.ino`](./ir_obstacle_led.ino).

## Working Principle
1. The IR sensor sends infrared light toward the area in front of it.
2. A nearby object can reflect some of the light back to the sensor.
3. The sensor module changes its digital output when the detection level is reached.
4. Arduino reads the signal through D2.
5. The LED turns ON when an object is detected.

## Use Cases
- IR-sensor lessons
- Object-detection demonstrations
- Simple indicator systems
- Beginner robotics preparation
