/*******************************************************************************
* File Name: mtb_hal_uart.c
*
* Description:
* Provides a high level interface for interacting with the Infineon UART. This is
* a wrapper around the lower level PDL API.
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

#include <stdlib.h>
#include <string.h>

#include "mtb_hal_uart.h"
#include "mtb_hal_gpio.h"
#include "mtb_hal_system_impl.h"
#include "mtb_hal_utils.h"
#include "mtb_hal_irq_impl.h"
#if (MTB_HAL_DRIVER_AVAILABLE_DMA)
#include "mtb_hal_dma.h"
#endif /* (MTB_HAL_DRIVER_AVAILABLE_DMA */
#if defined(COMPONENT_MW_ASYNC_TRANSFER)
#include "mtb_async_transfer.h"
#endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

#if (MTB_HAL_DRIVER_AVAILABLE_UART)

/** \ingroup group_hal_uart
 * \{
 * \section group_hal_uart_dma_transfers Asynchronous DMA Transfers
 * Asynchronous transfers can be performed using DMA to load data into
 * and from the FIFOs. The purpose of this is to minimize CPU load on
 * large transfers.
 *
 * \section group_hal_uart_pm_strategy UART at different power modes
 * In order to allow UART to maintain the specified baud rate in all
 * power modes as the clock inputs can change when switching power modes,
 * it is necessary to adjust the baud rate. The UART HAL cannot automatically
 * update the baud rate  because it does not own the source clock.
 * The application must adjust the UART source clock itself to retain
 * the desired frequency.
 * \} group_hal_uart
 */


#if defined(__cplusplus)
extern "C"
{
#endif

/*******************************************************************************
*                           Private Defines
*******************************************************************************/


/*******************************************************************************
*                           Private Variables
*******************************************************************************/

/* Keep track of the current UART object to ensure we are referencing the
 * correct one, as we don't directly pass the object through the PDL callback
 * indirection.  This also protects against a nested callback situation. */
static volatile mtb_hal_uart_t* _mtb_hal_uart_irq_obj = NULL;

/*******************************************************************************
*                       Private Function Definitions
*******************************************************************************/

//HAL_NEXT_TODO Propose to move to the PDL
/** Returns the UART's mode of operation */
__STATIC_INLINE uint32_t _mtb_hal_uart_get_mode(CySCB_Type const* base)
{
    return _FLD2VAL(SCB_UART_CTRL_MODE, SCB_UART_CTRL(base));
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart_irq_handler
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_uart_irq_handler(mtb_hal_uart_t* obj)
{
    /* Save the old value and store it aftewards in case we get into a nested IRQ situation */
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in
       here, they
     * just might change where the original pointer points */
    mtb_hal_uart_t* old_irq_obj = (mtb_hal_uart_t*)_mtb_hal_uart_irq_obj;

    CY_ASSERT(NULL != obj);

    _mtb_hal_uart_irq_obj = obj;

    /* Cy_SCB_UART_Interrupt() manipulates the interrupt masks. Save a copy to work around it. */
    uint32_t txMasked = Cy_SCB_GetTxInterruptStatusMasked(obj->base);
    uint32_t rxMasked = Cy_SCB_GetRxInterruptStatusMasked(obj->base);

    /* SCB high-level API interrupt handler. Must be called as high-level API is used in the HAL */
    Cy_SCB_UART_Interrupt(obj->base, obj->context);

    /* Custom handling for TX overflow (cannot occur using HAL API but can occur if user makes
       custom modifications)
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        but it only takes care of NACK and ARB_LOST errors. */
    if (0UL != (CY_SCB_UART_TX_OVERFLOW & txMasked))
    {
        Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_OVERFLOW);

        if (NULL != obj->context->cbEvents)
        {
            obj->context->cbEvents(CY_SCB_UART_TRANSMIT_ERR_EVENT);
        }
    }

    /* Custom handling for TX underflow (cannot occur using HAL API but can occur if user makes
       custom modifications)
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        but it only takes care of NACK and ARB_LOST errors. */
    if (0UL != (CY_SCB_UART_TX_UNDERFLOW & txMasked))
    {
        Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_UNDERFLOW);

        if (NULL != obj->context->cbEvents)
        {
            obj->context->cbEvents(CY_SCB_UART_TRANSMIT_ERR_EVENT);
        }
    }

    /* Custom handling for TX FIFO trigger.
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        when processing CY_SCB_TX_INTR_LEVEL. Do not clear the interrupt. */
    if (0UL != (CY_SCB_UART_TX_TRIGGER & txMasked))
    {
        if (NULL != obj->context->cbEvents)
        {
            obj->context->cbEvents((uint32_t)MTB_HAL_UART_IRQ_TX_FIFO);
        }
    }

    /* Manually clear the tx done interrupt and re-enable the interrupt mask */
    if (0UL != (CY_SCB_UART_TX_DONE & txMasked))
    {
        Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_DONE);
        Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(
                                      obj->base) | CY_SCB_UART_TX_DONE);
    }

    /* Custom handling for RX underflow (cannot occur using HAL API but can occur if user makes
       custom modifications)
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        which takes care of overflow, frame and parity errors. */
    if (0UL != (CY_SCB_RX_INTR_UNDERFLOW & rxMasked))
    {
        Cy_SCB_ClearRxInterrupt(obj->base, CY_SCB_RX_INTR_UNDERFLOW);

        if (NULL != obj->context->cbEvents)
        {
            obj->context->cbEvents(CY_SCB_UART_RECEIVE_ERR_EVENT);
        }
    }

    /* Custom handling for RX FIFO trigger
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        when processing CY_SCB_RX_INTR_LEVEL. Do not clear the interrupt. */
    if (0UL != (CY_SCB_UART_RX_TRIGGER & rxMasked))
    {
        if (NULL != obj->context->cbEvents)
        {
            obj->context->cbEvents((uint32_t)MTB_HAL_UART_IRQ_RX_FIFO);
        }
    }
    _mtb_hal_uart_irq_obj = old_irq_obj;
}


#if defined(HAL_NEXT_TODO)
#if defined(BCM55500)
// Interrupts are implemented oddly in PDL: they auto-disable themselves after firing.  So
// re-enable
static void _mtb_hal_uart0_irq_handler(void)
{
    _mtb_hal_uart_irq_handler(scb_0_interrupt_IRQn);
    Cy_SCB_EnableInterrupt(SCB0);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart1_irq_handler
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_uart1_irq_handler(void)
{
    _mtb_hal_uart_irq_handler(scb_1_interrupt_IRQn);
    Cy_SCB_EnableInterrupt(SCB1);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart2_irq_handler
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_uart2_irq_handler(void)
{
    _mtb_hal_uart_irq_handler(scb_2_interrupt_IRQn);
    Cy_SCB_EnableInterrupt(SCB2);
}


static CY_SCB_IRQ_THREAD_CB_t _mtb_hal_irq_cb[3] =
    { _mtb_hal_uart0_irq_handler, _mtb_hal_uart1_irq_handler, _mtb_hal_uart2_irq_handler };
#endif // defined(BCM55500)
#endif // if defined(HAL_NEXT_TODO)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart_cb_wrapper
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_uart_cb_wrapper(uint32_t event)
{
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in
       here, they
     * just might change where the original pointer points */
    mtb_hal_uart_t* obj = (mtb_hal_uart_t*)_mtb_hal_uart_irq_obj;
    CY_ASSERT(NULL != obj);
    mtb_hal_uart_event_t anded_events = (mtb_hal_uart_event_t)(obj->irq_cause & event);

    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    /* Suppress TX_DONE events while async transfer is in progress to prevent spurious TX done
       notifications if the FIFO temporarily runs empty */
    if ((anded_events & MTB_HAL_UART_IRQ_TX_DONE) && (NULL != obj->async_ctx))
    {
        if (!mtb_hal_uart_is_async_tx_available(obj))
        {
            /* Async TX is in progress, suppress TX_DONE event */
            anded_events &= ~MTB_HAL_UART_IRQ_TX_DONE;
        }
    }
    #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

    if (anded_events)
    {
        mtb_hal_uart_event_callback_t callback =
            (mtb_hal_uart_event_callback_t)obj->callback_data.callback;
        if (NULL != callback)
        {
            callback(obj->callback_data.callback_arg, anded_events);
        }
    }
}


/** Determines if UART peripheral is in use */
__STATIC_INLINE bool _mtb_hal_uart_is_busy(mtb_hal_uart_t* obj)
{
    return (mtb_hal_uart_is_rx_active(obj) || mtb_hal_uart_is_tx_active(obj));
}


#if defined(COMPONENT_MW_ASYNC_TRANSFER)

/** Handles the UART async transfer Invokes the fifo level event processing functions */
cy_rslt_t _mtb_hal_uart_async_transfer_handler(void* obj)
{
    uint32_t      direction = 0;
    cy_rslt_t     result = CY_RSLT_SUCCESS;
    mtb_hal_uart_t* uart_obj = (mtb_hal_uart_t*)obj;

    CY_ASSERT(NULL != uart_obj);

    uint32_t txMasked = Cy_SCB_GetTxInterruptStatusMasked(uart_obj->base);
    uint32_t rxMasked = Cy_SCB_GetRxInterruptStatusMasked(uart_obj->base);

    /* RX FIFO level event  */
    if (0u != (CY_SCB_UART_RX_TRIGGER & rxMasked))
    {
        direction = MTB_ASYNC_TRANSFER_DIRECTION_READ;
    }
    /* TX FIFO level event  */
    if (0u != (CY_SCB_UART_TX_TRIGGER & txMasked))
    {
        direction |= MTB_ASYNC_TRANSFER_DIRECTION_WRITE;
    }
    if (direction)
    {
        result =
            mtb_async_transfer_process_fifo_level_event(uart_obj->async_ctx,
                                                        (mtb_async_transfer_direction_t)direction);
    }
    return result;
}


/** Returns the number of bytes available in RX FIFO */
uint32_t _mtb_hal_uart_async_transfer_get_num_rx_fifo(void* inst_ref)
{
    return Cy_SCB_UART_GetNumInRxFifo(((mtb_hal_uart_t*)inst_ref)->base);
}


/** Returns the number of elements that can be written to the TX FIFO */
uint32_t _mtb_hal_uart_async_transfer_get_num_tx_fifo(void* inst_ref)
{
    CY_ASSERT(NULL != inst_ref);
    return (Cy_SCB_GetFifoSize(((mtb_hal_uart_t*)inst_ref)->base) -
            Cy_SCB_UART_GetNumInTxFifo(((mtb_hal_uart_t*)inst_ref)->base));
}


/** Enable/disable the UART RX Interrupt event */
void _mtb_hal_uart_async_transfer_enable_rx_event(void* inst_ref, bool enable)
{
    CY_ASSERT(NULL != inst_ref);
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    uint32_t rx_mask = Cy_SCB_GetRxInterruptMask(((mtb_hal_uart_t*)inst_ref)->base);
    rx_mask = (enable ? (rx_mask | CY_SCB_UART_RX_TRIGGER) : (rx_mask & ~CY_SCB_UART_RX_TRIGGER));
    Cy_SCB_SetRxInterruptMask(((mtb_hal_uart_t*)inst_ref)->base, rx_mask);
    mtb_hal_system_critical_section_exit(savedIntrStatus);
}


/** Enable/disable the UART TX Interrupt event */
void _mtb_hal_uart_async_transfer_enable_tx_event(void* inst_ref, bool enable)
{
    CY_ASSERT(NULL != inst_ref);
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    uint32_t tx_mask = Cy_SCB_GetTxInterruptMask(((mtb_hal_uart_t*)inst_ref)->base);

    tx_mask = (enable ? (tx_mask | CY_SCB_UART_TX_TRIGGER) : (tx_mask & ~CY_SCB_UART_TX_TRIGGER));
    Cy_SCB_SetTxInterruptMask(((mtb_hal_uart_t*)inst_ref)->base, tx_mask);
    mtb_hal_system_critical_section_exit(savedIntrStatus);
}


/** Get the UART RX transfer length for single transfer */
uint32_t _mtb_hal_uart_async_transfer_get_rx_transfer_len(void* inst_ref)
{
    CY_ASSERT(NULL != inst_ref);
    /* RX transfer length is RTS FIFO level when flow control is enabled
       and RTS output is connected to a pin */
    if (((mtb_hal_uart_t*)inst_ref)->rts_enable)
    {
        return Cy_SCB_UART_GetRtsFifoLevel(((mtb_hal_uart_t*)inst_ref)->base);
    }
    /* RX transfer length is half of the fifo size when flow control is not enabled*/
    else
    {
        return (Cy_SCB_GetFifoSize(((mtb_hal_uart_t*)inst_ref)->base)/2);
    }
}


/** Get the UART TX transfer length for single transfer */
uint32_t _mtb_hal_uart_async_transfer_get_tx_transfer_len(void* inst_ref)
{
    CY_ASSERT(NULL != inst_ref);
    /* TX transfer length is half of the fifo size */
    return (Cy_SCB_GetFifoSize(((mtb_hal_uart_t*)inst_ref)->base)/2);
}


/** Sets the RX FIFO threshold. When there are more data elements in the
   FIFO than this level, the RX level interrupt is triggered */
void _mtb_hal_uart_async_transfer_set_rx_fifo_level(void* inst_ref, uint32_t level)
{
    Cy_SCB_SetRxFifoLevel(((mtb_hal_uart_t*)inst_ref)->base, level);
}


/** Sets the RX FIFO threshold.When there are fewer data elements in the
   FIFO than this level, the TX level interrupt is triggered */
void _mtb_hal_uart_async_transfer_set_tx_fifo_level(void* inst_ref, uint32_t level)
{
    Cy_SCB_SetTxFifoLevel(((mtb_hal_uart_t*)inst_ref)->base, level);
}


/** Configure the UART interface for async transfer */
cy_rslt_t _mtb_hal_uart_config_async_common(mtb_hal_uart_t* obj,
                                            mtb_async_transfer_context_t* context,
                                            mtb_async_transfer_interface_t* interface)
{
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    /* Return busy if an async operation is in progress */
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj->async_ctx) &&
                          (mtb_hal_uart_is_async_tx_available(obj) ||
                           mtb_hal_uart_is_async_rx_available(
                               obj))), MTB_HAL_UART_RSLT_ERR_BUSY);
    #else
    if ((NULL != obj->async_ctx) &&
        (!mtb_hal_uart_is_async_tx_available(obj) || !mtb_hal_uart_is_async_rx_available(obj)))
    {
        return MTB_HAL_UART_RSLT_ERR_BUSY;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

    /* Set the UART peripheral interface */
    memset(interface, 0, sizeof(mtb_async_transfer_interface_t));

    obj->async_handler = NULL;

    interface->rx_addr = (uint32_t*)&((obj->base)->RX_FIFO_RD);
    interface->tx_addr = (uint32_t*)&((obj->base)->TX_FIFO_WR);
    /*Set this directly to the communications peripheral object.*/
    interface->inst_ref = obj;
    interface->get_num_rx_fifo = _mtb_hal_uart_async_transfer_get_num_rx_fifo;
    interface->get_num_tx_fifo = _mtb_hal_uart_async_transfer_get_num_tx_fifo;
    interface->set_rx_fifo_level = _mtb_hal_uart_async_transfer_set_rx_fifo_level;
    interface->set_tx_fifo_level = _mtb_hal_uart_async_transfer_set_tx_fifo_level;
    interface->enable_rx_event = _mtb_hal_uart_async_transfer_enable_rx_event;
    interface->enable_tx_event = _mtb_hal_uart_async_transfer_enable_tx_event;
    interface->get_rx_transfer_len = _mtb_hal_uart_async_transfer_get_rx_transfer_len;
    interface->get_tx_transfer_len = _mtb_hal_uart_async_transfer_get_tx_transfer_len;
    interface->transfer_width = _mtb_hal_scb_get_transfer_width(obj->base); /* Read from config
                                                                               registers */

    interface->enter_critical_section = Cy_SysLib_EnterCriticalSection;
    interface->exit_critical_section = Cy_SysLib_ExitCriticalSection;
    obj->async_ctx = context;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart_async_transfer_event_callback
//--------------------------------------------------------------------------------------------------
void _mtb_hal_uart_async_transfer_event_callback(void* callback_arg,
                                                 mtb_async_transfer_direction_t direction)
{
    mtb_hal_uart_event_t  event;
    mtb_hal_uart_t*       obj    = (mtb_hal_uart_t*)callback_arg;

    if (NULL == obj)
    {
        return;  /* The object is not valid */
    }

    if (direction == MTB_ASYNC_TRANSFER_DIRECTION_READ)
    {
        event = MTB_HAL_UART_IRQ_RX_DONE;
    }
    else
    {
        // Bytes are transmitted to the HW FIFO
        event = MTB_HAL_UART_IRQ_TX_TRANSMIT_IN_FIFO;
    }
    event &= (mtb_hal_uart_event_t)(obj->irq_cause);
    if (event)
    {
        mtb_hal_uart_event_callback_t callback =
            (mtb_hal_uart_event_callback_t)obj->callback_data.callback;
        if (NULL != callback)
        {
            callback(obj->callback_data.callback_arg, event);
        }
    }
}


#if (MTB_HAL_DRIVER_AVAILABLE_DMA)

/** Enable/disable the DMA transfer complete event and UART DMA channel*/
void _mtb_hal_uart_async_transfer_enable_dma(void* inst_ref, bool enable)
{
    CY_ASSERT(NULL != inst_ref);
    mtb_hal_dma_enable_event((mtb_hal_dma_t*)inst_ref,
                             MTB_HAL_DMA_DESCRIPTOR_COMPLETE,
                             enable);
    mtb_hal_dma_enable_event((mtb_hal_dma_t*)inst_ref,
                             MTB_HAL_DMA_TRANSFER_COMPLETE,
                             enable);
    enable ? mtb_hal_dma_enable((mtb_hal_dma_t*)inst_ref) : mtb_hal_dma_disable(
        (mtb_hal_dma_t*)inst_ref);
}


/** RX DMA transfer complete event callback */
void _mtb_hal_uart_rx_dma_event_callback(void* callback_arg, mtb_hal_dma_event_t event)
{
    mtb_hal_uart_t* obj = (mtb_hal_uart_t*)callback_arg;
    CY_UNUSED_PARAMETER(event);
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->async_ctx);
    mtb_async_transfer_process_dma_complete(obj->async_ctx, MTB_ASYNC_TRANSFER_DIRECTION_READ);
}


