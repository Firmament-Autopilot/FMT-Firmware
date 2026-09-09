/***************************************************************************//**
* \file mtb_hal_syspm.h
*
* \brief
* Provides a high level interface for interacting with the Infineon power
* management configuration. This interface abstracts out the
* chip specific details. If any chip specific functionality is necessary, or
* performance is critical the low level functions can be used directly.
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
//" *SUSPEND-FORMATTING*"
/**
 * \addtogroup group_hal_syspm System Power Management
 * \ingroup group_hal
 * \{
 * Interface for changing power states and restricting when they are allowed.
 *
 * Supported MCU Power States:
 * * Active - This is the normal operating state of the MCU
 * * Sleep - In this state the MCU is no longer running. It can be woken up again
 * from an interrupt. This state is reached by calling \ref mtb_hal_syspm_sleep.
 * * Deep Sleep - In this state the MCU is no longer running. It can only be woken
 * up by select interrupts. This state is reached by calling \ref
 * mtb_hal_syspm_deepsleep.
 * * Hibernate-Ram - This is intended to further reduce the power consumption from
 * deepsleep while maintaining SRAM retention. This state is reached by calling \ref
 * mtb_hal_syspm_hibernate_ram. The device can only be woken up by select interrupts
 * and these can specified when entering the hibernate-ram using wakeup source
 * parameter available in \ref mtb_hal_syspm_hibernate_ram
 *
 * Some devices support multiple modes for the DeepSleep power state. The currently
 * selected DeepSleep mode, which will be entered by \ref mtb_hal_syspm_deepsleep,
 * can be determined via the \ref mtb_hal_syspm_get_deepsleep_mode function. Configuration
 * of the DeepSleep mode can be performed via platform specific APIs (e.g. PDL).
 *
 * \note The power management functionality available depends on the availability
 * of the features in the hardware. For detailed information about exactly what is
 * supported on each device, refer to the Device Datasheet or Technical Reference
 * Manual (TRM).
 *
 * Any time a power state transition is requested a series of callbacks are invoked.
 * This allows peripherals, or other parts of the application, to confirm they are
 * not currently doing something that would not work in the requested power state.
 * Middleware has the option to register a callback function(s) to be called on
 * requested state transitions by callling \ref mtb_hal_syspm_register_callback.
 * Each callback registered can specify the exact set of states
 * ( \ref mtb_hal_syspm_callback_state_t ) that it should be called for. Each callback
 * is invoked multiple times as part of the transition process as defined by
 * \ref mtb_hal_syspm_callback_mode_t.
 *
 * At any point the code can lock the ability to enter deep sleep by calling \ref
 * mtb_hal_syspm_lock_deepsleep. This should be done in critical blocks that need to
 * continue remain active. When the critical work is complete, and the lock is no
 * longer needed, it can be released by calling \ref mtb_hal_syspm_unlock_deepsleep.
 * The lock is a counter with a max count of USHRT_MAX. It must be locked/unlocked
 * an equal number of times before the device is actually able to enter deep sleep.
 *
 * \section section_syspm_features Features
 * This driver provides control over multiple different types of power management
 * and when those transitions are allowed:
 * * Change CPU Power State: APIs to allow changing the current CPU state into
 * one of the lower power CPU states (SLEEP, DEEPSLEEP,HIBERNATE-RAM)
 * * General Purpose Power State Transition Callback: APIs allow for
 * registering/unregistering a callback function to be notified when various power
 * state transitions happen. If registered, the application can do anything necessary
 * at power transitions. It can even prevent the transition if need-be.
 * - Lock DeepSleep: APIs to prevent/allow the CPU from going to deep sleep. This
 * is a convenience API rather than needing to implement a full Transition Callback
 * handler.
 *
 * \section section_syspm_quickstart Quick Start
 *
 * Unlike most HAL drivers this does not require initializing an instance object. The
 * APIs provided here can be called at anytime. See the snippets below for examples
 * of how to use this driver.
 *
 * \section section_syspm_snippets Code Snippets
 *
 * \subsection subsection_syspm_snippet_1 Snippet 1: Simple deep sleep locking
 * The following snippet shows how to use the deep sleep locking APIs to restrict
 * when the device can enter deep sleep. In between the lock/unlock calls any
 * attempt to change power modes will automatically be canceled.
 * \snippet hal_syspm.c snippet_mtb_hal_syspm_simple_locking
 *
 * \subsection subsection_syspm_snippet_2 Snippet 2: Calling different power state functions
 * The following snippet shows the different functions that exist to change power states
 * on the device and how they can each be called.
 * \snippet hal_syspm.c snippet_mtb_hal_syspm_power_transitions
 *
 * \subsection subsection_syspm_snippet_3 Snippet 3: Using callbacks for application power management
 * The following snippet shows how to use the callback mechanisms to manage whether
 * it is safe to enter low power modes.
 * \snippet hal_syspm.c snippet_mtb_hal_syspm_app_callback
 */
