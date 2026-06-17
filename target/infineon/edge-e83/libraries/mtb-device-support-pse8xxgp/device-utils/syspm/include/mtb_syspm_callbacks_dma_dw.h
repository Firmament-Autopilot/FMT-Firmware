/***************************************************************************//**
* \file mtb_syspm_callbacks_dma_dw.h
*
* Description:
* Provides the implementation for syspm callbacks for the DW IP.
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
#include "cy_utils.h"

#if defined(__cplusplus)
extern "C" {
#endif

//--------------------------------------------------------------------------------------------------
// _mtb_syspm_dma_dw_is_active
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_syspm_dma_dw_is_active(const cy_stc_syspm_callback_params_t* params,
                                                 uint32_t channelNum)
{
    return ((Cy_DMA_GetActiveChannelIndex((params->base)) == (channelNum)));
}


#if defined(__cplusplus)
}
#endif
