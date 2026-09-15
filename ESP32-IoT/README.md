# ESP32 & IoT Projects

## What is ESP32?

ESP32 is a microcontroller platform that can read sensors, process information, control electronic devices, and communicate wirelessly. It is especially useful for connected STEM projects because Wi-Fi and Bluetooth are built into the chip.

A simple way to think about ESP32 is:

> **Sense something → Process it → Communicate it → Take action**

For example, an ESP32 can read temperature from a sensor, send the value to a mobile dashboard through Wi-Fi, and switch on a fan when the temperature becomes high.

ESP32 projects help students learn electronics, coding, wireless communication, automation, networking, data monitoring, and IoT system design.

## Main Parts and Features of an ESP32 Development Board

| Part / Feature | What It Does |
|---|---|
| ESP32 microcontroller | Runs the program and processes data |
| GPIO pins | Connect sensors, LEDs, relays, motor drivers, displays, and other devices |
| Analog inputs | Read changing voltage levels from compatible analog sensors |
| Wi-Fi | Connects to routers, local web pages, Internet services, and IoT platforms |
| Bluetooth Classic | Supports simple wireless control and serial-style communication |
| BLE | Provides Bluetooth Low Energy communication |
| ESP-NOW | Allows direct ESP32-to-ESP32 communication without a normal router |
| USB port | Used for programming and usually board power |
| 3.3V pin | Powers compatible low-voltage sensors and modules |
| GND pins | Provide the common electrical reference |
| Reset / EN button | Restarts the ESP32 |

> ESP32 GPIO pins normally use **3.3V logic**. Do not apply a 5V signal directly to a GPIO pin unless the circuit safely converts the voltage.

## How ESP32 Works

At the basic electronics level, ESP32 follows an **Input → Process → Output** cycle.

```text
Sensor / Input ---> ESP32 ---> Program Logic ---> Output Device
```

ESP32 can also add wireless communication:

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

Sensors and input devices collect information.

Examples include:

- DHT11 for temperature and humidity
- Ultrasonic sensor for distance
- PIR sensor for movement
- Soil-moisture sensor
- MQ gas sensor
- Push button
- Joystick
- IMU motion sensor

### 2. Processing

The ESP32 reads the input and follows the instructions written in the program.

```text
If soil is dry ---> Pump ON
If soil is wet ---> Pump OFF
```

### 3. Communication

ESP32 can send or receive information using several wireless methods.

| Method | Typical Use |
|---|---|
| Wi-Fi | Web servers, Internet access, IoT dashboards, cloud communication |
| Bluetooth Classic | Phone control and serial-style links |
| BLE | Low-power phone/device communication |
| ESP-NOW | Direct ESP32-to-ESP32 links, remotes, sensor networks |

### 4. Output

The ESP32 can control:

- LEDs
- Buzzers
- Relays
- Motors through motor drivers
- Water pumps through suitable drivers
- Displays
- Fans
- Servos

### 5. Repeat

```text
Sense ---> Process ---> Communicate ---> Act ---> Repeat
```

## What is IoT?

**IoT** means **Internet of Things**. It describes physical devices that collect information, communicate through a network, and can often be monitored or controlled remotely.

```text
Temperature Sensor ---> ESP32 ---> Wi-Fi ---> IoT Platform ---> Mobile Dashboard
```

A typical IoT system contains:

1. A sensor
2. A microcontroller such as ESP32
3. A communication network
4. A server or IoT platform
5. A dashboard or app
6. An actuator when automatic action is required

## ESP32-to-ESP32 Projects

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
- Correct virtual-pin datastreams

Do not publish real Wi-Fi passwords or private Blynk tokens in a public repository.

## Power and Hardware Rules

- ESP32 GPIO is 3.3V logic.
- Motors, pumps, and other high-current loads must not be powered directly from GPIO pins.
- Use a suitable motor driver, MOSFET, transistor, or relay when required.
- High-current loads should use a separate supply matched to the load.
- Grounds must normally be connected together when two powered circuits exchange electrical signals.
- Use ADC1 pins for analog measurements when Wi-Fi operation could interfere with ADC2 on classic ESP32 boards.
- Check every module's voltage requirement before wiring.

## Common Use Cases

- Smart home automation
- Wireless sensor monitoring
- Smart agriculture
- Weather monitoring
- IoT dashboards
- Bluetooth-controlled robots
- ESP32-to-ESP32 communication
- Wireless classroom systems
- Security and alert systems
- Energy monitoring
- Data logging
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
31. [ESP32 ESP-NOW Remote Controlled Brushed-Motor Quadcopter](./31-ESP-NOW-Remote-Controlled-Brushed-Quadcopter/)

<!-- Add only project titles here whenever new project folders are created. -->
