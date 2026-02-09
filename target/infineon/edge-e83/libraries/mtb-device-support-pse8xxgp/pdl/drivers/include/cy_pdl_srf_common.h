/***************************************************************************//**
* \file cy_pdl_srf_common.h
* \version 1.0
*
* \brief
* This file provides helpers / shared code between the various Secure Aware drivers.
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


#pragma once

/**
* \addtogroup group_pdl_srf_common
* \{
* Internal helpers for common code between the Secure Aware PDL drivers.
*   \defgroup group_pdl_srf_common_funcs    Functions
*   \defgroup group_pdl_srf_common_structs  Data Structures
*/

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "cy_syslib.h"
#include "cy_pdl_srf.h"
#include "mtb_srf.h"

#if (!defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_ENABLE_SECURE_AWARE)) || defined(CY_DOXYGEN)

/**
* \addtogroup group_pdl_srf_common_structs
* \{
*/

/** A struct containing information required to pass through the SRF, specifically through
 * the _Cy_PDL_Invoke_SRF API. */
typedef struct
{
    mtb_srf_invec_ns_t*     inVec;          /**< An array of input vectors */
    mtb_srf_outvec_ns_t*    outVec;         /**< An array of output vectors */
    mtb_srf_output_ns_t**   output_ptr;     /**< A double pointer for the helper to set to the output structure */
    uint8_t                 op_id;          /**< The operation ID, e.g. CY_PDL_RTC_OP_GET_DATETIME */
    uint32_t                submodule_id;   /**< The PDL submodule, see cy_pdl_submodule_t. */
    void*                   base;           /**< The base address of the hardware resource the request is for.
                                                 Set to NULL if not needed */
    uint32_t                sub_block;      /**< The sub-block of the hardware resource the request is for.  Set
                                                 to 0 if not needed. */
    uint8_t*                input_base;     /**< Request input_values */
    size_t                  input_len;      /**< Length of the request input_values */
    uint8_t*                output_base;    /**< Output struct output_values */
    size_t                  output_len;     /**< Length of the output struct's output_values */
    void**                  invec_bases;    /**< Base addresses of inVec[1,2], as needed.  Set to NULl if not needed. */
    size_t*                 invec_sizes;    /**< Size of inVec[1,2]. Ignored if invec_bases is NULL. */
    void**                  outvec_bases;   /**< Base addresses of outVec[1,2], as needed.  Set to NULl if not needed. */
    size_t*                 outvec_sizes;   /**< Size of outVec[1]. Ignored if outvec1_base is NULL. */
} cy_pdl_invoke_srf_args;

/** \} group_pdl_srf_common_structs */

/**
* \addtogroup group_pdl_srf_common_funcs
* \{
*/

/*******************************************************************************
* Function Name: _Cy_PDL_Invoke_SRF
****************************************************************************//**
*
* A helper to package and submit a secure request.  The purpose is this is to isolate
* all internal SRF knowledge in the PDL to one location.
*
* \param args
* All arguments required to perform an SRF request submission
*
* \return
* The result of the mtb_srf_request_submit call.
*
*******************************************************************************/
cy_rslt_t _Cy_PDL_Invoke_SRF(cy_pdl_invoke_srf_args* args);

/** \} group_pdl_srf_common_funcs */

#endif /* !defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_ENABLE_SECURE_AWARE) */

/** \} group_pdl_srf_common */
