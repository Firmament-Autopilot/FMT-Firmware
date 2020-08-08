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

#ifndef __FMT_DEF_H__
#define __FMT_DEF_H__

/* Firmament version information */
#define FMT_VERSION    0 /**< major version number */
#define FMT_SUBVERSION 0 /**< minor version number */
#define FMT_REVISION   1 /**< revise version number */

#ifndef bool
typedef int bool;
#endif

#ifndef true
#define true (1U)
#endif

#ifndef false
#define false (0U)
#endif

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
} fmt_err;

#endif