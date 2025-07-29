/*
 * =============================================================================
 * File Name    : S32K_NVIC.h
 * Project      : S32K144_basic
 * Module       : NVIC Configuration Module (Header)
 * Author       : JuaBue
 * Created On   : 2025-07-28
 * Version      : 1.0.0
 *
 * Description  :
 *   This header file provides definitions and a helper function for configuring
 *   the interrupt priority grouping of the NVIC on the S32K144 microcontroller.
 *   The module allows selecting among different preemption/subpriority groupings
 *   as defined by the ARM Cortex-M architecture.
 *
 *   NVIC Group Settings:
 *     - Group0: 0 bits preempt, 3 bits subpriority
 *     - Group4: 4 bits preempt, 0 bits subpriority
 *     - Others: intermediate combinations
 *
 * Dependencies :
 *   - S32K register definitions
 *   - include.h (project-level definitions)
 *
 * Configuration :
 *   - Call `NVIC_setPriorityGroup()` during system startup
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

#ifndef DRIVER_S32K_NVIC_H_
#define DRIVER_S32K_NVIC_H_
//==============================================================================
//                               INCLUDES
//==============================================================================
#include "include.h"

//==============================================================================
//                         PUBLIC DEFINES AND MACROS
//==============================================================================
/* Interrupt Priority Group */
#define NVIC_Group0                    0x07
#define NVIC_Group1                    0x06
#define NVIC_Group2                    0x05
#define NVIC_Group3                    0x04
#define NVIC_Group4                    0x03

/* S32K144 has 4 bits for priority */
#define NVIC_PI_BITS                   4U

//==============================================================================
//                         PUBLIC GLOBAL VARIABLES
//==============================================================================

//==============================================================================
//                        PUBLIC FUNCTION DECLARATIONS
//==============================================================================
/*
 * @brief: Set Priority Grouping
 * @param: PriorityGroup: Priority grouping field
 */
void NVIC_SetPriorityGrouping(uint32_t PriorityGroup);

/*
 * @brief: Get Priority Grouping
 * @return: Priority grouping field
 */
uint32_t NVIC_GetPriorityGrouping(void);

/*
 * @brief: Set Interrupt Priority
 * @param: IRQn: Number of the interrupt for set priority
 * @param: priority: Priority to set
 */
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);

/*
 * @brief: Set Interrupt Priority
 * @param: IRQn: Number of the interrupt for get priority
 * @return: Interrupt Priority
 */
uint32_t NVIC_GetPriority(IRQn_Type IRQn);

/*
 * @brief: Enable External Interrupt
 * @param: IRQn: Number of the external interrupt to enable
 */
void NVIC_EnableIRQ(IRQn_Type IRQn);

/*
 * @brief: Disable External Interrupt
 * @param: IRQn: Number of the external interrupt to disable
 */
void NVIC_DisableIRQ(IRQn_Type IRQn);

/*
 * @brief: Encode Priority
 * @param: PriorityGroup: Used priority group
 * @param: PreemptPriority: Preemptive priority value (starting from 0)
 * @param: SubPriority: Number of the interrupt for get priority
 * @return: Encoded priority for the interrupt
 */
uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority,
                              uint32_t SubPriority);

#endif /* DRIVER_S32K_NVIC_H_ */
