/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#ifndef ADC_H__
#define ADC_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    ADC_CMD_DISABLE = 0,
    ADC_CMD_ENABLE = 1,
};

struct adc_device {
    struct rt_device parent;
    const struct adc_ops* ops;
    rt_mutex_t lock;
};
typedef struct adc_device* adc_dev_t;

/* adc driver opeations */
struct adc_ops {
    rt_err_t (*enable)(adc_dev_t adc_dev, uint8_t enable);
    rt_err_t (*measure)(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt);
};

rt_err_t hal_adc_register(adc_dev_t adc_dev, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif /* ADC_H__ */
