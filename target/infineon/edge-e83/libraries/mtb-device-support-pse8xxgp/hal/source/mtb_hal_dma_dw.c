/***************************************************************************//**
* \file mtb_hal_dma_dw.c
*
* \brief
* Implements a high level interface for interacting with the Infineon Datawire DMA.
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
#include "mtb_hal_dma_dw.h"
#include "mtb_hal_dma_impl.h"
#include "mtb_hal_utils.h"

#if (_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)

#if defined(__cplusplus)
extern "C" {
#endif

/** Check if the requested DW descriptor configuration is supported */
static cy_rslt_t _mtb_hal_dma_dw_supported(const mtb_hal_dma_configurator_t* config)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    cy_en_dma_descriptor_type_t descr_type = Cy_DMA_Descriptor_GetDescriptorType(
        config->dw_descriptor);
    cy_en_dma_trigger_type_t intr_type = Cy_DMA_Descriptor_GetInterruptType(
        config->dw_descriptor);
    //Only 1-D transfer and 2-D transfer is supported
    if ((CY_DMA_1D_TRANSFER != descr_type) && (CY_DMA_2D_TRANSFER != descr_type))
    {
        result = MTB_HAL_DMA_RSLT_ERR_NOT_SUPPORTED;
    }
    //Only CY_DMA_DESCR and CY_DMA_X_LOOP interrupt types are supported
    else if ((CY_DMA_DESCR != intr_type) && (CY_DMA_X_LOOP != intr_type))
    {
        result = MTB_HAL_DMA_RSLT_ERR_NOT_SUPPORTED;
    }
    return result;
}


/** Get the expected bursts based on the descriptor configuration */
static uint32_t _mtb_hal_dma_dw_get_expected_bursts(mtb_hal_dma_t* obj)
{
    uint32_t expected_bursts = 1;
    cy_en_dma_trigger_type_t intr_type = Cy_DMA_Descriptor_GetInterruptType(
        obj->descriptor.dw);
    if (CY_DMA_DESCR == intr_type)
    {
        expected_bursts = 1;
    }
    else if (CY_DMA_X_LOOP == intr_type)
    {
        expected_bursts = Cy_DMA_Descriptor_GetYloopDataCount(obj->descriptor.dw);
    }
    return expected_bursts;
}


/** Convert PDL interrupt cause to hal dma event */
__STATIC_INLINE mtb_hal_dma_event_t _mtb_hal_dma_dw_convert_interrupt_cause(mtb_hal_dma_t* obj,
                                                                            cy_en_dma_intr_cause_t cause)
{
    static const mtb_hal_dma_event_t hal[] =
    {
        MTB_HAL_DMA_NO_INTR,
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
    CY_ASSERT(cause < sizeof(hal)/sizeof(mtb_hal_dma_event_t));
    if (cause < sizeof(hal)/sizeof(mtb_hal_dma_event_t))
    {
        hal_rslt = hal[cause];
    }

    if (((uint32_t)(hal_rslt & MTB_HAL_DMA_TRANSFER_COMPLETE) > 0) && (obj->expected_bursts > 0))
    {
        obj->expected_bursts--;
        if (0 == obj->expected_bursts)
        {
            hal_rslt |= MTB_HAL_DMA_DESCRIPTOR_COMPLETE;
            /* Setting up the expected burst count for the future transfers */
            obj->expected_bursts = _mtb_hal_dma_dw_get_expected_bursts(obj);
        }
    }

    return hal_rslt;
}


/** DW irq handler */
static void _mtb_hal_dma_dw_irq_handler(mtb_hal_dma_t* obj)
{
    /* Get interrupt type and call users event callback if they have enabled that event */
    cy_en_dma_intr_cause_t cause = Cy_DMA_Channel_GetStatus(obj->base.dw_base, obj->channel);
    mtb_hal_dma_event_t event_type = _mtb_hal_dma_dw_convert_interrupt_cause(obj, cause);
    uint32_t events_to_callback = event_type & obj->irq_cause;

    /* Clear all interrupts - this should be done prior to callback, in case the user wishes to
       chain DMA transfers
       e.g. DMA UART, which sets up a new transfer in the callback API */
    Cy_DMA_Channel_ClearInterrupt(obj->base.dw_base, obj->channel);

    if ((obj->callback_data.callback != NULL) && events_to_callback)
    {
        ((mtb_hal_dma_event_callback_t)obj->callback_data.callback)(obj->callback_data.callback_arg,
                                                                    (mtb_hal_dma_event_t)
                                                                    events_to_callback);
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dw_setup(mtb_hal_dma_t* obj, const mtb_hal_dma_configurator_t* config)
{
    cy_rslt_t result;
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != config->dw_base) ||
                          (NULL != config->dw_descriptor)), MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == config->dw_base) || (NULL == config->dw_descriptor))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    result = _mtb_hal_dma_dw_supported(config);
    if (CY_RSLT_SUCCESS == result)
    {
        obj->dma_type = config->dma_type;
        obj->channel = config->channel;
        obj->base.dw_base = (DW_Type*)config->dw_base;
        obj->descriptor.dw = config->dw_descriptor;
        obj->expected_bursts = _mtb_hal_dma_dw_get_expected_bursts(obj);
        #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
        SCB_CleanDCache_by_Addr((void*)obj->descriptor.dw, sizeof(*obj->descriptor.dw));
        #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_set_src_addr
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dw_set_src_addr(mtb_hal_dma_t* obj, uint32_t src_addr)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->descriptor.dw)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->descriptor.dw))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    Cy_DMA_Descriptor_SetSrcAddress(obj->descriptor.dw, (void*)src_addr);

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_CleanDCache_by_Addr((void*)obj->descriptor.dw, sizeof(*obj->descriptor.dw));
    #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_set_dst_addr
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dw_set_dst_addr(mtb_hal_dma_t* obj, uint32_t dst_addr)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->descriptor.dw)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->descriptor.dw))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    Cy_DMA_Descriptor_SetDstAddress(obj->descriptor.dw, (void*)dst_addr);

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_CleanDCache_by_Addr((void*)obj->descriptor.dw, sizeof(*obj->descriptor.dw));
    #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_set_length
