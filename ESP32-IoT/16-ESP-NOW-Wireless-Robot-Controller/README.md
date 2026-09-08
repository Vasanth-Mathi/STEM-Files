# ESP32 Wireless Robot Remote Controller Using ESP-NOW

## Description
Uses one ESP32 with a joystick as a handheld ESP-NOW transmitter and another ESP32 to control a four-wheel robot.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 2 |
| Dual-Axis Joystick Module | 1 |
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
| Remote GPIO 34 | Joystick VRx |
| Remote GPIO 35 | Joystick VRy |
| Robot GPIO 25 | Driver 1 IN1 and Driver 2 IN1 |
| Robot GPIO 26 | Driver 1 IN2 and Driver 2 IN2 |
| Robot GPIO 27 | Driver 1 IN3 and Driver 2 IN3 |
| Robot GPIO 14 | Driver 1 IN4 and Driver 2 IN4 |
| Robot GND | Both motor-driver GND pins |
| Motor Battery + | Both driver motor-power inputs |
| Motor Battery - | Both driver GND pins |

> Keep ENA and ENB jumpers fitted on both L298N modules for this full-speed version.
> Adjust the joystick threshold values if your joystick does not center near the middle of the ESP32 ADC range.

## Code
See [`espnow_wireless_robot_controller.ino`](./espnow_wireless_robot_controller.ino).

## Working Principle
1. Set `REMOTE_MODE` to `true` for the joystick ESP32 and enter the robot ESP32 MAC address.
2. Set `REMOTE_MODE` to `false` on the robot.
3. Joystick X and Y values are transmitted through ESP-NOW.
4. The robot interprets the joystick position as forward, backward, left, right, or stop.

## Use Cases
- Wireless robotics
- Remote-control design
- Joystick interfacing
- ESP-NOW control systems
