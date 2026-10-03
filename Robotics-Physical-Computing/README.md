# Robotics & Physical Computing

Robotics and physical computing combine **controllers, sensors, input devices, output devices, actuators, power, electronic components, tools, and mechanical structures** to create systems that interact with the physical world.

This section is organised as a student component handbook based on the uploaded **Microcontroller Boards Reference**. The source contains 82 items across electronics, robotics, tools, power, and mechanical construction.

## How Physical Computing Works

```text
Input / Sensor
      |
      v
Microcontroller ---> Program / Decision
      |
      v
Output / Actuator ---> Physical Action
```

A working system also depends on:

```text
Power + Correct Connections + Mechanical Structure + Testing
```

## How to Study a Component

For every component, students should be able to answer:

1. **What is it?**
2. **What physical or electrical idea makes it work?**
3. **Is it an input, output, controller, driver, power part, or structural part?**
4. **How is it connected?**
5. **What voltage/current/polarity limits must be checked?**
6. **Where could it be used?**
7. **How would I test it separately before building a full project?**

## Connection and Safety Rules

- Check the exact module label and datasheet when pin names or voltage levels vary.
- Connect GND correctly when circuits need a common reference.
- Use current-limiting resistors with LEDs.
- Do not connect motors or high-current loads directly to microcontroller I/O pins.
- Use a suitable driver for motors, relays, speakers, pumps, and other higher-current loads.
- Observe polarity on batteries, LEDs, diodes, electrolytic capacitors, and DC supplies.
- Keep school projects at safe low voltage.
- Do not use student breadboards for mains-voltage wiring.
- Test one section at a time with a multimeter where appropriate.
- Disconnect power before changing wiring.

## Reference Chapters

1. [Microcontroller Boards](./01-Microcontroller-Boards/)
2. [Displays and Modules](./02-Displays-and-Modules/)
3. [Sensors](./03-Sensors/)
4. [Input Devices](./04-Input-Devices/)
5. [Output Devices](./05-Output-Devices/)
6. [Actuators and Motors](./06-Actuators/)
7. [Resistors](./07-Resistors/)
8. [Capacitors](./08-Capacitors/)
9. [Transistors and Diodes](./09-Transistors-and-Diodes/)
10. [Integrated Circuits](./10-Integrated-Circuits/)
11. [Connectors and Prototyping](./11-Connectors-and-Prototyping/)
12. [Electronics Tools](./12-Tools/)
13. [Power Sources and Accessories](./13-Power-Sources-and-Accessories/)
14. [Mechanical and Structural Components](./14-Mechanical-and-Structural-Components/)

<!-- Add only project or reference titles here whenever new folders are created. -->
