/*
 * =============================================================================
 * File Name    : KEY.h
 * Project      : S32K144_basic
 * Module       : Key Input Module (Header)
 * Author       : JuaBue
 * Created On   : 2025-06-12
 * Version      : 1.0.0
 *
 * Description  :
 *   This header file provides the necessary definitions and function prototypes
 *   for handling key/button inputs on the S32K144. It supports two operation modes:
 *     - MODE_CONT   : Continuous detection while key is pressed
 *     - MODE_NOCONT : One-time detection per key press (edge-triggered)
 *
 *   Key definitions:
 *     - KEYA_IO : PTD2
 *     - KEYB_IO : PTD4
 *     - KEYC_IO : PTD3
 *
 * Dependencies :
 *   - GPIO driver
 *
 * Configuration :
 *   - Active-low keys with internal or external pull-up resistors
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
#ifndef DRIVER_KEY_H_
#define DRIVER_KEY_H_

//==============================================================================
//                               INCLUDES
//==============================================================================
#include "include.h"

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================

//==============================================================================
//                        PUBLIC TYPES AND ENUMERATIONS
//==============================================================================

typedef enum {
    KEY_NA = 0,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_MAX,
} Key_types;

typedef enum {
    MODE_NOCONT,
    MODE_CONT,
} Mode_types;

typedef enum {
    KSTATUS_NOPRESS,
    KSTATUS_B1_PRESS,
    KSTATUS_B2_PRESS,
    KSTATUS_B3_PRESS,
} KeyStatus_types;

//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================

//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================

/*
 * @brief KEY Initialization
 */
void KEY_Init(void);

/*
 * @brief: Get key value
 * @param: mode: MODE_NOCONT, does not support continuous pressing; MODE_CONT,
 *               supports continuous pressing.
 * @return: KeyStatus_types, KSTATUS_NOPRESS: No button pressed KSTATUS_B1_PRESS:
 *          Button 1 pressed KSTATUS_B2_PRESS: Button 2 pressed KSTATUS_B3_PRESS:
 *          Button 3 pressed
 */
KeyStatus_types KEY_Read(Mode_types mode, Key_types key);

/*
 * @brief: Key Test Procedure
 */
void Test_KEY(void);

/*
 * @brief: Key Test with interrupt
 */
void Test_KEYint(void);


#endif /* DRIVER_KEY_H_ */
