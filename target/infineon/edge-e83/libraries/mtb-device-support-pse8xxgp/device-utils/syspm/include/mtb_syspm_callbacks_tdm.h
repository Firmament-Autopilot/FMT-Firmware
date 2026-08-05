/***************************************************************************//**
* \file mtb_syspm_callbacks_tdm.h
*
* Description:
* Provides the implementation for syspm callbacks for the MXTDM IP.
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

__STATIC_INLINE  bool _mtb_syspm_i2s_tdm_is_active(const cy_stc_syspm_callback_params_t* params);
__STATIC_INLINE  bool _mtb_syspm_i2s_tdm_is_busy(const cy_stc_syspm_callback_params_t* params);

//--------------------------------------------------------------------------------------------------
// _mtb_syspm_i2s_tdm_is_active
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE  bool _mtb_syspm_i2s_tdm_is_active(const cy_stc_syspm_callback_params_t* params)
{
    const TDM_STRUCT_Type* base = (params->base);
    if ((0u !=
         (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_ACTIVE_Msk &
          base->TDM_RX_STRUCT.RX_FIFO_CTL)) ||
        (0u !=
         (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Msk &
          base->TDM_TX_STRUCT.TX_FIFO_CTL)))
    {
        return true;
    }
    else
    {
        return false;
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_syspm_i2s_tdm_is_busy
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE  bool _mtb_syspm_i2s_tdm_is_busy(const cy_stc_syspm_callback_params_t* params)
{
    TDM_STRUCT_Type* base = (params->base);
    if (0u != Cy_AudioTDM_GetNumInTxFifo(&(base->TDM_TX_STRUCT)))
    {
        return true;
    }
    else
    {
        return false;
    }
}


#if defined(__cplusplus)
}
#endif
