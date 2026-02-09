/***************************************************************************//**
* \file mtb_hal_dma_dmac.c
*
* \brief
* Implements a high level interface for interacting with the Infineon DMAC.
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
#include "mtb_hal_dma_dmac.h"
#include "mtb_hal_dma_impl.h"
#include "mtb_hal_utils.h"

#if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC)

#if defined(__cplusplus)
extern "C" {
#endif

/** Convert PDL interrupt cause to hal dma event */
static inline mtb_hal_dma_event_t _mtb_hal_dma_dmac_convert_interrupt_cause(mtb_hal_dma_t* obj,
                                                                            uint32_t cause)
{
    static const mtb_hal_dma_event_t hal[] =
    {
        MTB_HAL_DMA_TRANSFER_COMPLETE,
        MTB_HAL_DMA_SRC_BUS_ERROR,
        MTB_HAL_DMA_DST_BUS_ERROR,
        MTB_HAL_DMA_SRC_MISAL,
        MTB_HAL_DMA_DST_MISAL,
        MTB_HAL_DMA_CURR_PTR_NULL,
        MTB_HAL_DMA_ACTIVE_CH_DISABLED,
        MTB_HAL_DMA_DESCR_BUS_ERROR
    };

    mtb_hal_dma_event_t hal_rslt = MTB_HAL_DMA_NO_INTR;
    for (uint8_t i = 0; cause > 0 && i < sizeof(hal)/sizeof(mtb_hal_dma_event_t); i++)
    {
        if ((cause & (1 << i)) > 0)
        {
            hal_rslt |= hal[i];
        }
    }

    if (((uint32_t)(hal_rslt & MTB_HAL_DMA_TRANSFER_COMPLETE) > 0) && (obj->expected_bursts > 0))
    {
        obj->expected_bursts--;
        if (0 == obj->expected_bursts)
        {
            hal_rslt |= MTB_HAL_DMA_DESCRIPTOR_COMPLETE;
            /* Setting up the expected burst count for the future transfers */
            obj->expected_bursts = _mtb_hal_dma_dmac_get_expected_bursts(obj);
        }
    }
    return hal_rslt;
}


