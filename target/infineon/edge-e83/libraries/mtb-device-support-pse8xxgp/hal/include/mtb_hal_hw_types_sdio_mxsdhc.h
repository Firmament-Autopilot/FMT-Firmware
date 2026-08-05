/***************************************************************************//**
* \file mtb_hal_hw_types_sdio_mxsdhc.h
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
#include "mtb_hal_hw_types_mxsdhc.h"
#include "mtb_hal_hw_types_gpio.h"

#if defined(CY_IP_MXSDHC)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_SDIO)
/** Macro specifying whether the SDIO driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_SDIO (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_SDIO)
#if !defined(MTB_HAL_DRIVER_AVAILABLE_SDIO_HOST)
/** Macro specifying whether the SDIO Host driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_SDIO_HOST (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_SDIO HOST)

/** \} group_hal_availability */


/**
 * @brief SDIO object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    _mtb_hal_sdxx_t                     sdxx; //!< Common data for mxsdhc IP
    _mtb_hal_event_callback_data_t      callback_data; //!< Information about registered callback,
                                                       //!< if any

    mtb_hal_gpio_t                      pin_data0; //!< Pin connected to data bus bit 0
    mtb_hal_gpio_t                      pin_data1; //!< Pin connected to data bus bit 1
    mtb_hal_gpio_t                      pin_data2; //!< Pin connected to data bus bit 2
    mtb_hal_gpio_t                      pin_data3; //!< Pin connected to data bus bit 3

    uint16_t                            block_size; //!< Size configured for block transfers
} mtb_hal_sdio_t;

/**
 * @brief SDIO configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    SDHC_Type*                              base; //!< Base address for the sdhc block
    const cy_stc_sd_host_init_config_t*     host_config; //!< PDL-level sd host config
    const mtb_hal_clock_t*                  clock; //!< Default clock to use
    struct
    {
        mtb_hal_gpio_t                      clk; //!< SDIO clock pin
        mtb_hal_gpio_t                      cmd; //!< SDIO command pin
        mtb_hal_gpio_t                      data[4]; //!< SDIO data pins
    } gpios; //!< Pins that are connected to the SDIO interface
} mtb_hal_sdio_configurator_t;

#endif // defined(CY_IP_MXSDHC)
