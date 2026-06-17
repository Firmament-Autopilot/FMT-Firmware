/***************************************************************************//**
* \file mtb_syspm_callbacks_tcpwm_version2.h
*
* Description:
* Provides the implementation for syspm callbacks for the MXS40TCPWM and MXTCPWM
* Ver2 and Ver3 IP.
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
// _mtb_syspm_tcpwm_is_enabled
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_syspm_tcpwm_is_enabled(const cy_stc_syspm_callback_params_t* params,
                                                 uint32_t channelNum)
{
    if (_FLD2BOOL(TCPWM_GRP_CNT_V2_CTRL_ENABLED,
                  TCPWM_GRP_CNT_CTRL(params->base, TCPWM_GRP_CNT_GET_GRP(channelNum),
                                     channelNum)))
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
