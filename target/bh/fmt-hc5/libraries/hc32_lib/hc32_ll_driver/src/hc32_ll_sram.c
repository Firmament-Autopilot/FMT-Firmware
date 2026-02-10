/**
 *******************************************************************************
 * @file  hc32_ll_sram.c
 * @brief This file provides firmware functions to manage the SRAM.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
   2022-10-31       CDT             Deleted redundant comments
   2023-06-30       CDT             API fixed: SRAM_ClearStatus()
   2023-09-30       CDT             API fixed: SRAM_SetWaitCycle()
   2023-12-15       CDT             Refine SRAM_SetEccMode, and refine SRAM_SetErrorMode() as SRAM_SetExceptionType
   2024-08-31       CDT             Modify assert IS_SRAM_ECC_MD()
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
#include "hc32_ll_sram.h"
#include "hc32_ll_utility.h"

/**
 * @addtogroup LL_Driver
 * @{
 */

/**
 * @defgroup LL_SRAM SRAM
 * @brief SRAM Driver Library
 * @{
 */

#if (LL_SRAM_ENABLE == DDL_ON)

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup SRAM_Local_Macros SRAM Local Macros
 * @{
 */

/**
 * @defgroup SRAM_Configuration_Bits_Mask SRAM Configuration Bits Mask
 * @{
 */
#define SRAM_CYCLE_MASK                 (0x00000007UL)
/**
 * @}
 */

/**
 * @defgroup SRAM_Ecc_Mode_Mask SRAM ecc mode mask
 * @{
 */
#define SRAM_ECC_MD_MASK                (SRAMC_CKCR_ECCMOD | SRAMC_CKCR_BECCMOD)
/**
 * @}
 */

/**
 * @defgroup SRAM_Exception_Type_Mask SRAM exception type mask
 * @{
 */
#define SRAM_EXP_TYPE_MASK              (SRAMC_CKCR_ECCOAD | SRAMC_CKCR_BECCOAD | SRAMC_CKCR_PYOAD)
/**
 * @}
 */

/**
 * @defgroup SRAM_Check_Parameters_Validity SRAM check parameters validity
 * @{
 */
#define IS_SRAM_BIT_MASK(x, mask)       (((x) != 0U) && (((x) | (mask)) == (mask)))

/* Parameter valid check for SRAM wait cycle */
#define IS_SRAM_WAIT_CYCLE(x)           ((x) <= SRAM_WAIT_CYCLE7)

/* Parameter valid check for SRAM selection */
#define IS_SRAM_SEL(x)                  IS_SRAM_BIT_MASK(x, SRAM_SRAM_ALL)

/* Parameter valid check for SRAM ECC SRAM */
#define IS_SRAM_ECC_SRAM(x)             IS_SRAM_BIT_MASK(x, SRAM_ECC_SRAM_ALL)

/* Parameter valid check for SRAM ECC SRAM */
#define IS_SRAM_CHECK_SRAM(x)           IS_SRAM_BIT_MASK(x, SRAM_CHECK_SRAM_ALL)

/* Parameter valid check for SRAM flag */
#define IS_SRAM_FLAG(x)                 IS_SRAM_BIT_MASK(x, SRAM_FLAG_ALL)

/* Check SRAM  WTPR register lock status. */
#define IS_SRAM_WTPR_UNLOCK()           (CM_SRAMC->WTPR == SRAM_REG_UNLOCK_KEY)

/* Check SRAM CKPR register lock status. */
#define IS_SRAM_CKPR_UNLOCK()           (CM_SRAMC->CKPR == SRAM_REG_UNLOCK_KEY)

/* Parameter valid check for SRAM exception type mode */
#define IS_SRAM_EXP_TYPE(x)                                                    \
(   ((x) == SRAM_EXP_TYPE_NMI)                  ||                             \
    ((x) == SRAM_EXP_TYPE_RST))

/* Parameter valid check for SRAM ECC mode */
#define IS_SRAM_ECC_MD(x)               (((x) | SRAM_ECC_MD_MASK) == SRAM_ECC_MD_MASK)

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
 * @defgroup SRAM_Global_Functions SRAM Global Functions
 * @{
 */

/**
 * @brief  Initializes SRAM.
 * @param  None
 * @retval None
 */
void SRAM_Init(void)
{
    SET_REG32_BIT(CM_SRAMC->CKSR, SRAM_FLAG_ALL);
}

/**
 * @brief  De-initializes SRAM. RESET the registers of SRAM.
 * @param  None
 * @retval None
 * @note   Call SRAM_REG_Unlock to unlock registers WTCR and CKCR first.
 */
void SRAM_DeInit(void)
{
    /* Call SRAM_REG_Unlock to unlock register WTCR and CKCR. */
    DDL_ASSERT(IS_SRAM_CKPR_UNLOCK());
    DDL_ASSERT(IS_SRAM_WTPR_UNLOCK());

    WRITE_REG32(CM_SRAMC->WTCR, 0UL);
    WRITE_REG32(CM_SRAMC->CKCR, 0UL);
    SET_REG32_BIT(CM_SRAMC->CKSR, SRAM_FLAG_ALL);
}

/**
 * @brief  Specifies access wait cycle for SRAM.
 * @param  [in]  u32SramSel             The SRAM selection.
 *                                      This parameter can be values of @ref SRAM_Sel
 * @param  [in]  u32WriteCycle          The write access wait cycle for the specified SRAM
 *                                      This parameter can be a value of @ref SRAM_Access_Wait_Cycle
 * @param  [in]  u32ReadCycle           The read access wait cycle for the specified SRAM.
 *                                      This parameter can be a value of @ref SRAM_Access_Wait_Cycle
 *   @arg  SRAM_WAIT_CYCLE0:            Wait 0 CPU cycle.
 *   @arg  SRAM_WAIT_CYCLE1:            Wait 1 CPU cycle.
 *   @arg  SRAM_WAIT_CYCLE2:            Wait 2 CPU cycles.
 *   @arg  SRAM_WAIT_CYCLE3:            Wait 3 CPU cycles.
 *   @arg  SRAM_WAIT_CYCLE4:            Wait 4 CPU cycles.
 *   @arg  SRAM_WAIT_CYCLE5:            Wait 5 CPU cycles.
 *   @arg  SRAM_WAIT_CYCLE6:            Wait 6 CPU cycles.
 *   @arg  SRAM_WAIT_CYCLE7:            Wait 7 CPU cycles.
 * @retval None
 * @note   Call SRAM_REG_Unlock to unlock register WTCR first.
 */
void SRAM_SetWaitCycle(uint32_t u32SramSel, uint32_t u32WriteCycle, uint32_t u32ReadCycle)
{
    uint8_t i = 0U;
    uint8_t u8OfsWt;
    uint8_t u8OfsRd;

    DDL_ASSERT(IS_SRAM_SEL(u32SramSel));
    DDL_ASSERT(IS_SRAM_WAIT_CYCLE(u32WriteCycle));
    DDL_ASSERT(IS_SRAM_WAIT_CYCLE(u32ReadCycle));
    DDL_ASSERT(IS_SRAM_WTPR_UNLOCK());

    while (u32SramSel != 0UL) {
        if ((u32SramSel & 0x1UL) != 0UL) {
            u8OfsRd = i * 8U;
            u8OfsWt = u8OfsRd + 4U;
            MODIFY_REG32(CM_SRAMC->WTCR,
                         ((SRAM_CYCLE_MASK << u8OfsWt) | (SRAM_CYCLE_MASK << u8OfsRd)),
                         ((u32WriteCycle << u8OfsWt) | (u32ReadCycle << u8OfsRd)));
        }
        u32SramSel >>= 1U;
        i++;
    }
}

/**
 * @brief  Specifies ECC mode.
 * @param  [in]  u32EccSram             The ECC SRAM.
 *                                      This parameter can be any combination of @ref SRAM_ECC_SRAM
 * @param  [in]  u32EccMode             The ECC mode.
 *                                      This parameter can be any combination of @ref SRAM_ECC_Mode, but only choose
 *                                      one value of SRAM_SRAM4_ECC_xx and SRAM_SRAMB_ECC_xx
 * @retval None
 * @note   Call SRAM_REG_Unlock to unlock register CKCR first.
 *         The sram of u32EccMode should be the same with the sram of u32EccSram.
 */
void SRAM_SetEccMode(uint32_t u32EccSram, uint32_t u32EccMode)
{
    uint32_t u32Mask = 0UL;
    uint32_t u32Pos = 0UL;

    DDL_ASSERT(IS_SRAM_ECC_SRAM(u32EccSram));
    DDL_ASSERT(IS_SRAM_ECC_MD(u32EccMode));
    DDL_ASSERT(IS_SRAM_CKPR_UNLOCK());

    while (0UL != u32EccSram) {
        if (1UL == (u32EccSram & 0x01UL)) {
            u32Mask |= (SRAMC_CKCR_ECCMOD << u32Pos);
        }
        u32EccSram >>= 1UL;
        u32Pos += 2UL;
    }

    MODIFY_REG32(CM_SRAMC->CKCR, u32Mask, u32EccMode);
}

/**
 * @brief  Specifies the exception type while the chosen sram check error occurred.
 * @param  [in] u32CheckSram            The check SRAM.
 *                                      This parameter can be any combination of @ref SRAM_Check_SRAM
 * @param  [in] u32ExceptionType        The operation after check error occurred.
 *                                      This parameter can be a value of @ref SRAM_Exception_Type
 * @retval None
 * @note   Call SRAM_REG_Unlock to unlock register CKCR first.
 */
void SRAM_SetExceptionType(uint32_t u32CheckSram, uint32_t u32ExceptionType)
{
    DDL_ASSERT(IS_SRAM_CHECK_SRAM(u32CheckSram));
    DDL_ASSERT(IS_SRAM_EXP_TYPE(u32ExceptionType));
    DDL_ASSERT(IS_SRAM_CKPR_UNLOCK());

    if (SRAM_EXP_TYPE_RST == u32ExceptionType) {
        SET_REG32_BIT(CM_SRAMC->CKCR, u32CheckSram);
    } else {
        CLR_REG32_BIT(CM_SRAMC->CKCR, u32CheckSram);
    }
}

/**
 * @brief  Get the status of the specified flag of SRAM.
 * @param  [in]  u32Flag                The flag of SRAM.
 *                                      This parameter can be a value of @ref SRAM_Err_Status_Flag
 * @retval An @ref en_flag_status_t enumeration type value.
 */
en_flag_status_t SRAM_GetStatus(uint32_t u32Flag)
{
    en_flag_status_t enStatus = RESET;

    DDL_ASSERT(IS_SRAM_FLAG(u32Flag));
    if (READ_REG32_BIT(CM_SRAMC->CKSR, u32Flag) != 0U) {
        enStatus = SET;
    }

    return enStatus;
}

/**
 * @brief  Clear the status of the specified flag of SRAM.
 * @param  [in]  u32Flag                The flag of SRAM.
 *                                      This parameter can be values of @ref SRAM_Err_Status_Flag
 * @retval None
 */
void SRAM_ClearStatus(uint32_t u32Flag)
{
    DDL_ASSERT(IS_SRAM_FLAG(u32Flag));
    WRITE_REG32(CM_SRAMC->CKSR, u32Flag);
}

/**
 * @}
 */

#endif /* LL_SRAM_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/
