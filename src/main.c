/*
 * =============================================================================
 * File Name    : main.c
 * Project      : S32K144_basic
 * Module       : Application Entry Point
 * Author       : JuaBue
 * Created On   : 2025-03-13
 * Version      : 1.0.0
 *
 * Description  :
 *   Entry point for testing and validating all modules within the S32K144_basic
 *   project. This file contains application-level code used to verify GPIO,
 *   LED, UART, KEY input, and PLL functionalities on the NXP S32K144 platform.
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

//==============================================================================
//                         LOCAL DEFINES AND MACROS
//==============================================================================
/* Interrupt Priority Group */
#define NVIC_Group0                    0x07
#define NVIC_Group1                    0x06
#define NVIC_Group2                    0x05
#define NVIC_Group3                    0x04
#define NVIC_Group4                    0x03

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
static void setPriorityGroup(uint32_t PriorityGroup);


//==============================================================================
//                       PUBLIC FUNCTION DEFINITIONS
//==============================================================================
void PORTD_IRQHandler()
{
    uint32_t temp = PORTD->ISFR;
    PORTD->ISFR = 0xFFFFFFFF;

    /* PTD2 */
    if (temp & (1 << 2)) {
        LED_Reverse(3);
    }
    /* PTD3 */
    else if (temp & (1 << 3)) {
        LED_Reverse(6);
        LED_Reverse(4);
    }
    /* PTD4 */
    else if (temp & (1 << 4)) {
        LED_Reverse(5);
    }
    else {
        /* Do nothing */
    }
}

int main(void)
{
    DisableInterrupts;
    SPLL_Init(PLL160);
    UART_Init(LPUART0, 115200);
    NormalRUNmode_80MHz();

    BUZZ_Init();
    systime.init();

    setPriorityGroup(NVIC_Group2);

    printf("---------------------------------------------\n");
    printf("| Test of basic funtionalities with S32K144 |\n");
    printf("---------------------------------------------\n");
    EnableInterrupts;


    /* Initial example to check the notes */
    BUZZ_playNote('C', 150);
    delay(1000);
    BUZZ_playNote('E', 150);
    delay(1000);

    /* Play the song */
    BUZZ_MainTask();

    return 0;
}

//==============================================================================
//                       STATIC FUNCTION DEFINITIONS
//==============================================================================

static void setPriorityGroup(uint32_t PriorityGroup)
{
    uint32_t reg_value;

    reg_value = S32_SCB->AIRCR;
    reg_value &= ~((S32_SCB_AIRCR_VECTKEY_MASK << S32_SCB_AIRCR_VECTKEY_SHIFT) |
                   (S32_SCB_AIRCR_PRIGROUP_MASK << S32_SCB_AIRCR_VECTKEY_SHIFT));
    reg_value = (reg_value | ((uint32_t)0x5FA << S32_SCB_AIRCR_VECTKEY_SHIFT) |
                (PriorityGroup << 8U));
    S32_SCB->AIRCR = reg_value;
}
