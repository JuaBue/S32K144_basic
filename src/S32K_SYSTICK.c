/*
 * =============================================================================
 * File Name    : S32K_SYSTICK.c
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

//==============================================================================
//                                INCLUDES
//==============================================================================
#include "include.h"
#include "S32K_SYSTICK.h"

//==============================================================================
//                         LOCAL DEFINES AND MACROS
//==============================================================================
#define EACH_PER_MS                    25  //Interrupt every 25 ms. The systick timer is a 24-bit down-counting timer.
#define NUM_PI_BITS                    4U

//==============================================================================
//                       LOCAL TYPES AND ENUMERATIONS
//==============================================================================
struct time {
    uint32_t fac_us;                    // us division coefficient
    uint32_t fac_ms;                    // ms division coefficient
    volatile uint32_t millisecond;      // ms
    uint8_t ms_per_tick;                // How many systick counts per 1ms
} timer;

//==============================================================================
//                          STATIC VARIABLES
//==============================================================================

//==============================================================================
//                      STATIC FUNCTION DECLARATIONS
//==============================================================================
static inline uint32_t systime_get_current_time_ms(void);
static inline uint64_t systime_get_current_time_us(void);

//==============================================================================
//                       PUBLIC FUNCTION DEFINITIONS
//==============================================================================
void systime_init(void)
{
    uint32_t ticks;
    const uint32_t priority = 0xFU;

    timer.fac_us = bus_clk_M;
    timer.fac_ms = bus_clk_M * 1000;
    timer.ms_per_tick = EACH_PER_MS;
    timer.millisecond = 100;
    ticks = timer.fac_ms * timer.ms_per_tick;
    /* Enable Systick interrupt */
    if (ticks <= S32_SysTick_RVR_RELOAD_MASK) {
        /* set reload register */
        S32_SysTick->RVR = (ticks & (S32_SysTick_RVR_RELOAD_MASK <<
                            S32_SysTick_RVR_RELOAD_SHIFT)) - 1;
        /* Set priority interrupts */
        S32_NVIC->IP[(uint32_t)SysTick_IRQn] = ((priority << (8U - NUM_PI_BITS)) & 0xFF);
        /* Load the SysTick Counter Value */
        S32_SysTick->CVR = 0U;
        /* Enable SysTick IRQ and SysTick Timer */
        S32_SysTick->CSR = S32_SysTick_CSR_CLKSOURCE_MASK |
                           S32_SysTick_CSR_TICKINT_MASK |
                           S32_SysTick_CSR_ENABLE_MASK;
    }
}

void systime_delay_us(uint32_t us)
{
    uint64_t end_time = systime.get_time_us() + us;
    while((int64_t)(systime.get_time_us() - end_time) < 0);
}

void systime_delay_ms(uint32_t ms)
{
    systime.delay_us(ms * 1000);
}

void SysTick_Handler(void)
{
    /* For every interrupt increment the number of ms */
    timer.millisecond += timer.ms_per_tick;
}

//==============================================================================
//                           GLOBAL VARIABLES
//==============================================================================
systime_t systime =
{
    systime_init,
    systime_get_current_time_us,
    systime_get_current_time_ms,
    systime_delay_us,
    systime_delay_ms
};

//==============================================================================
//                       STATIC FUNCTION DEFINITIONS
//==============================================================================
static inline uint32_t systime_get_current_time_ms(void)
{
    return timer.millisecond - (S32_SysTick->CVR)/timer.fac_ms;
}

static inline uint64_t systime_get_current_time_us(void)
{
    return (uint64_t)(((uint64_t)timer.millisecond * 1000) - (S32_SysTick->CVR) / timer.fac_us);
}



