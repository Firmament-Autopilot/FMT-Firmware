/***************************************************************************//**
* \file mtb_hal_pwm_mxtcpwm_v2.h
*
* Description:
* Provides a high level interface for interacting with the Infineon PWM.
*
********************************************************************************
* \copyright
* Copyright 2019-2024 Cypress Semiconductor Corporation (an Infineon company) or
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

#include "mtb_hal_hw_types.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#if defined (CY_IP_MXTCPWM) && (CY_IP_MXTCPWM_VERSION == 2U)

/*******************************************************************************
*       Defines
*******************************************************************************/
/** The configuration of PWM output signal for Center and Asymmetric alignment with overflow and
   underflow swapped */
#define _MTB_HAL_PWM_MODE_CNTR_OR_ASYMM_UO_SWAPPED \
    (_VAL2FLD(TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC0_MATCH_MODE, CY_TCPWM_PWM_TR_CTRL2_INVERT) |                                   \
                                         _VAL2FLD(TCPWM_GRP_CNT_V2_TR_PWM_CTRL_OVERFLOW_MODE, CY_TCPWM_PWM_TR_CTRL2_CLEAR) | \
                                         _VAL2FLD(TCPWM_GRP_CNT_V2_TR_PWM_CTRL_UNDERFLOW_MODE, CY_TCPWM_PWM_TR_CTRL2_SET))

#define _mtb_hal_pwm_disable(base, cntnum)    Cy_TCPWM_Disable_Single(base,cntnum)

/* Backwards compatability macros to convert old group and counter indexing to new format */
#define _MTB_HAL_TCPWM_MAX_GRPS_PER_IP_BLOCK  (4u)
#define _MTB_HAL_TCPWM_GET_GRP(block) ((block) % _MTB_HAL_TCPWM_MAX_GRPS_PER_IP_BLOCK)

#if (CY_IP_MXTCPWM_INSTANCES == 1)
    #define _MTB_HAL_TCPWM_INSTANCES     TCPWM_GRP_NR
    #define _MTB_HAL_TCPWM_CNT_NUMBER(group, cntnum) (((group) << 8) | (cntnum))
#elif (CY_IP_MXTCPWM_INSTANCES == 2)
    #define _MTB_HAL_TCPWM_INSTANCES     (TCPWM0_GRP_NR + TCPWM1_GRP_NR)
// This is based on the model of 4x continuous groups mapping to x IP blocks
// (0-3 to 1, 4-7 to 2, etc)
    #define _MTB_HAL_TCPWM_CNT_NUMBER(group, cntnum) \
    ((((group) % _MTB_HAL_TCPWM_MAX_GRPS_PER_IP_BLOCK) << 8) | (cntnum))
#endif

/*******************************************************************************
*       Globals
*******************************************************************************/

