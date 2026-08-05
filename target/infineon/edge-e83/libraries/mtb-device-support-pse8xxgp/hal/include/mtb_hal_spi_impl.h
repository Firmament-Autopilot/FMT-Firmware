/***************************************************************************//**
* \file mtb_hal_spi_impl.h
*
* Description:
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

#pragma once

#include "mtb_hal_spi.h"
#include "mtb_hal_utils.h"
#include "mtb_hal_system.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Defines
*******************************************************************************/
#define _MTB_HAL_SPI_PENDING_NONE             0
#define _MTB_HAL_SPI_PENDING_RX               1
#define _MTB_HAL_SPI_PENDING_TX               2
#define _MTB_HAL_SPI_PENDING_TX_RX            3

/*******************************************************************************
*       Functions
*******************************************************************************/
/** Initialize the SPI Object.
 *
 * \note The application is responsible for initializing HAL objects
 *
 * @param[out] obj           Pointer to a SPI object. The caller must allocate
 *                           the memory for this object, but the init function will
 *                           initialize its contents.
 * @param[in] config         The configurator-generated HAL config structure for this
 *                           peripheral instance
 * @param[in]  context       Pointer to the SPI context structure. This is the context
 *                           structure passed when doing the SPI Driver HW Initialization
 * @param[in]  clock         The clock used by the SPI peripheral. Application shall allocate
 *                           and enable the clock
 * @return The status of the init request
 */
cy_rslt_t mtb_hal_spi_setup(mtb_hal_spi_t* obj, const mtb_hal_spi_configurator_t* config,
                            cy_stc_scb_spi_context_t* context, const mtb_hal_clock_t* clock);


/** Checks if the specified SPI peripheral is in use
 *
 * @param[in] obj         The SPI object
 * @return Indication of whether the SPI is still transmitting
 */
__STATIC_INLINE bool mtb_hal_spi_is_busy(mtb_hal_spi_t* obj)
{
    return Cy_SCB_SPI_IsBusBusy(obj->base) || (_MTB_HAL_SPI_PENDING_NONE != obj->pending);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_spi_enable
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_spi_enable(mtb_hal_spi_t* obj, bool enable)
{
    enable ? Cy_SCB_SPI_Enable(obj->base) : Cy_SCB_SPI_Disable(obj->base, obj->context);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_spi_enable _mtb_hal_spi_enable

//--------------------------------------------------------------------------------------------------
// mtb_hal_spi_set_fifo_level_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t mtb_hal_spi_set_fifo_level_internal(mtb_hal_spi_t* obj,
                                                              mtb_hal_spi_fifo_type_t type,
                                                              uint16_t level)
{
    if (type == MTB_HAL_SPI_FIFO_RX)
    {
        Cy_SCB_SetRxFifoLevel(obj->base, level);
        return CY_RSLT_SUCCESS;
    }
    else if (type == MTB_HAL_SPI_FIFO_TX)
    {
        Cy_SCB_SetTxFifoLevel(obj->base, level);
        return CY_RSLT_SUCCESS;
    }

    return MTB_HAL_SPI_RSLT_BAD_ARGUMENT;
}


#define mtb_hal_spi_set_fifo_level(obj, type, \
                                   level) mtb_hal_spi_set_fifo_level_internal(obj, type, level)

#if defined(__cplusplus)
}
#endif /* __cplusplus */
