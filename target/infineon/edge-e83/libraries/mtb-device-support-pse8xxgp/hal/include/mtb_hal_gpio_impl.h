/***************************************************************************//**
* \file mtb_hal_gpio_impl.h
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

#pragma once

#include "cy_gpio.h"
#include "mtb_hal_gpio.h"
#include "mtb_hal_utils.h"
#include "cy_utils.h"

#if (defined(CY_IP_M0S8IOSS) && (CY_IP_M0S8IOSS_VERSION == 1))
#include "mtb_hal_gpio_m0s8ioss_v1.h"
#elif (defined(CY_IP_MXS22IOSS) && (CY_IP_MXS22IOSS_VERSION == 1))
#include "mtb_hal_gpio_common.h"
#elif (defined(CY_IP_IOCL) && (CY_IP_IOCL_VERSION == 1))
#include "mtb_hal_gpio_common.h"
#elif (defined(CY_IP_MXS40IOSS) && (CY_IP_MXS40IOSS_VERSION == 2 || CY_IP_MXS40IOSS_VERSION == 3 || \
                                    CY_IP_MXS40IOSS_VERSION == 5))
#include "mtb_hal_gpio_common.h"
#elif (defined(CY_IP_MXS40SIOSS) && (CY_IP_MXS40SIOSS_VERSION == 1))
#include "mtb_hal_gpio_common.h"
#else // if (defined(CY_IP_M0S8IOSS) && (CY_IP_M0S8IOSS_VERSION == 1))
#error "Unhandled version"
#endif // if (defined(CY_IP_M0S8IOSS) && (CY_IP_M0S8IOSS_VERSION == 1))

#if defined(CY_IP_MXS40IOSS) || defined(CY_IP_M0S8IOSS) || defined(CY_IP_MXS40SIOSS) || \
    defined(CY_IP_MXS22IOSS) || defined(CY_IP_IOCL)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Defines
*******************************************************************************/


/*******************************************************************************
*       Functions
*******************************************************************************/

__STATIC_INLINE void mtb_hal_gpio_write_internal(mtb_hal_gpio_t* obj, bool value)
{
    Cy_GPIO_Write(obj->port_addr, (uint32_t)obj->pin_num, value);
}


#define mtb_hal_gpio_write(obj, value) mtb_hal_gpio_write_internal(obj, value)

//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_read_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool mtb_hal_gpio_read_internal(mtb_hal_gpio_t* obj)
{
    return 0 != Cy_GPIO_Read(obj->port_addr, (uint32_t)(obj->pin_num));
}


#define mtb_hal_gpio_read(obj) mtb_hal_gpio_read_internal(obj)

//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_toggle_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void mtb_hal_gpio_toggle_internal(mtb_hal_gpio_t* obj)
{
    Cy_GPIO_Inv(obj->port_addr, (uint32_t)obj->pin_num);
}


#define mtb_hal_gpio_toggle(obj) mtb_hal_gpio_toggle_internal(obj)


#if (MTB_HAL_DRIVER_AVAILABLE_GPIO_PORT)

//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_port_setup_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void mtb_hal_gpio_port_setup_internal(mtb_hal_gpio_port_t* port,
                                                      uint32_t port_number)
{
    *port = Cy_GPIO_PortToAddr(port_number);
}


#define mtb_hal_gpio_port_setup(port, \
                                port_number) mtb_hal_gpio_port_setup_internal(port, port_number)

//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_port_set_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void mtb_hal_gpio_port_set_internal(mtb_hal_gpio_port_t* port, uint32_t pin_mask)
{
    #if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    bool secPort;
    secPort = CY_PRA_IS_PORT_SECURE(*port);
    if (secPort)
    {
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(*port, CY_PRA_SUB_INDEX_PORT_OUT_SET), pin_mask);
    }
    else
    {
        GPIO_PRT_OUT_SET(*port) = pin_mask;
    }
    #else // if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    GPIO_PRT_OUT_SET(*port) = pin_mask;
    #endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
}


