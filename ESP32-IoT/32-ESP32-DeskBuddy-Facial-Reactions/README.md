# ESP32 DeskBuddy - Facial Reactions

## Description

DeskBuddy is an interactive desk companion built with an ESP32, a 128x64 OLED display, two servo motors, a TTP223 touch sensor, and a push button. The display shows six facial expressions while the servos move the side-mounted ears. Touching the sensor triggers a LOVE expression and a short ear wiggle before the previous mood returns.

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 1 |
| SSD1306 128x64 I2C OLED | 1 |
| SG90 micro servo | 2 |
| TTP223 capacitive touch sensor | 1 |
| Momentary push button | 1 |
| Regulated 5V servo power supply | 1 |
| Jumper wires and breadboard | As required |

## Circuit Connections

### OLED Display

| OLED Pin | ESP32 Connection |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

The sketch uses I2C address `0x3C`. If your module uses `0x3D`, update `OLED_ADDR` in the sketch.

### Servo Ears

| Connection | Pin / Supply |
|---|---|
| Left servo signal | GPIO 18 |
| Right servo signal | GPIO 19 |
| Both servo VCC wires | External regulated 5V |
| Both servo GND wires | External supply GND |
| Common ground | External supply GND connected to ESP32 GND |

**Power warning:** Do not power the servos from the ESP32 3.3V pin. Use a suitable regulated 5V supply with enough current for both servos and connect all grounds together.

### Touch Sensor and Button

| Component Pin | ESP32 Connection |
|---|---|
| TTP223 VCC | 3V3 |
| TTP223 GND | GND |
| TTP223 OUT | GPIO 5 |
| Push button terminal 1 | GPIO 4 |
| Push button terminal 2 | GND |

The button uses the internal pull-up resistor. The sketch expects the TTP223 output to go HIGH when touched.

## Code

- **Main Sketch:** [`deskbuddy_facial_reactions.ino`](./deskbuddy_facial_reactions.ino)

## Facial Reactions

| Mood | OLED Expression | Ear Behaviour |
|---|---|---|
| Happy | Smiling face | Friendly raised pose |
| Sad | Drooping eyes and frown | Lowered pose |
| Angry | Angled eyebrows and frown | Grumpy pose |
| Surprised | Wide eyes and open mouth | Alert pose |
| Sleepy | Closed eyes and Z marks | Relaxed pose |
| Love | Heart-shaped eyes and smile | Friendly pose |

Servo angles are starting values. Actual ear direction depends on servo orientation and mechanical linkage, so adjust the `earAngles` table after testing.

## Working Principle

1. The ESP32 initializes the OLED, touch sensor, button, and servos.
2. The display starts with the happy expression.
3. The program blinks periodically and changes mood approximately every 10 seconds.
4. Pressing the button cycles through the six moods.
5. Touching the TTP223 sensor displays LOVE and wiggles both ears.
6. After about 1.5 seconds, the previous mood returns.
7. Servo movement is smoothed by changing target angles in small steps.

## Before Uploading

1. Install the ESP32 board package by Espressif Systems in Arduino IDE.
2. Install **Adafruit GFX Library**, **Adafruit SSD1306**, and **ESP32Servo** using Library Manager.
3. Select the correct ESP32 board and serial port.
4. Check OLED wiring and I2C address.
5. Test servo movement before attaching the ears firmly. Keep linkages clear of the case and mechanical limits.
6. Use an external regulated 5V servo supply with common ground.
7. Upload the sketch and open Serial Monitor at 115200 baud.

## Troubleshooting

- **OLED blank:** Check SDA/SCL, power, ground, and I2C address.
- **Touch does not trigger:** Check TTP223 wiring and confirm OUT goes HIGH when touched.
- **ESP32 restarts when servos move:** Check the external supply current capacity and common ground.
- **Ears move in the wrong direction:** Adjust the `earAngles` values to match your mounting.
- **Servo buzzes or binds:** Disconnect power and reduce the angle range or adjust the linkage.

## Software Requirements

- Arduino IDE
- ESP32 board package by Espressif Systems
- Adafruit GFX Library
- Adafruit SSD1306
- ESP32Servo

## Use Cases

- Interactive desk companion
- OLED facial animation
- Beginner ESP32 input/output project
- Learning servo control and event-driven behaviour
