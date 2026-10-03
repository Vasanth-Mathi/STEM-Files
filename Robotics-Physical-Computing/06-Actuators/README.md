# Actuators and Motors

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Actuators turn electrical commands into physical movement.

| No. | Actuator | How It Works | Basic Connection | Example Use |
|---:|---|---|---|---|
| 35 | L298P Motor Driver | Uses control inputs to switch motor current and control motor direction. | Controller digital outputs go to driver inputs; motors connect to driver outputs; supply and GND must match the motor/driver requirements. | Robot motor control |
| 36 | DC Toy Motor | Rotates continuously when suitable DC power is applied. Reversing polarity reverses direction. | Connect through a suitable motor driver for controller-based control, or to a matched power source for simple testing. | Small moving mechanisms |
| 37 | SG90 Servo Motor | Moves its shaft to commanded angular positions using internal feedback electronics. | Signal wire to a suitable control pin; power and GND to a suitable supply. | Robotic arm or mechanism |
| 38 | BO Motor 150 RPM | A geared DC motor that trades speed for useful torque. | Connect to a motor driver/H-bridge and suitable motor power supply. | Robot wheels/mechanisms |

## Motor Rule
Never power a DC motor directly from a microcontroller I/O pin. Use a motor driver and a supply that matches the motor.
