# Temperature Monitor Using LM35 Sensor

## Description
A temperature monitor that uses an LM35 analog temperature sensor and a 16x2 I2C LCD. The Arduino converts the LM35 voltage into degrees Celsius and displays the result.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| LM35 Temperature Sensor | 1 |
| 16x2 I2C LCD | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | LM35 VCC and I2C LCD VCC |
| GND | LM35 GND and I2C LCD GND |
| A0 | LM35 OUT |
| A4 | I2C LCD SDA |
| A5 | I2C LCD SCL |

## Code
See [`temperature_monitor_lm35.ino`](./temperature_monitor_lm35.ino).

This sketch requires a **LiquidCrystal_I2C** library.

## Working Principle
1. The LM35 produces an output voltage proportional to temperature.
2. Arduino reads the voltage through A0.
3. The LM35 scale is approximately 10 mV for each degree Celsius.
4. Arduino converts the analog reading into temperature.
5. The temperature is displayed on the LCD.

## Use Cases
- Room temperature monitoring
- Temperature sensor lessons
- Environmental experiments
- STEM projects
