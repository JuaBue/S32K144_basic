/*
 * =============================================================================
 * File Name    : S32K_GPIO.h
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
#ifndef S32K_GPIO_H_
#define S32K_GPIO_H_

//==============================================================================
//                               INCLUDES
//==============================================================================
#include "include.h"

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================

#define GPIOX_BASE(PTxn)    GPIOX[PTX(PTxn)] // GPIO module address
#define PORTX_BASE(PTxn)    PORTX[PTX(PTxn)] // PORT module address

/* Bit operation macro definition */
/* Define the port of PTA */
#define PTA0_OUT     PTA_BASE_PTR->PDORs.PDOR0
#define PTA1_OUT     PTA_BASE_PTR->PDORs.PDOR1
#define PTA2_OUT     PTA_BASE_PTR->PDORs.PDOR2
#define PTA3_OUT     PTA_BASE_PTR->PDORs.PDOR3
#define PTA4_OUT     PTA_BASE_PTR->PDORs.PDOR4
#define PTA5_OUT     PTA_BASE_PTR->PDORs.PDOR5
#define PTA6_OUT     PTA_BASE_PTR->PDORs.PDOR6
#define PTA7_OUT     PTA_BASE_PTR->PDORs.PDOR7
#define PTA8_OUT     PTA_BASE_PTR->PDORs.PDOR8
#define PTA9_OUT     PTA_BASE_PTR->PDORs.PDOR9
#define PTA10_OUT    PTA_BASE_PTR->PDORs.PDOR10
#define PTA11_OUT    PTA_BASE_PTR->PDORs.PDOR11
#define PTA12_OUT    PTA_BASE_PTR->PDORs.PDOR12
#define PTA13_OUT    PTA_BASE_PTR->PDORs.PDOR13
#define PTA14_OUT    PTA_BASE_PTR->PDORs.PDOR14
#define PTA15_OUT    PTA_BASE_PTR->PDORs.PDOR15
#define PTA16_OUT    PTA_BASE_PTR->PDORs.PDOR16
#define PTA17_OUT    PTA_BASE_PTR->PDORs.PDOR17
#define PTA18_OUT    PTA_BASE_PTR->PDORs.PDOR18
#define PTA19_OUT    PTA_BASE_PTR->PDORs.PDOR19
#define PTA20_OUT    PTA_BASE_PTR->PDORs.PDOR20
#define PTA21_OUT    PTA_BASE_PTR->PDORs.PDOR21
#define PTA22_OUT    PTA_BASE_PTR->PDORs.PDOR22
#define PTA23_OUT    PTA_BASE_PTR->PDORs.PDOR23
#define PTA24_OUT    PTA_BASE_PTR->PDORs.PDOR24
#define PTA25_OUT    PTA_BASE_PTR->PDORs.PDOR25
#define PTA26_OUT    PTA_BASE_PTR->PDORs.PDOR26
#define PTA27_OUT    PTA_BASE_PTR->PDORs.PDOR27
#define PTA28_OUT    PTA_BASE_PTR->PDORs.PDOR28
#define PTA29_OUT    PTA_BASE_PTR->PDORs.PDOR29
#define PTA30_OUT    PTA_BASE_PTR->PDORs.PDOR30
#define PTA31_OUT    PTA_BASE_PTR->PDORs.PDOR31

/* Define the port of PTB */
#define PTB0_OUT     PTB_BASE_PTR->PDORs.PDOR0
#define PTB1_OUT     PTB_BASE_PTR->PDORs.PDOR1
#define PTB2_OUT     PTB_BASE_PTR->PDORs.PDOR2
#define PTB3_OUT     PTB_BASE_PTR->PDORs.PDOR3
#define PTB4_OUT     PTB_BASE_PTR->PDORs.PDOR4
#define PTB5_OUT     PTB_BASE_PTR->PDORs.PDOR5
#define PTB6_OUT     PTB_BASE_PTR->PDORs.PDOR6
#define PTB7_OUT     PTB_BASE_PTR->PDORs.PDOR7
#define PTB8_OUT     PTB_BASE_PTR->PDORs.PDOR8
#define PTB9_OUT     PTB_BASE_PTR->PDORs.PDOR9
#define PTB10_OUT    PTB_BASE_PTR->PDORs.PDOR10
#define PTB11_OUT    PTB_BASE_PTR->PDORs.PDOR11
#define PTB12_OUT    PTB_BASE_PTR->PDORs.PDOR12
#define PTB13_OUT    PTB_BASE_PTR->PDORs.PDOR13
#define PTB14_OUT    PTB_BASE_PTR->PDORs.PDOR14
#define PTB15_OUT    PTB_BASE_PTR->PDORs.PDOR15
#define PTB16_OUT    PTB_BASE_PTR->PDORs.PDOR16
#define PTB17_OUT    PTB_BASE_PTR->PDORs.PDOR17
#define PTB18_OUT    PTB_BASE_PTR->PDORs.PDOR18
#define PTB19_OUT    PTB_BASE_PTR->PDORs.PDOR19
#define PTB20_OUT    PTB_BASE_PTR->PDORs.PDOR20
#define PTB21_OUT    PTB_BASE_PTR->PDORs.PDOR21
#define PTB22_OUT    PTB_BASE_PTR->PDORs.PDOR22
#define PTB23_OUT    PTB_BASE_PTR->PDORs.PDOR23
#define PTB24_OUT    PTB_BASE_PTR->PDORs.PDOR24
#define PTB25_OUT    PTB_BASE_PTR->PDORs.PDOR25
#define PTB26_OUT    PTB_BASE_PTR->PDORs.PDOR26
#define PTB27_OUT    PTB_BASE_PTR->PDORs.PDOR27
#define PTB28_OUT    PTB_BASE_PTR->PDORs.PDOR28
#define PTB29_OUT    PTB_BASE_PTR->PDORs.PDOR29
#define PTB30_OUT    PTB_BASE_PTR->PDORs.PDOR30
#define PTB31_OUT    PTB_BASE_PTR->PDORs.PDOR31

