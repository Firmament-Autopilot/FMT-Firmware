/***************************************************************************//**
* \file mtb_hal_hw_types_mxsdhc.h
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

/** \cond INTERNAL */

#if defined(CY_IP_MXSDHC)
/**
 * Data transfer status on SDHC/SDIO
 */
typedef enum
{
    /** No data transfer in progress */
    _MTB_HAL_SDXX_NOT_RUNNING           = 0x0,
    /** Waiting for a command to complete */
    _MTB_HAL_SDXX_WAIT_CMD_COMPLETE     = 0x1,
    /** Waiting for a transfer to complete */
    _MTB_HAL_SDXX_WAIT_XFER_COMPLETE    = 0x2,
    /** Waiting for completion of both a command and a transfer */
    _MTB_HAL_SDXX_WAIT_BOTH             = _MTB_HAL_SDXX_WAIT_CMD_COMPLETE |
                                          _MTB_HAL_SDXX_WAIT_XFER_COMPLETE
} _mtb_hal_sdxx_data_transfer_status_t;

/**
 * Contains common members between SDHC and SDIO
 */
typedef struct
{
    bool                                  is_sdio;
    void*                                 obj;
    SDHC_Type*                            base;
    cy_stc_sd_host_context_t*             context;
    const mtb_hal_clock_t*                clock;

    bool                                  emmc;
    cy_en_sd_host_dma_type_t              dma_type;
    uint32_t                              adma_descriptor_tbl[2];
    _mtb_hal_sdxx_data_transfer_status_t  data_transfer_status;

    mtb_hal_gpio_t                        pin_clk;
    mtb_hal_gpio_t                        pin_cmd;
    bool                                  low_voltage_io_set;

    uint32_t                              irq_cause;
} _mtb_hal_sdxx_t;

#endif /* defined(CY_IP_MXSDHC) */

/** \endcond */