/** DMAC irq handler */
static void _mtb_hal_dma_dmac_irq_handler(mtb_hal_dma_t* obj)
{
    /* Get interrupt type and call event callback if that event is enabled*/
    uint32_t cause   = _mtb_hal_dma_dmac_channel_get_interrupt_status_masked(obj);
    mtb_hal_dma_event_t event_type = _mtb_hal_dma_dmac_convert_interrupt_cause(obj, cause);
    uint32_t events_to_callback    = event_type & obj->irq_cause;

    /* Clear all interrupts - this should be done prior to callback, in case the user wishes to
       chain DMA transfers for example sets up a new transfer in the callback API */
    _mtb_hal_dma_dmac_channel_clear_interrupt(obj);

    if ((obj->callback_data.callback != NULL) && events_to_callback)
    {
        ((mtb_hal_dma_event_callback_t)obj->callback_data.callback)(obj->callback_data.callback_arg,
                                                                    (mtb_hal_dma_event_t)
                                                                    events_to_callback);
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dmac_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dmac_setup(mtb_hal_dma_t* obj, const mtb_hal_dma_configurator_t* config)
{
    cy_rslt_t result;
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != config->dmac_base) ||
                          (NULL != config->dmac_descriptor)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == config->dmac_base) || (NULL == config->dmac_descriptor))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    result = _mtb_hal_dma_dmac_supported(config);
    if (CY_RSLT_SUCCESS == result)
    {
        _mtb_hal_dma_dmac_config_setup(obj, config);
        obj->expected_bursts = _mtb_hal_dma_dmac_get_expected_bursts(obj);
    }

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_CleanDCache_by_Addr((void*)obj->descriptor.dmac, sizeof(*obj->descriptor.dmac));
    #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dmac_set_src_addr
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dmac_set_src_addr(mtb_hal_dma_t* obj, uint32_t src_addr)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->descriptor.dmac)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->descriptor.dmac))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    _mtb_hal_dma_dmac_descriptor_set_src_addr(obj, src_addr);

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_CleanDCache_by_Addr((void*)obj->descriptor.dmac, sizeof(*obj->descriptor.dmac));
    #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dmac_set_dst_addr
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dmac_set_dst_addr(mtb_hal_dma_t* obj, uint32_t dst_addr)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->descriptor.dmac)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->descriptor.dmac))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    _mtb_hal_dma_dmac_descriptor_set_dst_addr(obj, dst_addr);

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_CleanDCache_by_Addr((void*)obj->descriptor.dmac, sizeof(*obj->descriptor.dmac));
    #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dmac_set_length
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dmac_set_length(mtb_hal_dma_t* obj, uint32_t length)
{
    cy_rslt_t result;
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->descriptor.dmac)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->descriptor.dmac))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // if defined(MTB_HAL_DISABLE_ERR_CHECK)
    result = _mtb_hal_dma_dmac_descriptor_set_length(obj, length);
    if (CY_RSLT_SUCCESS == result)
    {
        obj->expected_bursts = _mtb_hal_dma_dmac_get_expected_bursts(obj);
    }

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_CleanDCache_by_Addr((void*)obj->descriptor.dmac, sizeof(*obj->descriptor.dmac));
    #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dmac_enable
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dmac_enable(mtb_hal_dma_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dmac_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dmac_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    /* Enable the DMA channel */
    _mtb_hal_dma_dmac_channel_enable(obj);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dmac_disable
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dmac_disable(mtb_hal_dma_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dmac_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dmac_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    /* Disable the DMA channel */
    _mtb_hal_dma_dmac_channel_disable(obj);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dmac_is_busy
//--------------------------------------------------------------------------------------------------
bool _mtb_hal_dma_dmac_is_busy(mtb_hal_dma_t* obj)
{
    CY_ASSERT((NULL != obj) || (NULL != obj->base.dmac_base));

    uint32_t active_channels = _mtb_hal_dma_dmac_get_active_channels(obj);
    return (active_channels & (1 << obj->channel));
}


/* Starts the DMA transfer on the specified channel */
cy_rslt_t _mtb_hal_dma_dmac_start_transfer(mtb_hal_dma_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dmac_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dmac_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    /* Return warning if channel is busy */
    if (_mtb_hal_dma_dmac_is_busy(obj))
    {
        return MTB_HAL_DMA_RSLT_WARN_TRANSFER_ALREADY_STARTED;
    }
    /* Set SW trigger for the channel */
    _mtb_hal_dma_dmac_channel_set_swtrigger(obj);
    return CY_RSLT_SUCCESS;
}


/* Enable/disable the DMA event */
void _mtb_hal_dma_dmac_enable_event(mtb_hal_dma_t* obj, mtb_hal_dma_event_t event, bool enable)
{
    if (enable)
    {
        obj->irq_cause |= event;
    }
    else
    {
        obj->irq_cause &= ~event;
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dmac_get_max_elements_per_burst
//--------------------------------------------------------------------------------------------------
uint32_t _mtb_hal_dma_dmac_get_max_elements_per_burst(mtb_hal_dma_t* obj)
{
    CY_UNUSED_PARAMETER(obj);
    return _MTB_HAL_DMAC_MAX_EL_PER_TRANSFER;
}


/** Process interrupts related to the DMA.*/
cy_rslt_t _mtb_hal_dma_dmac_process_interrupt(mtb_hal_dma_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dmac_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dmac_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    _mtb_hal_dma_dmac_irq_handler(obj);
    return CY_RSLT_SUCCESS;
}


#if defined(__cplusplus)
}
#endif

#endif /* _MTB_HAL_DRIVER_AVAILABLE_DMA_DMAC */
