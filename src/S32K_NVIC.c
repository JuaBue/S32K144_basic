/*
 * =============================================================================
 * File Name    : S32K_NVIC.c
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
//==============================================================================
//                                INCLUDES
//==============================================================================
#include "S32K_NVIC.h"

//==============================================================================
//                         LOCAL DEFINES AND MACROS
//==============================================================================
//Set the macro _DLIB_FILE_DESCRIPTOR (Options -> Compiler C/C++ -> Preprocessor)

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

//==============================================================================
//                       PUBLIC FUNCTION DEFINITIONS
//==============================================================================
void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
    uint32_t reg_value;

    reg_value = S32_SCB->AIRCR;
    reg_value &= ~((S32_SCB_AIRCR_VECTKEY_MASK << S32_SCB_AIRCR_VECTKEY_SHIFT) |
                   (S32_SCB_AIRCR_PRIGROUP_MASK << S32_SCB_AIRCR_VECTKEY_SHIFT));
    reg_value = (reg_value | ((uint32_t)0x5FA << S32_SCB_AIRCR_VECTKEY_SHIFT) |
                (PriorityGroup << 8U));
    S32_SCB->AIRCR = reg_value;
}
