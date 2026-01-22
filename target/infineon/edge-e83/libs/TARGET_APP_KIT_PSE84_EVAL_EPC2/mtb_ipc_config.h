/*******************************************************************************
* \file mtb_ipc_config.h
*
* \brief
* Configuration for the MTB Interprocessor Communication Library
*
*******************************************************************************
* \copyright
* Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
 * \addtogroup group_mtb_ipc_config MTB IPC Configuration
 * \{
 * The ModusToolbox Interprocessor communication library (MTB-IPC) requires reservation of IPC
 * channels and interrupts.
 * Please refer to device documentation for what channels and interrupts are available on the
 * device.
 * Reservation ensures that there is no overlap between libraries that use IPC.
 * By default, the only library that has a reservation is MTB-SRF and these values
 * must not be deleted for SRF to function correctly.
 *
 * This file is owned by the application.  The expectation is for the user to store channel and
 * interrupt reservations
 * as needed.  Should the user wish to use a middleware library that depends on MTB IPC,
 * the user can keep track of which channels and interrupts have been used here.
 */

#if defined(COMPONENT_MW_MTB_IPC)
#include "mtb_ipc.h"

#pragma once

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/** Define the channel used to set up the IPC instance set up for SRF operations*/
#define MTB_IPC_CHANNEL_SRF                          (MTB_IPC_CHAN_0)

/** Define Semaphore index used to initialize the IPC instance set up for SRF operations */
#define MTB_IPC_SEMA_NUM_SRF                         (0UL)

/** Define reserved semaphore IRQ for SRF operations on Relay core */
#define MTB_IPC_IRQ_SEMA_SRF_RELAY                   (MTB_IPC_IRQ_USER)

/** Define reserved semaphore IRQ for SRF operations on Relay core */
#define MTB_IPC_IRQ_QUEUE_SRF_RELAY                  (MTB_IPC_IRQ_USER + 1)

/** Define reserved semaphore IRQ for SRF operations on client core*/
#define MTB_IPC_IRQ_SEMA_SRF_CLIENT                  (MTB_IPC_IRQ_USER + 2)

/** Define reserved semaphore IRQ for SRF operations on client core*/
#define MTB_IPC_IRQ_QUEUE_SRF_CLIENT                 (MTB_IPC_IRQ_USER + 3)

#if defined(COMPONENT_MW_MTB_SRF)

/** IPC Read Semaphore number to be used by SRF IPC mailbox */
#define MTB_IPC_SEMA_NUM_SRF_MBOX_READ              (MTB_IPC_SEMA_NUM_SRF + 1)

/** IPC Write Semaphore number to be used by SRF IPC mailbox */
#define MTB_IPC_SEMA_NUM_SRF_MBOX_WRITE             (MTB_IPC_SEMA_NUM_SRF_MBOX_READ + 1)

/** (Inclusive) Start of Semaphore indexes reserved by SRF for requests */
#define MTB_IPC_SEMA_NUM_SRF_REQ_START              (MTB_IPC_SEMA_NUM_SRF_MBOX_WRITE + 1)

/** (Inclusive) End of Semaphore indexes reserved by SRF for requests,
 *  Default of pool size 3UL */
#define MTB_IPC_SEMA_NUM_SRF_REQ_END                (MTB_IPC_SEMA_NUM_SRF_REQ_START + 2UL)

/** Mailbox Index to use in SRF IPC messaging */
#define MTB_IPC_MBOX_IDX_SRF                        (0UL)
#endif // if defined(COMPONENT_MW_MTB_SRF)


#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

#endif // defined(COMPONENT_MW_MTB_IPC)

/** \} group_mtb_ipc_config */
