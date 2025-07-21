/*
 * =============================================================================
 * File Name    : S32K_WDOG.h
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

#ifndef DRIVER_S32K_WDOG_H_
#define DRIVER_S32K_WDOG_H_

//==============================================================================
//                               INCLUDES
//==============================================================================

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================

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
 * @brief Disable watchdog
 */
void WDOG_Disable(void);

/*
 * @brief Unlock watchdog
 */
void WDOG_Unlock(void);

/*
 * @brief: Enable once the watchdog
 * @param: TM: Timeout period, value range im ms [2,130]
 */
void WDOG_EnableOnce(uint16_t TM);

/*
 * @brief: Enable watchdog
 * @param: TM: Timeout period, value range im ms [2,130]
 */
void WDOG_Enable(uint16_t TM);

/*
 * @brief Refresh watchdog
 */
void WDOG_Refresh(void);


#endif /* DRIVER_S32K_WDOG_H_ */
