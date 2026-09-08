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
