/***************************************************************************//**
* \file mtb_hal_dma.h
*
* \brief
* Provides a high level interface for interacting with the Infineon DMA.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
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

/**
 * \addtogroup group_hal_dma DMA (Direct Memory Access)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the direct memory access (DMA). The DMA driver allows
 * for setting up the DMA object in order to trigger data transfers to and from
 * memory and peripherals. The transfers occur independently of the CPU and can be triggered by
 * software or hardware. Multiple channels can be active at the same time each with their own
 * user-selectable priority and transfer characteristics.
 *
 * \section section_dma_features Features
 * * CPU independent memory access
 * * Access to memory and peripherals
 * * Multiple independent channels
 * * Configurable source and destination address
 * * Configurable data transfer length
 * * Event completion notification
 *
 * \section Usage Flow
 * The operational flow of the driver is listed below. This shows the basic order in which each of
 * the functions would generally be called.
 * -# Initialize: Inititialize the DMA descriptor and channel
 * -# Setup: Set up the HAL DMA object with the pre-initialized DMA HW \ref mtb_hal_dma_setup
 * -# Enable the DMA channel and the DMA HW
 * -# Configure and Enable the DMA interrupt
 * -# Configure: \ref mtb_hal_dma_set_src_addr, \ref mtb_hal_dma_set_dst_addr, \ref
 * mtb_hal_dma_set_length
 * -# Enable the event and callback: \ref mtb_hal_dma_register_callback, \ref
 * mtb_hal_dma_enable_event
 *
 * \note In case of DMA being used by other peripheral drivers, initialize and set up the DMA
 * before the peripheral driver is initialized and setup
 *
 * \section section_dma_quickstart Quick Start
 *
 * See \ref subsection_dma_snippet_1 for a code snippet that sets up a DMA
 * transfer to move memory from one location to another.
 *
 * \section section_dma_snippets Code snippets
 * \note Error handling code has been intentionally left out of snippets to highlight API usage.
 *
 * \subsection subsection_dma_snippet_1 Snippet 1: Simple DMA initialization and transfer
 * The following snippet initializes a DMA channel and uses it to transfer a a single block of
 * memory.
 * \ref mtb_hal_dma_set_src_addr, \ref mtb_hal_dma_set_dst_addr, \ref mtb_hal_dma_set_length can be
 * used after DMA initialization to handle a variety of memory layouts.
 *
 * \snippet hal_dma.c snippet_mtb_hal_dma_simple_init
 *
 *
 * \subsection subsection_dma_snippet_2 Snippet 2: Interrupts and triggering DMA transfers
 * DMA events like transfer complete or error events can be used to trigger a callback function.
 * <br>
 * This snippet  uses \ref mtb_hal_dma_enable_event() to enable the transfer complete event
 * to trigger the callback function registered by \ref mtb_hal_dma_register_callback().
 *
 * \snippet hal_dma.c snippet_mtb_hal_dma_events
 *
 *
 * \subsection subsection_dma_snippet_3 Snippet 3: DMA transfers with D-cache
 * If CPU D-cache is enabled, DMA transfers must be handled using cache management API when dealing
 * with cacheable memory in order to maintain CPU data cache coherency.
 * Regarding the CPU data cache coherence with DMA, the general rules are, <br>
 * - Source and destination buffers must be cacheline aligned (__SCB_DCACHE_LINE_SIZE) <br>
 * - D-cache of DMA descriptor and D-cahe of source's buffers must be cleaned before a DMA transfer
 * <br>
 * - D-cache of destination buffer must be invalidated after a DMA transfer <br>
 *
 * The following snippet initializes a DMA channel and uses it to transfer a single block from one
 * cacheable memory to another cacheable memory. Cleaning D-cache of DMA descriptor is done by
 * calling \ref mtb_hal_dma_set_src_addr, \ref mtb_hal_dma_set_dst_addr, \ref mtb_hal_dma_set_length
 * and \ref mtb_hal_dma_setup. Cleaning D-cache of source's buffer and Invalidating D-cahe of
 * destination's buffer should be done explicitly.
 *
 * Refer to \ref DCACHE_Management for more information.
 *
 * \snippet hal_dma.c snippet_mtb_hal_dma_with_dcache
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_DMA)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * \addtogroup group_hal_results_dma DMA HAL Results
 * DMA specific return codes
 * \ingroup group_hal_results
 * \{
 */