/* Define the port of PTC */
#define PTC0_OUT     PTC_BASE_PTR->PDORs.PDOR0
#define PTC1_OUT     PTC_BASE_PTR->PDORs.PDOR1
#define PTC2_OUT     PTC_BASE_PTR->PDORs.PDOR2
#define PTC3_OUT     PTC_BASE_PTR->PDORs.PDOR3
#define PTC4_OUT     PTC_BASE_PTR->PDORs.PDOR4
#define PTC5_OUT     PTC_BASE_PTR->PDORs.PDOR5
#define PTC6_OUT     PTC_BASE_PTR->PDORs.PDOR6
#define PTC7_OUT     PTC_BASE_PTR->PDORs.PDOR7
#define PTC8_OUT     PTC_BASE_PTR->PDORs.PDOR8
#define PTC9_OUT     PTC_BASE_PTR->PDORs.PDOR9
#define PTC10_OUT    PTC_BASE_PTR->PDORs.PDOR10
#define PTC11_OUT    PTC_BASE_PTR->PDORs.PDOR11
#define PTC12_OUT    PTC_BASE_PTR->PDORs.PDOR12
#define PTC13_OUT    PTC_BASE_PTR->PDORs.PDOR13
#define PTC14_OUT    PTC_BASE_PTR->PDORs.PDOR14
#define PTC15_OUT    PTC_BASE_PTR->PDORs.PDOR15
#define PTC16_OUT    PTC_BASE_PTR->PDORs.PDOR16
#define PTC17_OUT    PTC_BASE_PTR->PDORs.PDOR17
#define PTC18_OUT    PTC_BASE_PTR->PDORs.PDOR18
#define PTC19_OUT    PTC_BASE_PTR->PDORs.PDOR19
#define PTC20_OUT    PTC_BASE_PTR->PDORs.PDOR20
#define PTC21_OUT    PTC_BASE_PTR->PDORs.PDOR21
#define PTC22_OUT    PTC_BASE_PTR->PDORs.PDOR22
#define PTC23_OUT    PTC_BASE_PTR->PDORs.PDOR23
#define PTC24_OUT    PTC_BASE_PTR->PDORs.PDOR24
#define PTC25_OUT    PTC_BASE_PTR->PDORs.PDOR25
#define PTC26_OUT    PTC_BASE_PTR->PDORs.PDOR26
#define PTC27_OUT    PTC_BASE_PTR->PDORs.PDOR27
#define PTC28_OUT    PTC_BASE_PTR->PDORs.PDOR28
#define PTC29_OUT    PTC_BASE_PTR->PDORs.PDOR29
#define PTC30_OUT    PTC_BASE_PTR->PDORs.PDOR30
#define PTC31_OUT    PTC_BASE_PTR->PDORs.PDOR31

/* Define the port of PTD */
#define PTD0_OUT     PTD_BASE_PTR->PDORs.PDOR0
#define PTD1_OUT     PTD_BASE_PTR->PDORs.PDOR1
#define PTD2_OUT     PTD_BASE_PTR->PDORs.PDOR2
#define PTD3_OUT     PTD_BASE_PTR->PDORs.PDOR3
#define PTD4_OUT     PTD_BASE_PTR->PDORs.PDOR4
#define PTD5_OUT     PTD_BASE_PTR->PDORs.PDOR5
#define PTD6_OUT     PTD_BASE_PTR->PDORs.PDOR6
#define PTD7_OUT     PTD_BASE_PTR->PDORs.PDOR7
#define PTD8_OUT     PTD_BASE_PTR->PDORs.PDOR8
#define PTD9_OUT     PTD_BASE_PTR->PDORs.PDOR9
#define PTD10_OUT    PTD_BASE_PTR->PDORs.PDOR10
#define PTD11_OUT    PTD_BASE_PTR->PDORs.PDOR11
#define PTD12_OUT    PTD_BASE_PTR->PDORs.PDOR12
#define PTD13_OUT    PTD_BASE_PTR->PDORs.PDOR13
#define PTD14_OUT    PTD_BASE_PTR->PDORs.PDOR14
#define PTD15_OUT    PTD_BASE_PTR->PDORs.PDOR15
#define PTD16_OUT    PTD_BASE_PTR->PDORs.PDOR16
#define PTD17_OUT    PTD_BASE_PTR->PDORs.PDOR17
#define PTD18_OUT    PTD_BASE_PTR->PDORs.PDOR18
#define PTD19_OUT    PTD_BASE_PTR->PDORs.PDOR19
#define PTD20_OUT    PTD_BASE_PTR->PDORs.PDOR20
#define PTD21_OUT    PTD_BASE_PTR->PDORs.PDOR21
#define PTD22_OUT    PTD_BASE_PTR->PDORs.PDOR22
#define PTD23_OUT    PTD_BASE_PTR->PDORs.PDOR23
#define PTD24_OUT    PTD_BASE_PTR->PDORs.PDOR24
#define PTD25_OUT    PTD_BASE_PTR->PDORs.PDOR25
#define PTD26_OUT    PTD_BASE_PTR->PDORs.PDOR26
#define PTD27_OUT    PTD_BASE_PTR->PDORs.PDOR27
#define PTD28_OUT    PTD_BASE_PTR->PDORs.PDOR28
#define PTD29_OUT    PTD_BASE_PTR->PDORs.PDOR29
#define PTD30_OUT    PTD_BASE_PTR->PDORs.PDOR30
#define PTD31_OUT    PTD_BASE_PTR->PDORs.PDOR31

/* Define the port of PTE */
#define PTE0_OUT     PTE_BASE_PTR->PDORs.PDOR0
#define PTE1_OUT     PTE_BASE_PTR->PDORs.PDOR1
#define PTE2_OUT     PTE_BASE_PTR->PDORs.PDOR2
#define PTE3_OUT     PTE_BASE_PTR->PDORs.PDOR3
#define PTE4_OUT     PTE_BASE_PTR->PDORs.PDOR4
#define PTE5_OUT     PTE_BASE_PTR->PDORs.PDOR5
#define PTE6_OUT     PTE_BASE_PTR->PDORs.PDOR6
#define PTE7_OUT     PTE_BASE_PTR->PDORs.PDOR7
#define PTE8_OUT     PTE_BASE_PTR->PDORs.PDOR8
#define PTE9_OUT     PTE_BASE_PTR->PDORs.PDOR9
#define PTE10_OUT    PTE_BASE_PTR->PDORs.PDOR10
#define PTE11_OUT    PTE_BASE_PTR->PDORs.PDOR11
#define PTE12_OUT    PTE_BASE_PTR->PDORs.PDOR12
#define PTE13_OUT    PTE_BASE_PTR->PDORs.PDOR13
#define PTE14_OUT    PTE_BASE_PTR->PDORs.PDOR14
#define PTE15_OUT    PTE_BASE_PTR->PDORs.PDOR15
#define PTE16_OUT    PTE_BASE_PTR->PDORs.PDOR16
#define PTE17_OUT    PTE_BASE_PTR->PDORs.PDOR17
#define PTE18_OUT    PTE_BASE_PTR->PDORs.PDOR18
#define PTE19_OUT    PTE_BASE_PTR->PDORs.PDOR19
#define PTE20_OUT    PTE_BASE_PTR->PDORs.PDOR20
#define PTE21_OUT    PTE_BASE_PTR->PDORs.PDOR21
#define PTE22_OUT    PTE_BASE_PTR->PDORs.PDOR22
#define PTE23_OUT    PTE_BASE_PTR->PDORs.PDOR23
#define PTE24_OUT    PTE_BASE_PTR->PDORs.PDOR24
#define PTE25_OUT    PTE_BASE_PTR->PDORs.PDOR25
#define PTE26_OUT    PTE_BASE_PTR->PDORs.PDOR26
#define PTE27_OUT    PTE_BASE_PTR->PDORs.PDOR27
#define PTE28_OUT    PTE_BASE_PTR->PDORs.PDOR28
#define PTE29_OUT    PTE_BASE_PTR->PDORs.PDOR29
#define PTE30_OUT    PTE_BASE_PTR->PDORs.PDOR30
#define PTE31_OUT    PTE_BASE_PTR->PDORs.PDOR31

