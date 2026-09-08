# Obstacle Detector Using HC-SR04 Ultrasonic Sensor

## Description
This project detects nearby objects using an HC-SR04 ultrasonic sensor. The Arduino calculates the distance between the sensor and an obstacle and activates an LED and buzzer when the object comes closer than a specified distance.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Buzzer | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

## Circuit Connections

```text
HC-SR04 ULTRASONIC SENSOR
VCC ---> Arduino 5V
GND ---> Arduino GND
TRIG ---> Arduino D9
ECHO ---> Arduino D10

BUZZER
Positive ---> Arduino D7
Negative ---> Arduino GND

LED
Arduino D6 ---> 220 Ω Resistor ---> LED Anode (+)
LED Cathode (-) ---> Arduino GND
```

## Code
See [`obstacle_detector.ino`](./obstacle_detector.ino).

## Working Principle
1. Arduino sends a short trigger pulse to the HC-SR04 sensor.
2. The sensor transmits an ultrasonic sound pulse.
3. The sound wave travels toward an object and reflects back.
4. The HC-SR04 produces an ECHO pulse whose duration represents the round-trip travel time.
5. Arduino uses that travel time and the speed of sound to estimate the distance.
6. When the detected object is within the configured threshold, the LED turns ON and the buzzer sounds.
7. When no obstacle is within that range, both indicators remain OFF.

## Use Cases
- Robot obstacle avoidance
- Reverse parking assistance
- Distance measurement
- Automatic doors
- Smart dustbins
- Security systems
- Industrial object detection
