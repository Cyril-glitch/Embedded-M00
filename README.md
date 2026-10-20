# Embedded-M00 ⚡

![ATmega328P board illustration](assets/atmega328p.png)

This project is a hands-on introduction to embedded C programming with the AVR microcontroller family, using an ATmega328P target and a minimal Arduino-compatible setup.

The main goal is to learn the fundamentals of embedded systems by directly interacting with hardware registers, GPIO pins, timing, and button handling.

## What you learn 🧠

This repository introduces the core concepts of low-level embedded programming:

- GPIO configuration and register-level control
- Digital input/output on AVR ports
- LED control and signal toggling
- Button reading and switch detection
- Debounce techniques in software
- Basic project structure for AVR firmware
- Firmware compilation and flashing with `make` and `avrdude`

## Project setup 🛠️

This repository contains several small exercises under separate folders such as `ex00`, `ex01`, `ex02`, `ex03`, and `ex04`.

Each exercise is a small firmware project focused on a specific embedded concept.

## Build commands 🔧

From the project root, you can compile an exercise with:

```bash
make -C ex01 hex
```

To flash the firmware to the board:

```bash
make -C ex01 flash
```

To build and flash in one step:

```bash
make -C ex01 all
```

To clean generated build files:

```bash
make -C ex01 clean
```

If you are inside the exercise folder itself, the commands are simply:

```bash
make hex
make flash
make all
make clean
```

## Required tools 🧰

You need the AVR toolchain installed on your machine:

- `avr-gcc`
- `avr-libc`
- `avr-objcopy`
- `avrdude`

On Debian/Ubuntu-based systems:

```bash
sudo apt update
sudo apt install gcc-avr avr-libc avrdude
```

## Hardware used 🖥️

This project targets an ATmega328P-based board, typically an Arduino-compatible board.

Typical hardware components:

- ATmega328P microcontroller
- LED on a GPIO output pin
- Push button on an input pin
- USB programming interface / serial port

## Useful resources 📚

- ATmega328P datasheet: https://www.microchip.com/en-us/product/ATmega328P
- AVR libc documentation: https://www.nongnu.org/avr-libc/user-manual/
- AVR-GCC toolchain: https://gcc.gnu.org/wiki/avr-gcc
- avrdude documentation: https://github.com/avrdudes/avrdude

## Notes 📝

- These exercises use direct register access, which is the foundation of embedded programming.
- The Makefiles are configured for an Arduino-style ATmega328P target and may need the serial port adjusted depending on the machine.
- The target port is usually `/dev/ttyUSB0` in Linux environments.