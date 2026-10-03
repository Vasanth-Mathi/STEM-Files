# Microcontroller Boards

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Microcontroller boards are the programmable control centre of a physical-computing system. They read inputs, run the program, and control outputs.

| No. | Component | How It Works | Basic Connection | Example Use |
|---:|---|---|---|---|
| 1 | Arduino UNO | Runs an uploaded program and uses its input/output pins to read sensors and control devices. | Connect USB to a computer for programming. For standalone use, the reference recommends an external supply through the DC jack or VIN with GND. | General programming and electronics projects |
| 2 | Node MCU | A programmable controller with built-in Wi-Fi, allowing sensor data and control information to move through a network. | Connect USB for programming. For standalone operation, the reference uses VIN and GND for power. | IoT weather station with online data logging |

## Student Connection Idea

```text
Sensor / Input ---> Microcontroller Board ---> Program ---> Output / Network
```

## Before Connecting
- Identify the exact board version.
- Check its operating voltage and pin labels.
- Connect GND correctly.
- Do not power motors directly from controller pins.
