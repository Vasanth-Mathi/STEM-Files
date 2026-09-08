# Water Quality Monitoring Prototype Using TDS Sensor

## Description
A water-quality learning prototype that uses an analog TDS sensor to estimate Total Dissolved Solids in water. Arduino reads the sensor voltage and displays an approximate TDS value in ppm on an LCD.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Analog TDS Sensor Module with Probe | 1 |
| 16x2 I2C LCD | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | TDS Sensor Module VCC and I2C LCD VCC |
| GND | TDS Sensor Module GND and I2C LCD GND |
| A0 | TDS Sensor Module Analog Output |
| A4 | I2C LCD SDA |
| A5 | I2C LCD SCL |

> This is an educational prototype. Do not use its reading alone to decide whether water is safe to drink.

> Keep the TDS signal board dry; only the probe is intended to contact water.

## Code
See [`water_quality_tds_monitor.ino`](./water_quality_tds_monitor.ino).

This sketch requires a **LiquidCrystal_I2C** library.

## Working Principle
1. The TDS probe and signal board produce an analog voltage related to dissolved solids in the water.
2. Arduino averages several analog readings to reduce noise.
3. The average voltage is converted to an approximate TDS value using a common calibration equation at 25 °C.
4. The estimated value is displayed in ppm on the LCD.
5. For accurate measurements, the sensor must be calibrated and temperature compensation should be added.

## Use Cases
- Water-quality demonstrations
- Hydroponics lessons
- Environmental monitoring
- Sensor calibration activities
