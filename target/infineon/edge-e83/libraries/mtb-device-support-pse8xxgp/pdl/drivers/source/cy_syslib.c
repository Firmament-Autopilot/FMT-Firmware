/***************************************************************************//**
* \file cy_syslib.c
* \version 3.80
*
*  Description:
*   Provides system API implementation for the SysLib driver.
*
********************************************************************************
* Copyright (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"

#if defined (CY_IP_M33SYSCPUSS) || defined (CY_IP_M4CPUSS) || defined (CY_IP_M7CPUSS) || defined(CY_IP_M55APPCPUSS)

#include "cy_syslib.h"

#if defined (CY_IP_M33SYSCPUSS) && defined(CY_IP_MXEFUSE)
#include "cy_efuse.h"
#endif

#ifdef CY_IP_M4CPUSS
#include "cy_ipc_drv.h"
#endif
#if !defined(NDEBUG)
    #include <string.h>
#endif /* NDEBUG */

#if defined (CY_DEVICE_SECURE)
#include "cy_pra.h"
#endif /* defined (CY_DEVICE_SECURE) */

#ifdef CY_IP_M4CPUSS
/* Flash wait states (ULP mode at 0.9v) */
#define CY_SYSLIB_FLASH_ULP_WS_0_FREQ_MAX    ( 16UL)
#define CY_SYSLIB_FLASH_ULP_WS_1_FREQ_MAX    ( 33UL)
#define CY_SYSLIB_FLASH_ULP_WS_2_FREQ_MAX    ( 50UL)

/* ROM and SRAM wait states for the slow clock domain (LP mode at 1.1v) */
#define CY_SYSLIB_LP_SLOW_WS_0_FREQ_MAX      (100UL)
#define CY_SYSLIB_LP_SLOW_WS_1_FREQ_MAX      (120UL)

/* ROM and SRAM wait states for the slow clock domain (ULP mode at 0.9v) */
#define CY_SYSLIB_ULP_SLOW_WS_0_FREQ_MAX     ( 25UL)
#define CY_SYSLIB_ULP_SLOW_WS_1_FREQ_MAX     ( 50UL)
#elif (defined(CY_IP_M33SYSCPUSS) && (CY_IP_M33SYSCPUSS))
/* These definitions can be removed once SystemCorClockUpdate() function is implemented */
#define CY_SYSCLK_IMO_FREQ          (8000000UL) /* Hz */
#define CY_DELAY_1K_THRESHOLD           (1000u)
#define CY_DELAY_1K_MINUS_1_THRESHOLD   (CY_DELAY_1K_THRESHOLD - 1u)
#define CY_DELAY_1M_THRESHOLD           (1000000u)
#define CY_DELAY_1M_MINUS_1_THRESHOLD   (CY_DELAY_1M_THRESHOLD - 1u)

#elif defined(CY_IP_M7CPUSS)
#define CY_SYSLIB_LP_SLOW_WS_0_FREQ_MAX      (100UL)

#endif


#if  defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined(CY_IP_MXS22SRSS)
#define CY_SRSS_RES_CAUSE2_CSV_LOSS_Msk    (SRSS_RES_CAUSE2_RESET_CSV_HF_Msk)
#define CY_SRSS_RES_CAUSE2_CSV_LOSS_Pos    (SRSS_RES_CAUSE2_RESET_CSV_HF_Pos)
#define CY_SRSS_RES_CAUSE2_CSV_ERROR_Msk    (SRSS_RES_CAUSE2_RESET_CSV_REF_Msk)
#define CY_SRSS_RES_CAUSE2_CSV_ERROR_Pos    (SRSS_RES_CAUSE2_RESET_CSV_REF_Pos)
#endif

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
/** Holds the flag to indicate if the System woke up from Warm Boot or not */
bool cy_WakeupFromWarmBootStatus = false;
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */

#if !defined(NDEBUG)
    CY_NOINIT char_t cy_assertFileName[CY_MAX_FILE_NAME_SIZE + 1];
    CY_NOINIT uint32_t cy_assertLine;
#endif /* NDEBUG */

#if (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED)
    CY_NOINIT cy_stc_fault_frame_t cy_faultFrame;
#endif /* (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) */

#if defined(__ARMCC_VERSION)
        #if (__ARMCC_VERSION >= 6010050)
            static void Cy_SysLib_AsmInfiniteLoop(void) { __ASM (" b . "); }
        #else
            static __ASM void Cy_SysLib_AsmInfiniteLoop(void) { b . }
        #endif /* (__ARMCC_VERSION >= 6010050) */
#endif  /* (__ARMCC_VERSION) */

CY_SECTION_INIT_CODECOPY_BEGIN
void Cy_SysLib_Delay(uint32_t milliseconds)
{
    uint32_t max_delay_ms = 0xFFFFFFFFU / (cy_delayFreqKhz * CY_SYSLIB_DELAY_CALIBRATION_FACTOR);

    while(milliseconds > max_delay_ms)
    {
        /* This loop prevents an overflow in value passed to Cy_SysLib_DelayCycles() API. */
        Cy_SysLib_DelayCycles(max_delay_ms * cy_delayFreqKhz * CY_SYSLIB_DELAY_CALIBRATION_FACTOR);
        milliseconds -= max_delay_ms;
    }

    Cy_SysLib_DelayCycles(milliseconds * cy_delayFreqKhz * CY_SYSLIB_DELAY_CALIBRATION_FACTOR);
}