/** TX DMA transfer complete event callback */
void _mtb_hal_uart_tx_dma_event_callback(void* callback_arg, mtb_hal_dma_event_t event)
{
    mtb_hal_uart_t* obj = (mtb_hal_uart_t*)callback_arg;
    CY_UNUSED_PARAMETER(event);
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->async_ctx);
    mtb_async_transfer_process_dma_complete(obj->async_ctx, MTB_ASYNC_TRANSFER_DIRECTION_WRITE);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart_dma_set_src_addr
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_uart_dma_set_src_addr(void* dma_ref, void* addr)
{
    return mtb_hal_dma_set_src_addr((mtb_hal_dma_t*)dma_ref, (uint32_t)addr);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart_dma_set_dst_addr
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_uart_dma_set_dst_addr(void* dma_ref, void* addr)
{
    return mtb_hal_dma_set_dst_addr((mtb_hal_dma_t*)dma_ref, (uint32_t)addr);
}


#endif // (MTB_HAL_DRIVER_AVAILABLE_DMA)
#endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

/*******************************************************************************
*                        Public Function Definitions
*******************************************************************************/
/** Initialize the UART Object */
cy_rslt_t mtb_hal_uart_setup(mtb_hal_uart_t* obj, const mtb_hal_uart_configurator_t* cfg,
                             cy_stc_scb_uart_context_t* context, const mtb_hal_clock_t* clock)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != cfg);
    CY_ASSERT(NULL != context);
    CY_ASSERT(NULL != cfg->base);

    memset(obj, 0, sizeof(mtb_hal_uart_t));
    obj->base    = cfg->base;
    obj->clock   = (clock == NULL) ? cfg->clock : clock;
    obj->context = context;
    if (cfg->tx_port != 0xFF)
    {
        obj->tx_pin.port = ((GPIO_PRT_Type*)&GPIO->PRT[cfg->tx_port]);
    }
    else
    {
        obj->tx_pin.port = NULL;
    }
    obj->tx_pin.pinNum = cfg->tx_pin;
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    obj->rts_enable = cfg->rts_enable;
    if (cfg->rts_port != 0xFF)
    {
        obj->rts_pin.port = ((GPIO_PRT_Type*)&GPIO->PRT[cfg->rts_port]);
    }
    else
    {
        obj->rts_pin.port = NULL;
    }
    obj->rts_pin.pinNum = cfg->rts_pin;
    #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)
    obj->irq_cause = MTB_HAL_UART_IRQ_NONE;
    return CY_RSLT_SUCCESS;
}


