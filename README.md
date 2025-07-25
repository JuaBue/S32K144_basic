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

## 2. KEY Input Module

This module provides support for reading digital input signals from physical buttons (keys) connected to the **S32K144** microcontroller by NXP. It supports two operation modes: continuous polling or edge-triggered detection, allowing flexible integration depending on application needs.

### 2.0. Pin Configuration

| Key     | GPIO (Port) | Physical Pin | Description        |
|---------|-------------|---------------|--------------------|
| `KEYA`  | `PTD2`       | Pin D2        | Digital input      |
| `KEYB`  | `PTD4`       | Pin D4        | Digital input      |
| `KEYC`  | `PTD3`       | Pin D3        | Digital input      |

> 🧷 **Note:** Keys should be connected to ground (GND) and pulled high by either internal or external pull-up resistors.

### 2.1. Features

- Supports multiple physical keys
- Two operation modes:
  - `MODE_CONT`: Continuous detection while the key is held down (level-triggered)
  - `MODE_NOCONT`: Single detection per press (edge-triggered)
- Active-low key detection
- Supports internal or external pull-up resistors
- Direct GPIO pin mapping using Port D

### 2.2. Dependencies

- NXP SDK GPIO driver
- Prior initialization of GPIO ports and system clocks

### 2.3. Configuration

Before using this module, ensure the following:

- PTD2, PTD3, and PTD4 are configured as digital input pins.
- Pull-up resistors are enabled (either internal or external).
- Operation mode (`MODE_CONT` or `MODE_NOCONT`) is selected by the application code.