//--------------------------------------------------------------------------------------------------
/** Set the transfer length */
cy_rslt_t _mtb_hal_dma_dw_set_length(mtb_hal_dma_t* obj, uint32_t length)
{
    cy_en_dma_descriptor_type_t descr_type;
    cy_rslt_t                   result = CY_RSLT_SUCCESS;
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dw_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dw_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // if defined(MTB_HAL_DISABLE_ERR_CHECK)
    descr_type = Cy_DMA_Descriptor_GetDescriptorType(obj->descriptor.dw);
    if (CY_DMA_2D_TRANSFER == descr_type)
    {
        //This is based on the assumption that user/app does not want to change the burst size.
        //Length in case of 2-D transfers need to be a mutiple of the burst size.TODO: check this
        uint32_t xloop_count = Cy_DMA_Descriptor_GetXloopDataCount(obj->descriptor.dw);
        if ((length > (xloop_count * CY_DMA_LOOP_COUNT_MAX)) || (length % xloop_count))
        {
            result = MTB_HAL_DMA_RSLT_ERR_INVALID_TRANSFER_SIZE;
        }
        else
        {
            Cy_DMA_Descriptor_SetYloopDataCount(obj->descriptor.dw, length/xloop_count);
        }
    }
    else if (CY_DMA_1D_TRANSFER == descr_type)
    {
        if (length > CY_DMA_LOOP_COUNT_MAX)
        {
            result = MTB_HAL_DMA_RSLT_ERR_INVALID_TRANSFER_SIZE;
        }
        else
        {
            Cy_DMA_Descriptor_SetXloopDataCount(obj->descriptor.dw, length);
        }
    }
    else
    {
        //Return not supported
        result = MTB_HAL_DMA_RSLT_ERR_NOT_SUPPORTED;
    }
    if (CY_RSLT_SUCCESS == result)
    {
        obj->expected_bursts = _mtb_hal_dma_dw_get_expected_bursts(obj);
        #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
        SCB_CleanDCache_by_Addr((void*)obj->descriptor.dw, sizeof(*obj->descriptor.dw));
        #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_enable
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dw_enable(mtb_hal_dma_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dw_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dw_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    /* Enable the DMA channel */
    Cy_DMA_Channel_Enable(obj->base.dw_base, obj->channel);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_disable
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_dma_dw_disable(mtb_hal_dma_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dw_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dw_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    /* Disable the DMA channel */
    Cy_DMA_Channel_Disable(obj->base.dw_base, obj->channel);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_is_busy
//--------------------------------------------------------------------------------------------------
bool _mtb_hal_dma_dw_is_busy(mtb_hal_dma_t* obj)
{
    CY_ASSERT((NULL != obj) || (NULL != obj->base.dw_base));

    uint32_t active_channels = Cy_DMA_GetActiveChannel(obj->base.dw_base);
    return (active_channels & (1 << obj->channel));
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_start_transfer
//--------------------------------------------------------------------------------------------------
/* Starts the DMA transfer on the specified channel */
cy_rslt_t _mtb_hal_dma_dw_start_transfer(mtb_hal_dma_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dw_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dw_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    /* Return warning if channel is busy */
    if (_mtb_hal_dma_dw_is_busy(obj))
    {
        return MTB_HAL_DMA_RSLT_WARN_TRANSFER_ALREADY_STARTED;
    }

    /* Set SW trigger for the channel */
    Cy_DMA_Channel_SetSWTrigger(obj->base.dw_base, obj->channel);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_enable_event
//--------------------------------------------------------------------------------------------------
/* Enable/disable the DMA event */
void _mtb_hal_dma_dw_enable_event(mtb_hal_dma_t* obj, mtb_hal_dma_event_t event, bool enable)
{
    CY_ASSERT(NULL != obj);
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
// _mtb_hal_dma_dw_get_max_elements_per_burst
//--------------------------------------------------------------------------------------------------
uint32_t _mtb_hal_dma_dw_get_max_elements_per_burst(mtb_hal_dma_t* obj)
{
    CY_UNUSED_PARAMETER(obj);
    return CY_DMA_LOOP_COUNT_MAX;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_dma_dw_process_interrupt
//--------------------------------------------------------------------------------------------------
/** Process interrupts related to the DMA.*/
cy_rslt_t _mtb_hal_dma_dw_process_interrupt(mtb_hal_dma_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj) || (NULL != obj->base.dw_base)),
                         MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((NULL == obj) || (NULL == obj->base.dw_base))
    {
        return MTB_HAL_DMA_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif
    _mtb_hal_dma_dw_irq_handler(obj);
    return CY_RSLT_SUCCESS;
}


#if defined(__cplusplus)
}
#endif

#endif /* _MTB_HAL_DRIVER_AVAILABLE_DMA_DW */
