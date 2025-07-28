/*
 * =============================================================================
 * File Name    : S32K_GPIO.c
 * Project      : S32K144_basic
 * Module       : GPIO Control Module (Header)
 * Author       : JuaBue
 * Created On   : 2025-03-30
 * Version      : 1.0.0
 *
 * Description  :
 *   This header file provides enumerations, macros, and function declarations
 *   for configuring and controlling GPIO ports on the NXP S32K144 microcontroller.
 *   It supports flexible input/output settings, passive filters, pull-up/down
 *   configurations, and interrupt trigger modes.
 *
 *   Main features:
 *     - Configurable GPIO direction (input/output)
 *     - Support for passive filters, pull-up/down resistors
 *     - External interrupt trigger configuration (edge/level)
 *     - Bit-level, byte-level, and word-level pin control
 *     - Input/output direction configuration macros
 *
 * Dependencies :
 *   - MCU register definitions for GPIOx and PORTx
 *
 * Configuration :
 *   - Ensure that the system clock and GPIO modules are initialized prior to use
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
#include "S32K_GPIO.h"

//==============================================================================
//                         LOCAL DEFINES AND MACROS
//==============================================================================

//==============================================================================
//                       LOCAL TYPES AND ENUMERATIONS
//==============================================================================

//==============================================================================
//                           GLOBAL VARIABLES
//==============================================================================
/* Define five pointer arrays to save the address of GPIOX */
GPIO_MemMapPtr GPIOX[5] = {PTA,    PTB,   PTC,   PTD,   PTE};
PORT_MemMapPtr PORTX[5] = {PORTA,  PORTB, PORTC, PORTD, PORTE};

//==============================================================================
//                          STATIC VARIABLES
//==============================================================================

//==============================================================================
//                      STATIC FUNCTION DECLARATIONS
//==============================================================================

//==============================================================================
//                       PUBLIC FUNCTION DEFINITIONS
//==============================================================================
void GPIO_PinInit(PTXn_e ptx_n, GPIO_CFG dir, uint8_t data)
{
    uint8_t ptx, ptn;

    ptx = PTX(ptx_n);
    ptn = PTn(ptx_n);

    // 1. Enable port clock
    PCC->PCCn[PCC_PORTA_INDEX + ptx] = PCC_PCCn_CGC_MASK;

    // 2. Clear the previous Pin Mux Control
    PORTX[ptx]->PCR[ptn] &= ~(uint32)PORT_PCR_MUX_MASK;

    // 3. Set Pin Mux Control function to GPIO, i.e. normal IO port
    PORTX[ptx]->PCR[ptn] |= PORT_PCR_MUX(1);

    // 4. Set GPIO direction
    if (dir) {
        GPIOX[ptx]->PDDR |= (uint32_t)(1 << ptn);
    }
    else {
        GPIOX[ptx]->PDDR &= ~(uint32_t)(1 << ptn);
    }

    // 5. Set the default port status
    if (data) {
        GPIOX[ptx]->PDOR |= (uint32_t)(1 << ptn);
    }
    else {
        GPIOX[ptx]->PDOR &= ~(uint32_t)(1 << ptn);
    }

}


void GPIO_PinSetDir(PTXn_e ptx_n, bool input)
{
    uint8_t ptx, ptn;

    ptx = PTX(ptx_n);
    ptn = PTn(ptx_n);

    /* Set GPIO dir */
    if (input) {
        GPIOX[ptx]->PDDR |= (uint32_t)(1 << ptn);
    }
    else {
        GPIOX[ptx]->PDDR &= ~(uint32_t)(1 << ptn);
    }

}


void GPIO_PinWrite(PTXn_e ptx_n, uint8_t data)
{
    uint8_t ptx, ptn;

    ptx = PTX(ptx_n);
    ptn = PTn(ptx_n);

    if (data) {
        GPIOX[ptx]->PDOR |= (uint32_t)(1 << ptn);
    }
    else {
        GPIOX[ptx]->PDOR &= ~(uint32_t)(1 << ptn);
    }

}


void GPIO_PinReverse(PTXn_e ptx_n)
{
    uint8_t ptx,ptn;

    ptx = PTX(ptx_n);
    ptn = PTn(ptx_n);

    /* Toggle output register */
    GPIOX[ptx]->PTOR ^= (1<<ptn);
}


uint8_t GPIO_PinRead(PTXn_e ptx_n)
{
    uint8_t ptx, ptn;

    ptx = PTX(ptx_n);
    ptn = PTn(ptx_n);

    /* Read the PDIR register */
    return ((GPIOX[ptx]->PDIR >> ptn) & 0x1);
}


void GPIO_PortPull(PTXn_e ptx_n, bool pullup_ena)
{
    uint8_t ptx, ptn;

    ptx = PTX(ptx_n);
    ptn = PTn(ptx_n);

    /* Configuring Port Functions */
    PORTX[ptx]->PCR[ptn] |= PORT_PCR_MUX(1);

    /* Enable or disable the pull-up */
    if (pullup_ena) {
        PORTX[ptx]->PCR[ptn] |= PORT_PCR_PE_MASK;
    }
    else {
        PORTX[ptx]->PCR[ptn] &= ~PORT_PCR_PE_MASK;
    }

}

void GPIO_ExtiInit(PTXn_e ptx_n, exti_cfg cfg)
{
    uint8_t ptx,ptn;

    ptx = PTX(ptx_n);
    ptn = PTn(ptx_n);

    /* Enable port clock */
    PCC->PCCn[PCC_PORTA_INDEX + ptx] = PCC_PCCn_CGC_MASK;

    /* Clear interrupt flag */
    PORTX[ptx]->ISFR = (uint32_t)(1 << ptn);

    /* Configuring Port Functions */
    PORTX[ptx]->PCR[ptn] = PORT_PCR_MUX(1) | PORT_PCR_IRQC(cfg & 0x7f ) | PORT_PCR_PE_MASK | ((cfg & 0x80 ) >> 7);

    /* Set the port to input */
    GPIOX[ptx]->PDDR &= ~(uint32_t)(1 << ptn);
}
