/***************************************************************************//**
* \file cy_rtc_srf.h
* \version 2.100
*
* \brief
* This file provides macros and exposes operations for the APIs for the Secure Aware Real-Time Clock (RTC).
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
* \addtogroup group_rtc_srf
* \{
* Internal operation declarations to enable Secure Aware RTC.
*   \defgroup group_rtc_srf_enums    Enums
*/

#include "mtb_srf.h"
#include "cycfg_ppc.h"

#if !defined(CY_PDL_ENABLE_SECURE_AWARE_RTC)
/** RTC Secure Aware Driver enablement.  Set to 0 via Makefile defines to disable. When not manually set,
 * defaults to the PDL-wide Secure Aware Driver enablement status.
*/
#define CY_PDL_ENABLE_SECURE_AWARE_RTC (CY_PDL_ENABLE_SECURE_AWARE)
#endif /* !defined(CY_PDL_ENABLE_SECURE_AWARE_RTC) */

#if !defined(_CY_PDL_RTC_PPC_SECURED_RTC)
/** Macro to identify the RTC driver as secured */
#define _CY_PDL_RTC_PPC_SECURED_RTC             (CYCFG_PPC_SECURED_RTC_BACKUP)
#endif /* !defined(_CY_PDL_RTC_PPC_SECURED_RTC) */

#if (CY_PDL_ENABLE_SECURE_AWARE_RTC && _CY_PDL_RTC_PPC_SECURED_RTC)
/* Inform the PDL to use SRF for RTC - only if Secure Aware RTC is enabled and the RTC PPC region is secured */
#define CY_PDL_RTC_ENABLE_SRF_INTEG   (1)
#endif

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_RTC_ENABLE_SRF_INTEG)
/* Specifiy RTC SRF pool timeout value in microseconds. */
#define CY_PDL_RTC_SRF_POOL_TIMEOUT   1000UL
#endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_RTC_ENABLE_SRF_INTEG) */

/**
* \addtogroup group_rtc_srf_enums
* \{
*/
/** RTC Secure Operation IDs */
typedef enum
{
    CY_PDL_RTC_OP_GET_DATETIME,     /**< Cy_RTC_GetDateAndTime */
    CY_PDL_RTC_OP_GET_HR_FORMAT,    /**< Cy_RTC_GetHoursFormat */
    CY_PDL_RTC_OP_MAX,              /**< Maximum operation ID for bounds checking */
} cy_rtc_srf_op_id_t;
/** \} group_rtc_srf_enums */

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_RTC_ENABLE_SRF_INTEG)
/** Array of RTC Secure Operations */
extern mtb_srf_op_s_t _cy_pdl_rtc_srf_operations[(uint32_t)CY_PDL_RTC_OP_MAX];
#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_RTC_ENABLE_SRF_INTEG) */

/** \} group_rtc_srf */