/** Invalid parameter error */
#define MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER            \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_DMA, 0))
/** Transfer has already been started warning */
#define MTB_HAL_DMA_RSLT_WARN_TRANSFER_ALREADY_STARTED    \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_WARNING, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_DMA, 1))
/** Unsupported hardware error */
#define MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE       \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_FATAL, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_DMA, 2))
/** Requested transfer size is not supported */
#define MTB_HAL_DMA_RSLT_ERR_INVALID_TRANSFER_SIZE        \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_FATAL, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_DMA, 3))
/** Requested operation is not supported */
#define MTB_HAL_DMA_RSLT_ERR_NOT_SUPPORTED                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_DMA, 4))

/**
 * \}
 */

/** Flags enum of DMA events. Multiple events can be enabled via \ref mtb_hal_dma_enable_event and
 * the callback from \ref mtb_hal_dma_register_callback will be run to notify. */
typedef enum
{
    MTB_HAL_DMA_NO_INTR             = 0,      //!< No interrupt
    MTB_HAL_DMA_TRANSFER_COMPLETE   = 1 << 0, /**< Indicates that an individual transfer (burst or
                                                 full) has completed based on the dma hardware
                                                 configuration */
    MTB_HAL_DMA_DESCRIPTOR_COMPLETE = 1 << 1, //!< Indicates that the full transfer has completed
    MTB_HAL_DMA_SRC_BUS_ERROR       = 1 << 2, //!< Indicates that there is a source bus error
    MTB_HAL_DMA_DST_BUS_ERROR       = 1 << 3, //!< Indicates that there is a destination bus error
    MTB_HAL_DMA_SRC_MISAL           = 1 << 4, //!< Indicates that the source address is not aligned
    MTB_HAL_DMA_DST_MISAL           = 1 << 5, //!< Indicates that the destination address is not
                                              //!< aligned
    MTB_HAL_DMA_CURR_PTR_NULL       = 1 << 6, //!< Indicates that the current descriptor pointer is
                                              //!< null
    MTB_HAL_DMA_ACTIVE_CH_DISABLED  = 1 << 7, //!< Indicates that the active channel is disabled
    MTB_HAL_DMA_DESCR_BUS_ERROR     = 1 << 8, //!< Indicates that there has been a descriptor bus
                                              //!< error
    MTB_HAL_DMA_GENERIC_ERROR       = 1 << 9  /**< Indicates that there has been a generic error
                                                 during
                                                 the DMA transfer */
} mtb_hal_dma_event_t;

/** Event handler for DMA interrupts */
typedef void (* mtb_hal_dma_event_callback_t)(void* callback_arg, mtb_hal_dma_event_t event);

/**
 * Sets up a HAL instance to use the specified hardware resource. This hardware
 * resource must have already been configured via the PDL.
 *
 * @param[out] obj   The HAL driver instance object. The caller must allocate the
 *                   memory for this object, but the HAL will initialize its contents
 * @param[in] config The configurator-generated HAL config structure for this
 *                   peripheral instance
 * @return the status of the HAL setup
 *
 * \note If D-cache is enabled, this function cleans D-cache of DMA descriptor.
 * \note Not all the DMA configuration is supported in the HAL.
 *   Only 1D transfer and 2D transfer DMA Descriptor types are supported in the HAL
 *   Only X loop transfer (M loop in case of AXIDMAC) and decriptor transfer interrupt types are
 * supported in the HAL
 */
