/***********************************************************************************************//**
 * \file cybsp.h
 *
 * \brief
 * Basic API for setting up boards containing a Cypress MCU.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
 *
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
 **************************************************************************************************/

#pragma once

#include "cy_result.h"
#include "cybsp_types.h"
#include "cybsp_hw_config.h"
#include "cy_ipc_sema.h"
#if defined(COMPONENT_WICED_BLE) || defined(COMPONENT_WICED_DUALMODE)
#include "cybsp_bt_config.h"
#endif
#if defined(COMPONENT_MW_MTB_SRF)
#include "mtb_srf.h"
#if defined(COMPONENT_MW_MTB_IPC) && !defined(COMPONENT_SECURE_DEVICE)
#include "mtb_ipc.h"
#include "mtb_srf_ipc_init.h"
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * \addtogroup group_bsp_errors Error Codes
 * \{
 * Error codes specific to the board.
 */

/** Protection context 2 */
#define CYBSP_PC2        (2U)

/** Failed to configure sysclk power management callback */
#define CYBSP_RSLT_ERR_SYSCLK_PM_CALLBACK  \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_BSP, 0))

/** \} group_bsp_errors */

/**
 * \addtogroup group_bsp_externs Externs
 * \{
 * Global structures exposed by the BSP
 */
#if (CY_SYSTEM_CPU_M33) && !defined(COMPONENT_SECURE_DEVICE)
extern cy_stc_ipc_sema_t cybsp_ipc_sema;
#endif
#if defined(COMPONENT_MW_MTB_SRF) && !defined(CYBSP_DISABLE_SRF_INIT)
#if defined(COMPONENT_SECURE_DEVICE)
extern mtb_srf_context_s_t cybsp_srf_context;
#else
#if defined(COMPONENT_MW_MTB_IPC)
#if (CY_SYSTEM_CPU_M55)
/** Context for the SRF client */
extern mtb_srf_ipc_client_context_t cybsp_mtb_srf_client_context;
/** Instance of MTB IPC on the CM55 setup by SRF */
extern mtb_ipc_t cybsp_cm55_ipc_instance;
#elif (CY_SYSTEM_CPU_M33)
/** Context for the SRF relay */
extern mtb_srf_ipc_relay_context_t cybsp_mtb_srf_relay_context;
/** Instance of MTB IPC on the CM33 setup by SRF*/
extern mtb_ipc_t cybsp_cm33_ipc_instance;
#endif // (CY_SYSTEM_CPU_M55)
#endif // defined(COMPONENT_MW_MTB_IPC)
#endif // defined(COMPONENT_SECURE_DEVICE)
#endif // defined(COMPONENT_MW_MTB_SRF) && !defined(CYBSP_DISABLE_SRF_INIT)
/** \} group_bsp_externs */

/**
 * \addtogroup group_bsp_functions Functions
 * \{
 * All functions exposed by the board.
 */

/**
 * \brief Initialize all hardware on the board
 * \returns CY_RSLT_SUCCESS if the board is successfully initialized, if there is
 *          a problem initializing any hardware it returns an error code specific
 *          to the hardware module that had a problem.
 */
cy_rslt_t cybsp_init(void);

#if defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
//--------------------------------------------------------------------------------------------------
// cybsp_register_custom_sysclk_pm_callback
//
// Registers a power management callback that prepares the clock system for entering deep sleep mode
// and restore the clocks upon wakeup from deep sleep. The application should implement this
// function and define `CYBSP_CUSTOM_SYSCLK_PM_CALLBACK` if it needs to replace the default SysClk
// DeepSleep callback behavior with application specific logic.
// NOTE: This is called automatically as part of \ref cybsp_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t cybsp_register_custom_sysclk_pm_callback(void);
#endif // defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)

/** \} group_bsp_functions */
#ifdef __cplusplus
}
#endif // __cplusplus
