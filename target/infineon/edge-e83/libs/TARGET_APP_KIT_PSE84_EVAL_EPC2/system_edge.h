/***************************************************************************//**
* \file system_edge.h
* \version 1.0
*
* \brief PSOC Edge Device system header file.
*
********************************************************************************
* \copyright
* Copyright 2016-2025 Cypress Semiconductor Corporation
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


#ifndef _SYSTEM_EDGE_H_
#define _SYSTEM_EDGE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "cyip_mxcm55.h"
#include "system_pse84.h"
#include "partition_edge.h"

#define CY_SYSTEM_CPU_M0P    (__CORTEX_M == 0U)    /**< CM0+ core CPU Code */
#define CY_SYSTEM_CPU_M55     (__CORTEX_M == 55U)   /**< CM55 core CPU Code */
#define CY_SYSTEM_CPU_M33     (__CORTEX_M == 33U)   /**< CM33 core CPU Code */


/** \cond INTERNAL */
/* Deprecated enumerator names. Do not use them in the new design. */
#define APPCPUSS_DBG_INVASSIVE_MODE                APPCPUSS_DBG_INVASIVE_MODE
#define APPCPUSS_DBG_TRACES_NON_INVASSIVE_MODE     APPCPUSS_DBG_TRACES_NON_INVASIVE_MODE

/* BWC defines for CM33, CM55 and U55 related functions */
#define Cy_SysEnableCM55(A, B, C)    Cy_SysCM55Enable(A, B, APPCPUSS_DBG_ENABLE_ALL, C)
#define Cy_SysDisableCM55            Cy_SysCM55Disable
#define Cy_SysResetCM55(A, B)        Cy_SysCM55Reset(A, B)
#define Cy_SysGetCM55Status(A)       Cy_SysCM55GetStatus(A)
#define Cy_System_SetCM55DbgPort(A)  Cy_SysCM55SetDbgPort(A)
#define Cy_SysEnableCM33(A, B)       Cy_SysCM33Enable(A, B)
#define Cy_SysResetCM33(A, B)        Cy_SysCM33Reset(A, B)
#define Cy_SysGetCM33Status          Cy_SysCM33GetStatus
#define Cy_SysEnableU55(A)           Cy_SysU55Enable(A)
/** \endcond */

/**
* \addtogroup group_system_enums
* \{
*/
/** APPCPU debug port control */
typedef enum
{
  APPCPUSS_DBG_DISABLE = 0, /**< Disable debug port for CM55 */
  APPCPUSS_DBG_INVASIVE_MODE = 1,/**< Enables invasive debug CM55 */
  APPCPUSS_DBG_TRACES_NON_INVASIVE_MODE = 2,/**< Enables all trace and non-invasive debug features */
  APPCPUSS_DBG_ENABLE_ALL = 3, /**< Enables invasive debug & all trace and non-invasive enable for CM55 */
} cy_app_cpu_dbg_port_type_t;


/** \} group_system_enums */

/**
* \addtogroup group_system_config_user_settings_macro_edge
* \{
*/

#if !defined (CY_CORTEX_M33_NS_APPL_ADDR)
/** The Cortex-M33 non secure application start address, corresponds to the location of the
 *  vector table. This is the default address in the case of main cm33_ns execution out of
 *  external flash. */
    #define CY_CORTEX_M33_NS_APPL_ADDR                (0x08340400)
#endif /* (CY_CORTEX_M33_NS_APPL_ADDR) */

#if !defined(CY_CM55_APP_BOOT_ADDR)
/** The Cortex-M55 application start address, corresponds to the location of the
 *  vector table. This is the default address in the case of main cm33_ns execution out of
 *  external flash. */
#define CY_CM55_APP_BOOT_ADDR                         (0x60580400)
#endif

#if !defined (CY_CORTEX_M55_APPL_ADDR)
/** Alternate define for CY_CM55_APP_BOOT_ADDR*/
    #define CY_CORTEX_M55_APPL_ADDR                   (CY_CM55_APP_BOOT_ADDR)
#endif /* (CY_CORTEX_M55_APPL_ADDR) */

/** \} group_system_config_user_settings_macro_edge */


#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  \brief CMSE void function pointer
*/
typedef void (*cy_cmse_funcptr) (void) __attribute__((cmse_nonsecure_call));
#endif // (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)

/**
  \brief System Clock Frequency (Core Clock)
*/
extern uint32_t SystemCoreClock;

/**
  \brief Setup the microcontroller system.
   Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);


/**
  \brief  Update SystemCoreClock variable.
   Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

/**
  \brief  Setup SystemCoreClock variable.
   Sets the SystemCoreClock with initial core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockSetup (uint32_t systemCoreClk_freq_hz, uint32_t ahb_freq_hz);


/* TODO: Do we need to put this block inside CM33 core flag? */
/**
* \addtogroup group_system_config_core_status_macro_edge
* \{
*/
#define CY_SYS_CORE_STATUS_ACTIVE     (0x0U)    /**< The core is in Active mode */
#define CY_SYS_CORE_STATUS_SLEEP      (0x1U)    /**< The core is in sleep mode */
#define CY_SYS_CORE_STATUS_DEEPSLEEP  (0x3U)    /**< The core is in deep sleep mode */
#define CY_SYS_CORE_STATUS_INVALID    (0x2U)    /**< Invalid core state */

