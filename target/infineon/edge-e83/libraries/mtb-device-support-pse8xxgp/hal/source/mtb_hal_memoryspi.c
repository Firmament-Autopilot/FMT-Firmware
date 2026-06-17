/***************************************************************************//**
* \file mtb_hal_memoryspi.c
*
* Description:
* Provides a high level interface for interacting with the Infineon MemorySPI (SMIF).
* This is a wrapper around the lower level PDL API.
*
********************************************************************************
* \copyright
* Copyright 2018-2024 Cypress Semiconductor Corporation (an Infineon company) or
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
 * \addtogroup group_hal_impl_memoryspi MemorySPI (Memory Serial Peripheral Interface)
 * \ingroup group_hal_impl
 * \{
 * \section section_hal_impl_memoryspi_init_cfg Configurator-generated features limitations
 * List of SMIF personality items, which are currently not supported in MemorySPI HAL
 * driver on non-PSE84 devices:
 *  - XIP (eXecute In Place) mode
 *  - Memory Mode Alignment Error interrupt
 *  - RX Data FIFO Underflow interrupt
 *  - TX Command FIFO Overflow
 *  - TX Data FIFO Overflow interrupt
 *  - RX FIFO Level Trigger interrupt
 *  - TX FIFO Level Trigger interrupt
 *  - RX DMA Trigger
 *  - TX DMA Trigger
 *
 *
 * \section section_hal_impl_clock_freq Interface clock frequency
 * Starting MXSMIF HW block version 2 (checked with `CY_IP_MXSMIF_VERSION` define), MemorySPI
 * interface clock frequency is twice lower than configured source HF clock, so if MemorySPI
 * source HF clock is configured, for instance, for 50 MHz, connected memory will be accessed
 * on 25 MHz clock.
 * Interface clock frequency of MXSMIF block with version 1 corresponds to frequency of source HF
 * clock.
 *
 * \} group_hal_impl_memoryspi
 */

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cy_smif.h"
#include "mtb_hal_utils.h"
#include "mtb_hal_memoryspi.h"
#include "mtb_hal_system_impl.h"

#if (MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Internal
*******************************************************************************/
/* in microseconds, timeout for all blocking functions */
#define _MTB_HAL_MEMORYSPI_TIMEOUT_10_MS (10000UL)
/* max number of bytes that the SMIF can drive in one operation */
#define _MTB_HAL_MEMORYSPI_MAX_RX_COUNT (65536UL)


/*******************************************************************************
*       Dispatcher Interrupt Service Routine
*******************************************************************************/

/* Keep track of the current MemorySPI object to ensure we are referencing the
 * correct one, as we don't directly pass the object through the PDL callback
 * indirection.  This also protects against a nested callback situation. */
static volatile mtb_hal_memoryspi_t* _mtb_hal_memoryspi_irq_obj = NULL;

//--------------------------------------------------------------------------------------------------
// _mtb_hal_memoryspi_cb_wrapper
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_memoryspi_cb_wrapper(uint32_t event)
{
    mtb_hal_memoryspi_event_t hal_event = MTB_HAL_MEMORYSPI_EVENT_NONE;
    if (event == CY_SMIF_SEND_CMPLT)
    {
        hal_event = MTB_HAL_MEMORYSPI_IRQ_TRANSMIT_DONE;
    }
    else if (event == CY_SMIF_REC_CMPLT)
    {
        hal_event = MTB_HAL_MEMORYSPI_IRQ_RECEIVE_DONE;
    }

    mtb_hal_memoryspi_t* obj = (mtb_hal_memoryspi_t*)_mtb_hal_memoryspi_irq_obj;

    if ((obj->enabled_events & (uint32_t)hal_event) > 0) // Make sure a user requested event is set
                                                         // before calling
    {
        mtb_hal_memoryspi_event_callback_t callback =
            (mtb_hal_memoryspi_event_callback_t)obj->callback_data.callback;
        callback(obj->callback_data.callback_arg, hal_event);
    }
}


/*******************************************************************************
*       (Internal) MemorySPI Config Related Functions
*******************************************************************************/

