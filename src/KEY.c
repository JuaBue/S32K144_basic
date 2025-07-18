/*
 * KEY.c
 *
 *  Created on: 12 jun. 2025
 *      Author: Usuario
 */

#include "include.h"


/* Button pin definitions */
#define KEYA_IO                        PTD2
#define KEYB_IO                        PTD4
#define KEYC_IO                        PTD3

#define KEY_NOPRESS                    1U
#define KEY_PRESS                      0U

#define NUM_PI_BITS                    4U // S32K144 has 4 bits for priority
#define PREEM_PI_VALUE                 1U
#define SUB_PI_VALUE                   2U

static void key_delayms(int ms);

void KEY_Init(void)
{
    GPIO_PinInit(KEYA_IO, GPI, 1);
    GPIO_PinInit(KEYB_IO, GPI, 1);
    GPIO_PinInit(KEYA_IO, GPI, 1);
}

KeyStatus_types KEY_Read(Mode_types mode, Key_types key)
{
    const uint8_t keys[4] = {0, KEYA_IO, KEYB_IO, KEYC_IO};
    const KeyStatus_types press[4] = { KSTATUS_NOPRESS, KSTATUS_B1_PRESS,
                                      KSTATUS_B2_PRESS, KSTATUS_B3_PRESS };
    static uint8_t pressKey[4] = { KEY_NOPRESS, KEY_NOPRESS, KEY_NOPRESS,
                                   KEY_NOPRESS };
    uint8_t readPin = KEY_NOPRESS;
    KeyStatus_types keyStatus = KSTATUS_NOPRESS;

    if ((key > KEY_NA) && (key < KEY_MAX)) {
        if (MODE_CONT == mode) {
            /* To support the continuous mode reset the pressKey value */
            pressKey[key] = KEY_NOPRESS;
        }

        readPin = GPIO_PinRead(keys[key]);
        if (KEY_PRESS == readPin) {
            if (KEY_NOPRESS == pressKey[key]) {
                /* Debounce time of 10ms */
                key_delayms(10);
                pressKey[key] = KEY_PRESS;
                readPin = GPIO_PinRead(keys[key]);
                if (KEY_PRESS == readPin) {
                    keyStatus = press[key];
                }
                else {
                    keyStatus = KSTATUS_NOPRESS;
                }
            }
        }
        else {
            pressKey[key] = KEY_NOPRESS;
            keyStatus = KSTATUS_NOPRESS;
        }
    }
    else {
        pressKey[key] = KEY_NOPRESS;
        keyStatus = KSTATUS_NOPRESS;
    }

    return keyStatus;
}

void Test_KEY(void)
{
    LED_Init();
    KEY_Init();
    uint8_t index = 1U;

    while(1)
    {
        if (KEY_Read(MODE_CONT, KEY_A) || KEY_Read(MODE_NOCONT, KEY_B))
        {
            if (index > MAX_LED) {
                index = 1;
            }
            LED_Reverse(index);
            index++;
        }

        key_delayms(50);
    }

}

void Test_KEYint(void)
{
    LED_Init();
    uint32_t priority;
    uint32_t priorityGroup;
    uint32_t preemptPriority = PREEM_PI_VALUE;
    uint32_t preemptPriorityBits;
    uint32_t subPriority = SUB_PI_VALUE;
    uint32_t subPriorityBits;

    /* Configuration button interrupt with "Falling edge triggered, internal pull-up" */
    GPIO_ExtiInit(KEYA_IO, falling_up);
    GPIO_ExtiInit(KEYB_IO, falling_up);
    GPIO_ExtiInit(KEYC_IO, falling_up);

    /* Priority Configuration:  */
    priorityGroup = ((S32_SCB->AIRCR & S32_SCB_AIRCR_PRIGROUP_MASK) >> S32_SCB_AIRCR_PRIGROUP_SHIFT);

    /* Maximum value for PRIGROUP */
    if (priorityGroup > NUM_PI_BITS) {
        priorityGroup = NUM_PI_BITS;
    }

    /* Set the number of bits for every field */
    preemptPriorityBits = priorityGroup;
    subPriorityBits = NUM_PI_BITS - priorityGroup;

    /* Set mask to avoid overload */
    preemptPriority &= ((1U << preemptPriorityBits) - 1U);
    subPriority &= ((1U << subPriorityBits) - 1U);

    /* Encode priority */
    priority = (preemptPriority << subPriorityBits) | subPriority;

    /* Set Priority for device specific Interrupts */
    S32_NVIC->IP[(uint32_t)PORTD_IRQn] = ((priority << (8U - NUM_PI_BITS)) & 0xFF);

    /* Enable interrupt for PORTD_IRQn */
    S32_NVIC->ISER[(uint32_t)(PORTD_IRQn) >> 5] = (1U << ((uint32_t)(PORTD_IRQn) & 0x1F));

    /* Infinite loop */
    while(1);
}

/* TODO: replace this way to set delay for a timer. */
static void key_delayms(int ms)
{
    volatile uint32_t i = 0;

    while(ms--)
    {
        for (i = 0; i < 10000; ++i) {
            __asm("NOP"); /* delay */
        }
    }
}