/* Define the input and output direction of PTA */
#define DDRA0       PTA_BASE_PTR->DDRs.DDR0
#define DDRA1       PTA_BASE_PTR->DDRs.DDR1
#define DDRA2       PTA_BASE_PTR->DDRs.DDR2
#define DDRA3       PTA_BASE_PTR->DDRs.DDR3
#define DDRA4       PTA_BASE_PTR->DDRs.DDR4
#define DDRA5       PTA_BASE_PTR->DDRs.DDR5
#define DDRA6       PTA_BASE_PTR->DDRs.DDR6
#define DDRA7       PTA_BASE_PTR->DDRs.DDR7
#define DDRA8       PTA_BASE_PTR->DDRs.DDR8
#define DDRA9       PTA_BASE_PTR->DDRs.DDR9
#define DDRA10      PTA_BASE_PTR->DDRs.DDR10
#define DDRA11      PTA_BASE_PTR->DDRs.DDR11
#define DDRA12      PTA_BASE_PTR->DDRs.DDR12
#define DDRA13      PTA_BASE_PTR->DDRs.DDR13
#define DDRA14      PTA_BASE_PTR->DDRs.DDR14
#define DDRA15      PTA_BASE_PTR->DDRs.DDR15
#define DDRA16      PTA_BASE_PTR->DDRs.DDR16
#define DDRA17      PTA_BASE_PTR->DDRs.DDR17
#define DDRA18      PTA_BASE_PTR->DDRs.DDR18
#define DDRA19      PTA_BASE_PTR->DDRs.DDR19
#define DDRA20      PTA_BASE_PTR->DDRs.DDR20
#define DDRA21      PTA_BASE_PTR->DDRs.DDR21
#define DDRA22      PTA_BASE_PTR->DDRs.DDR22
#define DDRA23      PTA_BASE_PTR->DDRs.DDR23
#define DDRA24      PTA_BASE_PTR->DDRs.DDR24
#define DDRA25      PTA_BASE_PTR->DDRs.DDR25
#define DDRA26      PTA_BASE_PTR->DDRs.DDR26
#define DDRA27      PTA_BASE_PTR->DDRs.DDR27
#define DDRA28      PTA_BASE_PTR->DDRs.DDR28
#define DDRA29      PTA_BASE_PTR->DDRs.DDR29
#define DDRA30      PTA_BASE_PTR->DDRs.DDR30
#define DDRA31      PTA_BASE_PTR->DDRs.DDR31

/* Define the input and output direction of PTB */
#define DDRB0       PTB_BASE_PTR->DDRs.DDR0
#define DDRB1       PTB_BASE_PTR->DDRs.DDR1
#define DDRB2       PTB_BASE_PTR->DDRs.DDR2
#define DDRB3       PTB_BASE_PTR->DDRs.DDR3
#define DDRB4       PTB_BASE_PTR->DDRs.DDR4
#define DDRB5       PTB_BASE_PTR->DDRs.DDR5
#define DDRB6       PTB_BASE_PTR->DDRs.DDR6
#define DDRB7       PTB_BASE_PTR->DDRs.DDR7
#define DDRB8       PTB_BASE_PTR->DDRs.DDR8
#define DDRB9       PTB_BASE_PTR->DDRs.DDR9
#define DDRB10      PTB_BASE_PTR->DDRs.DDR10
#define DDRB11      PTB_BASE_PTR->DDRs.DDR11
#define DDRB12      PTB_BASE_PTR->DDRs.DDR12
#define DDRB13      PTB_BASE_PTR->DDRs.DDR13
#define DDRB14      PTB_BASE_PTR->DDRs.DDR14
#define DDRB15      PTB_BASE_PTR->DDRs.DDR15
#define DDRB16      PTB_BASE_PTR->DDRs.DDR16
#define DDRB17      PTB_BASE_PTR->DDRs.DDR17
#define DDRB18      PTB_BASE_PTR->DDRs.DDR18
#define DDRB19      PTB_BASE_PTR->DDRs.DDR19
#define DDRB20      PTB_BASE_PTR->DDRs.DDR20
#define DDRB21      PTB_BASE_PTR->DDRs.DDR21
#define DDRB22      PTB_BASE_PTR->DDRs.DDR22
#define DDRB23      PTB_BASE_PTR->DDRs.DDR23
#define DDRB24      PTB_BASE_PTR->DDRs.DDR24
#define DDRB25      PTB_BASE_PTR->DDRs.DDR25
#define DDRB26      PTB_BASE_PTR->DDRs.DDR26
#define DDRB27      PTB_BASE_PTR->DDRs.DDR27
#define DDRB28      PTB_BASE_PTR->DDRs.DDR28
#define DDRB29      PTB_BASE_PTR->DDRs.DDR29
#define DDRB30      PTB_BASE_PTR->DDRs.DDR30
#define DDRB31      PTB_BASE_PTR->DDRs.DDR31

/* Define the input and output direction of PTC */
#define DDRC0       PTC_BASE_PTR->DDRs.DDR0
#define DDRC1       PTC_BASE_PTR->DDRs.DDR1
#define DDRC2       PTC_BASE_PTR->DDRs.DDR2
#define DDRC3       PTC_BASE_PTR->DDRs.DDR3
#define DDRC4       PTC_BASE_PTR->DDRs.DDR4
#define DDRC5       PTC_BASE_PTR->DDRs.DDR5
#define DDRC6       PTC_BASE_PTR->DDRs.DDR6
#define DDRC7       PTC_BASE_PTR->DDRs.DDR7
#define DDRC8       PTC_BASE_PTR->DDRs.DDR8
#define DDRC9       PTC_BASE_PTR->DDRs.DDR9
#define DDRC10      PTC_BASE_PTR->DDRs.DDR10
#define DDRC11      PTC_BASE_PTR->DDRs.DDR11
#define DDRC12      PTC_BASE_PTR->DDRs.DDR12
#define DDRC13      PTC_BASE_PTR->DDRs.DDR13
#define DDRC14      PTC_BASE_PTR->DDRs.DDR14
#define DDRC15      PTC_BASE_PTR->DDRs.DDR15
#define DDRC16      PTC_BASE_PTR->DDRs.DDR16
#define DDRC17      PTC_BASE_PTR->DDRs.DDR17
#define DDRC18      PTC_BASE_PTR->DDRs.DDR18
#define DDRC19      PTC_BASE_PTR->DDRs.DDR19
#define DDRC20      PTC_BASE_PTR->DDRs.DDR20
#define DDRC21      PTC_BASE_PTR->DDRs.DDR21
#define DDRC22      PTC_BASE_PTR->DDRs.DDR22
#define DDRC23      PTC_BASE_PTR->DDRs.DDR23
#define DDRC24      PTC_BASE_PTR->DDRs.DDR24
#define DDRC25      PTC_BASE_PTR->DDRs.DDR25
#define DDRC26      PTC_BASE_PTR->DDRs.DDR26
#define DDRC27      PTC_BASE_PTR->DDRs.DDR27
#define DDRC28      PTC_BASE_PTR->DDRs.DDR28
#define DDRC29      PTC_BASE_PTR->DDRs.DDR29
#define DDRC30      PTC_BASE_PTR->DDRs.DDR30
#define DDRC31      PTC_BASE_PTR->DDRs.DDR31

