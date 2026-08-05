/***************************************************************************//**
* \file cy_syspm_srf.h
* \version 2.100
*
* \brief
* This file provides macros and exposes operations for the APIs for the Secure Aware SYSPM.
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
* \addtogroup group_syspm_srf
* \{
* Internal operation declarations to enable Secure Aware SYSPM.
*   \defgroup group_syspm_srf_enums    Enums
*/

#pragma once

#include "mtb_srf.h"
#include "cycfg_ppc.h"

#if !defined(CY_PDL_ENABLE_SECURE_AWARE_SYSPM)
/** SYSPM Secure Aware Driver enablement.  Set to 0 via Makefile defines to disable. When not manually set,
 * defaults to the PDL-wide Secure Aware Driver enablement status.
*/
#define CY_PDL_ENABLE_SECURE_AWARE_SYSPM (CY_PDL_ENABLE_SECURE_AWARE)
#endif /* !defined(CY_PDL_ENABLE_SECURE_AWARE_SYSPM) */

#if !defined(_CY_PDL_SYSPM_PPC_SECURED)
/*
 * The below syspm srf operations show it access which PPC regions respectively.
 * If we have to run below secure-aware APIs via SRF, we have to configure the PPC regions as secure attribute.
 * Otherwise it causes PPC hardfault.
 * CY_PDL_SYSPM_OP_CPUENTERSLEEP:
 * CY_PDL_SYSPM_OP_CPUENTERDEEPSLEEP: CYCFG_PPC_SECURED_SRSS_MAIN
 * CY_PDL_SYSPM_OP_SYSTEMENTERHIBERNATE: CYCFG_PPC_SECURED_SRSS_MAIN/CYCFG_PPC_SECURED_SRSS_HIB_DATA
 * CY_PDL_SYSPM_OP_GETPROGRAMMEDPWRMODE: CYCFG_PPC_SECURED_PWRMODE_PWRMODE
 * CY_PDL_SYSPM_OP_SETPWRMODE: CYCFG_PPC_SECURED_PWRMODE_PWRMODE/CYCFG_PPC_SECURED_M55APPCPUSS
 * CY_PDL_SYSPM_OP_ISLPMREADY: CYCFG_PPC_SECURED_SRSS_MAIN
 * CY_PDL_SYSPM_OP_SYSCM55ENABLE: CYCFG_PPC_SECURED_APPCPUSS_AP/CYCFG_PPC_SECURED_PWRMODE_PWRMODE/CYCFG_PPC_SECURED_M55APPCPUSS/CYCFG_PPC_SECURED_MXCM55_CM55/CYCFG_PPC_SECURED_MXCM55_CM55_NS
 * CY_PDL_SYSPM_OP_SYSCM55RESET: CYCFG_PPC_SECURED_MXCM55_CM55/CYCFG_PPC_SECURED_MXCM55_CM55_NS
 * CY_PDL_SYSPM_OP_SYSCM55DISABLE: CYCFG_PPC_SECURED_M55APPCPUSS
 */
#define _CY_PDL_SYSPM_PPC_SECURED               (CYCFG_PPC_SECURED_SRSS_MAIN || CYCFG_PPC_SECURED_SRSS_HIB_DATA || CYCFG_PPC_SECURED_PWRMODE_PWRMODE || CYCFG_PPC_SECURED_M55APPCPUSS)
#endif /* !defined(_CY_PDL_SYSPM_PPC_SECURED) */

#if !defined(_CY_PDL_SYSPM_PPC_SECURED_MXCM55_CM55)
#define _CY_PDL_SYSPM_PPC_SECURED_MXCM55_CM55   (CYCFG_PPC_SECURED_MXCM55_CM55 || CYCFG_PPC_SECURED_MXCM55_CM55_NS)
#endif /* !defined(_CY_PDL_SYSPM_PPC_SECURED_MXCM55_CM55) */

#if (CY_PDL_ENABLE_SECURE_AWARE_SYSPM && _CY_PDL_SYSPM_PPC_SECURED)
/* Inform the PDL to use SRF for SYSPM - only if Secure Aware SYSPM is enabled and the SYSPM PPC region is secured */
#define CY_PDL_SYSPM_ENABLE_SRF_INTEG       (1)
#endif

#if defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
#if !((CYCFG_PPC_SECURED_SRSS_MAIN && CYCFG_PPC_SECURED_SRSS_HIB_DATA && CYCFG_PPC_SECURED_PWRMODE_PWRMODE && CYCFG_PPC_SECURED_M55APPCPUSS && CYCFG_PPC_SECURED_APPCPUSS_AP) || \
      (!CYCFG_PPC_SECURED_SRSS_MAIN && !CYCFG_PPC_SECURED_SRSS_HIB_DATA && !CYCFG_PPC_SECURED_PWRMODE_PWRMODE && !CYCFG_PPC_SECURED_M55APPCPUSS && !CYCFG_PPC_SECURED_APPCPUSS_AP))
    #error "Unsupported PPC regions' security state: SRSS_MAIN, SRSS_HIB_DATA, PWRMODE_PWRMODE, APPCPUSS_AP and M55APPCPUSS PPC regions must all be configured to the same security state"
#endif

#if !((CYCFG_PPC_SECURED_MXCM55_CM55 && CYCFG_PPC_SECURED_MXCM55_CM55_NS) || (!CYCFG_PPC_SECURED_MXCM55_CM55 && !CYCFG_PPC_SECURED_MXCM55_CM55_NS))
    #error "Unsupported PPC regions' security state: MXCM55_CM55 and MXCM55_CM55_NS PPC regions must all be configured to the same security state"
#endif
#endif

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
/* Specifiy SYSPM SRF pool timeout value in microseconds. */
#define CY_PDL_SYSPM_SRF_POOL_TIMEOUT       0UL
#endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */

/**
* \addtogroup group_syspm_srf_enums
* \{
*/
/** SYSPM Secure Operation IDs */
typedef enum
{
    CY_PDL_SYSPM_OP_CPUENTERSLEEP,          /**< Cy_SYSPM_CpuEnterSleep */
    CY_PDL_SYSPM_OP_CPUENTERDEEPSLEEP,      /**< Cy_SYSPM_CpuEnterDeepSleep */
    CY_PDL_SYSPM_OP_SYSTEMENTERHIBERNATE,   /**< Cy_SYSPM_SystemEnterHibernate */
    CY_PDL_SYSPM_OP_GETPROGRAMMEDPWRMODE,   /**< Cy_SYSPM_GetProgrammedPwrMode */
    CY_PDL_SYSPM_OP_SETPWRMODE,             /**< Cy_SYSPM_SetPwrMode */
    CY_PDL_SYSPM_OP_ISLPMREADY,             /**< Cy_SYSPM_IsLpmReady */
    CY_PDL_SYSPM_OP_SYSCM55ENABLE,          /**< Cy_SYSPM_SysCM55Enable */
    CY_PDL_SYSPM_OP_SYSCM55RESET,           /**< Cy_SYSPM_SysCM55Reset */
    CY_PDL_SYSPM_OP_SYSCM55DISABLE,         /**< Cy_SYSPM_SysCM55Disable */
    CY_PDL_SYSPM_OP_MAX,                    /**< Maximum operation ID for bounds checking */
} cy_syspm_srf_op_id_t;

/** \} group_syspm_srf_enums */

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
/** Array of SYSPM Secure Operations */
extern mtb_srf_op_s_t _cy_pdl_syspm_srf_operations[(uint32_t)CY_PDL_SYSPM_OP_MAX];
#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */

/** \} group_syspm_srf */
