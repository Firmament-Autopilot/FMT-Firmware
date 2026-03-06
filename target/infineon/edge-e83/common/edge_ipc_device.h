#ifndef EDGE_IPC_DEVICE_H
#define EDGE_IPC_DEVICE_H

#include <rtthread.h>
#include "edge_ipc_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define EDGE_IPC_DEVICE_NAME            "ipc0"
#define EDGE_IPC_CTRL_GET_STATS         (0x1000)

typedef struct
{
    rt_uint32_t tx_ok;
    rt_uint32_t tx_err;
    rt_uint32_t rx_ok;
    rt_uint32_t rx_err;
    rt_uint32_t rx_drop;
    rt_uint32_t sema_fail;
} edge_ipc_device_stats_t;

rt_device_t edge_ipc_device_find(void);
int edge_ipc_device_register(void);

#ifdef __cplusplus
}
#endif

#endif
