/***************************************************************************//**
* \file mtb_hal_dma_dw.h
*
* \brief
* Defines a high level interface for interacting with the Infineon Datawire DMA.
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

#include "mtb_hal_dma.h"

#pragma once

#if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * Sets up a HAL instance to use the specified hardware resource. This hardware
 * resource must have already been configured via the PDL.
 *
 * @param[out] obj   The HAL driver instance object. The caller must allocate the
 *                   memory for this object, but the HAL will initialize its contents
 * @param[in] config The configurator-generated HAL config structure for this
 *                   peripheral instance
 * @return the status of the HAL setup
 */
cy_rslt_t _mtb_hal_dma_dw_setup(mtb_hal_dma_t* obj, const mtb_hal_dma_configurator_t* config);

/** Set the source address for the DMA transfer
 *
 * @param[in] obj      The DMA object
 * @param[in] src_addr The source address
 * @return The status of the request
 */
cy_rslt_t _mtb_hal_dma_dw_set_src_addr(mtb_hal_dma_t* obj, uint32_t src_addr);

/** Set the destination address for the DMA transfer
 *
 * @param[in] obj       The DMA object
 * @param[in] dst_addr The destination address
 * @return The status of the request
 */
cy_rslt_t _mtb_hal_dma_dw_set_dst_addr(mtb_hal_dma_t* obj, uint32_t dst_addr);

/** Set the length for the DMA transfer
 *
 * @param[in] obj      The DMA object
 * @param[in] length   The transfer length, in bytes
 * @return The status of the request
 */
cy_rslt_t _mtb_hal_dma_dw_set_length(mtb_hal_dma_t* obj, uint32_t length);

/** Enable the DMA transfer so that it can start transferring data when triggered. A trigger
 * is caused either by calling \ref mtb_hal_dma_start_transfer or by hardware as a result of
 * connection made using the interconnect components in the device configurator. The DMA can
 * be disabled by calling \ref mtb_hal_dma_disable
 *
 * @param[in] obj    The DMA object
 * @return The status of the enable request
 */
cy_rslt_t _mtb_hal_dma_dw_enable(mtb_hal_dma_t* obj);

/** Disable the DMA transfer so that it does not continue to trigger. It can be reenabled by calling
 * \ref mtb_hal_dma_enable
 *
 * @param[in] obj    The DMA object
 * @return The status of the disable request
 */
cy_rslt_t _mtb_hal_dma_dw_disable(mtb_hal_dma_t* obj);

/** Initiates DMA channel transfer for specified DMA object. This should only be done after the
 * channel has been configured and setup and any necessary event callbacks setup
 * (\ref mtb_hal_dma_register_callback \ref mtb_hal_dma_enable_event)
 *
 * @param[in] obj    The DMA object
 * @return The status of the start_transfer request
 */
cy_rslt_t _mtb_hal_dma_dw_start_transfer(mtb_hal_dma_t* obj);

/** Checks if the transfer has been triggered, but not yet complete (eg: is pending, blocked or
   running)
 *
 * @param[in] obj    The DMA object
 * @return True if DMA channel is busy
 */
bool _mtb_hal_dma_dw_is_busy(mtb_hal_dma_t* obj);

/**
 * Process interrupts related related to a DMA instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t _mtb_hal_dma_dw_process_interrupt(mtb_hal_dma_t* obj);

/** Configure DMA event enablement.
 *
 * When an enabled event occurs, the function specified by \ref mtb_hal_dma_register_callback will
 * be called.
 *
 * @param[in] obj            The DMA object
 * @param[in] event          The DMA event type
 * recent call will take precedence, i.e all events will have the same priority.
 * @param[in] enable         True to turn on interrupts, False to turn off
 */
void _mtb_hal_dma_dw_enable_event(mtb_hal_dma_t* obj, mtb_hal_dma_event_t event, bool enable);

/** Max number of elements, that can be transferred by one burst
 *
 * @param[in]  obj         The DMA object
 * @return Max number of elements, that can be transferred by one burst
 * */
uint32_t _mtb_hal_dma_dw_get_max_elements_per_burst(mtb_hal_dma_t* obj);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _MTB_HAL_DRIVER_AVAILABLE_DMA_DW */
