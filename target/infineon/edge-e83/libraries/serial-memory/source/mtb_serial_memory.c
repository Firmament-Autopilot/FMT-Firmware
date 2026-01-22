/***********************************************************************************************//**
 * \file mtb_serial_memory.c
 *
 * \brief
 * Provides APIs for interacting with an external memory connected to the SPI or
 * serial memory interface, uses SFDP to auto-discover memory properties if SFDP is
 * enabled in the configuration.
 *
 ***************************************************************************************************
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
 **************************************************************************************************/

#include <stdbool.h>
#include "mtb_serial_memory.h"
#include "cy_utils.h"

#ifdef CY_IP_MXSMIF

#if defined(__cplusplus)
extern "C" {
#endif


/** \cond INTERNAL */

/** Timeout to apply while polling the memory for its ready status after quad
 *  enable command has been sent out. Quad enable is a non-volatile write.
 */
#define MTB_SERIAL_MEMORY_QUAD_ENABLE_TIMEOUT_US    (5000lu) // in microseconds

/** Number of loops to run while polling the SMIF for its busy status. */
#define _MTB_SERIAL_MEMORY_SMIF_BUSY_CHECK_LOOP_COUNT                  (10lu)

/** Timeout to apply per loop while polling the SMIF for its busy status. */
#define _MTB_SERIAL_MEMORY_SMIF_BUSY_CHECK_TIMEOUT_MS                  (1lu) // in milliseconds

/* Maximum number of bytes that can be read by SMIF in one transfer */
#define _MTB_SERIAL_MEMORY_SMIF_MAX_RX_COUNT                           (65536lu)

#define _MTB_SERIAL_MEMORY_MSB_SHIFT_EIGHT                             (0x08u)
#define _MTB_SERIAL_MEMORY_LSB_MASK                                    (0xFFlu)

/* Masks used for checking the flag bits */
#define _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE                             (0x01lu << 0)
#define _MTB_SERIAL_MEMORY_FLAG_ASYNC_INIT_DONE                        (0x01lu << 1)
#define _MTB_SERIAL_MEMORY_FLAG_READ_IN_PROGRESS                       (0x01lu << 2)

#define _MTB_SERIAL_MEMORY_IS_EVEN(value)                              \
    ((value % 2 == 0) ? true : false)

/* Maximum frequency that SFDP can operate at. It's differenet depending on the memory module
 * but the SFDP protocol requires that all memories reach at least 50MHz */
#define _MTB_SERIAL_MEMORY_MAX_SFDP_FREQ                               (50000000u)

/* Some devices execute program code from external memory (XIP mode).
 * SerialFlash still can work on such devices, but with some limitations. */
#if defined(CY_DEVICE_CYW20829)
#define _MTB_SERIAL_MEMORY_USING_XIP_MEMORY
#endif /* defined(CY_DEVICE_CYW20829) */

/*******************************************************************************
*                       Private Function Definitions
*******************************************************************************/
//------------------------------------------------------------------------------
// _mtb_serial_memory_slaveslot_to_memnum
//------------------------------------------------------------------------------
static uint8_t _mtb_serial_memory_slaveslot_to_memnum(uint32_t slaveslot)
{
    uint8_t memnum;

    switch (slaveslot)
    {
        case MTB_SERIAL_MEMORY_CHIP_SELECT_0:
        {
            memnum = 0U;
            break;
        }

        case MTB_SERIAL_MEMORY_CHIP_SELECT_1:
        {
            memnum = 1U;
            break;
        }

        case MTB_SERIAL_MEMORY_CHIP_SELECT_2:
        {
            memnum = 2U;
            break;
        }

        case MTB_SERIAL_MEMORY_CHIP_SELECT_3:
        {
            memnum = 3U;
            break;
        }

        default:
        {
            memnum = 0xFFU;
            break;
        }
    } /* End Switch */

    return memnum;
}


//------------------------------------------------------------------------------
// _mtb_serial_memory_is_flag_set
//------------------------------------------------------------------------------
bool _mtb_serial_memory_is_flag_set(mtb_serial_memory_t* obj, uint32_t mask)
{
    return ((obj->status_flags & mask) != 0U);
}


//------------------------------------------------------------------------------
// _mtb_serial_memory_clear_flag
//------------------------------------------------------------------------------
void _mtb_serial_memory_clear_flag(mtb_serial_memory_t* obj, uint32_t mask)
{
    obj->status_flags &= ~mask;
}


//--------------------------------------------------------------------------------------------------
// _mtb_serial_memory_set_flag
//--------------------------------------------------------------------------------------------------
void _mtb_serial_memory_set_flag(mtb_serial_memory_t* obj, uint32_t mask)
{
    obj->status_flags |= mask;
}


//--------------------------------------------------------------------------------------------------
// _mtb_serial_memory_is_busy
//--------------------------------------------------------------------------------------------------
bool _mtb_serial_memory_is_busy(mtb_serial_memory_t* obj)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(obj->base != NULL);

    uint32_t smif_status = Cy_SMIF_GetTransferStatus(obj->base, &obj->mem_context->smif_context);
    return (Cy_SMIF_BusyCheck(obj->base) ||
            ((CY_SMIF_SEND_BUSY == smif_status) || (CY_SMIF_RX_BUSY == smif_status)));
}


