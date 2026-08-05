/***************************************************************************//**
* \file mtb_hal_gpio.c
*
* Description:
* Provides a high level interface for interacting with the Infineon GPIO. This is
* a wrapper around the lower level PDL API.
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

#include <string.h>
#include "mtb_hal_gpio.h"
#include "mtb_hal_utils.h"
#include "mtb_hal_irq_impl.h"

#if (MTB_HAL_DRIVER_AVAILABLE_GPIO)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */


/*******************************************************************************
*       Internal
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_gpio_convert_drive_mode
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE uint32_t _mtb_hal_gpio_convert_drive_mode(mtb_hal_gpio_drive_mode_t drive_mode,
                                                          mtb_hal_gpio_direction_t direction)
{
    uint32_t drvMode = (uint32_t)CY_GPIO_DM_HIGHZ;

    if (drive_mode == MTB_HAL_GPIO_DRIVE_PULL_NONE)
    {
        if ((direction == MTB_HAL_GPIO_DIR_OUTPUT) || (direction == MTB_HAL_GPIO_DIR_BIDIRECTIONAL))
        {
            drvMode = CY_GPIO_DM_STRONG;
        }
        else
        {
            drvMode = CY_GPIO_DM_HIGHZ;
        }
    }
    else
    {
        /* HAL and PDL values map exactly for the other cases */
        drvMode = (uint32_t)drive_mode;
    }

    if (direction == MTB_HAL_GPIO_DIR_OUTPUT)
    {
        drvMode = _mtb_hal_gpio_get_drive_mode(drvMode);
    }
    return drvMode;
}


/*******************************************************************************
*       Interrupt Process Service Routine
*******************************************************************************/

cy_rslt_t mtb_hal_gpio_process_interrupt(mtb_hal_gpio_t* obj)
{
    /* Return warning result code in case the interrupt status is
       not set for the requested  gpio pin */
    cy_rslt_t result     = MTB_HAL_GPIO_RSLT_WRN_INTERRUPT_STATUS_NOT_SET;
    uint32_t  intr_cause = _mtb_hal_gpio_get_interrupt_cause(obj);

    if (intr_cause != 0)
    {
        /* Each supported architecture much have a way to check the interrupt status of a pin on
           a port. */
        if (_mtb_hal_gpio_get_interrupt_status_masked(obj))
        {
            uint8_t                       pin = obj->pin_num;
            mtb_hal_gpio_event_t          event = (mtb_hal_gpio_event_t)Cy_GPIO_GetInterruptEdge(
                obj->port_addr, pin);
            mtb_hal_gpio_event_callback_t callback =
                (mtb_hal_gpio_event_callback_t)obj->callback_data.callback;

            /* Clear the interrupt bit corresponding to the pin */
            Cy_GPIO_ClearInterrupt(obj->port_addr, pin);

            if (NULL != callback)
            {
                switch (event)
                {
                    case MTB_HAL_GPIO_IRQ_RISE:
                    case MTB_HAL_GPIO_IRQ_FALL:
                        break;

                    default:
                        event =
                            (Cy_GPIO_Read(obj->port_addr,
                                          pin) !=
                             0) ? MTB_HAL_GPIO_IRQ_RISE : MTB_HAL_GPIO_IRQ_FALL;
                        break;
                }
                /* Call registered callbacks here */
                callback(obj->callback_data.callback_arg, event);
            }
            result = CY_RSLT_SUCCESS;
        }
    }
    return result;
}


/*******************************************************************************
*       HAL Implementation
*******************************************************************************/

void mtb_hal_gpio_setup(mtb_hal_gpio_t* obj, const uint8_t port, const uint8_t pin)
{
    CY_ASSERT(NULL != obj);

    memset(obj, 0, sizeof(mtb_hal_gpio_t));
    obj->pin_num = pin;
    obj->port_num = port;
    obj->port_addr = Cy_GPIO_PortToAddr((uint32_t)port);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_configure
//--------------------------------------------------------------------------------------------------
void mtb_hal_gpio_configure(mtb_hal_gpio_t* obj, mtb_hal_gpio_direction_t direction,
                            mtb_hal_gpio_drive_mode_t drive_mode)
{
    uint32_t pdldrive_mode = _mtb_hal_gpio_convert_drive_mode(drive_mode, direction);
    Cy_GPIO_SetDrivemode(obj->port_addr, (uint32_t)obj->pin_num, pdldrive_mode);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_gpio_register_callback(mtb_hal_gpio_t* obj, mtb_hal_gpio_event_callback_t callback,
                                    void* callback_arg)
{
    uint32_t savedIntrStatus = Cy_SysLib_EnterCriticalSection();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    Cy_SysLib_ExitCriticalSection(savedIntrStatus);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_gpio_enable_event(mtb_hal_gpio_t* obj, mtb_hal_gpio_event_t event, bool enable)
{
    #if (_MTB_HAL_IRQ_MUXING)
    /* We may be in a critical section. Only clear the interrupt status if there isn't a pending
       interrupt */
    if ((Cy_GPIO_GetInterruptStatus(obj->port_addr, (uint32_t)obj->pin_num) == 0) || enable)
    #endif
    {
        Cy_GPIO_ClearInterrupt(obj->port_addr, (uint32_t)obj->pin_num);
    }

    _mtb_hal_gpio_set_interrupt_edge(obj, event, enable);
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* MTB_HAL_DRIVER_AVAILABLE_GPIO */
