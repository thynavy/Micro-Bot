# **Micro:BOT Educational Board Overview**

## Introduction of Micro:Bot
Micro:Bot is an educational board that is a microcontroller board based on the ATmega328P ([datasheet](https://github.com/thynavy/Micro-Bot)). It is widely used in embedded systems and robotics projects due to its simplicity, low power consumption, and support for a broad range of peripherals. On board Micro:Bot is the basic of robotics with 4 motors, buzzer, button, RGB, servo pinout, IO pinout and with multi protocol communications such as SPI, I2C and UART. The Micro:BOT is designed to offer students, hobbyists, and engineers a robust platform for learning and implementing robotics and automation concepts.

![Micro:BOT](https://github.com/thynavy/Micro-Bot/blob/main/Picture/Micro_BOT_1111.png)

You can find your board's warranty information or any discount [here](https://github.com/thynavy/Micro-Bot).

# **Getting started with Micro:BOT**
Welcome to Micro:BOT! Before you start controlling the world around you, you'll need to set up the software to program your board. The [Arduino Software (IDE)](https://www.arduino.cc/en/software) allows you to write programs and upload them to your board. Install the Arduino Desktop IDE and To get step-by-step instructions select one of the following link according to your operating system as below:
  - [Windows](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/#windows)
  - [macOS](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/#macos)
  - [Linux](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/#linux)
  - [Portable IDE](https://docs.arduino.cc/software/ide-v1/tutorials/PortableIDE)(Windows and Linux)
  - ChromeOS (Arduino Create App) in the [Chrome Web Store](https://chromewebstore.google.com/detail/arduino-create/dcgicpihgkmccjigalccipmjlnjopdfe?pli=1)
Choose your board in the list here on the right to learn how to get started with it and how to use it on the Desktop IDE.

## Learn Micro:BOT
  - Read an introduction on what is [Micro:BOT](https://github.com/thynavy/Micro-Bot) and why you'd want to use it.
  - What is the [Arduino Software (IDE)](https://www.arduino.cc/en/software) with Micro:BOT board?
  - [Libraries](https://github.com/thynavy/Micro-Bot): Using and installing STEAMxLAB Libraries.

Making the Micro:BOT Starter Kit projects and reading the book '[Getting Started with Micro:BOT](https://github.com/thynavy/Micro-Bot)' are great ways to start learning and tinkering with coding and electronics.

## General Care - Cleaning Your Board
Now you know how to get started with your Micro:BOT board, so here are a few basic tips on caring for your Micro:BOT in the future:

  - Despite the temptation to carry on with your project through dinner, try to avoid eating and drinking whilst using your Micro:BOT board - it doesn’t like getting wet, and there’s nothing worse than food crumbs in your headers!
  - If your Micro:BOT has been running a project for the past few months and gathered a fair amount of dust, try using any readily available Air Duster - these are ideal for removing dust and debris from the surface of the board and difficult to reach areas such as the ports and between the pins.
  - Please do your best to not spill liquid on your board. As accidents do happen though, if you inadvertently spill something sticky on your board and are lucky enough that it still works then we’d recommend using an IPA (isopropyl alcohol) wipe to safely remove grease, dirt and dust from the board. N.B. please ensure your board is disconnected from the computer or battery before applying the IPA wipe.

Finally, please wash your hands.

# **Documentation**
## Pinout Diagram

![Micro:BOT](https://github.com/thynavy/Micro-Bot/blob/main/Picture/MicroBOT.drawio.png)

Download the full pinout diagram as PDF [here](https://github.com/thynavy/Micro-Bot).

# Micro:BOT Specifications

| **Feature**             | **Description**                              |
|--------------------------|----------------------------------------------|
| Microcontroller          | ATmega328P                                  |
| Operating Voltage        | 5V                                          |
| Input Voltage (recommended) | 7-12V                                    |
| Input Voltage (limit)    | 6-18V                                       |
| DC Current per I/O Pin   | 20 mA                                       |
| DC Current for 3.3V Pin  | 50 mA                                       |
| Flash Memory             | 32 KB (ATmega328P) of which 0.5 KB used by bootloader |
| SRAM                     | 2 KB (ATmega328P)                           |
| EEPROM                   | 1 KB (ATmega328P)                           |
| Clock Speed              | 16 MHz                                      |
| BUTTON_BUILTIN           | Button                                      |
| BUZZER_BUILTIN           | buzzerPin                                   |
| RGB_BUILTIN              | rgbPin                                      |
| MOTOR1_BUILTIN           | motor1                                      |
| MOTOR2_BUILTIN           | motor2                                      |
| MOTOR3_BUILTIN           | motor3                                      |
| MOTOR4_BUILTIN           | motor4                                      |
| Servo Motor PIN          | servoMotor                                  |
| Analog PIN               | A0, A1, A2, A3                              |
| I/O Digital PIN          | ioRead, ioWrite                             |
| nRF24L01 PIN             | nrfTransmit, nrfReceiver                    |
| Bluetooth PIN            | Rx, Tx, GND, 5V                             |
| I²C protocol PIN         | SDA, SCL, GND, 5V                           |
| Length                   | 69.35 mm                                    |
| Width                    | 68.25 mm                                    |
| Weight                   | 40 g                                        |


## Core Features and Capabilities
### 1. Microcontroller Core:
  - Powered by the ATmega328P, an 8-bit microcontroller featuring 32 KB flash memory, 2 KB SRAM, and 1 KB EEPROM (which can be read and written with the [EEPROM library](https://docs.arduino.cc/learn/built-in-libraries/eeprom/)).
### 2. Motor Control:
  - Supports 4 motor outputs, enabling easy implementation of motor-driven robotic systems. [_Example with Motor Control_](https://github.com/thynavy/Micro-Bot)
### 3. On-Board Components for Learning and Development:
  - Buzzer: Integrated for sound feedback and signaling. [_Example with Buzzer_](https://github.com/thynavy/Micro-Bot)
  - Button: For user input and control. [_Example with Button_](https://github.com/thynavy/Micro-Bot)
  - RGB LED: Provides color-coded visual feedback. [_Example with RGB_](https://github.com/thynavy/Micro-Bot)
### 4. Servo and I/O Pinouts:
  - Servo motor control pinout for handling precise position control applications. [_Example with Servo motor control_](https://github.com/thynavy/Micro-Bot)
  - General I/O pinout for connecting external sensors, actuators, and other peripherals. [_Example with General I/O_](https://github.com/thynavy/Micro-Bot)
### 5. Communication Interfaces:
  - SPI (Serial Peripheral Interface). [_Example with SPI communication (nRF24L01)_](https://github.com/thynavy/Micro-Bot)
  - I²C (Inter-Integrated Circuit). [_Example with I2C protocol_](https://github.com/thynavy/Micro-Bot)
  - UART (Universal Asynchronous Receiver-Transmitter). [_Example with UART communication (Bluetooth)_](https://github.com/thynavy/Micro-Bot)

## Applications
  - **Educational Robotics**: Teaching robotics fundamentals such as motor control, sensor integration, and embedded systems programming. [_Example with Robotics_](https://github.com/thynavy/Micro-Bot)
  - **Automation Projects**: Designing simple automation tasks and smart systems. [_Example with Automation_](https://github.com/thynavy/Micro-Bot)
  - **DIY Electronics**: Developing personal electronics projects with robust communication options. [_Example with DIY Electronics_](https://github.com/thynavy/Micro-Bot)

## Advantages
  - User-Friendly Design: Simplified interface for beginners and advanced users.
  - All-in-One Learning Platform: Comprehensive support for robotics concepts on a single board.
  - Low Power Consumption: Efficient design suited for battery-powered applications.
  - Versatile Peripheral Support: Ready to handle a wide range of components and external devices.
  - [Libraries](https://github.com/thynavy/Micro-Bot) support: Have libraries support from STEAMx LAB with an example code in Arduino IDE.
