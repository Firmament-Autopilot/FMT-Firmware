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
#include <firmament.h>

#include "hal/sd/sd.h"

static rt_err_t init(sd_dev_t sd)
{
    return RT_EOK;
}

static rt_err_t write_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;

    return err;
}

static rt_err_t read_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;

    return err;
}

static rt_err_t io_control(sd_dev_t sd, int cmd, void* arg)
{
    return RT_EOK;
}

const static struct sd_ops dev_ops = {
    .init = init,
    .write_disk = write_disk,
    .read_disk = read_disk,
    .io_control = io_control
};

rt_err_t drv_sdio_init(void)
{
    return RT_EOK;
}
