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

#ifndef ETHOSU_DRIVER_H
#define ETHOSU_DRIVER_H

/******************************************************************************
 * Includes
 ******************************************************************************/
#include "cy_device.h"
#include "ethosu_types.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Defines
 ******************************************************************************/

#define ETHOSU_DRIVER_VERSION_MAJOR 0  ///< Driver major version
#define ETHOSU_DRIVER_VERSION_MINOR 16 ///< Driver minor version
#define ETHOSU_DRIVER_VERSION_PATCH 0  ///< Driver patch version

#define ETHOSU_SEMAPHORE_WAIT_FOREVER (UINT64_MAX)

#ifndef ETHOSU_SEMAPHORE_WAIT_INFERENCE
#define ETHOSU_SEMAPHORE_WAIT_INFERENCE ETHOSU_SEMAPHORE_WAIT_FOREVER
#endif

/******************************************************************************
 * Types
 ******************************************************************************/

// Forward declare
struct ethosu_device;

enum ethosu_job_state
{
    ETHOSU_JOB_IDLE = 0,
    ETHOSU_JOB_RUNNING,
    ETHOSU_JOB_DONE
};

enum ethosu_job_result
{
    ETHOSU_JOB_RESULT_OK = 0,
    ETHOSU_JOB_RESULT_TIMEOUT,
    ETHOSU_JOB_RESULT_ERROR
};

struct ethosu_job
{
    volatile enum ethosu_job_state state;
    volatile enum ethosu_job_result result;
    const void *custom_data_ptr;
    int custom_data_size;
    const uint64_t *base_addr;
    const size_t *base_addr_size;
    int num_base_addr;
    void *user_arg;
};

struct ethosu_driver
{
    struct ethosu_device *dev;
    struct ethosu_driver *next;
    struct ethosu_job job;
    void *semaphore;
    uint64_t fast_memory;
    size_t fast_memory_size;
    uint32_t power_request_counter;
    bool reserved;
};

struct ethosu_driver_version
{
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
};

enum ethosu_request_clients
{
    ETHOSU_PMU_REQUEST       = 0,
    ETHOSU_INFERENCE_REQUEST = 1,
};

/******************************************************************************
 * Prototypes (weak functions in driver)
 ******************************************************************************/

/**
 * Interrupt handler to be called on IRQ from Ethos-U
 *
 * @param drv       Pointer to driver handle
 */
void ethosu_irq_handler(struct ethosu_driver *drv);

/**
 * Flush/clean the data cache by address and size. Passing NULL as p argument
 * expects the whole cache to be flushed.
 *
 * Addresses passed to this function must be 16 byte aligned.
 *
 * @param p         16 byte aligned address
 * @param bytes     Size of memory block in bytes
 */
void ethosu_flush_dcache(uint32_t *p, size_t bytes);

/**
 * Invalidate the data cache by address and size. Passing NULL as p argument
 * expects the whole cache to be invalidated.
 *
 * Addresses passed to this function must be 16 byte aligned.
 *
 * @param p         16 byte aligned address
 * @param bytes     Size in bytes
 */
void ethosu_invalidate_dcache(uint32_t *p, size_t bytes);

/**
 * Minimal mutex implementation for baremetal applications. See
 * ethosu_driver.c.
 *
 * @return Pointer to mutex handle
 */
void *ethosu_mutex_create(void);

/**
 * Destroy mutex.
 *
 * @param mutex     Pointer to mutex handle
 */
void ethosu_mutex_destroy(void *mutex);

/**
 * Minimal sempahore implementation for baremetal applications. See
 * ethosu_driver.c.
 *
 * @return Pointer to semaphore handle
 */
void *ethosu_semaphore_create(void);

/**
 * Destroy semaphore.
 *
 * @param sem       Pointer to semaphore handle
 */
void ethosu_semaphore_destroy(void *sem);

/**
 * Lock mutex.
 *
 * @param mutex     Pointer to mutex handle
 * @returns 0 on success, else negative error code
 */
int ethosu_mutex_lock(void *mutex);

/**
 * Unlock mutex.
 *
 * @param mutex     Pointer to mutex handle
 * @returns 0 on success, else negative error code
 */
int ethosu_mutex_unlock(void *mutex);

/**
 * Take semaphore.
 *
 * @param sem       Pointer to semaphore handle
 * @param timeout   Timeout value (unit impl. defined)
 * @returns 0 on success else negative error code
 */
int ethosu_semaphore_take(void *sem, uint64_t timeout);

/**
 * Give semaphore.
 *
 * @param sem       Pointer to semaphore handle
 * @returns 0 on success, else negative error code
 */
int ethosu_semaphore_give(void *sem);

/**
 * Callback invoked just before the inference is started.
 *
 * @param drv       Pointer to driver handle
 * @param user_arg  User argument provided to ethosu_invoke_*()
 */
void ethosu_inference_begin(struct ethosu_driver *drv, void *user_arg);

/**
 * Callback invoked just after the inference has completed.
 *
 * @param drv       Pointer to driver handle
 * @param user_arg  User argument provided to ethosu_invoke_*()
 */
void ethosu_inference_end(struct ethosu_driver *drv, void *user_arg);

/**
 * Remapping command stream and base pointer addresses.
 *
 * @param address   Address to be remapped.
 * @param index     -1 command stream, 0-n base address index
 *
 * @return Remapped address
 */
uint64_t ethosu_address_remap(uint64_t address, int index);

/******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * Initialize the Ethos-U driver.
 *
 * @param drv               Pointer to driver handle
 * @param base_address      NPU register base address
 * @param fast_memory       Fast memory area, used for Ethos-U65 with spilling
 * @param fast_memory_size  Size in bytes of fast memory area
 * @param secure_enable     Configure NPU in secure- or non-secure mode
 * @param privilege_enable  Configure NPU in privileged- or non-privileged mode
 * @return 0 on success, else negative error code
 */
int ethosu_init(struct ethosu_driver *drv,
                void *const base_address,
                const void *fast_memory,
                const size_t fast_memory_size,
                uint32_t secure_enable,
                uint32_t privilege_enable);

/**
 * Deinitialize the Ethos-U driver.
 *
 * @param drv       Pointer to driver handle
 */
void ethosu_deinit(struct ethosu_driver *drv);

/**
 * Soft resets the Ethos-U device.
 *
 * @param drv       Pointer to driver handle
 * @return 0 on success, else negative error code
 */
int ethosu_soft_reset(struct ethosu_driver *drv);

/**
 * Request to disable Q-channel power gating of the Ethos-U device.
 * Power requests are ref.counted. Increases count.
 * (Note: clock gating is made to follow power gating)
 *
 * @param drv       Pointer to driver handle
 * @return 0 on success, else negative error code
 */
int ethosu_request_power(struct ethosu_driver *drv);

/**
 * Release disable request for Q-channel power gating of the Ethos-U device.
 * Power requests are ref.counted. Decreases count.
 *
 * @param drv       Pointer to driver handle
 */
void ethosu_release_power(struct ethosu_driver *drv);

/**
 * Get Ethos-U driver version.
 *
 * @param ver       Driver version struct
 */
void ethosu_get_driver_version(struct ethosu_driver_version *ver);

/**
 * Get Ethos-U hardware information.
 *
 * @param drv       Pointer to driver handle
 * @param hw        Hardware information struct
 */
void ethosu_get_hw_info(struct ethosu_driver *drv, struct ethosu_hw_info *hw);

/**
 * Invoke command stream.
 *
 * @param drv               Pointer to driver handle
 * @param custom_data_ptr   Custom data payload
 * @param custom_data_size  Size in bytes of custom data
 * @param base_addr         Array of base address pointers
 * @param base_addr_size    Size in bytes of each address in base_addr
 * @param num_base_addr     Number of elements in base_addr array
 * @param user_arg          User argument, will be passed to
 *                          ethosu_inference_begin() and ethosu_inference_end()
 * @return 0 on success, else negative error code
 */
int ethosu_invoke_v3(struct ethosu_driver *drv,
                     const void *custom_data_ptr,
                     const int custom_data_size,
                     uint64_t *const base_addr,
                     const size_t *base_addr_size,
                     const int num_base_addr,
                     void *user_arg);

#define ethosu_invoke(drv, custom_data_ptr, custom_data_size, base_addr, base_addr_size, num_base_addr)                \
    ethosu_invoke_v3(drv, custom_data_ptr, custom_data_size, base_addr, base_addr_size, num_base_addr, 0)

/**
 * Invoke command stream using async interface.
 * Must be followed by call(s) to ethosu_wait() upon successful return.
 *
 * @see ethosu_invoke_v3 for documentation.
 */
int ethosu_invoke_async(struct ethosu_driver *drv,
                        const void *custom_data_ptr,
                        const int custom_data_size,
                        uint64_t *const base_addr,
                        const size_t *base_addr_size,
                        const int num_base_addr,
                        void *user_arg);

/**
 * Wait for inference to complete (block=true)
 * Poll status or finish up if inference is complete (block=false)
 * (This function is only intended to be used in conjuction with ethosu_invoke_async)
 *
 * @param drv       Pointer to driver handle
 * @param block     If call should block if inference is running
 * @return -2 on inference not invoked, -1 on inference error, 0 on success, 1 on inference running
 */
int ethosu_wait(struct ethosu_driver *drv, bool block);

/**
 * Reserves a driver to execute inference with. Call will block until a driver
 * is available.
 *
 * @return Pointer to driver handle.
 */
struct ethosu_driver *ethosu_reserve_driver(void);

/**
 * Release driver that was previously reserved with @see ethosu_reserve_driver.
 *
 * @param drv       Pointer to driver handle
 */
void ethosu_release_driver(struct ethosu_driver *drv);

/**
 * Static inline for backwards-compatibility.
 *
 * @see ethosu_invoke_v3 for documentation.
 */
static inline int ethosu_invoke_v2(const void *custom_data_ptr,
                                   const int custom_data_size,
                                   uint64_t *const base_addr,
                                   const size_t *base_addr_size,
                                   const int num_base_addr)
{
    struct ethosu_driver *drv = ethosu_reserve_driver();
    if (!drv)
    {
        return -1;
    }
    int result = ethosu_invoke_v3(drv, custom_data_ptr, custom_data_size, base_addr, base_addr_size, num_base_addr, 0);
    ethosu_release_driver(drv);
    return result;
}

#ifdef __cplusplus
}
#endif

#endif // ETHOSU_DRIVER_H
