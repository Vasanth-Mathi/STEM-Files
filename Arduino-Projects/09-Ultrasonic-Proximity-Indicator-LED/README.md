# Ultrasonic Proximity Indicator Using LED

## Description
A beginner distance-sensing project using an HC-SR04 ultrasonic sensor and one LED. The LED turns ON when an object is detected within the selected distance.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | HC-SR04 VCC |
| GND | HC-SR04 GND and LED cathode (-) |
| D2 | HC-SR04 TRIG |
| D3 | HC-SR04 ECHO |
| D8 | 220 Ω resistor ---> LED anode (+) |

## Code
See [`ultrasonic_proximity_led.ino`](./ultrasonic_proximity_led.ino).

## Working Principle
1. Arduino sends a short trigger pulse to the ultrasonic sensor.
2. The sensor sends an ultrasonic pulse and waits for the echo.
3. Arduino measures the echo time and calculates distance.
4. If a valid distance is at or below `ALERT_DISTANCE_CM`, the LED turns ON.
5. If no valid echo is received or the object is farther away, the LED stays OFF.

## Use Cases
- Distance-sensor lessons
- Simple proximity indicators
- Parking-sensor demonstrations
- Preparation for obstacle-avoiding robots
