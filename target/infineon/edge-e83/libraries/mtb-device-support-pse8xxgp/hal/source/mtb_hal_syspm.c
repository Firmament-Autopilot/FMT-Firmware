/***************************************************************************//**
* \file mtb_hal_syspm.c
*
* \brief
* Provides a high level interface for interacting with the Infineon power
* management and system clock configuration. This interface abstracts out the
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
#include <limits.h>
#include <string.h>
#include "cy_syspm.h"
#include "cy_utils.h"
#include "mtb_hal_system.h"
#include "mtb_hal_syspm.h"
#include "mtb_hal_utils.h"

#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)
#include "mtb_hal_lptimer.h"
#endif /* (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0) */

#if (MTB_HAL_DRIVER_AVAILABLE_SYSPM)

#if defined(__cplusplus)
extern "C"
{
#endif

/* Disable the SysTick */
#define _mtb_hal_syspm_disable_systick() (SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk)

/* Enable the SysTick */
#define _mtb_hal_syspm_enable_systick()  (SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk)

/* Default to running callbacks relatively early, but still allow critical items
 * to be manually specified to run even earlier
 */
#define _MTB_HAL_SYSPM_CALLBACK_ORDER    (10u)

cy_stc_syspm_callback_params_t _mtb_hal_syspm_cb_params_default = { NULL, NULL };
static uint16_t _mtb_hal_syspm_deepsleep_lock = 0;

#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)
/* State for pre-deep-sleep LPTimer handling */
typedef struct
{
    mtb_hal_lptimer_t* lptimer;
    uint32_t desired_sleep_ms;
    #if defined(MTB_HAL_SYSPM_DEBUG_TICKLESS)
    uint32_t pre_sleep_ticks;
    uint32_t post_sleep_ticks
    uint32_t actual_sleep_ms;
    #endif
} _mtb_hal_syspm_lptimer_context_t;

static _mtb_hal_syspm_lptimer_context_t _mtb_hal_syspm_lptimer_context;
#endif // if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_check_ds_lock
//--------------------------------------------------------------------------------------------------
static cy_en_syspm_status_t _mtb_hal_syspm_check_ds_lock(cy_stc_syspm_callback_params_t* params,
                                                         cy_en_syspm_callback_mode_t mode)
{
    /* This callback is configured to be only called for check ready */
    CY_UNUSED_PARAMETER(mode);
    CY_UNUSED_PARAMETER(params);
    return (_mtb_hal_syspm_deepsleep_lock == 0u) ? CY_SYSPM_SUCCESS : CY_SYSPM_FAIL;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_ensure_cb_registered_dslock
//--------------------------------------------------------------------------------------------------
void _mtb_hal_syspm_ensure_cb_registered_dslock(void)
{
    static bool registered_cb = false;
    static cy_stc_syspm_callback_t cb_deepsleep =
    {
        .callback       = _mtb_hal_syspm_check_ds_lock,
        .type           = CY_SYSPM_DEEPSLEEP,
        // We only care about CHECK_READY so we can block DeepSleep if it's locked
        .skipMode       =
            (CY_SYSPM_SKIP_BEFORE_TRANSITION | CY_SYSPM_SKIP_AFTER_TRANSITION |
             CY_SYSPM_SKIP_CHECK_FAIL),
        .callbackParams = &_mtb_hal_syspm_cb_params_default,
        .prevItm        = NULL,
        .nextItm        = NULL,
        .order          = 0u, /* Check for locked before anything else */
    };
    bool intr_status = mtb_hal_system_critical_section_enter();
    if (false == registered_cb)
    {
        registered_cb = true;
        bool newly_registered = Cy_SysPm_RegisterCallback(&cb_deepsleep);
        // We only try the registration once, so the PDL should never report false
        CY_ASSERT(newly_registered);
        CY_UNUSED_PARAMETER(newly_registered);
    }
    mtb_hal_system_critical_section_exit(intr_status);
}


#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_handle_lptimer
//--------------------------------------------------------------------------------------------------
cy_en_syspm_status_t _mtb_hal_syspm_handle_lptimer(cy_stc_syspm_callback_params_t* params,
                                                   cy_en_syspm_callback_mode_t mode)
{
    CY_UNUSED_PARAMETER(params);
    cy_en_syspm_status_t result = CY_SYSPM_SUCCESS;

    if (NULL != _mtb_hal_syspm_lptimer_context.lptimer)
    {
        uint32_t desired_ms = _mtb_hal_syspm_lptimer_context.desired_sleep_ms;
        mtb_hal_lptimer_t* lptimer = _mtb_hal_syspm_lptimer_context.lptimer;
        if (CY_SYSPM_BEFORE_TRANSITION == mode)
        {
            // LPTimer is driven by clk_lf
            uint32_t lptimer_frequency_hz = lptimer->lfclk_freqhz;

            // lp_ticks = ms * lp_rate_khz
            uint32_t sleep_ticks = _MTB_HAL_UTILS_HZ_TO_KHZ(
                ((uint64_t)(desired_ms - 1)) * lptimer_frequency_hz);
            mtb_hal_lptimer_enable_event(lptimer, MTB_HAL_LPTIMER_COMPARE_MATCH, true);
            result = (cy_en_syspm_status_t)mtb_hal_lptimer_set_delay(lptimer, sleep_ticks);
            CY_ASSERT(CY_RSLT_SUCCESS == result);

            #if defined(MTB_HAL_SYSPM_DEBUG_TICKLESS)
            _mtb_hal_syspm_lptimer_context.pre_sleep_ticks = mtb_hal_lptimer_read(lptimer);
            #endif
        }
        else if (CY_SYSPM_AFTER_TRANSITION == mode)
        {
            #if defined(MTB_HAL_SYSPM_DEBUG_TICKLESS)
            /* Compute time spent actually in DeepSleep state, for debugging */
            uint32_t pre_sleep_ticks = _mtb_hal_syspm_lptimer_context.pre_sleep_ticks;
            uint32_t post_sleep_ticks = mtb_hal_lptimer_read(lptimer);
            uint32_t ticks = (post_sleep_ticks < pre_sleep_ticks)
                ? (_MTB_HAL_LPTIMER_MAX_DELAY_TICKS - pre_sleep_ticks) + post_sleep_ticks
                : post_sleep_ticks - pre_sleep_ticks;
            _mtb_hal_syspm_lptimer_context.post_sleep_ticks = post_sleep_ticks;

            _mtb_hal_syspm_lptimer_context.actual_sleep_ms =
                (uint32_t)(_MTB_HAL_UTILS_KHZ_TO_HZ(ticks) / lptimer_frequency_hz);
            #endif // if defined(MTB_HAL_SYSPM_DEBUG_TICKLESS)
            mtb_hal_lptimer_enable_event(lptimer, MTB_HAL_LPTIMER_COMPARE_MATCH, false);
            // Null out the lptimer so that the next DeepSleep attempt doesn't
            // attempt to reuse these values, which are no longer applicable
            // Leave the rest around for debugging purposes
            _mtb_hal_syspm_lptimer_context.lptimer = NULL;
        }
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_ensure_cb_registered_lptimer
//--------------------------------------------------------------------------------------------------
void _mtb_hal_syspm_ensure_cb_registered_lptimer(void)
{
    static bool registered_cb = false;
    static cy_stc_syspm_callback_t cb_deepsleep =
    {
        .callback       = _mtb_hal_syspm_handle_lptimer,
        .type           = CY_SYSPM_DEEPSLEEP,
        // We need to start the LPTimer before transition and stop it after the transition
        .skipMode       = (CY_SYSPM_SKIP_CHECK_READY | CY_SYSPM_SKIP_CHECK_FAIL),
        .callbackParams = &_mtb_hal_syspm_cb_params_default,
        .prevItm        = NULL,
        .nextItm        = NULL,
        /* We want this to be the last to run before DeepSleep entry, so that the LPTimer
         * delay corresponds as closely as possible to the actual time asleep. This also
         * means this will be the first to run on wakeup, which is also what we want
         * so that we can accurately capture the time spent actually asleep for debugging
         */
        .order          = 255u,
    };

    static cy_stc_syspm_callback_t cb_sleep =
    {
        .callback       = _mtb_hal_syspm_handle_lptimer,
        .type           = CY_SYSPM_SLEEP,
        // We need to start the LPTimer before transition and stop it after the transition
        .skipMode       = (CY_SYSPM_SKIP_CHECK_READY | CY_SYSPM_SKIP_CHECK_FAIL),
        .callbackParams = &_mtb_hal_syspm_cb_params_default,
        .prevItm        = NULL,
        .nextItm        = NULL,
        /* We want this to be the last to run before DeepSleep entry, so that the LPTimer
         * delay corresponds as closely as possible to the actual time asleep. This also
         * means this will be the first to run on wakeup, which is also what we want
         * so that we can accurately capture the time spent actually asleep for debugging
         */
        .order          = 255u,
    };

    bool intr_status = mtb_hal_system_critical_section_enter();
    if (false == registered_cb)
    {
        registered_cb = true;

        memset(&_mtb_hal_syspm_lptimer_context, 0u, sizeof(_mtb_hal_syspm_lptimer_context));
        bool newly_registered = Cy_SysPm_RegisterCallback(&cb_deepsleep);
        // We only try the registration once, so the PDL should never report false
        CY_ASSERT(newly_registered);

        newly_registered = _mtb_hal_syspm_ensure_cb_registered_dsram_lptimer();
        CY_ASSERT(newly_registered);

        newly_registered = Cy_SysPm_RegisterCallback(&cb_sleep);
        CY_ASSERT(newly_registered);

        CY_UNUSED_PARAMETER(newly_registered);
    }
    mtb_hal_system_critical_section_exit(intr_status);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_tickless_setup
//--------------------------------------------------------------------------------------------------
static inline void _mtb_hal_syspm_tickless_setup(mtb_hal_lptimer_t* lptimer,
                                                 uint32_t desired_sleep_ms)
{
    _mtb_hal_syspm_ensure_cb_registered_lptimer();
    _mtb_hal_syspm_lptimer_context.lptimer          = lptimer;
    _mtb_hal_syspm_lptimer_context.desired_sleep_ms = desired_sleep_ms;
    #if defined(MTB_HAL_SYSPM_DEBUG_TICKLESS)
    _mtb_hal_syspm_lptimer_context.pre_sleep_ticks  = 0u;
    _mtb_hal_syspm_lptimer_context.post_sleep_ticks = 0u;
    _mtb_hal_syspm_lptimer_context.actual_sleep_ms  = 0u;
    #endif
}


#endif // (MTB_HAL_SYSPM_AVAILABLE_LPTIMER)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_cb_wrapper
//--------------------------------------------------------------------------------------------------
static cy_en_syspm_status_t _mtb_hal_syspm_cb_wrapper(
    cy_stc_syspm_callback_params_t* callback_params, cy_en_syspm_callback_mode_t mode)
{
    // We don't have a traditional "base address" here, so we repurpose that to store the
    // user CB address, and store the HAL object pointer in the `context` member
    mtb_hal_syspm_callback_t user_callback  = (mtb_hal_syspm_callback_t)callback_params->base;
    mtb_hal_syspm_callback_data_t* cb_data  =
        (mtb_hal_syspm_callback_data_t*)callback_params->context;
    // We store this as a uint32_t on the HAL object to avoid circular includes
    mtb_hal_syspm_callback_state_t state    = (mtb_hal_syspm_callback_state_t)cb_data->state;
    // mtb_hal_pdl_map ensures this value can be directly cast
    mtb_hal_syspm_callback_mode_t  hal_mode = (mtb_hal_syspm_callback_mode_t)mode;
    void*                          cb_arg   = cb_data->user_arg;
    bool result = user_callback(state, hal_mode, cb_arg);
    return result ? CY_SYSPM_SUCCESS : CY_SYSPM_FAIL;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_deepsleep_internal
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_syspm_deepsleep_internal(void)
{
    return Cy_SysPm_CpuEnterDeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_syspm_register_callback
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_syspm_register_callback(mtb_hal_syspm_callback_data_t* obj,
                                          mtb_hal_syspm_callback_params_t* params)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(params != NULL);
    memset(obj, 0u, sizeof(mtb_hal_syspm_callback_data_t));
    // Populate PDL-level params
    obj->pdl_cb.callback = _mtb_hal_syspm_cb_wrapper;
    // We store this as a uint32_t on the HAL object to avoid circular includes
    obj->pdl_cb.type = (cy_en_syspm_callback_type_t)params->state;
    obj->pdl_cb.skipMode = (cy_en_syspm_callback_mode_t)params->ignore_modes;
    obj->pdl_cb.order = _MTB_HAL_SYSPM_CALLBACK_ORDER;
    obj->pdl_cb.callbackParams = &(obj->cb_params);
    // We don't have a traditional "base address" here, so we repurpose that to store the
    // user CB address, and store the HAL object pointer in the `context` member
    obj->cb_params.base = (void*)params->callback;
    obj->cb_params.context = obj;

    obj->user_arg = params->arg;
    obj->state = (uint32_t)params->state;
    bool registered = Cy_SysPm_RegisterCallback(&obj->pdl_cb);
    return registered ? CY_RSLT_SUCCESS : MTB_HAL_SYSPM_RSLT_CB_REGISTER_ERROR;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_syspm_unregister_callback
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_syspm_unregister_callback(mtb_hal_syspm_callback_data_t* obj)
{
    bool unregistered = Cy_SysPm_UnregisterCallback(&obj->pdl_cb);
    return unregistered ? CY_RSLT_SUCCESS : MTB_HAL_SYSPM_RSLT_CB_REGISTER_ERROR;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_syspm_lock_deepsleep
//--------------------------------------------------------------------------------------------------
void mtb_hal_syspm_lock_deepsleep(void)
{
    _mtb_hal_syspm_ensure_cb_registered_dslock();
    CY_ASSERT(_mtb_hal_syspm_deepsleep_lock != USHRT_MAX);
    uint32_t intr_status = mtb_hal_system_critical_section_enter();
    _mtb_hal_syspm_deepsleep_lock++;
    mtb_hal_system_critical_section_exit(intr_status);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_syspm_unlock_deepsleep
//--------------------------------------------------------------------------------------------------
void mtb_hal_syspm_unlock_deepsleep(void)
{
    CY_ASSERT(_mtb_hal_syspm_deepsleep_lock != 0U);
    uint32_t intr_status = mtb_hal_system_critical_section_enter();
    _mtb_hal_syspm_deepsleep_lock--;
    mtb_hal_system_critical_section_exit(intr_status);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_syspm_deepsleep
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_syspm_deepsleep(void)
{
    if (_mtb_hal_syspm_deepsleep_lock != 0)
    {
        return MTB_HAL_SYSPM_RSLT_DEEPSLEEP_LOCKED;
    }
    return _mtb_hal_syspm_deepsleep_internal();
}


#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_tickless_timer_presleep
//--------------------------------------------------------------------------------------------------
void _mtb_hal_syspm_tickless_timer_presleep(mtb_hal_lptimer_t* obj, uint32_t desired_ms,
                                            uint32_t* initial_ticks)
{
    _mtb_hal_syspm_tickless_setup(obj, desired_ms);
    _mtb_hal_syspm_disable_systick();
    *initial_ticks = mtb_hal_lptimer_read(obj);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_tickless_timer_postsleep
//--------------------------------------------------------------------------------------------------
void _mtb_hal_syspm_tickless_timer_postsleep(mtb_hal_lptimer_t* obj, uint32_t* initial_ticks,
                                             uint32_t* actual_ms)
{
    /* We need to do the following steps whether or not the DeepSleep entry succeeded */
    uint32_t final_ticks = mtb_hal_lptimer_read(obj);
    _mtb_hal_syspm_enable_systick();
    uint32_t lptimer_frequency_hz = obj->lfclk_freqhz;
    /* Total Idle ticks, handling rollover */
    uint32_t idle_ticks = (final_ticks < *initial_ticks)
                    ? (_MTB_HAL_LPTIMER_MAX_DELAY_TICKS - *initial_ticks) + final_ticks
                    : final_ticks - *initial_ticks;
    /* To avoid precision loss due to truncation, convert the idle ticks to hz first, then
        divide */
    uint64_t idle_ticks_hz = _MTB_HAL_UTILS_KHZ_TO_HZ(idle_ticks);
    *actual_ms = (uint32_t)(idle_ticks_hz / lptimer_frequency_hz);
}


#endif /* (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0) */

//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_tickless_sleep_deepsleep
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_syspm_tickless_sleep_deepsleep(mtb_hal_lptimer_t* obj, uint32_t desired_ms,
                                                  uint32_t* actual_ms, bool deep_sleep)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    if ((deep_sleep == true) && (_mtb_hal_syspm_deepsleep_lock != 0))
    {
        return MTB_HAL_SYSPM_RSLT_DEEPSLEEP_LOCKED;
    }

    #if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)
    CY_ASSERT(obj != NULL);
    *actual_ms = 0;
    uint32_t initial_ticks = 0;

    if (desired_ms > 1)
    {
        _mtb_hal_syspm_tickless_timer_presleep(obj, desired_ms, &initial_ticks);
        if (result == CY_RSLT_SUCCESS)
        {
            result = deep_sleep ? _mtb_hal_syspm_deepsleep_internal() : mtb_hal_syspm_sleep();
        }
        _mtb_hal_syspm_tickless_timer_postsleep(obj, &initial_ticks, actual_ms);
    }
    #else // if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)
    /* no lptimer available on currently selected device */
    result = MTB_HAL_SYSPM_RSLT_ERR_NOT_SUPPORTED;
    CY_UNUSED_PARAMETER(obj);
    CY_UNUSED_PARAMETER(desired_ms);
    CY_UNUSED_PARAMETER(actual_ms);
    CY_UNUSED_PARAMETER(deep_sleep);
    #endif /* (MTB_HAL_DRIVER_AVAILABLE_LPTIMER) */

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_syspm_get_deepsleep_mode
//--------------------------------------------------------------------------------------------------
mtb_hal_syspm_system_deep_sleep_mode_t mtb_hal_syspm_get_deepsleep_mode(void)
{
    mtb_hal_syspm_system_deep_sleep_mode_t deep_sleep_mode = MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP;
    #if defined(_MTB_HAL_SYSPM_SUPPORTS_DS_MODES)
    cy_en_syspm_deep_sleep_mode_t mode = _mtb_hal_syspm_get_pdl_dsmode();
    switch (mode)
    {
        case CY_SYSPM_MODE_DEEPSLEEP:
            deep_sleep_mode = MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP;
            break;

        case CY_SYSPM_MODE_DEEPSLEEP_RAM:
            deep_sleep_mode = MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP_RAM;
            break;

        case CY_SYSPM_MODE_DEEPSLEEP_OFF:
            deep_sleep_mode = MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP_OFF;
            break;

        case CY_SYSPM_MODE_DEEPSLEEP_NONE:
            deep_sleep_mode = MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP_NONE;
            break;

        default:
            deep_sleep_mode = MTB_HAL_SYSPM_SYSTEM_DEEPSLEEP_NONE;
            break;
    }
    #endif // defined(_MTB_HAL_SYSPM_SUPPORTS_DS_MODES)

    return deep_sleep_mode;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_syspm_hibernate_ram
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_syspm_hibernate_ram(mtb_hal_syspm_hibernate_wakeup_source_t wakeup_source)
{
    #if defined(_MTB_HAL_SYSPM_SUPPORTS_HIB_RAM_MODE)
    Cy_SysPm_SetHibernateWakeupSource(wakeup_source);
    return Cy_SysPm_SystemEnterHibernateRam(CY_SYSPM_WAIT_FOR_INTERRUPT);
    #else
    CY_UNUSED_PARAMETER(wakeup_source);
    return MTB_HAL_SYSPM_RSLT_ERR_NOT_SUPPORTED;
    #endif // defined(_MTB_HAL_SYSPM_SUPPORTS_HIB_RAM_MODE)
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_syspm_tickless_hibernate_ram
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_syspm_tickless_hibernate_ram(mtb_hal_lptimer_t* lptimer_obj,
                                               mtb_hal_syspm_hibernate_wakeup_source_t wakeup_source,
                                               uint32_t desired_ms, uint32_t* actual_ms)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    #if defined(_MTB_HAL_SYSPM_SUPPORTS_HIB_RAM_MODE) && (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)
    CY_ASSERT(lptimer_obj != NULL);
    *actual_ms = 0;
    uint32_t initial_ticks = 0;

    if (desired_ms > 1)
    {
        _mtb_hal_syspm_tickless_timer_presleep(lptimer_obj, desired_ms, &initial_ticks);
        result = mtb_hal_syspm_hibernate_ram(wakeup_source);
        _mtb_hal_syspm_tickless_timer_postsleep(lptimer_obj, &initial_ticks, actual_ms);
    }
    #else \
    // defined(_MTB_HAL_SYSPM_SUPPORTS_HIB_RAM_MODE) && (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)
    /* hibernate ram support and/or lptimer not available on currently selected device */
    result = MTB_HAL_SYSPM_RSLT_ERR_NOT_SUPPORTED;
    CY_UNUSED_PARAMETER(lptimer_obj);
    CY_UNUSED_PARAMETER(wakeup_source);
    CY_UNUSED_PARAMETER(desired_ms);
    CY_UNUSED_PARAMETER(actual_ms);
    #endif \
    /* defined(_MTB_HAL_SYSPM_SUPPORTS_HIB_RAM_MODE) && (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0) */

    return result;
}


#if defined(__cplusplus)
}
#endif

#endif // MTB_HAL_DRIVER_AVAILABLE_SYSPM
