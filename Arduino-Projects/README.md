# Arduino STEM Projects

Arduino is an open-source electronics platform used to build interactive projects by combining simple hardware and software. It is widely used in STEM education because it allows students to connect sensors, motors, lights, displays, and other electronic components, then control them using code.

## How Arduino Works

An Arduino board contains a microcontroller that acts as the brain of the project. It continuously reads inputs, processes them according to the uploaded program, and controls outputs.

```text
Input Sensors ---> Arduino Microcontroller ---> Program Logic ---> Output Devices
```

For example:

```text
Ultrasonic Sensor ---> Arduino ---> Distance Calculation ---> Buzzer / LED
```

A typical Arduino project works in the following sequence:

1. Sensors or input devices collect information from the environment.
2. The Arduino reads the input through its digital or analog pins.
3. The microcontroller processes the input based on the uploaded Arduino program.
4. The Arduino sends signals to output devices such as LEDs, buzzers, motors, displays, or relays.
5. This process repeats continuously while the board is powered.

Arduino programs are commonly written in C/C++ using the Arduino IDE and uploaded to the board through USB.

## Standard Power Setup

For the projects in this repository:

- Arduino Uno is powered through its USB port using a power bank, or through the DC jack using a suitable 7-12V supply such as a 9V source.
- Sensors, small modules, and low-power components normally receive 5V from the Arduino 5V pin.
- DC motors are not powered from the Arduino.
- Motor drivers use a separate motor battery.
- The Arduino GND and motor-driver GND must be connected together in robot projects.
- The motor-battery voltage must match the motors being used. A 12V battery should only be used when the motors are rated for that supply.
- Small servos may be powered from Arduino 5V in beginner projects, but servo current can cause resets or jitter. USB power from a capable power bank is preferred for servo-based projects.

## Common Use Cases

Arduino can be used for:

- Robotics and autonomous vehicles
- Home automation
- Smart lighting systems
- Environmental monitoring
- Sensor-based projects
- Internet of Things (IoT) prototypes
- Agriculture automation
- Security and alarm systems
- Industrial prototypes
- Data collection and measurement
- Classroom STEM activities
- Learning electronics, coding, problem-solving, and computational thinking

## Projects

<!-- Keep this list updated whenever a new project folder is added. -->

1. [Line Follower Robot Using IR Sensors](./01-Line-Follower-IR/)
2. [Obstacle Avoiding Robot Using Ultrasonic Sensor](./02-Obstacle-Detector-Ultrasonic/)
3. [Automatic Streetlight Using LDR Sensor](./03-Automatic-Streetlight-LDR/)
4. [Obstacle Avoiding Robot Using Ultrasonic Sensor and Servo Motor](./04-Obstacle-Avoider-Servo-Scan/)
