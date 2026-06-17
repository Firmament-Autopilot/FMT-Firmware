/***************************************************************************//**
* \file mtb_hal_irq_impl.h
*
* \brief
* Provides internal utility functions for working with interrupts
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
#include "cy_result.h"
#include "cy_sysint.h"

/* System IRQ refers to signals that peripherals produce to request and interrupt,
 * which may or may not correspond 1:1 to the CPU IRQ lines */
#if defined(CPUSS_SYSTEM_IRQ_PRESENT)
#define _MTB_HAL_IRQ_MUXING (CY_CPU_CORTEX_M0P || CPUSS_SYSTEM_IRQ_PRESENT)
#elif defined(CY_DEVICE_PSOC6ABLE2)
#define _MTB_HAL_IRQ_MUXING (CY_CPU_CORTEX_M0P)
#else
#define _MTB_HAL_IRQ_MUXING (0)
#endif