/** Configure the baud rate */
cy_rslt_t mtb_hal_uart_set_baud(mtb_hal_uart_t* obj, uint32_t baudrate, uint32_t* actualbaud)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    CY_ASSERT(NULL != obj->clock->interface->get_frequency_hz);
    CY_ASSERT(NULL != obj->clock->interface->set_frequency_hz);

    cy_rslt_t result;
    uint32_t  original_freq;
    uint32_t  desired_freq;
    uint32_t  actual_freq;
    uint32_t  tolerance;
    uint32_t  oversample;
    en_hsiom_sel_t  tx_hsiom = (en_hsiom_sel_t)0U;
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    en_hsiom_sel_t  rts_hsiom = (en_hsiom_sel_t)0U;
    #endif

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN((!_mtb_hal_uart_is_busy(obj)), MTB_HAL_UART_RSLT_ERR_BUSY);
    #else
    if (_mtb_hal_uart_is_busy(obj))
    {
        return MTB_HAL_UART_RSLT_ERR_BUSY;
    }
    #endif

    // The output pins need to be set to high before going to deepsleep.
    // Otherwise the UART on the other side would see incoming data as '0'.
    if (NULL != obj->tx_pin.port)
    {
        tx_hsiom = Cy_GPIO_GetHSIOM(obj->tx_pin.port, obj->tx_pin.pinNum);
        Cy_GPIO_Set(obj->tx_pin.port, obj->tx_pin.pinNum);
        Cy_GPIO_SetHSIOM(obj->tx_pin.port, obj->tx_pin.pinNum, HSIOM_SEL_GPIO);
    }
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    if (NULL != obj->rts_pin.port)
    {
        rts_hsiom = Cy_GPIO_GetHSIOM(obj->rts_pin.port, obj->rts_pin.pinNum);
        Cy_GPIO_Set(obj->rts_pin.port, obj->rts_pin.pinNum);
        Cy_GPIO_SetHSIOM(obj->rts_pin.port, obj->rts_pin.pinNum, HSIOM_SEL_GPIO);
    }
    #endif

    Cy_SCB_UART_Disable(obj->base, NULL);

    original_freq = obj->clock->interface->get_frequency_hz(obj->clock->clock_ref);
    oversample = Cy_SCB_UART_GetOverSample(obj->base); /* User-controlled oversample value */
    desired_freq =  baudrate * oversample;

    /* Check if the baudrate is achievable */
    result = obj->clock->interface->set_frequency_hz(obj->clock->clock_ref, desired_freq,
                                                     MTB_HAL_UART_CLOCK_FREQ_MAX_TOLERANCE_PPM);

    if (result == CY_RSLT_SUCCESS)
    {
        actual_freq = obj->clock->interface->get_frequency_hz(obj->clock->clock_ref);
        tolerance   =
            (uint32_t)abs(_mtb_hal_utils_calculate_tolerance(MTB_HAL_TOLERANCE_PPM,
                                                             desired_freq,
                                                             actual_freq));

        if (tolerance > MTB_HAL_UART_CLOCK_FREQ_MAX_TOLERANCE_PPM)
        {
            result = MTB_HAL_UART_RSLT_ERR_CLOCK_FREQ_TOLERANCE;
        }
    }

    if (result != CY_RSLT_SUCCESS)
    {
        /* Revert back to original */
        actual_freq = original_freq;
        obj->clock->interface->set_frequency_hz(obj->clock->clock_ref, original_freq,
                                                MTB_HAL_UART_CLOCK_FREQ_MAX_TOLERANCE_PPM);
    }

    if (actualbaud != NULL)
    {
        *actualbaud = actual_freq/oversample;
    }

    //Restore the pins fuctionality
    if (NULL != obj->tx_pin.port)
    {
        Cy_GPIO_SetHSIOM(obj->tx_pin.port, obj->tx_pin.pinNum, tx_hsiom);
    }
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    if (NULL != obj->rts_pin.port)
    {
        Cy_GPIO_SetHSIOM(obj->rts_pin.port, obj->rts_pin.pinNum, rts_hsiom);
    }
    #endif

    Cy_SCB_UART_Enable(obj->base);
    return result;
}


/** Check the number of bytes available to read from the receive buffers */
uint32_t mtb_hal_uart_readable(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    uint32_t number_available = Cy_SCB_UART_GetNumInRxFifo(obj->base);

    if (obj->context->rxRingBuf != NULL)
    {
        CY_ASSERT(NULL != obj->context);
        number_available += Cy_SCB_UART_GetNumInRingBuffer(obj->base, obj->context);
    }
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    return number_available;
}


/** Check the number of bytes than can be written to the transmit buffer */
uint32_t mtb_hal_uart_writable(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    return Cy_SCB_GetFifoSize(obj->base) - Cy_SCB_GetNumInTxFifo(obj->base);
}


/** Clear the UART buffers */
cy_rslt_t mtb_hal_uart_clear(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    Cy_SCB_UART_ClearRxFifo(obj->base);
    Cy_SCB_UART_ClearTxFifo(obj->base);

    if (obj->context->rxRingBuf != NULL)
    {
        CY_ASSERT(NULL != obj->context);
        Cy_SCB_UART_ClearRingBuffer(obj->base, obj->context);
    }

    return CY_RSLT_SUCCESS;
}


/** Configure the UART CTS for flow control */
cy_rslt_t mtb_hal_uart_enable_cts_flow_control(mtb_hal_uart_t* obj, bool enable)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    enable ? Cy_SCB_UART_EnableCts(obj->base) : Cy_SCB_UART_DisableCts(obj->base);
    return CY_RSLT_SUCCESS;
}


