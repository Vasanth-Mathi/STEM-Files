# ESP32 Blynk IoT Home Security and Motion Alert System

## Description
Combines a PIR motion sensor and magnetic reed switch with Blynk arming control, local buzzer output, and intrusion notifications.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| PIR Motion Sensor | 1 |
| Magnetic Reed Switch | 1 |
| Active Buzzer | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 5V / VIN or sensor-rated supply | PIR VCC |
| GND | PIR GND and buzzer GND |
| GPIO 27 | PIR OUT |
| GPIO 33 | Reed switch to GND using INPUT_PULLUP |
| GPIO 23 | Buzzer signal |

## Code
See [`blynk_home_security_alert.ino`](./blynk_home_security_alert.ino).

## Working Principle
1. Blynk virtual pin V0 arms or disarms the system.
2. The ESP32 monitors motion and door state.
3. V1 and V2 show motion and door status.
4. When armed, an intrusion activates the buzzer and logs the Blynk event `security_alert`.

## Use Cases
- Security-system prototypes
- PIR and reed-switch lessons
- Blynk event alerts
- Remote arming demonstrations
