/***************************************************************************//**
* \file mtb_syspm_callbacks_tcpwm.c
*
* Description:
* Provides the implementation for syspm callbacks for the TCPWM IP.
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
#include "mtb_syspm_callbacks_tcpwm.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1, \
                             'Rule requires const attributes for inputs but signature for following APIs needs to match requested one in PDL');
//--------------------------------------------------------------------------------------------------
// mtb_syspm_tcpwm_deepsleep_callback
//--------------------------------------------------------------------------------------------------
cy_en_syspm_status_t mtb_syspm_tcpwm_deepsleep_callback(
    cy_stc_syspm_callback_params_t* params,
    cy_en_syspm_callback_mode_t mode)
{
    bool allow = false;
    mtb_syspm_tcpwm_deepsleep_context_t* context =
        (mtb_syspm_tcpwm_deepsleep_context_t*)(params->context);
    switch (mode)
    {
        case CY_SYSPM_BEFORE_TRANSITION:
        {
            if (_mtb_syspm_tcpwm_is_enabled(params, context->channelNum))
            {
                context->preSleepState = true;

                // Check if the TCPWM is running
                if (CY_TCPWM_PWM_STATUS_COUNTER_RUNNING &
                    Cy_TCPWM_PWM_GetStatus(params->base, (context->channelNum)))
                {
                    context->preSleepRunning = true;
                }
                else
                {
                    context->preSleepRunning = false;
                }
            }
            else
            {
                context->preSleepState = false;
                context->preSleepRunning = false;
            }
            allow = true;
            break;
        }

        case CY_SYSPM_AFTER_TRANSITION:
        {
            if (context->preSleepState)
            {
                Cy_TCPWM_Enable_Single(params->base, (context->channelNum));

                // Trigger the TCPWM if it was running before sleep
                if (context->preSleepRunning)
                {
                    Cy_TCPWM_TriggerStart_Single(params->base, (context->channelNum));
                }
            }

            allow = true;
            break;
        }

        default:
        {
            CY_ASSERT(false);
            break;
        }
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
