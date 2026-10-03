# Sensors

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Sensors convert a physical condition such as distance, light, motion, moisture, gas, temperature, or identification data into an electrical signal a controller can read.

| No. | Sensor | How It Works | Basic Connection | Example Use |
|---:|---|---|---|---|
| 6 | Ultrasonic Sensor | Measures distance by sending sound pulses and timing the returning echo. | Trigger to a digital output, Echo to a digital input, plus suitable power and GND. | Obstacle detection |
| 7 | IR Proximity Sensor | Detects nearby objects using infrared light and a detector circuit. | Connect the module output to a compatible digital or analog input, plus power and GND. | Robot navigation |
| 8 | LDR | Changes resistance as light level changes. | Use it with a known resistor as a voltage divider and read the divider using an analog input. | Automatic street light |
| 9 | PIR Motion Sensor | Detects changes in infrared energy caused by moving warm objects. | Output to a digital input, plus power and GND. | Security system |
| 10 | Color Recognition Sensor | Produces signals related to detected colour. | Connect the sensor's output/interface pins to corresponding controller inputs and provide power/GND. | Sorting objects by colour |
| 11 | MQ2 Smoke Sensor | Produces an electrical response to smoke and several gases. | Connect analog output to an analog input, plus suitable power and GND. | Fire/smoke alarm prototype |
| 12 | Soil Moisture Sensor | Produces a signal related to moisture in soil. | Connect analog output to an analog input, plus suitable power and GND. | Automatic plant watering |
| 13 | DHT11 Humidity Sensor | Digitally reports humidity and temperature data. | Connect data/output to a suitable digital pin, plus power and GND. | Environmental monitoring |
| 14 | pH Sensor | Produces an analog signal related to acidity/alkalinity when used with its interface circuitry. | Connect module output to an analog input, plus suitable power and GND. | Water-quality monitoring |
| 15 | RFID Reader with Tags | Reads identification data stored in compatible RFID tags. | Connect using the reader's required interface such as SPI or UART, plus correct power/GND. | Access control and inventory |
| 16 | Pulse Rate Heart Sensor | Detects pulse-related changes and produces a signal that can be measured. | Connect sensor output to an analog input, plus suitable power and GND. | Heart-rate learning prototype |
| 17 | TSOP1738 IR Receiver | Detects modulated infrared signals commonly sent by remote controls. | Output to a digital input, plus correct power/GND. | IR remote control |
| 18 | Thermistor | Changes resistance as temperature changes. | Form a voltage divider with a known resistor and read the divider using an analog input. | Temperature-controlled fan |
| 19 | Rain Drop Sensor | Changes its output when water is present on the sensing plate. | Reference uses the analog output connected to an analog input, plus power/GND. | Rain/water detection |

## Sensor Learning Pattern

```text
Physical Change ---> Sensor ---> Electrical Signal ---> Controller Reading ---> Decision
```

## Important
Sensor values often need calibration. Do not copy a threshold from another setup and assume it will match your sensor.