/* Define the input and output direction of PTD */
#define DDRD0       PTD_BASE_PTR->DDRs.DDR0
#define DDRD1       PTD_BASE_PTR->DDRs.DDR1
#define DDRD2       PTD_BASE_PTR->DDRs.DDR2
#define DDRD3       PTD_BASE_PTR->DDRs.DDR3
#define DDRD4       PTD_BASE_PTR->DDRs.DDR4
#define DDRD5       PTD_BASE_PTR->DDRs.DDR5
#define DDRD6       PTD_BASE_PTR->DDRs.DDR6
#define DDRD7       PTD_BASE_PTR->DDRs.DDR7
#define DDRD8       PTD_BASE_PTR->DDRs.DDR8
#define DDRD9       PTD_BASE_PTR->DDRs.DDR9
#define DDRD10      PTD_BASE_PTR->DDRs.DDR10
#define DDRD11      PTD_BASE_PTR->DDRs.DDR11
#define DDRD12      PTD_BASE_PTR->DDRs.DDR12
#define DDRD13      PTD_BASE_PTR->DDRs.DDR13
#define DDRD14      PTD_BASE_PTR->DDRs.DDR14
#define DDRD15      PTD_BASE_PTR->DDRs.DDR15
#define DDRD16      PTD_BASE_PTR->DDRs.DDR16
#define DDRD17      PTD_BASE_PTR->DDRs.DDR17
#define DDRD18      PTD_BASE_PTR->DDRs.DDR18
#define DDRD19      PTD_BASE_PTR->DDRs.DDR19
#define DDRD20      PTD_BASE_PTR->DDRs.DDR20
#define DDRD21      PTD_BASE_PTR->DDRs.DDR21
#define DDRD22      PTD_BASE_PTR->DDRs.DDR22
#define DDRD23      PTD_BASE_PTR->DDRs.DDR23
#define DDRD24      PTD_BASE_PTR->DDRs.DDR24
#define DDRD25      PTD_BASE_PTR->DDRs.DDR25
#define DDRD26      PTD_BASE_PTR->DDRs.DDR26
#define DDRD27      PTD_BASE_PTR->DDRs.DDR27
#define DDRD28      PTD_BASE_PTR->DDRs.DDR28
#define DDRD29      PTD_BASE_PTR->DDRs.DDR29
#define DDRD30      PTD_BASE_PTR->DDRs.DDR30
#define DDRD31      PTD_BASE_PTR->DDRs.DDR31

/* Define the input and output direction of PTE */
#define DDRE0       PTE_BASE_PTR->DDRs.DDR0
#define DDRE1       PTE_BASE_PTR->DDRs.DDR1
#define DDRE2       PTE_BASE_PTR->DDRs.DDR2
#define DDRE3       PTE_BASE_PTR->DDRs.DDR3
#define DDRE4       PTE_BASE_PTR->DDRs.DDR4
#define DDRE5       PTE_BASE_PTR->DDRs.DDR5
#define DDRE6       PTE_BASE_PTR->DDRs.DDR6
#define DDRE7       PTE_BASE_PTR->DDRs.DDR7
#define DDRE8       PTE_BASE_PTR->DDRs.DDR8
#define DDRE9       PTE_BASE_PTR->DDRs.DDR9
#define DDRE10      PTE_BASE_PTR->DDRs.DDR10
#define DDRE11      PTE_BASE_PTR->DDRs.DDR11
#define DDRE12      PTE_BASE_PTR->DDRs.DDR12
#define DDRE13      PTE_BASE_PTR->DDRs.DDR13
#define DDRE14      PTE_BASE_PTR->DDRs.DDR14
#define DDRE15      PTE_BASE_PTR->DDRs.DDR15
#define DDRE16      PTE_BASE_PTR->DDRs.DDR16
#define DDRE17      PTE_BASE_PTR->DDRs.DDR17
#define DDRE18      PTE_BASE_PTR->DDRs.DDR18
#define DDRE19      PTE_BASE_PTR->DDRs.DDR19
#define DDRE20      PTE_BASE_PTR->DDRs.DDR20
#define DDRE21      PTE_BASE_PTR->DDRs.DDR21
#define DDRE22      PTE_BASE_PTR->DDRs.DDR22
#define DDRE23      PTE_BASE_PTR->DDRs.DDR23
#define DDRE24      PTE_BASE_PTR->DDRs.DDR24
#define DDRE25      PTE_BASE_PTR->DDRs.DDR25
#define DDRE26      PTE_BASE_PTR->DDRs.DDR26
#define DDRE27      PTE_BASE_PTR->DDRs.DDR27
#define DDRE28      PTE_BASE_PTR->DDRs.DDR28
#define DDRE29      PTE_BASE_PTR->DDRs.DDR29
#define DDRE30      PTE_BASE_PTR->DDRs.DDR30
#define DDRE31      PTE_BASE_PTR->DDRs.DDR31

