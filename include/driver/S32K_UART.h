/*
 * =============================================================================
 * File Name    : S32K_UART.h
 * Project      : S32K144_basic
 * Module       : UART Communication Module (Header)
 * Author       : JuaBue
 * Created On   : 2025-03-22
 * Version      : 1.0.0
 *
 * Description  :
 *   This header file declares functions and macros for configuring and using
 *   the UART (LPUART) peripherals of the NXP S32K144 microcontroller. It supports
 *   initialization, data transmission, and reception through UART0, UART1, and
 *   UART2.
 *
 *   UART pin mappings:
 *     - UART0_RX : PTB0   | UART0_TX : PTB1
 *     - UART1_RX : PTC8   | UART1_TX : PTC9
 *     - UART2_RX : PTA8   | UART2_TX : PTA9
 *
 *   All UARTs operate with 8 data bits, 1 stop bit, and no parity (8N1).
 *
 * Dependencies :
 *   - GPIO configuration (via UART_PinInit)
 *   - PLL configuration (via S32K_PLL.h)
 *
 * Configuration :
 *   - Baud rate must be passed by the user
 *   - Ensure system clock and PLL are configured before UART_Init()
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

#ifndef __S32K_UART_H__
#define __S32K_UART_H__

//==============================================================================
//                               INCLUDES
//==============================================================================
#include "include.h"
#include "S32K_PLL.h"

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================
/*               UART          */
//      channel     port       options
#define UART0_RX    PTB0       //PTA2 PTB0 PTC2
#define UART0_TX    PTB1       //PTA3 PTB1 PTC3

#define UART1_RX    PTC8       //PTC6 PTC8 PTD13
#define UART1_TX    PTC9       //PTC7 PTC9 PTD14

#define UART2_RX    PTA8       //PTD6 PTD17 PTA8
#define UART2_TX    PTA9       //PTD7 PTE12 PTA9

//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================

//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================
/*
 * @brief: Initialize IO Port
 * @param: LPUART0, LPUART1, LPUART2
 */
void UART_PinInit(LPUART_Type *base);

/*
 * @brief: Initialize serial port
 * @param: base, LPUART0, LPUART1, LPUART2
 * @param: baud: frequency
 * @note: 81N
 */
void UART_Init (LPUART_Type *base, uint32 baud);

/*
 * @brief: Send char via UART
 * @param: base, LPUART0, LPUART1, LPUART2
 * @param: chr, char to send
 */
void UART_PutChar(LPUART_Type *base, uint8_t chr);

/*
 * @brief: Send buffer via UART
 * @param: base, LPUART0, LPUART1, LPUART2
 * @param: buff, pointer to buffer
 * @param: len, length
 */
void UART_PutBuff(LPUART_Type *base, uint8_t *buff, uint32_t len);

/*
 * @brief: Send string via UART
 * @param: base, LPUART0, LPUART1, LPUART2
 * @param: str, pointer to string
 */
void UART_PutStr(LPUART_Type *base, uint8_t *str);

/*
 * @brief: receive a char
 * @param: base, LPUART0, LPUART1, LPUART2
 */
uint8_t UART_GetChar(LPUART_Type *base);


#endif // __S32K_UART_H__