//" *RESUME-FORMATTING*"
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_general_types.h"
#include "mtb_hal_hw_types.h"
#include "mtb_hal_system.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_SYSPM)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_syspm SYSPM HAL Results
 *  SYSPM specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Incorrect argument passed into a function. */
#define MTB_HAL_SYSPM_RSLT_BAD_ARGUMENT               \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SYSPM, 0))
/** Failed to register callback */
#define MTB_HAL_SYSPM_RSLT_CB_REGISTER_ERROR          \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SYSPM, 1))
/** Deepsleep has been locked */
#define MTB_HAL_SYSPM_RSLT_DEEPSLEEP_LOCKED           \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SYSPM, 2))
/** The requested operation is not supported on the current hardware */
#define MTB_HAL_SYSPM_RSLT_ERR_NOT_SUPPORTED           \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SYSPM, 3))

/**
 * \}
 */

/** \cond INTERNAL */
/** Sentinel value to indicate end of callback list */
#define MTB_HAL_SYSPM_END_OF_LIST ((mtb_hal_syspm_callback_data_t*)0x789)
/** \endcond */

/** Enumeration of the system Deep Sleep modes. These modes are device specifc and
 * may not be supported on all devices. Refer to the device specific documentation
 * or the Data Sheet to determine what is allowed.
 */
typedef enum
{
    MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP_NONE,  /**< Not Deep Sleep Mode. */
    MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP,       /**< Deep Sleep Mode.     */
    MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP_RAM,   /**< Deep Sleep RAM Mode. */
    MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP_OFF    /**< Deep Sleep OFF Mode. */
} mtb_hal_syspm_system_deep_sleep_mode_t;

/** Flags enum for the cpu state in a custom callback. This is used to indicate what
 * states a callback should be called in. When a callback is called, only one of these
 * will be set at a time.
 */
typedef enum
{
    /** Flag for MCU sleep callback. */
    MTB_HAL_SYSPM_CB_CPU_SLEEP             = MTB_HAL_MAP_SYSPM_CB_SLEEP,
    /** Flag for MCU deep sleep callback. */
    MTB_HAL_SYSPM_CB_CPU_DEEPSLEEP         = MTB_HAL_MAP_SYSPM_CB_DEEPSLEEP,
    /** Flag for MCU deep sleep ram callback. */
    MTB_HAL_SYSPM_CB_CPU_DEEPSLEEP_RAM     = MTB_HAL_MAP_SYSPM_CB_DEEPSLEEP_RAM,
    /** Flag for Hibernate callback. */
    MTB_HAL_SYSPM_CB_SYSTEM_HIBERNATE      = MTB_HAL_MAP_SYSPM_CB_HIBERNATE,
    /** Flag for Normal mode callback. */
    MTB_HAL_SYSPM_CB_SYSTEM_NORMAL         = MTB_HAL_MAP_SYSPM_CB_NORMAL,
    /** Flag for Low power mode callback. */
    MTB_HAL_SYSPM_CB_SYSTEM_LOW            = MTB_HAL_MAP_SYSPM_CB_LOW,
    /** Flag for High Performance mode callback. */
    MTB_HAL_SYSPM_CB_SYSTEM_HIGH           = MTB_HAL_MAP_SYSPM_CB_HIGH,
    /** Flag for MCU Hibernate Ram callback. */
    MTB_HAL_SYSPM_CB_CPU_HIBERNATE_RAM     = MTB_HAL_MAP_SYSPM_CB_HIBERNATE_RAM
} mtb_hal_syspm_callback_state_t;

/** Enumeration of the transition modes in custom callback. The general sequence
 * is: CHECK_READY, BEFORE_TRANSITION, AFTER_TRANSITION.
 * If any callback indicates that it is not able to change state as part of
 * CHECK_READY, CHECK_FAIL will be run instead of the BEFORE/AFTER_TRANSITION.
 */
typedef enum
{
    /** Callbacks with this mode are executed before entering into the low power mode. The purpose
     * of this transition state is to check if the device is ready to enter the low power mode. The
     * application must not perform any actions that would prevent transition after returning true
     * for this mode. */
    MTB_HAL_SYSPM_CHECK_READY              = MTB_HAL_MAP_SYSPM_CHECK_READY,
    /** Callbacks with this mode are only executed if the callback returned true for
     * MTB_HAL_SYSPM_CHECK_READY and a later callback returns false for MTB_HAL_SYSPM_CHECK_READY.
     * This mode should roll back any changes made to avoid blocking transition made in
     * MTB_HAL_SYSPM_CHECK_READY mode*/
    MTB_HAL_SYSPM_CHECK_FAIL               = MTB_HAL_MAP_SYSPM_CHECK_FAIL,
    /** Callbacks with this mode are executed after the MTB_HAL_SYSPM_CHECK_READY callbacks'
     * execution returns true. In this mode, the callback must perform the actions to be done before
     * entering into the low power mode. */
    MTB_HAL_SYSPM_BEFORE_TRANSITION        = MTB_HAL_MAP_SYSPM_BEFORE_TRANSITION,
    /** In this mode, the application must perform the actions to be done after exiting the low
     * power mode. */
    MTB_HAL_SYSPM_AFTER_TRANSITION         = MTB_HAL_MAP_SYSPM_AFTER_TRANSITION,
    /** Performs the actions to be done after exiting the Deepsleep low power mode if entered and
     * before the interrupts are enabled. This mode is not invoked on all devices, see the
     * implementation specific documentation for details. */
    MTB_HAL_SYSPM_AFTER_DS_WFI_TRANSITION  = MTB_HAL_MAP_SYSPM_AFTER_DS_WFI_TRANSITION
} mtb_hal_syspm_callback_mode_t;

/** The system wide custom action power callback type.
 *
 * @param[in] state          State the system or CPU is being transitioned into.
 * @param[in] mode           Callback mode.
 * @param[in] callback_arg   User argument passed as part of registering callback.
 * @return If mode is @ref MTB_HAL_SYSPM_CHECK_READY, then this indicates whether the low power mode
 * should be allowed (true) or not (false).
          Otherwise the return value is ignored.
 */
typedef bool (* mtb_hal_syspm_callback_t)(mtb_hal_syspm_callback_state_t state,
                                          mtb_hal_syspm_callback_mode_t mode, void* callback_arg);

/** Power management callback data object. This is used to register a new
 * callback handler for power management transitions. The specific power
 * states to register for can be specified as well as any modes
 */
typedef struct mtb_hal_syspm_callback_data
{
    /** Callback to run on power state change */
    mtb_hal_syspm_callback_t              callback;
    /** Power states that should trigger calling the callback. */
    mtb_hal_syspm_callback_state_t        state;
    /** Modes to ignore invoking the callback for. Multiple
     * \ref mtb_hal_syspm_callback_mode_t values can be ored together. */
    mtb_hal_syspm_callback_mode_t         ignore_modes;
    /** Argument value to provide to the callback. */
    void* arg;
} mtb_hal_syspm_callback_params_t;

/** Register the specified handler with the power manager to be notified of power
 * state changes. This callback will be called before any of the peripheral callbacks
 * for \ref MTB_HAL_SYSPM_CHECK_READY and \ref MTB_HAL_SYSPM_BEFORE_TRANSITION.
 * \note The callback will be executed from a critical section
 *
 * @param[out] obj      The callback object. The caller must allocate the
 *                      memory for this object, but the HAL will populate its
 * @param[in] params    The paramers for the callback to register
 * @return CY_RSLT_SUCCESS if the callback was successfully registered, otherwise an error

 */
cy_rslt_t mtb_hal_syspm_register_callback(mtb_hal_syspm_callback_data_t* obj,
                                          mtb_hal_syspm_callback_params_t* params);

/** Removes the registered handler from the power manager so no future notifications are made.
 *
 * @param[in] obj The callback object to unregister.
 * @return CY_RSLT_SUCCESS if the callback was successfully unregistered, otherwise an error
 */
cy_rslt_t mtb_hal_syspm_unregister_callback(mtb_hal_syspm_callback_data_t* obj);

/** Set CPU to sleep mode.
 *
 * @return  Returns CY_RSLT_SUCCESS if the processor successfully entered the sleep mode ,
 * otherwise error.
 */
cy_rslt_t mtb_hal_syspm_sleep(void);

/** Set CPU to deep sleep mode.
 *
 * @return  Returns CY_RSLT_SUCCESS if the processor successfully entered the deep sleep mode,
 * otherwise error.
 */
cy_rslt_t mtb_hal_syspm_deepsleep(void);

/** Lock deep sleep.
 *
 * This function prevents the CPU from going to deep sleep. The lock is implemented as a counter
 * from 0 to USHRT_MAX. Each call to this function increments the counter by 1.
 * \ref mtb_hal_syspm_unlock_deepsleep must be called an equal number of times to fully unlock.
 * Deepsleep will only be allowed when the counter is equal to 0.
 */
void mtb_hal_syspm_lock_deepsleep(void);

/** Unlock deep sleep.
 *
 * This function decrements the lock counter by 1 and must be called an equal number of times as
 * @ref mtb_hal_syspm_lock_deepsleep is called to fully unlock. Deepsleep will only be allowed
 * when the counter is equal to 0.
 */
void mtb_hal_syspm_unlock_deepsleep(void);

/** Set CPU to hibernate-ram mode.
 *
 * @param[in] wakeup_source Wakeup source(s) to wake the device from hibernate-ram mode
 *
 * @return  Returns CY_RSLT_SUCCESS if the processor successfully entered the hibernate-ram mode,
 * otherwise error.
 *
 * @note  Hibernate Ram Mode shall be setup using the driver API Cy_SysPm_SetHibernateRamMode
 * before invoking this. Also make sure that wakeup source is configured to wakeup the device
 * from hibernate-ram
 */
cy_rslt_t mtb_hal_syspm_hibernate_ram(mtb_hal_syspm_hibernate_wakeup_source_t wakeup_source);

#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)

/** Timed hibernate-ram sleep without system timer.
 *
 * Provides a way to do hibernate-ram sleep for a desired number of milliseconds(ms) with the system
 * timer
 * disabled.
 * The system timer is disabled before sleeping and a low power timer is setup to wake
 * the device from hib-ram after the desired number of ms have elapsed.
 *
 * @note The actual ms in the best case will be 1 ms less than the desired time to
 * prevent the device from over-sleeping due to low clock accuracy.
 *
 * @param[in]   lptimer_obj Pre-Initialized LPTimer object.
 * @param[in]   wakeup_source Wakeup source(s) to wake the device from hibernate-ram mode
 * @param[in]   desired_ms  Desired number of ms to perform hib-ram sleep.
 * @param[out]  actual_ms   Actual number of ms in which systick timer was disabled.
 *                          This value can range from 0 to desired_ms - 1
 *                          depending on how long the device was able to  perform hib-ram sleep.
 * @return The status of the hib-ram sleep request.
 */
cy_rslt_t mtb_hal_syspm_tickless_hibernate_ram(mtb_hal_lptimer_t* lptimer_obj,
                                               mtb_hal_syspm_hibernate_wakeup_source_t wakeup_source,
                                               uint32_t desired_ms, uint32_t* actual_ms);

/** Timed deep-sleep without system timer.
 *
 * Provides a way to deep-sleep for a desired number of milliseconds(ms) with the system timer
 * disabled.
 * The system timer is disabled before sleeping and a low power timer is setup to wake
 * the device from deep-sleep after the desired number of ms have elapsed.
 *
 * @note The actual ms in the best case will be 1 ms less than the desired time to
 * prevent the device from over-sleeping due to low clock accuracy.
 *
 * @param[in]   lptimer_obj Pre-Initialized LPTimer object.
 * @param[in]   desired_ms  Desired number of ms to deep-sleep.
 * @param[out]  actual_ms   Actual number of ms in which systick timer was disabled.
 *                          This value can range from 0 to desired_ms - 1
 *                          depending on how long the device was able to deep-sleep.
 * @return The status of the deep-sleep request.
 */
cy_rslt_t mtb_hal_syspm_tickless_deepsleep(mtb_hal_lptimer_t* lptimer_obj, uint32_t desired_ms,
                                           uint32_t* actual_ms);

/** Timed sleep without system timer.
 *
 * Provides a way to sleep for a desired number of milliseconds(ms) with the system timer disabled.
 * The system timer is disabled before sleeping and a low power timer is setup to wake
 * the device from sleep after the desired number of ms have elapsed.
 *
 * @note The actual ms in the best case will be 1 ms less than the desired time to
 * prevent the device from over-sleeping due to low clock accuracy.
 *
 * @param[in]   lptimer_obj Pre-Initialized LPTimer object.
 * @param[in]   desired_ms  Desired number of ms to sleep.
 * @param[out]  actual_ms   Actual number of ms that was spent in sleep.
 *                          This value can range from 0 to desired_ms - 1
 *                          depending on how long the device was able to sleep.
 * @return The status of the sleep request.
 */
cy_rslt_t mtb_hal_syspm_tickless_sleep(mtb_hal_lptimer_t* lptimer_obj, uint32_t desired_ms,
                                       uint32_t* actual_ms);

#endif /* (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0) */

/** Get current deep sleep mode.
 *
 * Provides a way to get the current deep sleep mode.
 * @return The current deep sleep mode.
 */
mtb_hal_syspm_system_deep_sleep_mode_t mtb_hal_syspm_get_deepsleep_mode(void);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_SYSPM_IMPL_HEADER
#include MTB_HAL_SYSPM_IMPL_HEADER
#endif /* MTB_HAL_SYSTEM_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_SYSPM)

/** \} group_hal_system */
