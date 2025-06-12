/*
 * LED.c
 *
 *  Created on: 11 jun. 2025
 *      Author: Usuario
 */

#include "include.h"
#include "LED.h"
#include "S32K_GPIO.h"

static void led_delayms(int ms);


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
