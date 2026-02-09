/*******************************************************************************
* File Name: mtb_hal_i2c.c
*
* Description:
* Provides a high level interface for interacting with the Infineon I2C. This is
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
#include "mtb_hal_i2c.h"
#include "mtb_hal_system.h"
#include "mtb_hal_utils.h"

#if   defined(CY_IP_MXSCB) && (CY_IP_MXSCB_VERSION == 1)
#include "mtb_hal_i2c_mxs22scb_v1.h"
#elif defined(CY_IP_MXSCB) && (CY_IP_MXSCB_VERSION == 2)
#include "mtb_hal_i2c_mxscb_ver2_s40e_v2.h"
#elif defined(CY_IP_MXSCB) && (CY_IP_MXSCB_VERSION == 3)
#include "mtb_hal_i2c_mxscb_v3.h"
#elif defined(CY_IP_MXSCB) && (CY_IP_MXSCB_VERSION == 4)
#include "mtb_hal_i2c_mxscb_v4.h"
#elif defined (CY_IP_MXS22SCB) && (CY_IP_MXS22SCB_VERSION == 1)
#include "mtb_hal_i2c_mxs22scb_v1.h"
#endif

#if (MTB_HAL_DRIVER_AVAILABLE_I2C)

#if defined(__cplusplus)
extern "C"
{
#endif

/* Peripheral clock values for different I2C speeds according PDL API Reference Guide */
#if defined(CY_DEVICE_SERIES_PSOCE84)
/* Must be between 1.55 MHz and 12.8 MHz for running i2c controller at 100KHz   */
#define _MTB_HAL_SCB_PERI_CLOCK_TARGET_STD      6000000
/* Must be between 7.82 MHz and 15.38 MHz for running i2c controller at 400KHz  */
#define _MTB_HAL_SCB_PERI_CLOCK_TARGET_FST      12000000
#else
/* Must be between 1.55 MHz and 12.8 MHz for running i2c controller at 100KHz   */
#define _MTB_HAL_SCB_PERI_CLOCK_TARGET_STD      8000000
/* Must be between 7.82 MHz and 15.38 MHz for running i2c controller at 400KHz  */
#define _MTB_HAL_SCB_PERI_CLOCK_TARGET_FST      12500000
#endif /* defined(CY_DEVICE_SERIES_PSOCE84) */


/* Must be between 15.84 MHz and 89.0 MHz for running i2c controller at 1MHz */
#if defined(CY_IP_S8SRSSLT) || defined(CY_IP_M0S8SRSSHV)
#define _MTB_HAL_SCB_PERI_CLOCK_TARGET_FSTP     24000000
#elif defined(BCM55500)
#define _MTB_HAL_SCB_PERI_CLOCK_TARGET_FSTP     48000000
#else
#define _MTB_HAL_SCB_PERI_CLOCK_TARGET_FSTP     50000000
#endif

/* Must be between 1.55 MHz and 3.2 MHz for running i2c target at 100KHz */
#define _MTB_HAL_SCB_PERI_CLOCK_CONTROLLER_STD     2000000
/* Must be between 7.82 MHz and 10 MHz for running i2c target at 400KHz  */
#define _MTB_HAL_SCB_PERI_CLOCK_CONTROLLER_FST     8500000
/* Must be between 14.32 MHz and 25.8 MHz for running i2c target at 1MHz */
#define _MTB_HAL_SCB_PERI_CLOCK_CONTROLLER_FSTP    20000000

/* Introduce a tolerance limitation of 5% to ensure that the final clock is near enough to the
   target frequency. This is not a limitation that is required per the I2C standard */
#define _MTB_HAL_I2C_CLK_DIV_TOLERANCE_PPM        (50000)

static const _mtb_hal_buffer_info_t _mtb_hal_i2c_buff_info_default =
{
    .addr = { NULL },
    .size = 0,
};

