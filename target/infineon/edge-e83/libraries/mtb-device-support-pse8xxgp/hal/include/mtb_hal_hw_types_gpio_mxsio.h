/***************************************************************************//**
* \file mtb_hal_hw_types_gpio_mxsio.h
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

#pragma once

#include "cy_pdl.h"
#include "mtb_hal_impl_types.h"

#if defined(CY_IP_MXS22IOSS) || defined(CY_IP_MXS40IOSS) || defined(CY_IP_MXS40SIOSS) \
    || defined(CY_IP_IOCL)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_GPIO)
/** Macro specifying whether the GPIO driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_GPIO (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_GPIO)
#if !defined(MTB_HAL_DRIVER_AVAILABLE_GPIO_PORT)
/** Macro specifying whether the GPIO Port driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_GPIO_PORT (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_GPIO PORT)

/** \} group_hal_availability */


/** GPIO HAL to PDL enum map for pin drive modes. */
#define MTB_HAL_MAP_GPIO_DRIVE_ANALOG                         (CY_GPIO_DM_ANALOG)
#define MTB_HAL_MAP_GPIO_DRIVE_NONE                           (CY_GPIO_DM_HIGHZ)
#define MTB_HAL_MAP_GPIO_DRIVE_PULLUP                         (CY_GPIO_DM_PULLUP)
#define MTB_HAL_MAP_GPIO_DRIVE_PULLDOWN                       (CY_GPIO_DM_PULLDOWN)
#define MTB_HAL_MAP_GPIO_DRIVE_OPENDRAINDRIVESLOW             (CY_GPIO_DM_OD_DRIVESLOW)
#define MTB_HAL_MAP_GPIO_DRIVE_OPENDRAINDRIVESHIGH            (CY_GPIO_DM_OD_DRIVESHIGH)
#define MTB_HAL_MAP_GPIO_DRIVE_STRONG                         (CY_GPIO_DM_STRONG)
#define MTB_HAL_MAP_GPIO_DRIVE_PULLUPDOWN                     (CY_GPIO_DM_PULLUP_DOWN)
#define MTB_HAL_MAP_GPIO_DRIVE_PULL_NONE                      (CY_GPIO_DM_PULLUP_DOWN << 1)

/**
 * @brief Connection type definition
 *
 * Represents an association between gpio and pin port numbers
 */
typedef struct
{
    uint8_t                               pin_num;        //!< The associated gpio pin number
    uint8_t                               port_num;       //!< The associated gpio port number
    GPIO_PRT_Type*                        port_addr;      //!< The associated gpio port address
    _mtb_hal_event_callback_data_t        callback_data;  //!< The callback data associated with the
                                                          //!< pin
} mtb_hal_gpio_t;

/**
 * @brief GPIO Port object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef GPIO_PRT_Type* mtb_hal_gpio_port_t;

#endif /* defined(CY_IP_MXS22IOSS) || defined(CY_IP_MXS40IOSS) || defined(CY_IP_MXS40SIOSS)
       || defined(CY_IP_IOCL) */
