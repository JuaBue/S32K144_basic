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

void DSW_Init(void)
{

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
