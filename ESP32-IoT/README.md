# ESP32 & IoT Projects

## What is ESP32?

ESP32 is a powerful microcontroller platform designed for connected electronics projects. Like Arduino, it can read sensors, process information, and control devices. What makes ESP32 especially useful is that it also includes **built-in Wi-Fi and Bluetooth**, allowing projects to communicate wirelessly with phones, computers, other ESP32 boards, local networks, and Internet of Things (IoT) platforms.

A simple way to think about ESP32 is:

> **Sense something → Process it → Communicate it → Take action**

For example, an ESP32 can read the temperature from a sensor, send the value to a mobile dashboard through Wi-Fi, and automatically switch on a fan when the temperature becomes high.

Because of these features, ESP32 is useful for learning **electronics, coding, wireless communication, automation, networking, data monitoring, and IoT systems**.

## Main Parts and Features of an ESP32 Development Board

Different ESP32 development boards may look slightly different, but they usually provide the following important features.

| Part / Feature | What It Does |
|---|---|
| ESP32 Microcontroller | Runs the program and processes sensor data |
| GPIO Pins | Connect sensors, LEDs, relays, displays, motor drivers, and other devices |
| Analog Inputs | Read changing voltage levels from compatible analog sensors |
| Wi-Fi | Connects the ESP32 to routers, local networks, web servers, and Internet services |
| Bluetooth | Allows wireless communication with compatible phones and other devices |
| BLE | Provides Bluetooth Low Energy communication for low-power wireless applications |
| USB Port | Used for programming and usually for powering the development board |
| 3.3V Pin | Provides 3.3V for compatible sensors and modules |
| 5V / VIN Pin | Available on many development boards for suitable board or module connections |
| GND Pins | Provide the common electrical ground connection |
| Reset / EN Button | Restarts the ESP32 program |

> **Important:** ESP32 GPIO pins normally use **3.3V logic**. A 5V signal should not be connected directly to an ESP32 GPIO pin unless the specific board or circuit safely converts the voltage.

## How ESP32 Works

At the basic electronics level, ESP32 works using the same **Input → Process → Output** idea used in Arduino projects.

```text
Sensor / Input ---> ESP32 ---> Program Logic ---> Output Device
```

But ESP32 can also add wireless communication:

```text
Sensor
   |
   v
 ESP32 ---> Wi-Fi / Bluetooth / ESP-NOW ---> Phone / ESP32 / Network / Cloud
   |
   v
Output Device
```

### 1. Input

Sensors and input devices collect information from the environment.

Examples:

- DHT11 measures temperature and humidity
- Ultrasonic sensor measures distance
- PIR sensor detects movement
- Soil-moisture sensor measures moisture level
- MQ sensor responds to certain gases or smoke
- Push button gives a user command

### 2. Processing

The ESP32 program reads the input and decides what to do.

For example:

```text
If soil is dry     ---> Turn pump ON
If soil is wet     ---> Turn pump OFF
```

The program can also prepare the data for wireless transmission.

### 3. Communication

The ESP32 can send or receive information using several wireless methods.

| Communication Method | Simple Use |
|---|---|
| Wi-Fi | Web servers, Internet access, IoT dashboards, cloud communication |
| Bluetooth Classic | Simple phone-to-ESP32 control and serial-style communication |
| BLE | Low-power wireless data exchange with phones and BLE devices |
| ESP-NOW | Direct ESP32-to-ESP32 communication without a normal Wi-Fi router |

### 4. Output or Action

After processing information, the ESP32 can control devices such as:

- LEDs
- Buzzers
- Relays
- Motors through motor drivers
- Water pumps through suitable drivers or relays
- Displays
- Fans
- Servos

### 5. Repeat

The ESP32 continuously repeats this cycle while powered.

```text
Sense ---> Process ---> Communicate ---> Act ---> Repeat
```

## What is IoT?

**IoT** stands for **Internet of Things**. It describes physical devices that can collect data, communicate through a network, and sometimes be monitored or controlled remotely.

A normal electronic project may work only on the device itself. An IoT project can make that information available somewhere else.

For example:

```text
Temperature Sensor ---> ESP32 ---> Wi-Fi ---> IoT Platform ---> Mobile Dashboard
```

A student can then view the temperature on a phone instead of standing next to the sensor.