void Cy_SysLib_DelayUs(uint16_t microseconds)
{
    Cy_SysLib_DelayCycles((uint32_t) microseconds * cy_delayFreqMhz * CY_SYSLIB_DELAY_CALIBRATION_FACTOR);
}

__WEAK void Cy_SysLib_Rtos_Delay(uint32_t milliseconds)
{
    Cy_SysLib_Delay(milliseconds);
}

__WEAK void Cy_SysLib_Rtos_DelayUs(uint16_t microseconds)
{
    Cy_SysLib_DelayUs(microseconds);
}

__NO_RETURN void Cy_SysLib_Halt(uint32_t reason)
{
    if(0U != reason)
    {
        /* To remove an unreferenced local variable warning */
    }

    #if defined (__ARMCC_VERSION)
        __BKPT(0x0);
    #elif defined(__GNUC__)
        CY_HALT();
    #elif defined (__ICCARM__)
        CY_HALT();
    #else
        #error "An unsupported toolchain"
    #endif  /* (__ARMCC_VERSION) */

    while(true) {}
}


__WEAK void Cy_SysLib_AssertFailed(const char_t * file, uint32_t line)
{
#if !defined(NDEBUG) || defined(CY_DOXYGEN)
    (void) strncpy(cy_assertFileName, file, CY_MAX_FILE_NAME_SIZE);
    cy_assertLine = line;
    Cy_SysLib_Halt(0UL);
#else
    (void) file;
    (void) line;
#endif  /* !defined(NDEBUG) || defined(CY_DOXYGEN) */
}

#ifdef CY_IP_M4CPUSS


void Cy_SysLib_ClearFlashCacheAndBuffer(void)
{
    #if CY_CPU_CORTEX_M4 && defined(CY_DEVICE_SECURE)
        CY_PRA_REG32_SET(CY_PRA_INDX_FLASHC_FLASH_CMD, FLASHC_FLASH_CMD_INV_Msk);
    #else
        FLASHC_FLASH_CMD = FLASHC_FLASH_CMD_INV_Msk;
    #endif /* CY_CPU_CORTEX_M4 && defined(CY_DEVICE_SECURE) */
}
#endif


cy_en_syslib_status_t Cy_SysLib_ResetBackupDomain(void)
{
    BACKUP_RESET = BACKUP_RESET_RESET_Msk;
    return (Cy_SysLib_GetResetStatus());
}

uint32_t Cy_SysLib_GetResetReason(void)
{
    uint32_t retVal = 0UL;

    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_WDT, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_HWWDT;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_ACT_FAULT, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_ACT_FAULT;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_DPSLP_FAULT, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_DPSLP_FAULT;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_TC_DBGRESET, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_TC_DBGRESET;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_SOFT, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_SOFT0;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_SOFT1, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_SOFT1;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_SOFT2, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_SOFT2;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_MCWDT0, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_SWWDT0;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_MCWDT1, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_SWWDT1;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_MCWDT2, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_SWWDT2;
    }
    if(0 != _FLD2VAL(SRSS_RES_CAUSE_RESET_MCWDT3, SRSS_RES_CAUSE))
    {
        retVal |= CY_SYSLIB_RESET_SWWDT3;
    }

    if(CY_SYSLIB_HIBERNATE_TOKEN == _FLD2VAL(SRSS_PWR_HIBERNATE_TOKEN, SRSS_PWR_HIBERNATE))
    {
        retVal |= CY_SYSLIB_RESET_HIB_WAKEUP;
    }
    if (CY_SYSLIB_DEEP_SLEEP_OFF_TOKEN == _FLD2VAL(SRSS_PWR_HIBERNATE_TOKEN, SRSS_PWR_HIBERNATE))
    {
        retVal |= CY_SYSLIB_RESET_DS_OFF_WAKEUP;
    }


#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) ||  defined(CY_IP_MXS22SRSS)
    if(0U != _FLD2VAL(CY_SRSS_RES_CAUSE2_CSV_LOSS, SRSS_RES_CAUSE2))
    {
        retVal |= CY_SYSLIB_RESET_CSV_LOSS_WAKEUP;
    }

    if(0U != _FLD2VAL(CY_SRSS_RES_CAUSE2_CSV_ERROR, SRSS_RES_CAUSE2))
    {
        retVal |= CY_SYSLIB_RESET_CSV_ERROR_WAKEUP;
    }
#endif

