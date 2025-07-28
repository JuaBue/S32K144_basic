/*
 * =============================================================================
 * File Name    : LED.c
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
//==============================================================================
//                                INCLUDES
//==============================================================================
#include "LED.h"

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
static void led_delayms(int ms);

//==============================================================================
//                       PUBLIC FUNCTION DEFINITIONS
//==============================================================================
void LED_Init(void)
{
    GPIO_PinInit(LED1_IO, GPO, 0);
    GPIO_PinInit(LED2_IO, GPO, 0);
    GPIO_PinInit(LED3_IO, GPO, 0);
    GPIO_PinInit(LED4_IO, GPO, 0);
    GPIO_PinInit(LED5_IO, GPO, 0);
    GPIO_PinInit(LED6_IO, GPO, 0);
}

void LED_ON(uint8_t led)
{
    switch(led) {
      case 1:
        GPIO_PinWrite(LED1_IO,  0);
        break;
      case 2:
        GPIO_PinWrite(LED2_IO,  0);
        break;
      case 3:
        GPIO_PinWrite(LED3_IO,  1);
        break;
      case 4:
        GPIO_PinWrite(LED4_IO,  1);
        break;
      case 5:
        GPIO_PinWrite(LED5_IO,  1);
        break;
      case 6:
        GPIO_PinWrite(LED6_IO,  1);
        break;
      default:
        break;
    }
}

void LED_OFF(uint8_t led)
{
    switch(led) {
      case 1:
        GPIO_PinWrite(LED1_IO, 1);
        break;
      case 2:
        GPIO_PinWrite(LED2_IO, 1);
        break;
      case 3:
        GPIO_PinWrite(LED3_IO, 0);
        break;
      case 4:
        GPIO_PinWrite(LED4_IO, 0);
        break;
      case 5:
        GPIO_PinWrite(LED5_IO, 0);
        break;
      case 6:
        GPIO_PinWrite(LED6_IO, 0);
        break;
      default:
        break;
    }
}

void LED_Reverse(uint8_t led)
{
    switch(led) {
      case 1:
        GPIO_PinReverse(LED1_IO);
        break;
      case 2:
        GPIO_PinReverse(LED2_IO);
        break;
      case 3:
        GPIO_PinReverse(LED3_IO);
        break;
      case 4:
        GPIO_PinReverse(LED4_IO);
        break;
      case 5:
        GPIO_PinReverse(LED5_IO);
        break;
      case 6:
        GPIO_PinReverse(LED6_IO);
        break;
      default:
        break;
    }
}

void Test_LED(void)
{
    uint8_t index = 0U;

    LED_Init();

    while(1)
    {
        for (index = 1U; index <= MAX_LED; index++) {
            if (index == 1U){
                LED_OFF(MAX_LED);
            }
            else {
                LED_OFF(index - 1U);
            }
            LED_ON(index);
            led_delayms(200);
        }

    }
}

//==============================================================================
//                       STATIC FUNCTION DEFINITIONS
//==============================================================================
/* TODO: replace this way to set delay for a timer. */
static void led_delayms(int ms)
{
    volatile uint32_t i = 0;

    while(ms--)
    {
        for (i = 0; i < 10000; ++i) {
            __asm("NOP"); /* delay */
        }
    }
}
