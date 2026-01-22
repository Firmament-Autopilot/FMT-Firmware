/***************************************************************************//**
* \file mtb_hal_hw_types_comp.h
*
*********************************************************************************
* \copyright
* Copyright(c) 2024-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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

/**
 * \brief
 * Provides implementation specific values for types that are part of the
 * portable HAL Comp API.
 *
 * \addtogroup group_hal_impl_hw_types Specific Hardware Types
 * \{
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "mtb_hal_impl_types.h"
#include "mtb_hal_hw_types_comp_lp.h"

#if defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)  || \
    defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG) || \
    defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_COMP)
/** Macro specifying whether the Comp driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_COMP (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_COMP)

/** \} group_hal_availability */


//! IP-specific implementation header for Comp
#define MTB_HAL_COMP_IMPL_HEADER          "mtb_hal_comp_impl.h"

/** Comp type */
typedef enum
{
    MTB_HAL_COMP_LP = 0,
    MTB_HAL_COMP_CSG = 1,
    MTB_HAL_COMP_DCSG = 2
} mtb_hal_comp_type_t;

/** For backwards compatiblity with old PDLs */
#define MTB_HAL_RSC_LPCOMP (MTB_HAL_COMP_LP)
/** For backwards compatiblity with old PDLs */
#define MTB_HAL_RSC_CSG    (MTB_HAL_COMP_CSG)

/**
 * @brief Comparator object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    mtb_hal_comp_type_t comp_type;
    union
    {
        #if defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
        struct
        {
            _mtb_hal_lpcomp_base_t*   base_lpcomp;
            _mtb_hal_lpcomp_channel_t channel_lpcomp;
        };
        #endif
        #if defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG)
        _mtb_hal_csg_slice_t      slice_csg;
        #endif
        #if defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
        _mtb_hal_dcsg_base_t*     base_dcsg_slice;
        #endif
    };

    _mtb_hal_event_callback_data_t      callback_data;
    uint32_t                            callback_event;
} mtb_hal_comp_t;

/**
 * @brief Comp configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    mtb_hal_comp_type_t resource_type;
    uint8_t             channel_num;
    union
    {
        #if defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_CSG)
        /* No base address required for HPPASS */
        const _mtb_hal_csg_pdl_config_t* hppass_config;       /* Contains SAR instance within it */
        #endif
        #if defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
        const _mtb_hal_lpcomp_pdl_config_t* lpcomp;
        #endif
    };
    union
    {
        #if defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_DCSG)
        _mtb_hal_dcsg_base_t* dcsg_base;
        #endif
        #if defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
        _mtb_hal_lpcomp_base_t* lpcomp_base;
        #endif
    };
} mtb_hal_comp_configurator_t;

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_COMP)

/** \} group_hal_impl_hw_types */


#if defined(__cplusplus)
}
#endif /* __cplusplus */
