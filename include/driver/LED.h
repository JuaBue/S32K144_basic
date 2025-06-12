/*
 * LED.h
 *
 *  Created on: 11 jun. 2025
 *      Author: Juan.Bueno
 */

#ifndef LED_H_
#define LED_H_

#define LED1_IO             PTC17   // Core board LED
#define LED2_IO             PTD17
#define LED3_IO             PTA11   // Expansion board LED
#define LED4_IO             PTA12
#define LED5_IO             PTA13
#define LED6_IO             PTA14

#define MAX_LED             6U

/*
 * @brief LED Initialization
 */
void LED_Init(void);

/*
 * @brief: Turn on LED
 * @param: led: number of LED
 */
void LED_ON(uint8_t led);

/*
 * @brief: Turn off LED
 * @param: led: number of LED
 */
void LED_OFF(uint8_t led);

/*
 * @brief: Flip LED
 * @param: led: number of LED
 */
void LED_Reverse(uint8_t led);

/*
 * @brief: Test Routine LED
 */
void Test_LED(void);

#endif /* LED_H_ */