/* Define the input port of PTA */
#define PTA0_IN     PTA_BASE_PTR->PDIRs.PDIR0
#define PTA1_IN     PTA_BASE_PTR->PDIRs.PDIR1
#define PTA2_IN     PTA_BASE_PTR->PDIRs.PDIR2
#define PTA3_IN     PTA_BASE_PTR->PDIRs.PDIR3
#define PTA4_IN     PTA_BASE_PTR->PDIRs.PDIR4
#define PTA5_IN     PTA_BASE_PTR->PDIRs.PDIR5
#define PTA6_IN     PTA_BASE_PTR->PDIRs.PDIR6
#define PTA7_IN     PTA_BASE_PTR->PDIRs.PDIR7
#define PTA8_IN     PTA_BASE_PTR->PDIRs.PDIR8
#define PTA9_IN     PTA_BASE_PTR->PDIRs.PDIR9
#define PTA10_IN    PTA_BASE_PTR->PDIRs.PDIR10
#define PTA11_IN    PTA_BASE_PTR->PDIRs.PDIR11
#define PTA12_IN    PTA_BASE_PTR->PDIRs.PDIR12
#define PTA13_IN    PTA_BASE_PTR->PDIRs.PDIR13
#define PTA14_IN    PTA_BASE_PTR->PDIRs.PDIR14
#define PTA15_IN    PTA_BASE_PTR->PDIRs.PDIR15
#define PTA16_IN    PTA_BASE_PTR->PDIRs.PDIR16
#define PTA17_IN    PTA_BASE_PTR->PDIRs.PDIR17
#define PTA18_IN    PTA_BASE_PTR->PDIRs.PDIR18
#define PTA19_IN    PTA_BASE_PTR->PDIRs.PDIR19
#define PTA20_IN    PTA_BASE_PTR->PDIRs.PDIR20
#define PTA21_IN    PTA_BASE_PTR->PDIRs.PDIR21
#define PTA22_IN    PTA_BASE_PTR->PDIRs.PDIR22
#define PTA23_IN    PTA_BASE_PTR->PDIRs.PDIR23
#define PTA24_IN    PTA_BASE_PTR->PDIRs.PDIR24
#define PTA25_IN    PTA_BASE_PTR->PDIRs.PDIR25
#define PTA26_IN    PTA_BASE_PTR->PDIRs.PDIR26
#define PTA27_IN    PTA_BASE_PTR->PDIRs.PDIR27
#define PTA28_IN    PTA_BASE_PTR->PDIRs.PDIR28
#define PTA29_IN    PTA_BASE_PTR->PDIRs.PDIR29
#define PTA30_IN    PTA_BASE_PTR->PDIRs.PDIR30
#define PTA31_IN    PTA_BASE_PTR->PDIRs.PDIR31

/* Define the input port of PTB */
#define PTB0_IN     PTB_BASE_PTR->PDIRs.PDIR0
#define PTB1_IN     PTB_BASE_PTR->PDIRs.PDIR1
#define PTB2_IN     PTB_BASE_PTR->PDIRs.PDIR2
#define PTB3_IN     PTB_BASE_PTR->PDIRs.PDIR3
#define PTB4_IN     PTB_BASE_PTR->PDIRs.PDIR4
#define PTB5_IN     PTB_BASE_PTR->PDIRs.PDIR5
#define PTB6_IN     PTB_BASE_PTR->PDIRs.PDIR6
#define PTB7_IN     PTB_BASE_PTR->PDIRs.PDIR7
#define PTB8_IN     PTB_BASE_PTR->PDIRs.PDIR8
#define PTB9_IN     PTB_BASE_PTR->PDIRs.PDIR9
#define PTB10_IN    PTB_BASE_PTR->PDIRs.PDIR10
#define PTB11_IN    PTB_BASE_PTR->PDIRs.PDIR11
#define PTB12_IN    PTB_BASE_PTR->PDIRs.PDIR12
#define PTB13_IN    PTB_BASE_PTR->PDIRs.PDIR13
#define PTB14_IN    PTB_BASE_PTR->PDIRs.PDIR14
#define PTB15_IN    PTB_BASE_PTR->PDIRs.PDIR15
#define PTB16_IN    PTB_BASE_PTR->PDIRs.PDIR16
#define PTB17_IN    PTB_BASE_PTR->PDIRs.PDIR17
#define PTB18_IN    PTB_BASE_PTR->PDIRs.PDIR18
#define PTB19_IN    PTB_BASE_PTR->PDIRs.PDIR19
#define PTB20_IN    PTB_BASE_PTR->PDIRs.PDIR20
#define PTB21_IN    PTB_BASE_PTR->PDIRs.PDIR21
#define PTB22_IN    PTB_BASE_PTR->PDIRs.PDIR22
#define PTB23_IN    PTB_BASE_PTR->PDIRs.PDIR23
#define PTB24_IN    PTB_BASE_PTR->PDIRs.PDIR24
#define PTB25_IN    PTB_BASE_PTR->PDIRs.PDIR25
#define PTB26_IN    PTB_BASE_PTR->PDIRs.PDIR26
#define PTB27_IN    PTB_BASE_PTR->PDIRs.PDIR27
#define PTB28_IN    PTB_BASE_PTR->PDIRs.PDIR28
#define PTB29_IN    PTB_BASE_PTR->PDIRs.PDIR29
#define PTB30_IN    PTB_BASE_PTR->PDIRs.PDIR30
#define PTB31_IN    PTB_BASE_PTR->PDIRs.PDIR31

/* Define the input port of PTC */
#define PTC0_IN     PTC_BASE_PTR->PDIRs.PDIR0
#define PTC1_IN     PTC_BASE_PTR->PDIRs.PDIR1
#define PTC2_IN     PTC_BASE_PTR->PDIRs.PDIR2
#define PTC3_IN     PTC_BASE_PTR->PDIRs.PDIR3
#define PTC4_IN     PTC_BASE_PTR->PDIRs.PDIR4
#define PTC5_IN     PTC_BASE_PTR->PDIRs.PDIR5
#define PTC6_IN     PTC_BASE_PTR->PDIRs.PDIR6
#define PTC7_IN     PTC_BASE_PTR->PDIRs.PDIR7
#define PTC8_IN     PTC_BASE_PTR->PDIRs.PDIR8
#define PTC9_IN     PTC_BASE_PTR->PDIRs.PDIR9
#define PTC10_IN    PTC_BASE_PTR->PDIRs.PDIR10
#define PTC11_IN    PTC_BASE_PTR->PDIRs.PDIR11
#define PTC12_IN    PTC_BASE_PTR->PDIRs.PDIR12
#define PTC13_IN    PTC_BASE_PTR->PDIRs.PDIR13
#define PTC14_IN    PTC_BASE_PTR->PDIRs.PDIR14
#define PTC15_IN    PTC_BASE_PTR->PDIRs.PDIR15
#define PTC16_IN    PTC_BASE_PTR->PDIRs.PDIR16
#define PTC17_IN    PTC_BASE_PTR->PDIRs.PDIR17
#define PTC18_IN    PTC_BASE_PTR->PDIRs.PDIR18
#define PTC19_IN    PTC_BASE_PTR->PDIRs.PDIR19
#define PTC20_IN    PTC_BASE_PTR->PDIRs.PDIR20
#define PTC21_IN    PTC_BASE_PTR->PDIRs.PDIR21
#define PTC22_IN    PTC_BASE_PTR->PDIRs.PDIR22
#define PTC23_IN    PTC_BASE_PTR->PDIRs.PDIR23
#define PTC24_IN    PTC_BASE_PTR->PDIRs.PDIR24
#define PTC25_IN    PTC_BASE_PTR->PDIRs.PDIR25
#define PTC26_IN    PTC_BASE_PTR->PDIRs.PDIR26
#define PTC27_IN    PTC_BASE_PTR->PDIRs.PDIR27
#define PTC28_IN    PTC_BASE_PTR->PDIRs.PDIR28
#define PTC29_IN    PTC_BASE_PTR->PDIRs.PDIR29
#define PTC30_IN    PTC_BASE_PTR->PDIRs.PDIR30
#define PTC31_IN    PTC_BASE_PTR->PDIRs.PDIR31