//--------------------------------------------------------------------------------------------------
// _mtb_serial_memory_mutex_acquire
//--------------------------------------------------------------------------------------------------
static inline cy_rslt_t _mtb_serial_memory_mutex_acquire(mtb_serial_memory_t* obj)
{
    #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE)
    return cy_rtos_get_mutex(&obj->mutex, CY_RTOS_NEVER_TIMEOUT);
    #else /* defined(MTB_SERIAL_MEMORY_THREAD_SAFE) */
    CY_UNUSED_PARAMETER(obj);
    return CY_RSLT_SUCCESS;
    #endif /* defined(MTB_SERIAL_MEMORY_THREAD_SAFE) */
}


//--------------------------------------------------------------------------------------------------
// _mtb_serial_memory_mutex_release
//--------------------------------------------------------------------------------------------------
static inline cy_rslt_t _mtb_serial_memory_mutex_release(mtb_serial_memory_t* obj)
{
    #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE)
    return cy_rtos_set_mutex(&obj->mutex);
    #else /* defined(MTB_SERIAL_MEMORY_THREAD_SAFE) */
    CY_UNUSED_PARAMETER(obj);
    return CY_RSLT_SUCCESS;
    #endif /* defined(MTB_SERIAL_MEMORY_THREAD_SAFE) */
}


//--------------------------------------------------------------------------------------------------
// _mtb_serial_memory_compute_data_rate
//--------------------------------------------------------------------------------------------------
cy_en_smif_data_rate_t _mtb_serial_memory_compute_data_rate(mtb_serial_memory_t* obj)
{
    cy_en_smif_data_rate_t dataRate;
    cy_stc_smif_mem_config_t const* memCfg =
        obj->mem_context->block_config->memConfig[obj->smif_active_slot];

    if ((memCfg->deviceCfg != NULL) &&
        (obj->mem_context->block_config->memConfig[obj->smif_active_slot]->deviceCfg->readCmd->
         dataRate == CY_SMIF_DDR) &&
        (obj->mem_context->block_config->memConfig[obj->smif_active_slot]->deviceCfg->programCmd->
         dataRate == CY_SMIF_DDR))
    {
        dataRate = CY_SMIF_DDR;
    }
    else
    {
        dataRate = CY_SMIF_SDR;
    }

    return dataRate;
}


 #if (CY_IP_MXSMIF_VERSION >= 4)
// --------------------------------------------------------------------------------------------------
//  _mtb_serial_memory_set_rx_capture_mode
// --------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_serial_memory_set_rx_capture_mode(mtb_serial_memory_t* obj,
                                                 cy_en_smif_capture_mode_t rx_capture_mode)
{
    cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;
    cy_rslt_t result = CY_RSLT_SUCCESS;

    /* We need to disable before we can successfully update Capture mode */
    Cy_SMIF_Disable(obj->base);

    /* Set capture mode */
    smif_status = Cy_SMIF_SetRxCaptureMode(obj->base, rx_capture_mode,
                                           (cy_en_smif_slave_select_t)obj->chip_select);
    if (smif_status != CY_SMIF_SUCCESS)
    {
        result = MTB_RSLT_SERIAL_MEMORY_ERR_RX_CAPTURE;
    }

    Cy_SMIF_Enable(obj->base, &obj->mem_context->smif_context);

    return result;
}


