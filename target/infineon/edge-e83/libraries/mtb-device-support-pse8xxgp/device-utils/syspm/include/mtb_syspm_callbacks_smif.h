/***************************************************************************//**
* \file mtb_syspm_callbacks_smif.h
*
* Description:
* Provides a high level interface for syspm callbacks for the SMIF IP.
*
********************************************************************************
* \copyright
* Copyright 2024-2024 Cypress Semiconductor Corporation (an Infineon company) or
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
*******************************************************************************/
#pragma once
#include "cy_pdl.h"

#if defined(__cplusplus)
extern "C" {
#endif

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1, \
                             'Rule requires const attributes for inputs but signature for following APIs needs to match requested one in PDL');

/**
 * \addtogroup mtb_syspm_group_smif SMIF Deep Sleep Callback
 * \{
 * Implementation of the SMIF Deep Sleep callback
 */

/**Context Reference Structure for SMIF peripheral in case of DeepSleep */
typedef struct
{
    cy_stc_smif_context_t*      smif_context; /**< Context of the SMIF IP */
    uint32_t                    smif_crypto_input1; /**< Content of SMIF_CRYPTO_INPUT1 register */
    uint32_t                    smif_crypto_input2; /**< Content of SMIF_CRYPTO_INPUT2 register */
    uint32_t                    smif_crypto_input3; /**< Content of SMIF_CRYPTO_INPUT3 register */
} mtb_syspm_smif_deepsleep_context_t;

/** Deepsleep callback for SMIF IP
 *
 * @param[in] params    The param structure for the callback for which the context element should be
 * of type \ref mtb_syspm_smif_deepsleep_context_t
 * @param[in] mode      The callback mode
 * @return Returns CY_SYSPM_SUCCESS if successful, an error code otherwise
 * \note If the application is stored in external memory of the device, this callback should have
 * order
 * as high as possible to reenable the correct access to extenral memory.
 */
cy_en_syspm_status_t mtb_syspm_smif_deepsleep_callback(
    cy_stc_syspm_callback_params_t* params,
    cy_en_syspm_callback_mode_t mode);
#if defined(__cplusplus)
}
#endif

/** \} mtb_syspm_group_smif */
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13');
