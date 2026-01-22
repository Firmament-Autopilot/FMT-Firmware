/***************************************************************************//**
* \file mtb_hal_spi.c
*
* \brief
* Provides a high level interface for interacting with the Infineon SPI. This is
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

/**
 * \addtogroup group_hal_impl_spi SPI (Serial Peripheral Interface)
 * \ingroup group_hal_impl
 * \{
 * \section section_hal_impl_spi_init_cfg Configurator-generated features limitations
 * List of SPI personality items, which are currently not supported in SPI HAL driver:
 *  - Modes: TI (Start Coincides), TI (Start Precedes), National Semiconductor (Microwire)
 *  - Low-level RX Interrupt sources
 *  - Low-level TX Interrupt sources
 *  - SPI Done Controller interrupt source
 *  - Different data width for RX and TX
 *
 * \section section_hal_impl_spi_data_width Supported transfer data width options
 * Next transfer data width options are supported by next devices:
 *  - Devices with MXSCB block version 2 and further (value of CY_IP_MXSCB_VERSION) support
 * next data width range: 4 - 32 (included) with step 1
 *  - Devices with MXSCB block version 1 (value of CY_IP_MXSCB_VERSION) support next data width
 * range: 4 - 16 (included) with step 1
 *  - Devices support next data width range : 4-16 (included) with step 1
 *
 *  \section section_hal_impl_spi_controller_ss SPI controller SS pin configured in GPIO mode
 * SPI controller Target Select pins are configured in GPIO mode to support asymmetric data
 * transfers. Therefore these pins are not restricted to direct connections to the SPI hardware
 *
 * \} group_hal_impl_spi
 */

#include <stdlib.h>
#include <string.h>
#include "mtb_hal_hw_types.h"
#include "mtb_hal_spi.h"
#include "mtb_hal_system_impl.h"
#include "mtb_hal_utils.h"

#if (MTB_HAL_DRIVER_AVAILABLE_SPI)