/* Define the input port of PTD */
#define PTD0_IN     PTD_BASE_PTR->PDIRs.PDIR0
#define PTD1_IN     PTD_BASE_PTR->PDIRs.PDIR1
#define PTD2_IN     PTD_BASE_PTR->PDIRs.PDIR2
#define PTD3_IN     PTD_BASE_PTR->PDIRs.PDIR3
#define PTD4_IN     PTD_BASE_PTR->PDIRs.PDIR4
#define PTD5_IN     PTD_BASE_PTR->PDIRs.PDIR5
#define PTD6_IN     PTD_BASE_PTR->PDIRs.PDIR6
#define PTD7_IN     PTD_BASE_PTR->PDIRs.PDIR7
#define PTD8_IN     PTD_BASE_PTR->PDIRs.PDIR8
#define PTD9_IN     PTD_BASE_PTR->PDIRs.PDIR9
#define PTD10_IN    PTD_BASE_PTR->PDIRs.PDIR10
#define PTD11_IN    PTD_BASE_PTR->PDIRs.PDIR11
#define PTD12_IN    PTD_BASE_PTR->PDIRs.PDIR12
#define PTD13_IN    PTD_BASE_PTR->PDIRs.PDIR13
#define PTD14_IN    PTD_BASE_PTR->PDIRs.PDIR14
#define PTD15_IN    PTD_BASE_PTR->PDIRs.PDIR15
#define PTD16_IN    PTD_BASE_PTR->PDIRs.PDIR16
#define PTD17_IN    PTD_BASE_PTR->PDIRs.PDIR17
#define PTD18_IN    PTD_BASE_PTR->PDIRs.PDIR18
#define PTD19_IN    PTD_BASE_PTR->PDIRs.PDIR19
#define PTD20_IN    PTD_BASE_PTR->PDIRs.PDIR20
#define PTD21_IN    PTD_BASE_PTR->PDIRs.PDIR21
#define PTD22_IN    PTD_BASE_PTR->PDIRs.PDIR22
#define PTD23_IN    PTD_BASE_PTR->PDIRs.PDIR23
#define PTD24_IN    PTD_BASE_PTR->PDIRs.PDIR24
#define PTD25_IN    PTD_BASE_PTR->PDIRs.PDIR25
#define PTD26_IN    PTD_BASE_PTR->PDIRs.PDIR26
#define PTD27_IN    PTD_BASE_PTR->PDIRs.PDIR27
#define PTD28_IN    PTD_BASE_PTR->PDIRs.PDIR28
#define PTD29_IN    PTD_BASE_PTR->PDIRs.PDIR29
#define PTD30_IN    PTD_BASE_PTR->PDIRs.PDIR30
#define PTD31_IN    PTD_BASE_PTR->PDIRs.PDIR31

/* Define the input port of PTE */
#define PTE0_IN     PTE_BASE_PTR->PDIRs.PDIR0
#define PTE1_IN     PTE_BASE_PTR->PDIRs.PDIR1
#define PTE2_IN     PTE_BASE_PTR->PDIRs.PDIR2
#define PTE3_IN     PTE_BASE_PTR->PDIRs.PDIR3
#define PTE4_IN     PTE_BASE_PTR->PDIRs.PDIR4
#define PTE5_IN     PTE_BASE_PTR->PDIRs.PDIR5
#define PTE6_IN     PTE_BASE_PTR->PDIRs.PDIR6
#define PTE7_IN     PTE_BASE_PTR->PDIRs.PDIR7
#define PTE8_IN     PTE_BASE_PTR->PDIRs.PDIR8
#define PTE9_IN     PTE_BASE_PTR->PDIRs.PDIR9
#define PTE10_IN    PTE_BASE_PTR->PDIRs.PDIR10
#define PTE11_IN    PTE_BASE_PTR->PDIRs.PDIR11
#define PTE12_IN    PTE_BASE_PTR->PDIRs.PDIR12
#define PTE13_IN    PTE_BASE_PTR->PDIRs.PDIR13
#define PTE14_IN    PTE_BASE_PTR->PDIRs.PDIR14
#define PTE15_IN    PTE_BASE_PTR->PDIRs.PDIR15
#define PTE16_IN    PTE_BASE_PTR->PDIRs.PDIR16
#define PTE17_IN    PTE_BASE_PTR->PDIRs.PDIR17
#define PTE18_IN    PTE_BASE_PTR->PDIRs.PDIR18
#define PTE19_IN    PTE_BASE_PTR->PDIRs.PDIR19
#define PTE20_IN    PTE_BASE_PTR->PDIRs.PDIR20
#define PTE21_IN    PTE_BASE_PTR->PDIRs.PDIR21
#define PTE22_IN    PTE_BASE_PTR->PDIRs.PDIR22
#define PTE23_IN    PTE_BASE_PTR->PDIRs.PDIR23
#define PTE24_IN    PTE_BASE_PTR->PDIRs.PDIR24
#define PTE25_IN    PTE_BASE_PTR->PDIRs.PDIR25
#define PTE26_IN    PTE_BASE_PTR->PDIRs.PDIR26
#define PTE27_IN    PTE_BASE_PTR->PDIRs.PDIR27
#define PTE28_IN    PTE_BASE_PTR->PDIRs.PDIR28
#define PTE29_IN    PTE_BASE_PTR->PDIRs.PDIR29
#define PTE30_IN    PTE_BASE_PTR->PDIRs.PDIR30
#define PTE31_IN    PTE_BASE_PTR->PDIRs.PDIR31

/* Defines the 8-bit port of PTA */
#define PTA_BYTE0_OUT   PTA_BASE_PTR->PDORByte.Byte0
#define PTA_BYTE1_OUT   PTA_BASE_PTR->PDORByte.Byte1
#define PTA_BYTE2_OUT   PTA_BASE_PTR->PDORByte.Byte2
#define PTA_BYTE3_OUT   PTA_BASE_PTR->PDORByte.Byte3

/* Defines the 8-bit port of PTB */
#define PTB_BYTE0_OUT   PTB_BASE_PTR->PDORByte.Byte0
#define PTB_BYTE1_OUT   PTB_BASE_PTR->PDORByte.Byte1
#define PTB_BYTE2_OUT   PTB_BASE_PTR->PDORByte.Byte2
#define PTB_BYTE3_OUT   PTB_BASE_PTR->PDORByte.Byte3

