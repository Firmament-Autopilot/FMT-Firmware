/**
 *******************************************************************************
 * @file  hc32_ll_aos.c
 * @brief This file provides firmware functions to manage the AOS.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
   2023-01-15       CDT             Macro name modified: from IS_AOS_TRIG_SEL to IS_AOS_TARGET
                                    Modified parameters name and comments of AOS_CommonTriggerCmd() and AOS_SetTriggerEventSrc()
   2024-08-31       CDT             Optimize assert IS_AOS_TARGET
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2025, Xiaohua Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by XHSC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_ll_aos.h"
#include "hc32_ll_utility.h"

/**
 * @addtogroup LL_Driver
 * @{
 */

/**
 * @defgroup LL_AOS AOS
 * @brief AOS Driver Library
 * @{
 */

#if (LL_AOS_ENABLE == DDL_ON)

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup AOS_Local_Macros AOS Local Macros
 * @{
 */

/**
 * @defgroup AOS_Const_Value_Def AOS Const Value Definition
 * @{
 */
#define AOS_TRG_START               AOS_DCU1
#define AOS_TRG_END                 AOS_COMM_2
/**
 * @}
 */

/**
 * @defgroup AOS_Common_Trigger_ID_Validity AOS Common Trigger ID Validity
 * @{
 */
#define IS_AOS_COMM_TRIG(x)                                                    \
(   ((x) != 0UL)                                &&                             \
    ((x) | AOS_COMM_TRIG_MASK) == AOS_COMM_TRIG_MASK)

/**
 * @}
 */

/**
 * @defgroup AOS_Target_Select_Validity AOS Target Select Validity
 * @{
 */
#define IS_AOS_TARGET(x)                                                       \
(   ((x) >= AOS_TRG_START) && ((x) <= AOS_TRG_END) && (((x) & 0x03UL) == 0UL))

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @defgroup AOS_Global_Functions AOS Global Functions
 * @{
 */

/**
 * @brief  Common trigger function command
 * @param  [in] u32Target           AOS target that need to be triggered by common trigger @ref AOS_Target_Select in details
 * @param  [in] u32CommonTrigger    Common trigger ID
 *                                  This parameter can be one of the following values:
 *   @arg  AOS_COMM_TRIG1:          Common trigger 1.
 *   @arg  AOS_COMM_TRIG2:          Common trigger 2.
 * @param  [in] enNewState          An @ref en_functional_state_t enumeration value.
 * @retval None
 */
void AOS_CommonTriggerCmd(uint32_t u32Target, uint32_t u32CommonTrigger, en_functional_state_t enNewState)
{
    DDL_ASSERT(IS_AOS_TARGET(u32Target));
    DDL_ASSERT(IS_AOS_COMM_TRIG(u32CommonTrigger));
    DDL_ASSERT(IS_FUNCTIONAL_STATE(enNewState));

    if (ENABLE == enNewState) {
        SET_REG32_BIT(*(__IO uint32_t *)u32Target, u32CommonTrigger);
    } else {
        CLR_REG32_BIT(*(__IO uint32_t *)u32Target, u32CommonTrigger);
    }
}

/**
 * @brief  Set trigger event source
 * @param  [in] u32Target       AOS target that need to be triggered by AOS source @ref AOS_Target_Select in details
 * @param  [in] enSource        AOS source that trigger the AOS target @ref en_event_src_t in details
 * @retval None
 */
void AOS_SetTriggerEventSrc(uint32_t u32Target, en_event_src_t enSource)
{
    DDL_ASSERT(IS_AOS_TARGET(u32Target));

    MODIFY_REG32(*(__IO uint32_t *)u32Target, AOS_TRIG_SEL_MASK, enSource);
}

/**
 * @}
 */

#endif /* LL_AOS_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/