/** Begin synchronous TX transfer. */
cy_rslt_t mtb_hal_uart_write(mtb_hal_uart_t* obj, void* tx, size_t* tx_length)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    CY_ASSERT(NULL != tx);
    CY_ASSERT(NULL != tx_length);
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    /* Return busy if an async write operation is in progress */
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj->async_ctx) && mtb_hal_uart_is_async_tx_available(
                              obj)), MTB_HAL_UART_RSLT_ERR_BUSY);
    #else
    if ((NULL != obj->async_ctx) && (!mtb_hal_uart_is_async_tx_available(obj)))
    {
        return MTB_HAL_UART_RSLT_ERR_BUSY;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

    *tx_length = Cy_SCB_UART_PutArray(obj->base, tx, *tx_length);
    return CY_RSLT_SUCCESS;
}


/** Begin synchronous RX transfer */
cy_rslt_t mtb_hal_uart_read(mtb_hal_uart_t* obj, void* rx, size_t* rx_length)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    CY_ASSERT(NULL != rx);
    CY_ASSERT(NULL != rx_length);

    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    /* Return busy if an async read operation is in progress */
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((NULL != obj->async_ctx) && mtb_hal_uart_is_async_rx_available(
                              obj)), MTB_HAL_UART_RSLT_ERR_BUSY);
    #else
    if ((NULL != obj->async_ctx) && (!mtb_hal_uart_is_async_rx_available(obj)))
    {
        return MTB_HAL_UART_RSLT_ERR_BUSY;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

    *rx_length = Cy_SCB_UART_GetArray(obj->base, rx, *rx_length);
    return CY_RSLT_SUCCESS;
}


/** Determines if the UART peripheral is currently in use for TX */
bool mtb_hal_uart_is_tx_active(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    CY_ASSERT(NULL != obj->context);
    return
        #if defined(COMPONENT_MW_ASYNC_TRANSFER)
        //Calling the mtb_async_transfer_available_write directly (instead of accessing via
        //a function pointer setup only when the async interface is used) as it is simple
        //function and overhead may be comparable to setting up the function pointer option
        ((NULL != obj->async_ctx) && (!mtb_async_transfer_available_write(obj->async_ctx))) ||
        #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)
        (0UL != (obj->context->txStatus & CY_SCB_UART_TRANSMIT_ACTIVE)) || !Cy_SCB_IsTxComplete(
        obj->base);
}


/** Determines if the UART peripheral is currently in use for RX */
bool mtb_hal_uart_is_rx_active(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->context);
    return
        #if defined(COMPONENT_MW_ASYNC_TRANSFER)
        //Calling the mtb_async_transfer_available_read directly (instead of accessing via
        //a function pointer setup only when the async interface is used) as it is simple
        //function and overhead may be comparable to setting up the function pointer option
        ((NULL != obj->async_ctx) && (!mtb_async_transfer_available_read(obj->async_ctx))) ||
        #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)
        (0UL != (obj->context->rxStatus & CY_SCB_UART_RECEIVE_ACTIVE));
}


/** Register a uart callback handler */
void mtb_hal_uart_register_callback(mtb_hal_uart_t* obj, mtb_hal_uart_event_callback_t callback,
                                    void* callback_arg)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    CY_ASSERT(NULL != obj->context);
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    Cy_SCB_UART_RegisterCallback(obj->base, _mtb_hal_uart_cb_wrapper, obj->context);
}