/* Defines the 8-bit port of PTC */
#define PTC_BYTE0_OUT   PTC_BASE_PTR->PDORByte.Byte0
#define PTC_BYTE1_OUT   PTC_BASE_PTR->PDORByte.Byte1
#define PTC_BYTE2_OUT   PTC_BASE_PTR->PDORByte.Byte2
#define PTC_BYTE3_OUT   PTC_BASE_PTR->PDORByte.Byte3

/* Defines the 8-bit port of PTD */
#define PTD_BYTE0_OUT   PTD_BASE_PTR->PDORByte.Byte0
#define PTD_BYTE1_OUT   PTD_BASE_PTR->PDORByte.Byte1
#define PTD_BYTE2_OUT   PTD_BASE_PTR->PDORByte.Byte2
#define PTD_BYTE3_OUT   PTD_BASE_PTR->PDORByte.Byte3

/* Defines the 8-bit port of PTE */
#define PTE_BYTE0_OUT   PTE_BASE_PTR->PDORByte.Byte0
#define PTE_BYTE1_OUT   PTE_BASE_PTR->PDORByte.Byte1
#define PTE_BYTE2_OUT   PTE_BASE_PTR->PDORByte.Byte2
#define PTE_BYTE3_OUT   PTE_BASE_PTR->PDORByte.Byte3

/* Define the 8-bit input and output direction of PTA */
#define DDRA_BYTE0      PTA_BASE_PTR->DDRByte.Byte0
#define DDRA_BYTE1      PTA_BASE_PTR->DDRByte.Byte1
#define DDRA_BYTE2      PTA_BASE_PTR->DDRByte.Byte2
#define DDRA_BYTE3      PTA_BASE_PTR->DDRByte.Byte3

/* Define the 8-bit input and output direction of PTB */
#define DDRB_BYTE0      PTB_BASE_PTR->DDRByte.Byte0
#define DDRB_BYTE1      PTB_BASE_PTR->DDRByte.Byte1
#define DDRB_BYTE2      PTB_BASE_PTR->DDRByte.Byte2
#define DDRB_BYTE3      PTB_BASE_PTR->DDRByte.Byte3

/* Define the 8-bit input and output direction of PTC */
#define DDRC_BYTE0      PTC_BASE_PTR->DDRByte.Byte0
#define DDRC_BYTE1      PTC_BASE_PTR->DDRByte.Byte1
#define DDRC_BYTE2      PTC_BASE_PTR->DDRByte.Byte2
#define DDRC_BYTE3      PTC_BASE_PTR->DDRByte.Byte3

/* Define the 8-bit input and output direction of PTD */
#define DDRD_BYTE0      PTD_BASE_PTR->DDRByte.Byte0
#define DDRD_BYTE1      PTD_BASE_PTR->DDRByte.Byte1
#define DDRD_BYTE2      PTD_BASE_PTR->DDRByte.Byte2
#define DDRD_BYTE3      PTD_BASE_PTR->DDRByte.Byte3

/* Define the 8-bit input and output direction of PTE */
#define DDRE_BYTE0      PTE_BASE_PTR->DDRByte.Byte0
#define DDRE_BYTE1      PTE_BASE_PTR->DDRByte.Byte1
#define DDRE_BYTE2      PTE_BASE_PTR->DDRByte.Byte2
#define DDRE_BYTE3      PTE_BASE_PTR->DDRByte.Byte3

/* Defines the 8-bit input port of PTA */
#define PTA_BYTE0_IN    PTA_BASE_PTR->PDIRByte.Byte0
#define PTA_BYTE1_IN    PTA_BASE_PTR->PDIRByte.Byte1
#define PTA_BYTE2_IN    PTA_BASE_PTR->PDIRByte.Byte2
#define PTA_BYTE3_IN    PTA_BASE_PTR->PDIRByte.Byte3

/* Defines the 8-bit input port of PTB */
#define PTB_BYTE0_IN    PTB_BASE_PTR->PDIRByte.Byte0
#define PTB_BYTE1_IN    PTB_BASE_PTR->PDIRByte.Byte1
#define PTB_BYTE2_IN    PTB_BASE_PTR->PDIRByte.Byte2
#define PTB_BYTE3_IN    PTB_BASE_PTR->PDIRByte.Byte3

/* Defines the 8-bit input port of PTC */
#define PTC_BYTE0_IN    PTC_BASE_PTR->PDIRByte.Byte0
#define PTC_BYTE1_IN    PTC_BASE_PTR->PDIRByte.Byte1
#define PTC_BYTE2_IN    PTC_BASE_PTR->PDIRByte.Byte2
#define PTC_BYTE3_IN    PTC_BASE_PTR->PDIRByte.Byte3

/* Defines the 8-bit input port of PTD */
#define PTD_BYTE0_IN    PTD_BASE_PTR->PDIRByte.Byte0
#define PTD_BYTE1_IN    PTD_BASE_PTR->PDIRByte.Byte1
#define PTD_BYTE2_IN    PTD_BASE_PTR->PDIRByte.Byte2
#define PTD_BYTE3_IN    PTD_BASE_PTR->PDIRByte.Byte3

/* Defines the 8-bit input port of PTE */
#define PTE_BYTE0_IN    PTE_BASE_PTR->PDIRByte.Byte0
#define PTE_BYTE1_IN    PTE_BASE_PTR->PDIRByte.Byte1
#define PTE_BYTE2_IN    PTE_BASE_PTR->PDIRByte.Byte2
#define PTE_BYTE3_IN    PTE_BASE_PTR->PDIRByte.Byte3

/* Defines the 16-bit port of PTA */
#define PTA_WORD0_OUT   PTA_BASE_PTR->PDORWord.Word0
#define PTA_WORD1_OUT   PTA_BASE_PTR->PDORWord.Word1

/* Defines the 16-bit port of PTB */
#define PTB_WORD0_OUT   PTB_BASE_PTR->PDORWord.Word0
#define PTB_WORD1_OUT   PTB_BASE_PTR->PDORWord.Word1

/* Defines the 16-bit port of PTC */
#define PTC_WORD0_OUT   PTC_BASE_PTR->PDORWord.Word0
#define PTC_WORD1_OUT   PTC_BASE_PTR->PDORWord.Word1

/* Defines the 16-bit port of PTD */
#define PTD_WORD0_OUT   PTD_BASE_PTR->PDORWord.Word0
#define PTD_WORD1_OUT   PTD_BASE_PTR->PDORWord.Word1

/* Defines the 16-bit port of PTE */
#define PTE_WORD0_OUT   PTE_BASE_PTR->PDORWord.Word0
#define PTE_WORD1_OUT   PTE_BASE_PTR->PDORWord.Word1

