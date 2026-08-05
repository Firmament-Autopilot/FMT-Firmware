/***************************************************************************//**
* \file mtb_hal_comp.c
*
* \brief
* Provides a high level interface for interacting with the Infineon Comparator.
* This is a wrapper around the lower level PDL API.
*
********************************************************************************
* \copyright
* Copyright 2018-2024 Cypress Semiconductor Corporation (an Infineon company) or
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

#include "mtb_hal_utils.h"
#include "mtb_hal_comp.h"
#include "mtb_hal_comp_impl.h"
#include "mtb_hal_system.h"

#if (MTB_HAL_DRIVER_AVAILABLE_COMP)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */


/*******************************************************************************
*       Defines
*******************************************************************************/


/*******************************************************************************
*       Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// mtb_hal_comp_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_comp_register_callback(mtb_hal_comp_t* obj, mtb_hal_comp_event_callback_t callback,
                                    void* callback_arg)
{
    CY_UNUSED_PARAMETER(obj);
    CY_ASSERT(NULL != obj);

    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    mtb_hal_system_critical_section_exit(savedIntrStatus);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_comp_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_comp_enable_event(mtb_hal_comp_t* obj, mtb_hal_comp_event_t event, bool enable)
{
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
    if (obj->comp_type == MTB_HAL_COMP_DCSG)
    {
        _mtb_hal_comp_dcsg_enable_event(obj, event, enable);
        return;
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG)
    if (obj->comp_type == MTB_HAL_COMP_CSG)
    {
        _mtb_hal_comp_csg_enable_event(obj, event, enable);
        return;
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
    if (obj->comp_type == MTB_HAL_COMP_LP)
    {
        _mtb_hal_comp_lpcomp_enable_event(obj, event, enable);
        return;
    }
    #endif
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_comp_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_comp_process_interrupt(mtb_hal_comp_t* obj)
{
    cy_rslt_t result = MTB_HAL_COMP_RSLT_ERR_BAD_ARGUMENT;
    bool interrupt_status = false;

    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
    if (obj->comp_type == MTB_HAL_COMP_DCSG)
    {
        interrupt_status = _mtb_hal_comp_dcsg_process_interrupt(obj);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG)
    if (obj->comp_type == MTB_HAL_COMP_CSG)
    {
        interrupt_status = _mtb_hal_comp_csg_process_interrupt(obj);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
    if (obj->comp_type == MTB_HAL_COMP_LP)
    {
        interrupt_status =_mtb_hal_comp_lpcomp_process_interrupt(obj);
    }
    #endif

    if (interrupt_status)
    {
        mtb_hal_comp_event_callback_t callback =
            (mtb_hal_comp_event_callback_t)obj->callback_data.callback;
        if (NULL != callback)
        {
            callback(obj->callback_data.callback_arg, (mtb_hal_comp_event_t)(obj->callback_event));
        }
        result = CY_RSLT_SUCCESS;
    }

    return result;
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* defined (MTB_HAL_DRIVER_AVAILABLE_COMP) */
