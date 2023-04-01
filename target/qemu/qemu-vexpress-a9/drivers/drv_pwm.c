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
#include <firmament.h>

#include "hal/actuator/actuator.h"

const static struct actuator_ops __act_ops = {
    .act_config = RT_NULL,
    .act_control = RT_NULL,
    .act_read = RT_NULL,
    .act_write = RT_NULL
};

//TODO modify channel mask
static struct actuator_device act_dev = {
    .ops = &__act_ops
};

rt_err_t drv_pwm_init(void)
{
    rt_err_t ret = RT_EOK;

    /* register actuator hal device */
    ret = hal_actuator_register(&act_dev, "null_out", RT_DEVICE_FLAG_RDWR, NULL);

    return ret;
}