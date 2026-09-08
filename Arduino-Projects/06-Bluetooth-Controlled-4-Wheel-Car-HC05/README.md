# Bluetooth Controlled 4-Wheel Car Using HC-05 Bluetooth Module

## Description
A four-wheel robot car controlled from a phone or computer through an HC-05 Bluetooth module. The Arduino receives simple commands and moves the car forward, backward, left, right, or stop.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-05 Bluetooth Module | 1 |
| 1 kΩ Resistor | 1 |
| 2 kΩ Resistor | 1 |
| L298N Motor Driver Module | 2 |
| 6V DC Geared Motor | 4 |
| Wheel | 4 |
| 4-Wheel Robot Chassis | 1 |
| 7.4V Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | HC-05 VCC |
| GND | HC-05 GND |
| D2 | HC-05 TX |
| D3 | HC-05 RX through 1 kΩ / 2 kΩ voltage divider |
| D8 | Motor Driver 1 IN1 and Motor Driver 2 IN1 |
| D9 | Motor Driver 1 IN2 and Motor Driver 2 IN2 |
| D10 | Motor Driver 1 IN3 and Motor Driver 2 IN3 |
| D11 | Motor Driver 1 IN4 and Motor Driver 2 IN4 |

### Motor Connections

| Motor | Connect To |
|---|---|
| Front Left Motor | Motor Driver 1 OUT1 and OUT2 |
| Front Right Motor | Motor Driver 1 OUT3 and OUT4 |
| Rear Left Motor | Motor Driver 2 OUT1 and OUT2 |
| Rear Right Motor | Motor Driver 2 OUT3 and OUT4 |

### Power Connections

| From | Connect To |
|---|---|
| Motor Battery + | Motor Driver 1 Motor Power and Motor Driver 2 Motor Power |
| Motor Battery - | Motor Driver 1 GND and Motor Driver 2 GND |
| Arduino GND | Motor Driver 1 GND and Motor Driver 2 GND |

> Keep the ENA and ENB jumpers fitted on both L298N modules.

> Use the resistor voltage divider between Arduino D3 and HC-05 RX because the HC-05 RX logic input is 3.3 V.

## Code
See [`bluetooth_controlled_car.ino`](./bluetooth_controlled_car.ino).

## Working Principle
1. The HC-05 receives a command sent from a paired Bluetooth device.
2. Arduino reads the command through software serial.
3. Command `F` moves the car forward.
4. Command `B` moves the car backward.
5. Commands `L` and `R` turn the car left and right.
6. Command `S` stops the car.

## Use Cases
- Bluetooth robotics
- Mobile-controlled vehicles
- Wireless communication lessons
- STEM robotics activities
