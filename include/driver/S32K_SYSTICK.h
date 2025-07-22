/*
 * =============================================================================
 * File Name    : S32K_SYSTICK.h
 * Project      : S32K144_basic
 * Module       : SysTick Driver
 * Author       : JuaBue
 * Created On   : 2025-07-21
 * Version      : 1.0.0
 *
 * Description  :
 *   Provides initialization and basic control of the SysTick timer.
 *   Intended for use as a system time base (e.g., 1ms tick).
 *
 * Dependencies :
 *   - None
 *
 * Configuration :
 *   - SYS_TICK_FREQUENCY_HZ
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

#ifndef DRIVER_S32K_SYSTICK_H_
#define DRIVER_S32K_SYSTICK_H_

//==============================================================================
//                               INCLUDES
//==============================================================================

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================
#define delay(X)                    systime_delay_ms(X)

//==============================================================================
//                        PUBLIC TYPES AND ENUMERATIONS
//==============================================================================
typedef struct {
    void (* init) (void);
    uint64_t (* get_time_us) (void);
    uint32_t (* get_time_ms) (void);
    void (* delay_us) (uint32_t);
    void (* delay_ms) (uint32_t);
} systime_t;


//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================
extern systime_t  systime;


//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================

/*
 * @brief Initialize the systime
 */
void systime_init(void);

/*
 * @brief: Set the delay time in us
 * @param: us: delay time in us
 */
void systime_delay_us(uint32_t us);

/*
 * @brief: Set the delay time in ms
 * @param: ms: delay time in ms
 */
void systime_delay_ms(uint32_t ms);

#endif /* DRIVER_S32K_SYSTICK_H_ */