An IoT system may contain:

1. **Sensor** - collects information.
2. **ESP32** - processes the information.
3. **Network** - carries the information.
4. **IoT platform or server** - stores or manages the data.
5. **Dashboard or app** - shows information to the user.
6. **Actuator** - performs an action when required.

## How Data Moves in an IoT Project

Consider a smart plant-watering system.

```text
Soil Moisture Sensor
        |
        v
      ESP32
        |
        +----> Blynk IoT Dashboard ---> Student sees moisture level
        |
        +----> Program checks moisture
                         |
                         +---- Dry ---> Pump ON
                         |
                         +---- Wet ---> Pump OFF
```

This project combines **sensing, decision-making, wireless communication, monitoring, and automation**.

## ESP32 Wi-Fi Projects

Wi-Fi allows the ESP32 to communicate through a wireless network.

The ESP32 can work in different ways depending on the project:

- Connect to an existing Wi-Fi router and join the local network.
- Create its own Wi-Fi access point for nearby devices to connect directly.
- Host a simple web page that controls LEDs, relays, or other devices.
- Connect to Internet services such as time servers or IoT platforms.

Example:

```text
Phone / Computer ---> Wi-Fi Router ---> ESP32 ---> LED
```

or, when the ESP32 creates its own access point:

```text
Phone ---> ESP32 Wi-Fi Access Point ---> Local Control Page
```

## ESP32 Bluetooth and BLE Projects

Bluetooth allows nearby devices to communicate without using an Internet connection.

Bluetooth Classic is useful for simple remote controls and serial-style communication.

BLE is designed for lower-power applications and uses services and characteristics to exchange data.

Examples include:

- Phone-controlled robot
- Wireless sensor monitor
- BLE proximity experiment
- Nearby-device control

## Multi-ESP32 Projects

Some projects in this folder require **more than one ESP32 board**.

For those projects, the code is intentionally separated by board role. Do not upload one mode-switching sketch and expect students to guess which half belongs where.

Typical file names are:

```text
sender.ino
receiver.ino
```

or:

```text
esp32_1.ino
esp32_2.ino
```

or role-based names such as:

```text
remote_sender.ino
robot_receiver.ino
```

Each multi-board README also contains separate connection tables for each ESP32.

## How ESP-NOW Works

ESP-NOW allows ESP32 boards to exchange small packets directly using the Wi-Fi radio without joining a normal Wi-Fi network.

```text
ESP32 Sender ~~~ ESP-NOW ~~~> ESP32 Receiver
```

It can be used for:

- One-to-one communication
- Two-way communication
- One-to-many control
- Many-to-one sensor networks
- Remote controls
- Wireless classroom systems

All communicating ESP-NOW boards must use the same Wi-Fi channel.

## ESP-NOW and Wi-Fi Together

An ESP32 can use normal Wi-Fi and ESP-NOW in the same project, but both must operate on the same radio channel.

This is used in the Blynk gateway project:

```text
Sensor ESP32 ---> ESP-NOW ---> Gateway ESP32 ---> Wi-Fi ---> Blynk
```

## Blynk IoT

Blynk allows an ESP32 to send data to dashboards and receive remote-control commands.

A Blynk project normally needs:

- Blynk Template ID
- Template Name
- Auth Token
- Wi-Fi name
- Wi-Fi password
- Datastream or virtual-pin configuration

These values should be replaced by the student before uploading the project.

## ESP32 Power and Voltage Rules

- ESP32 GPIO pins use 3.3V logic.
- Do not connect 5V sensor outputs directly to ESP32 GPIO pins unless a suitable level shifter or voltage divider is used.
- Motors, pumps, and fans should not be powered directly from ESP32 GPIO pins.
- High-current loads need a suitable motor driver, MOSFET, relay, or other driver circuit.
- When separate supplies are used in the same control circuit, connect grounds together where required by the circuit.
- Always match the supply voltage and current capability to the actual module or motor being used.

## What Students Learn

These projects help students learn:

- Embedded programming
- Sensor interfacing
- Wireless communication
- Wi-Fi networking
- Bluetooth and BLE
- ESP-NOW communication
- IoT dashboards
- Cloud-connected devices
- Automation
- Remote-control robotics
- Feedback-control experiments

## Projects

