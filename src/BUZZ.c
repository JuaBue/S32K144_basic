/*
 * =============================================================================
 * File Name    : Buzz.c
 * Project      : S32K144_basic
 * Module       : Buzz Module
 * Author       : JuaBue
 * Created On   : 2025-07-23
 * Last Updated : 2025-07-23
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
//==============================================================================
//                                INCLUDES
//==============================================================================
#include "BUZZ.h"

//==============================================================================
//                         LOCAL DEFINES AND MACROS
//==============================================================================
#define MAX_NUM_NOTES                  8U


//==============================================================================
//                       LOCAL TYPES AND ENUMERATIONS
//==============================================================================

//==============================================================================
//                           GLOBAL VARIABLES
//==============================================================================
/* List the frequencies according to the simple notation */
const uint16_t tune[] = {
    M3, M3, M4, M5,
    M5, M4, M3, M2,
    M1, M1, M2, M3,
    M3, M2, M2,
    M3, M3, M4, M5,
    M5, M4, M3, M2,
    M1, M1, M2, M3,
    M2, M1, M1,
    M2, M2, M3, M1,
    M2, M3, M4, M3, M1,
    M2, M3, M4, M3, M2,
    M1, M2, D5, D0,
    M3, M3, M4, M5,
    M5, M4, M3, M4, M2,
    M1, M1, M2, M3,
    M2, M1, M1
};

/* List the beats according to the simple notation */
const float durt[] = {
    1,    1,    1,    1,
    1,    1,    1,    1,
    1,    1,    1,    1,
  1.5,  0.5,    2,
    1,    1,    1,    1,
    1,    1,    1,    1,
    1,    1,    1,    1,
  1.5,  0.5,    2,
    1,    1,    1,    1,
    1,  0.5,  0.5,    1,    1,
    1,  0.5,  0.5,    1,    1,
    1,    1,    1,    1,
    1,    1,    1,    1,
    1,    1,    1,  0.5,  0.5,
    1,    1,    1,    1,
  1.5,  0.5,    2,
};

//==============================================================================
//                          STATIC VARIABLES
//==============================================================================

//==============================================================================
//                      STATIC FUNCTION DECLARATIONS
//==============================================================================
static void tone (uint32_t frecuency, uint32_t duration);

//==============================================================================
//                       PUBLIC FUNCTION DEFINITIONS
//==============================================================================
void BUZZ_Init(void)
{
    GPIO_PinInit(PTD16, GPO, 0);         /* Configure buzz ports */
    LED_Init();
}

void BUZZ_MainTask(void)
{
    const uint16_t length = sizeof (tune)/ sizeof (tune[0]);
    for (uint16_t i = 0; i < length; i++) {
        LED_Reverse(3);
        tone(tune[i], (500*durt[i]));
        LED_Reverse(3);
    }
    delay(2000);
}

void BUZZ_playNote(char note, uint16_t duration)
{
    const char names[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    const uint16_t tones[] = {1900, 1200, 900, 500, 300, 200, 150, 100};

    for (uint16_t i = 0; i < MAX_NUM_NOTES; i++) {
        if (names[i] == note) {
            for (uint32_t j = 0; j < duration * 1000; j += tones[i] * 2 ) {
                BUZZ_OFF();
                systime.delay_us(tones[i]);
                BUZZ_ON();
                systime.delay_us(tones[i]);
                BUZZ_OFF();
            }
            /* break the loop */
            break;
        }
    }
}

//==============================================================================
//                       STATIC FUNCTION DEFINITIONS
//==============================================================================

/*
 * @brief: Play a note with the buzzer
 * @param: frecuency: frecuency of the note
 * @param: duration: duration time in us
 */
static void tone (uint32_t frecuency, uint32_t duration)
{
    uint32_t ustime = 1000000 / frecuency;
    uint32_t dur = systime.get_time_ms();

    while ((systime.get_time_ms() - dur) < duration) {
        BUZZ_OFF();
        systime.delay_us(ustime/2);
        BUZZ_ON();
        systime.delay_us(ustime/2);
        BUZZ_OFF();
    }
}