/* Translates HAL bus width to PDL bus width */
static cy_en_smif_txfr_width_t _mtb_hal_memoryspi_convert_bus_width(
    mtb_hal_memoryspi_bus_width_t bus_width)
{
    cy_en_smif_txfr_width_t mtb_hal_bus_width;

    switch (bus_width)
    {
        case MTB_HAL_MEMORYSPI_CFG_BUS_SINGLE:
            mtb_hal_bus_width = CY_SMIF_WIDTH_SINGLE;
            break;

        case MTB_HAL_MEMORYSPI_CFG_BUS_DUAL:
            mtb_hal_bus_width = CY_SMIF_WIDTH_DUAL;
            break;

        case MTB_HAL_MEMORYSPI_CFG_BUS_QUAD:
            mtb_hal_bus_width = CY_SMIF_WIDTH_QUAD;
            break;

        case MTB_HAL_MEMORYSPI_CFG_BUS_OCTAL:
            mtb_hal_bus_width = CY_SMIF_WIDTH_OCTAL;
            break;

        default:
            mtb_hal_bus_width = CY_SMIF_WIDTH_SINGLE;
    }

    return mtb_hal_bus_width;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_memoryspi_is_command_struct_valid
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_memoryspi_is_command_struct_valid(
    const mtb_hal_memoryspi_command_t* memoryspi_command)
{
    #if (CY_IP_MXSMIF_VERSION < 3)
    if (((!memoryspi_command->instruction.disabled) &&
         (memoryspi_command->instruction.data_rate == MTB_HAL_MEMORYSPI_DATARATE_DDR)) ||
        ((!memoryspi_command->address.disabled) &&
         (memoryspi_command->address.data_rate == MTB_HAL_MEMORYSPI_DATARATE_DDR)) ||
        ((!memoryspi_command->mode_bits.disabled) &&
         (memoryspi_command->mode_bits.data_rate == MTB_HAL_MEMORYSPI_DATARATE_DDR)) ||
        ((memoryspi_command->dummy_cycles.dummy_count != 0) &&
         (memoryspi_command->dummy_cycles.data_rate == MTB_HAL_MEMORYSPI_DATARATE_DDR)) ||
        (memoryspi_command->data.data_rate == MTB_HAL_MEMORYSPI_DATARATE_DDR))
    {
        /* DDR datarate is not supported by used SMIF IP block */
        return MTB_HAL_MEMORYSPI_RSLT_ERR_DATARATE;
    }
    if (memoryspi_command->instruction.two_byte_cmd)
    {
        /* Two byte instuction is not supported on current SMIF IP block */
        return MTB_HAL_MEMORYSPI_RSLT_ERR_INSTRUCTION;
    }
    if ((memoryspi_command->dummy_cycles.dummy_count != 0) &&
        (memoryspi_command->dummy_cycles.bus_width != MTB_HAL_MEMORYSPI_CFG_BUS_SINGLE))
    {
        /* Bus width parameter for dummy cycles can only be 'single' for current version of SMIF IP
           block */
        return MTB_HAL_MEMORYSPI_RSLT_ERR_DUMMY_CYCLES;
    }
    #else /* CY_IP_MXSMIF_VERSION < 3 or other */
    CY_UNUSED_PARAMETER(memoryspi_command);
    #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_memoryspi_uint32_to_byte_array
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_memoryspi_uint32_to_byte_array(uint32_t value, uint8_t* byteArray,
                                                    uint32_t startPos, uint32_t size)
{
    do
    {
        size--;
        byteArray[size + startPos] = (uint8_t)(value & 0xFF);
        value >>= 0x08;
    } while (size > 0);
}


/* mtb_hal_memoryspi_size_t to number bytes */
__STATIC_INLINE uint32_t _mtb_hal_memoryspi_get_size(mtb_hal_memoryspi_size_t hal_size)
{
    return ((uint32_t)hal_size >> 3); /* convert bits to bytes */
}


/* Sends MemorySPI command with certain set of data */
static cy_rslt_t _mtb_hal_memoryspi_command_transfer(mtb_hal_memoryspi_t* obj,
                                                     const mtb_hal_memoryspi_command_t* command,
                                                     uint32_t addr, bool endOfTransfer)
{
    /* max address size is 4 bytes and max mode bits size is 4 bytes */
    uint8_t cmd_param[8] = { 0 };
    memset(&cmd_param, 0x00, sizeof(cmd_param));
    uint32_t start_pos = 0;
    uint32_t addr_size = 0;
    uint32_t mode_bits_size = 0;
    cy_en_smif_txfr_width_t bus_width = CY_SMIF_WIDTH_SINGLE;
    #if (CY_IP_MXSMIF_VERSION >= 3)
    cy_en_smif_data_rate_t data_rate = CY_SMIF_SDR;
    #endif /* CY_IP_MXSMIF_VERSION >= 3 */

    cy_rslt_t result = _mtb_hal_memoryspi_is_command_struct_valid(command);

    if (CY_RSLT_SUCCESS == result)
    {
        /* Does not support different bus_width for address and mode bits.
         * bus_width is selected based on what (address or mode bits) is enabled.
         * If both are enabled, bus_width of mode bits is selected
         * It is either possible to support 1 byte mode bits with different bus_width
         * by sending the mode byte as command as done in Cy_SMIF_Memslot_CmdRead()
         * in mtb_hal_smif_memslot.c or support multiple bytes of mode bits with same bus_width
         * as address by passing the mode bytes as cmd_param to Cy_SMIF_TransmitCommand().
         * Second approach is implemented here. This restriction is because of the way
         * PDL API is implemented.
         */

        if (!command->address.disabled && !command->mode_bits.disabled)
        {
            if (command->address.bus_width != command->mode_bits.bus_width)
            {
                result = MTB_HAL_MEMORYSPI_RSLT_ERR_BUS_WIDTH;
            }
            #if (CY_IP_MXSMIF_VERSION >= 3)
            else if (command->address.data_rate != command->mode_bits.data_rate)
            {
                result = MTB_HAL_MEMORYSPI_RSLT_ERR_DATARATE;
            }
            #endif /* CY_IP_MXSMIF_VERSION >= 3 */
        }

        if (CY_RSLT_SUCCESS == result)
        {
            if (!command->address.disabled)
            {
                addr_size = _mtb_hal_memoryspi_get_size(command->address.size);
                _mtb_hal_memoryspi_uint32_to_byte_array(addr, cmd_param, start_pos, addr_size);
                start_pos += addr_size;
                bus_width = _mtb_hal_memoryspi_convert_bus_width(command->address.bus_width);
                #if (CY_IP_MXSMIF_VERSION >= 3)
                data_rate = (cy_en_smif_data_rate_t)command->address.data_rate;
                #endif /* CY_IP_MXSMIF_VERSION >= 3 */
            }

            if (!command->mode_bits.disabled)
            {
                mode_bits_size = _mtb_hal_memoryspi_get_size(command->mode_bits.size);
                _mtb_hal_memoryspi_uint32_to_byte_array(command->mode_bits.value, cmd_param,
                                                        start_pos,
                                                        mode_bits_size);
                bus_width = _mtb_hal_memoryspi_convert_bus_width(command->mode_bits.bus_width);
                #if (CY_IP_MXSMIF_VERSION >= 3)
                data_rate = (cy_en_smif_data_rate_t)command->mode_bits.data_rate;
                #endif /* CY_IP_MXSMIF_VERSION >= 3 */
            }

            uint32_t cmpltTxfr = ((endOfTransfer) ? 1UL : 0UL);
            #if (CY_IP_MXSMIF_VERSION < 3)
            result =
                (cy_rslt_t)Cy_SMIF_TransmitCommand(obj->base,
                                                   (uint8_t)(command->instruction.value & 0xFF),
                                                   _mtb_hal_memoryspi_convert_bus_width(command->
                                                                                        instruction.
                                                                                        bus_width), cmd_param,
                                                   (addr_size + mode_bits_size), bus_width, obj->chip_select, cmpltTxfr,
                                                   obj->context);
            #else
            uint16_t completeInstruction = command->instruction.value;
            if (command->instruction.two_byte_cmd)
            {
                completeInstruction |= (completeInstruction << 8);
            }
            result = (cy_rslt_t)Cy_SMIF_TransmitCommand_Ext(obj->base, completeInstruction,
                                                            command->instruction.two_byte_cmd, _mtb_hal_memoryspi_convert_bus_width(
                                                                command->instruction.bus_width),
                                                            (cy_en_smif_data_rate_t)command->instruction.data_rate, cmd_param,
                                                            (addr_size + mode_bits_size),
                                                            bus_width, data_rate, obj->chip_select, cmpltTxfr,
                                                            obj->context);
            #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
        }
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_memoryspi_wait_for_cmd_fifo
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_memoryspi_wait_for_cmd_fifo(mtb_hal_memoryspi_t* obj)
{
    cy_rslt_t status = CY_RSLT_SUCCESS;
    uint32_t timeout = _MTB_HAL_MEMORYSPI_TIMEOUT_10_MS;
    while ((Cy_SMIF_GetCmdFifoStatus(obj->base) == CY_SMIF_TX_CMD_FIFO_STATUS_RANGE) &&
           (CY_RSLT_SUCCESS == status))
    {
        /* Waiting for 1 us per iteration */
        Cy_SysLib_DelayUs(1);
        --timeout;
        status = (0u == timeout) ? MTB_HAL_MEMORYSPI_RSLT_ERR_TIMEOUT : CY_RSLT_SUCCESS;
    }
    return status;
}


/*******************************************************************************
*       Functions
*******************************************************************************/
cy_rslt_t mtb_hal_memoryspi_setup(mtb_hal_memoryspi_t* obj,
                                  const mtb_hal_memoryspi_configurator_t* config,
                                  cy_stc_smif_context_t* context)
{
    /* Explicitly marked not allocated resources as invalid to prevent freeing them. */
    memset(obj, 0, sizeof(mtb_hal_memoryspi_t));
    obj->base = config->base;
    //If multiple csel are specified, the first one is used as the active one
    bool foundValidCsel = false;
    for (int i = 0; i < 4; i++)
    {
        if (config->csel[i] != false)
        {
            if (foundValidCsel == false)
            {
                obj->chip_select = (cy_en_smif_slave_select_t)(1 << i);
                foundValidCsel = true;
            }
            /*This is to keep track of all the csel that are passed in so that we only allow
             * configured csel to be set as active.*/
            obj->configured_csel |= (1 << i);
        }
    }

    obj->clock = config->clock;
    obj->context = context;
    obj->enabled_events = MTB_HAL_MEMORYSPI_EVENT_NONE;
    obj->callback_data.callback = NULL;
    obj->callback_data.callback_arg = NULL;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_get_frequency
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_memoryspi_get_frequency(mtb_hal_memoryspi_t* obj)
{
    CY_ASSERT(NULL != obj);
    #if (CY_IP_MXSMIF_VERSION >= 2)
    /* Please refer to `section_hal_impl_clock_freq` implementation-specific documentation for
       details. */
    return (obj->clock->interface->get_frequency_hz(obj->clock->clock_ref)) /
           1000000U / 2;
    #else
    return (obj->clock->interface->get_frequency_hz(obj->clock->clock_ref)) /
           1000000U;
    #endif /* (CY_IP_MXSMIF_VERSION >= 2) or other */
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_chip_configure
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_memoryspi_chip_configure(mtb_hal_memoryspi_t* obj,
                                           const mtb_hal_memoryspi_chip_select_t csel,
                                           mtb_hal_memoryspi_data_select_t data_select)
{
    CY_ASSERT(NULL != obj);
    Cy_SMIF_SetDataSelect(obj->base, (cy_en_smif_slave_select_t)csel,
                          (cy_en_smif_data_select_t)data_select);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_select_active_csel
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_memoryspi_select_active_csel(mtb_hal_memoryspi_t* obj,
                                               mtb_hal_memoryspi_chip_select_t csel)
{
    CY_ASSERT(NULL != obj);
    cy_rslt_t status = CY_RSLT_SUCCESS;
    if ((obj->configured_csel & csel) != 0)
    {
        obj->chip_select = (cy_en_smif_slave_select_t)csel;
    }
    else
    {
        status = MTB_HAL_MEMORYSPI_RSLT_ERR_CANNOT_SWITCH_CSEL;
    }
    return status;
}


/* no restriction on the value of length. This function splits the read into multiple chunked
   transfers. */
cy_rslt_t mtb_hal_memoryspi_read(mtb_hal_memoryspi_t* obj,
                                 const mtb_hal_memoryspi_command_t* command,
                                 uint32_t address, void* data, size_t* length)
{
    cy_rslt_t status = CY_RSLT_SUCCESS;
    uint32_t chunk = 0;
    size_t read_bytes = *length;

    /* SMIF can read only up to 65536 bytes in one go. Split the larger read into multiple chunks */
    while (read_bytes > 0)
    {
        chunk =
            (read_bytes >
             _MTB_HAL_MEMORYSPI_MAX_RX_COUNT) ? (_MTB_HAL_MEMORYSPI_MAX_RX_COUNT) : read_bytes;

        status = _mtb_hal_memoryspi_command_transfer(obj, command, address, false);

        if (CY_RSLT_SUCCESS == status)
        {
            if (command->dummy_cycles.dummy_count > 0u)
            {
                status = _mtb_hal_memoryspi_wait_for_cmd_fifo(obj);
                if (CY_RSLT_SUCCESS == status)
                {
                    #if (CY_IP_MXSMIF_VERSION < 3)
                    status = (cy_rslt_t)Cy_SMIF_SendDummyCycles(obj->base,
                                                                command->dummy_cycles.dummy_count);
                    #else
                    status = (cy_rslt_t)Cy_SMIF_SendDummyCycles_Ext(obj->base,
                                                                    _mtb_hal_memoryspi_convert_bus_width(
                                                                        command->dummy_cycles.
                                                                        bus_width),
                                                                    (cy_en_smif_data_rate_t)command->dummy_cycles.data_rate,
                                                                    command->dummy_cycles.dummy_count);
                    #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
                }
            }

            if (CY_RSLT_SUCCESS == status)
            {
                status = _mtb_hal_memoryspi_wait_for_cmd_fifo(obj);
                if (CY_RSLT_SUCCESS == status)
                {
                    #if (CY_IP_MXSMIF_VERSION < 3)
                    status = (cy_rslt_t)Cy_SMIF_ReceiveDataBlocking(obj->base, (uint8_t*)data,
                                                                    chunk,
                                                                    _mtb_hal_memoryspi_convert_bus_width(
                                                                        command->data.bus_width),
                                                                    obj->context);
                    #else
                    status = (cy_rslt_t)Cy_SMIF_ReceiveDataBlocking_Ext(obj->base, (uint8_t*)data,
                                                                        chunk,
                                                                        _mtb_hal_memoryspi_convert_bus_width(
                                                                            command->data.bus_width),
                                                                        (cy_en_smif_data_rate_t)command->data.data_rate,
                                                                        obj->context);
                    #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
                    if (CY_RSLT_SUCCESS != status)
                    {
                        break;
                    }
                }
            }
        }
        read_bytes -= chunk;
        address += chunk;
        data = (void*)&((uint8_t*)data)[chunk];
    }

    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_read_async
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_memoryspi_read_async(mtb_hal_memoryspi_t* obj,
                                       const mtb_hal_memoryspi_command_t* command,
                                       uint32_t address, void* data, size_t* length)
{
    cy_rslt_t status = _mtb_hal_memoryspi_command_transfer(obj, command, address, false);

    if (CY_RSLT_SUCCESS == status)
    {
        if (command->dummy_cycles.dummy_count > 0u)
        {
            status = _mtb_hal_memoryspi_wait_for_cmd_fifo(obj);
            if (CY_RSLT_SUCCESS == status)
            {
                #if (CY_IP_MXSMIF_VERSION < 3)
                status = (cy_rslt_t)Cy_SMIF_SendDummyCycles(obj->base,
                                                            command->dummy_cycles.dummy_count);
                #else
                status = (cy_rslt_t)Cy_SMIF_SendDummyCycles_Ext(obj->base,
                                                                _mtb_hal_memoryspi_convert_bus_width(
                                                                    command->dummy_cycles.bus_width),
                                                                (cy_en_smif_data_rate_t)command->dummy_cycles.data_rate,
                                                                command->dummy_cycles.dummy_count);
                #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
            }
        }

        if (CY_RSLT_SUCCESS == status)
        {
            status = _mtb_hal_memoryspi_wait_for_cmd_fifo(obj);
            if (CY_RSLT_SUCCESS == status)
            {
                #if (CY_IP_MXSMIF_VERSION < 3)
                status = (cy_rslt_t)Cy_SMIF_ReceiveData(obj->base, (uint8_t*)data,
                                                        (uint32_t)*length,
                                                        _mtb_hal_memoryspi_convert_bus_width(command
                                                                                             ->
                                                                                             data.
                                                                                             bus_width), _mtb_hal_memoryspi_cb_wrapper,
                                                        obj->context);
                #else
                status = (cy_rslt_t)Cy_SMIF_ReceiveData_Ext(obj->base, (uint8_t*)data,
                                                            (uint32_t)*length,
                                                            _mtb_hal_memoryspi_convert_bus_width(
                                                                command
                                                                ->
                                                                data.
                                                                bus_width),
                                                            (cy_en_smif_data_rate_t)command->data.data_rate, _mtb_hal_memoryspi_cb_wrapper,
                                                            obj->context);
                #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
            }
        }
    }
    return status;
}


/* length can be up to 65536. */
cy_rslt_t mtb_hal_memoryspi_write(mtb_hal_memoryspi_t* obj,
                                  const mtb_hal_memoryspi_command_t* command,
                                  uint32_t address, const void* data,
                                  size_t* length)
{
    cy_rslt_t status = CY_RSLT_SUCCESS;

    if ((*length > 0))
    {
        status = _mtb_hal_memoryspi_command_transfer(obj, command, address, false);

        if (CY_RSLT_SUCCESS == status)
        {
            if (command->dummy_cycles.dummy_count > 0u)
            {
                status = _mtb_hal_memoryspi_wait_for_cmd_fifo(obj);
                if (CY_RSLT_SUCCESS == status)
                {
                    #if (CY_IP_MXSMIF_VERSION < 3)
                    status = (cy_rslt_t)Cy_SMIF_SendDummyCycles(obj->base,
                                                                command->dummy_cycles.dummy_count);
                    #else
                    status = (cy_rslt_t)Cy_SMIF_SendDummyCycles_Ext(obj->base,
                                                                    _mtb_hal_memoryspi_convert_bus_width(
                                                                        command->dummy_cycles.
                                                                        bus_width),
                                                                    (cy_en_smif_data_rate_t)command->dummy_cycles.data_rate,
                                                                    command->dummy_cycles.dummy_count);
                    #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
                }
            }

            if ((CY_SMIF_SUCCESS == status) && (*length > 0))
            {
                status = _mtb_hal_memoryspi_wait_for_cmd_fifo(obj);
                if (CY_RSLT_SUCCESS == status)
                {
                    #if (CY_IP_MXSMIF_VERSION < 3)
                    status = (cy_rslt_t)Cy_SMIF_TransmitDataBlocking(obj->base, (uint8_t*)data,
                                                                     *length,
                                                                     _mtb_hal_memoryspi_convert_bus_width(
                                                                         command->data.bus_width),
                                                                     obj->context);
                    #else
                    status = (cy_rslt_t)Cy_SMIF_TransmitDataBlocking_Ext(obj->base, (uint8_t*)data,
                                                                         *length,
                                                                         _mtb_hal_memoryspi_convert_bus_width(
                                                                             command->data.bus_width),
                                                                         (cy_en_smif_data_rate_t)command->data.data_rate,
                                                                         obj->context);
                    #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
                }
            }
        }
    }
    return status;
}


/* length can be up to 65536. */
cy_rslt_t mtb_hal_memoryspi_write_async(mtb_hal_memoryspi_t* obj,
                                        const mtb_hal_memoryspi_command_t* command,
                                        uint32_t address, const void* data, size_t* length)
{
    cy_rslt_t status = CY_RSLT_SUCCESS;

    if ((*length > 0))
    {
        status = _mtb_hal_memoryspi_command_transfer(obj, command, address, false);

        if (CY_RSLT_SUCCESS == status)
        {
            if (command->dummy_cycles.dummy_count > 0u)
            {
                status = _mtb_hal_memoryspi_wait_for_cmd_fifo(obj);
                if (CY_RSLT_SUCCESS == status)
                {
                    #if (CY_IP_MXSMIF_VERSION < 3)
                    status = (cy_rslt_t)Cy_SMIF_SendDummyCycles(obj->base,
                                                                command->dummy_cycles.dummy_count);
                    #else
                    status = (cy_rslt_t)Cy_SMIF_SendDummyCycles_Ext(obj->base,
                                                                    _mtb_hal_memoryspi_convert_bus_width(
                                                                        command->dummy_cycles.
                                                                        bus_width),
                                                                    (cy_en_smif_data_rate_t)command->dummy_cycles.data_rate,
                                                                    command->dummy_cycles.dummy_count);
                    #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
                }
            }

            if ((CY_SMIF_SUCCESS == status) && (*length > 0))
            {
                status = _mtb_hal_memoryspi_wait_for_cmd_fifo(obj);
                if (CY_RSLT_SUCCESS == status)
                {
                    #if (CY_IP_MXSMIF_VERSION < 3)
                    status = (cy_rslt_t)Cy_SMIF_TransmitData(obj->base, (uint8_t*)data, *length,
                                                             _mtb_hal_memoryspi_convert_bus_width(
                                                                 command
                                                                 ->
                                                                 data.
                                                                 bus_width), _mtb_hal_memoryspi_cb_wrapper,
                                                             obj->context);
                    #else
                    status = (cy_rslt_t)Cy_SMIF_TransmitData_Ext(obj->base, (uint8_t*)data, *length,
                                                                 _mtb_hal_memoryspi_convert_bus_width(
                                                                     command->data.bus_width),
                                                                 (cy_en_smif_data_rate_t)command->data.data_rate, _mtb_hal_memoryspi_cb_wrapper,
                                                                 obj->context);
                    #endif /* CY_IP_MXSMIF_VERSION < 3 or other */
                }
            }
        }
    }
    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_transfer
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_memoryspi_transfer(
    mtb_hal_memoryspi_t* obj, const mtb_hal_memoryspi_command_t* command, uint32_t address,
    const void* tx_data, size_t tx_size, void* rx_data,
    size_t rx_size)
{
    cy_rslt_t status = CY_RSLT_SUCCESS;

    //Size for DDR operations needs to always be a multiple of 2
    if (((rx_size % 2) == 1) &&
        (command->instruction.data_rate == MTB_HAL_MEMORYSPI_DATARATE_DDR) &&
        (command->instruction.bus_width == MTB_HAL_MEMORYSPI_CFG_BUS_OCTAL))
    {
        rx_size += 1;
    }

    if (((tx_data == NULL) || (tx_size == 0)) && ((rx_data == NULL) || (rx_size == 0)))
    {
        /* only command, no rx or tx */
        status = _mtb_hal_memoryspi_command_transfer(obj, command, address, true);
    }
    else
    {
        if ((tx_data != NULL) && tx_size)
        {
            status = mtb_hal_memoryspi_write(obj, command, address, tx_data, &tx_size);
        }

        if (status == CY_RSLT_SUCCESS)
        {
            if ((rx_data != NULL) && rx_size)
            {
                status = mtb_hal_memoryspi_read(obj, command, address, rx_data, &rx_size);
            }
        }
    }
    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_memoryspi_register_callback(mtb_hal_memoryspi_t* obj,
                                         mtb_hal_memoryspi_event_callback_t callback,
                                         void* callback_arg)
{
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    mtb_hal_system_critical_section_exit(savedIntrStatus);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_memoryspi_enable_event(mtb_hal_memoryspi_t* obj, mtb_hal_memoryspi_event_t event,
                                    bool enable)
{
    if (enable)
    {
        obj->enabled_events |= event;
    }
    else
    {
        obj->enabled_events &= ~event;
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_memoryspi_process_interrupt(mtb_hal_memoryspi_t* obj)
{
    /* Save the old value and store it aftewards in case we get into a nested IRQ situation */
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in
       here, they just might change where the original pointer points */
    mtb_hal_memoryspi_t* old_irq_obj = (mtb_hal_memoryspi_t*)_mtb_hal_memoryspi_irq_obj;
    _mtb_hal_memoryspi_irq_obj = obj;

    if (NULL != obj)
    {
        Cy_SMIF_Interrupt(obj->base, (obj->context));
    }

    _mtb_hal_memoryspi_irq_obj = old_irq_obj;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_is_async_in_progress
//--------------------------------------------------------------------------------------------------
bool mtb_hal_memoryspi_is_async_in_progress(mtb_hal_memoryspi_t* obj)
{
    CY_ASSERT(obj->base != NULL);

    uint32_t smif_status = Cy_SMIF_GetTransferStatus(obj->base, obj->context);

    return ((CY_SMIF_SEND_BUSY == smif_status) || (CY_SMIF_RX_BUSY == smif_status));
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_memoryspi_is_busy
//--------------------------------------------------------------------------------------------------
bool mtb_hal_memoryspi_is_busy(mtb_hal_memoryspi_t* obj)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(obj->base != NULL);

    return (mtb_hal_memoryspi_is_async_in_progress(obj) || Cy_SMIF_BusyCheck(obj->base));
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI */
