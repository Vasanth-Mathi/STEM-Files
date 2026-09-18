# High Temperature Alarm Using LM35 and Buzzer

## Description
A simple temperature-alert project using an LM35 temperature sensor and an active buzzer. Arduino sounds the buzzer when the measured temperature reaches the selected limit.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| LM35 Temperature Sensor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | LM35 VCC and Buzzer Module VCC |
| GND | LM35 GND and Buzzer Module GND |
| A0 | LM35 OUT |
| D8 | Buzzer Module SIG |

> Check the pin order of your exact LM35 package before wiring it. The calculation below assumes the Arduino Uno ADC reference is approximately 5V and the LM35 output changes by about 10 mV per °C.

## Code
See [`lm35_temperature_buzzer.ino`](./lm35_temperature_buzzer.ino).

## Working Principle
1. The LM35 produces an analog voltage related to temperature.
2. Arduino reads the voltage through A0.
3. The program converts the reading into an approximate temperature in °C.
4. The temperature is compared with `HIGH_TEMPERATURE_C`.
5. The buzzer sounds when the temperature reaches or exceeds the limit.

## Use Cases
- Temperature-sensor lessons
- Simple heat alarms
- Analog measurement experiments
- Threshold-control demonstrations
