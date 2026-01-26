/***************************************************************************//**
* \file mtb_hal_gpio_common.h
*
* \brief
* Provides common API declarations of the MXS IOSS IP's ( MXS22 IOSS v1, MXS40
* IOCL v1, IOSS v3, MXS40S IOSS v1)
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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


#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */


/*******************************************************************************
*                           Defines
*******************************************************************************/

#define _MTB_HAL_GPIO_DIRECTION_OUTPUT_MASK        (0x07UL)   /**< Mask to disable the input buffer
                                                               */

/*******************************************************************************
*                           Typedefs
*******************************************************************************/


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/

/** Return the drive mode with input buffer disabled */
__STATIC_INLINE uint32_t _mtb_hal_gpio_get_drive_mode(uint32_t drive_mode)
{
    return (drive_mode & _MTB_HAL_GPIO_DIRECTION_OUTPUT_MASK);
}


/** Return the pin's current interrupt state after being masked */
__STATIC_INLINE uint32_t _mtb_hal_gpio_get_interrupt_status_masked(mtb_hal_gpio_t* obj)
{
    return Cy_GPIO_GetInterruptStatusMasked(obj->port_addr, (uint32_t)obj->pin_num);
}


/** Return the interrupt cause */
__STATIC_INLINE uint32_t _mtb_hal_gpio_get_interrupt_cause(mtb_hal_gpio_t* obj)
{
    return 1 << (obj->port_num);
}


/** Set the GPIO interrupt edge */
__STATIC_INLINE void _mtb_hal_gpio_set_interrupt_edge(mtb_hal_gpio_t* obj,
                                                      mtb_hal_gpio_event_t event, bool enable)
{
    Cy_GPIO_SetInterruptEdge(obj->port_addr, (uint32_t)obj->pin_num,
                             (uint32_t)event);
    Cy_GPIO_SetInterruptMask(obj->port_addr, (uint32_t)obj->pin_num,
                             (uint32_t)enable);
}


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
