/*
 * =============================================================================
 * File Name    : LED.h
 * Project      : S32K144_basic
 * Module       : LED Control Module (Header)
 * Author       : JuaBue
 * Created On   : 2025-06-11
 * Version      : 1.0.0
 *
 * Description  :
 *   This module provides definitions and function prototypes for controlling
 *   onboard and expansion board LEDs on the S32K144 platform. It includes basic
 *   operations such as initialization, turning LEDs on/off, and toggling their
 *   state.
 *
 *   LED pin mappings:
 *     - LED1_IO : PTC17 (Core board)
 *     - LED2_IO : PTD17
 *     - LED3_IO : PTA11
 *     - LED4_IO : PTA12
 *     - LED5_IO : PTA13
 *     - LED6_IO : PTA14
 *
 * Dependencies :
 *   - GPIO driver
 *
 * Configuration :
 *   - Output mode, active-high logic
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

#ifndef LED_H_
#define LED_H_

//==============================================================================
//                               INCLUDES
//==============================================================================
#include "include.h"

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================
#define LED1_IO             PTC17   // Core board LED
#define LED2_IO             PTD17
#define LED3_IO             PTA11   // Expansion board LED
#define LED4_IO             PTA12
#define LED5_IO             PTA13
#define LED6_IO             PTA14

#define MAX_LED             6U

//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================

//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================

/*
 * @brief LED Initialization
 */
void LED_Init(void);

/*
 * @brief: Turn on LED
 * @param: led: number of LED
 */
void LED_ON(uint8_t led);

/*
 * @brief: Turn off LED
 * @param: led: number of LED
 */
void LED_OFF(uint8_t led);

/*
 * @brief: Flip LED
 * @param: led: number of LED
 */
void LED_Reverse(uint8_t led);

/*
 * @brief: Test Routine LED
 */
void Test_LED(void);

#endif /* LED_H_ */
