/***************************************************************************//**
* \file cy_pdl_srf.h
* \version 1.0
*
* \brief
* This file contains the PDL SRF module registration and information on the sub-modules.
*
********************************************************************************
* \copyright
* Copyright(c) 2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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
*******************************************************************************/


/**
* \addtogroup group_pdl_srf
* \{
* This file contains the cy_pdl_srf_module_register API.  This must be called on
* the secure side during startup after Secure Request Framework (SRF) initialization
* in order to call Secure Aware PDL APIs.
*
* \section group_pdl_srf_general Secure Aware PDL
* Some APIs are marked as Secure Aware.  This means that if the driver's hardware resource
* is marked as a secure resource in the Peripheral Protection Controller (PPC) and these APIs
* are called from a non-secure CPU state, the PDL will submit a request to the Secure Request
* Framework (SRF) middleware to transition to a secure CPU state to perform the operation.
* From the application's perspective, the API will behave the same whether it is called from
* a secure or non-secure CPU state albeit slower.
*
* Note that the inverse is not supported - calling to an API that operates on a non-secured
* resource from a secure CPU state will not be automatically handled and will result in a PPC
* fault. To perform this action legally, abide by ARM guidelines for calling to NS from S.
*
* The general rule is
* 1. Secure-aware APIs:
*      Some of these APIs involve multiple PPC regions. See the documentation for individual APIs
*      for restrictions on how these PPC regions must be configured relative to each other.
*      Custom PPC configurations which do not meet the requirements of a security API may be handled as follows:
*      1. Access to secure resources from a non-secure processing environment can be enabled
*         by creating a custom secure operation. See the secure request framework documentation for details.
*      2. Access to a non-secure resource from a secure processing environment may be achieved either
*         by following ARM's "guidelines for calling to NS from S" or by using the `GET_NSALIAS_ADDRESS` macro.
* 2. Non Secure-aware APIs:
*      All involved PPC regions should be either secure (calling to the API in secure CPU state) or
*      non-secure (calling to the API in non-secure CPU state).
*
* This functionality is automatically enabled on devices with ARM TrustZone processors. To
* disable all driver Secure Awareness, set the DEFINE+=CY_PDL_ENABLE_SECURE_AWARE=0 in the
* application Makefile.  To disable specific drivers, each has a matching macro that can be
* used in the same way, e.g. RTC has CY_PDL_ENABLE_SECURE_AWARE_RTC.  See individual driver
* documentation for specific macro names.
*
* Marking a hardware resource as Non-Secure via the PPC in the device configurator will also
* disable the Secure Aware driver to save memory during secure image compilation.  For drivers
* with multiple hardware resource instances (e.g. SCBs), the Secure Aware APIs will take the
* default or SRF route depending on if the instance they're invoked on is Secured.  If all
* resources are marked Non-Secure, the Secure Aware driver will be disabled.
*
* Secure Awareness is only relevent on APIs which interact with hardware resources. APIs which
* do not interact with hardware resources have notes in the API's function header comments
* documenting that they are safe to call from either state.
*
* \section group_pdl_srf_setup Setup
* The Secure Aware PDL that requires a shared request pool (see SRF documentation) is setup for
* it to allocate requests from.  This pool is initialized by default as part of cybsp_init on the
* Non-Secure CPU.
*
* The \ref cy_pdl_srf_module_register API must be called with the default cybsp_secure_context
* secure context to register the secure operations for SRF to reference.  This is similarly done
* as part of cybsp_init, but on the Secure CPU.
*   \defgroup group_pdl_srf_macros   Macros
*   \defgroup group_pdl_srf_enums    Enums
*   \defgroup group_pdl_srf_funcs    Functions
*/

#pragma once

#include "mtb_srf.h"
#include "cy_syslib.h"
#include "cycfg_ppc.h"
#if !defined(COMPONENT_SECURE_DEVICE)
#include "mtb_srf_pool.h"
/* BSP must implement and initialize our default pool, cy_pdl_srf_default_pool */
extern mtb_srf_pool_t cy_pdl_srf_default_pool;
#endif

#if !defined(MTB_SRF_MODULE_PDL)
#error Please define MTB_SRF_MODULE_PDL in the mtb_srf_config.h to enable Secure Aware PDL
#endif

/**
* \addtogroup group_pdl_srf_macros
* \{
*/
#if !defined(CY_PDL_ENABLE_SECURE_AWARE) && !defined(CY_SRF_DISABLE)
/** PDL-wide Secure Aware Driver enablement.  Set to 0 to disable all Secure Aware Drivers */
#define CY_PDL_ENABLE_SECURE_AWARE (1)
#endif /* !defined(CY_PDL_ENABLE_SECURE_AWARE) */

/** SRF Integration identifier */
#define CY_PDL_SRF_ID                                   (CY_PDL_DRV_ID(0x66U))

/** \} group_pdl_srf_macros */

/**
* \addtogroup group_pdl_srf_enums
* \{
*/
/** SRF Integration status enumeration */
typedef enum
{
    CY_PDL_SRF_SUCCESS      = 0x00U,                                        /**< Successful */
    CY_PDL_SRF_BAD_PARAM    = CY_PDL_SRF_ID | CY_PDL_STATUS_ERROR | 0x01U,  /**< One or more invalid parameters */
} cy_en_srf_status_t;

#include "cy_rtc_srf.h"
#include "cy_smif_srf.h"
#include "cy_sysclk_srf.h"
#include "cy_syspm_srf.h"


/* Ordering in this enum must exactly match ordering in cy_pdl_srf_operations and cy_pdl_srf_num_operations
 * Note that submodule indices are not fixed, but that is okay because nobody should refer to them by numeric
 * value. */
typedef enum
{
#if defined(CY_PDL_RTC_ENABLE_SRF_INTEG)
    CY_PDL_SECURE_SUBMODULE_RTC,
#endif /* defined(CY_PDL_RTC_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    CY_PDL_SECURE_SUBMODULE_SMIF,
#endif /* defined(CY_PDL_SMIF_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
    CY_PDL_SECURE_SUBMODULE_SYSCLK,
#endif /* defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    CY_PDL_SECURE_SUBMODULE_SYSPM,
#endif /* defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */
    CY_PDL_SECURE_SUBMODULE_END, /* One greater than max submodule */
} cy_pdl_submodule_t;

/** \} group_pdl_srf_enums */

#if (defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_ENABLE_SECURE_AWARE)) || defined(CY_DOXYGEN)
/**
* \addtogroup group_pdl_srf_funcs
* \{
*/
/*******************************************************************************
* Function Name: cy_pdl_srf_module_register
****************************************************************************//**
*
* Registers the PDL module with an SRF context.
*
* \note
* If all driver PPC regions are set to Non-Secure, this API does nothing.
*
* \param context
* The SRF context with which the PDL is registered with

* \return
* Status of the registration request.
*
*******************************************************************************/
cy_rslt_t cy_pdl_srf_module_register(mtb_srf_context_s_t* context);
/** \} group_pdl_srf_funcs */

#endif /* defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_ENABLE_SECURE_AWARE) */

/** \} group_pdl_srf */
