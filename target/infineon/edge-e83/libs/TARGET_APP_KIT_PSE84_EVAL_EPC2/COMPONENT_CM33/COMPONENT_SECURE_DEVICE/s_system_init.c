/***************************************************************************//**
* \file s_system_init.c
* \version 1.0
*
* The device system-init file.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License")
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

#include <stdio.h>

void SystemInitStage2(void);


void SystemInitStage2(void)
{

    /* All system initialization code should go here. */
    /* - Unlocks and disables WDT.
     * - Calls Cy_PDL_Init() function to define the driver library.
     * - Calls the Cy_SystemInit() function, if compiled from PSoC Creator.
     * - Calls \ref SystemCoreClockUpdate().
     */
    //printf("\nSystem Init Stage 2\n");


    return;
}