/*******************************************************************************
*       Functions
*******************************************************************************/
__STATIC_INLINE void _mtb_hal_tcpwm_trigger_reload(mtb_hal_pwm_t* obj)
{
    Cy_TCPWM_TriggerReloadOrIndex_Single(obj->tcpwm.base, obj->tcpwm.cntnum);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_tcpwm_is_center_aligned
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_tcpwm_is_center_aligned(mtb_hal_pwm_t* obj)
{
    uint32_t pwm_ctrl_reg = TCPWM_GRP_CNT_TR_PWM_CTRL(obj->tcpwm.base, obj->tcpwm.group,
                                                      obj->tcpwm.cntnum);
    uint32_t cc1_ignore_mask = (0 == obj->tcpwm.group) ? 0 : CY_TCPWM_PWM_MODE_CC1_IGNORE;
    bool is_center_aligned =
        (pwm_ctrl_reg == (CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM | cc1_ignore_mask)) ||
        (pwm_ctrl_reg == (_MTB_HAL_PWM_MODE_CNTR_OR_ASYMM_UO_SWAPPED | cc1_ignore_mask));
    return is_center_aligned;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_get_killed_state
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_get_killed_state(mtb_hal_pwm_t* obj, bool* killed)
{
    uint32_t pwm_ctrl_reg =
        TCPWM_GRP_CNT_CTRL(obj->tcpwm.base, obj->tcpwm.group, obj->tcpwm.cntnum);
    uint32_t pwm_status_reg = TCPWM_GRP_CNT_STATUS(obj->tcpwm.base, obj->tcpwm.group,
                                                   obj->tcpwm.cntnum);
    uint32_t pwm_tr_in_sel0_reg = TCPWM_GRP_CNT_TR_IN_SEL0(obj->tcpwm.base, obj->tcpwm.group,
                                                           obj->tcpwm.cntnum);
    uint32_t tcpwm_mode = _FLD2VAL(TCPWM_GRP_CNT_V2_CTRL_MODE, pwm_ctrl_reg);
    uint32_t is_stop_on_kill = _FLD2VAL(TCPWM_GRP_CNT_V2_CTRL_PWM_STOP_ON_KILL, pwm_ctrl_reg);
    uint32_t kill_signal = _FLD2VAL(TCPWM_GRP_CNT_V2_TR_IN_SEL0_STOP_SEL, pwm_tr_in_sel0_reg);

    if ((kill_signal == 0UL) ||
        ((tcpwm_mode != CY_TCPWM_PWM_MODE_PWM) && (tcpwm_mode != CY_TCPWM_PWM_MODE_DEADTIME) &&
         (tcpwm_mode != CY_TCPWM_PWM_MODE_PSEUDORANDOM)))
    {
        *killed = false;
    }
    else
    {
        // For Stop On Kill case
        if (is_stop_on_kill == 1UL)
        {
            *killed = (bool)!(_FLD2VAL(TCPWM_GRP_CNT_V2_STATUS_RUNNING, pwm_status_reg));
        }
        // For Sync. Kill and Async. Kill case
        else
        {
            *killed = (bool)(_FLD2VAL(TCPWM_GRP_CNT_V2_STATUS_RUNNING, pwm_status_reg) &&
                             _FLD2VAL(TCPWM_GRP_CNT_V2_STATUS_TR_STOP, pwm_status_reg));
        }
    }

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_set_period0
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_set_period0(mtb_hal_pwm_t* obj, uint32_t count)
{
    Cy_TCPWM_PWM_SetPeriod0(obj->tcpwm.base, obj->tcpwm.cntnum, count);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_pwm_set_period_count _mtb_hal_pwm_set_period0

//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_set_period1
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_set_period1(mtb_hal_pwm_t* obj, uint32_t count)
{
    Cy_TCPWM_PWM_SetPeriod1(obj->tcpwm.base, obj->tcpwm.cntnum, count);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_pwm_set_period_alt_count _mtb_hal_pwm_set_period1

//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_set_compare0
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_set_compare0(mtb_hal_pwm_t* obj, uint32_t count)
{
    Cy_TCPWM_PWM_SetCompare0Val(obj->tcpwm.base, obj->tcpwm.cntnum, count);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_pwm_set_compare_count _mtb_hal_pwm_set_compare0

//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_set_compare0_shadow
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_set_compare0_shadow(mtb_hal_pwm_t* obj, uint32_t count)
{
    Cy_TCPWM_PWM_SetCompare0BufVal(obj->tcpwm.base, obj->tcpwm.cntnum, count);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_pwm_set_compare_shadow_count _mtb_hal_pwm_set_compare0_shadow

//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_set_compare1
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_set_compare1(mtb_hal_pwm_t* obj, uint32_t count)
{
    Cy_TCPWM_PWM_SetCompare1Val(obj->tcpwm.base, obj->tcpwm.cntnum, count);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_pwm_set_compare_alt_count _mtb_hal_pwm_set_compare1

//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_set_compare1_shadow
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_set_compare1_shadow(mtb_hal_pwm_t* obj, uint32_t count)
{
    Cy_TCPWM_PWM_SetCompare1BufVal(obj->tcpwm.base, obj->tcpwm.cntnum, count);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_pwm_set_compare_alt_shadow_count _mtb_hal_pwm_set_compare1_shadow

//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_set_deadtime
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_set_deadtime(mtb_hal_pwm_t* obj, uint32_t count)
{
    Cy_TCPWM_PWM_SetDT(obj->tcpwm.base, obj->tcpwm.cntnum, count);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_pwm_set_deadtime_count _mtb_hal_pwm_set_deadtime

//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_set_deadtime_shadow
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_set_deadtime_shadow(mtb_hal_pwm_t* obj, uint32_t count)
{
    CY_UNUSED_PARAMETER(obj);
    CY_UNUSED_PARAMETER(count);
    return MTB_HAL_PWM_RSLT_ERR_UNSUPPORTED;
}


#define mtb_hal_pwm_set_deadtime_shadow_count _mtb_hal_pwm_set_deadtime_shadow

//--------------------------------------------------------------------------------------------------
// _mtb_hal_pwm_configure_output
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_pwm_configure_output(mtb_hal_pwm_t* obj,
                                                        mtb_hal_pwm_output_t out,
                                                        mtb_hal_pwm_output_t out_compl)
{
    Cy_TCPWM_PWM_Configure_LineSelect(obj->tcpwm.base, obj->tcpwm.cntnum,
                                      (cy_en_line_select_config_t)out,
                                      (cy_en_line_select_config_t)out_compl);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_pwm_configure_output _mtb_hal_pwm_configure_output

#endif //#if defined (CY_IP_MXTCPWM) && (CY_IP_MXTCPWM_VERSION == 2U)

#if defined(__cplusplus)
}
#endif /* __cplusplus */
