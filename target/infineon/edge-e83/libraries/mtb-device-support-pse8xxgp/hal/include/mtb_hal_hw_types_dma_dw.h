/***************************************************************************//**
* \file mtb_hal_hw_types_dma_dw.h
*
*********************************************************************************
* \copyright
* Copyright(c) 2024-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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

#include "cy_pdl.h"

#if defined(CY_IP_M4CPUSS_DMA) || defined(CY_IP_M7CPUSS_DMA) || defined(CY_IP_MXDW)

#if !defined(_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)
#define _MTB_HAL_DRIVER_AVAILABLE_DMA_DW (1u)
#endif // !defined(_MTB_HAL_DRIVER_AVAILABLE_DMA_DW)


typedef cy_stc_dma_descriptor_t _mtb_hal_dw_descriptor_t;
typedef DW_Type                 _mtb_hal_dw_base_t;

#endif // defined(CY_IP_M4CPUSS_DMA) || defined(CY_IP_M7CPUSS_DMA) || defined(CY_IP_MXDW)