// --------------------------------------------------------------------------------------------------
//  _mtb_serial_memory_enable_octal_mode_if_needed
// --------------------------------------------------------------------------------------------------
// This is needed in the case of an external memory that by default is set up as SPI and then needs
// to be set to Octal mode via the specified command. For memories that by default are set up as
// OSPI such a command does not exist.
static cy_rslt_t _mtb_serial_memory_enable_octal_mode_if_needed(mtb_serial_memory_t* obj)
{
    cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;
    cy_rslt_t result = CY_RSLT_SUCCESS;
    cy_stc_smif_mem_config_t const* memCfg =
        obj->mem_context->block_config->memConfig[obj->smif_active_slot];

    if ((memCfg->deviceCfg != NULL) &&
        (obj->mem_context->block_config->memConfig[obj->smif_active_slot]->deviceCfg->
         writeStsRegOeCmd !=
         NULL))
    {
        if ((obj->mem_context->block_config->memConfig[obj->smif_active_slot]->deviceCfg->readCmd->
             dataWidth
             == CY_SMIF_WIDTH_OCTAL) ||
            (obj->mem_context->block_config->memConfig[obj->smif_active_slot]->deviceCfg->programCmd
             ->
             dataWidth == CY_SMIF_WIDTH_OCTAL))
        {
            cy_en_smif_data_rate_t dataRate = _mtb_serial_memory_compute_data_rate(obj);

            smif_status = Cy_SMIF_MemOctalEnable(obj->base,
                                                 obj->mem_context->block_config->memConfig[obj->
                                                                                           smif_active_slot],
                                                 dataRate,
                                                 &obj->mem_context->smif_context);

            if (CY_SMIF_SUCCESS == smif_status)
            {
                result = _mtb_serial_memory_set_rx_capture_mode(obj,
                                                                (dataRate ==
                                                                 CY_SMIF_DDR) ? CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS : CY_SMIF_SEL_NORMAL_SPI);
            }
            else
            {
                result = MTB_RSLT_SERIAL_MEMORY_ERR_OCTAL_ENABLE;
            }
        }
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_serial_memory_set_capture_mode_if_needed
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_serial_memory_set_capture_mode_if_needed(mtb_serial_memory_t* obj)
{
    cy_rslt_t status = CY_SMIF_SUCCESS;
    cy_stc_smif_mem_config_t const* memCfg =
        obj->mem_context->block_config->memConfig[obj->smif_active_slot];

    if (0 != (obj->mem_context->block_config->memConfig[obj->smif_active_slot]->flags &
              CY_SMIF_FLAG_DETECT_SFDP))
    {
        // If we want to perform SFDP we need the SMIF to be configured in NORMAL SPI MODE as the
        // protocol is working in single SPI mode. Therefore if a previous setting had put the
        // memory in XSPI mode we need to revert it so that we can perform SFDP correctly.
        if ((obj->base->CTL2 & SMIF_CORE_CTL2_RX_CAPTURE_MODE_Msk) >>
            SMIF_CORE_CTL2_RX_CAPTURE_MODE_Pos ==
            CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS)
        {
            status = _mtb_serial_memory_set_rx_capture_mode(obj, CY_SMIF_SEL_NORMAL_SPI);
        }
    }
    else
    {
        if (memCfg->deviceCfg != NULL)
        {
            // If we are not performing SFDP but we are connecting to an OSPI memory we need to
            // check
            // the data rate and set it to HYPERBUS for DDR mode.
            if ((obj->mem_context->block_config->memConfig[obj->smif_active_slot]->deviceCfg->
                 readCmd->
                 dataWidth
                 == CY_SMIF_WIDTH_OCTAL) ||
                (obj->mem_context->block_config->memConfig[obj->smif_active_slot]->deviceCfg->
                 programCmd->
                 dataWidth == CY_SMIF_WIDTH_OCTAL))
            {
                cy_en_smif_data_rate_t dataRate = _mtb_serial_memory_compute_data_rate(obj);

                status = _mtb_serial_memory_set_rx_capture_mode(obj, (dataRate == CY_SMIF_DDR) ?
                                                                CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS : CY_SMIF_SEL_NORMAL_SPI);
            }
        }
    }
    return status;
}


#endif /* (CY_IP_MXSMIF_VERSION >= 4) */

/** \endcond */


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_serial_memory_setup(
    mtb_serial_memory_t* obj,
    mtb_serial_memory_chip_select_t smif_active_chip,
    SMIF_Type* base,
    const mtb_hal_clock_t* clock,
    cy_stc_smif_mem_context_t* mem_context,
    cy_stc_smif_mem_info_t* mem_info,
    const cy_stc_smif_block_config_t* block_config)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    cy_stc_smif_mem_config_t const* memCfg;
    uint8_t memnum;

    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != base);
    CY_ASSERT(NULL != clock);
    CY_ASSERT(NULL != mem_context);
    CY_ASSERT(NULL != mem_info);
    CY_ASSERT(NULL != block_config);

    mem_context->block_config = block_config;
    obj->chip_select = smif_active_chip;
    obj->base = base;
    obj->clock = clock;
    obj->mem_context = mem_context;
    obj->mem_info = mem_info;
    memnum = _mtb_serial_memory_slaveslot_to_memnum(obj->chip_select);

    for (uint32_t i = 0; i < block_config->memCount; i++)
    {
        if (block_config->memConfig[i]->slaveSelect ==
            (cy_en_smif_slave_select_t)smif_active_chip)
        {
            obj->smif_active_slot = i;
        }
        obj->configured_csel |= block_config->memConfig[i]->slaveSelect;
    }
    memCfg = block_config->memConfig[obj->smif_active_slot];

    for (uint32_t idx = 0; idx < block_config->memCount; idx++)
    {
        Cy_SMIF_SetDataSelect(obj->base, block_config->memConfig[idx]->slaveSelect,
                              block_config->memConfig[idx]->dataSelect);
    }

    uint32_t current_freq = (mtb_hal_clock_get_hf_clock_freq(obj->clock->clock_ref)) / 1000000U;
    #if (CY_IP_MXSMIF_VERSION >= 2)
    //Internal divider of value 2 always present for MXSMIF v2 onwards
    current_freq /= 2;
    #endif /* (CY_IP_MXSMIF_VERSION >= 2) or other */

    /* Iterate through the memory configurations and check if SFDP detection flag is set */
    for (uint32_t i = 0; i < block_config->memCount; i++)
    {
        if (0 != (block_config->memConfig[i]->flags & CY_SMIF_FLAG_DETECT_SFDP))
        {
            if (current_freq > _MTB_SERIAL_MEMORY_MAX_SFDP_FREQ)
            {
                result = MTB_RSLT_SERIAL_MEMORY_ERR_UNSUPPORTED;
                break;
            }
        }
    }

    if (CY_RSLT_SUCCESS == result)
    {
        #if (CY_IP_MXSMIF_VERSION >= 4)
        // For MemInit to complete successfully the SMIF peripheral needs to have
        // capture mode set to normal.
        // SFDP mode cannot be used for octal memories that have already been initialized
        // and gone through the octal enable process.
        result = _mtb_serial_memory_set_capture_mode_if_needed(obj);
        if (CY_SMIF_SUCCESS == result)
        #endif // if (CY_IP_MXSMIF_VERSION >= 5)
        {
            cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;
            result = CY_RSLT_SUCCESS;
            // Perform SFDP detection and XIP register configuration depending on the memory
            // configuration.
            smif_status = Cy_SMIF_MemNumInit(obj->base, block_config, mem_context);

            if (CY_SMIF_SUCCESS == smif_status)
            {
                smif_status =
                    Cy_SMIF_MemNumGetInfo(mem_context, memnum, mem_info);
            }

            if (CY_SMIF_SUCCESS == smif_status)
            {
                if (memCfg->deviceCfg != NULL)
                {
                    // Enable Quad mode (1-1-4 or 1-4-4 modes) to use all the four I/Os during
                    // communication if needed.
                    if ((block_config->memConfig[obj->smif_active_slot]->deviceCfg->
                         readCmd->
                         dataWidth == CY_SMIF_WIDTH_QUAD) ||
                        (block_config->memConfig[obj->smif_active_slot]->deviceCfg->
                         programCmd
                         ->dataWidth == CY_SMIF_WIDTH_QUAD))
                    {
                        bool isQuadEnabled = false;
                        smif_status =
                            Cy_SMIF_MemIsQuadEnabled(obj->base,
                                                     block_config->memConfig[obj->
                                                                             smif_active_slot],
                                                     &isQuadEnabled,
                                                     &obj->mem_context->smif_context);
                        if ((CY_SMIF_SUCCESS == smif_status) && !isQuadEnabled)
                        {
                            smif_status =
                                Cy_SMIF_MemEnableQuadMode(obj->base,
                                                          block_config->memConfig[obj->
                                                                                  smif_active_slot],
                                                          MTB_SERIAL_MEMORY_QUAD_ENABLE_TIMEOUT_US,
                                                          &obj->mem_context->smif_context);
                        }
                    }
                }
            }

            if (CY_SMIF_SUCCESS != smif_status)
            {
                result = (cy_rslt_t)smif_status;
            }
        }
    }
    #if (CY_IP_MXSMIF_VERSION >= 4)
    // Enable Octal mode (8S-8S-8S or 8D-8D-8D modes) to use all the eight I/Os during
    // communication if needed.
    if (CY_RSLT_SUCCESS == result)
    {
        result = _mtb_serial_memory_enable_octal_mode_if_needed(obj);
    }
    #endif // if (CY_IP_MXSMIF_VERSION >= 4)

    #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE)
    if (CY_RSLT_SUCCESS == result)
    {
        /* Initialize the mutex */
        result = cy_rtos_init_mutex(&obj->mutex);
    }
    #endif /* #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE) */

    if (CY_RSLT_SUCCESS == result)
    {
        _mtb_serial_memory_set_flag(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE);
    }

    return result;
}


#if !defined(COMPONENT_SECURE_DEVICE)
//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_setup_nonsecure
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_serial_memory_setup_nonsecure(
    mtb_serial_memory_t* obj,
    mtb_serial_memory_chip_select_t smif_active_chip,
    SMIF_Type* base,
    cy_stc_smif_mem_context_t* mem_context,
    cy_stc_smif_mem_info_t* mem_info)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    uint8_t memnum;

    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != base);
    CY_ASSERT(NULL != mem_context);
    CY_ASSERT(NULL != mem_info);

    obj->chip_select = smif_active_chip;
    obj->base = base;
    obj->mem_context = mem_context;
    obj->mem_info = mem_info;
    memnum = _mtb_serial_memory_slaveslot_to_memnum(obj->chip_select);

    cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;
    result = CY_RSLT_SUCCESS;
    smif_status = Cy_SMIF_MemNumSetupNonSecure(base, mem_context);

    if (CY_SMIF_SUCCESS == smif_status)
    {
        smif_status = Cy_SMIF_MemNumGetInfo(mem_context, memnum, mem_info);
    }

    if (CY_SMIF_SUCCESS != smif_status)
    {
        result = (cy_rslt_t)smif_status;
    }

    #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE)
    if (CY_RSLT_SUCCESS == result)
    {
        /* Initialize the mutex */
        result = cy_rtos_init_mutex(&obj->mutex);
    }
    #endif /* #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE) */

    if (CY_RSLT_SUCCESS == result)
    {
        _mtb_serial_memory_set_flag(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE);
    }

    return result;
}


