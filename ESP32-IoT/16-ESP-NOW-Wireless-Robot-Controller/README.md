# ESP32 Wireless Robot Remote Controller Using ESP-NOW

## Description

This project uses one ESP32 as a handheld joystick transmitter and a second ESP32 on a four-wheel robot. The two boards communicate directly using ESP-NOW.

The robot uses **four DC motors and two dual-channel L298N motor-driver modules**, so each motor has its own H-bridge channel. Matching direction inputs are shared between the two drivers.

```text
Joystick ---> ESP32 1 Remote ~~~ ESP-NOW ~~~> ESP32 2 Robot
                                              |
                                              v
                                      2 × L298N Drivers
                                              |
                                              v
                                         4 DC Motors
```

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 2 |
| Dual-Axis Joystick Module | 1 |
| L298N Dual-Channel Motor Driver | 2 |
| DC Geared Motor | 4 |
| Wheel | 4 |
| Four-wheel chassis | 1 |
| Motor battery matched to motor rating | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 1 - Remote Sender

The joystick uses ADC1 pins, which remain available while ESP-NOW is active.

| ESP32 1 Pin | Connect To |
|---|---|
| 3.3V | Joystick VCC |
| GND | Joystick GND |
| GPIO 34 | Joystick VRx |
| GPIO 35 | Joystick VRy |

### ESP32 2 - Robot Receiver to L298N Drivers

| ESP32 2 Pin | Connect To |
|---|---|
| GPIO 25 | Driver 1 IN1 + Driver 2 IN1 |
| GPIO 26 | Driver 1 IN2 + Driver 2 IN2 |
| GPIO 27 | Driver 1 IN3 + Driver 2 IN3 |
| GPIO 14 | Driver 1 IN4 + Driver 2 IN4 |
| GND | GND of both L298N modules |

Keep **ENA and ENB jumpers fitted** on both modules for this full-speed version.

### Motor Connections

| Driver Output | Motor |
|---|---|
| Driver 1 OUT1 / OUT2 | Front-left motor |
| Driver 1 OUT3 / OUT4 | Front-right motor |
| Driver 2 OUT1 / OUT2 | Rear-left motor |
| Driver 2 OUT3 / OUT4 | Rear-right motor |

### Power Connections

| Connection | Connect To |
|---|---|
| Motor battery + | Motor-supply input of both L298N modules |
| Motor battery - | GND of both L298N modules |
| ESP32 2 GND | Same common GND |
| ESP32 boards | USB or suitable regulated supply |

Do not power the four motors from the ESP32. The motor-battery voltage must match the motors being used.

## Code

- **ESP32 1 Remote Sender:** [`remote_sender.ino`](./remote_sender.ino)
- **ESP32 2 Robot Receiver:** [`robot_receiver.ino`](./robot_receiver.ino)

The receiver includes a communication failsafe. If valid packets stop arriving, the robot stops.

## Working Principle

1. ESP32 1 reads the joystick X and Y values.
2. It broadcasts the values using ESP-NOW.
3. ESP32 2 receives the latest valid packet.
4. The robot compares the joystick position with a center dead zone.
5. The motors are commanded forward, backward, left, right, or stop.
6. If the wireless link is lost, the receiver stops the robot automatically.

## Use Cases

- Wireless robotics
- Remote-control systems
- Joystick interfacing
- ESP-NOW control projects
