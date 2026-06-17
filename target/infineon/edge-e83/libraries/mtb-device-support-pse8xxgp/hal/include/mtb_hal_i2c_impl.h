/***************************************************************************//**
* \file mtb_hal_i2c_impl.h
*
* \brief
* Provides a high level interface for interacting with the Infineon I2C.
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

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * Sets up a HAL instance to use the specified hardware resource. This hardware
 * resource must have already been configured via the PDL.
 *
 * @param[out] obj     The HAL driver instance object. The caller must allocate the
 *                     memory for this object, but the HAL will initialize its contents
 * @param[in]  config  The configurator-generated HAL config structure for this
 *                     peripheral instance
 * @param[in]  context Pointer to the I2C context structure. This is the context
 *                     structure passed when doing the I2C driver HW Initialization
 * @param[in]  clock   The clock divider that clocks the I2C instance
 * @return the status of the HAL setup
 */
cy_rslt_t mtb_hal_i2c_setup(mtb_hal_i2c_t* obj, const mtb_hal_i2c_configurator_t* config,
                            cy_stc_scb_i2c_context_t* context, const mtb_hal_clock_t* clock);

#if defined(__cplusplus)
}
#endif /* __cplusplus */
