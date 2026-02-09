/***************************************************************************//**
* \file mtb_hal_hw_types_sdhc_mxsdhc.h
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
#include "mtb_hal_hw_types_mxsdhc.h"
#include "mtb_hal_hw_types_gpio.h"

#if defined(CY_IP_MXSDHC)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_SDHC)
/** Macro specifying whether the SDHC driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_SDHC (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_SDHC)

/** \} group_hal_availability */


/**
 * @brief SDHC object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    _mtb_hal_sdxx_t                     sdxx; //!< Common data for mxsdhc IP
    cy_stc_sd_host_sd_card_config_t*    card_config; //!< PDL-level card config
    uint8_t                             bus_width; //!< Width configured for the sdhc bus
    uint8_t                             data_timeout_tout; //!< TOUT setting of SDHC block
    bool                                data_timeout_auto_reconfig; //!< Automatically reconfigure
                                                                    //!< data timeout
    /* Desired by user data timeout in card clocks */
    uint32_t                            data_timeout_card_clocks_user; //!< Timeout provided by the
                                                                       //!< user
    mtb_hal_gpio_t                      pin_data[8]; //!< Pins used for the data bus
    bool                                low_voltage_io_desired; //!< Is card configured for low
                                                                //!< voltage
    uint16_t                            emmc_generic_cmd6_time_ms; //!< Maximum timeout for CMD6
                                                                   //!< (swwitch command)
} mtb_hal_sdhc_t;

/**
 * @brief SDHC configurator struct
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
    cy_stc_sd_host_sd_card_config_t*        card_config; //!< PDL-level sd host config
    const mtb_hal_clock_t*                  clock; //!< Default clock to use
    struct
    {
        mtb_hal_gpio_t                      clk; //!< SDHC clock pin
        mtb_hal_gpio_t                      cmd; //!< SDHC command pin
        mtb_hal_gpio_t                      data[8]; //!< SDHC data pins
    } gpios; //!< Pins that are connected to the sdhc interface
} mtb_hal_sdhc_configurator_t;

#endif // if defined(CY_IP_MXSDHC)
