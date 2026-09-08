# Arduino STEM Projects

## What is Arduino?

Arduino is an open-source electronics platform that helps students turn ideas into working models. An Arduino board can receive information from sensors, make simple decisions using a program, and control output devices such as LEDs, buzzers, displays, motors, relays, and servos.

A simple way to think about Arduino is:

> **Sense something → Think using code → Do something**

For example, an ultrasonic sensor can measure the distance to an object. The Arduino reads that distance and decides whether a robot should move forward, stop, or turn.

Arduino is especially useful in STEM education because one project can combine **science, technology, engineering, mathematics, electronics, coding, design, testing, and problem-solving**.

## Main Parts of an Arduino Uno

The Arduino Uno used in these projects contains several important parts.

| Part | What It Does |
|---|---|
| Microcontroller | Acts as the brain of the Arduino and runs the uploaded program |
| Digital Pins | Read or send HIGH/LOW signals for buttons, LEDs, sensors, motor drivers, and other modules |
| Analog Pins | Measure changing voltage levels from sensors such as LDRs, soil-moisture sensors, and temperature sensors |
| USB Port | Connects the Arduino to a computer and can also provide power |
| DC Power Jack | Allows the Arduino to be powered from a suitable external supply |
| 5V and 3.3V Pins | Provide regulated power for compatible low-power modules and sensors |
| GND Pins | Provide the common electrical ground connection |
| Reset Button | Restarts the program from the beginning |
| Built-in LED | Useful for simple testing and beginner experiments |

## How Arduino Works

An Arduino project usually follows an **Input → Process → Output** cycle.

```text
Input Device ---> Arduino ---> Program Logic ---> Output Device
```

### 1. Input

The Arduino first receives information from an input device.

Examples:

- IR sensor detects a line
- Ultrasonic sensor measures distance
- PIR sensor detects movement
- LDR measures light level
- Temperature sensor measures temperature
- Push button detects a press

### 2. Processing

The microcontroller reads the input and follows the instructions written in the Arduino program.

For example:

```text
If distance is more than 20 cm  ---> Move forward
If distance is 20 cm or less    ---> Stop and turn
```

The Arduino is not making decisions like a human. It simply follows the conditions and instructions written in the program.

### 3. Output

After processing the input, the Arduino controls an output device.

Examples:

- Turn an LED ON or OFF
- Sound a buzzer
- Move a motor
- Rotate a servo
- Show information on a display
- Switch a relay

### 4. Repeat

This cycle keeps repeating very quickly while the Arduino is powered.

```text
Sense ---> Read ---> Decide ---> Act ---> Repeat
```

## How an Arduino Program Works

Arduino programs are commonly written in C/C++ using the Arduino IDE. A basic Arduino program normally contains two important functions:

```cpp
void setup() {
  // Runs once when the Arduino starts
}

void loop() {
  // Runs again and again while the Arduino is powered
}
```

### `setup()`

`setup()` runs only once when the board starts or resets. It is normally used to prepare pins, sensors, displays, communication, and other devices.

### `loop()`

`loop()` runs continuously. This is where the Arduino repeatedly reads sensors, checks conditions, performs calculations, and controls outputs.

## Digital and Analog Signals

Students will meet two main types of signals in Arduino projects.

### Digital Signal

A digital signal normally has two states:

```text
LOW  = 0
HIGH = 1
```

Examples include push buttons, PIR sensors, flame-sensor digital outputs, LEDs, buzzers, and motor-driver control pins.

### Analog Signal

An analog signal can represent many levels instead of only ON and OFF. Arduino Uno analog inputs convert the measured voltage into a numerical reading that the program can use.

Examples include:

- Light intensity from an LDR circuit
- Soil moisture level
- Temperature from an analog temperature sensor
- Gas-sensor analog output

This allows the Arduino to compare a sensor value with a threshold and decide what action to take.

## Example: Obstacle Avoiding Robot

A simple obstacle-avoiding robot demonstrates the complete Arduino process.

```text
Ultrasonic Sensor
       |
       v
Arduino measures distance
       |
       v
Program checks the distance
       |
       +---- Clear path ----> Motors move forward
       |
       +---- Obstacle ------> Stop / reverse / turn
```

In one project, students learn about **distance measurement, conditions, motors, motor drivers, power connections, programming, testing, and mechanical movement**.

## Standard Power Setup

For the projects in this repository:

- Arduino Uno is powered through its USB port using a power bank, or through the DC jack using a suitable 7-12V supply such as a 9V source.
- Sensors, small modules, and low-power components normally receive 5V from the Arduino 5V pin.
- DC motors are not powered from the Arduino.
- Motor drivers use a separate motor battery.
- Arduino GND and motor-driver GND are connected together in robot projects so the control signals have a common reference.
- The motor-battery voltage must match the motors being used. A 12V battery should only be used when the motors are rated for that supply.
- Small servos may be powered from Arduino 5V in beginner projects, but servo current can sometimes cause resets or jitter. A capable USB power source is preferred for servo-based projects.

## Good Practices for Students

- Check the circuit before switching on the power.
- Confirm the voltage required by every sensor and module.
- Never connect a DC motor directly to an Arduino output pin.
- Connect GND correctly when different power sources are used together.
- Test one section of a project at a time instead of connecting everything at once.
- Calibrate sensors when the project depends on light, gas, moisture, distance, sound, or other changing environmental values.
- Read the code and understand what each section is doing before changing pin numbers or thresholds.

## What Students Learn

Arduino projects help students practise:

- Basic electronics and circuit building
- Programming logic
- Input and output systems
- Sensor calibration
- Measurement and data interpretation
- Robotics and automation
- Debugging and troubleshooting
- Computational thinking
- Engineering design
- Problem-solving and experimentation

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
5. [Light Avoiding Robot Using LDR Sensors](./05-Light-Avoiding-Robot-LDR/)
6. [Bluetooth Controlled 4-Wheel Car Using HC-05 Bluetooth Module](./06-Bluetooth-Controlled-4-Wheel-Car-HC05/)
7. [Gesture Controlled Robot Car Using PAJ7620 Gesture Sensor](./07-Gesture-Controlled-Robot-PAJ7620/)
8. [Light Following Robot Using LDR Sensors](./08-Light-Following-Robot-LDR/)
9. [Fire Detection Robot Using Flame Sensor](./09-Fire-Detection-Robot-Flame-Sensor/)
10. [Object Following Robot Using Ultrasonic and IR Sensors](./10-Object-Following-Robot-Ultrasonic-IR/)
11. [Edge Detection Robot Using IR Sensors](./11-Edge-Detection-Robot-IR/)
12. [Digital Measuring Tape Using Ultrasonic Sensor](./12-Digital-Measuring-Tape-Ultrasonic/)
13. [Motion Detector Using PIR Sensor](./13-Motion-Detector-PIR/)
14. [Laser Security Alarm Using LDR Sensor](./14-Laser-Security-Alarm-LDR/)
15. [Door Intrusion Alarm Using Magnetic Reed Switch](./15-Door-Intrusion-Alarm-Reed-Switch/)
16. [Gas Leakage Detector Using MQ-5 Gas Sensor](./16-Gas-Leakage-Detector-MQ5/)
17. [Smoke Detector Using MQ-2 Sensor](./17-Smoke-Detector-MQ2/)
18. [Flame Detector Using Flame Sensor](./18-Flame-Detector-Flame-Sensor/)
19. [Rain Detector Using Rain Sensor](./19-Rain-Detector-Rain-Sensor/)
20. [Water Level Indicator Using Water Level Sensor](./20-Water-Level-Indicator/)
21. [Water Overflow Alarm Using Water Level Sensor](./21-Water-Overflow-Alarm/)
22. [Soil Moisture Monitor Using Capacitive Soil Moisture Sensor](./22-Soil-Moisture-Monitor-Capacitive/)
23. [Temperature Monitor Using LM35 Sensor](./23-Temperature-Monitor-LM35/)
24. [Temperature and Humidity Monitor Using DHT11 Sensor](./24-Temperature-Humidity-Monitor-DHT11/)
25. [Light Intensity Meter Using LDR Sensor](./25-Light-Intensity-Meter-LDR/)
26. [Sound Level Indicator Using Sound Sensor](./26-Sound-Level-Indicator/)
27. [Vibration Detector Using SW-420 Sensor](./27-Vibration-Detector-SW420/)
28. [Tilt Detection Alarm Using Tilt Sensor](./28-Tilt-Detection-Alarm/)
29. [Automatic Room Light Using PIR Sensor](./29-Automatic-Room-Light-PIR/)
30. [Automatic Door Opening System Using Ultrasonic Sensor](./30-Automatic-Door-Ultrasonic/)
31. [Touchless Automatic Dustbin Using Ultrasonic Sensor](./31-Touchless-Automatic-Dustbin-Ultrasonic/)
32. [Automatic Hand Sanitizer Dispenser Using Ultrasonic Sensor](./32-Automatic-Hand-Sanitizer-Ultrasonic/)
33. [Automatic Exhaust Fan Using MQ-2 Sensor](./33-Automatic-Exhaust-Fan-MQ2/)
34. [Temperature Controlled Fan Using LM35 Sensor](./34-Temperature-Controlled-Fan-LM35/)
35. [Clap Controlled Light Using Sound Sensor](./35-Clap-Controlled-Light-Sound-Sensor/)
36. [RFID Door Lock Using RDM6300 RFID Reader](./36-RFID-Door-Lock-RDM6300/)
37. [Visitor Counter Using IR Sensors](./37-Visitor-Counter-IR-Sensors/)
38. [Soil Moisture Based Irrigation Using Capacitive Soil Moisture Sensor](./38-Soil-Moisture-Irrigation/)
39. [Rainwater Tank Level Monitor Using Ultrasonic Sensor](./39-Rainwater-Tank-Level-Ultrasonic/)
40. [Greenhouse Temperature Monitor Using DHT11 Sensor](./40-Greenhouse-Temperature-Monitor-DHT11/)
41. [Automatic Greenhouse Fan Using DHT11 Sensor](./41-Automatic-Greenhouse-Fan-DHT11/)
42. [Water Quality Monitoring Prototype Using TDS Sensor](./42-Water-Quality-TDS-Prototype/)
43. [Air Quality Monitoring System Using MQ-135 Sensor](./43-Air-Quality-Monitor-MQ135/)
44. [Digital Dice Using LEDs](./44-Digital-Dice-LEDs/)
45. [Electronic Reaction Time Game Using LED and Push Button](./45-Electronic-Reaction-Time-Game/)
46. [Arduino Traffic Light Simulator Using LEDs](./46-Arduino-Traffic-Light-Simulator/)
47. [Countdown Timer Using TM1637 Display](./47-Countdown-Timer-TM1637/)
48. [Digital Stopwatch Using TM1637 Display](./48-Digital-Stopwatch-TM1637/)
49. [Quiz Buzzer System Using Push Buttons and LEDs](./49-Quiz-Buzzer-System/)