/* Keep track of the current I2C object to ensure we are referencing the
 * correct one, as we don't directly pass the object through the PDL callback
 * indirection.  This also protects against a nested callback situation. */
static volatile mtb_hal_i2c_t* _mtb_hal_i2c_irq_obj = NULL;

//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_process_interrupt(mtb_hal_i2c_t* obj)
{
    /* Save the old value and store it aftewards in case we get into a nested IRQ situation */
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in
     * here, they just might change where the original pointer points */
    mtb_hal_i2c_t* old_irq_obj = (mtb_hal_i2c_t*)_mtb_hal_i2c_irq_obj;

    if (NULL == obj)
    {
        return MTB_HAL_I2C_RSLT_ERR_BAD_ARGUMENT;  /* The interrupt object is not valid */
    }

    _mtb_hal_i2c_irq_obj = obj;
    Cy_SCB_I2C_Interrupt(obj->base, obj->context);
    _mtb_hal_i2c_irq_obj = old_irq_obj;

    #if defined(BCM55500)
    Cy_SCB_EnableInterrupt(obj->base);
    #endif /* defined(BCM55500) */

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_i2c_cb_wrapper
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_i2c_cb_wrapper(uint32_t event)
{
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in
       here, they just might change where the original pointer points */
    mtb_hal_i2c_t* obj = (mtb_hal_i2c_t*)_mtb_hal_i2c_irq_obj;
    if ((mtb_hal_i2c_event_t)(obj->irq_cause & event))
    {
        /* Indicates read/write operations will be in a callback */
        obj->op_in_callback = true;
        mtb_hal_i2c_event_callback_t callback =
            (mtb_hal_i2c_event_callback_t)obj->callback_data.callback;
        CY_ASSERT(callback != NULL);
        callback(obj->callback_data.callback_arg, (mtb_hal_i2c_event_t)(obj->irq_cause & event));
        obj->op_in_callback = false;
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_i2c_cb_addr_wrapper
//--------------------------------------------------------------------------------------------------
static cy_en_scb_i2c_command_t _mtb_hal_i2c_cb_addr_wrapper(uint32_t event)
{
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in
       here, they just might change where the original pointer points */
    mtb_hal_i2c_t* obj = (mtb_hal_i2c_t*)_mtb_hal_i2c_irq_obj;
    mtb_hal_i2c_addr_event_t addr_events =
        (mtb_hal_i2c_addr_event_t)(obj->addr_irq_cause & event);
    uint8_t device_address = 0;
    /* The default command is the ACK address. It can be overridden in an address callback */
    mtb_hal_i2c_command_rsp_t cmd = MTB_HAL_I2C_CMD_ACK;
    if (addr_events)
    {
        /* If ADDR_IN_FIFO_EVENT received, HAL need to read the device address using
           Cy_SCB_ReadRxFifo API as per I2C PDL documentation */
        if (0L != (MTB_HAL_I2C_ADDR_MATCH_EVENT & addr_events))
        {
            device_address = (Cy_SCB_ReadRxFifo(obj->base));
        }
        /* Indicates read/write operations will be in a callback */
        obj->op_in_callback = true;
        mtb_hal_i2c_address_callback_t callback =
            (mtb_hal_i2c_address_callback_t)obj->addr_callback_data.callback;
        CY_ASSERT(callback != NULL);
        cmd = callback(obj->addr_callback_data.callback_arg, addr_events, device_address);
        obj->op_in_callback = false;
    }
    return (cy_en_scb_i2c_command_t)cmd;
}


#if ((CY_IP_MXSCB_VERSION >= 4) && (CY_IP_MXSCB_VERSION_MINOR >= 4))
//--------------------------------------------------------------------------------------------------
// _mtb_hal_i2c_cb_byte_wrapper
//--------------------------------------------------------------------------------------------------
static cy_en_scb_i2c_command_t _mtb_hal_i2c_cb_byte_wrapper(uint8_t byte_received)
{
    mtb_hal_i2c_t* obj = (mtb_hal_i2c_t*)_mtb_hal_i2c_irq_obj;
    obj->op_in_callback = true;
    mtb_hal_i2c_byte_callback_t callback =
        (mtb_hal_i2c_byte_callback_t)obj->byte_callback_data.callback;
    mtb_hal_i2c_command_rsp_t cmd = callback(obj->byte_callback_data.callback_arg, byte_received);
    obj->op_in_callback = false;
    return (cy_en_scb_i2c_command_t)cmd;
}


#endif /* ((CY_IP_MXSCB_VERSION>=4) && (CY_IP_MXSCB_VERSION_MINOR>=4)) */

//--------------------------------------------------------------------------------------------------
// _mtb_hal_i2c_target_status
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE uint32_t _mtb_hal_i2c_target_status(mtb_hal_i2c_t* obj)
{
    return Cy_SCB_I2C_SlaveGetStatus(obj->base, obj->context);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_i2c_target_clear_write_status
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_i2c_target_clear_write_status(mtb_hal_i2c_t* obj)
{
    (void)Cy_SCB_I2C_SlaveClearWriteStatus(obj->base, obj->context);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_i2c_target_clear_read_status
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_i2c_target_clear_read_status(mtb_hal_i2c_t* obj)
{
    (void)Cy_SCB_I2C_SlaveClearReadStatus(obj->base, obj->context);
}


/* Wait for I2C target status for some time (timeout > 0) or no wait (timeout == 0).
 * The function returns MTB_HAL_I2C_RSLT_WARN_TIMEOUT in case timeout reached, otherwise -
 * CY_RSLT_SUCCESS
 * NOTE: When the read/write operation was called in a I2C callback function timeout is ignored
 */
static cy_rslt_t _mtb_hal_i2c_target_wait_for_status(mtb_hal_i2c_t* obj, uint32_t i2c_status,
                                                     uint32_t timeout)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    uint32_t timeout_us = _MTB_HAL_UTILS_US_PER_MS;

    if (!(obj->op_in_callback) && (timeout > 0))
    {
        while (0U == (_mtb_hal_i2c_target_status(obj) & i2c_status) && timeout > 0)
        {
            if (timeout_us > 0)
            {
                mtb_hal_system_delay_us(_MTB_HAL_UTILS_ONE_TIME_UNIT);
                --timeout_us;
            }
            else
            {
                timeout_us = _MTB_HAL_UTILS_US_PER_MS;
                --timeout;
            }
        }
        result = (timeout > 0) ? CY_RSLT_SUCCESS : MTB_HAL_I2C_RSLT_WARN_TIMEOUT;
    }
    return result;
}


/* Sets the desired clocks & data rate to achieve the specified frequency. Configuration
 * of clock is not changed if driver does not own it
 */
cy_rslt_t _mtb_hal_i2c_set_peri_divider(void* obj, uint32_t freq, bool is_target)
{
    CySCB_Type* base = ((mtb_hal_i2c_t*)obj)->base;
    const mtb_hal_clock_t* clock = (((mtb_hal_i2c_t*)obj)->clock);
    cy_rslt_t result = MTB_HAL_I2C_RSLT_ERR_CAN_NOT_REACH_DR;

    /* Return the actual data rate on success, 0 otherwise */
    uint32_t peri_freq = 0;
    if (freq != 0)
    {
        if (freq <= CY_SCB_I2C_STD_DATA_RATE)
        {
            peri_freq =
                is_target ? _MTB_HAL_SCB_PERI_CLOCK_TARGET_STD :
                _MTB_HAL_SCB_PERI_CLOCK_CONTROLLER_STD;
        }
        else if (freq <= CY_SCB_I2C_FST_DATA_RATE)
        {
            peri_freq =
                is_target ? _MTB_HAL_SCB_PERI_CLOCK_TARGET_FST :
                _MTB_HAL_SCB_PERI_CLOCK_CONTROLLER_FST;
        }
        else if (freq <= CY_SCB_I2C_FSTP_DATA_RATE)
        {
            peri_freq =
                is_target ? _MTB_HAL_SCB_PERI_CLOCK_TARGET_FSTP :
                _MTB_HAL_SCB_PERI_CLOCK_CONTROLLER_FSTP;
        }

        uint32_t data_rate;
        uint32_t original_freq = clock->interface->get_frequency_hz(clock->clock_ref);
        uint32_t original_data_rate = Cy_SCB_I2C_GetDataRate(base, original_freq);
        result = clock->interface->set_frequency_hz(clock->clock_ref, peri_freq,
                                                    _MTB_HAL_I2C_CLK_DIV_TOLERANCE_PPM);

        if (result == CY_RSLT_SUCCESS)
        {
            data_rate = (is_target)
                ? Cy_SCB_I2C_GetDataRate(base, clock->interface->get_frequency_hz(clock->clock_ref))
                : Cy_SCB_I2C_SetDataRate(base, freq, clock->interface->get_frequency_hz(
                                             clock->clock_ref));
            if (data_rate == 0)
            {
                result = MTB_HAL_I2C_RSLT_ERR_CAN_NOT_REACH_DR;
            }
        }

        if (result != CY_RSLT_SUCCESS)
        {
            /* Revert clocks */
            clock->interface->set_frequency_hz(clock->clock_ref, original_freq,
                                               _MTB_HAL_I2C_CLK_DIV_TOLERANCE_PPM);
            if (!is_target)
            {
                Cy_SCB_I2C_SetDataRate(base, original_data_rate, original_freq);
            }
        }
    }
    return result;
}


/* Start API implementing */
cy_rslt_t mtb_hal_i2c_setup(mtb_hal_i2c_t* obj, const mtb_hal_i2c_configurator_t* config,
                            cy_stc_scb_i2c_context_t* context, const mtb_hal_clock_t* clock)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != config);

    obj->base               = config->base;
    obj->context            = context;
    obj->clock              = (clock == NULL) ? config->clock : clock;
    obj->irq_cause          = MTB_HAL_I2C_EVENT_NONE;
    obj->addr_irq_cause     = MTB_HAL_I2C_ADDR_EVENT_NONE;
    obj->op_in_callback     = false;
    obj->config             = config->config;

    obj->rx_target_buff = _mtb_hal_i2c_buff_info_default;
    obj->tx_target_buff = _mtb_hal_i2c_buff_info_default;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_configure
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_configure(mtb_hal_i2c_t* obj, const mtb_hal_i2c_cfg_t* cfg)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != cfg);

    (void)Cy_SCB_I2C_Disable(obj->base, obj->context);

    cy_stc_scb_i2c_config_t _config_structure;
    memcpy(&_config_structure, obj->config, sizeof(cy_stc_scb_i2c_config_t));

    // Preserve the dual mode if it was initially set
    _config_structure.i2cMode =
        (_config_structure.i2cMode == CY_SCB_I2C_MASTER_SLAVE) ? CY_SCB_I2C_MASTER_SLAVE :
        ((cfg->is_target) ? CY_SCB_I2C_SLAVE : CY_SCB_I2C_MASTER);

    _config_structure.slaveAddress  = (uint8_t)cfg->address;

    if (cfg->is_target)
    {
        _config_structure.acceptAddrInFifo = cfg->enable_address_callback;
        _config_structure.ackGeneralAddr   = cfg->enable_address_callback;
        _config_structure.slaveAddressMask = cfg->address_mask;
    }

    cy_rslt_t result = (cy_rslt_t)Cy_SCB_I2C_Init(obj->base, &_config_structure, obj->context);
    if ((CY_RSLT_SUCCESS == result) && (cfg->frequency_hz != 0))
    {
        result  = _mtb_hal_i2c_set_peri_divider((void*)obj, cfg->frequency_hz, cfg->is_target);
    }

    /* Revert back to original configuration */
    if (CY_RSLT_SUCCESS != result)
    {
        Cy_SCB_I2C_Init(obj->base, obj->config, obj->context);
    }

    _mtb_hal_scb_i2c_enable(obj->base, obj->context);

    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_i2c_controller_read_write
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_i2c_controller_read_write(mtb_hal_i2c_t* obj, uint16_t dev_addr,
                                                    const uint8_t* data, uint16_t size,
                                                    uint32_t timeout, bool send_stop,
                                                    cy_en_scb_i2c_direction_t direction)
{
    cy_en_scb_i2c_command_t ack = CY_SCB_I2C_ACK;

    cy_en_scb_i2c_status_t status = (obj->context->state == CY_SCB_I2C_IDLE)
        ? Cy_SCB_I2C_MasterSendStart(obj->base, dev_addr, direction, timeout, obj->context)
        : Cy_SCB_I2C_MasterSendReStart(obj->base, dev_addr, direction, timeout, obj->context);

    if (status == CY_SCB_I2C_SUCCESS)
    {
        while (size > 0)
        {
            if (direction == CY_SCB_I2C_WRITE_XFER)
            {
                status = Cy_SCB_I2C_MasterWriteByte(obj->base, *data, timeout, obj->context);
            }
            else
            {
                if (size == 1)
                {
                    ack = CY_SCB_I2C_NAK;
                }
                status = Cy_SCB_I2C_MasterReadByte(obj->base, ack, (uint8_t*)data, timeout,
                                                   obj->context);
            }

            if (status != CY_SCB_I2C_SUCCESS)
            {
                break;
            }
            --size;
            ++data;
        }
    }

    if (send_stop)
    {
        /* SCB in I2C mode is very time sensitive. In practice we have to request STOP after */
        /* each block, otherwise it may break the transmission */
        Cy_SCB_I2C_MasterSendStop(obj->base, timeout, obj->context);
    }

    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_controller_write
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_controller_write(mtb_hal_i2c_t* obj, uint16_t dev_addr, const uint8_t* data,
                                       uint16_t size, uint32_t timeout, bool send_stop)
{
    return _mtb_hal_i2c_controller_read_write(obj, dev_addr, data, size, timeout, send_stop,
                                              CY_SCB_I2C_WRITE_XFER);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_controller_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_controller_read(mtb_hal_i2c_t* obj, uint16_t dev_addr, uint8_t* data,
                                      uint16_t size, uint32_t timeout, bool send_stop)
{
    return _mtb_hal_i2c_controller_read_write(obj, dev_addr, data, size, timeout, send_stop,
                                              CY_SCB_I2C_READ_XFER);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_target_abort_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_target_abort_read(mtb_hal_i2c_t* obj)
{
    Cy_SCB_I2C_SlaveAbortRead(obj->base, obj->context);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_target_config_read_buffer
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_target_config_read_buffer(mtb_hal_i2c_t* obj, const uint8_t* data,
                                                uint16_t size)
{
    cy_rslt_t result = MTB_HAL_I2C_RSLT_ERR_BAD_ARGUMENT;
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(size > 0 && data != NULL, MTB_HAL_I2C_RSLT_ERR_BAD_ARGUMENT);
    #else
    if ((size > 0) && (data != NULL))
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        /* Note - 'WriteBuf' is intentional.  PDL and HAL buffer names are opposite */
        Cy_SCB_I2C_SlaveConfigWriteBuf(obj->base, (uint8_t*)data, size, obj->context);
        obj->rx_target_buff.addr.u8 = (uint8_t*)data;
        obj->rx_target_buff.size = size;
        result = CY_RSLT_SUCCESS;
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_target_config_write_buffer
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_target_config_write_buffer(mtb_hal_i2c_t* obj, uint8_t* data, uint16_t size)
{
    cy_rslt_t result = MTB_HAL_I2C_RSLT_ERR_BAD_ARGUMENT;
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(size > 0 && data != NULL, MTB_HAL_I2C_RSLT_ERR_BAD_ARGUMENT);
    #else
    if ((size > 0) && (data != NULL))
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        /* Note - 'ReadBuf' is intentional.  PDL and HAL buffer names are opposite */
        Cy_SCB_I2C_SlaveConfigReadBuf(obj->base, (uint8_t*)data, size, obj->context);
        obj->tx_target_buff.addr.u8 = data;
        obj->tx_target_buff.size = size;
        result = CY_RSLT_SUCCESS;
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_target_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_target_read(mtb_hal_i2c_t* obj, uint8_t* dst_buff, uint16_t* size,
                                  uint32_t timeout)
{
    cy_rslt_t status = MTB_HAL_I2C_RSLT_ERR_BAD_ARGUMENT;

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((obj->rx_target_buff.addr.u8 != NULL) &&
                          ((dst_buff != NULL) && (size != NULL))),
                         MTB_HAL_I2C_RSLT_ERR_BUFFERS_NULL_PTR);
    #else
    if (obj->rx_target_buff.addr.u8 == NULL)
    {
        status = MTB_HAL_I2C_RSLT_ERR_BUFFERS_NULL_PTR;
    }
    else if ((dst_buff != NULL) && (size != NULL))
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        /* Wait until the controller completes writing */
        status = _mtb_hal_i2c_target_wait_for_status(obj, CY_SCB_I2C_SLAVE_WR_CMPLT, timeout);

        if (CY_RSLT_SUCCESS == status)
        {
            *size = _MTB_HAL_MIN(mtb_hal_i2c_target_readable(obj), *size);
            /* Check if the destination buffer is not a I2C RX buffer. */
            if (obj->rx_target_buff.addr.u8 != dst_buff)
            {
                /* Copy command into the destination buffer */
                (void)memcpy((void*)dst_buff, (const void*)obj->rx_target_buff.addr.u8, *size);
            }

            /* Wait for device set the state to IDLE */
            while (obj->context->state != CY_SCB_I2C_IDLE && !(obj->op_in_callback))
            {
                /* I2C PDL driver guarantee the target will be in IDLE state
                    after the end of a transaction */
            }

            _mtb_hal_i2c_target_clear_write_status(obj);
        }
    }
    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_target_write
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_target_write(mtb_hal_i2c_t* obj, const uint8_t* src_buff, uint16_t* size,
                                   uint32_t timeout)
{
    cy_rslt_t status = MTB_HAL_I2C_RSLT_ERR_BAD_ARGUMENT;

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN((obj->tx_target_buff.addr.u8 != NULL) &&
                         ((src_buff != NULL) && (size != NULL)),
                         MTB_HAL_I2C_RSLT_ERR_BUFFERS_NULL_PTR);
    #else
    if (obj->tx_target_buff.addr.u8 == NULL)
    {
        status = MTB_HAL_I2C_RSLT_ERR_BUFFERS_NULL_PTR;
    }
    else if ((src_buff != NULL) && (size != NULL))
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        /* Wait for completion of a previous Controller read transaction */
        while (obj->context->state != CY_SCB_I2C_IDLE && !(obj->op_in_callback))
        {
            /* I2C PDL driver guarantee the target will be in IDLE state
                after the end of a previous transaction */
        }

        if (obj->context->state == CY_SCB_I2C_IDLE)
        {
            *size = _MTB_HAL_MIN(obj->tx_target_buff.size, *size);
            /* Check if the source buffer is not a I2C TX buffer. */
            if (obj->tx_target_buff.addr.u8 != src_buff)
            {
                /* Copy command into the TX buffer */
                (void)memcpy((void*)obj->tx_target_buff.addr.u8, (const void*)src_buff, *size);
            }

            /* Wait until the controller completes reading */
            status = _mtb_hal_i2c_target_wait_for_status(obj, CY_SCB_I2C_SLAVE_RD_CMPLT, timeout);
            if (CY_RSLT_SUCCESS == status)
            {
                _mtb_hal_i2c_target_clear_read_status(obj);
            }
        }
    }
    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_i2c_register_callback(mtb_hal_i2c_t* obj, mtb_hal_i2c_event_callback_t callback,
                                   void* callback_arg)
{
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    Cy_SCB_I2C_RegisterEventCallback(obj->base, _mtb_hal_i2c_cb_wrapper, obj->context);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_register_address_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_i2c_register_address_callback(mtb_hal_i2c_t* obj,
                                           mtb_hal_i2c_address_callback_t callback,
                                           void* callback_arg)
{
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    obj->addr_callback_data.callback = (cy_israddress)callback;
    obj->addr_callback_data.callback_arg = callback_arg;
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    Cy_SCB_I2C_RegisterAddrCallback(obj->base, _mtb_hal_i2c_cb_addr_wrapper, obj->context);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_register_byte_received_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_i2c_register_byte_received_callback(mtb_hal_i2c_t* obj,
                                                 mtb_hal_i2c_byte_callback_t callback,
                                                 void* callback_arg)
{
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    obj->byte_callback_data.callback = (cy_israddress)callback;
    obj->byte_callback_data.callback_arg = callback_arg;
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    #if ((CY_IP_MXSCB_VERSION >= 4) && (CY_IP_MXSCB_VERSION_MINOR >= 4))
    if ((obj->config->i2cMode == CY_SCB_I2C_MASTER_SLAVE) ||
        (obj->config->i2cMode == CY_SCB_I2C_SLAVE))
    {
        Cy_SCB_I2C_RegisterSlaveByteReceivedCallback(obj->base, _mtb_hal_i2c_cb_byte_wrapper,
                                                     obj->context);
    }
    if ((obj->config->i2cMode == CY_SCB_I2C_MASTER_SLAVE) ||
        (obj->config->i2cMode == CY_SCB_I2C_MASTER))
    {
        Cy_SCB_I2C_RegisterMasterByteReceivedCallback(obj->base, _mtb_hal_i2c_cb_byte_wrapper,
                                                      obj->context);
    }
    #endif /* ((CY_IP_MXSCB_VERSION>=4) && (CY_IP_MXSCB_VERSION_MINOR>=4)) */
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_i2c_enable_event(mtb_hal_i2c_t* obj, mtb_hal_i2c_event_t event, bool enable)
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
// mtb_hal_i2c_enable_address_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_i2c_enable_address_event(mtb_hal_i2c_t* obj, mtb_hal_i2c_addr_event_t event,
                                      bool enable)
{
    if (enable)
    {
        obj->addr_irq_cause |= event;
    }
    else
    {
        obj->addr_irq_cause &= ~event;
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_target_readable
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_i2c_target_readable(mtb_hal_i2c_t* obj)
{
    return Cy_SCB_I2C_SlaveGetWriteTransferCount(obj->base, obj->context);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_target_writable
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_i2c_target_writable(mtb_hal_i2c_t* obj)
{
    return (obj->tx_target_buff.size -
            Cy_SCB_I2C_SlaveGetReadTransferCount(obj->base, obj->context));
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_i2c_clear
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_i2c_clear(mtb_hal_i2c_t* obj)
{
    Cy_SCB_ClearRxFifo(obj->base);
    Cy_SCB_ClearTxFifo(obj->base);

    _mtb_hal_i2c_target_clear_write_status(obj);
    _mtb_hal_i2c_target_clear_read_status(obj);
    return CY_RSLT_SUCCESS;
}


#if defined(__cplusplus)
}
#endif

#endif /* MTB_HAL_DRIVER_AVAILABLE_I2C */
