/*******************************************************************************
* \file mtb_async_transfer.c
*
* \brief
* Provides API implementation for the Async Transfer Utility library.
*
********************************************************************************
* \copyright
* (c) (2024), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#include <string.h>
#include "cy_utils.h"
#include "mtb_async_transfer.h"
#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

/*******************************************************************************
*                           Private Defines
*******************************************************************************/

#define _MTB_ASYNC_TRANSFER_MIN(a, b)           (((a) < (b)) ? (a) : (b))

/*******************************************************************************
*                       Private Function Definitions
*******************************************************************************/

/* Updates the rx fifo trigger level */
static cy_rslt_t _mtb_async_transfer_update_rx_level(const mtb_async_transfer_context_t* context)
{
    uint32_t rx_fifo_level;

    CY_ASSERT(NULL != context->interface.get_rx_transfer_len);
    CY_ASSERT(NULL != context->interface.set_rx_fifo_level);

    /* Set the RX FIFO level to 'remaining bytes to read' or 'rx transfer length'
        whichever is lesser */
    rx_fifo_level =
        _MTB_ASYNC_TRANSFER_MIN(context->dest_length, context->interface.get_rx_transfer_len(
                                    context->interface.inst_ref));
    /*Setting one lesser since the interruptis triggered
        when number of bytes exceeds the 'level' */
    rx_fifo_level--;

    /* Set the RX FIFO level to trigger an interrupt. Setting one lesser since the interrupt
            is triggered when number of bytes exceeds the 'level'*/
    context->interface.set_rx_fifo_level(context->interface.inst_ref, rx_fifo_level);

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_async_transfer_rx_done
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_async_transfer_rx_done(mtb_async_transfer_context_t* context)
{
    /* Read transfer is complete */
    context->dest_addr = NULL;
    /* Invoke the callback to indicate that the read transfer is complete */
    if (NULL != context->callback)
    {
        context->callback(context->callback_arg, MTB_ASYNC_TRANSFER_DIRECTION_READ);
    }
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_async_transfer_update_tx_level_event
//--------------------------------------------------------------------------------------------------
/* Updates the tx fifo trigger level */
static cy_rslt_t _mtb_async_transfer_update_tx_level(const mtb_async_transfer_context_t* context)
{
    CY_ASSERT(NULL != context->interface.set_tx_fifo_level);
    CY_ASSERT(NULL != context->interface.get_tx_transfer_len);

    /* Set the TX FIFO level to 'tx transfer length' */
    context->interface.set_tx_fifo_level(context->interface.inst_ref,
                                         context->interface.get_tx_transfer_len(context->
                                                                                interface.
                                                                                inst_ref));

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_async_transfer_tx_done
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_async_transfer_tx_done(mtb_async_transfer_context_t* context)
{
    /* Write transfer is complete */
    context->src_addr = NULL;
    /* Invoke the callback to indicate that the write transfer is complete */
    if (NULL != context->callback)
    {
        context->callback(context->callback_arg, MTB_ASYNC_TRANSFER_DIRECTION_WRITE);
    }
    return CY_RSLT_SUCCESS;
}


/** Performs read transfer in the background using the CPU copy */
static cy_rslt_t _mtb_async_transfer_cpu_read(mtb_async_transfer_context_t* context)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    uint32_t  rx_fifo_num = 0u;
    uint32_t  index = 0u;
    uint32_t  rx_len = 0u;
    uint32_t  irq_status = 0u;

    CY_ASSERT(context->interface.transfer_width <= 4u);
    CY_ASSERT(NULL != context->interface.get_num_rx_fifo);
    CY_ASSERT(NULL != context->interface.enable_rx_event);
    CY_ASSERT(NULL != context->interface.enter_critical_section);
    CY_ASSERT(NULL != context->interface.exit_critical_section);

    /* Disable the RX FIFO level interrupt */
    context->interface.enable_rx_event(context->interface.inst_ref, false);

    /* Get the number of bytes available in the RX FIFO */
    rx_fifo_num = context->interface.get_num_rx_fifo(context->interface.inst_ref);

    /* Update the read length with lesser of 'num of entries available in the FIFO' or
        'bytes to read' */
    rx_len = _MTB_ASYNC_TRANSFER_MIN(context->dest_length, rx_fifo_num);

    /* Data available to read and Read transfer width is less than or equal to 1 byte */
    if ((0u != rx_len) && (context->interface.transfer_width <= 1u))
    {
        uint8_t* buffer = (uint8_t*)(context->dest_addr);
        /* Read the data from the RX FIFO to the buffer */
        for (index = 0u; index < rx_len; index++)
        {
            buffer[index]=  (uint8_t)(*(context->interface.rx_addr));
        }
    }
    /* Data available to read and Read transfer width is in between 1 byte(not including) and 2
       bytes */
    else if ((0u != rx_len) && (context->interface.transfer_width <= 2u))
    {
        uint16_t* buffer = (uint16_t*)(context->dest_addr);
        /* Read the data from the RX FIFO to the buffer */
        for (index = 0u; index < rx_len; index++)
        {
            buffer[index]= (uint16_t)(*(context->interface.rx_addr));
        }
    }
    /* Data available to read and Read transfer width is in between 2(not including) and 4 bytes */
    else if (0u != rx_len)
    {
        uint32_t* buffer = (uint32_t*)(context->dest_addr);
        /* Read from the RX FIFO */
        for (index = 0u; index < rx_len; index++)
        {
            buffer[index]= *(context->interface.rx_addr);
        }
    }
    irq_status = context->interface.enter_critical_section();
    /* Update the read destination address */
    context->dest_addr =
        (void*)((uint8_t*)context->dest_addr +
                (context->interface.transfer_width * rx_len));
    /* Update the read length */
    context->dest_length -= rx_len;
    context->interface.exit_critical_section(irq_status);
    if (0u != context->dest_length)
    {
        result = _mtb_async_transfer_update_rx_level(context);
        /* Enable RX FIFO level interrupt */
        context->interface.enable_rx_event(context->interface.inst_ref, true);
    }
    else
    {
        result = _mtb_async_transfer_rx_done(context);
    }
    return result;
}


/** Performs write transfer in the background */
static cy_rslt_t _mtb_async_transfer_cpu_write(mtb_async_transfer_context_t* context)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    uint32_t  index = 0u;
    uint32_t  tx_len = 0u;
    uint32_t  irq_status = 0u;

    CY_ASSERT(context->interface.transfer_width <= 4u);
    CY_ASSERT(NULL != context->interface.get_num_tx_fifo);
    CY_ASSERT(NULL != context->interface.enable_tx_event);
    CY_ASSERT(NULL != context->interface.enter_critical_section);
    CY_ASSERT(NULL != context->interface.exit_critical_section);

    /* Get the number of entries that can be written to the TX FIFO */
    tx_len = context->interface.get_num_tx_fifo(context->interface.inst_ref);

    /* Disable the TX FIFO level interrupt */
    context->interface.enable_tx_event(context->interface.inst_ref, false);

    /* Update the TX length with lesser of 'num of bytes that can be written to FIFO' or
        'bytes to write' */
    tx_len = _MTB_ASYNC_TRANSFER_MIN(context->src_length, tx_len);

    /* Data is to be written and Write transfer width is less than or equal to 1 byte */
    if ((0u != tx_len) && (context->interface.transfer_width <= 1u))
    {
        const uint8_t* buffer = (const uint8_t*)(context->src_addr);
        /* Write the data from the buffer to the TX FIFO */
        for (index = 0u; index < tx_len; index++)
        {
            *(context->interface.tx_addr) = *(buffer + index);
        }
    }
    /* Data  is to be written and Write transfer width is in between 1(not including) and 2 bytes */
    else if ((0u != tx_len) && (context->interface.transfer_width <= 2u))
    {
        const uint16_t* buffer = (const uint16_t*)(context->src_addr);
        /* Write the data from the buffer to the TX FIFO */
        for (index = 0u; index < tx_len; index++)
        {
            *(context->interface.tx_addr) = *(buffer + index);
        }
    }
    /* Read data transfer width is in between 2(not including) and 4 bytes */
    else if (0u != tx_len)
    {
        const uint32_t* buffer = (const uint32_t*)(context->src_addr);
        /* Write the data from the buffer to the TX FIFO */
        for (index = 0u; index < tx_len; index++)
        {
            *(context->interface.tx_addr) = *(buffer + index);
        }
    }
    irq_status = context->interface.enter_critical_section();
    /* Update the write source address */
    context->src_addr =
        (void*)((uint8_t*)context->src_addr +
                (context->interface.transfer_width * tx_len));
    /* Update the write length */
    context->src_length -= tx_len;
    context->interface.exit_critical_section(irq_status);

    /* Data remaining to write */
    if (0u != context->src_length)
    {
        result = _mtb_async_transfer_update_tx_level(context);
        /* Enable TX FIFO level interrupt */
        context->interface.enable_tx_event(context->interface.inst_ref, true);
    }
    else
    {
        result = _mtb_async_transfer_tx_done(context);
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_async_transfer_dma_read
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_async_transfer_dma_read(mtb_async_transfer_context_t* context)
{
    uint32_t dma_transfer_length;

    CY_ASSERT(NULL != context->interface.get_rx_transfer_len);
    CY_ASSERT(NULL != context->interface.dma_enable_rx);

    /* Update the transfer length with lesser of 'num of bytes that can be read from FIFO' or
        'bytes to read' */
    dma_transfer_length = _MTB_ASYNC_TRANSFER_MIN(context->dest_length, context->interface.get_rx_transfer_len(
                                                      context->interface.inst_ref));
    /* Disable the DMA RX interface */
    context->interface.dma_enable_rx(context->interface.dma_rx_ref, false);
    if (dma_transfer_length > 0u)
    {
        uint32_t irq_status;
        CY_ASSERT(NULL != context->interface.dma_set_src);
        CY_ASSERT(NULL != context->interface.dma_set_dest);
        CY_ASSERT(NULL != context->interface.dma_set_length);
        CY_ASSERT(NULL != context->interface.enter_critical_section);
        CY_ASSERT(NULL != context->interface.exit_critical_section);
        /* Setting up the source address from which DMA TX is initiated */
        (void)context->interface.dma_set_src(context->interface.dma_rx_ref,
                                             (void*)context->interface.rx_addr);
        /* Setting up the destination address to which DMA TX data will be copied */
        (void)context->interface.dma_set_dest(context->interface.dma_rx_ref,
                                              context->dest_addr);
        /* Setting up the length of the DMA transfer */
        (void)context->interface.dma_set_length(context->interface.dma_rx_ref, dma_transfer_length);

        #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
        SCB_InvalidateDCache_by_Addr((void*)context->dest_addr,
                                     (context->interface.transfer_width * dma_transfer_length));
        #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

        irq_status = context->interface.enter_critical_section();
        /* Update the buffer and length */
        context->dest_addr =
            (void*)((uint8_t*)context->dest_addr +
                    (context->interface.transfer_width * dma_transfer_length));
        context->dest_length -= dma_transfer_length;
        context->interface.exit_critical_section(irq_status);

        /* Enable the DMA RX interface to start the DMA transfer */
        context->interface.dma_enable_rx(context->interface.dma_rx_ref, true);
    }
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_async_transfer_dma_read_handler
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_async_transfer_dma_read_handler(mtb_async_transfer_context_t* context)
{
    cy_rslt_t result;
    if (0u != context->dest_length)
    {
        /* Update the RX trigger level */
        (void)_mtb_async_transfer_update_rx_level(context);
        /* Set up the DMA read */
        result = _mtb_async_transfer_dma_read(context);
    }
    else
    {
        CY_ASSERT(NULL != context->interface.dma_enable_rx);
        /* Disable the DMA RX event and the DMA RX channel */
        context->interface.dma_enable_rx(context->interface.dma_rx_ref, false);
        /* RX transfer is completed */
        result = _mtb_async_transfer_rx_done(context);
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_async_transfer_dma_write
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_async_transfer_dma_write(mtb_async_transfer_context_t* context)
{
    uint32_t dma_transfer_length;

    CY_ASSERT(NULL != context->interface.get_tx_transfer_len);
    CY_ASSERT(NULL != context->interface.dma_enable_tx);

    /* Update the transfer length with lesser of 'num of bytes that can be written to FIFO' or
        'bytes to write' */
    dma_transfer_length = _MTB_ASYNC_TRANSFER_MIN(context->src_length, context->interface.get_tx_transfer_len(
                                                      context->interface.inst_ref));
    /* Disable the DMA TX interface */
    context->interface.dma_enable_tx(context->interface.dma_tx_ref, false);
    if (dma_transfer_length > 0u)
    {
        uint32_t irq_status;
        CY_ASSERT(NULL != context->interface.dma_set_src);
        CY_ASSERT(NULL != context->interface.dma_set_dest);
        CY_ASSERT(NULL != context->interface.dma_set_length);
        CY_ASSERT(NULL != context->interface.enter_critical_section);
        CY_ASSERT(NULL != context->interface.exit_critical_section);
        /* Setting up the source address from which DMA RX is initiated */
        (void)context->interface.dma_set_src(context->interface.dma_tx_ref,
                                             context->src_addr);
        /* Setting up the destination address to which DMA RX data will be copied */
        (void)context->interface.dma_set_dest(context->interface.dma_tx_ref,
                                              (void*)context->interface.tx_addr);
        /* Setting up the length of the DMA transfer */
        (void)context->interface.dma_set_length(context->interface.dma_tx_ref, dma_transfer_length);

        #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
        SCB_CleanDCache_by_Addr((void*)context->src_addr,
                                (context->interface.transfer_width * dma_transfer_length));
        #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

        irq_status = context->interface.enter_critical_section();
        /* Update the buffer and length */
        context->src_addr =
            (void*)((uint8_t*)context->src_addr +
                    (context->interface.transfer_width * dma_transfer_length));
        context->src_length -= dma_transfer_length;
        context->interface.exit_critical_section(irq_status);

        /* Enable the DMA TX interface */
        context->interface.dma_enable_tx(context->interface.dma_tx_ref, true);
    }
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_async_transfer_dma_write_handler
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_async_transfer_dma_write_handler(mtb_async_transfer_context_t* context)
{
    cy_rslt_t result;
    if (0u != context->src_length)
    {
        /* Update the TX FIFO trigger level  */
        (void)_mtb_async_transfer_update_tx_level(context);
        /* Set up the DMA write */
        result = _mtb_async_transfer_dma_write(context);
    }
    else
    {
        CY_ASSERT(NULL != context->interface.dma_enable_tx);
        /* Disable the TX DMA interface */
        context->interface.dma_enable_tx(context->interface.dma_tx_ref, false);
        /* TX transfer is completed */
        result = _mtb_async_transfer_tx_done(context);
    }
    return result;
}


/*******************************************************************************
*                        Public Function Definitions
*******************************************************************************/
/** Initializes an async transfer library instance */
cy_rslt_t mtb_async_transfer_init(mtb_async_transfer_context_t* context,
                                  const mtb_async_transfer_interface_t* iface)
{
    cy_rslt_t result = MTB_ASYNC_TRANSFER_BAD_PARAM_ERROR;

    if ((NULL != context) && (NULL != iface))
    {
        /* Initialize the context to 0's */
        (void)memset(context, 0, sizeof(mtb_async_transfer_context_t));
        /* Copy the communication interface info */
        (void)memcpy(&context->interface, iface, sizeof(mtb_async_transfer_interface_t));
        result = CY_RSLT_SUCCESS;
    }
    return result;
}


/** Reads data from the peripheral to the memory in the background */
cy_rslt_t mtb_async_transfer_read(mtb_async_transfer_context_t* context, void* dest, size_t length)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    if ((NULL == context) || (NULL == dest))
    {
        result = MTB_ASYNC_TRANSFER_BAD_PARAM_ERROR;
    }
    else
    {
        /* Check if the interface is available for a read transfer */
        if (mtb_async_transfer_available_read(context) == true)
        {
            uint32_t irq_status;
            CY_ASSERT(NULL != context->interface.enter_critical_section);
            CY_ASSERT(NULL != context->interface.exit_critical_section);
            irq_status = context->interface.enter_critical_section();
            /* Store the address to copy the read data and the number of bytes to read */
            context->dest_addr = dest;
            context->dest_length = length;
            context->interface.exit_critical_section(irq_status);
            if (context->dest_length > 0u)
            {
                /* Use the DMA mode for transfer, if it is setup */
                if (NULL != context->interface.dma_rx_ref)
                {
                    /* Update the RX level */
                    (void)_mtb_async_transfer_update_rx_level(context);
                    /* Set up the DMA read */
                    result = _mtb_async_transfer_dma_read(context);
                }
                else
                {
                    /* Use the CPU copy mode for transfer */
                    result = _mtb_async_transfer_cpu_read(context);
                }
            }
        }
        else
        {
            result = MTB_ASYNC_TRANSFER_READ_BUSY;
        }
    }
    return result;
}


/** Writes data from memory to the peripheral in the background */
cy_rslt_t mtb_async_transfer_write(mtb_async_transfer_context_t* context, void* source,
                                   uint32_t length)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    if ((NULL == context) || (NULL == source))
    {
        result = MTB_ASYNC_TRANSFER_BAD_PARAM_ERROR;
    }
    else
    {
        /* Check if the interface is available for a write transfer */
        if (mtb_async_transfer_available_write(context) == true)
        {
            uint32_t irq_status;
            CY_ASSERT(NULL != context->interface.enter_critical_section);
            CY_ASSERT(NULL != context->interface.exit_critical_section);
            irq_status = context->interface.enter_critical_section();
            /* Store the address from where the data is copied to write and the number of bytes to
               write */
            context->src_addr = source;
            context->src_length = length;
            context->interface.exit_critical_section(irq_status);
            if (context->src_length > 0u)
            {
                /* Use the DMA mode for transfer, if it is setup */
                if (NULL != context->interface.dma_tx_ref)
                {
                    /* Update the TX level and enable the event to trigger the TX DMA */
                    (void)_mtb_async_transfer_update_tx_level(context);
                    /* Set up the DMA write */
                    result = _mtb_async_transfer_dma_write(context);
                }
                /* Use the CPU copy mode for transfer */
                else
                {
                    result = _mtb_async_transfer_cpu_write(context);
                }
            }
        }
        else
        {
            result = MTB_ASYNC_TRANSFER_WRITE_BUSY;
        }
    }
    return result;
}


/** Checks whether the async-transfer instance is available to start a read transfer */
bool mtb_async_transfer_available_read(const mtb_async_transfer_context_t* context)
{
    CY_ASSERT(NULL != context);
    return (((context->dest_length == 0u) && (context->dest_addr == NULL)) ? true : false);
}


/** Checks whether the async-transfer instance is available to start a write transfer */
bool mtb_async_transfer_available_write(const mtb_async_transfer_context_t* context)
{
    CY_ASSERT(NULL != context);
    return (((context->src_length == 0u) && (context->src_addr == NULL)) ? true : false);
}


/** Stops an in-progress read transfer */
cy_rslt_t mtb_async_transfer_abort_read(mtb_async_transfer_context_t* context)
{
    uint32_t irq_status;
    cy_rslt_t result = MTB_ASYNC_TRANSFER_BAD_PARAM_ERROR;
    if (NULL != context)
    {
        if (NULL != context->interface.dma_rx_ref)
        {
            CY_ASSERT(NULL != context->interface.dma_enable_rx);
            context->interface.dma_enable_rx(context->interface.dma_rx_ref, false);
        }
        CY_ASSERT(NULL != context->interface.enable_rx_event);
        CY_ASSERT(NULL != context->interface.enter_critical_section);
        CY_ASSERT(NULL != context->interface.exit_critical_section);
        /* Disable RX FIFO level interrupt */
        context->interface.enable_rx_event(context->interface.inst_ref, false);
        irq_status = context->interface.enter_critical_section();
        /* Clear the read length and address */
        context->dest_length = 0u;
        context->dest_addr = NULL;
        context->interface.exit_critical_section(irq_status);
        result = CY_RSLT_SUCCESS;
    }
    return result;
}


/** Stops an in-progress write transfer */
cy_rslt_t mtb_async_transfer_abort_write(mtb_async_transfer_context_t* context)
{
    uint32_t irq_status;
    cy_rslt_t result = MTB_ASYNC_TRANSFER_BAD_PARAM_ERROR;
    if (NULL != context)
    {
        if (NULL != context->interface.dma_tx_ref)
        {
            CY_ASSERT(NULL != context->interface.dma_enable_tx);
            context->interface.dma_enable_tx(context->interface.dma_tx_ref, false);
        }
        CY_ASSERT(NULL != context->interface.enable_tx_event);
        CY_ASSERT(NULL != context->interface.enter_critical_section);
        CY_ASSERT(NULL != context->interface.exit_critical_section);
        /* Disable TX FIFO level interrupt */
        context->interface.enable_tx_event(context->interface.inst_ref, false);
        irq_status = context->interface.enter_critical_section();
        /* Clear the write length and address */
        context->src_length = 0u;
        context->src_addr = NULL;
        context->interface.exit_critical_section(irq_status);
        result = CY_RSLT_SUCCESS;
    }
    return result;
}


/** Register a callback to be invoked when an async transfer is complete */
cy_rslt_t mtb_async_transfer_register_callback(mtb_async_transfer_context_t* context,
                                               mtb_async_transfer_event_callback_t callback,
                                               void* arg)
{
    uint32_t irq_status;
    cy_rslt_t result = MTB_ASYNC_TRANSFER_BAD_PARAM_ERROR;
    if (NULL != context)
    {
        CY_ASSERT(NULL != context->interface.enter_critical_section);
        CY_ASSERT(NULL != context->interface.exit_critical_section);
        irq_status = context->interface.enter_critical_section();
        context->callback_arg = arg;
        context->callback = callback;
        context->interface.exit_critical_section(irq_status);
        result = CY_RSLT_SUCCESS;
    }
    return result;
}


/** Handler for when the FIFO in the peripheral reaches the trigger level */
cy_rslt_t mtb_async_transfer_process_fifo_level_event(mtb_async_transfer_context_t* context,
                                                      mtb_async_transfer_direction_t direction)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    if (0u != ((uint32_t)direction & (uint32_t)MTB_ASYNC_TRANSFER_DIRECTION_READ))
    {
        /* DMA is not setup, use the CPU copy mode for receive */
        if ((context->dest_length > 0u) && (NULL == context->interface.dma_rx_ref))
        {
            result = _mtb_async_transfer_cpu_read(context);
        }
    }
    if (0u != ((uint32_t)direction & (uint32_t)MTB_ASYNC_TRANSFER_DIRECTION_WRITE))
    {
        /* DMA is not setup, use the CPU copy mode for transmit */
        if ((context->src_length > 0u) && (NULL == context->interface.dma_tx_ref))
        {
            result |= _mtb_async_transfer_cpu_write(context);
        }
    }
    result =
        ((result ==
          (MTB_ASYNC_TRANSFER_READ_ERROR|
           MTB_ASYNC_TRANSFER_WRITE_ERROR)) ? MTB_ASYNC_TRANSFER_READ_WRITE_ERROR : result);
    return result;
}


/** Handler for when a DMA transfer is complete */
cy_rslt_t mtb_async_transfer_process_dma_complete(mtb_async_transfer_context_t* context,
                                                  mtb_async_transfer_direction_t direction)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    if ((0u != ((uint32_t)direction & (uint32_t)MTB_ASYNC_TRANSFER_DIRECTION_READ)) &&
        (NULL != context->interface.dma_rx_ref))
    {
        result = _mtb_async_transfer_dma_read_handler(context);
    }

    if ((0u != ((uint32_t)direction & (uint32_t)MTB_ASYNC_TRANSFER_DIRECTION_WRITE)) &&
        (NULL != context->interface.dma_tx_ref))
    {
        result |= _mtb_async_transfer_dma_write_handler(context);
    }
    result =
        ((result ==
          (MTB_ASYNC_TRANSFER_READ_ERROR|
           MTB_ASYNC_TRANSFER_WRITE_ERROR)) ? MTB_ASYNC_TRANSFER_READ_WRITE_ERROR : result);

    return result;
}


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
