/***************************************************************************//**
* \file mtb_hal_impl_types.h
*
* \brief
* Provides type definitions that are specific to an implementation but which are
* shared between drivers within that implementation
*
********************************************************************************
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
#if defined(COMPONENT_MW_ASYNC_TRANSFER)
#include "mtb_async_transfer.h"
#endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

/** \cond INTERNAL */

// Common types that are not part of the HAL public API but are shared
// among multiple implementation-specific types

/** @brief Event callback data object */
typedef struct
{
    cy_israddress                       callback;
    void*                               callback_arg;
} _mtb_hal_event_callback_data_t;

/**
 * @brief Store information about buffer
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    union
    {
        void*       v;
        uint8_t*    u8;
        uint16_t*   u16;
        uint32_t*   u32;
    } addr;
    uint32_t size;
} _mtb_hal_buffer_info_t;

#if defined(COMPONENT_MW_ASYNC_TRANSFER)
/** Function to handle the async transfer */
typedef cy_rslt_t (* async_transfer_handler_t)(void* obj);
#endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

/** \endcond */
