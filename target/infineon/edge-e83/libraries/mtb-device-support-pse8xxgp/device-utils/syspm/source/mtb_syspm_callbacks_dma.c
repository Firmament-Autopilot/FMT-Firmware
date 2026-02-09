/***************************************************************************//**
* \file mtb_syspm_callbacks_dma.c
*
* Description:
* Provides the implementation for syspm callbacks for the DMA IP.
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

#include "cy_pdl.h"
#include "cy_utils.h"
#include "mtb_syspm_callbacks_dma.h"

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_DMA_DW)
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1, \
                             'Rule requires const attributes for inputs but signature for following APIs needs to match requested one in PDL');
//--------------------------------------------------------------------------------------------------
// mtb_syspm_dma_dw_deepsleep_callback
//--------------------------------------------------------------------------------------------------
cy_en_syspm_status_t mtb_syspm_dma_dw_deepsleep_callback(
    cy_stc_syspm_callback_params_t* params,
    cy_en_syspm_callback_mode_t mode)
{
    bool allow = true;
    const mtb_syspm_dma_deepsleep_context_t* context =
        (mtb_syspm_dma_deepsleep_context_t*)(params->context);
    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
            if (_mtb_syspm_dma_dw_is_active(params, context->channelNum))
            {
                allow = false;
            }
            else
            {
                //Do nothing
            }
            break;

        default:
            allow = true;
            break;
    }
    if (allow)
    {
        return CY_SYSPM_SUCCESS;
    }
    else
    {
        return CY_SYSPM_FAIL;
    }
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13');

#endif // (MTB_SYSPM_CALLBACKS_AVAILABLE_DMA_DW)

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_DMA_DMAC)
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1, \
                             'Rule requires const attributes for inputs but signature for following APIs needs to match requested one in PDL');
//--------------------------------------------------------------------------------------------------
// mtb_syspm_dma_dmac_deepsleep_callback
//--------------------------------------------------------------------------------------------------
cy_en_syspm_status_t mtb_syspm_dma_dmac_deepsleep_callback(
    cy_stc_syspm_callback_params_t* params,
    cy_en_syspm_callback_mode_t mode)
{
    bool allow = true;
    const mtb_syspm_dma_deepsleep_context_t* context =
        (mtb_syspm_dma_deepsleep_context_t*)(params->context);
    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
            if (_mtb_syspm_dma_dmac_is_active(params, context->channelNum))
            {
                allow = false;
            }
            else
            {
                //Do nothing
            }
            break;

        default:
            allow = true;
            break;
    }
    if (allow)
    {
        return CY_SYSPM_SUCCESS;
    }
    else
    {
        return CY_SYSPM_FAIL;
    }
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13');

#endif // (MTB_SYSPM_CALLBACKS_AVAILABLE_DMA_DMAC)
