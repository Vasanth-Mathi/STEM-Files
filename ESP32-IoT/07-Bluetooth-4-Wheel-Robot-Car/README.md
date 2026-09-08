# ESP32 Bluetooth Controlled 4-Wheel Robot Car

## Description
Controls a four-wheel robot using Bluetooth Classic commands from a phone or computer.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module with Bluetooth Classic | 1 |
| L298N Motor Driver Module | 2 |
| 6V DC Geared Motor | 4 |
| Wheel | 4 |
| 4-Wheel Robot Chassis | 1 |
| Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| GPIO 25 | Motor Driver 1 IN1 and Motor Driver 2 IN1 |
| GPIO 26 | Motor Driver 1 IN2 and Motor Driver 2 IN2 |
| GPIO 27 | Motor Driver 1 IN3 and Motor Driver 2 IN3 |
| GPIO 14 | Motor Driver 1 IN4 and Motor Driver 2 IN4 |
| ESP32 GND | Both motor-driver GND pins |
| Motor Battery + | Both motor-driver motor-power inputs |
| Motor Battery - | Both motor-driver GND pins |

> Keep ENA and ENB jumpers fitted on both L298N modules for this beginner full-speed version.
> Bluetooth Classic requires an ESP32 variant that supports Bluetooth Classic, such as the original ESP32.

## Code
See [`bluetooth_robot_car.ino`](./bluetooth_robot_car.ino).

## Working Principle
1. The ESP32 creates a Bluetooth serial device named `ESP32-Robot`.
2. A phone sends F, B, L, R, or S commands.
3. The ESP32 changes the four shared motor-direction signals.
4. Two L298N modules drive the four motors, one motor per H-bridge channel.

## Use Cases
- Bluetooth robotics
- Wireless-control lessons
- Mobile robot projects
- Physical-computing activities