#if defined(CY_IP_MXS22SRSS) && (SRSS_POR_PRESENT)
    if (0U != _FLD2VAL(SRSS_RES_CAUSE_EXTEND_RESET_XRES, SRSS_RES_CAUSE_EXTEND))
    {
        retVal |= CY_SYSLIB_RESET_XRES;
    }
    if (0U != _FLD2VAL(SRSS_RES_CAUSE_EXTEND_RESET_BODVDDD, SRSS_RES_CAUSE_EXTEND))
    {
        retVal |= CY_SYSLIB_RESET_BODVDDD;
    }
    if (0U != _FLD2VAL(SRSS_RES_CAUSE_EXTEND_RESET_BODVCCD, SRSS_RES_CAUSE_EXTEND))
    {
        retVal |= CY_SYSLIB_RESET_BODVCCD;
    }
    if (0U != _FLD2VAL(SRSS_RES_CAUSE_EXTEND_RESET_BODVBAT, SRSS_RES_CAUSE_EXTEND))
    {
        retVal |= CY_SYSLIB_RESET_BODVBAT;
    }
    if (0U != _FLD2VAL(SRSS_RES_CAUSE_EXTEND_RESET_OVDVCCD, SRSS_RES_CAUSE_EXTEND))
    {
        retVal |= CY_SYSLIB_RESET_OVDVCCD;
    }
    if (0U != _FLD2VAL(SRSS_RES_CAUSE_EXTEND_RESET_PXRES, SRSS_RES_CAUSE_EXTEND))
    {
        retVal |= CY_SYSLIB_RESET_PXRES;
    }
    if (0U != _FLD2VAL(SRSS_RES_CAUSE_EXTEND_RESET_STRUCT_XRES, SRSS_RES_CAUSE_EXTEND))
    {
        retVal |= CY_SYSLIB_RESET_STRUCT_XRES;
    }
    if (0U != _FLD2VAL(SRSS_RES_CAUSE_EXTEND_RESET_PORVDDD, SRSS_RES_CAUSE_EXTEND))
    {
        retVal |= CY_SYSLIB_RESET_PORVDDD;
    }
#endif
    return (retVal);
}


void Cy_SysLib_ClearResetReason(void)
{
    /* RES_CAUSE and RES_CAUSE2 register's bits are RW1C (every bit is cleared upon writing 1),
     * so write all ones to clear all the reset reasons.
     */
    SRSS_RES_CAUSE  = 0xFFFFFFFFU;
    SRSS_RES_CAUSE2 = 0xFFFFFFFFU;

    /* RES_CAUSE_EXTEND register bits are RW1C (every bit is cleared upon writing 1),
     * so write all ones to clear all the reset reasons.
     */
#if defined(CY_IP_MXS22SRSS) && (SRSS_POR_PRESENT)
    SRSS_RES_CAUSE_EXTEND = 0xFFFFFFFFU;
#endif /* defined(CY_IP_MXS22SRSS) && (SRSS_POR_PRESENT) */

    if(0U != _FLD2VAL(SRSS_PWR_HIBERNATE_TOKEN, SRSS_PWR_HIBERNATE))
    {
        /* Clears PWR_HIBERNATE token */
#if CY_CPU_CORTEX_M4 && defined (CY_DEVICE_SECURE)
        CY_PRA_REG32_CLR_SET(CY_PRA_INDX_SRSS_PWR_HIBERNATE, SRSS_PWR_HIBERNATE_TOKEN, 0UL);
#else
        SRSS_PWR_HIBERNATE &= ~SRSS_PWR_HIBERNATE_TOKEN_Msk;
#endif /* CY_CPU_CORTEX_M4 && defined (CY_DEVICE_SECURE) */
    }
}

#ifdef CY_IP_M4CPUSS
#if (CY_CPU_CORTEX_M0P)


void Cy_SysLib_SoftResetCM4(void)
{
    static uint32_t msg;

    msg = CY_IPC_DATA_FOR_CM4_SOFT_RESET;

    /* Tries to acquire the IPC structure and pass the arguments to SROM API.
    *  SROM API parameters:
    *   ipcPtr: IPC Structure 0 reserved for M0+ Secure Access.
    *   notifyEvent_Intr: 1U - IPC Interrupt Structure 1 is used for Releasing IPC 0 (M0+ NMI Handler).
    *   msgPtr: &msg - The address of SRAM with the API's parameters.
    */
    if(CY_IPC_DRV_SUCCESS != Cy_IPC_Drv_SendMsgPtr(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL_CM0), 1U, (void *) &msg))
    {
        CY_ASSERT(0U != 0U);
    }

    while(Cy_IPC_Drv_IsLockAcquired(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL_CM0)))
    {
        /* Waits until SROM API runs the command (sent over the IPC channel) and releases the IPC0 structure. */
    }
}
#endif /* CY_CPU_CORTEX_M0P || defined (CY_DOXYGEN) */


#if defined (CY_IP_M4CPUSS) && (!(defined (SRSS_HT_VARIANT) && (SRSS_HT_VARIANT == 1u)))

uint64_t Cy_SysLib_GetUniqueId(void)
{
    uint32_t uniqueIdHi;
    uint32_t uniqueIdLo;

    uniqueIdHi = ((uint32_t) SFLASH_DIE_YEAR        << (CY_UNIQUE_ID_DIE_YEAR_Pos  - CY_UNIQUE_ID_DIE_X_Pos)) |
                 (((uint32_t)SFLASH_DIE_MINOR & 1U) << (CY_UNIQUE_ID_DIE_MINOR_Pos - CY_UNIQUE_ID_DIE_X_Pos)) |
                 ((uint32_t) SFLASH_DIE_SORT        << (CY_UNIQUE_ID_DIE_SORT_Pos  - CY_UNIQUE_ID_DIE_X_Pos)) |
                 ((uint32_t) SFLASH_DIE_Y           << (CY_UNIQUE_ID_DIE_Y_Pos     - CY_UNIQUE_ID_DIE_X_Pos)) |
                 ((uint32_t) SFLASH_DIE_X);

    uniqueIdLo = ((uint32_t) SFLASH_DIE_WAFER       << CY_UNIQUE_ID_DIE_WAFER_Pos) |
                 ((uint32_t) SFLASH_DIE_LOT(2U)     << CY_UNIQUE_ID_DIE_LOT_2_Pos) |
                 ((uint32_t) SFLASH_DIE_LOT(1U)     << CY_UNIQUE_ID_DIE_LOT_1_Pos) |
                 ((uint32_t) SFLASH_DIE_LOT(0U));

    return (((uint64_t) uniqueIdHi << CY_UNIQUE_ID_DIE_X_Pos) | uniqueIdLo);
}
#endif /* defined (CY_IP_M4CPUSS) && (!(defined (SRSS_HT_VARIANT) && (SRSS_HT_VARIANT == 1u))) */
#endif


#if ((defined (CY_IP_M33SYSCPUSS) && defined(CY_IP_MXEFUSE)) && defined (CY_UNIQUE_DEVICE_ID_PRESENT_SFLASH))
#define CY_DIE_REG_EFUSE_OFFSET    0x74
#define CY_DIE_REG_COUNT           3U

uint64_t Cy_SysLib_GetUniqueId(void)
{
#if (!CY_UNIQUE_DEVICE_ID_PRESENT_SFLASH)
    uint32_t uniqueIdHi;
    uint32_t uniqueIdLo;
    uint32_t dieRead[3];
    cy_en_efuse_status_t status = CY_EFUSE_ERR_UNC;

    if(Cy_EFUSE_IsEnabled(EFUSE))
    {

        status = Cy_EFUSE_ReadWordArray(EFUSE, dieRead, CY_DIE_REG_EFUSE_OFFSET, CY_DIE_REG_COUNT);

        if(status == CY_EFUSE_SUCCESS)
        {
            uniqueIdHi = ((uint32_t)  _FLD2VAL(EFUSE_DATA_DIE_2_YEAR, dieRead[2])              << (CY_UNIQUE_ID_DIE_YEAR_Pos  - CY_UNIQUE_ID_DIE_X_Pos)) |
                         (((uint32_t)_FLD2VAL(EFUSE_DATA_DIE_2_REVISION_ID, dieRead[2]) & 1U)  << (CY_UNIQUE_ID_DIE_MINOR_Pos - CY_UNIQUE_ID_DIE_X_Pos)) |
                         ((uint32_t)  _FLD2VAL(EFUSE_DATA_DIE_1_SORT, dieRead[1])               << (CY_UNIQUE_ID_DIE_SORT_Pos  - CY_UNIQUE_ID_DIE_X_Pos)) |
                         ((uint32_t)  _FLD2VAL(EFUSE_DATA_DIE_1_Y, dieRead[1])                  << (CY_UNIQUE_ID_DIE_Y_Pos     - CY_UNIQUE_ID_DIE_X_Pos)) |
                         ((uint32_t)  _FLD2VAL(EFUSE_DATA_DIE_1_X, dieRead[1]));

            uniqueIdLo = (((uint32_t) _FLD2VAL(EFUSE_DATA_DIE_0_WAFER, dieRead[0])       << CY_UNIQUE_ID_DIE_WAFER_Pos) |
                         ((uint32_t) _FLD2VAL(EFUSE_DATA_DIE_0_LOT, dieRead[0])));

            return (((uint64_t) uniqueIdHi << CY_UNIQUE_ID_DIE_X_Pos) | uniqueIdLo);
        }
        else
        {
            return 0UL;
        }
    }
    else
    {
        return 0UL;
    }
#else
    uint32_t uniqueIdHi;
    uint32_t uniqueIdLo;

    uniqueIdHi = ((uint32_t) SFLASH_DIE_YEAR         << (CY_UNIQUE_ID_DIE_YEAR_Pos  - CY_UNIQUE_ID_DIE_X_Pos)) |
                 (((uint32_t)SFLASH_DIE_MINOR & 1U) << (CY_UNIQUE_ID_DIE_MINOR_Pos - CY_UNIQUE_ID_DIE_X_Pos)) |
                 ((uint32_t) SFLASH_DIE_SORT         << (CY_UNIQUE_ID_DIE_SORT_Pos  - CY_UNIQUE_ID_DIE_X_Pos)) |
                 ((uint32_t) SFLASH_DIE_Y            << (CY_UNIQUE_ID_DIE_Y_Pos    - CY_UNIQUE_ID_DIE_X_Pos)) |
                 ((uint32_t) SFLASH_DIE_X);

    uniqueIdLo = ((uint32_t) SFLASH_DIE_WAFER        << CY_UNIQUE_ID_DIE_WAFER_Pos) |
                 ((uint32_t) SFLASH_DIE_LOT(2U)      << CY_UNIQUE_ID_DIE_LOT_2_Pos) |
                 ((uint32_t) SFLASH_DIE_LOT(1U)      << CY_UNIQUE_ID_DIE_LOT_1_Pos) |
                 ((uint32_t) SFLASH_DIE_LOT(0U));

    return (((uint64_t) uniqueIdHi << CY_UNIQUE_ID_DIE_X_Pos) | uniqueIdLo);
#endif
}
#endif


#if ((defined (CY_IP_M33SYSCPUSS) || defined (CY_IP_M55APPCPUSS)) && defined(CY_IP_MXS22RRAMC))
#define _CY_DIE_REG_COUNT       (3U)

uint64_t Cy_SysLib_GetUniqueId(void)
{
    uint32_t uniqueIdHi = 0;
    uint32_t uniqueIdLo = 0;
    uint32_t revId = 0;
    uint32_t dieRead[_CY_DIE_REG_COUNT];

    for (uint32_t i = 0; i < _CY_DIE_REG_COUNT; i++)
    {
        dieRead[i] = CY_GET_REG32(CY_RRAM_PROTECTED_NS_SFLASH_DIE + (uint32_t)(i * sizeof(uint32_t)));
    }
    revId = CY_GET_REG32(CY_RRAM_PROTECTED_NS_SFLASH_SI_REV);

    uniqueIdLo = (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT0,  dieRead[0])) << CY_UNIQUE_ID_DIE_LOT_0_Pos |
                 (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT1,  dieRead[0])) << CY_UNIQUE_ID_DIE_LOT_1_Pos |
                 (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT2,  dieRead[0])) << CY_UNIQUE_ID_DIE_LOT_2_Pos |
                 (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_DIE_WAFER, dieRead[0])) << CY_UNIQUE_ID_DIE_WAFER_Pos;

    uniqueIdHi = (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_DIE_X,    dieRead[1])) << (CY_UNIQUE_ID_DIE_X_Pos     - CY_UNIQUE_ID_DIE_X_Pos) |
                 (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_DIE_Y,    dieRead[1])) << (CY_UNIQUE_ID_DIE_Y_Pos     - CY_UNIQUE_ID_DIE_X_Pos) |
                 (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_DIE_SORT, dieRead[1])) << (CY_UNIQUE_ID_DIE_SORT_Pos  - CY_UNIQUE_ID_DIE_X_Pos) |
                 (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_SI_REV_MINOR,  revId)) << (CY_UNIQUE_ID_DIE_MINOR_Pos - CY_UNIQUE_ID_DIE_X_Pos) |
                 (_FLD2VAL(CY_RRAM_PROTECTED_NS_SFLASH_DIE_YEAR, dieRead[2])) << (CY_UNIQUE_ID_DIE_YEAR_Pos  - CY_UNIQUE_ID_DIE_X_Pos);

    return (((uint64_t) uniqueIdHi << CY_UNIQUE_ID_DIE_X_Pos) | uniqueIdLo);
}
#endif

CY_SECTION_INIT_CODECOPY_END

#if (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED)


void Cy_SysLib_FaultHandler(uint32_t const *faultStackAddr)
{
    /* Stores general registers */
    cy_faultFrame.r0  = faultStackAddr[CY_R0_Pos];
    cy_faultFrame.r1  = faultStackAddr[CY_R1_Pos];
    cy_faultFrame.r2  = faultStackAddr[CY_R2_Pos];
    cy_faultFrame.r3  = faultStackAddr[CY_R3_Pos];
    cy_faultFrame.r12 = faultStackAddr[CY_R12_Pos];
    cy_faultFrame.lr  = faultStackAddr[CY_LR_Pos];
    cy_faultFrame.pc  = faultStackAddr[CY_PC_Pos];
    cy_faultFrame.psr = faultStackAddr[CY_PSR_Pos];

#if (defined (CY_IP_M4CPUSS) || defined (CY_IP_M7CPUSS) || CY_IP_M33SYSCPUSS || CY_IP_M55APPCPUSS)
#if (CY_CPU_CORTEX_M4 || (defined (CY_CPU_CORTEX_M7) && CY_CPU_CORTEX_M7) || \
     (defined (CY_CPU_CORTEX_M33) && CY_CPU_CORTEX_M33) || (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55))
    /* Stores the Configurable Fault Status Register state with the fault cause */
    cy_faultFrame.cfsr.cfsrReg = SCB->CFSR;
    /* Stores the Hard Fault Status Register */
    cy_faultFrame.hfsr.hfsrReg = SCB->HFSR;
    /* Stores the System Handler Control and State Register */
    cy_faultFrame.shcsr.shcsrReg = SCB->SHCSR;
    /* Store MemMange fault address */
    cy_faultFrame.mmfar = SCB->MMFAR;
    /* Store Bus fault address */
    cy_faultFrame.bfar = SCB->BFAR;

#if ((defined (__FPU_PRESENT) && (__FPU_PRESENT == 1U)) && \
     (defined (__FPU_USED   ) && (__FPU_USED    == 1U)))
    /* Checks cumulative exception bits for floating-point exceptions */
    if(0U != (__get_FPSCR() & (CY_FPSCR_IXC_Msk | CY_FPSCR_IDC_Msk)))
    {
        cy_faultFrame.s0    = faultStackAddr[CY_S0_Pos];
        cy_faultFrame.s1    = faultStackAddr[CY_S1_Pos];
        cy_faultFrame.s2    = faultStackAddr[CY_S2_Pos];
        cy_faultFrame.s3    = faultStackAddr[CY_S3_Pos];
        cy_faultFrame.s4    = faultStackAddr[CY_S4_Pos];
        cy_faultFrame.s5    = faultStackAddr[CY_S5_Pos];
        cy_faultFrame.s6    = faultStackAddr[CY_S6_Pos];
        cy_faultFrame.s7    = faultStackAddr[CY_S7_Pos];
        cy_faultFrame.s8    = faultStackAddr[CY_S8_Pos];
        cy_faultFrame.s9    = faultStackAddr[CY_S9_Pos];
        cy_faultFrame.s10   = faultStackAddr[CY_S10_Pos];
        cy_faultFrame.s11   = faultStackAddr[CY_S11_Pos];
        cy_faultFrame.s12   = faultStackAddr[CY_S12_Pos];
        cy_faultFrame.s13   = faultStackAddr[CY_S13_Pos];
        cy_faultFrame.s14   = faultStackAddr[CY_S14_Pos];
        cy_faultFrame.s15   = faultStackAddr[CY_S15_Pos];
        cy_faultFrame.fpscr = faultStackAddr[CY_FPSCR_Pos];
    }
#endif /* __FPU_PRESENT */
#endif /* CY_CPU_CORTEX_M4, CY_CPU_CORTEX_M7, CY_CPU_CORTEX_M33, CY_CPU_CORTEX_M55 */
#endif
    Cy_SysLib_ProcessingFault();
}


__WEAK void Cy_SysLib_ProcessingFault(void)
{
    #if defined(__ARMCC_VERSION)
        /* Assembly implementation of an infinite loop
         * is used for the armcc compiler to preserve the call stack.
         * Otherwise, the compiler destroys the call stack,
         * because treats this API as a no return function.
         */
        Cy_SysLib_AsmInfiniteLoop();
    #else
        while(true) {}
    #endif  /* (__ARMCC_VERSION) */
}
#endif /* (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) || defined(CY_DOXYGEN) */

CY_SECTION_INIT_CODECOPY_BEGIN
void Cy_SysLib_SetWaitStates(bool ulpMode, uint32_t clkHfMHz)
{
#if defined(CY_IP_M4CPUSS) || defined(CY_IP_M7CPUSS)
#if !((CY_CPU_CORTEX_M4) && (defined(CY_DEVICE_SECURE))) || defined(CY_IP_M7CPUSS)
    uint32_t waitStates;
    uint32_t freqMax;

#if defined(CY_IP_M7CPUSS)
    CY_ASSERT_L1(ulpMode == false);
#endif

#if defined(CY_IP_M7CPUSS)
    freqMax = CY_SYSLIB_LP_SLOW_WS_0_FREQ_MAX;
#else
    freqMax = ulpMode ? CY_SYSLIB_ULP_SLOW_WS_0_FREQ_MAX : CY_SYSLIB_LP_SLOW_WS_0_FREQ_MAX;
#endif
    waitStates = (clkHfMHz <= freqMax) ? 0UL : 1UL;

    /* ROM */
    CPUSS_ROM_CTL = _CLR_SET_FLD32U(CPUSS_ROM_CTL, CPUSS_ROM_CTL_SLOW_WS, waitStates);
    CPUSS_ROM_CTL = _CLR_SET_FLD32U(CPUSS_ROM_CTL, CPUSS_ROM_CTL_FAST_WS, 0UL);

    /* SRAM */
    CPUSS_RAM0_CTL0 = _CLR_SET_FLD32U(CPUSS_RAM0_CTL0, CPUSS_RAM0_CTL0_SLOW_WS, waitStates);
    CPUSS_RAM0_CTL0 = _CLR_SET_FLD32U(CPUSS_RAM0_CTL0, CPUSS_RAM0_CTL0_FAST_WS, 0UL);
    #if defined (RAMC1_PRESENT) && (RAMC1_PRESENT == 1UL)
        CPUSS_RAM1_CTL0 = _CLR_SET_FLD32U(CPUSS_RAM1_CTL0, CPUSS_RAM1_CTL0_SLOW_WS, waitStates);
        CPUSS_RAM1_CTL0 = _CLR_SET_FLD32U(CPUSS_RAM1_CTL0, CPUSS_RAM1_CTL0_FAST_WS, 0UL);
    #endif /* defined (RAMC1_PRESENT) && (RAMC1_PRESENT == 1UL) */
    #if defined (RAMC2_PRESENT) && (RAMC2_PRESENT == 1UL)
        CPUSS_RAM2_CTL0 = _CLR_SET_FLD32U(CPUSS_RAM2_CTL0, CPUSS_RAM2_CTL0_SLOW_WS, waitStates);
        CPUSS_RAM2_CTL0 = _CLR_SET_FLD32U(CPUSS_RAM2_CTL0, CPUSS_RAM2_CTL0_FAST_WS, 0UL);
    #endif /* defined (RAMC2_PRESENT) && (RAMC2_PRESENT == 1UL) */

    /* Flash */
#if defined(CY_IP_M7CPUSS)
    if (clkHfMHz <= CY_SYSLIB_LP_SLOW_WS_0_FREQ_MAX)
    {
        waitStates = 0UL;
    }
    else
    {
        waitStates = 1UL;
    }

    FLASHC_FLASH_CTL = _CLR_SET_FLD32U(FLASHC_FLASH_CTL, FLASHC_FLASH_CTL_WS, waitStates);

#else
    if (ulpMode)
    {
        waitStates =  (clkHfMHz <= CY_SYSLIB_FLASH_ULP_WS_0_FREQ_MAX) ? 0UL :
                     ((clkHfMHz <= CY_SYSLIB_FLASH_ULP_WS_1_FREQ_MAX) ? 1UL : 2UL);
    }
    else
    {
        waitStates =  (clkHfMHz <= cy_device->flashCtlMainWs0Freq) ? 0UL :
                     ((clkHfMHz <= cy_device->flashCtlMainWs1Freq) ? 1UL :
                     ((clkHfMHz <= cy_device->flashCtlMainWs2Freq) ? 2UL :
                     ((clkHfMHz <= cy_device->flashCtlMainWs3Freq) ? 3UL :
                     ((clkHfMHz <= cy_device->flashCtlMainWs4Freq) ? 4UL : 5UL))));
    }

    FLASHC_FLASH_CTL = _CLR_SET_FLD32U(FLASHC_FLASH_CTL, FLASHC_FLASH_CTL_MAIN_WS, waitStates);
#endif

#else
    (void) ulpMode;
    (void) clkHfMHz;
#endif /* !((CY_CPU_CORTEX_M4) && (defined(CY_DEVICE_SECURE))) || defined(CY_IP_M7CPUSS) */
#endif /* defined(CY_IP_M4CPUSS) || defined(CY_IP_M7CPUSS) */
#if (defined(CY_PDL_TZ_ENABLED) && defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
    uint32_t waitStates;

    if (ulpMode)
    {
        waitStates =  ((CY_SYSLIB_COEFFICIENT_ULP*clkHfMHz)/1000U)+1U;
    }
    else
    {
        waitStates =  ((CY_SYSLIB_COEFFICIENT*clkHfMHz)/1000U)+1U;
    }

    FLASHC_FLASH_CTL =_CLR_SET_FLD32U(FLASHC_FLASH_CTL, FLASHC_FLASH_CTL_RBUS_WS, waitStates);
#else
    (void) ulpMode;
    (void) clkHfMHz;
#endif
}


