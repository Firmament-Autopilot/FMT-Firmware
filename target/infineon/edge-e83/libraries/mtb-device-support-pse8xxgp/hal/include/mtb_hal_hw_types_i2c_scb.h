/***************************************************************************//**
* \file mtb_hal_hw_types_i2c_scb.h
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

/* Older IP versions don't define SCB_I2C; it is always present */
#if (defined(CY_IP_MXSCB) || defined(CY_IP_MXS22SCB)) && (!defined(SCB_I2C) || (SCB_I2C))
 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_I2C)
/** Macro specifying whether the I2C driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_I2C (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_I2C)

/** \} group_hal_availability */


/** I2C HAL to PDL enum map to enable/disable/report event cause flags. */
#define MTB_HAL_MAP_I2C_TARGET_READ_EVENT                     (CY_SCB_I2C_SLAVE_READ_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_WRITE_EVENT                    (CY_SCB_I2C_SLAVE_WRITE_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_RD_IN_FIFO_EVENT               (CY_SCB_I2C_SLAVE_RD_IN_FIFO_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_RD_BUF_EMPTY_EVENT             (CY_SCB_I2C_SLAVE_RD_BUF_EMPTY_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_RD_CMPLT_EVENT                 (CY_SCB_I2C_SLAVE_RD_CMPLT_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_WR_CMPLT_EVENT                 (CY_SCB_I2C_SLAVE_WR_CMPLT_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_ERR_EVENT                      (CY_SCB_I2C_SLAVE_ERR_EVENT)
#if ((CY_IP_MXSCB_VERSION >= 4) && (CY_IP_MXSCB_VERSION_MINOR >= 4))
#define MTB_HAL_MAP_I2C_TARGET_RESTART_EVENT                  (CY_SCB_I2C_SLAVE_RESTART_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_STOP_EVENT                     (CY_SCB_I2C_SLAVE_STOP_ANY_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_ARB_LOST_EVENT                 (CY_SCB_I2C_SLAVE_ARB_LOST_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_TIMEOUT0_EVENT                 (CY_SCB_I2C_SLAVE_TIMEOUT0_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_TIMEOUT1_EVENT                 (CY_SCB_I2C_SLAVE_TIMEOUT1_EVENT)
#define MTB_HAL_MAP_I2C_TARGET_TIMEOUT2_EVENT                 (CY_SCB_I2C_SLAVE_TIMEOUT2_EVENT)
#define MTB_HAL_MAP_I2C_CONTROLLER_ARB_LOST_EVENT             (CY_SCB_I2C_MASTER_ARB_LOST_EVENT)
#define MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT0_EVENT             (CY_SCB_I2C_MASTER_TIMEOUT0_EVENT)
#define MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT1_EVENT             (CY_SCB_I2C_MASTER_TIMEOUT1_EVENT)
#define MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT2_EVENT             (CY_SCB_I2C_MASTER_TIMEOUT2_EVENT)
#else /* ((CY_IP_MXSCB_VERSION>=4) && (CY_IP_MXSCB_VERSION_MINOR>=4)) */
#define MTB_HAL_MAP_I2C_TARGET_RESTART_EVENT                  (0UL)
#define MTB_HAL_MAP_I2C_TARGET_STOP_EVENT                     (0UL)
#define MTB_HAL_MAP_I2C_TARGET_ARB_LOST_EVENT                 (0UL)
#define MTB_HAL_MAP_I2C_TARGET_TIMEOUT0_EVENT                 (0UL)
#define MTB_HAL_MAP_I2C_TARGET_TIMEOUT1_EVENT                 (0UL)
#define MTB_HAL_MAP_I2C_TARGET_TIMEOUT2_EVENT                 (0UL)
#define MTB_HAL_MAP_I2C_CONTROLLER_ARB_LOST_EVENT             (0UL)
#define MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT0_EVENT             (0UL)
#define MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT1_EVENT             (0UL)
#define MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT2_EVENT             (0UL)
#endif /* ((CY_IP_MXSCB_VERSION>=4) && (CY_IP_MXSCB_VERSION_MINOR>=4)) */
#define MTB_HAL_MAP_I2C_CONTROLLER_ERR_EVENT                  (CY_SCB_I2C_MASTER_ERR_EVENT)

/** I2C HAL to PDL enum map to enable/disable/report address interrupt cause flags. */
#define MTB_HAL_MAP_I2C_GENERAL_CALL_EVENT                    (CY_SCB_I2C_GENERAL_CALL_EVENT)
#define MTB_HAL_MAP_I2C_ADDR_IN_FIFO_EVENT                    (CY_SCB_I2C_ADDR_IN_FIFO_EVENT)

/**
 * @brief I2C object
 *
 * Application code should not rely on the specific contents of this staruct.
 * They are considered an implementation detail which is subject to chnge
 * between platforms and/or HAL releases.
 */
typedef struct
{
    CySCB_Type*                         base; //!< Base address for the SCB
    cy_stc_scb_i2c_context_t*           context; //!< PDL context
    const mtb_hal_clock_t*              clock; //!< Clock interface
    _mtb_hal_event_callback_data_t      callback_data; //!< User-registered callback
    _mtb_hal_event_callback_data_t      addr_callback_data; //!< User-registered address callback
    _mtb_hal_event_callback_data_t      byte_callback_data; //!< User-registered byte callback
    uint32_t                            irq_cause; //!< User-enabled events
    uint8_t                             addr_irq_cause; //!< User-enabled address events
    bool                                op_in_callback; //!< Currently operating in callback context
    _mtb_hal_buffer_info_t              rx_target_buff; //!< Target buffer for receive operations
    _mtb_hal_buffer_info_t              tx_target_buff; //!< Target buffer for transmit operations
    // I2C reconfigures at run-time using this structure, so keep track of it
    const cy_stc_scb_i2c_config_t*      config; //!< PDL-level configuration structure
} mtb_hal_i2c_t;

/**
 * @brief I2C configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    CySCB_Type*                     base; //!< Base address for the SCB
    const cy_stc_scb_i2c_config_t*  config; //!< PDL-level configuration structure
    const mtb_hal_clock_t*          clock; //!< Default clock object
} mtb_hal_i2c_configurator_t;

#endif // defined(CY_IP_MXSCB) || defined(CY_IP_MXS22SCB)
