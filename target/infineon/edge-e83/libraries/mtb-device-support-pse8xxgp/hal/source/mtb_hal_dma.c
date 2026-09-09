/***************************************************************************//**
* \file mtb_hal_dma.c
*
* \brief
* Implements a high level interface for interacting with the Infineon DMA.
* This implementation abstracts out the chip specific details. If any chip specific
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
 * \addtogroup group_hal_impl_dma DMA (Direct Memory Access)
 * \ingroup group_hal_impl
 * \{
 * \section section_hal_impl_dma_data_arr_requirement User-provided data arrays requirements
 * CM7 cores support Data Cache. Data Cache line is 32 bytes. User needs to make
 * sure that
 * the source and destination buffer pointers points to 32 byte aligned data. User can use
 * CY_ALIGN(32) macro for
 * 32 byte alignment.
 *
 * \} group_hal_impl_dma
 */

#include "mtb_hal_dma.h"
#include "mtb_hal_system.h"
#include <string.h>

#if (MTB_HAL_DRIVER_AVAILABLE_DMA)

#if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
#include "mtb_hal_dma_dmac.h"
#endif
#if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
#include "mtb_hal_dma_dw.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_dma_setup(mtb_hal_dma_t* obj, const mtb_hal_dma_configurator_t* config)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != config);

    memset(obj, 0, sizeof(mtb_hal_dma_t));

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == config->dma_type)
    {
        return _mtb_hal_dma_dw_setup(obj, config);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == config->dma_type)
    {
        return _mtb_hal_dma_dmac_setup(obj, config);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_set_src_addr
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_dma_set_src_addr(mtb_hal_dma_t* obj, uint32_t src_addr)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_set_src_addr(obj, src_addr);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_set_src_addr(obj, src_addr);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_set_dst_addr
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_dma_set_dst_addr(mtb_hal_dma_t* obj, uint32_t dst_addr)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_set_dst_addr(obj, dst_addr);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_set_dst_addr(obj, dst_addr);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_set_length
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_dma_set_length(mtb_hal_dma_t* obj, uint32_t length)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_set_length(obj, length);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_set_length(obj, length);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_start_transfer
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_dma_start_transfer(mtb_hal_dma_t* obj)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_start_transfer(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    else if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_start_transfer(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_enable
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_dma_enable(mtb_hal_dma_t* obj)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_enable(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_enable(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_disable
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_dma_disable(mtb_hal_dma_t* obj)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_disable(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_disable(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_is_busy
//--------------------------------------------------------------------------------------------------
bool mtb_hal_dma_is_busy(mtb_hal_dma_t* obj)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_is_busy(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_is_busy(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return false;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_dma_register_callback(mtb_hal_dma_t* obj, mtb_hal_dma_event_callback_t callback,
                                   void* callback_arg)
{
    CY_ASSERT(NULL != obj);

    uint32_t saved_intr_status = Cy_SysLib_EnterCriticalSection();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    Cy_SysLib_ExitCriticalSection(saved_intr_status);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_dma_enable_event(mtb_hal_dma_t* obj, mtb_hal_dma_event_t event, bool enable)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        _mtb_hal_dma_dw_enable_event(obj, event, enable);
        return;
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        _mtb_hal_dma_dmac_enable_event(obj, event, enable);
        return;
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_get_max_elements_per_burst
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_dma_get_max_elements_per_burst(mtb_hal_dma_t* obj)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_get_max_elements_per_burst(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_get_max_elements_per_burst(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return 0;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_dma_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_dma_process_interrupt(mtb_hal_dma_t* obj)
{
    CY_ASSERT(NULL != obj);

    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
    if (MTB_HAL_DMA_DW == obj->dma_type)
    {
        return _mtb_hal_dma_dw_process_interrupt(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW) */
    #if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)
    if (MTB_HAL_DMA_DMAC == obj->dma_type)
    {
        return _mtb_hal_dma_dmac_process_interrupt(obj);
    }
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC) */
    return MTB_HAL_DMA_RSLT_FATAL_UNSUPPORTED_HARDWARE;
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* (MTB_HAL_DRIVER_AVAILABLE_DMA) */
