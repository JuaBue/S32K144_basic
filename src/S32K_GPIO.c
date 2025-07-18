/*
 * S32K_GPIO.c
 *
 *  Created on: 31 mar. 2025
 *      Author: Juan.Bueno
 */
#include "include.h"
#include "S32K_GPIO.h"

/* Define five pointer arrays to save the address of GPIOX */
GPIO_MemMapPtr GPIOX[5] = {PTA,    PTB,   PTC,   PTD,   PTE};
PORT_MemMapPtr PORTX[5] = {PORTA,  PORTB, PORTC, PORTD, PORTE};

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
