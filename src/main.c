/*
 * main implementation: use this 'C' sample to create your own application
 *
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
        LED_Reverse(4);
    }
    /* PTD3 */
    else if (temp & (1 << 3)) {
        LED_Reverse(6);
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
    SPLL_Init(PLL160);
    UART_Init(LPUART0, 115200);

    printf("This is my first test with S32K144\r\n");

    setPriorityGroup(NVIC_Group2);

    Test_KEYint();

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