/* Define the 16-bit input and output direction of PTA */
#define DDRA_WORD0      PTA_BASE_PTR->DDRWord.Word0
#define DDRA_WORD1      PTA_BASE_PTR->DDRWord.Word1

/* Define the 16-bit input and output direction of PTB */
#define DDRB_WORD0      PTB_BASE_PTR->DDRWord.Word0
#define DDRB_WORD1      PTB_BASE_PTR->DDRWord.Word1

/* Define the 16-bit input and output direction of PTC */
#define DDRC_WORD0      PTC_BASE_PTR->DDRWord.Word0
#define DDRC_WORD1      PTC_BASE_PTR->DDRWord.Word1

/* Define the 16-bit input and output direction of PTD */
#define DDRD_WORD0      PTD_BASE_PTR->DDRWord.Word0
#define DDRD_WORD1      PTD_BASE_PTR->DDRWord.Word1

/* Define the 16-bit input and output direction of PTE */
#define DDRE_WORD0      PTE_BASE_PTR->DDRWord.Word0
#define DDRE_WORD1      PTE_BASE_PTR->DDRWord.Word1

/* Defines the 16-bit input port of PTA */
#define PTA_WORD0_IN    PTA_BASE_PTR->PDIRWord.Word0
#define PTA_WORD1_IN    PTA_BASE_PTR->PDIRWord.Word1

/* Defines the 16-bit input port of PTB */
#define PTB_WORD0_IN    PTB_BASE_PTR->PDIRWord.Word0
#define PTB_WORD1_IN    PTB_BASE_PTR->PDIRWord.Word1

/* Defines the 16-bit input port of PTC */
#define PTC_WORD0_IN    PTC_BASE_PTR->PDIRWord.Word0
#define PTC_WORD1_IN    PTC_BASE_PTR->PDIRWord.Word1

/* Defines the 16-bit input port of PTD */
#define PTD_WORD0_IN    PTD_BASE_PTR->PDIRWord.Word0
#define PTD_WORD1_IN    PTD_BASE_PTR->PDIRWord.Word1

/* Defines the 16-bit input port of PTE */
#define PTE_WORD0_IN    PTE_BASE_PTR->PDIRWord.Word0
#define PTE_WORD1_IN    PTE_BASE_PTR->PDIRWord.Word1

//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================

// Define pin status
typedef enum GPIO_CFG
{
    // The value here cannot be changed!!!
    GPI         = 0x00, // Define the pin input direction. In GPIOx_PDDRn, 0 means input and 1 means output.
    GPO         = 0x01, // Define the pin output direction

    GPI_DOWN    = 0x02, // Input pull-down PORTx_PCRn requires PE=1, PS=0
    GPI_UP      = 0x03, // Input pull-up PORTx_PCRn requires PE=1, PS=1
    GPI_PF      = 0x10, // Input, with passive filter, filter range: 10 MHz ~ 30 MHz. Does not support high-speed interface (>=2MHz) 0b10000           Passive Filter Enable
    GPI_DOWN_PF = GPI_DOWN | GPI_PF ,       // Input pull-down with passive filter
    GPI_UP_PF   = GPI_UP   | GPI_PF ,       // Input pull-up with passive filter

    GPO_HDS     = 0x41, // Output high drive strength 0b100 0001 High drive strength
    GPO_SSR     = 0x05, // Output slow change rate 0b101 Slow slew rate
    GPO_HDS_SSR = GPO_HDS | GPO_SSR,    // Output high drive capability, slow change rate
} GPIO_CFG;     // The lowest bit is 0, which means it is definitely input; the lowest bit of GPI_UP and GPI_UP_PF is 1, and the others are output


// Define pin external interrupt trigger mode
typedef enum exti_cfg
{
    rising_DMA      = 0x01,     // Rising edge triggers DMA interrupt
    falling_DMA     = 0x02,     // Falling edge triggers DMA interrupt
    either_down_DMA = 0x03,     // DMA interrupt triggered by edge transition

    // Use the highest bit to mark pull-up and pull-down
    zero_down       = 0x08u,    // Low level trigger, internal pull-down
    rising_down     = 0x09u,    // Rising edge trigger, internal pull-down
    falling_down    = 0x0Au,    // Falling edge triggered, internal pull-down
    either_down     = 0x0Bu,    // Edge trigger, internal pull-down
    one_down        = 0x0Cu,    // High level trigger, internal pull-down

    // Use the highest bit to mark pull-up and pull-down
    zero_up         = 0x88u,    // Low level trigger, internal pull-up
    rising_up       = 0x89u,    // Rising edge trigger, internal pull-up
    falling_up      = 0x8Au,    // Falling edge triggered, internal pull-up
    either_up       = 0x8Bu,    // Edge trigger, internal pull-up
    one_up          = 0x8Cu     // High level trigger, internal pull-up
} exti_cfg;

extern GPIO_MemMapPtr GPIOX[5];
extern PORT_MemMapPtr PORTX[5];

//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================
/* @brief GPIO initialization
 * @param ptx_n: pin number defined in common.h
 * @param dir: pin status (pull-up/pull-down, input/output, etc.)
 * @param data: pin output level 0: low level 1: high level
 */
void GPIO_PinInit(PTXn_e ptx_n, GPIO_CFG dir, uint8_t data);


/* @brief Set IO direction
 * @param ptx_n: pin number defined in common.h
 * @param input: GPIO direction true: input false: output
 */
void GPIO_PinSetDir(PTXn_e ptx_n, bool input);


/* @brief Set IO port output
 * @param ptx_n: GPIO to be initialized, defined in common.h
 * @param data: 1: high level 0: low level
 */
void GPIO_PinWrite(PTXn_e ptx_n, uint8_t data);


/* @brief Flip IO port output
 * @param ptx_n: GPIO to be initialized, defined in common.h
 */
void GPIO_PinReverse(PTXn_e ptx_n);


/* @brief Get IO port level
 * @param ptx_n: GPIO to be initialized, defined in common.h
 * @return 0: low level 1: high level
 */
uint8_t GPIO_PinRead(PTXn_e ptx_n);


/* @brief IO pull-up
 * @param ptx_n select port
 * @param pullup_ena false: pulldown, true: pullup
 */
void GPIO_PortPull(PTXn_e ptx_n, bool pullup_ena);


/* @brief GPIO external interrupt initialization
 * @param ptx_n: GPIO to be initialized, defined in common.h
 * @param cfg: interrupt trigger mode, such as: rising_down // rising edge trigger, internal pull-down
 * @note Here only the peripheral interrupt is enabled, and NVIC_EnableIRQ() is also required to enable the kernel interrupt
 */
void GPIO_ExtiInit(PTXn_e ptx_n, exti_cfg cfg);

#endif /* S32K_GPIO_H_ */
