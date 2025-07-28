/*
 * =============================================================================
 * File Name    : S32K_PLL.h
 * Project      : S32K144_basic
 * Module       : Clock & PLL Initialization Module (Header)
 * Author       : JuaBue
 * Created On   : 2025-03-13
 * Version      : 1.0.0
 *
 * Description  :
 *   This header file provides functions and configuration options to initialize
 *   the system clocks on the NXP S32K144 microcontroller. It supports setting up
 *   the System PLL (SPLL), external oscillator (XOSC), and RUN mode transitions.
 *
 *   Clock configuration options are defined in the `clk_option` enumeration, with
 *   recommended and unstable values annotated.
 *
 *   Example values:
 *     - PLL160: Recommended stable configuration
 *     - PLL220: Unstable
 *     - PLL252: Very unstable (not recommended)
 *
 * Dependencies :
 *   - Device-specific SCG, SPLL, and SOSC register definitions
 *
 * Configuration :
 *   - XOSC expected to operate at 8 MHz
 *   - Default RUN mode transitions to 80 MHz using PLL
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

#ifndef S32K_PLL_H_
#define S32K_PLL_H_

//==============================================================================
//                               INCLUDES
//==============================================================================
#include "include.h"

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================

//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================
extern uint32 core_clk_M;	//MHZ
extern uint32 bus_clk_M;	//MHZ

// PLL Parameters (Phase-locked loop)
typedef enum clk_option
{
    PLLUNULL ,
    PLL100   = 100,
    PLL112   = 112,
    PLL160   = 160,			// Recommended stable configuration
    PLL180   = 180,
    PLL184   = 184,
    PLL188   = 188,

    PLL200   = 200,
    PLL220   = 220,         // Unstable
    PLL252   = 252,         // Very unstable (not recommended)
    PLLtest,
} clk_option;


//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================

/*
 * @brief: CPU Initialize
 */
void MCU_Init(void);


/*
 * @brief: PLL Initialize
 * @param: opt: main frequency, (check clk_option)
 */
void SPLL_Init(clk_option opt);


/*
 * @brief: SCG Initialize
 * @note: Initialize XOSC (8MHz), SPLL (160MHz) and RUN mode
 */
void SCG_Init(void);

/*
 * @brief: Change to normal RUN mode with 8MHz SOSC, 80 MHz PLL
 */
void NormalRUNmode_80MHz(void);

#endif /* S32K_PLL_H_ */