#define CY_SYS_CORE_WAIT_INFINITE     (0x0U)    /**< Wait in a loop for Infinite micro second */

/** \} group_system_config_core_status_macro_edge */

/**
* \addtogroup group_system_config_cm55_functions_edge
* \{
*/

#if (CY_SYSTEM_CPU_M33 == 1UL) || defined(CY_DOXYGEN)
uint32_t Cy_SysCM55GetStatus(MXCM55_Type *CM55Base);
void Cy_SysCM55Enable(MXCM55_Type *CM55Base, uint32_t vectorTableOffset, cy_app_cpu_dbg_port_type_t dbgMode, uint32_t waitus);
void Cy_SysCM55Disable(void);
void Cy_SysCM55Reset(MXCM55_Type *CM55Base, uint32_t waitus);
void Cy_SysEnableSOCMEM(bool enable);
void Cy_System_EnablePD1(void);
void Cy_System_DisablePD1(void);
void Cy_SysCM55SetDbgPort(cy_app_cpu_dbg_port_type_t dbgMode);
#endif /* (CY_SYSTEM_CPU_M33 == 1UL) || defined(CY_DOXYGEN) */
#if (CY_SYSTEM_CPU_M55 == 1UL) || defined(CY_DOXYGEN)
void Cy_SysU55Enable(bool enable);
#endif /* (CY_SYSTEM_CPU_M55 == 1UL) || defined(CY_DOXYGEN) */


/** \} group_system_config_cm55_functions_edge */

/**
* \addtogroup group_system_config_cm33_functions_edge
* \{
*/
#if (CY_SYSTEM_CPU_M0P == 1UL) || defined(CY_DOXYGEN)
uint32_t Cy_SysCM33GetStatus(void);
void Cy_SysCM33Enable(uint32_t vectorTableOffset, uint32_t waitus);
void Cy_SysCM33Reset(uint32_t waitus);
#endif /* (CY_SYSTEM_CPU_M0P == 1UL) || defined(CY_DOXYGEN) */

/**
 *****************************************************************************
 ** \brief  CBUS address remap
 **  remap address for masters on CBUS
 **
 ** \param [in]  addr  pointer to be remap
 **
 ** \retval remap address
 **
 *****************************************************************************/
static inline uint32_t cy_CbusRemapAddr(const void *addr)
{
  uint32_t remapAddr, offset;

  /* SRAM Address */
  if (((uint32_t)addr >= CY_SRAM_BASE) &&
      ((uint32_t)addr < (CY_SRAM_BASE + CY_SRAM_SIZE)))
  {
    offset = (uint32_t)addr - CY_SRAM_BASE;
    remapAddr = CY_SRAM_CBUS_BASE + offset;
  } /* SOCMEM Address */
  else if (((uint32_t)addr >= CY_SOCMEM_RAM_BASE) &&
      ((uint32_t)addr < (CY_SOCMEM_RAM_BASE + CY_SOCMEM_RAM_SIZE)))
  {
    offset = (uint32_t)addr - CY_SOCMEM_RAM_BASE;
    remapAddr = CY_SOCMEM_RAM_CBUS_BASE + offset;
  }
  /* XIP is mapped with offset */
  else if (((uint32_t)addr >= CY_XIP_PORT0_BASE) &&
      ((uint32_t)addr < (CY_XIP_PORT1_BASE + CY_XIP_PORT1_SIZE)))
  {
    offset = (uint32_t)addr - CY_XIP_PORT0_BASE;
    remapAddr =  CY_XIP_PORT0_CBUS_BASE + offset;
  }
  /* RRAM Address */
  else if (((uint32_t)addr >= CY_RRAM_CBUS_BASE) &&
      ((uint32_t)addr < (CY_RRAM_CBUS_BASE + CY_RRAM_SIZE)))
  {
    offset = (uint32_t)addr - CY_RRAM_CBUS_BASE;
    remapAddr = CY_RRAM_BASE + offset;
  }/* no remapping, addr not in range */
  else
  {
    remapAddr = (uint32_t)addr;
  }
  return remapAddr;
}

/**
 *****************************************************************************
 ** \brief  AHB address remap
 **  remap address for masters
 **
 ** \param [in]  addr  pointer to be remap
 **
 ** \retval remap address
 **
 *****************************************************************************/