uint8_t Cy_SysLib_GetDeviceRevision(void)
{
#if defined (CY_IP_M4CPUSS) && !(defined (SRSS_HT_VARIANT) && (SRSS_HT_VARIANT == 1u))
    return ((SFLASH_SI_REVISION_ID == 0UL) ? CY_SYSLIB_DEVICE_REV_0A : SFLASH_SI_REVISION_ID);
#elif defined(CY_IP_M33SYSCPUSS) || defined(CY_IP_M7CPUSS) || (defined (SRSS_HT_VARIANT) && (SRSS_HT_VARIANT == 1u))
    return ((uint8_t)((_FLD2VAL(CPUSS_PRODUCT_ID_MINOR_REV, CPUSS_PRODUCT_ID) << 4U) | _FLD2VAL(CPUSS_PRODUCT_ID_MAJOR_REV, CPUSS_PRODUCT_ID)));
#else
    return 0;
#endif
}

uint16_t Cy_SysLib_GetDevice(void)
{
#if defined (CY_IP_M4CPUSS) && !(defined (SRSS_HT_VARIANT) && (SRSS_HT_VARIANT == 1u))
    return ((SFLASH_FAMILY_ID == 0UL) ? CY_SYSLIB_DEVICE_PSOC6ABLE2 : SFLASH_FAMILY_ID);
#elif defined(CY_IP_M33SYSCPUSS)
    return CPUSS_FAMILYID;
#else
    return 0;
#endif
}

#if  defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
void Cy_Syslib_SetWarmBootEntryPoint(uint32_t *entryPoint, bool enable)
{
    *(uint32_t *)CY_SYSPM_BOOTROM_ENTRYPOINT_ADDR = (uint32_t)entryPoint | (enable ? CY_SYSPM_BOOTROM_DSRAM_DBG_ENABLE_MASK : 0UL) ;
}

bool Cy_SysLib_IsDSRAMWarmBootEntry(void)
{
    return cy_WakeupFromWarmBootStatus;
}

void Cy_SysLib_ClearDSRAMWarmBootEntryStatus(void)
{
    cy_WakeupFromWarmBootStatus = false;
}
#endif


