/*******************************************************************************
 * File Name: cycfg_dmas.c
 *
 * Description:
 * DMA configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.60.0
 * device-db 4.34.0.9502
 * mtb-dsl-pse8xxgp 1.2.0.895
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
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
 ******************************************************************************/

#include "cycfg_dmas.h"

const cy_stc_dma_descriptor_config_t CYBSP_DMA_TX_SPI_CONTROLLER_Descriptor_0_config =
{
    .retrigger = CY_DMA_RETRIG_IM,
    .interruptType = CY_DMA_DESCR,
    .triggerOutType = CY_DMA_1ELEMENT,
    .channelState = CY_DMA_CHANNEL_DISABLED,
    .triggerInType = CY_DMA_1ELEMENT,
    .dataSize = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType = CY_DMA_1D_TRANSFER,
    .srcAddress = NULL,
    .dstAddress = NULL,
    .srcXincrement = 1,
    .dstXincrement = 0,
    .xCount = 12,
    .srcYincrement = 0,
    .dstYincrement = 0,
    .yCount = 1,
    .nextDescriptor = &CYBSP_DMA_TX_SPI_CONTROLLER_Descriptor_0,
};
CY_SECTION(".cy_socmem_data") CY_ALIGN(8) cy_stc_dma_descriptor_t CYBSP_DMA_TX_SPI_CONTROLLER_Descriptor_0 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL,
};
const cy_stc_dma_channel_config_t CYBSP_DMA_TX_SPI_CONTROLLER_channelConfig =
{
    .descriptor = &CYBSP_DMA_TX_SPI_CONTROLLER_Descriptor_0,
    .preemptable = false,
    .priority = 3,
    .enable = false,
    .bufferable = false,
};
const cy_stc_dma_crc_config_t CYBSP_DMA_TX_SPI_CONTROLLER_crcConfig =
{
    .dataReverse = false,
    .dataXor = 0,
    .reminderReverse = false,
    .reminderXor = 0,
    .polynomial = 79764919,
};

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
const mtb_hal_dma_configurator_t CYBSP_DMA_TX_SPI_CONTROLLER_hal_config =
{
    .dma_type = MTB_HAL_DMA_DW,
    .channel = CYBSP_DMA_TX_SPI_CONTROLLER_CHANNEL,
    .dw_base = CYBSP_DMA_TX_SPI_CONTROLLER_HW,
    .dw_descriptor = &CYBSP_DMA_TX_SPI_CONTROLLER_Descriptor_0,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */
