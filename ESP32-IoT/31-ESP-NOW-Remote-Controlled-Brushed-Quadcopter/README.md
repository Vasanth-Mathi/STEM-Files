# ESP32 ESP-NOW Remote Controlled Brushed-Motor Quadcopter

## Description

This project uses **two ESP32 boards** to create an educational remote-controlled brushed-motor quadcopter prototype.

- **ESP32 1 - Remote Controller** reads two joysticks and sends throttle, roll, pitch, yaw, and arm/disarm commands using ESP-NOW.
- **ESP32 2 - Flight Controller** receives those commands, reads an MPU6050 IMU, performs basic attitude stabilization, and controls four brushed DC motors through four MOSFET motor-driver stages.

> This is an advanced educational prototype. A quadcopter cannot be made safely flyable by connecting four motors directly to an ESP32 or by sending four raw motor speeds. It needs motor drivers, an IMU, correct motor/propeller direction, a balanced frame, PID tuning, a suitable battery, and careful testing.

## Components

### ESP32 1 - Remote Controller

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 1 |
| Dual-Axis Joystick Module | 2 |
| Push Button for ARM / DISARM | 1 |
| Jumper Wires | As required |
| Suitable USB / battery power source | 1 |

### ESP32 2 - Quadcopter

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 1 |
| MPU6050 IMU Module | 1 |
| Small brushed DC motor | 4 |
| Propeller matched to the motors | 4 |
| Logic-level N-channel MOSFET motor-driver stage | 4 |
| Flyback / suppression components appropriate for the chosen motors | As required |
| Lightweight quadcopter frame | 1 |
| Battery matched to the motors and ESP32 power system | 1 |
| Regulated supply for ESP32 when required | 1 |
| Jumper wires / lightweight wiring | As required |

## Communication

The two ESP32 boards communicate directly using ESP-NOW.

```text
ESP32 1 Remote Controller
        |
        |  ESP-NOW
        v
ESP32 2 Flight Controller
        |
        +--> MPU6050 feedback
        |
        +--> Motor 1
        +--> Motor 2
        +--> Motor 3
        +--> Motor 4
```

Both ESP32 boards must use the same ESP-NOW Wi-Fi channel.

## Circuit Connections

### ESP32 1 - Remote Controller

Two joysticks are used so the remote has the usual four flight controls.

| ESP32 1 Pin | Connect To |
|---|---|
| 3.3V | Both joystick VCC pins |
| GND | Both joystick GND pins and ARM button GND |
| GPIO 34 | Left joystick vertical axis - throttle |
| GPIO 35 | Left joystick horizontal axis - yaw |
| GPIO 32 | Right joystick horizontal axis - roll |
| GPIO 33 | Right joystick vertical axis - pitch |
| GPIO 25 | ARM / DISARM push button to GND |

The button uses `INPUT_PULLUP`, so no external pull-up resistor is required.

> Confirm that the joystick modules are safe at 3.3V before connecting their analog outputs to ESP32 ADC pins. ESP32 GPIO inputs are not 5V tolerant.

### ESP32 2 - MPU6050

| ESP32 2 Pin | MPU6050 |
|---|---|
| 3.3V | VCC on a 3.3V-compatible MPU6050 module |
| GND | GND |
| GPIO 21 | SDA |
| GPIO 22 | SCL |

The sketch uses I2C address `0x68`, which is the common default when AD0 is LOW.

### ESP32 2 - Motor Control Signals

| ESP32 2 Pin | Motor Driver |
|---|---|
| GPIO 25 | Motor 1 MOSFET PWM input |
| GPIO 26 | Motor 2 MOSFET PWM input |
| GPIO 27 | Motor 3 MOSFET PWM input |
| GPIO 14 | Motor 4 MOSFET PWM input |

### One Brushed-Motor Driver Stage

Each motor needs its **own** switching stage. Repeat this circuit four times.

```text
Battery + -------------------------- Motor +
                                      Motor
Motor - ---------------------------- MOSFET Drain
ESP32 PWM Pin ---- Gate resistor ---> MOSFET Gate
MOSFET Gate ------ Pull-down -------> GND
MOSFET Source ----------------------> GND
Battery - --------------------------> GND
ESP32 GND --------------------------> GND
```

Use a motor-driver design suitable for the stall current of the actual motors. Do not connect a motor directly between an ESP32 GPIO pin and GND.

The motor battery ground and ESP32 ground must be common.

