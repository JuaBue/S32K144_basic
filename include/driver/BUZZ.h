/*
 * =============================================================================
 * File Name    : Buzz.h
 * Project      : S32K144_basic
 * Module       : Buzz Module
 * Author       : JuaBue
 * Created On   : 2025-07-23
 * Version      : 1.0.0
 *
 * Description  :
 *   This file contains functions for controlling a buzzer to play simple songs.
 *   In this example, the buzzer will play a song in a predefined pattern.
 *
 * Dependencies :
 *   - GPIO driver for buzzer control
 *   - Timer driver for generating delays
 *
 * Configuration :
 *   - Buzzer connected to GPIO pin PTD16
 *   - Timer configured for delay generation
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
#ifndef DRIVER_BUZZ_H_
#define DRIVER_BUZZ_H_

//==============================================================================
//                               INCLUDES
//==============================================================================
#include "include.h"

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================
#define BUZZ_OFF()                     GPIO_PinWrite(PTD16, 0);
#define BUZZ_ON()                      GPIO_PinWrite(PTD16, 1);
#define LED                            PTB12

/* Song */
#define D0                             0xFFFFU
#define D1                             262
#define D2                             293
#define D3                             329
#define D4                             349
#define D5                             392
#define D6                             440
#define D7                             494

#define M1                             523
#define M2                             586
#define M3                             658
#define M4                             697
#define M5                             783
#define M6                             879
#define M7                             987

#define H1                             1045
#define H2                             1171
#define H3                             1316
#define H4                             1393
#define H5                             1563
#define H6                             1755
#define H7                             1971

/* List all D frequencies */
#define WHOLE                          1
#define HALF                           0.5
#define QUARTER                        0.25
#define EIGHTH                         0.25
#define SIXTEENTH                      0.625


//==============================================================================
//                        PUBLIC TYPES AND ENUMERATIONS
//==============================================================================

//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================
extern const uint16_t tune[];
extern const float durt[];

//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================

/*
 * @brief BUZZ Initialization
 */
void BUZZ_Init(void);

/*
 * @brief Main task to perform the buzzer activities
 */
void BUZZ_MainTask(void);

/*
 * @brief: Play a note with the buzzer
 * @param: note: musical note from 'A' to 'H'
 * @param: duration: duration time in us
 */
void BUZZ_playNote(char note, uint16_t duration);

#endif /* DRIVER_BUZZ_H_ */
