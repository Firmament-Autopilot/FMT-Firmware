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
#ifndef DEVMQ_H__
#define DEVMQ_H__

#ifdef __cplusplus
extern "C" {
#endif

/* device status msg */
#define DEVICE_STATUS_CONNECT    (1)
#define DEVICE_STAUTS_DISCONNECT (2)
#define DEVICE_STATUS_RX         (3)
#define DEVICE_STATUS_TX         (4)

typedef int device_status;

fmt_err_t devmq_create(rt_device_t device, uint32_t msg_size, uint32_t max_msgs);
fmt_err_t devmq_register(rt_device_t device, void (*handler)(rt_device_t dev, void* msg));
fmt_err_t devmq_deregister(rt_device_t device);
fmt_err_t devmq_notify(rt_device_t device, void* msg);
void devmq_distribute_msg(void* parameter);
fmt_err_t devmq_start_work(void);

#ifdef __cplusplus
}
#endif

#endif /* DEVMQ_H__ */
