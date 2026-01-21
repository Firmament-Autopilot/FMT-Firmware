/**
 *******************************************************************************
 * @file  system_wl32f436.h
 * @brief This file contains all the functions prototypes of the WL32 System.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2023, wlhc Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by WLHC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#ifndef __SYSTEM_WL32F436_H__
#define __SYSTEM_WL32F436_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "wl32_ll_def.h"
#include "wl32f436.h"
#include "wl32f4xx_conf.h"

/**
 * @addtogroup CMSIS
 * @{
 */

/**
 * @addtogroup WL32F436_System
 * @{
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('define')
 ******************************************************************************/
/**
 * @addtogroup WL32F436_System_Global_Macros
 * @{
 */

/**
 * @addtogroup WL32F436_System_Clock_Source
 * @{
 */
#if !defined (MRC_VALUE)
#define MRC_VALUE                       (8000000UL)     /*!< Internal middle speed RC freq. */
#endif

#if !defined (LRC_VALUE)
#define LRC_VALUE                       (32768UL)       /*!< Internal low speed RC freq. */
#endif

#if !defined (RTCLRC_VALUE)
#define RTCLRC_VALUE                    (32768UL)       /*!< Internal RTC low speed RC freq. */
#endif

#if !defined (SWDTLRC_VALUE)
#define SWDTLRC_VALUE                   (10000UL)       /*!< Internal SWDT low speed RC freq. */
#endif

#if !defined (XTAL_VALUE)
#define XTAL_VALUE                      (16000000UL)     /*!< External high speed OSC freq. */
#endif

#if !defined (XTAL32_VALUE)
#define XTAL32_VALUE                    (32768UL)       /*!< External low speed OSC freq. */
#endif

#if !defined (HCLK_VALUE)
#define HCLK_VALUE                      (SystemCoreClock >> ((CM_CMU->SCFGR & CMU_SCFGR_HCLKS) >> CMU_SCFGR_HCLKS_POS))
#endif

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/
/**
 * @addtogroup WL32F436_System_Exported_Variable
 * @{
 */

extern uint32_t SystemCoreClock;        /*!< System clock frequency (Core clock) */
#define NOW_SYSTEM_CORE_CLOCK 336000000
extern uint32_t HRC_VALUE;              /*!< HRC frequency */

/**
 * @}
 */

/*******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
/**
 * @addtogroup WL32F436_System_Global_Functions
 * @{
 */

extern void SystemInit(void);             /*!< Initialize the system */
extern void SystemCoreClockUpdate(void);  /*!< Update SystemCoreClock variable */

#if defined (ROM_EXT_QSPI)
void SystemInit_QspiMem(void);
#endif

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_WL32F436_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
