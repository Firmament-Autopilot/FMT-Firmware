/***************************************************************************//**
* \file mtb_syspm_callbacks_pdm_pcm.h
*
* Description:
* Provides a high level interface for syspm callbacks for the PDM_PCM IP.
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
#include "mtb_syspm_callbacks_hw_resources.h"

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_AUDIOSS_PDM)
#include "mtb_syspm_callbacks_audioss_pdm.h"
#endif // (MTB_SYSPM_CALLBACKS_AVAILABLE_AUDIOSS_PDM)

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_MX_PDM)
#include "mtb_syspm_callbacks_mxpdm.h"
#endif // (MTB_SYSPM_CALLBACKS_AVAILABLE_MX_PDM)

#if defined(__cplusplus)
extern "C" {
#endif

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1, \
                             'Rule requires const attributes for inputs but signature for following APIs needs to match requested one in PDL');

/**
 * \addtogroup mtb_syspm_group_pdm_pcm PDM PCM Deep Sleep Callback
 * \{
 * Implementation of the PDM PCM Deep Sleep callback
 */

/**Context Reference Structure for PDM_PCM peripheral in case of DeepSleep */
typedef struct
{
    uint8_t      channelNum;    /**< Number of the PDM channel */
} mtb_syspm_pdm_pcm_deepsleep_context_t;

/** Deepsleep callback for PDM_PCM IP
 *
 * @param[in] params    The param structure for the callback for which the context element should be
 * of type \ref mtb_syspm_pdm_pcm_deepsleep_context_t
 * @param[in] mode      The callback mode
 * @return Returns CY_SYSPM_SUCCESS if successful, an error code otherwise
 */
cy_en_syspm_status_t mtb_syspm_pdm_pcm_deepsleep_callback(
    cy_stc_syspm_callback_params_t* params,
    cy_en_syspm_callback_mode_t mode);


#if defined(__cplusplus)
}
#endif

/** \} mtb_syspm_group_pdm_pcm */
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13');
