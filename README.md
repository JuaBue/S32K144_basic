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

## 2. FTM - FlexTimer Module

### 2.0. FTM0

This project demonstrates the use of the **FTM0 (FlexTimer Module)** on the **NXP S32K144** microcontroller, including basic PWM generation. FTM modules are ideal for precise timing applications such as motor control, signal measurement, and event scheduling.

#### 2.0.0. FTM0 Features

- 8 independent channels (0–7)
- 16-bit up-counter
- Supports:
  - Edge-aligned and center-aligned PWM
  - Input capture and output compare
  - Quadrature decoding (encoder interface)
  - Channel combination with dead-time insertion
- Interrupt and DMA capable
- Configurable polarity and output masking
- Software and hardware synchronization

#### 2.0.1. Supported Modes

| Mode               | Description |
|--------------------|-------------|
| PWM                | Generates pulse-width modulated signals. |
| Input Capture      | Captures timer value on signal edges. |
| Output Compare     | Triggers output action on match with a reference value. |
| Quadrature Decoder | Reads rotary encoder inputs (direction + speed). |
| Complementary PWM  | Dual outputs with dead-time, used for motor drivers. |

#### 2.0.2. Basic Setup

1. Enable the PCC clock for FTM0
2. Disable write protection and enable FTM mode
3. Configure prescaler, clock source, and counting mode
4. Set MOD register for PWM period
5. Set CnSC/CnV for duty cycle
6. Enable the output pin via PORTx_PCRn

---

## 3. References

| Title              | Description | Location        |
|--------------------|-------------|-----------------|
| S32K1xx Reference Manual | Full technical reference for peripherals, including FTM, NVIC, GPIO, etc. | https://www.nxp.com/webapp/Download?colCode=S32K1XXRM |
| S32K144 Datasheet | Electrical characteristics, pinouts, timing, and package options. | https://www.nxp.com/docs/en/data-sheet/S32K1xx.pdf |
| AN5303 |  A step-by-step explanation on how to use FTM for advanced motor control (BLDC, PMSM). | https://www.nxp.com/docs/en/application-note/AN5303.pdf |
>>>>>>> d05f41f (Include info in the Readme.md for the FTM)