#if defined(__cplusplus)
extern "C"
{
#endif

#define _MTB_HAL_SPI_WAIT_OP_RD_BUSY          1
#define _MTB_HAL_SPI_WAIT_OP_RD_NOT_BUSY      2
#define _MTB_HAL_SPI_WAIT_OP_WR               3
#define _MTB_HAL_SPI_WAIT_OP_VALID(op)        ((op) > 0 && (op) <= _MTB_HAL_SPI_WAIT_OP_WR)

/** The maximum allowable tolerance in PPM on the SPI clock frequency **/
#define MTB_HAL_SPI_CLOCK_FREQ_MAX_TOLERANCE_PPM (20000UL)
#define MTB_HAL_SPI_US_IN_MS                     (1000UL)
/*******************************************************************************
*       internal Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_spi_readable
//--------------------------------------------------------------------------------------------------
static uint32_t _mtb_hal_spi_readable(mtb_hal_spi_t* obj)
{
    return Cy_SCB_SPI_GetNumInRxFifo(obj->base);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_spi_writable
//--------------------------------------------------------------------------------------------------
static uint32_t _mtb_hal_spi_writable(mtb_hal_spi_t* obj)
{
    return Cy_SCB_GetFifoSize(obj->base) - Cy_SCB_SPI_GetNumInTxFifo(obj->base);
}


/* Check SPI is busy or readable depends on op status */
static bool _mtb_hal_check_spi_status(void* obj, uint32_t op)
{
    CY_ASSERT(_MTB_HAL_SPI_WAIT_OP_VALID(op)); // Wait Operation
    bool op_condition = true;
    mtb_hal_spi_t* _obj = (mtb_hal_spi_t*)obj;

    switch (op)
    {
        case _MTB_HAL_SPI_WAIT_OP_RD_BUSY:
            op_condition =
                (false == (_mtb_hal_spi_readable(_obj) != 0 && !mtb_hal_spi_is_busy(_obj)));
            break;

        case _MTB_HAL_SPI_WAIT_OP_RD_NOT_BUSY:
            op_condition =
                (false == (_mtb_hal_spi_readable(_obj) != 0 || mtb_hal_spi_is_busy(_obj)));
            break;

        case _MTB_HAL_SPI_WAIT_OP_WR:
            op_condition =
                ((_mtb_hal_spi_writable(_obj) < Cy_SCB_GetFifoSize(_obj->base)) ||
                 mtb_hal_spi_is_busy(_obj) || !Cy_SCB_IsTxComplete(_obj->base));
            break;

        default:
            op_condition = false;
            break;
    }
    return op_condition;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_spi_put_get
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_spi_put_get(mtb_hal_spi_t* obj, uint32_t fill, bool put)
{
    if (NULL == obj)
    {
        return MTB_HAL_SPI_RSLT_BAD_ARGUMENT;
    }

    CY_ASSERT(obj != NULL);

    uint32_t count = 0;

    if (!obj->is_target)
    {
        mtb_hal_spi_clear(obj);
    }

    if (put || !obj->is_target)
    {
        while (count == 0)
        {
            count = Cy_SCB_SPI_Write(obj->base, fill);
        }
    }

    if (!obj->is_target)
    {
        while (Cy_SCB_SPI_IsTxComplete(obj->base) == false)
        {
        }
        while (Cy_SCB_SPI_GetNumInRxFifo(obj->base) == 0) /* Wait for RX FIFO not empty */
        {
        }
    }

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_spi_transfer_async
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_spi_transfer_async(mtb_hal_spi_t* obj, const uint8_t* tx,
                                             size_t tx_length, uint8_t* rx, size_t rx_length)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(obj != NULL, MTB_HAL_SPI_RSLT_BAD_ARGUMENT);
    #else
    if (NULL == obj)
    {
        return MTB_HAL_SPI_RSLT_BAD_ARGUMENT;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    cy_en_scb_spi_status_t spi_status = CY_SCB_SPI_SUCCESS;

    obj->is_async = true;

    uint8_t arr_size_modifier = 0;
    if (obj->data_bits <= 8)
    {
        arr_size_modifier = 1;
    }
    else if (obj->data_bits <= 16)
    {
        arr_size_modifier = 2;
    }
    else
    {
        arr_size_modifier = 4;
    }

    if ((tx_length % arr_size_modifier != 0) || (rx_length % arr_size_modifier != 0))
    {
        return MTB_HAL_SPI_RSLT_BAD_ARGUMENT;
    }

    size_t tx_words = tx_length / arr_size_modifier;
    size_t rx_words = rx_length / arr_size_modifier;

    /* Setup transfer */
    obj->rx_buffer = NULL;
    obj->tx_buffer = NULL;

    CY_UNUSED_PARAMETER(arr_size_modifier);
    if (tx_words != rx_words)
    {
        if (tx_words == 0)
        {
            obj->pending = _MTB_HAL_SPI_PENDING_RX;
            tx = NULL;
        }
        else if (rx_words == 0)
        {
            obj->pending = _MTB_HAL_SPI_PENDING_TX;
            rx = NULL;
        }
        else
        {
            obj->pending = _MTB_HAL_SPI_PENDING_TX_RX;
        }
        spi_status = Cy_SCB_SPI_Transfer_Buffer(obj->base, (void*)tx, (void*)rx, tx_words, rx_words,
                                                obj->write_fill, obj->context);
    }
    else
    {
        obj->pending = _MTB_HAL_SPI_PENDING_TX_RX;
        spi_status = Cy_SCB_SPI_Transfer(obj->base, (void*)tx, rx, tx_words, obj->context);
    }

    return spi_status == CY_SCB_SPI_SUCCESS
        ? CY_RSLT_SUCCESS
        : MTB_HAL_SPI_RSLT_TRANSFER_ERROR;
}


/*******************************************************************************
*       External Functions
*******************************************************************************/
static volatile mtb_hal_spi_t* _mtb_hal_spi_irq_obj = NULL;

//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_setup(mtb_hal_spi_t* obj, const mtb_hal_spi_configurator_t* config,
                            cy_stc_scb_spi_context_t* context, const mtb_hal_clock_t* clock)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != config);
    memset(obj, 0, sizeof(mtb_hal_spi_t));

    obj->base = config->base;
    obj->clock = (clock == NULL) ? config->clock : clock;
    obj->context = context;
    obj->is_target = (bool)!config->config->spiMode;
    obj->data_bits = config->config->txDataWidth;
    obj->irq_cause = MTB_HAL_SPI_EVENT_NONE;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_set_frequency
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_set_frequency(mtb_hal_spi_t* obj, uint32_t hz)
{
    CY_ASSERT(NULL != obj);
    cy_rslt_t result = CY_RSLT_SUCCESS;
    Cy_SCB_SPI_Disable(obj->base, obj->context);

    if (!obj->is_target)
    {
        uint32_t original_freq = obj->clock->interface->get_frequency_hz(obj->clock->clock_ref);
        uint32_t oversample = Cy_SCB_UART_GetOverSample(obj->base); /* User-controlled oversample
                                                                       value */
        uint32_t desired_freq =  hz * oversample;
        result = obj->clock->interface->set_frequency_hz(obj->clock->clock_ref, desired_freq,
                                                         MTB_HAL_SPI_CLOCK_FREQ_MAX_TOLERANCE_PPM);

        if (result == CY_RSLT_SUCCESS)
        {
            uint32_t actual_freq = obj->clock->interface->get_frequency_hz(obj->clock->clock_ref);
            uint32_t tolerance   =
                (uint32_t)abs(_mtb_hal_utils_calculate_tolerance(MTB_HAL_TOLERANCE_PPM,
                                                                 desired_freq,
                                                                 actual_freq));

            if (tolerance > MTB_HAL_SPI_CLOCK_FREQ_MAX_TOLERANCE_PPM)
            {
                result = MTB_HAL_SPI_RSLT_CLOCK_ERROR;
            }
        }

        if (result != CY_RSLT_SUCCESS)
        {
            /* Revert back to original */
            obj->clock->interface->set_frequency_hz(obj->clock->clock_ref, original_freq,
                                                    MTB_HAL_SPI_CLOCK_FREQ_MAX_TOLERANCE_PPM);
        }
    }
    else
    {
        uint32_t peri_freq = mtb_hal_clock_get_peri_src_clock_freq(obj->clock->clock_ref);

        /* Target requires such frequency:
         * required_frequency = N / ((0.5 * desired_period) – 20 nsec - tDSI,
         *   N is 3 when "Enable Input Glitch Filter" is false and 4 when true.
         *   tDSI Is external controller delay which is assumed to be 16.66 nsec */

        /* Divided by 2 desired period to avoid dividing in required_frequency formula */
        cy_float32_t desired_period_us_divided = 5e5f * (1 / (cy_float32_t)hz);
        uint32_t required_frequency =
            (uint32_t)(3e6f / (desired_period_us_divided - 36.66f / 1e3f));

        #if defined(MTB_HAL_DISABLE_ERR_CHECK)
        CY_ASSERT_AND_RETURN(!(required_frequency > peri_freq), MTB_HAL_SPI_RSLT_CLOCK_ERROR);
        #else
        if (required_frequency > peri_freq)
        {
            return MTB_HAL_SPI_RSLT_CLOCK_ERROR;
        }
        #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

        /* Note: set clock divider to always be 1 in this mode for BWC */
        result = obj->clock->interface->set_frequency_hz(obj->clock->clock_ref, peri_freq,
                                                         MTB_HAL_SPI_CLOCK_FREQ_MAX_TOLERANCE_PPM);
    }
    Cy_SCB_SPI_Enable(obj->base);

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_get
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_get(mtb_hal_spi_t* obj, uint32_t* value)
{
    uint32_t read_value = CY_SCB_SPI_RX_NO_DATA;

    cy_rslt_t result = _mtb_hal_spi_put_get(obj, CY_SCB_SPI_RX_NO_DATA, false);
    if (result == CY_RSLT_SUCCESS)
    {
        while (read_value == CY_SCB_SPI_RX_NO_DATA)
        {
            read_value = Cy_SCB_SPI_Read(obj->base);
        }
        *value = read_value;
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_put
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_put(mtb_hal_spi_t* obj, uint32_t value)
{
    return _mtb_hal_spi_put_get(obj, value, true);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_target_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_target_read(mtb_hal_spi_t* obj, uint8_t* dst_buff, uint16_t* size,
                                  uint32_t timeout)
{
    cy_rslt_t status = MTB_HAL_SPI_RSLT_BAD_ARGUMENT;

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((dst_buff != NULL) && (size != NULL)), MTB_HAL_SPI_RSLT_BAD_ARGUMENT);
    #else
    if ((dst_buff != NULL) && (size != NULL))
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        // In case controller completed SPI transcation before this API is called.
        bool transfer_start = Cy_SCB_SPI_GetNumInRxFifo(obj->base);

        uint32_t i = 0U;
        uint16_t size_remaining = *size;
        do
        {
            if (mtb_hal_spi_is_busy(obj))
            {
                transfer_start = true;
            }
            else if (transfer_start)
            {
                if ((Cy_SCB_SPI_GetNumInRxFifo(obj->base) == 0U) && (!mtb_hal_spi_is_busy(obj)))
                {
                    //Stop receiving while line is no longer active
                    transfer_start = false;
                }
            }
            if ((Cy_SCB_SPI_GetNumInRxFifo(obj->base) > 0U) && (transfer_start == true))
            {
                size_remaining -=
                    (uint16_t)Cy_SCB_SPI_ReadArray(obj->base,
                                                   (void*)&dst_buff[*size - size_remaining],
                                                   size_remaining);
            }
            // If all expected data is received - exit the loop
            if (size_remaining == 0U)
            {
                break;
            }
            mtb_hal_system_delay_us(1U);
            i++;
        } while(i < (timeout * MTB_HAL_SPI_US_IN_MS));


        if ((i != (timeout * MTB_HAL_SPI_US_IN_MS)) || (size_remaining == 0U))
        {
            status = CY_RSLT_SUCCESS;
        }
        *size = (*size - size_remaining);
    }

    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_controller_write
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_controller_write(mtb_hal_spi_t* obj, const uint8_t* src_buff, uint16_t* size)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((src_buff != NULL) && (size != NULL)), MTB_HAL_SPI_RSLT_BAD_ARGUMENT);
    #else
    if ((src_buff != NULL) && (size != NULL))
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        *size = Cy_SCB_SPI_WriteArray(obj->base, (void*)src_buff, *size);
        return CY_RSLT_SUCCESS;
    }
    #if !defined(MTB_HAL_DISABLE_ERR_CHECK)
    return MTB_HAL_SPI_RSLT_BAD_ARGUMENT;
    #endif // !defined(MTB_HAL_DISABLE_ERR_CHECK)
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_target_write
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_target_write(mtb_hal_spi_t* obj, const uint8_t* src_buff, uint16_t* size,
                                   uint32_t timeout)
{
    cy_rslt_t status = MTB_HAL_SPI_RSLT_BAD_ARGUMENT;

    if ((src_buff != NULL) && (size != NULL))
    {
        status = _mtb_hal_spi_transfer_async(obj, src_buff, (size_t)*size, NULL, 0U);

        if (CY_RSLT_SUCCESS == status)
        {
            /* Wait until the target finish writing */
            status = _mtb_hal_wait_for_status(obj, _MTB_HAL_SPI_WAIT_OP_WR, &timeout,
                                              _mtb_hal_check_spi_status);
        }
    }

    if (CY_RSLT_SUCCESS != status)
    {
        Cy_SCB_SPI_AbortTransfer(obj->base, (obj->context));
        obj->pending = _MTB_HAL_SPI_PENDING_NONE;
    }

    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_transfer
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_transfer(mtb_hal_spi_t* obj, const uint8_t* tx, size_t tx_length, uint8_t* rx,
                               size_t rx_length, uint8_t write_fill)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(obj != NULL, MTB_HAL_SPI_RSLT_BAD_ARGUMENT);
    #else
    if (NULL == obj)
    {
        return MTB_HAL_SPI_RSLT_BAD_ARGUMENT;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    obj->write_fill = write_fill;
    cy_rslt_t rslt = _mtb_hal_spi_transfer_async(obj, tx, tx_length, rx, rx_length);
    if (rslt == CY_RSLT_SUCCESS)
    {
        while (obj->pending != _MTB_HAL_SPI_PENDING_NONE)
        {
        }                                                     /* Wait for async transfer to complete
                                                               */
    }
    obj->write_fill = (uint8_t)CY_SCB_SPI_DEFAULT_TX;

    return rslt;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_clear
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_clear(mtb_hal_spi_t* obj)
{
    Cy_SCB_SPI_ClearRxFifo(obj->base);
    Cy_SCB_SPI_ClearTxFifo(obj->base);

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_spi_enable_event(mtb_hal_spi_t* obj, mtb_hal_spi_event_t event, bool enable)
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
// _mtb_hal_spi_cb_wrapper
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_spi_cb_wrapper(uint32_t event)
{
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in
       here, they
     * just might change where the original pointer points */
    mtb_hal_spi_t* obj = (mtb_hal_spi_t*)_mtb_hal_spi_irq_obj;
    mtb_hal_spi_event_t anded_events = (mtb_hal_spi_event_t)(obj->irq_cause & ((uint32_t)event));

    // Don't call the callback until the final transfer has put everything in the FIFO/completed
    if ((anded_events & (MTB_HAL_SPI_IRQ_DATA_IN_FIFO | MTB_HAL_SPI_IRQ_DONE)) &&
        !((obj->rx_buffer == NULL) && (obj->tx_buffer == NULL)))
    {
        return;
    }

    if (anded_events)
    {
        mtb_hal_spi_event_callback_t callback =
            (mtb_hal_spi_event_callback_t)obj->callback_data.callback;
        callback(obj->callback_data.callback_arg, anded_events);
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_spi_register_callback(mtb_hal_spi_t* obj, mtb_hal_spi_event_callback_t callback,
                                   void* callback_arg)
{
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    Cy_SCB_SPI_RegisterCallback(obj->base, _mtb_hal_spi_cb_wrapper, obj->context);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_process_interrupt(mtb_hal_spi_t* spi)
{
    /* Save the old value and store it aftewards in case we get into a nested IRQ situation */
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in
       here, they
     * just might change where the original pointer points */
    mtb_hal_spi_t* old_irq_obj = (mtb_hal_spi_t*)_mtb_hal_spi_irq_obj;

    if (NULL == spi)
    {
        return MTB_HAL_SPI_RSLT_BAD_ARGUMENT;  /* The interrupt object is not valid */
    }

    _mtb_hal_spi_irq_obj = spi;

    Cy_SCB_SPI_Interrupt(spi->base, (spi->context));

    if (spi->is_async)
    {
        if (0 ==
            (Cy_SCB_SPI_GetTransferStatus(spi->base, spi->context) & CY_SCB_SPI_TRANSFER_ACTIVE))
        {
            /* Finish Async Transfer */
            spi->pending = _MTB_HAL_SPI_PENDING_NONE;
            spi->is_async = false;
        }
    }

    _mtb_hal_spi_irq_obj = old_irq_obj;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_target_read_transaction
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_spi_target_read_transaction(mtb_hal_spi_t* obj, uint8_t* dst_buff, uint16_t* size,
                                              uint32_t timeout)
{
    cy_rslt_t status = MTB_HAL_SPI_RSLT_BAD_ARGUMENT;

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((dst_buff != NULL) && (size != NULL)), MTB_HAL_SPI_RSLT_BAD_ARGUMENT);
    #else
    if ((dst_buff != NULL) && (size != NULL))
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        /* Wait until the controller start writing or any data will be in the target RX buffer */
        status = _mtb_hal_wait_for_status(obj, _MTB_HAL_SPI_WAIT_OP_RD_NOT_BUSY, &timeout,
                                          _mtb_hal_check_spi_status);

        if (CY_RSLT_SUCCESS != status)
        {
            return status;
        }

        // In case controller completed SPI transcation before this API is called.
        bool transfer_start = Cy_SCB_SPI_GetNumInRxFifo(obj->base);
        bool exit_loop = false;

        uint32_t i = 0U;
        uint16_t size_remaining = *size;
        do
        {
            if (mtb_hal_spi_is_busy(obj))
            {
                transfer_start = true;
            }
            else if (transfer_start)
            {
                if ((Cy_SCB_SPI_GetNumInRxFifo(obj->base) == 0U) && (!mtb_hal_spi_is_busy(obj)))
                {
                    transfer_start = false;
                }
                if (!mtb_hal_spi_is_busy(obj))
                {
                    exit_loop = true;
                }
            }
            if ((Cy_SCB_SPI_GetNumInRxFifo(obj->base) > 0U) && (transfer_start == true))
            {
                size_remaining -=
                    (uint16_t)Cy_SCB_SPI_ReadArray(obj->base,
                                                   (void*)&dst_buff[*size - size_remaining],
                                                   size_remaining);
            }
            mtb_hal_system_delay_us(1U);
            i++;
            // If all expected data is received, timeout reached or line is inacyive - exit the loop
        } while((i < (timeout * MTB_HAL_SPI_US_IN_MS)) && (size_remaining > 0U) &&
                (exit_loop == false));


        if ((i != (timeout * MTB_HAL_SPI_US_IN_MS)) || (size_remaining == 0U))
        {
            status = CY_RSLT_SUCCESS;
        }
        *size = (*size - size_remaining);
    }

    return status;
}


#if defined(__cplusplus)
}
#endif

#endif /* MTB_HAL_DRIVER_AVAILABLE_SPI */