#define mtb_hal_gpio_port_set(port, pin_mask) mtb_hal_gpio_port_set_internal(port, pin_mask)

//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_port_clear_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void mtb_hal_gpio_port_clear_internal(mtb_hal_gpio_port_t* port, uint32_t pin_mask)
{
    #if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    bool secPort;
    secPort = CY_PRA_IS_PORT_SECURE(*port);
    if (secPort)
    {
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(*port, CY_PRA_SUB_INDEX_PORT_OUT_CLR), pin_mask);
    }
    else
    {
        GPIO_PRT_OUT_CLR(*port) = pin_mask;
    }
    #else // if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    GPIO_PRT_OUT_CLR(*port) = pin_mask;
    #endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
}


#define mtb_hal_gpio_port_clear(port, pin_mask) mtb_hal_gpio_port_clear_internal(port, pin_mask)

//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_port_toggle_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void mtb_hal_gpio_port_toggle_internal(mtb_hal_gpio_port_t* port, uint32_t pin_mask)
{
    #if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    bool secPort;
    secPort = CY_PRA_IS_PORT_SECURE(*port);
    if (secPort)
    {
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(*port, CY_PRA_SUB_INDEX_PORT_OUT_INV), pin_mask);
    }
    else
    {
        GPIO_PRT_OUT_INV(*port) = pin_mask;
    }
    #else // if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    GPIO_PRT_OUT_INV(*port) = pin_mask;
    #endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
}


#define mtb_hal_gpio_port_toggle(port, pin_mask) mtb_hal_gpio_port_toggle_internal(port, pin_mask)

//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_port_write_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void mtb_hal_gpio_port_write_internal(mtb_hal_gpio_port_t* port, uint32_t value)
{
    #if defined(CY_IP_M0S8IOSS)
    GPIO_PRT_DR(*port) = value;
    #elif (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    bool secPort;
    secPort = CY_PRA_IS_PORT_SECURE(*port);
    if (secPort)
    {
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(*port, CY_PRA_SUB_INDEX_PORT_OUT), value);
    }
    else
    {
        GPIO_PRT_OUT(*port) = value;
    }
    #else // defined(CY_IP_M0S8IOSS)
    GPIO_PRT_OUT(*port) = value;
    #endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
}


#define mtb_hal_gpio_port_write(port, value) mtb_hal_gpio_port_write_internal(port, value)

//--------------------------------------------------------------------------------------------------
// mtb_hal_gpio_port_read_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void mtb_hal_gpio_port_read_internal(mtb_hal_gpio_port_t* port, uint32_t* value)
{
    #if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) && defined(CY_DEVICE_PSOC6ABLE2)
    bool secPort;
    secPort = CY_PRA_IS_PORT_SECURE(*port);
    if (secPort)
    {
        *value = CY_PRA_REG32_GET(CY_PRA_GET_PORT_REG_INDEX(*port, CY_PRA_SUB_INDEX_PORT_IN));
    }
    else
    {
        *value = GPIO_PRT_IN(*port);
    }
    #else // if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) && defined(CY_DEVICE_PSOC6ABLE2)
    *value = GPIO_PRT_IN(*port);
    #endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) && defined(CY_DEVICE_PSOC6ABLE2) */
    *value &= ((1UL << CY_GPIO_PINS_MAX) - 1UL);
}


#define mtb_hal_gpio_port_read(port, value) mtb_hal_gpio_port_read_internal(port, value)


//--------------------------------------------------------------------------------------------------
// _mtb_hal_gpio_read_out
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_gpio_read_out(mtb_hal_gpio_t* obj)
{
    return 0 != Cy_GPIO_ReadOut(obj->port_addr, (uint32_t)obj->pin_num);
}


#define mtb_hal_gpio_read_out _mtb_hal_gpio_read_out

#endif /* MTB_HAL_DRIVER_AVAILABLE_GPIO_PORT */


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif \
    /* defined(CY_IP_MXS40IOSS) || defined(CY_IP_M0S8IOSS) || defined(CY_IP_MXS40SIOSS) ||
       defined(CY_IP_MXS22IOSS) */
