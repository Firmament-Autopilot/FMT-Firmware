/****************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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
#ifndef E83_DRV_DSHOT_H__
#define E83_DRV_DSHOT_H__

#include "hal/actuator/actuator.h"

#define E83_DSHOT_CHANNELS (4U)

rt_err_t drv_dshot_configure(const struct actuator_configure* cfg);
rt_err_t drv_dshot_enable(void);
rt_err_t drv_dshot_disable(void);
rt_size_t drv_dshot_write(rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size);
rt_size_t drv_dshot_read(rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size);

#endif /* E83_DRV_DSHOT_H__ */
