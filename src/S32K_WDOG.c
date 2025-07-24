/*
 * =============================================================================
 * File Name    : S32K_WDOG.c
 * Project      : S32K144_basic
 * Module       : Watchdog Timer (WDOG)
 * Author       : JuaBue
 * Created On   : 2025-07-21
 * Version      : 1.0.0
 *
 * Description  :
 *   This module provides initialization, configuration, and refresh handling
 *   for the Watchdog Timer (WDOG) peripheral of the NXP S32K144 microcontroller.
 *   It allows enabling, disabling, and servicing the WDOG in bare-metal
 *   environments without using SDK or CMSIS.
 *
 * Dependencies :
 *   - S32K144 device memory map (WDOG base address: 0x40052000)
 *   - Core system clock for prescaler calculations
 *
 * Configuration :
 *   - WDOG_ENABLE           : Enable or disable the watchdog (macro or function call)
 *   - WDOG_TIMEOUT_MS       : Timeout value in milliseconds (uint16_t range)
 *   - WDOG_USE_PRESCALER    : Use prescaler ÷256 to extend timeout range
 *   - WDOG_LPO_CLOCK_KHZ    : Expected LPO frequency in kHz (typically 1 kHz)
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
#include "include.h"
#include "S32K_WDOG.h"

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
void WDOG_Disable(void)
{
    DisableInterrupts;                          // Disable global interrupt
    WDOG->CNT = FEATURE_WDOG_UNLOCK_VALUE;      // Unlock watchdog
    WDOG->TOVAL = 0x0000FFFF;                   // Maximum timeout value
    WDOG->CS &= ~WDOG_CS_EN_MASK;               // Disable watchdog
    EnableInterrupts;                           // Enable global interrupt
}


void WDOG_Unlock(void)
{
    DisableInterrupts;                          // Disable global interrupt
    WDOG->CNT = FEATURE_WDOG_UNLOCK_VALUE;      // Unlock watchdog
    EnableInterrupts;                           // Enable global interrupt
}


void WDOG_EnableOnce(uint16_t TM)
{
    DisableInterrupts;                          // Disable global interrupt
    WDOG->CNT = FEATURE_WDOG_UNLOCK_VALUE;      // Unlock watchdog
    while((WDOG->CS & WDOG_CS_ULK_MASK) == 0);  // Wait until registers are unlocked
    WDOG->CS = WDOG_CS_CMD32EN(1)               // Configure Watchdog
             | WDOG_CS_EN(1)
             | WDOG_CS_PRES(1)
             | WDOG_CS_CLK(1)
             | WDOG_CS_INT(1)
             | WDOG_CS_WIN(0)
             | WDOG_CS_UPDATE(0);
    WDOG->TOVAL = TM/2;                           // Set timeout value
    while((WDOG->CS & WDOG_CS_RCS_MASK) == 0);  // Wait until new config takes effect
    EnableInterrupts;                           // Enable global interrupt
}


void WDOG_Enable(uint16_t TM)
{
    DisableInterrupts;                          // Disable global interrupt
    WDOG->CNT = FEATURE_WDOG_UNLOCK_VALUE;      // Unlock watchdog
    while((WDOG->CS & WDOG_CS_ULK_MASK) == 0);  // Wait until registers are unlocked
    WDOG->CS = WDOG_CS_CMD32EN(1)               // Configure Watchdog
             | WDOG_CS_EN(1)
             | WDOG_CS_PRES(1)
             | WDOG_CS_CLK(1)
             | WDOG_CS_INT(1)
             | WDOG_CS_WIN(0)
             | WDOG_CS_UPDATE(1);
    WDOG->TOVAL = TM/2;                           // Set timeout value
    while((WDOG->CS & WDOG_CS_RCS_MASK) == 0);  // Wait until new config takes effect
    EnableInterrupts;                           // Enable global interrupt
}


void WDOG_Refresh(void)
{
    DisableInterrupts;                          // Disable global interrupt
    WDOG->CNT = FEATURE_WDOG_TRIGGER_VALUE;     // refresh watchdog
    EnableInterrupts;                           // Enable global interrupt
}

//==============================================================================
//                       STATIC FUNCTION DEFINITIONS
//==============================================================================
