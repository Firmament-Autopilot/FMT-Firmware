/***************************************************************************//**
* \file cy_smif_srf.h
* \version 2.100
*
* \brief
* This file provides macros and exposes operations for the APIs for the Secure Aware Serial Memory Interface (SMIF).
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
* \addtogroup group_smif_srf
* \{
* Internal operation declarations to enable Secure Aware SMIF.
*   \defgroup group_smif_srf_enums    Enums
*/

#include "mtb_srf.h"
#include "cycfg_ppc.h"

#if !defined(CY_PDL_ENABLE_SECURE_AWARE_SMIF)
/** SMIF Secure Aware Driver enablement.  Set to 0 via Makefile defines to disable. When not manually set,
 * defaults to the PDL-wide Secure Aware Driver enablement status.
*/
#define CY_PDL_ENABLE_SECURE_AWARE_SMIF (CY_PDL_ENABLE_SECURE_AWARE)
#endif /* !defined(CY_PDL_ENABLE_SECURE_AWARE_SMIF) */

#if !defined(_CY_PDL_SMIF0_PPC_SECURED)
/** Macro to identify instance 0 of the SMIF driver as secured */
#define _CY_PDL_SMIF0_PPC_SECURED       (CYCFG_PPC_SECURED_SMIF0_CORE_MAIN || CYCFG_PPC_SECURED_SMIF0_CORE_CRYPTO || CYCFG_PPC_SECURED_SMIF0_CORE_MAIN2 || CYCFG_PPC_SECURED_SMIF0_CORE_DEVICE)
#endif /* !defined(_CY_PDL_SMIF0_PPC_SECURED) */

#if !defined(_CY_PDL_SMIF1_PPC_SECURED)
/** Macro to identify instance 1 of the SMIF driver as secured */
#define _CY_PDL_SMIF1_PPC_SECURED       (CYCFG_PPC_SECURED_SMIF1_CORE_MAIN || CYCFG_PPC_SECURED_SMIF1_CORE_CRYPTO || CYCFG_PPC_SECURED_SMIF1_CORE_MAIN2 || CYCFG_PPC_SECURED_SMIF1_CORE_DEVICE)
#endif /* !defined(_CY_PDL_SMIF1_PPC_SECURED) */

/** Macro to identify the SMIF driver as secured */
#define _CY_PDL_SMIF_PPC_SECURED        (_CY_PDL_SMIF0_PPC_SECURED || _CY_PDL_SMIF1_PPC_SECURED)

#if (CY_PDL_ENABLE_SECURE_AWARE_SMIF && _CY_PDL_SMIF_PPC_SECURED)
/* Inform the PDL to use SRF for SMIF - only if Secure Aware SMIF is enabled and the SMIF PPC region is secured */
#define CY_PDL_SMIF_ENABLE_SRF_INTEG   (1)
#endif

#if defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
#if !((CYCFG_PPC_SECURED_SMIF0_CORE_MAIN && CYCFG_PPC_SECURED_SMIF0_CORE_CRYPTO && CYCFG_PPC_SECURED_SMIF0_CORE_MAIN2 && CYCFG_PPC_SECURED_SMIF0_CORE_DEVICE) || \
        (!CYCFG_PPC_SECURED_SMIF0_CORE_MAIN && !CYCFG_PPC_SECURED_SMIF0_CORE_CRYPTO && !CYCFG_PPC_SECURED_SMIF0_CORE_MAIN2 && !CYCFG_PPC_SECURED_SMIF0_CORE_DEVICE))
    #error "Unsupported PPC regions' security state: SMIF0_CORE_MAIN, SMIF0_CORE_CRYPTO, SMIF0_CORE_MAIN2, and SMIF0_CORE_DEVICE PPC regions must all be configured to the same security state"
#endif

#if !((CYCFG_PPC_SECURED_SMIF1_CORE_MAIN && CYCFG_PPC_SECURED_SMIF1_CORE_CRYPTO && CYCFG_PPC_SECURED_SMIF1_CORE_MAIN2 && CYCFG_PPC_SECURED_SMIF1_CORE_DEVICE) || \
        (!CYCFG_PPC_SECURED_SMIF1_CORE_MAIN && !CYCFG_PPC_SECURED_SMIF1_CORE_CRYPTO && !CYCFG_PPC_SECURED_SMIF1_CORE_MAIN2 && !CYCFG_PPC_SECURED_SMIF1_CORE_DEVICE))
    #error "Unsupported PPC regions' security state: SMIF1_CORE_MAIN, SMIF1_CORE_CRYPTO, SMIF1_CORE_MAIN2, and SMIF1_CORE_DEVICE PPC regions must all be configured to the same security state"
#endif
#endif

/**
* \addtogroup group_smif_srf_enums
* \{
*/
/** SMIF Secure Operation IDs */
typedef enum
{
    CY_PDL_SMIF_OP_MEM_GET_INFO,       /**< Cy_SMIF_MemNumGetInfo                         */
    CY_PDL_SMIF_OP_MEM_READ,           /**< Cy_SMIF_MemNumRead                            */
    CY_PDL_SMIF_OP_MEM_WRITE,          /**< Cy_SMIF_MemNumWrite                           */
    CY_PDL_SMIF_OP_MEM_ERASE_SECTOR,   /**< Cy_SMIF_MemNumEraseSector                     */
    CY_PDL_SMIF_OP_MEM_ERASE_CHIP,     /**< Cy_SMIF_MemNumEraseChip                       */
    CY_PDL_SMIF_OP_HB_READ,            /**< Cy_SMIF_MemNumHyperBusRead                    */
    CY_PDL_SMIF_OP_HB_WRITE,           /**< Cy_SMIF_MemNumHyperBusWrite                   */
    CY_PDL_SMIF_OP_CLEAN_CACHE,        /**< Cy_SMIF_Clean_Cache_by_Addr                   */
    CY_PDL_SMIF_OP_INVALIDATE_CACHE,   /**< Cy_SMIF_Invalidate_Cache_by_Addr              */
    CY_PDL_SMIF_OP_CL_INV_CACHE,       /**< Cy_SMIF_Clean_And_Invalidate_Cache_by_Addr    */
    CY_PDL_SMIF_OP_MAX,                /**< Maximum operation ID for bounds checking       */
} cy_smif_srf_op_id_t;

/** \} group_smif_srf_enums */

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
/** Array of SMIF Secure Operations */
extern mtb_srf_op_s_t _cy_pdl_smif_srf_operations[(uint32_t)CY_PDL_SMIF_OP_MAX];
#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG) */


/** \} group_smif_srf */