1. [ESP32 Wi-Fi LED Control Using Web Server](./01-WiFi-LED-Web-Server/)
2. [ESP32 Wi-Fi Access Point with Local Control Page](./02-WiFi-Access-Point-Local-Control/)
3. [ESP32 Wi-Fi Network Scanner](./03-WiFi-Network-Scanner/)
4. [ESP32 Wi-Fi Weather Dashboard Using DHT11 and BMP280](./04-WiFi-Weather-Dashboard/)
5. [ESP32 Internet Clock Using Wi-Fi, NTP and OLED Display](./05-WiFi-Internet-Clock-NTP/)
6. [ESP32 Wi-Fi Data Logger Using DHT11 and SD Card](./06-WiFi-Data-Logger-SD-Card/)
7. [ESP32 Bluetooth Controlled 4-Wheel Robot Car](./07-Bluetooth-4-Wheel-Robot-Car/)
8. [ESP32 Bluetooth Home Appliance Controller](./08-Bluetooth-Home-Appliance-Controller/)
9. [ESP32 BLE Proximity Detection System](./09-BLE-Proximity-Detector/)
10. [ESP32 BLE Wireless Temperature and Humidity Monitor Using DHT11](./10-BLE-Wireless-Sensor-Monitor/)
11. [ESP32 One-Way Sensor Communication Using ESP-NOW](./11-ESP-NOW-One-Way-Sensor-Communication/)
12. [ESP32 Two-Way Communication Using ESP-NOW](./12-ESP-NOW-Two-Way-Communication/)
13. [ESP32 One-to-Many Wireless Control Using ESP-NOW](./13-ESP-NOW-One-To-Many-Wireless-Control/)
14. [ESP32 Many-to-One Wireless Sensor Network Using ESP-NOW](./14-ESP-NOW-Many-To-One-Sensor-Network/)
15. [ESP32 Wireless Doorbell Using ESP-NOW](./15-ESP-NOW-Wireless-Doorbell/)
16. [ESP32 Wireless Robot Remote Controller Using ESP-NOW](./16-ESP-NOW-Wireless-Robot-Controller/)
17. [ESP32 Wireless Classroom Quiz Buzzer Using ESP-NOW](./17-ESP-NOW-Wireless-Quiz-Buzzer/)
18. [ESP32 Blynk IoT Automatic Plant Watering System](./18-Blynk-Automatic-Plant-Watering/)
19. [ESP32 Blynk IoT Water Tank Level Monitoring System](./19-Blynk-Water-Tank-Level-Monitor/)
20. [ESP32 Blynk IoT Smart Home Control System](./20-Blynk-Smart-Home-Control/)
21. [ESP32 Blynk IoT Greenhouse Automation System Using DHT11](./21-Blynk-Greenhouse-Automation/)
22. [ESP32 Blynk IoT Air Quality Monitoring and Alert System Using MQ135](./22-Blynk-Air-Quality-Monitor-MQ135/)
23. [ESP32 Blynk IoT Gas Leakage Alert System Using MQ5](./23-Blynk-Gas-Leakage-Alert-MQ5/)
24. [ESP32 Blynk IoT DC Energy Monitoring Prototype Using INA219](./24-Blynk-DC-Energy-Monitor-INA219/)
25. [ESP32 Blynk IoT Home Security and Motion Alert System](./25-Blynk-Home-Security-Motion-Alert/)
26. [ESP32 Blynk IoT Smart Parking Monitoring System](./26-Blynk-Smart-Parking-Monitor/)
27. [ESP32 Blynk IoT Classroom Environment Monitoring System](./27-Blynk-Classroom-Environment-Monitor/)
28. [ESP32 Blynk IoT Water Quality Monitoring Prototype Using TDS Sensor](./28-Blynk-Water-Quality-TDS-Monitor/)
29. [ESP32 Multi-Sensor Smart Agriculture System Using Blynk IoT](./29-Blynk-Smart-Agriculture-System/)
30. [ESP32 ESP-NOW Sensor Network with Blynk IoT Gateway](./30-ESP-NOW-Sensor-Network-Blynk-Gateway/)
31. [ESP32 ESP-NOW Remote Controlled Drone - Quadcopter](./31-ESP-NOW-Remote-Controlled%20Drone%20-Quadcopter/)

<!-- Add only project titles here whenever new project folders are created. -->