## Motor Layout

The code assumes this X-style layout when viewed from above:

```text
          FRONT

     M1           M2
   Front Left   Front Right


     M4           M3
    Rear Left    Rear Right
```

For yaw control, diagonally opposite motors normally rotate in the same direction and the other diagonal rotates in the opposite direction. The exact CW/CCW motor and propeller arrangement must match the physical frame and propellers.

## Code

### ESP32 1 - Remote Controller

[`drone_remote_sender.ino`](./drone_remote_sender.ino)

This sketch:

1. Reads four joystick axes.
2. Converts them into throttle, roll, pitch, and yaw commands.
3. Uses a push button to arm or disarm the aircraft.
4. Sends the control packet repeatedly through ESP-NOW.
5. Starts in a disarmed state.

Before uploading, replace the placeholder `DRONE_MAC` with the station MAC address printed by ESP32 2.

### ESP32 2 - Flight Controller

[`drone_flight_receiver.ino`](./drone_flight_receiver.ino)

This sketch:

1. Receives commands from the remote through ESP-NOW.
2. Reads acceleration and angular-rate data from the MPU6050.
3. Estimates roll and pitch using a complementary filter.
4. Uses PID-style correction for roll and pitch and rate correction for yaw.
5. Mixes throttle and corrections into four motor commands.
6. Stops the motors if control packets are lost.
7. Requires a deliberate arm command before producing motor output.

## Working Principle

### 1. Remote Input

The pilot moves the two joysticks.

```text
Left vertical   ---> Throttle
Left horizontal ---> Yaw
Right horizontal ---> Roll
Right vertical   ---> Pitch
```

### 2. ESP-NOW Communication

ESP32 1 sends the control values to ESP32 2 many times per second.

```text
Joystick ---> ESP32 1 ~~~ ESP-NOW ~~~> ESP32 2
```

### 3. Stabilization

ESP32 2 reads the MPU6050 to estimate the direction and movement of the aircraft.

If the drone tilts away from the requested angle, the program changes individual motor outputs to oppose that tilt.

Example:

```text
Drone tilts right
      |
      v
IMU detects positive roll
      |
      v
Controller changes left/right motor thrust
      |
      v
Drone is pushed back toward level
```

### 4. Motor Mixing

The four motors do not always run at exactly the same speed. Their speeds are mixed according to:

- Throttle
- Roll correction
- Pitch correction
- Yaw correction

This is what allows a quadcopter to rise, tilt, turn, and stabilize.

## Important Setup Before Testing

1. Upload `drone_flight_receiver.ino` to ESP32 2 with the motors disconnected.
2. Open Serial Monitor and copy the displayed ESP32 station MAC address.
3. Enter that MAC address into `DRONE_MAC` inside `drone_remote_sender.ino`.
4. Upload the sender code to ESP32 1.
5. Confirm that joystick data is being received.
6. Confirm that the MPU6050 is detected.
7. Check the IMU orientation and roll/pitch signs.
8. Test PWM outputs with the **propellers removed**.
9. Confirm every motor number and rotation direction.
10. Tune the stabilization constants gradually before attempting free flight.

## Failsafe Behaviour

The flight-controller code stops all motors when:

- The aircraft is disarmed.
- Communication is lost for longer than the configured timeout.
- The MPU6050 cannot be initialized.
- Throttle is below the minimum armed threshold.

A wireless flight-control prototype should never continue running the motors indefinitely after losing its controller signal.

## Calibration and Tuning

The included PID values are **starting values for experimentation**, not universal flight-ready values. Real values depend on:

- Motor size
- Propeller size
- Battery voltage
- Frame weight
- Frame geometry
- Sensor mounting
- Center of gravity
- PWM characteristics

The MPU6050 gyro offsets should also be calibrated while the aircraft is completely still.

## Safety

- Remove all propellers while testing code, radio communication, IMU direction, and motor outputs.
- Keep hands, hair, wires, and loose objects away from spinning propellers.
- Use a battery and motor drivers rated for the actual motor current.
- Do not power brushed motors from the ESP32 board.
- Secure the battery and electronics to the frame.
- Test at low power before increasing throttle.
- Use an open, controlled test area with adult supervision for school demonstrations.

## Use Cases

- Learning ESP-NOW remote control
- Understanding multi-ESP32 systems
- Learning IMU sensing
- Introduction to feedback control
- Motor mixing experiments
- PID-control learning
- Embedded robotics and flight-control education
