# Digital Measuring Tape Using Ultrasonic Sensor

## Description
A digital distance-measuring project that uses an HC-SR04 ultrasonic sensor and a 16x2 I2C LCD. The Arduino measures the distance to an object and displays the result in centimetres.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 16x2 I2C LCD | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | HC-SR04 VCC and I2C LCD VCC |
| GND | HC-SR04 GND and I2C LCD GND |
| D2 | HC-SR04 TRIG |
| D3 | HC-SR04 ECHO |
| A4 | I2C LCD SDA |
| A5 | I2C LCD SCL |

## Code
See [`digital_measuring_tape.ino`](./digital_measuring_tape.ino).

This sketch requires a **LiquidCrystal_I2C** library.

## Working Principle
1. Arduino sends a short trigger pulse to the HC-SR04.
2. The sensor sends an ultrasonic pulse and measures the returning echo.
3. Arduino calculates the distance from the echo travel time.
4. The measured distance is shown on the LCD.
5. If no valid echo is received, the LCD shows that the object is out of range.

## Use Cases
- Digital measuring tools
- Ultrasonic sensor lessons
- Distance measurement experiments
- STEM demonstrations