/** Enable or disable specified UART events.*/
void mtb_hal_uart_enable_event(mtb_hal_uart_t* obj, mtb_hal_uart_event_t event, bool enable)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);

    #if defined(HAL_NEXT_TODO)
    #if defined(BCM55500)
    Cy_SCB_DisableInterrupt(obj->base);
    #endif
    #endif //defined(HAL_NEXT_TODO)

    uint32_t tx_mask = 0x0;
    uint32_t rx_mask = 0x0;

    if (event & MTB_HAL_UART_IRQ_TX_EMPTY)
    {
        tx_mask |= CY_SCB_UART_TX_EMPTY;
    }
    if (event & MTB_HAL_UART_IRQ_TX_DONE)
    {
        tx_mask |= CY_SCB_UART_TX_DONE;
    }
    if (event & MTB_HAL_UART_IRQ_TX_ERROR)
    {
        // Omit underflow condition as the interrupt perpetually triggers
        //Standard mode only uses OVERFLOW irq
        if (_mtb_hal_uart_get_mode(obj->base) == CY_SCB_UART_STANDARD)
        {
            tx_mask |= (CY_SCB_UART_TX_OVERFLOW | CY_SCB_UART_TRANSMIT_ERR);
        }
        //SMARTCARD mode uses OVERFLOW, NACK, and ARB_LOST irq's
        else if (_mtb_hal_uart_get_mode(obj->base) == CY_SCB_UART_SMARTCARD)
        {
            tx_mask |=
                (CY_SCB_UART_TX_OVERFLOW | CY_SCB_TX_INTR_UART_NACK | CY_SCB_TX_INTR_UART_ARB_LOST |
                 CY_SCB_UART_TRANSMIT_ERR);
        }
        //LIN Mode only uses OVERFLOW, ARB_LOST irq's
        else
        {
            tx_mask |=
                (CY_SCB_UART_TX_OVERFLOW | CY_SCB_TX_INTR_UART_ARB_LOST | CY_SCB_UART_TRANSMIT_ERR);
        }
    }
    if (event & MTB_HAL_UART_IRQ_TX_FIFO)
    {
        tx_mask |= CY_SCB_UART_TX_TRIGGER;
    }

    if (event & MTB_HAL_UART_IRQ_RX_NOT_EMPTY)
    {
        rx_mask |= CY_SCB_UART_RX_NOT_EMPTY;
    }
    if (event & MTB_HAL_UART_IRQ_RX_ERROR)
    {
        // Omit underflow condition as the interrupt perpetually triggers.
        rx_mask |= CY_SCB_UART_RECEIVE_ERR;
    }
    if (event & MTB_HAL_UART_IRQ_RX_FIFO)
    {
        rx_mask |= CY_SCB_UART_RX_TRIGGER;
    }

    if (enable)
    {
        obj->irq_cause |= event;
    }
    else
    {
        obj->irq_cause &= ~event;
    }
    if (event == MTB_HAL_UART_IRQ_NONE)
    {
        /* "No interrupt" is equivalent for both "enable" and "disable" */
        enable = false;
        tx_mask = CY_SCB_TX_INTR_MASK;
        rx_mask = CY_SCB_RX_INTR_MASK;
    }

    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    //Get and modify TX events
    uint32_t current_tx_mask = Cy_SCB_GetTxInterruptMask(obj->base);
    if (enable && tx_mask)
    {
        Cy_SCB_ClearTxInterrupt(obj->base, tx_mask);
    }
    Cy_SCB_SetTxInterruptMask(obj->base,
                              (enable ? (current_tx_mask | tx_mask) : (current_tx_mask &
                                                                       ~tx_mask)));


    //Get and modify RX events
    uint32_t current_rx_mask = Cy_SCB_GetRxInterruptMask(obj->base);

    if (enable && rx_mask)
    {
        Cy_SCB_ClearRxInterrupt(obj->base, rx_mask);
    }
    Cy_SCB_SetRxInterruptMask(obj->base,
                              (enable ? (current_rx_mask | rx_mask) : (current_rx_mask &
                                                                       ~rx_mask)));
    mtb_hal_system_critical_section_exit(savedIntrStatus);

    #if defined(HAL_NEXT_TODO)
    #if defined(BCM55500)
    // The above Cy_SCB_DisableInterrupt also disconnects all the callback functions. They need to
    // be registered again
    Cy_SCB_RegisterInterruptCallback(obj->base, _mtb_hal_irq_cb[_MTB_HAL_SCB_IRQ_N[scb_arr_index]]);
    Cy_SCB_EnableInterrupt(obj->base);
    #endif
    #endif //defined(HAL_NEXT_TODO)
}


/** Process interrupts related related to a UART instance.*/
cy_rslt_t mtb_hal_uart_process_interrupt(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    if (NULL != obj->async_handler)
    {
        CY_ASSERT(NULL != obj->base);
        obj->async_handler(obj);
    }
    #endif
    _mtb_hal_uart_irq_handler(obj);
    return CY_RSLT_SUCCESS;
}