cy_rslt_t mtb_hal_dma_setup(mtb_hal_dma_t* obj, const mtb_hal_dma_configurator_t* config);

/** Set the source address for the DMA transfer
 *
 * @param[in] obj      The DMA object
 * @param[in] src_addr The source address
 * @return The status of the request
 *
 * \note If D-cache is enabled, this function cleans D-cache of DMA descriptor.
 */
cy_rslt_t mtb_hal_dma_set_src_addr(mtb_hal_dma_t* obj, uint32_t src_addr);

/** Set the destination address for the DMA transfer
 *
 * @param[in] obj       The DMA object
 * @param[in] dst_addr The destination address
 * @return The status of the request
 *
 * \note If D-cache is enabled, this function cleans D-cache of DMA descriptor.
 */
cy_rslt_t mtb_hal_dma_set_dst_addr(mtb_hal_dma_t* obj, uint32_t dst_addr);

/** Set the length for the DMA transfer
 *
 * @param[in] obj      The DMA object
 * @param[in] length   The transfer length, in bytes
 * @return The status of the request
 *
 * \note If D-cache is enabled, this function cleans D-cache of DMA descriptor.
 */
cy_rslt_t mtb_hal_dma_set_length(mtb_hal_dma_t* obj, uint32_t length);

/** Enable the DMA transfer so that it can start transferring data when triggered. A trigger
 * is caused either by calling \ref mtb_hal_dma_start_transfer or by hardware as a result of
 * connection made using the interconnect components in the device configurator. The DMA can
 * be disabled by calling \ref mtb_hal_dma_disable
 *
 * @param[in] obj    The DMA object
 * @return The status of the enable request
 */
cy_rslt_t mtb_hal_dma_enable(mtb_hal_dma_t* obj);

/** Disable the DMA transfer so that it does not continue to trigger. It can be reenabled by calling
 * \ref mtb_hal_dma_enable
 *
 * @param[in] obj    The DMA object
 * @return The status of the disable request
 */
cy_rslt_t mtb_hal_dma_disable(mtb_hal_dma_t* obj);

/** Initiates DMA channel transfer for specified DMA object. This should only be done after the
 * channel has been configured and setup and any necessary event callbacks setup
 * (\ref mtb_hal_dma_register_callback \ref mtb_hal_dma_enable_event)
 *
 * @param[in] obj    The DMA object
 * @return The status of the start_transfer request
 */
cy_rslt_t mtb_hal_dma_start_transfer(mtb_hal_dma_t* obj);

/** Checks if the transfer has been triggered, but not yet complete (eg: is pending, blocked or
   running)
 *
 * @param[in] obj    The DMA object
 * @return True if DMA channel is busy
 */
bool mtb_hal_dma_is_busy(mtb_hal_dma_t* obj);

/**
 * Process interrupts related related to a DMA instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_dma_process_interrupt(mtb_hal_dma_t* obj);

/** Register a DMA callback handler.
 *
 * This function will be called when one of the events enabled by \ref mtb_hal_dma_enable_event
 * occurs.
 *
 * @param[in] obj          The DMA object
 * @param[in] callback     The callback handler which will be invoked when an event triggers
 * @param[in] callback_arg Generic argument that will be provided to the callback when called
 */
void mtb_hal_dma_register_callback(mtb_hal_dma_t* obj, mtb_hal_dma_event_callback_t callback,
                                   void* callback_arg);

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
void mtb_hal_dma_enable_event(mtb_hal_dma_t* obj, mtb_hal_dma_event_t event, bool enable);

/** Max number of elements, that can be transferred by one burst
 *
 * @param[in]  obj         The DMA object
 * @return Max number of elements, that can be transferred by one burst
 * */
uint32_t mtb_hal_dma_get_max_elements_per_burst(mtb_hal_dma_t* obj);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_DMA_IMPL_HEADER
#include MTB_HAL_DMA_IMPL_HEADER
#endif /* MTB_HAL_DMA_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_DMA)

/** \} group_hal_dma */
