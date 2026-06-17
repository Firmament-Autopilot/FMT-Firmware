/*
 * SPDX-FileCopyrightText: Copyright 2019-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ETHOSU_DEVICE_H
#define ETHOSU_DEVICE_H

/******************************************************************************
 * Includes
 ******************************************************************************/
#include "ethosu_types.h"

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Types
 ******************************************************************************/
struct NPU_REG; // Forward declare, to be implemented by each device

struct ethosu_device
{
    volatile struct NPU_REG *reg; // Register map
    uint32_t secure;
    uint32_t privileged;
};

/******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * Initialize the device.
 */
struct ethosu_device *ethosu_dev_init(void *const base_address, uint32_t secure_enable, uint32_t privilege_enable);

/**
 * Deinitialize the device.
 */
void ethosu_dev_deinit(struct ethosu_device *dev);

/**
 * Initialize AXI settings for device.
 */
enum ethosu_error_codes ethosu_dev_axi_init(struct ethosu_device *dev);

/**
 * Execute a given command stream on NPU.
 * \param[in] cmd_stream_ptr   Pointer to the command stream
 * \param[in] cms_length       Command stream length
 * \param[in] base_addr        Pointer to array of base addresses
 *                             - 0: weight tensor
 *                             - 1: scratch tensor
 *                             - All input tensors
 *                             - All output tensors
 * \param[in] num_base_addr    Number of base addresses.
 */
void ethosu_dev_run_command_stream(struct ethosu_device *dev,
                                   const uint8_t *cmd_stream_ptr,
                                   uint32_t cms_length,
                                   const uint64_t *base_addr,
                                   int num_base_addr);

/**
 * Print information on NPU error status
 */
void ethosu_dev_print_err_status(struct ethosu_device *dev);

/**
 *  Interrupt handler on device layer
 * \return                     true if NPU status is OK, otherwise false
 */
bool ethosu_dev_handle_interrupt(struct ethosu_device *dev);

/**
 * Get hardware information from NPU
 * \param[out] hwinfo          Pointer to the hardware info struct to be filled in.
 */
void ethosu_dev_get_hw_info(struct ethosu_device *dev, struct ethosu_hw_info *hwinfo);

/**
 * Verify that requested security state and privilege mode are active
 * \return                     32 bit status value
 */
bool ethosu_dev_verify_access_state(struct ethosu_device *dev);

/**
 * Performs a NPU soft reset and waits for the NPU to become ready
 * \return                     \ref ethosu_error_codes
 */
enum ethosu_error_codes ethosu_dev_soft_reset(struct ethosu_device *dev);

/**
 * Enable/disable clock and power using clock/power q interface.
 * \param[in] clock_q          Clock q ENABLE/DISABLE \ref clock_q_request.
 * \param[in] power_q          Power q ENABLE/DISABLE \ref power_q_request.
 * \return                     \ref ethosu_error_codes
 */
enum ethosu_error_codes ethosu_dev_set_clock_and_power(struct ethosu_device *dev,
                                                       enum ethosu_clock_q_request clock_q,
                                                       enum ethosu_power_q_request power_q);

/**
 * Verifies that optimizer parameters from model are compatible with the hardware
 * \param[in] cfg              Config data from optimizer.
 * \param[in] id               Id data from optimizer.
 * \return                     true if parameters match with hardware, false otherwise.
 */
bool ethosu_dev_verify_optimizer_config(struct ethosu_device *dev, uint32_t cfg_in, uint32_t id_in);

#ifdef __cplusplus
}
#endif

#endif // ETHOSU_DEVICE_H
