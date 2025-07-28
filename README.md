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

> 💡 **Note:** Keys should be connected to ground (GND) and pulled high by either internal or external pull-up resistors.

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

## 3. LED Control Module

This module provides support for controlling digital output signals connected to LEDs on the **S32K144** microcontroller by NXP. It enables turning individual LEDs on/off or toggling them dynamically from application code.

### 3.0. Pin Configuration

| LED     | GPIO (Port) | Physical Pin | Description            |
|---------|-------------|--------------|------------------------|
| `LED1`  | `PTC17`     | Pin C17      | Digital output         |
| `LED2`  | `PTD17`     | Pin D17      | Digital output         |
| `LED3`  | `PTA11`     | Pin A11      | Digital output         |
| `LED4`  | `PTA12`     | Pin A12      | Digital output         |
| `LED5`  | `PTA13`     | Pin A13      | Digital output         |
| `LED6`  | `PTA14`     | Pin A14      | Digital output         |

> 💡 **Note:** LEDs operate in **active-high** mode. A logic HIGH turns the LED on.

### 3.1. Features

- Controls up to 6 independent LEDs
- Basic operations:
  - `LED_ON(led)`: Turns on the specified LED
  - `LED_OFF(led)`: Turns off the specified LED
  - `LED_Reverse(led)`: Toggles the state of the specified LED
- Centralized initialization via `LED_Init()`
- Easy to extend by adjusting the `MAX_LED` macro

### 3.2. Dependencies

- NXP SDK GPIO driver
- Prior initialization of GPIO ports and system clocks

### 3.3. Configuration

Before using this module, ensure the following:

- Pins `PTC17`, `PTD17`, `PTA11`–`PTA14` are configured as **digital outputs**.
- External circuitry (e.g., resistors, LEDs) matches the expected voltage and current levels.
- `MAX_LED` is set appropriately if additional LEDs are added or removed.

> 🧪 You can use the `Test_LED()` function as a diagnostic routine to verify the LEDs are correctly wired and responding to commands.

## 4. GPIO Control Module

This module provides a flexible and complete interface for managing General Purpose Input/Output (GPIO) operations on the **S32K144** microcontroller by NXP. It enables input/output configuration, pin direction control, output toggling, and interrupt setup for all GPIO ports (PTA–PTE).

### 4.0. Pin Configuration and Modes

- Supports all GPIO ports: PTA, PTB, PTC, PTD, PTE
- Each pin can be individually configured with the following options:
  - Input (with optional pull-up/down)
  - Output (standard or high drive, optional slew rate)
  - Passive filter (for noisy digital input lines)
  - Interrupt triggers (edge or level)

> ⚠️ **Note:** Ensure the GPIO ports and system clock are properly initialized before calling any GPIO functions.

### 4.1. Features

- Direction selection: `GPI`, `GPO`, `GPO_HDS`, etc.
- Passive input filters and pull resistor configuration
- External interrupt support via `GPIO_ExtiInit()`
- Output control:
  - `GPIO_PinWrite()`
  - `GPIO_PinReverse()`
- Input reading:
  - `GPIO_PinRead()`
- Direction control:
  - `GPIO_PinSetDir()`
- Pull-up/pull-down control:
  - `GPIO_PortPull()`

### 4.2. Dependencies

- `common.h` (for `PTXn_e` type and GPIO index macros)
- MCU hardware headers (e.g., `PORTx`, `GPIOx` structures)
- NVIC initialization (for interrupt use)

### 4.3. Configuration

Before using this module:

- Include this header and ensure that `GPIOX` and `PORTX` arrays are mapped properly to their corresponding memory addresses.
- Enable pull-up/down as needed depending on the configuration (`GPI_UP`, `GPI_DOWN`, etc.).
- For interrupts, configure with `GPIO_ExtiInit()` and enable `NVIC_EnableIRQ()` separately.
- Use the appropriate macros (`PTA0_OUT`, `DDRA0`, etc.) for direct bit/byte/word access where needed.

## 5. UART Communication Module

This module provides a lightweight interface for serial communication over the **LPUART** peripherals on the NXP **S32K144** microcontroller. It supports full-duplex transmission and reception for UART0, UART1, and UART2, with basic send/receive APIs for strings, characters, and buffers.

### 5.0. Pin Configuration

| UART    | TX Pin   | RX Pin   | Ports Available     |
|---------|----------|----------|----------------------|
| UART0   | `PTB1`   | `PTB0`   | Also PTA2/PTA3/PTC2/PTC3 |
| UART1   | `PTC9`   | `PTC8`   | Also PTC6/PTC7/PTD13/PTD14 |
| UART2   | `PTA9`   | `PTA8`   | Also PTD6/PTD7/PTD17/PTE12 |

> 🔌 **Note:** Only one TX/RX pair per UART should be configured in the MUX settings at a time.

### 5.1. Features

- Supports 3 independent UART channels (LPUART0, 1, 2)
- Send/receive data as:
  - Single character
  - Buffer of bytes
  - Null-terminated strings
- Fixed configuration: 8 data bits, 1 stop bit, no parity (8N1)
- Dedicated initialization function for GPIO and peripheral
- Clean abstraction layer over LPUART peripheral registers

### 5.2. Dependencies

- PLL system configuration via `S32K_PLL.h`
- GPIO initialization for correct UART pin mapping
- Clock configuration must be completed before UART use

### 5.3. Configuration

Before using this module:

- Call `UART_PinInit(LPUARTx)` to configure the required TX/RX pins.
- Call `UART_Init(LPUARTx, baud)` with the desired baud rate (e.g., 9600, 115200).
- Ensure only the necessary UART MUX is active to avoid conflicts.
