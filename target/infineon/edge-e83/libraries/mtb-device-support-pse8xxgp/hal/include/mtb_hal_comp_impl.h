/***************************************************************************//**
* \file mtb_hal_comp_impl.h
*
* \brief
* Provides a high level interface for interacting with the Infineon Analog to
* Digital Converter. This interface abstracts out the chip specific details.
* If any chip specific functionality is necessary, or performance is critical
* the low level functions can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
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

#if (MTB_HAL_DRIVER_AVAILABLE_COMP)

#if ((CY_IP_MXS40LPCOMP_INSTANCES) > 0) || ((CY_IP_MXS22LPCOMP_INSTANCES) > 0)
#include "mtb_hal_comp_lpcomp_common.h"
#endif

#if ((CY_IP_MXS40PPSS_INSTANCES) > 0) && defined (_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
#include "mtb_hal_comp_mxs40ppss_dcsg_v1.h"
#endif
#if ((CY_IP_MXS40MCPASS_INSTANCES) > 0)
#include "mtb_hal_comp_mxs40mcpass_csg_v1.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Defines
*******************************************************************************/

/*******************************************************************************
*       Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_comp_setup
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_comp_setup(mtb_hal_comp_t* obj,
                                              const mtb_hal_comp_configurator_t* config)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(config != NULL);
    cy_rslt_t result = CY_RSLT_SUCCESS;

    obj->comp_type = config->resource_type;
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
    if (obj->comp_type == MTB_HAL_COMP_DCSG)
    {
        result =  _mtb_hal_comp_dcsg_setup(obj, config);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG)
    if (obj->comp_type == MTB_HAL_COMP_CSG)
    {
        result =  _mtb_hal_comp_csg_setup(obj, config);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
    if (obj->comp_type == MTB_HAL_COMP_LP)
    {
        result =  _mtb_hal_comp_lpcomp_setup(obj, config);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_PTC)
    if (obj->comp_type == MTB_HAL_COMP_PTC)
    {
        // TBD
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_CTB)
    if (obj->comp_type == MTB_HAL_COMP_OPAMP)
    {
        // TBD
    }
    #endif
    return result;
}


#define mtb_hal_comp_setup(obj, config) _mtb_hal_comp_setup(obj, config)


//--------------------------------------------------------------------------------------------------
// _mtb_hal_comp_read
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_comp_read(mtb_hal_comp_t* obj)
{
    CY_ASSERT(obj != NULL);
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
    if (obj->comp_type == MTB_HAL_COMP_DCSG)
    {
        return _mtb_hal_comp_dcsg_read(obj);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG)
    if (obj->comp_type == MTB_HAL_COMP_CSG)
    {
        return _mtb_hal_comp_csg_read(obj);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
    if (obj->comp_type == MTB_HAL_COMP_LP)
    {
        return _mtb_hal_comp_lpcomp_read(obj);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_PTC)
    if (obj->comp_type == MTB_HAL_COMP_PTC)
    {
        return false; // TBD
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_CTB)
    if (obj->comp_type == MTB_HAL_COMP_OPAMP)
    {
        return false; // TBD
    }
    #endif
    return false;
}


#define mtb_hal_comp_read(obj) _mtb_hal_comp_read(obj)


//--------------------------------------------------------------------------------------------------
// _mtb_hal_comp_set_ref
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_comp_set_ref(mtb_hal_comp_t* obj, uint16_t ref_mv)
{
    CY_ASSERT(obj != NULL);

    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
    if (obj->comp_type == MTB_HAL_COMP_DCSG)
    {
        return _mtb_hal_comp_dcsg_set_ref(obj, ref_mv);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG)
    if (obj->comp_type == MTB_HAL_COMP_CSG)
    {
        return _mtb_hal_comp_csg_set_ref(obj, ref_mv);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
    if (obj->comp_type == MTB_HAL_COMP_LP)
    {
        return _mtb_hal_comp_lpcomp_set_ref(obj, ref_mv);
    }
    #endif
    return MTB_HAL_COMP_RSLT_ERR_NOT_SUPPORTED;
}


#define mtb_hal_comp_set_ref(obj, ref_mv) _mtb_hal_comp_set_ref(obj, ref_mv)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_comp_enable
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_comp_enable(mtb_hal_comp_t* obj, bool enable)
{
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
    if (obj->comp_type == MTB_HAL_COMP_DCSG)
    {
        return _mtb_hal_comp_dcsg_enable(obj, enable);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG)
    if (obj->comp_type == MTB_HAL_COMP_CSG)
    {
        return _mtb_hal_comp_csg_enable(obj, enable);
    }
    #endif
    #if (_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
    CY_UNUSED_PARAMETER(enable);
    if (obj->comp_type == MTB_HAL_COMP_LP)
    {
        return MTB_HAL_COMP_RSLT_ERR_NOT_SUPPORTED;
    }
    #endif
    return MTB_HAL_COMP_RSLT_ERR_NOT_SUPPORTED;
}


#define mtb_hal_comp_enable _mtb_hal_comp_enable

#if defined(__cplusplus)
}
#endif

#endif /* (MTB_HAL_DRIVER_AVAILABLE_COMP) */
