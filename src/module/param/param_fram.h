/******************************************************************************
 * Copyright 2020-2024 The Firmament Authors. All Rights Reserved.
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

#ifndef PARAM_FRAM_H__
#define PARAM_FRAM_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* FRAM parameter storage configuration */
#define FRAM_MTD_DEVICE_NAME    "mtdblk0"      /* FRAM MTD device name */
#define FRAM_PARAM_MAGIC        0x464D5450     /* "FMTP" magic number */
#define FRAM_PARAM_VERSION      1              /* Parameter format version */
#define FRAM_PARAM_START_SECTOR 0              /* Start sector for parameter storage */
#define FRAM_PARAM_MAX_SECTORS  64             /* Maximum sectors for parameter (32KB) */

/**
 * @brief Save parameters to FRAM
 * 
 * This function saves all parameters to FRAM as a binary backup.
 * It is automatically called when saving parameters to SD card.
 * 
 * @return fmt_err_t FMT_EOK on success, FMT_ERROR on failure
 */
fmt_err_t param_fram_save(void);

/**
 * @brief Load parameters from FRAM
 * 
 * This function loads parameters from FRAM binary storage.
 * It is used as a fallback when SD card parameter file is not available.
 * 
 * @return fmt_err_t FMT_EOK on success, FMT_ERROR on failure
 */
fmt_err_t param_fram_load(void);

/**
 * @brief Check if valid parameters exist in FRAM
 * 
 * @return rt_bool_t RT_TRUE if valid parameters found, RT_FALSE otherwise
 */
rt_bool_t param_fram_valid(void);

/**
 * @brief Erase all parameters in FRAM
 * 
 * @return fmt_err_t FMT_EOK on success, FMT_ERROR on failure
 */
fmt_err_t param_fram_erase(void);

#ifdef __cplusplus
}
#endif

#endif /* PARAM_FRAM_H__ */
