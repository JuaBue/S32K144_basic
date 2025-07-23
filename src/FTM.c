/*
 * =============================================================================
 * File Name    : FTM.c
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
//==============================================================================
//                                INCLUDES
//==============================================================================
#include "FTM.h"

//==============================================================================
//                         LOCAL DEFINES AND MACROS
//==============================================================================

//==============================================================================
//                       LOCAL TYPES AND ENUMERATIONS
//==============================================================================

//==============================================================================
//                           GLOBAL VARIABLES
//==============================================================================

//==============================================================================
//                          STATIC VARIABLES
//==============================================================================

//==============================================================================
//                      STATIC FUNCTION DECLARATIONS
//==============================================================================

//==============================================================================
//                       PUBLIC FUNCTION DEFINITIONS
//==============================================================================

void FTM0_init(void)
{
    /* Ensure clk disabled for the configuration */
    PCC->PCCn[PCC_FTM0_INDEX] &= ~PCC_PCCn_CGC_MASK;
    /* Clock Src = 1, 8 MHz SOSCDIV1_CLK and Enable clock for FTM regs */
    PCC->PCCn[PCC_FTM0_INDEX] |= (PCC_PCCn_PCS(0x01) | PCC_PCCn_CGC_MASK);

    /* Write protect to registers diabled (default) */
    FTM0->MODE |= FTM_MODE_WPDIS_MASK;
    /* Channel 0 PWM enable bit = 1 Output port is enable
     * Channel 1 PWM enable bit = 1 Output port is enable
     * Channel 2-7 PWM enable bit = 0 Output port are disable
     * TOIE (Timer Overflow Interrupt Enable) = 0 Disable
     * CPWMS (Center aligned PWM Select) = 0 Up counting mode
     * CLKS (Clock source) = 0 No clock selected -> FTM disabled
     * PS (Prescaler factor) = 0. Prescaler = 1 */
    FTM0->SC = (FTM_SC_PWMEN0_MASK | FTM_SC_PWMEN1_MASK);
    /* FTM mode settings used: DECAPENx, MCOMBINEx, COMBINEx=0 */
    FTM0->COMBINE = 0x00000000;
    /* Polarity for all channels is active high (default) */
    FTM0->POL = 0x00000000;
    /* FTM0 counter final value (used for PWM mode)
     * FTM0 Period = MOD_CNTIN+0x0001
     * 8MHz / 1 = 8MHz ticks -> 1280Hz */
    FTM0->MOD = FTM0_COUNT_NUM - 1;



}

//==============================================================================
//                       STATIC FUNCTION DEFINITIONS
//==============================================================================


