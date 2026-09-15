# ESP32 ESP-NOW Remote-Controlled Drone

## Description

This project uses **two ESP32 boards** to build an educational remote-controlled brushed-motor quadcopter prototype.

- **ESP32 1 - Remote Controller** reads two joysticks and an ARM / DISARM button.
- **ESP32 2 - Drone Flight Controller** receives those commands through ESP-NOW, reads an MPU6050 motion sensor, and controls four brushed DC motors through four separate MOSFET motor-driver stages.

The project is designed to teach students how a wireless controller, motion sensor, feedback control, motor mixing, and safety failsafe work together in a simple drone-control system.

> This is an advanced educational prototype. The included control values are starting values for experimentation. Real flight requires careful motor selection, propeller direction, frame balance, IMU orientation, power-system design, and PID tuning.

## System Overview

```text
Two Joysticks + ARM Button
          |
          v
ESP32 1 - Remote Controller
          |
          |  ESP-NOW
          v
ESP32 2 - Drone Flight Controller
          |
          +----> MPU6050 IMU
          |
          +----> Motor Driver 1 ---> Motor 1
          +----> Motor Driver 2 ---> Motor 2
          +----> Motor Driver 3 ---> Motor 3
          +----> Motor Driver 4 ---> Motor 4
```

Both ESP32 boards use the same **ESP-NOW channel** and the same **PAIR_KEY**. Packets with a different pairing key are ignored by the drone receiver.

## Components

### ESP32 1 - Remote Controller

| Component | Quantity |
|---|---:|
| ESP32 development board | 1 |
| Dual-axis joystick module | 2 |
| Push button for ARM / DISARM | 1 |
| Jumper wires | As required |
| Suitable USB or battery power source | 1 |

### ESP32 2 - Drone

| Component | Quantity |
|---|---:|
| ESP32 development board | 1 |
| MPU6050 IMU module | 1 |
| Small brushed DC motor | 4 |
| Propeller matched to the motors | 4 |
| Logic-level N-channel MOSFET motor-driver stage | 4 |
| Flyback / suppression diode suitable for each motor | 4 |
| Gate resistor and gate pull-down resistor | 4 sets |
| Lightweight quadcopter frame | 1 |
| Battery matched to the chosen motors | 1 |
| Suitable regulated supply for the ESP32 | 1 |
| Lightweight wiring | As required |

## Circuit Connections

## ESP32 1 - Remote Controller

Two joysticks provide the four basic flight controls.

| ESP32 1 Pin | Connection | Purpose |
|---|---|---|
| 3.3V | Both joystick VCC pins | Joystick power |
| GND | Both joystick GND pins | Common ground |
| GPIO 34 | Left joystick vertical axis | Throttle |
| GPIO 35 | Left joystick horizontal axis | Yaw |
| GPIO 32 | Right joystick horizontal axis | Roll |
| GPIO 33 | Right joystick vertical axis | Pitch |
| GPIO 25 | ARM / DISARM button to GND | Safety control |

The ARM button uses `INPUT_PULLUP`, so the button connects between **GPIO 25 and GND**.

> Use joystick modules whose analog outputs are safe for the ESP32's 3.3V GPIO inputs. ESP32 GPIO pins are not 5V tolerant.

## ESP32 2 - MPU6050

| ESP32 2 Pin | MPU6050 Pin |
|---|---|
| 3.3V | VCC on a 3.3V-compatible MPU6050 module |
| GND | GND |
| GPIO 21 | SDA |
| GPIO 22 | SCL |

The code uses MPU6050 I2C address `0x68`, which is the common address when the module's AD0 input is LOW.

## ESP32 2 - Motor Control Signals

The flight code and this table use the same motor-control pins.

| ESP32 2 Pin | Connect To |
|---|---|
| GPIO 13 | Motor 1 MOSFET driver input |
| GPIO 14 | Motor 2 MOSFET driver input |
| GPIO 25 | Motor 3 MOSFET driver input |
| GPIO 26 | Motor 4 MOSFET driver input |

Each motor requires its **own driver stage**. Do not connect a brushed motor directly to an ESP32 GPIO pin.

## One Motor-Driver Stage

Repeat this basic switching stage for all four motors.

```text
Motor Battery + -------------------- Motor +
                                       |
                                     Motor
                                       |
Motor - -------------------------- MOSFET Drain

ESP32 PWM Pin -- Gate Resistor --> MOSFET Gate
MOSFET Gate ---- Pull-down ------> GND
MOSFET Source --------------------> GND
Motor Battery - ------------------> GND
ESP32 GND ------------------------> GND
```

A suitable flyback / suppression diode should be connected according to the selected brushed-motor driver design.

Choose a MOSFET and diode that can safely handle the **stall current** of the actual motors. Motor current must not pass through an ESP32 GPIO pin.

## Power Connections

The motors and ESP32 should not be treated as one tiny load.

```text
Motor Battery ---> Four Motor Driver Stages ---> Four Motors
        |
        +------ Common Ground ------ ESP32 2

Suitable Regulated Supply ----------> ESP32 2
```

Important rules:

- Match the motor battery voltage to the actual motors.
- Use a regulator suitable for powering the ESP32 when required.
- Connect the ESP32 ground and motor-driver ground together.
- Do not power the four motors from the ESP32 board.
- Check the battery's current capability against the total motor load.

## Motor Layout

The flight code assumes this X-style layout when viewed from above.

