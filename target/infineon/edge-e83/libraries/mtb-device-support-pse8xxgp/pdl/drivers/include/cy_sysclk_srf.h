/***************************************************************************//**
* \file cy_sysclk_srf.h
* \version 2.100
*
* \brief
* This file provides macros and exposes secure operations for the APIs for the SYSCLK.
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
* \addtogroup group_sysclk_srf
* \{
* Internal operation declarations to enable Secure Aware SYSCLK.
*   \defgroup group_sysclk_srf_enums    Enums
*/

#include "mtb_srf.h"

#if !defined(CY_PDL_ENABLE_SECURE_AWARE_SYSCLK)
/** SYSCLK Secure Aware Driver enablement.  Set to 0 via Makefile defines to disable. When not manually set,
 * defaults to the PDL-wide Secure Aware Driver enablement status.
*/
#define CY_PDL_ENABLE_SECURE_AWARE_SYSCLK           (CY_PDL_ENABLE_SECURE_AWARE)
#endif /* !defined(CY_PDL_ENABLE_SECURE_AWARE_SYSCLK) */

/* Rename non-obvious region names, and cluster regions that share implementations */
#if !defined(_CY_PDL_SYSCLK_PPC_SECURED_HF)
#define _CY_PDL_SYSCLK_PPC_SECURED_HF		        (CYCFG_PPC_SECURED_SRSS_MAIN)
#endif /* !defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) */

#if !defined(_CY_PDL_SYSCLK_PPC_SECURED_LF)
#define _CY_PDL_SYSCLK_PPC_SECURED_LF		        (CYCFG_PPC_SECURED_SRSS_MAIN)
#endif /* !defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) */

#if !defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK        (CYCFG_PPC_SECURED_PERI_PCLK0_MAIN || CYCFG_PPC_SECURED_PERI_PCLK1_MAIN)
#endif /* !defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) */

/* Not all Peri Groups have CLOCK_CTL registers - only enable Secure Awareness if present.  Attempting to call a PDL API that uses
 * the CLOCK_CTL register on a Peri Group without one does nothing - do nothing faster by skipping the SRF call. */
#if defined(PERI0_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR0_GROUP  (CYCFG_PPC_SECURED_PERI0_GR0_GROUP && PERI0_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR0_GROUP  (0)
#endif /* PERI0_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI0_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR1_GROUP  (CYCFG_PPC_SECURED_PERI0_GR1_GROUP && PERI0_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR1_GROUP  (0)
#endif /* PERI0_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI0_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR2_GROUP  (CYCFG_PPC_SECURED_PERI0_GR2_GROUP && PERI0_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR2_GROUP  (0)
#endif /* PERI0_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI0_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR3_GROUP  (CYCFG_PPC_SECURED_PERI0_GR3_GROUP && PERI0_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR3_GROUP  (0)
#endif /* PERI0_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI0_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR4_GROUP  (CYCFG_PPC_SECURED_PERI0_GR4_GROUP && PERI0_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR4_GROUP  (0)
#endif /* PERI0_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI0_GROUP_PRESENT5_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR5_GROUP  (CYCFG_PPC_SECURED_PERI0_GR5_GROUP && PERI0_GROUP_PRESENT5_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR5_GROUP  (0)
#endif /* PERI0_GROUP_PRESENT5_PERI_GROUP_CLOCK_PRESENT */

#if defined(PERI1_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR0_GROUP  (CYCFG_PPC_SECURED_PERI1_GR0_GROUP && PERI1_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR0_GROUP  (0)
#endif /* PERI1_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI1_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR1_GROUP  (CYCFG_PPC_SECURED_PERI1_GR1_GROUP && PERI1_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR1_GROUP  (0)
#endif /* PERI1_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI1_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR2_GROUP  (CYCFG_PPC_SECURED_PERI1_GR2_GROUP && PERI1_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR2_GROUP  (0)
#endif /* PERI1_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI1_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR3_GROUP  (CYCFG_PPC_SECURED_PERI1_GR3_GROUP && PERI1_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR3_GROUP  (0)
#endif /* PERI1_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT */
#if defined(PERI1_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR4_GROUP  (CYCFG_PPC_SECURED_PERI1_GR4_GROUP && PERI1_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT)
#else
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR4_GROUP  (0)
#endif /* PERI1_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT */

#if !defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP)
#define _CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP    (_CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR0_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR1_GROUP || \
                                                     _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR2_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR3_GROUP || \
                                                     _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR4_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR5_GROUP || \
                                                     _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR0_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR1_GROUP || \
                                                     _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR2_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR3_GROUP || \
                                                     _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR4_GROUP)
#endif /* !defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) */

#if (CY_PDL_ENABLE_SECURE_AWARE_SYSCLK && (_CY_PDL_SYSCLK_PPC_SECURED_HF || _CY_PDL_SYSCLK_PPC_SECURED_LF || _CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK || _CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP))
/* Inform the PDL to use SRF for SYSCLK - only if Secure Aware SYSCLK is enabled and the SYSCLK PPC region is secured */
#define CY_PDL_SYSCLK_ENABLE_SRF_INTEG   (1)
#endif

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
/* Specifiy SYSCLK SRF pool timeout value in microseconds. */
#define CY_PDL_SYSCLK_SRF_POOL_TIMEOUT   0UL
#endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */

#if defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
#if !( ((CYCFG_PPC_SECURED_SRSS_MAIN) && (CYCFG_PPC_SECURED_SRSS_GENERAL)) || \
       (!(CYCFG_PPC_SECURED_SRSS_MAIN) && !(CYCFG_PPC_SECURED_SRSS_GENERAL)) )
    #error "Unsupported PPC regions' security state: SRSS_MAIN and SRSS_GENERAL PPC regions must all be configured to the same security state"
#endif

#if ( (!(CYCFG_PPC_SECURED_SRSS_MAIN) && !(CYCFG_PPC_SECURED_SRSS_GENERAL)) && \
      (CYCFG_PPC_SECURED_PERI_PCLK0_MAIN || CYCFG_PPC_SECURED_PERI_PCLK1_MAIN) )
    #error "Unsupported PPC regions' security state: PERI_PCLKx_MAIN PPC regions must be configured to non-secure if SRSS_MAIN and SRSS_GENERAL PPC regions are non-secure"
#endif

#if ( (!(CYCFG_PPC_SECURED_SRSS_MAIN) && !(CYCFG_PPC_SECURED_SRSS_GENERAL)) && \
      (_CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR0_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR1_GROUP || \
       _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR2_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR3_GROUP || \
       _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR4_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR5_GROUP) )
    /* Only the PERI0_GRx_GROUPs with CLOCK_CTL registers matter - see PERI0_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT, etc. */
    #error "Unsupported PPC regions' security state: PERI0_GRx_GROUP PPC regions must be configured to non-secure if SRSS_MAIN and SRSS_GENERAL PPC regions are non-secure"
#endif

#if ( (!(CYCFG_PPC_SECURED_SRSS_MAIN) && !(CYCFG_PPC_SECURED_SRSS_GENERAL)) && \
      (_CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR0_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR1_GROUP || \
       _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR2_GROUP || _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR3_GROUP || \
       _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR4_GROUP) )
    /* Only the PERI1_GRx_GROUPs with CLOCK_CTL registers matter - see PERI1_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT, etc. */
    #error "Unsupported PPC regions' security state: PERI1_GRx_GROUP PPC regions must be configured to non-secure if SRSS_MAIN and SRSS_GENERAL PPC regions are non-secure"
#endif

#endif /* defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */

/**
* \addtogroup group_sysclk_srf_enums
* \{
*/
/** SYSCLK Secure Operation IDs */
typedef enum
{
#if (defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF)) || defined(CY_DOXYGEN)
    /** \brief HF CLK operations */
    CY_PDL_SYSCLK_OP_HF_IS_ENABLED,            /**< Cy_SysClk_ClkHfIsEnabled */
    CY_PDL_SYSCLK_OP_HF_GET_DIV,               /**< Cy_SysClk_ClkHfGetDivider */
    CY_PDL_SYSCLK_OP_HF_SET_DIV,               /**< Cy_SysClk_ClkHfSetDivider */
    CY_PDL_SYSCLK_OP_HF_GET_FREQ,              /**< Cy_SysClk_ClkHfGetFrequency */
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF) */
#if (defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF)) || defined(CY_DOXYGEN)
    /** \brief CLK_LF operations */
    CY_PDL_SYSCLK_OP_CLKLF_GET_FREQ,            /**< Cy_SysClk_ClkLfGetFrequency */
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF) */
#if (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP)) || defined(CY_DOXYGEN)
    /** \brief PERI Groups operations */
    CY_PDL_SYSCLK_OP_PERI_GET_DIV,             /**< Cy_SysClk_PeriGroupGetDivider */
    CY_PDL_SYSCLK_OP_PERI_SET_DIV,             /**< Cy_SysClk_PeriGroupSetDivider */
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) */
#if (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK)) || defined(CY_DOXYGEN)
    /** \brief PERI Dividers operations */
    CY_PDL_SYSCLK_OP_PERIPCLK_GET_DIV,         /**< Cy_SysClk_PeriPclkGetDivider */
    CY_PDL_SYSCLK_OP_PERIPCLK_SET_DIV,         /**< Cy_SysClk_PeriPclkSetDivider */
    CY_PDL_SYSCLK_OP_PERIPCLK_GET_FRAC_DIV,    /**< Cy_SysClk_PeriPclkGetFracDivider */
    CY_PDL_SYSCLK_OP_PERIPCLK_SET_FRAC_DIV,    /**< Cy_SysClk_PeriPclkSetFracDivider */
    CY_PDL_SYSCLK_OP_PERIPCLK_GET_ASSN_DIV,    /**< Cy_SysClk_PeriPclkGetAssignedDivider */
    CY_PDL_SYSCLK_OP_PERIPCLK_ENABLE_DIV,      /**< Cy_SysClk_PeriPclkEnableDivider */
    CY_PDL_SYSCLK_OP_PERIPCLK_DISABLE_DIV,     /**< Cy_SysClk_PeriPclkDisableDivider */
    CY_PDL_SYSCLK_OP_PERIPCLK_GET_FREQ,        /**< Cy_SysClk_PeriPclkGetFrequency */
    CY_PDL_SYSCLK_OP_PERIPCLK_GET_DIV_ENABLED, /**< Cy_SysClk_PeriPclkGetDividerEnabled */
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) */
    CY_PDL_SYSCLK_OP_MAX,                      /**< Maximum operation ID for bounds checking */
} cy_sysclk_srf_op_id_t;
/** \} group_sysclk_srf_enums */

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
/** Array of SYSCLK Secure Operations */
extern mtb_srf_op_s_t _cy_pdl_sysclk_srf_operations[(uint32_t)CY_PDL_SYSCLK_OP_MAX];
#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */

/** \} group_sysclk_srf */
