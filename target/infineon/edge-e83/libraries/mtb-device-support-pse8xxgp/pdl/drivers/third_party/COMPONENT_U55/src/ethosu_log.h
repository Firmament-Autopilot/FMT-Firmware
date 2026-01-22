/*
 * SPDX-FileCopyrightText: Copyright 2021-2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef ETHOSU_LOG_H
#define ETHOSU_LOG_H

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdio.h>
#include <string.h>

/******************************************************************************
 * Defines
 ******************************************************************************/

// Log severity levels
#define ETHOSU_LOG_ERR 0
#define ETHOSU_LOG_WARN 1
#define ETHOSU_LOG_INFO 2
#define ETHOSU_LOG_DEBUG 3

// Define default log severity
#ifndef ETHOSU_LOG_SEVERITY
#define ETHOSU_LOG_SEVERITY ETHOSU_LOG_WARN
#endif

// Logs enabled by default
#ifndef ETHOSU_LOG_ENABLE
#define ETHOSU_LOG_ENABLE 1
#endif

#if ETHOSU_LOG_ENABLE
#define LOG_COMMON(s, f, ...) (void)fprintf(s, f, ##__VA_ARGS__)
#else
#define LOG_COMMON(s, f, ...)
#endif

// Log formatting
#define LOG(f, ...) LOG_COMMON(stdout, f, ##__VA__ARGS__)

#if ETHOSU_LOG_SEVERITY >= ETHOSU_LOG_ERR
#define LOG_ERR(f, ...)                                                                                                \
    LOG_COMMON(stderr, "E: " f " (%s:%d)\n", ##__VA_ARGS__, strrchr("/" __FILE__, '/') + 1, __LINE__)
#else
#define LOG_ERR(f, ...)
#endif

#if ETHOSU_LOG_SEVERITY >= ETHOSU_LOG_WARN
#define LOG_WARN(f, ...) LOG_COMMON(stdout, "W: " f "\n", ##__VA_ARGS__)
#else
#define LOG_WARN(f, ...)
#endif

#if ETHOSU_LOG_SEVERITY >= ETHOSU_LOG_INFO
#define LOG_INFO(f, ...) LOG_COMMON(stdout, "I: " f "\n", ##__VA_ARGS__)
#else
#define LOG_INFO(f, ...)
#endif

#if ETHOSU_LOG_SEVERITY >= ETHOSU_LOG_DEBUG
#define LOG_DEBUG(f, ...) LOG_COMMON(stdout, "D: %s(): " f "\n", __FUNCTION__, ##__VA_ARGS__)
#else
#define LOG_DEBUG(f, ...)
#endif

#endif
