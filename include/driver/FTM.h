/*
 * =============================================================================
 * File Name    : FTM.h
 * Project      : S32K144_basic
 * Module       : FlexTimer Module (FTM)
 * Author       : JuaBue
 * Created On   : 2025-07-22
 * Version      : 1.0.0
 *
 * Description  :
 *   This module provides low-level initialization and control routines for the
 *   FlexTimer Module (FTM) peripheral in the NXP S32K144 microcontroller.
 *   It supports PWM generation, input capture, output compare, and general-
 *   purpose timing functions across multiple FTM instances (FTM0–FTM3).
 *
 *   The module is implemented for bare-metal use (no SDK or CMSIS dependencies),
 *   giving the user full control over the FTM registers.
 *
 * Dependencies :
 *   - S32K144 memory map (FTMx base addresses: FTM0: 0x40038000,
 *     FTM1: 0x40039000, ...)
 *   - System clock configuration (needed to compute timer ticks)
 *   - Optional GPIO or PORT configuration for FTM pin muxing
 *
 * Configuration :
 *   - FTM_USE_INSTANCE        : Select which FTM instance to use (0, 1, 2, or 3)
 *   - FTM_CHANNEL             : Channel number to configure (0–7)
 *   - FTM_PWM_FREQUENCY_HZ    : Desired PWM frequency in Hz
 *   - FTM_PWM_DUTY_PERCENT    : Duty cycle (0–100%)
 *   - FTM_INPUT_CAPTURE_EDGE  : Edge type (rising/falling/both)
 *   - FTM_CLOCK_SOURCE_MHZ    : Clock input to the FTM module (after prescaler)
 *   - FTM_PRESCALER           : Prescaler divisor (1, 2, 4, ..., 128)
 *
 * License :
 *   This file is part of a free software project released under the terms of
 *   the GNU General Public License version 3 (GPLv3).
 *
 *   You are free to use, modify, and distribute this file under the conditions
 *   of the GPLv3, as long as you retain this header and provide proper
 *   attribution to the original author.
 *
 *   See <https://www.gnu.org/licenses/gpl-3.0.html> for the full license text.
 *
 *   Copyright (c) 2025 Juan I. Bueno
 *   All rights reserved.
 *
 * =============================================================================
 */
#ifndef DRIVER_FTM_H_
#define DRIVER_FTM_H_

//==============================================================================
//                               INCLUDES
//==============================================================================
#include "include.h"

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================
#define FTM0_COUNT_NUM                 6250

//==============================================================================
//                        PUBLIC TYPES AND ENUMERATIONS
//==============================================================================

//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================

//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================

/*
 * @brief Initilize the FlexTimer module 0
 */
void FTM0_init(void);

#endif /* DRIVER_FTM_H_ */