#if defined(COMPONENT_MW_ASYNC_TRANSFER)
/**Configure the UART async transfer interface */
cy_rslt_t mtb_hal_uart_config_async(mtb_hal_uart_t* obj, mtb_async_transfer_context_t* context)
{
    cy_rslt_t result;
    mtb_async_transfer_interface_t interface;
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != context);

    result = _mtb_hal_uart_config_async_common(obj, context, &interface);
    if (CY_RSLT_SUCCESS == result)
    {
        result = mtb_async_transfer_init(context, &interface);
        if (CY_RSLT_SUCCESS == result)
        {
            obj->async_handler = _mtb_hal_uart_async_transfer_handler;
            obj->async_event_callback = _mtb_hal_uart_async_transfer_event_callback;
            result = mtb_async_transfer_register_callback(context, obj->async_event_callback, obj);
        }
    }
    return result;
}


#if (MTB_HAL_DRIVER_AVAILABLE_DMA)
/**Configure the UART async transfer interface */
cy_rslt_t mtb_hal_uart_config_async_dma(mtb_hal_uart_t* obj, mtb_hal_dma_t* dma_rx,
                                        mtb_hal_dma_t* dma_tx,
                                        mtb_async_transfer_context_t* context)
{
    mtb_async_transfer_interface_t interface;
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != context);
    cy_rslt_t result = _mtb_hal_uart_config_async_common(obj, context, &interface);
    if (CY_RSLT_SUCCESS == result)
    {
        interface.dma_rx_ref = dma_rx;
        interface.dma_tx_ref = dma_tx;
        interface.dma_set_length = (mtb_async_transfer_dma_set_len_t)mtb_hal_dma_set_length;
        interface.dma_set_src = _mtb_hal_uart_dma_set_src_addr;
        interface.dma_set_dest = _mtb_hal_uart_dma_set_dst_addr;
        interface.dma_enable_rx = _mtb_hal_uart_async_transfer_enable_dma;
        interface.dma_enable_tx = _mtb_hal_uart_async_transfer_enable_dma;
        if (NULL != dma_rx)
        {
            mtb_hal_dma_register_callback(dma_rx, _mtb_hal_uart_rx_dma_event_callback, obj);
        }
        if (NULL != dma_tx)
        {
            mtb_hal_dma_register_callback(dma_tx, _mtb_hal_uart_tx_dma_event_callback, obj);
        }
        result = mtb_async_transfer_init(context, &interface);
        if (CY_RSLT_SUCCESS == result)
        {
            obj->async_handler = _mtb_hal_uart_async_transfer_handler;
            obj->async_event_callback = _mtb_hal_uart_async_transfer_event_callback;
            result = mtb_async_transfer_register_callback(context, obj->async_event_callback, obj);
        }
    }
    return result;
}


#endif /* (MTB_HAL_DRIVER_AVAILABLE_DMA) */


/** Note: Before calling any of the below  functions, either mtb_hal_uart_config_async or
   mtb_hal_uart_config_async_dma must have been called.*/

/** Begin asynchronous RX transfer. */
cy_rslt_t mtb_hal_uart_read_async(mtb_hal_uart_t* obj, void* rx, size_t length)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != rx);
    CY_ASSERT(NULL != obj->async_ctx);
    return mtb_async_transfer_read(obj->async_ctx, rx, length);
}


/** Begin asynchronous TX transfer.*/
cy_rslt_t mtb_hal_uart_write_async(mtb_hal_uart_t* obj, void* tx, size_t length)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != tx);
    CY_ASSERT(NULL != obj->async_ctx);

    return mtb_async_transfer_write(obj->async_ctx, tx, length);
}


/** Checks whether the UART interface is available to start a write transfer */
bool mtb_hal_uart_is_async_tx_available(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->async_ctx);
    return mtb_async_transfer_available_write(obj->async_ctx);
}


/** Checks whether the UART interface is available to start a read transfer */
bool mtb_hal_uart_is_async_rx_available(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->async_ctx);
    return mtb_async_transfer_available_read(obj->async_ctx);
}


/** Abort the ongoing read transaction.*/
cy_rslt_t mtb_hal_uart_read_abort(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    cy_rslt_t result = CY_RSLT_SUCCESS;

    /* Abort the async read transfer */
    if (NULL != obj->async_ctx)
    {
        result = mtb_async_transfer_abort_read(obj->async_ctx);
    }
    /* Clear the RX FIFO */
    Cy_SCB_UART_ClearRxFifo(obj->base);
    return result;
}


/** Abort the ongoing write transaction. */
cy_rslt_t mtb_hal_uart_write_abort(mtb_hal_uart_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    cy_rslt_t result = CY_RSLT_SUCCESS;

    /* Abort the async write transfer */
    if (NULL != obj->async_ctx)
    {
        result = mtb_async_transfer_abort_write(obj->async_ctx);
    }
    /* Clear the TX FIFO */
    Cy_SCB_UART_ClearTxFifo(obj->base);
    return result;
}


#endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

#if defined(__cplusplus)
}
#endif

#endif /* MTB_HAL_DRIVER_AVAILABLE_UART */