```text
               FRONT

        M1               M2
    Front Left       Front Right


        M4               M3
     Rear Left        Rear Right
```

For yaw control, diagonally opposite motors normally rotate in the same direction while the other diagonal rotates in the opposite direction.

The actual **CW / CCW motor and propeller arrangement must be checked on the physical frame** before flight testing.

## Code

### ESP32 1 - Remote Controller

[`drone_remote_sender.ino`](./drone_remote_sender.ino)

The sender code:

1. Reads throttle, yaw, roll, and pitch from two joysticks.
2. Allows arming only when throttle is low.
3. Sends a control packet every 20 ms using ESP-NOW.
4. Includes a pairing key in every packet.
5. Starts in the disarmed state.

### ESP32 2 - Drone Flight Controller

[`drone_flight_receiver.ino`](./drone_flight_receiver.ino)

The receiver code:

1. Receives the remote-control packet.
2. Rejects packets with the wrong pairing key.
3. Reads the MPU6050 accelerometer and gyroscope.
4. Estimates roll and pitch using a complementary filter.
5. Applies PID-style roll and pitch correction.
6. Applies yaw-rate correction.
7. Mixes the corrections into four motor PWM outputs.
8. Stops all motors when the controller signal is lost.

## ESP-NOW Pairing Settings

The same two values must appear in **both** sketches:

```cpp
const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PAIR_KEY = 0xD31A2026;
```

For a different classroom group, students can change `PAIR_KEY`, but the value must be identical in both the sender and receiver code.

This pairing key is an educational identifier, not cryptographic security.

## Working Principle

### 1. Pilot Input

The joystick controls are arranged as follows:

```text
Left joystick vertical    ---> Throttle
Left joystick horizontal  ---> Yaw
Right joystick horizontal ---> Roll
Right joystick vertical   ---> Pitch
```

### 2. Wireless Transmission

ESP32 1 converts the joystick positions into control values and sends them using ESP-NOW.

```text
Joysticks ---> ESP32 1 ~~~ ESP-NOW ~~~> ESP32 2
```

### 3. Motion Sensing

The MPU6050 measures acceleration and angular movement.

ESP32 2 combines accelerometer and gyroscope information to estimate the drone's roll and pitch angles.

### 4. Feedback Correction

If the measured angle is different from the angle requested by the remote, the program calculates a correction.

Example:

```text
Drone tilts right
       |
       v
MPU6050 detects roll change
       |
       v
Controller calculates correction
       |
       v
Left / right motor outputs change
       |
       v
Drone is pushed back toward the requested angle
```

### 5. Motor Mixing

The motors do not always receive the same PWM value.

Each final motor command is calculated using:

- Base throttle
- Roll correction
- Pitch correction
- Yaw correction

This motor mixing allows the quadcopter to rise, tilt, turn, and stabilize.

## Failsafe Behaviour

The receiver stops all four motors when:

- The remote is disarmed.
- No valid control packet has been received for more than the configured timeout.
- The MPU6050 cannot initialize.
- An MPU6050 reading fails during operation.
- Throttle is below the motor-start threshold.

The remote also refuses to arm while throttle is high.

## First Test Procedure

Always begin with **all propellers removed**.

1. Upload `drone_remote_sender.ino` to ESP32 1.
2. Upload `drone_flight_receiver.ino` to ESP32 2.
3. Confirm that both sketches use the same `ESPNOW_CHANNEL` and `PAIR_KEY`.
4. Power the remote and drone electronics.
5. Keep the drone completely still during gyro calibration.
6. Confirm that the MPU6050 initializes successfully.
7. Move each joystick and confirm the expected control direction.
8. Check all four PWM motor outputs with propellers removed.
9. Confirm Motor 1, Motor 2, Motor 3, and Motor 4 match the physical frame positions.
10. Confirm motor rotation and propeller direction.
11. Check roll and pitch correction direction before any free-flight attempt.
12. Tune the control constants gradually on the actual frame.

## Calibration and Tuning

The included PID-style values are **starting values only**.

Real tuning depends on:

- Motor size
- Propeller size
- Battery voltage
- Frame weight
- Frame geometry
- Center of gravity
- MPU6050 orientation
- Motor-driver behaviour
- PWM characteristics

A value that works on one drone may perform badly on another.

## Safety

- Remove all propellers during programming and initial motor tests.
- Keep hands, hair, loose wires, and clothing away from spinning propellers.
- Use motor drivers and wiring rated for the actual motor current.
- Never power a brushed motor directly from an ESP32 GPIO pin.
- Secure the battery, ESP32, IMU, and wiring to the frame.
- Test motor direction before attaching propellers.
- Use a suitable battery and charger designed for that battery chemistry.
- Test in an open, controlled area with appropriate adult supervision for school activities.
- Treat this as an educational prototype, not a certified flight controller.

## What Students Learn

- ESP32-to-ESP32 communication
- ESP-NOW wireless control
- Multi-board project design
- Joystick interfacing
- MPU6050 motion sensing
- PWM motor control
- MOSFET motor-driver concepts
- Feedback control
- PID fundamentals
- Motor mixing
- Failsafe programming
- Power-system planning

## Use Cases

- ESP-NOW learning project
- Wireless-control experiments
- Introduction to drone electronics
- IMU and feedback-control demonstrations
- Motor-mixing experiments
- Embedded robotics and flight-control education