#endif // if !defined(COMPONENT_SECURE_DEVICE)


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_get_size
//--------------------------------------------------------------------------------------------------
size_t mtb_serial_memory_get_size(mtb_serial_memory_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));

    return (size_t)obj->mem_info->memSize;
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_get_erase_size
//--------------------------------------------------------------------------------------------------
size_t mtb_serial_memory_get_erase_size(mtb_serial_memory_t* obj, uint32_t addr)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    size_t erase_sector_size = obj->mem_info->eraseSize;
    uint32_t idx;
    uint32_t regionStartAddr;
    uint32_t regionEndAddr;

    for (idx = 0UL; idx < obj->mem_info->hybridRegionCount; idx++)
    {
        regionStartAddr = obj->mem_info->hybridRegionInfo[idx].regionStartAddress;
        regionEndAddr = obj->mem_info->hybridRegionInfo[idx].regionEndAddress;
        if ((addr >= regionStartAddr) && (addr < regionEndAddr))
        {
            erase_sector_size = obj->mem_info->hybridRegionInfo[idx].eraseSize;
            break;
        }
    }

    return erase_sector_size;
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_get_prog_size
//--------------------------------------------------------------------------------------------------
size_t mtb_serial_memory_get_prog_size(mtb_serial_memory_t* obj, uint32_t addr)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    CY_UNUSED_PARAMETER(addr);

    return (size_t)obj->mem_info->programSize;
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_serial_memory_read(mtb_serial_memory_t* obj, uint32_t addr, size_t length,
                                 uint8_t* buf)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    cy_rslt_t result_mutex_rel = CY_RSLT_SUCCESS;
    uint8_t memnum = _mtb_serial_memory_slaveslot_to_memnum(obj->chip_select);

    cy_rslt_t result = _mtb_serial_memory_mutex_acquire(obj);

    if (CY_RSLT_SUCCESS == result)
    {
        if ((obj->mem_info->flags & CY_SMIF_FLAG_SPI_DEVICE) != 0UL)
        {
            #if defined(_MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE)
            if (_MTB_SERIAL_MEMORY_IS_EVEN(addr))
            #endif /* if defined(_MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE) */
            {
                // Cy_SMIF_MemNumRead() returns error if (addr + length) > total memory size.
                result = (cy_rslt_t)Cy_SMIF_MemNumRead(obj->mem_context, memnum, addr, buf, length);
            }
            #if defined(_MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE)
            else if ((!_MTB_SERIAL_MEMORY_IS_EVEN(addr)) && (length == 1))
            {
                uint32_t temp_addr = addr - 1;
                uint8_t temp_buf[2];
                memset(temp_buf, 0, length+1);
                // Cy_SMIF_MemNumRead() returns error if (addr + length) > total memory size.
                result = (cy_rslt_t)Cy_SMIF_MemNumRead(obj->mem_context, memnum, addr, buf,
                                                       length + 1);
                memcpy(buf, &temp_buf[1], length);
            }
            else
            {
                result = MTB_RSLT_SERIAL_MEMORY_ERR_UNSUPPORTED;
            }
            #endif /* if defined(_MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE) */
        }
        else if ((obj->mem_info->flags & CY_SMIF_FLAG_HYPERBUS_DEVICE) != 0UL)
        {
            result = (cy_rslt_t)Cy_SMIF_MemNumHyperBusRead(obj->mem_context, memnum, addr, buf,
                                                           length);
        }
        else
        {
            result = MTB_RSLT_SERIAL_MEMORY_ERR_UNSUPPORTED;
        }
    }
    result_mutex_rel = _mtb_serial_memory_mutex_release(obj);

    /* Give priority to the status of SMIF operation when both SMIF operation
     * and mutex release fail.
     */
    return ((CY_RSLT_SUCCESS == result) ? result_mutex_rel : result);
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_write
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_serial_memory_write(mtb_serial_memory_t* obj, uint32_t addr, size_t length,
                                  const uint8_t* buf)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    cy_rslt_t result_mutex_rel = CY_RSLT_SUCCESS;
    uint8_t memnum = _mtb_serial_memory_slaveslot_to_memnum(obj->chip_select);

    cy_rslt_t result = _mtb_serial_memory_mutex_acquire(obj);

    if (CY_RSLT_SUCCESS == result)
    {
        if ((obj->mem_info->flags & CY_SMIF_FLAG_SPI_DEVICE) != 0UL)
        {
            #if defined(_MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE)
            if (_MTB_SERIAL_MEMORY_IS_EVEN(addr) && _MTB_SERIAL_MEMORY_IS_EVEN(length))
            #endif /* if defined(_MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE) */
            {
                // Cy_SMIF_MemNumWrite() returns error if (addr + length) > total memory size.
                result =
                    (cy_rslt_t)Cy_SMIF_MemNumWrite(obj->mem_context, memnum, addr, buf, length);
            }
            #if defined(_MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE)
            else if (length == 1)
            {
                uint32_t full_addr = addr;
                if (!_MTB_SERIAL_MEMORY_IS_EVEN(addr))
                {
                    full_addr -= 1;
                }
                uint8_t full_buf[2];
                memset(full_buf, 0, sizeof(full_buf));
                size_t full_length = 2;

                result = mtb_serial_memory_read(obj, full_addr, full_length, full_buf);

                if (CY_RSLT_SUCCESS == result)
                {
                    if (_MTB_SERIAL_MEMORY_IS_EVEN(addr))
                    {
                        memcpy(&full_buf[0], buf, length);
                    }
                    else
                    {
                        memcpy(&full_buf[1], buf, length);
                    }
                    result = (cy_rslt_t)Cy_SMIF_MemNumWrite(obj->mem_context, memnum, full_addr,
                                                            full_buf, full_length);
                }
            }
            else
            {
                result = MTB_RSLT_SERIAL_MEMORY_ERR_UNSUPPORTED;
            }
            #endif /* if defined(_MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE) */
        }
        else if ((obj->mem_info->flags & CY_SMIF_FLAG_HYPERBUS_DEVICE) != 0UL)
        {
            result = (cy_rslt_t)Cy_SMIF_MemNumHyperBusWrite(obj->mem_context, memnum, addr, buf,
                                                            length);
        }
        else
        {
            result = MTB_RSLT_SERIAL_MEMORY_ERR_UNSUPPORTED;
        }
    }

    result_mutex_rel = _mtb_serial_memory_mutex_release(obj);
    /* Give priority to the status of SMIF operation when both SMIF operation
     * and mutex release fail.
     */
    return ((CY_RSLT_SUCCESS == result) ? result_mutex_rel : result);
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_erase
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_serial_memory_erase(mtb_serial_memory_t* obj, uint32_t addr, size_t length)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    cy_rslt_t result_mutex_rel = CY_RSLT_SUCCESS;
    uint8_t memnum = _mtb_serial_memory_slaveslot_to_memnum(obj->chip_select);

    cy_rslt_t result = _mtb_serial_memory_mutex_acquire(obj);

    if (CY_RSLT_SUCCESS == result)
    {
        if ((obj->mem_info->flags & CY_SMIF_FLAG_SPI_DEVICE) != 0UL)
        {
            // If the erase is for the entire chip, use chip erase command
            if ((addr == 0u) && (length == mtb_serial_memory_get_size(obj)))
            {
                result = (cy_rslt_t)Cy_SMIF_MemNumEraseChip(obj->mem_context, memnum);
            }
            else
            {
                // Cy_SMIF_MemEraseSector() returns error if (addr + length) > total memory size or
                // if
                // addr is not aligned to erase sector size or if (addr + length) is not aligned to
                // erase sector size.
                result =
                    (cy_rslt_t)Cy_SMIF_MemNumEraseSector(obj->mem_context, memnum, addr, length);
            }
        }
        else
        {
            result = MTB_RSLT_SERIAL_MEMORY_ERR_UNSUPPORTED;
        }
    }
    result_mutex_rel = _mtb_serial_memory_mutex_release(obj);

    /* Give priority to the status of SMIF operation when both SMIF operation
     * and mutex release fail.
     */
    return ((CY_RSLT_SUCCESS == result) ? result_mutex_rel : result);
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_enable_xip
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_serial_memory_enable_xip(mtb_serial_memory_t* obj, bool enable)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    if (enable)
    {
        Cy_SMIF_SetMode(obj->base, CY_SMIF_MEMORY);
    }
    else
    {
        Cy_SMIF_SetMode(obj->base, CY_SMIF_NORMAL);
    }

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_set_active_chip
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_serial_memory_set_active_chip(mtb_serial_memory_t* obj,
                                            mtb_serial_memory_chip_select_t chip_select)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    cy_rslt_t result = CY_RSLT_SUCCESS;
    if ((obj->configured_csel & chip_select) > 0)
    {
        for (uint32_t i = 0; i < obj->mem_context->block_config->memCount; i++)
        {
            if (obj->mem_context->block_config->memConfig[i]->slaveSelect ==
                (cy_en_smif_slave_select_t)chip_select)
            {
                obj->smif_active_slot = i;
                obj->chip_select = chip_select;
                break;
            }
        }
    }
    else
    {
        result = MTB_RSLT_SERIAL_MEMORY_ERR_BAD_PARAM;
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_get_chip_count
//--------------------------------------------------------------------------------------------------
uint32_t mtb_serial_memory_get_chip_count(mtb_serial_memory_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    return obj->mem_context->block_config->memCount;
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_get_active_chip
//--------------------------------------------------------------------------------------------------
uint32_t mtb_serial_memory_get_active_chip(mtb_serial_memory_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    return obj->chip_select;
}


//--------------------------------------------------------------------------------------------------
// mtb_serial_memory_set_write_enable
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_serial_memory_set_write_enable(mtb_serial_memory_t* obj, bool enable)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(_mtb_serial_memory_is_flag_set(obj, _MTB_SERIAL_MEMORY_FLAG_SETUP_DONE));
    if (enable)
    {
        return (cy_rslt_t)Cy_SMIF_MemCmdWriteEnable(obj->base,
                                                    obj->mem_context->block_config->memConfig[obj->
                                                                                              smif_active_slot],
                                                    &obj->mem_context->smif_context);
    }
    else
    {
        return (cy_rslt_t)Cy_SMIF_MemCmdWriteDisable(obj->base,
                                                     obj->mem_context->block_config->memConfig[obj->
                                                                                               smif_active_slot],
                                                     &obj->mem_context->smif_context);
    }
}


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXSMIF */
