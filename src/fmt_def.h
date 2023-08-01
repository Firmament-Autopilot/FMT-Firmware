/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef FMT_DEF_H__
#define FMT_DEF_H__

#include "rtdef.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Firmament version information */
#define FMT_VERSION "v1.0.0-rc"

/* Thread Prority */
#define VEHICLE_THREAD_PRIORITY    3
#define FMTIO_THREAD_PRIORITY      7
#define DRONECAN_THREAD_PRIORITY   4
#define LOGGER_THREAD_PRIORITY     10
#define MAVLINK_RX_THREAD_PRIORITY 11
#define MAVOBC_THREAD_PRIORITY     12
#define MAVGCS_THREAD_PRIORITY     13
#define STATUS_THREAD_PRIORITY     14

#if !defined(bool) && !defined(__cplusplus)
typedef int bool;
#endif

#ifndef true
    #define true (1U)
#endif

#ifndef false
    #define false (0U)
#endif

// Macro to define packed structures
#ifdef __GNUC__
    #define __PACKED__(__Declaration__) __Declaration__ __attribute__((packed))
#else
    #define __PACKED__(__Declaration__) __pragma(pack(push, 1)) __Declaration__ __pragma(pack(pop))
#endif

#ifndef PI
    #define PI 3.14159265358979f
#endif

#ifndef STRING
    #define STR_EXPAND(x) #x
    #define STR(x)        STR_EXPAND(x)
    #define STRING(...)   #__VA_ARGS__
#endif

#ifdef FMT_USING_SYS_DEBUG
    #define SYS_DBG(...) printf(__VA_ARGS__)
#else
    #define SYS_DBG(...)
#endif

#define RT_TRY(__exp)                                                                                \
    do {                                                                                             \
        rt_err_t err = (__exp);                                                                      \
        if (err != RT_EOK) {                                                                         \
            SYS_DBG("RT_TRY failed at function:%s, line:%u, err:%d\n", __FUNCTION__, __LINE__, err); \
            return err;                                                                              \
        }                                                                                            \
    } while (false)

#define FMT_TRY(__exp)                                                                                \
    do {                                                                                              \
        fmt_err_t err = (__exp);                                                                      \
        if (err != FMT_EOK) {                                                                         \
            SYS_DBG("FMT_TRY failed at function:%s, line:%u, err:%d\n", __FUNCTION__, __LINE__, err); \
            return err;                                                                               \
        }                                                                                             \
    } while (false)

#define OS_ENTER_CRITICAL rt_enter_critical()
#define OS_EXIT_CRITICAL  rt_exit_critical()
#define OS_MALLOC(size)   rt_malloc(size)
#define OS_FREE(ptr)      rt_free(ptr)

#define FMT_ASSERT(exp) RT_ASSERT((exp))
#define FMT_CHECK(func) RT_ASSERT(func == FMT_EOK)
#define RT_CHECK(func)  RT_ASSERT(func == RT_EOK)

typedef enum {
    FMT_EOK = 0,         /**< There is no error */
    FMT_ERROR = 1,       /**< A generic error happens */
    FMT_ETIMEOUT = 2,    /**< Timed out */
    FMT_EFULL = 3,       /**< The resource is full */
    FMT_EEMPTY = 4,      /**< The resource is empty */
    FMT_ENOMEM = 5,      /**< No memory */
    FMT_ENOSYS = 6,      /**< No system */
    FMT_EBUSY = 7,       /**< Busy */
    FMT_EIO = 8,         /**< IO error */
    FMT_EINTR = 9,       /**< Interrupted system call */
    FMT_EINVAL = 10,     /**< Invalid argument */
    FMT_ENOTHANDLE = 11, /**< Not handled */
} fmt_err_t;

typedef struct {
    uint32_t period;
    char* info;
} fmt_model_info_t;

#ifdef __cplusplus
}
#endif

#endif