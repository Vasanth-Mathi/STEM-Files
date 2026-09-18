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

Projects are arranged from **simple beginner circuits with very few components** to **more advanced automation and robotics projects**.

<!-- Keep this list updated whenever a new project folder is added. -->

1. [Push Button Controlled LED](./01-Push-Button-Controlled-LED/)
2. [Potentiometer Controlled LED Brightness](./02-Potentiometer-LED-Brightness/)
3. [IR Obstacle Indicator Using LED](./03-IR-Obstacle-Indicator-LED/)
4. [IR Obstacle Alarm Using Buzzer](./04-IR-Obstacle-Alarm-Buzzer/)
5. [PIR Motion Indicator Using LED](./05-PIR-Motion-Indicator-LED/)
6. [Rain Alert Using Buzzer](./06-Rain-Alert-Buzzer/)
7. [Soil Moisture Dryness Indicator Using LED](./07-Soil-Moisture-Dryness-LED/)
8. [High Temperature Alarm Using LM35 and Buzzer](./08-LM35-High-Temperature-Alarm/)
9. [Ultrasonic Proximity Indicator Using LED](./09-Ultrasonic-Proximity-Indicator-LED/)
10. [Ultrasonic Distance Alarm Using Buzzer](./10-Ultrasonic-Distance-Alarm-Buzzer/)
11. [Automatic Streetlight Using LDR Sensor](./11-Automatic-Streetlight-LDR/)
12. [Motion Detector Using PIR Sensor](./12-Motion-Detector-PIR/)
13. [Door Intrusion Alarm Using Magnetic Reed Switch](./13-Door-Intrusion-Alarm-Reed-Switch/)
14. [Laser Security Alarm Using LDR Sensor](./14-Laser-Security-Alarm-LDR/)
15. [Flame Detector Using Flame Sensor](./15-Flame-Detector-Flame-Sensor/)
16. [Rain Detector Using Rain Sensor](./16-Rain-Detector-Rain-Sensor/)
17. [Water Overflow Alarm Using Water Level Sensor](./17-Water-Overflow-Alarm/)
18. [Light Intensity Meter Using LDR Sensor](./18-Light-Intensity-Meter-LDR/)
19. [Vibration Detector Using SW-420 Sensor](./19-Vibration-Detector-SW420/)
20. [Tilt Detection Alarm Using Tilt Sensor](./20-Tilt-Detection-Alarm/)
21. [Clap Controlled Light Using Sound Sensor](./21-Clap-Controlled-Light-Sound-Sensor/)
22. [Automatic Room Light Using PIR Sensor](./22-Automatic-Room-Light-PIR/)
23. [Soil Moisture Monitor Using Capacitive Soil Moisture Sensor](./23-Soil-Moisture-Monitor-Capacitive/)
24. [Temperature Monitor Using LM35 Sensor](./24-Temperature-Monitor-LM35/)
25. [Temperature and Humidity Monitor Using DHT11 Sensor](./25-Temperature-Humidity-Monitor-DHT11/)
26. [Sound Level Indicator Using Sound Sensor](./26-Sound-Level-Indicator/)
27. [Gas Leakage Detector Using MQ-5 Gas Sensor](./27-Gas-Leakage-Detector-MQ5/)
28. [Smoke Detector Using MQ-2 Sensor](./28-Smoke-Detector-MQ2/)
29. [Air Quality Monitoring System Using MQ-135 Sensor](./29-Air-Quality-Monitor-MQ135/)
30. [Water Level Indicator Using Water Level Sensor](./30-Water-Level-Indicator/)
31. [Arduino Traffic Light Simulator Using LEDs](./31-Arduino-Traffic-Light-Simulator/)
32. [Digital Dice Using LEDs](./32-Digital-Dice-LEDs/)
33. [Electronic Reaction Time Game Using LED and Push Button](./33-Electronic-Reaction-Time-Game/)
34. [Quiz Buzzer System Using Push Buttons and LEDs](./34-Quiz-Buzzer-System/)
35. [Digital Measuring Tape Using Ultrasonic Sensor](./35-Digital-Measuring-Tape-Ultrasonic/)
36. [Visitor Counter Using IR Sensors](./36-Visitor-Counter-IR-Sensors/)
37. [Countdown Timer Using TM1637 Display](./37-Countdown-Timer-TM1637/)
38. [Digital Stopwatch Using TM1637 Display](./38-Digital-Stopwatch-TM1637/)
39. [Automatic Door Opening System Using Ultrasonic Sensor](./39-Automatic-Door-Ultrasonic/)
40. [Touchless Automatic Dustbin Using Ultrasonic Sensor](./40-Touchless-Automatic-Dustbin-Ultrasonic/)
41. [Automatic Hand Sanitizer Dispenser Using Ultrasonic Sensor](./41-Automatic-Hand-Sanitizer-Ultrasonic/)
42. [RFID Door Lock Using RDM6300 RFID Reader](./42-RFID-Door-Lock-RDM6300/)
43. [Temperature Controlled Fan Using LM35 Sensor](./43-Temperature-Controlled-Fan-LM35/)
44. [Automatic Exhaust Fan Using MQ-2 Sensor](./44-Automatic-Exhaust-Fan-MQ2/)
45. [Greenhouse Temperature Monitor Using DHT11 Sensor](./45-Greenhouse-Temperature-Monitor-DHT11/)
46. [Automatic Greenhouse Fan Using DHT11 Sensor](./46-Automatic-Greenhouse-Fan-DHT11/)
47. [Soil Moisture Based Irrigation Using Capacitive Soil Moisture Sensor](./47-Soil-Moisture-Irrigation/)
48. [Rainwater Tank Level Monitor Using Ultrasonic Sensor](./48-Rainwater-Tank-Level-Ultrasonic/)
49. [Water Quality Monitoring Prototype Using TDS Sensor](./49-Water-Quality-TDS-Prototype/)
50. [Line Follower Robot Using IR Sensors](./50-Line-Follower-IR/)
51. [Edge Detection Robot Using IR Sensors](./51-Edge-Detection-Robot-IR/)
52. [Light Following Robot Using LDR Sensors](./52-Light-Following-Robot-LDR/)
53. [Light Avoiding Robot Using LDR Sensors](./53-Light-Avoiding-Robot-LDR/)
54. [Obstacle Avoiding Robot Using Ultrasonic Sensor](./54-Obstacle-Detector-Ultrasonic/)
55. [Obstacle Avoiding Robot Using Ultrasonic Sensor and Servo Motor](./55-Obstacle-Avoider-Servo-Scan/)
56. [Bluetooth Controlled 4-Wheel Car Using HC-05 Bluetooth Module](./56-Bluetooth-Controlled-4-Wheel-Car-HC05/)
57. [Gesture Controlled Robot Car Using PAJ7620 Gesture Sensor](./57-Gesture-Controlled-Robot-PAJ7620/)
58. [Fire Detection Robot Using Flame Sensor](./58-Fire-Detection-Robot-Flame-Sensor/)
59. [Object Following Robot Using Ultrasonic and IR Sensors](./59-Object-Following-Robot-Ultrasonic-IR/)
