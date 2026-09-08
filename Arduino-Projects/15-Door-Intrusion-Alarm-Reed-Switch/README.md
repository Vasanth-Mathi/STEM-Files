# Door Intrusion Alarm Using Magnetic Reed Switch

## Description
A door alarm that uses a magnetic reed switch to detect whether a door is open or closed. When the magnet moves away and the switch opens, Arduino activates an LED and buzzer.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Magnetic Reed Switch | 1 |
| Magnet | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| GND | One wire of Reed Switch, LED cathode (-) and Buzzer Module GND |
| 5V | Buzzer Module VCC |
| D2 | Other wire of Reed Switch |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

## Code
See [`door_intrusion_alarm.ino`](./door_intrusion_alarm.ino).

## Working Principle
1. The reed switch is mounted on the door frame and the magnet is mounted on the door.
2. When the door is closed, the magnet keeps the reed switch closed.
3. Arduino uses its internal pull-up resistor on D2.
4. When the door opens, the reed switch opens and D2 becomes HIGH.
5. Arduino turns ON the LED and buzzer.

## Use Cases
- Door intrusion alarms
- Window alarms
- Magnetic sensor lessons
- Security-system prototypes