#if defined(CY_IP_MXS22SRSS) || defined(CY_IP_MXS40SSRSS)
cy_en_syslib_lcs_mode_t Cy_SysLib_GetDeviceLCS(cy_syslib_lcs_data_t *base)
{
    CY_ASSERT_L2(base);

    cy_en_syslib_lcs_mode_t lcsMode;

#if defined(CY_IP_MXS40SSRSS)
    lcsMode = (cy_en_syslib_lcs_mode_t)(base->BOOTROW);
#elif defined(CY_IP_MXS22SRSS)
    lcsMode = (cy_en_syslib_lcs_mode_t)(base->DECODED_LCS_DATA);
#else
    lcsMode = (cy_en_syslib_lcs_mode_t)(CY_GET_REG32(base));
#endif

    switch (lcsMode)
    {
        case CY_SYSLIB_LCS_VIRGIN:
        case CY_SYSLIB_LCS_SORT:
        case CY_SYSLIB_LCS_PROVISIONED:
        case CY_SYSLIB_LCS_NORMAL_PROVISIONED:
        case CY_SYSLIB_LCS_NORMAL:
        case CY_SYSLIB_LCS_SECURE:
        case CY_SYSLIB_LCS_NORMAL_NO_SECURE:
        case CY_SYSLIB_LCS_RMA:
        break;
        default:
            lcsMode = CY_SYSLIB_LCS_CORRUPTED;
        break;
    }

    return lcsMode;
}
#endif /* defined(CY_IP_MXS22SRSS) || defined(CY_IP_MXS40SSRSS) */

#if (((defined (CY_CPU_CORTEX_M7) && CY_CPU_CORTEX_M7) || (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55)) && (defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)))
bool Cy_Syslib_IsMemCacheable(MPU_Type* mpu, uint32_t addr, uint32_t size)
{
    uint32_t maxRegions;
    uint32_t en;
    uint8_t idx;
    uint32_t startAddr;
    bool ret = true;
#if (CY_CPU_CORTEX_M55)
    uint32_t endAddr;
    uint32_t attrIdx;
    uint32_t attribute;
    uint8_t reg;
    uint32_t pos;
    uint32_t mask;
#elif (CY_CPU_CORTEX_M7)
    uint32_t SIZE;
    uint32_t TEX;
    uint32_t C;
    uint32_t B;
#endif

    if ((NULL == mpu) || (size == (uint32_t)0))
    {
        return ret;
    }

    maxRegions = _FLD2VAL(MPU_TYPE_DREGION, mpu->TYPE);

    for (idx = 0; idx < maxRegions; idx++)
    {
        mpu->RNR = idx;
#if (CY_CPU_CORTEX_M55)
        en = _FLD2VAL(MPU_RLAR_EN, mpu->RLAR);
#elif (CY_CPU_CORTEX_M7)
        en = _FLD2VAL(MPU_RASR_ENABLE, mpu->RASR);
#endif

        if (en == 1U)
        {
#if (CY_CPU_CORTEX_M55)
            attrIdx = _FLD2VAL(MPU_RLAR_AttrIndx, mpu->RLAR);

            reg = (uint8_t)(attrIdx / 4U);
            pos = ((attrIdx % 4U) * 8U);
            mask = (uint32_t)((uint32_t)0x000000FFU << pos);

            if (reg >= (sizeof(mpu->MAIR) / sizeof(mpu->MAIR[0]))) {
                return ret; // invalid index
            }
            attribute = (uint8_t)((mpu->MAIR[reg] & mask) >> pos);
            startAddr = (uint32_t)(mpu->RBAR & MPU_RBAR_BASE_Msk);
            endAddr =  (uint32_t)(mpu->RLAR & MPU_RLAR_LIMIT_Msk);

            /*
                Check bit7:4 of outer attribute for non-cacheable region (0b0100 or 0x4)
                Check bit3:0 of inner attribute for non-cacheable region (0b0100 or 0x4)
                Thus the attribute is checked for 0x44
            */
            if ((attribute == (uint32_t)0x44) && (addr >= startAddr) && ((addr+size) <= endAddr))
            {
                ret = false;
                break;
            }
#elif (CY_CPU_CORTEX_M7)
            TEX = _FLD2VAL(MPU_RASR_TEX, mpu->RASR);
            C = _FLD2VAL(MPU_RASR_C, mpu->RASR);
            B = _FLD2VAL(MPU_RASR_B, mpu->RASR);
            startAddr = (uint32_t)(mpu->RBAR & MPU_RBAR_ADDR_Msk);
            SIZE = _FLD2VAL(MPU_RASR_SIZE, mpu->RASR);

            /*
                Check Type Extension field (TEX) bit21:19 for 0b001
                Check Cacheable bit17 for 0b0
                Check Bufferable bit16 for 0b0
            */
            if ((TEX == 1U) && (C == 0U) && (B == 0U) && (addr >= startAddr) && \
                ((addr+size) <= (startAddr + (1UL << (SIZE+1UL)))))
            {
                ret = false;
                break;
            }
#endif
        }
        else
        {
            // Nothing to be done
        }
    }
    return ret;
}
#endif // (((defined (CY_CPU_CORTEX_M7) && CY_CPU_CORTEX_M7) || (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55)) && (defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)))

CY_SECTION_INIT_CODECOPY_END

#endif /* CY_IP_M33SYSCPUSS, CY_IP_M4CPUSS */

/* [] END OF FILE */
