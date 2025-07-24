# S32K144 Basic

## 1. BUZZ Module

Buzzer Control on S32K144 (PTD16) This module provides an interface to control a passive buzzer using **Port D pin 16 (PTD16)** on the NXP **S32K144**. It allows generation of single tones (notes) and predefined songs using PWM.

### 1.0. Pin Configuration

| Signal     | MCU Pin | Function    |
|------------|---------|-------------|
| Buzzer PWM | PTD16   | Output PWM  |
| LED 3      | PTA11   | Output LED  |

- This pin should be connected to a passive buzzer (through a transistor or driver, if required).

### 1.1. Features

- Generates tones with configurable frequency and duration
- Supports playing sequences (songs)
- Configurable volume (via duty cycle)

### 1.2. How It Works

1. We act directly on the buzzer pin using two for loops: one to define the note frequencies and another for the duration.
2. Notes are represented as frequencies in Hz (e.g., A4 = 440 Hz).
3. A song is an array of `{frequency, duration_ms}` pairs.
