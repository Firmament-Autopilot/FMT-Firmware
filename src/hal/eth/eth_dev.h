/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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
#ifndef ETH_DEV_H__
#define ETH_DEV_H__

#include <lwip/sockets.h>

#include "module/utils/ringbuffer.h"

#ifdef __cplusplus
extern "C" {
#endif

struct eth_dev {
    struct rt_device parent;
    struct udp_pcb* udp_pcb;
    ringbuffer* rx_rb;
    struct rt_completion rx_ind;
    ip_addr_t local_addr, remote_addr;
    uint16_t local_port, remote_port;
};
typedef struct eth_dev* eth_dev_t;

void init_eth_dev(eth_dev_t eth);
rt_err_t hal_eth_dev_register(eth_dev_t eth, const char* name, rt_uint16_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif