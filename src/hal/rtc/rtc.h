/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#ifndef RTC_H__
#define RTC_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RTC_BKP_MAGIC 0x32F2

struct rtc_device {
    struct rt_device parent;
    const struct rtc_ops* ops;
};
typedef struct rtc_device* rtc_dev_t;

struct rtc_ops {
    /**
     * @brief rtc init
     * @param dev systick device
     */
    rt_err_t (*init)(rtc_dev_t dev);
    /**
     * @brief read rtc value
     * @param dev rtc device
     * @param time rtc time
     */
    rt_err_t (*read)(rtc_dev_t dev, struct rtc_time* time);
    /**
     * @brief rtc write
     * @param dev rtc device
     * @param time rtc time
     */
    rt_err_t (*write)(rtc_dev_t dev, const struct rtc_time* time);
};

rt_err_t hal_rtc_register(rtc_dev_t rtc, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