static inline uint32_t cy_AhbRemapAddr(const void *addr)
{
  uint32_t remapAddr, offset;

  /* SRAM Address */
  if (((uint32_t)addr >= CY_SRAM_CBUS_BASE) &&
      ((uint32_t)addr < (CY_SRAM_CBUS_BASE + CY_SRAM_SIZE)))
  {
    offset = (uint32_t)addr - CY_SRAM_CBUS_BASE;
    remapAddr = CY_SRAM_BASE + offset;
  }
  /* SOCMEM Address */
  else if (((uint32_t)addr >= CY_SOCMEM_RAM_CBUS_BASE) &&
      ((uint32_t)addr < (CY_SOCMEM_RAM_CBUS_BASE + CY_SOCMEM_RAM_SIZE)))
  {
    offset = (uint32_t)addr - CY_SOCMEM_RAM_CBUS_BASE;
    remapAddr = CY_SOCMEM_RAM_BASE + offset;
  }
  /* XIP is mapped with offset */
  else if (((uint32_t)addr >= CY_XIP_PORT0_CBUS_BASE) &&
      ((uint32_t)addr < (CY_XIP_PORT1_CBUS_BASE + CY_XIP_PORT1_SIZE)))
  {
    offset = (uint32_t)addr - CY_XIP_PORT0_CBUS_BASE;
    remapAddr =  CY_XIP_PORT0_BASE + offset;
  }
  /* RRAM is mapped with offset */
  else if (((uint32_t)addr >= CY_RRAM_BASE) &&
      ((uint32_t)addr < (CY_RRAM_BASE + CY_RRAM_SIZE)))
  {
    offset = (uint32_t)addr - CY_RRAM_BASE;
    remapAddr = CY_RRAM_CBUS_BASE + offset;
  }/* no remapping, addr not in range */
  else
  {
    remapAddr = (uint32_t)addr;
  }
  return remapAddr;
}


#if defined(CORE_NAME_CM55_0)
/**
 *****************************************************************************
 ** \brief  DTCM address remap
 **  remap address for masters
 **
 ** \param [in]  addr  pointer to be remap
 **
 ** \retval remap address
 **
 *****************************************************************************/
#define CY_CM55_DTCM_REMAP_BASE 0x48040000UL

static inline uint32_t cy_DTCMRemapAddr(const void *addr)
{
  uint32_t remapAddr, offset;

  /* DTCM  Address */
  if (((uint32_t)addr >= CY_CM55_DTCM_INTERNAL_BASE) &&
      ((uint32_t)addr < (CY_CM55_DTCM_INTERNAL_BASE + CY_CM55_DTCM_INTERNAL_SIZE)))
  {
    offset = (uint32_t)addr - CY_CM55_DTCM_INTERNAL_BASE;
    remapAddr = CY_CM55_DTCM_REMAP_BASE + offset;
  } /* DTCM Address */
  else
  {
    remapAddr = (uint32_t)addr;
  }
  return remapAddr;
}

/**
 *****************************************************************************
 ** \brief  DTCM Internal address remap
 **  Internal address for CPU access
 **
 ** \param [in]  addr  pointer to be remap
 **
 ** \retval internal remap address
 **
 *****************************************************************************/
static inline uint32_t cy_DTCMInternalRemapAddr(const void *addr)
{
  uint32_t remapAddr, offset;

  /* DTCM  Address */
  if (((uint32_t)addr >= CY_CM55_DTCM_REMAP_BASE) &&
      ((uint32_t)addr < (CY_CM55_DTCM_REMAP_BASE + CY_CM55_DTCM_INTERNAL_SIZE)))
  {
    offset = (uint32_t)addr - CY_CM55_DTCM_REMAP_BASE;
    remapAddr = CY_CM55_DTCM_INTERNAL_BASE + offset;
  } /* Internal DTCM Address */
  else
  {
    remapAddr = (uint32_t)addr;
  }
  return remapAddr;
}
#endif

/**
 *****************************************************************************
 ** \brief  DTCM/CBUS address remap
 **  remap address for masters
 **
 ** \param [in]  addr  pointer to be remap
 **
 ** \retval remap address
 **
 *****************************************************************************/
#if defined(CORE_NAME_CM33_0)
#define CY_REMAP_ADDRESS_CBUS_TO_SAHB(addr)    ((void *)cy_AhbRemapAddr(addr))
#elif defined(CORE_NAME_CM55_0)
#define CY_REMAP_ADDRESS_CBUS_TO_SAHB(addr)    ((void *)cy_DTCMRemapAddr(addr))
#endif

/**
 *****************************************************************************
 ** \brief  DTCM alias/SAHB address remap
 **  remap address for masters
 **
 ** \param [in]  addr  pointer to be remap
 **
 ** \retval remap address
 **
 *****************************************************************************/
#if defined(CORE_NAME_CM33_0)
#define CY_REMAP_ADDRESS_SAHB_TO_CBUS(addr)    ((void *)cy_CbusRemapAddr(addr))
#elif defined(CORE_NAME_CM55_0)
#define CY_REMAP_ADDRESS_SAHB_TO_CBUS(addr)    ((void *)cy_DTCMInternalRemapAddr(addr))
#endif

/** \} group_system_config_cm33_functions_edge */

#ifdef __cplusplus
}
#endif

#endif /* _SYSTEM_EDGE_H_ */


/* [] END OF FILE */
