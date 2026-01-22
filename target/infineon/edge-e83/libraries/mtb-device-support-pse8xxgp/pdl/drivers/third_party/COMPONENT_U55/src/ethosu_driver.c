/*
 * SPDX-FileCopyrightText: Copyright 2019-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/******************************************************************************
 * Includes
 ******************************************************************************/
#include "ethosu_driver.h"
#include "ethosu_device.h"
#include "ethosu_log.h"

#if defined(ETHOSU55)
#include "ethosu_config_u55.h"
#elif defined(ETHOSU65)
#include "ethosu_config_u65.h"
#elif defined(ETHOSU85)
#include "ethosu_config_u85.h"
#else
#error Missing device type macro
#endif

#include <assert.h>
#include "cy_syslib.h"
#include <cmsis_compiler.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 * Defines
 ******************************************************************************/

#define UNUSED(x) ((void)x)

#define BYTES_IN_32_BITS 4
#define MASK_16_BYTE_ALIGN (0xF)
#define OPTIMIZER_CONFIG_LENGTH_32_BIT_WORD 2
#define DRIVER_ACTION_LENGTH_32_BIT_WORD 1
#define ETHOSU_FOURCC ('1' << 24 | 'P' << 16 | 'O' << 8 | 'C') // "Custom Operator Payload 1"

#define FAST_MEMORY_BASE_ADDR_INDEX 2

/******************************************************************************
 * Types
 ******************************************************************************/

// Driver actions
enum DRIVER_ACTION_e
{
    RESERVED         = 0,
    OPTIMIZER_CONFIG = 1,
    COMMAND_STREAM   = 2,
    NOP              = 5,
};

// Custom operator payload data struct
struct cop_data_s
{
    union
    {
        // Driver action data
        struct
        {
            uint8_t driver_action_command; // (valid values in DRIVER_ACTION_e)
            uint8_t reserved;

            // Driver action data
            union
            {
                // DA_CMD_OPT_CFG
                struct
                {
                    uint16_t rel_nbr : 4;
                    uint16_t patch_nbr : 4;
                    uint16_t opt_cfg_reserved : 8;
                };

                // DA_CMD_CMSTRM
                struct
                {
                    uint16_t length;
                };

                uint16_t driver_action_data;
            };
        };

        uint32_t word;
    };
};

// optimizer config struct
struct opt_cfg_s
{
    struct cop_data_s da_data;
    uint32_t cfg;
    uint32_t id;
};

/******************************************************************************
 * Variables
 ******************************************************************************/

// Registered drivers linked list HEAD
static struct ethosu_driver *registered_drivers = NULL;

/******************************************************************************
 * Weak functions - Cache
 *
 * Default NOP operations. Override if available on the targeted device.
 ******************************************************************************/

/*
 * Flush/clean the data cache by address and size. Passing NULL as p argument
 * expects the whole cache to be flushed.
 */
void __attribute__((weak)) ethosu_flush_dcache(uint32_t *p, size_t bytes)
{
  if (p)
    SCB_CleanDCache_by_Addr(p, bytes);
  else
    SCB_CleanDCache();
}

/*
 * Invalidate the data cache by address and size. Passing NULL as p argument
 * expects the whole cache to be invalidated.
 */
void __attribute__((weak)) ethosu_invalidate_dcache(uint32_t *p, size_t bytes)
{

  if (p)
    SCB_InvalidateDCache_by_Addr(p, bytes);
  else
    SCB_InvalidateDCache();
}

/******************************************************************************
 * Weak functions - Semaphore/Mutex for multi NPU
 *
 * Following section handles the minimal sempahore and mutex implementation in
 * case of baremetal applications. Weak symbols will be overridden by RTOS
 * definitions and implement true thread-safety (in application layer).
 ******************************************************************************/

struct ethosu_semaphore_t
{
    uint8_t count;
};

static void *ethosu_mutex;
static void *ethosu_semaphore;

void *__attribute__((weak)) ethosu_mutex_create(void)
{
    static uint8_t mutex_placeholder;
    return &mutex_placeholder;
}

void __attribute__((weak)) ethosu_mutex_destroy(void *mutex)
{
    UNUSED(mutex);
}

int __attribute__((weak)) ethosu_mutex_lock(void *mutex)
{
    UNUSED(mutex);
    return 0;
}

int __attribute__((weak)) ethosu_mutex_unlock(void *mutex)
{
    UNUSED(mutex);
    return 0;
}

// Baremetal implementation of creating a semaphore
void *__attribute__((weak)) ethosu_semaphore_create(void)
{
    struct ethosu_semaphore_t *sem = malloc(sizeof(*sem));
    if (sem != NULL)
    {
        sem->count = 0;
    }
    return sem;
}

void __attribute__((weak)) ethosu_semaphore_destroy(void *sem)
{
    free((struct ethosu_semaphore_t *)sem);
}

// Baremetal simulation of waiting/sleeping for and then taking a semaphore using intrisics
int __attribute__((weak)) ethosu_semaphore_take(void *sem, uint64_t timeout)
{
    UNUSED(timeout);
    // Baremetal pseudo-example on how to trigger a timeout:
    // if (timeout != ETHOSU_SEMAPHORE_WAIT_FOREVER) {
    //     setup_a_timer_to_call_SEV_after_time(timeout);
    // }
    struct ethosu_semaphore_t *s = sem;
    while (s->count == 0)
    {
        __WFE();
        // Baremetal pseudo-example check if timeout triggered:
        // if (SEV_timer_triggered()) {
        //     return -1;
        // }
    }
    s->count--;
    return 0;
}

// Baremetal simulation of giving a semaphore and waking up processes using intrinsics
int __attribute__((weak)) ethosu_semaphore_give(void *sem)
{
    struct ethosu_semaphore_t *s = sem;
    s->count++;
    __SEV();
    return 0;
}

/******************************************************************************
 * Weak functions - Inference begin/end callbacks
 ******************************************************************************/

void __attribute__((weak)) ethosu_inference_begin(struct ethosu_driver *drv, void *user_arg)
{
    UNUSED(user_arg);
    UNUSED(drv);
}

void __attribute__((weak)) ethosu_inference_end(struct ethosu_driver *drv, void *user_arg)
{
    UNUSED(user_arg);
    UNUSED(drv);
}

/******************************************************************************
 * Static functions
 ******************************************************************************/
static void ethosu_register_driver(struct ethosu_driver *drv)
{
    ethosu_mutex_lock(ethosu_mutex);
    drv->next          = registered_drivers;
    registered_drivers = drv;
    ethosu_mutex_unlock(ethosu_mutex);

    ethosu_semaphore_give(ethosu_semaphore);

    LOG_INFO("New NPU driver registered (handle: 0x%p, NPU: 0x%p)", drv, drv->dev->reg);
}

static int ethosu_deregister_driver(struct ethosu_driver *drv)
{
    struct ethosu_driver *curr;
    struct ethosu_driver **prev;

    ethosu_mutex_lock(ethosu_mutex);
    curr = registered_drivers;
    prev = &registered_drivers;

    while (curr != NULL)
    {
        if (curr == drv)
        {
            *prev = curr->next;
            LOG_INFO("NPU driver handle %p deregistered.", drv);
            ethosu_semaphore_take(ethosu_semaphore, ETHOSU_SEMAPHORE_WAIT_FOREVER);
            break;
        }

        prev = &curr->next;
        curr = curr->next;
    }

    ethosu_mutex_unlock(ethosu_mutex);

    if (curr == NULL)
    {
        LOG_ERR("No NPU driver handle registered at address %p.", drv);
        return -1;
    }

    return 0;
}

static void ethosu_reset_job(struct ethosu_driver *drv)
{
    memset(&drv->job, 0, sizeof(struct ethosu_job));
}

static int handle_optimizer_config(struct ethosu_driver *drv, struct opt_cfg_s const *opt_cfg_p)
{
    LOG_INFO("Optimizer release nbr: %u patch: %u", opt_cfg_p->da_data.rel_nbr, opt_cfg_p->da_data.patch_nbr);

    if (ethosu_dev_verify_optimizer_config(drv->dev, opt_cfg_p->cfg, opt_cfg_p->id) != true)
    {
        return -1;
    }

    return 0;
}

static int handle_command_stream(struct ethosu_driver *drv, const uint8_t *cmd_stream, const int cms_length)
{
    uint32_t cms_bytes       = cms_length * BYTES_IN_32_BITS;
    ptrdiff_t cmd_stream_ptr = (ptrdiff_t)cmd_stream;

    LOG_INFO("handle_command_stream: cmd_stream=%p, cms_length %d", cmd_stream, cms_length);

    if (0 != ((ptrdiff_t)cmd_stream & MASK_16_BYTE_ALIGN))
    {
        LOG_ERR("Command stream addr %p not aligned to 16 bytes", cmd_stream);
        return -1;
    }

    // Verify 16 byte alignment for base address'
    for (int i = 0; i < drv->job.num_base_addr; i++)
    {
        if (0 != (drv->job.base_addr[i] & MASK_16_BYTE_ALIGN))
        {
            LOG_ERR("Base addr %d: 0x%" PRIx64 "not aligned to 16 bytes", i, drv->job.base_addr[i]);
            return -1;
        }
    }

    // Flush the cache if available on CPU.
    // The upcasting to uin32_t* is ok since the pointer never is dereferenced.
    // The base_addr_size is null if invoking from prior to invoke_V2, in that case
    // the whole cache is being flushed.

    if (drv->job.base_addr_size != NULL)
    {
        ethosu_flush_dcache((uint32_t *)cmd_stream_ptr, cms_bytes);
        for (int i = 0; i < drv->job.num_base_addr; i++)
        {
            ethosu_flush_dcache((uint32_t *)(uintptr_t)drv->job.base_addr[i], drv->job.base_addr_size[i]);
        }
    }
    else
    {
        ethosu_flush_dcache(NULL, 0);
    }

    // Request power gating disabled during inference run
    if (ethosu_request_power(drv))
    {
        LOG_ERR("Failed to request power");
        return -1;
    }

    drv->job.state = ETHOSU_JOB_RUNNING;

    // Inference begin callback
    ethosu_inference_begin(drv, drv->job.user_arg);

    // Execute the command stream
    ethosu_dev_run_command_stream(drv->dev, cmd_stream, cms_bytes, drv->job.base_addr, drv->job.num_base_addr);

    return 0;
}

/******************************************************************************
 * Weak functions - Interrupt handler
 ******************************************************************************/
void __attribute__((weak)) ethosu_irq_handler(struct ethosu_driver *drv)
{
    LOG_DEBUG("Got interrupt from Ethos-U");

    // Prevent race condition where interrupt triggered after a timeout waiting
    // for semaphore, but before NPU is reset.
    if (drv->job.result == ETHOSU_JOB_RESULT_TIMEOUT)
    {
        return;
    }

    drv->job.state  = ETHOSU_JOB_DONE;
    drv->job.result = ethosu_dev_handle_interrupt(drv->dev) ? ETHOSU_JOB_RESULT_OK : ETHOSU_JOB_RESULT_ERROR;
    ethosu_semaphore_give(drv->semaphore);
}

/******************************************************************************
 * Functions API
 ******************************************************************************/

int ethosu_init(struct ethosu_driver *drv,
                void *const base_address,
                const void *fast_memory,
                const size_t fast_memory_size,
                uint32_t secure_enable,
                uint32_t privilege_enable)
{
    LOG_INFO("Initializing NPU: base_address=%p, fast_memory=%p, fast_memory_size=%zu, secure=%" PRIu32
             ", privileged=%" PRIu32,
             base_address,
             fast_memory,
             fast_memory_size,
             secure_enable,
             privilege_enable);

    if (!ethosu_mutex)
    {
        ethosu_mutex = ethosu_mutex_create();
        if (!ethosu_mutex)
        {
            LOG_ERR("Failed to create global driver mutex");
            return -1;
        }
    }

    if (!ethosu_semaphore)
    {
        ethosu_semaphore = ethosu_semaphore_create();
        if (!ethosu_semaphore)
        {
            LOG_ERR("Failed to create global driver semaphore");
            return -1;
        }
    }

    drv->fast_memory           = (uintptr_t)fast_memory;
    drv->fast_memory_size      = fast_memory_size;
    drv->power_request_counter = 0;

    // Initialize the device and set requested security state and privilege mode
    drv->dev = ethosu_dev_init(base_address, secure_enable, privilege_enable);

    if (drv->dev == NULL)
    {
        LOG_ERR("Failed to initialize Ethos-U device");
        return -1;
    }

    drv->semaphore = ethosu_semaphore_create();
    if (!drv->semaphore)
    {
        LOG_ERR("Failed to create driver semaphore");
        ethosu_dev_deinit(drv->dev);
        drv->dev = NULL;
        return -1;
    }

    ethosu_reset_job(drv);
    ethosu_register_driver(drv);

    return 0;
}

void ethosu_deinit(struct ethosu_driver *drv)
{
    ethosu_deregister_driver(drv);
    ethosu_semaphore_destroy(drv->semaphore);
    ethosu_semaphore_destroy(ethosu_semaphore);
    ethosu_mutex_destroy(ethosu_mutex);
    ethosu_dev_deinit(drv->dev);
    ethosu_semaphore = NULL;
    ethosu_mutex = NULL;
    drv->dev = NULL;
}

int ethosu_soft_reset(struct ethosu_driver *drv)
{
    // Soft reset the NPU
    if (ethosu_dev_soft_reset(drv->dev) != ETHOSU_SUCCESS)
    {
        LOG_ERR("Failed to soft-reset NPU");
        return -1;
    }

    // Update power and clock gating after the soft reset
    ethosu_dev_set_clock_and_power(drv->dev,
                                   drv->power_request_counter > 0 ? ETHOSU_CLOCK_Q_DISABLE : ETHOSU_CLOCK_Q_ENABLE,
                                   drv->power_request_counter > 0 ? ETHOSU_POWER_Q_DISABLE : ETHOSU_POWER_Q_ENABLE);

    return 0;
}

int ethosu_request_power(struct ethosu_driver *drv)
{
    // Check if this is the first power request, increase counter
    if (drv->power_request_counter++ == 0)
    {
        // Always reset to a known state. Changes to requested
        // security state/privilege mode if necessary.
        if (ethosu_soft_reset(drv))
        {
            LOG_ERR("Failed to request power for Ethos-U");
            drv->power_request_counter--;
            return -1;
        }
    }
    return 0;
}

void ethosu_release_power(struct ethosu_driver *drv)
{
    if (drv->power_request_counter == 0)
    {
        LOG_WARN("No power request left to release, reference counter is 0");
    }
    else
    {
        // Decrement ref counter and enable power gating if no requests remain
        if (--drv->power_request_counter == 0)
        {
            ethosu_dev_set_clock_and_power(drv->dev, ETHOSU_CLOCK_Q_ENABLE, ETHOSU_POWER_Q_ENABLE);
        }
    }
}

void ethosu_get_driver_version(struct ethosu_driver_version *ver)
{
    assert(ver != NULL);
    ver->major = ETHOSU_DRIVER_VERSION_MAJOR;
    ver->minor = ETHOSU_DRIVER_VERSION_MINOR;
    ver->patch = ETHOSU_DRIVER_VERSION_PATCH;
}

void ethosu_get_hw_info(struct ethosu_driver *drv, struct ethosu_hw_info *hw)
{
    assert(hw != NULL);
    ethosu_dev_get_hw_info(drv->dev, hw);
}

int ethosu_wait(struct ethosu_driver *drv, bool block)
{
    int ret = 0;

    switch (drv->job.state)
    {
    case ETHOSU_JOB_IDLE:
        LOG_ERR("Inference job not running...");
        ret = -2;
        break;
    case ETHOSU_JOB_RUNNING:
        if (!block)
        {
            // Inference still running, do not block
            ret = 1;
            break;
        }
        // fall through
    case ETHOSU_JOB_DONE:
        // Wait for interrupt in blocking mode. In non-blocking mode
        // the interrupt has already triggered
        ret = ethosu_semaphore_take(drv->semaphore, ETHOSU_SEMAPHORE_WAIT_INFERENCE);
        if (ret < 0)
        {
            drv->job.result = ETHOSU_JOB_RESULT_TIMEOUT;

            // There's a race where the NPU interrupt can have fired between semaphore
            // timing out and setting the result above (checked in interrupt handler).
            // By checking if the job state has been changed (only set to DONE by interrupt
            // handler), we know if the interrupt handler has run, if so decrement the
            // semaphore count by one (given in interrupt handler).
            if (drv->job.state == ETHOSU_JOB_DONE)
            {
                drv->job.result = ETHOSU_JOB_RESULT_TIMEOUT; // Reset back to timeout
                ethosu_semaphore_take(drv->semaphore, ETHOSU_SEMAPHORE_WAIT_INFERENCE);
            }
        }

        // Inference done callback - always called even in case of timeout
        ethosu_inference_end(drv, drv->job.user_arg);

        // Release power gating disabled requirement
        ethosu_release_power(drv);

        // Check NPU and interrupt status
        if (drv->job.result)
        {
            if (drv->job.result == ETHOSU_JOB_RESULT_ERROR)
            {
                LOG_ERR("NPU error(s) occured during inference.");
                ethosu_dev_print_err_status(drv->dev);
            }
            else
            {
                LOG_ERR("NPU inference timed out.");
            }

            // Reset the NPU
            (void)ethosu_soft_reset(drv);

            ret = -1;
        }
        else
        {
            // Invalidate cache
            if (drv->job.base_addr_size != NULL)
            {
                for (int i = 0; i < drv->job.num_base_addr; i++)
                {
                    if ((uint32_t *)(uintptr_t)drv->job.base_addr[i] != NULL)
                      ethosu_invalidate_dcache((uint32_t *)(uintptr_t)drv->job.base_addr[i], drv->job.base_addr_size[i]);
                }
            }
            else
            {
                ethosu_invalidate_dcache(NULL, 0);
            }

            LOG_DEBUG("Inference finished successfully...");
            ret = 0;
        }

        // Reset internal job (state resets to IDLE)
        ethosu_reset_job(drv);
        break;

    default:
        LOG_ERR("Unexpected job state");
        ethosu_reset_job(drv);
        ret = -1;
        break;
    }

    // Return inference job status
    return ret;
}

int ethosu_invoke_async(struct ethosu_driver *drv,
                        const void *custom_data_ptr,
                        const int custom_data_size,
                        uint64_t *const base_addr,
                        const size_t *base_addr_size,
                        const int num_base_addr,
                        void *user_arg)
{

    const struct cop_data_s *data_ptr = custom_data_ptr;
    const struct cop_data_s *data_end = (struct cop_data_s *)((ptrdiff_t)custom_data_ptr + custom_data_size);

    // Make sure an inference is not already running
    if (drv->job.state != ETHOSU_JOB_IDLE)
    {
        LOG_ERR("Inference already running, or waiting to be cleared...");
        return -1;
    }

    drv->job.state            = ETHOSU_JOB_IDLE;
    drv->job.custom_data_ptr  = custom_data_ptr;
    drv->job.custom_data_size = custom_data_size;
    drv->job.base_addr        = base_addr;
    drv->job.base_addr_size   = base_addr_size;
    drv->job.num_base_addr    = num_base_addr;
    drv->job.user_arg         = user_arg;

    // First word in custom_data_ptr should contain "Custom Operator Payload 1"
    if (data_ptr->word != ETHOSU_FOURCC)
    {
        LOG_ERR("Custom Operator Payload: %" PRIu32 " is not correct, expected %x", data_ptr->word, ETHOSU_FOURCC);
        goto err;
    }

    // Custom data length must be a multiple of 32 bits
    if ((custom_data_size % BYTES_IN_32_BITS) != 0)
    {
        LOG_ERR("custom_data_size=0x%x not a multiple of 4", (unsigned)custom_data_size);
        goto err;
    }

    data_ptr++;

    // Adjust base address to fast memory area
    if (drv->fast_memory != 0 && num_base_addr >= FAST_MEMORY_BASE_ADDR_INDEX)
    {

        if (base_addr_size != NULL && base_addr_size[FAST_MEMORY_BASE_ADDR_INDEX] > drv->fast_memory_size)
        {
            LOG_ERR("Fast memory area too small. fast_memory_size=%zu, base_addr_size=%zu",
                    drv->fast_memory_size,
                    base_addr_size[FAST_MEMORY_BASE_ADDR_INDEX]);
            goto err;
        }

        base_addr[FAST_MEMORY_BASE_ADDR_INDEX] = drv->fast_memory;
    }

    // Parse Custom Operator Payload data
    while (data_ptr < data_end)
    {
        switch (data_ptr->driver_action_command)
        {
        case OPTIMIZER_CONFIG:
            LOG_DEBUG("OPTIMIZER_CONFIG");
            struct opt_cfg_s const *opt_cfg_p = (const struct opt_cfg_s *)data_ptr;

            if (handle_optimizer_config(drv, opt_cfg_p) < 0)
            {
                goto err;
            }
            data_ptr += DRIVER_ACTION_LENGTH_32_BIT_WORD + OPTIMIZER_CONFIG_LENGTH_32_BIT_WORD;
            break;
        case COMMAND_STREAM:
            // Vela only supports putting one COMMAND_STREAM per op
            LOG_DEBUG("COMMAND_STREAM");
            const uint8_t *command_stream = (const uint8_t *)(data_ptr + 1);
            int cms_length                = (data_ptr->reserved << 16) | data_ptr->length;

            if (handle_command_stream(drv, command_stream, cms_length) < 0)
            {
                goto err;
            }
            data_ptr += DRIVER_ACTION_LENGTH_32_BIT_WORD + cms_length;
            break;
        case NOP:
            LOG_DEBUG("NOP");
            data_ptr += DRIVER_ACTION_LENGTH_32_BIT_WORD;
            break;
        default:
            LOG_ERR("UNSUPPORTED driver_action_command: %u", data_ptr->driver_action_command);
            goto err;
            //break;
        }
    }

    return 0;
err:
    LOG_ERR("Failed to invoke inference.");
    ethosu_reset_job(drv);
    return -1;
}

int ethosu_invoke_v3(struct ethosu_driver *drv,
                     const void *custom_data_ptr,
                     const int custom_data_size,
                     uint64_t *const base_addr,
                     const size_t *base_addr_size,
                     const int num_base_addr,
                     void *user_arg)
{
    if (ethosu_invoke_async(
            drv, custom_data_ptr, custom_data_size, base_addr, base_addr_size, num_base_addr, user_arg) < 0)
    {
        return -1;
    }

    return ethosu_wait(drv, true);
}

struct ethosu_driver *ethosu_reserve_driver(void)
{
    struct ethosu_driver *drv = NULL;

    LOG_INFO("Acquiring NPU driver handle");
    ethosu_semaphore_take(ethosu_semaphore, ETHOSU_SEMAPHORE_WAIT_FOREVER); // This is meant to block until available

    ethosu_mutex_lock(ethosu_mutex);
    drv = registered_drivers;

    while (drv != NULL)
    {
        if (!drv->reserved)
        {
            drv->reserved = true;
            LOG_DEBUG("NPU driver handle %p reserved", drv);
            break;
        }
        drv = drv->next;
    }
    ethosu_mutex_unlock(ethosu_mutex);

    if (!drv)
    {
        LOG_ERR("No NPU driver handle available, but semaphore taken");
    }

    return drv;
}

void ethosu_release_driver(struct ethosu_driver *drv)
{
    ethosu_mutex_lock(ethosu_mutex);
    if (drv != NULL && drv->reserved)
    {
        if (drv->job.state == ETHOSU_JOB_RUNNING || drv->job.state == ETHOSU_JOB_DONE)
        {
            // Give the inference one shot to complete or force kill the job
            if (ethosu_wait(drv, false) == 1)
            {
                // Still running, soft reset the NPU and reset driver
                drv->power_request_counter = 0;
                ethosu_soft_reset(drv);
                ethosu_reset_job(drv);
            }
        }

        drv->reserved = false;
        LOG_DEBUG("NPU driver handle %p released", drv);
        ethosu_semaphore_give(ethosu_semaphore);
    }
    ethosu_mutex_unlock(ethosu_mutex);
}
