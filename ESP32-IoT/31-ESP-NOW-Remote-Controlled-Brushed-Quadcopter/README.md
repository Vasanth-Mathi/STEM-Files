# ESP32 ESP-NOW Remote Controlled Brushed-Motor Quadcopter

## Description

This project is an **educational remote-controlled quadcopter prototype** using two ESP32 boards.

- **ESP32 1** is the handheld remote.
- **ESP32 2** is the flight controller mounted on the quadcopter.
- Four brushed DC motors are controlled through four MOSFET motor-driver stages.
- An MPU6050 IMU measures motion so the flight controller can stabilize roll and pitch.
- ESP-NOW carries throttle, roll, pitch, yaw, and arm/disarm commands from the remote to the quadcopter.

A quadcopter cannot fly reliably by sending four motor speeds directly from a joystick. It needs continuous motion sensing and stabilization. This project therefore includes a basic complementary filter and PID-style stabilization loop.

```text
Two Joysticks
     |
     v
ESP32 1 Remote
     |
     | ESP-NOW
     v
ESP32 2 Flight Controller <--- MPU6050 IMU
     |
     +----> MOSFET Driver 1 ---> Motor 1
     +----> MOSFET Driver 2 ---> Motor 2
     +----> MOSFET Driver 3 ---> Motor 3
     +----> MOSFET Driver 4 ---> Motor 4
```

## Important Safety Note

**Remove all propellers during wiring, programming, calibration, and first motor tests.**

A spinning propeller can cause injury. Do not arm the system on a desk with propellers fitted. Use a proper frame, motor guards where possible, and a clear open test area.

This code is a learning prototype, not a certified flight controller. Real flight requires careful motor-direction checks, center-of-gravity adjustment, PID tuning, battery selection, propeller matching, and controlled testing.

## Components

| Component | Quantity |
|---|---:|
| ESP32 board | 2 |
| Dual-axis joystick module | 2 |
| Push button for arm/disarm | 1 |
| MPU6050 IMU | 1 |
| Small brushed DC motor | 4 |
| Logic-level N-channel MOSFET motor-driver stage | 4 |
| Flyback diode suitable for each motor | 4 |
| Gate resistor around 100 Ω | 4 |
| Gate pull-down resistor around 10 kΩ | 4 |
| Quadcopter frame | 1 |
| Correct CW/CCW propeller set | 1 set |
| Motor battery matched to motor rating | 1 |
| Regulated supply for ESP32 electronics | 1 |
| Jumper wires / lightweight wiring | As required |

> Do **not** connect any motor directly to an ESP32 GPIO pin.

## Circuit Connections

### ESP32 1 - Handheld Remote Sender

The joystick analog outputs use **ADC1 pins**, which are suitable while Wi-Fi/ESP-NOW is active.

| ESP32 1 Pin | Connect To |
|---|---|
| GPIO 34 | Throttle joystick vertical output |
| GPIO 35 | Yaw joystick horizontal output |
| GPIO 32 | Pitch joystick vertical output |
| GPIO 33 | Roll joystick horizontal output |
| GPIO 25 | Arm/disarm push button to GND |
| 3.3V | Joystick VCC pins |
| GND | Joystick GND and arm-button GND |

### ESP32 2 - MPU6050

| ESP32 2 Pin | MPU6050 |
|---|---|
| 3.3V | VCC |
| GND | GND |
| GPIO 21 | SDA |
| GPIO 22 | SCL |

### ESP32 2 - Motor Control Outputs

| ESP32 2 Pin | Motor Driver Stage |
|---|---|
| GPIO 13 | Motor 1 MOSFET gate driver |
| GPIO 14 | Motor 2 MOSFET gate driver |
| GPIO 25 | Motor 3 MOSFET gate driver |
| GPIO 26 | Motor 4 MOSFET gate driver |

### One Brushed-Motor Driver Stage

Repeat this circuit four times.

```text
ESP32 GPIO ---- 100 Ω ---- MOSFET Gate
                         |
                        10 kΩ
                         |
                        GND

Battery + ---------------------- Motor +
Motor - ------------------------ MOSFET Drain
MOSFET Source ------------------ GND

Flyback diode across motor:
Cathode ---> Battery + / Motor +
Anode   ---> Motor - / MOSFET Drain
```

Use a **logic-level N-channel MOSFET** that switches properly from a 3.3V gate signal.

### Common Ground

The following grounds must be connected together:

- ESP32 2 GND
- MPU6050 GND
- Motor-driver MOSFET source grounds
- Motor battery negative
- Regulated ESP32 supply ground

### Motor Layout

The receiver sketch assumes this X-frame layout:

```text
             FRONT

       M1              M2
      CCW              CW


       M4              M3
       CW             CCW

              REAR
```

Motor wiring and propeller direction must match the physical frame.

With a single-MOSFET unidirectional driver, each motor's rotation direction is set by its wiring polarity. Use motors/propellers intended for alternating CW/CCW positions and verify every motor direction with propellers removed.

## Code

Upload the two sketches separately:

- **ESP32 1 Remote Sender:** [`drone_remote_sender.ino`](./drone_remote_sender.ino)
- **ESP32 2 Flight Receiver:** [`drone_flight_receiver.ino`](./drone_flight_receiver.ino)

## Remote Controls

| Control | Function |
|---|---|
| Throttle joystick | Increase / decrease total motor power |
| Roll joystick | Tilt left / right |
| Pitch joystick | Tilt forward / backward |
| Yaw joystick | Rotate left / right |
| Arm button | Arm or disarm when throttle is low |

If a joystick moves in the opposite direction from what you expect, change the relevant `REVERSE_...` constant in the sender sketch.

## Working Principle

1. ESP32 1 reads four joystick axes.
2. The remote sends commands every 20 ms using ESP-NOW.
3. ESP32 2 receives the latest valid control packet.
4. The flight controller reads the MPU6050.
5. Accelerometer and gyroscope readings are combined using a complementary filter.
6. The code calculates roll, pitch, and yaw corrections.
7. Motor mixing produces four PWM values.
8. The four MOSFET stages control the four brushed motors.
9. If communication is lost for more than the failsafe time, all motors stop.

## First Test Procedure

1. **Remove all propellers.**
2. Power the flight controller.
3. Keep the frame completely still while the gyroscope calibrates.
4. Confirm that the remote only arms when throttle is low.
5. Check that moving throttle changes all four motor outputs together.
6. Tilt the frame by hand and confirm the controller tries to correct the tilt.
7. Verify motor numbering and motor rotation directions.
8. Fit propellers only after the above tests pass.
9. Begin with very low-power restrained or protected tests.
10. Tune PID values gradually for the actual frame, motors, battery, and propellers.

## Important Technical Notes

- The code targets the **Arduino-ESP32 3.x** API.
- Motor PWM uses the current pin-based `ledcAttach()` and `ledcWrite()` style.
- The MPU6050 is read directly over I2C, so no third-party MPU6050 library is required.
- The ESP-NOW receiver includes a communication failsafe.
- PID values are starting values only. They are not universal because every physical quadcopter behaves differently.
- The ESP32 and motors should use suitable power supplies. Do not power four motors from the ESP32 regulator.

## Use Cases

- Learning ESP-NOW remote control
- Studying quadcopter motor mixing
- Learning IMU sensing
- Introduction to feedback control and PID
- Robotics and flight-control experiments
