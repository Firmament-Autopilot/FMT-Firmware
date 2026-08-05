/******************************************************************************
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
#include <rtdevice.h>
#include <rtthread.h>
#include <string.h>

#include "board.h"
#include "cy_ipc_pipe.h"

#include "drv_ipc.h"

#define EDGE_IPC_RX_QUEUE_SIZE (128U)

#define CY_IPC0_CHAN_CYPIPE_EP1       (5UL)
#define CY_IPC0_INTR_CYPIPE_EP1       (3UL)
#define CY_IPC0_CHAN_CYPIPE_EP2       (14UL)
#define CY_IPC0_INTR_CYPIPE_EP2       (6UL)
#define CY_IPC0_CYPIPE_INTR_MASK      (CY_IPC_CH_MASK(CY_IPC0_CHAN_CYPIPE_EP1) | \
                                        CY_IPC_CH_MASK(CY_IPC0_CHAN_CYPIPE_EP2))

#if defined(COMPONENT_CM33) || ((__CORTEX_M) == 33U)
    #define EDGE_IPC0_LOCAL_EP_ADDR   (1UL)
    #define EDGE_IPC0_PEER_EP_ADDR    (2UL)
    #define EDGE_IPC0_LOCAL_CLIENT_ID CM33_IPC_PIPE_CLIENT_ID
    #define EDGE_IPC0_TX_INTR_MASK    CY_IPC_INTR_MASK(CY_IPC0_INTR_CYPIPE_EP1)
    #define EDGE_IPC0_LOCAL_CHAN      CY_IPC0_CHAN_CYPIPE_EP1
    #define EDGE_IPC0_LOCAL_INTR      CY_IPC0_INTR_CYPIPE_EP1
    #define EDGE_IPC0_LOCAL_PRIOR     (1UL)
    #define EDGE_IPC0_LOCAL_MUX       (CY_IPC0_INTR_MUX(CY_IPC0_INTR_CYPIPE_EP1))
    #define EDGE_IPC0_PEER_CHAN       CY_IPC0_CHAN_CYPIPE_EP2
    #define EDGE_IPC0_PEER_INTR       CY_IPC0_INTR_CYPIPE_EP2
    #define EDGE_IPC0_PEER_PRIOR      (1UL)
    #define EDGE_IPC0_PEER_MUX        (CY_IPC0_INTR_MUX(CY_IPC0_INTR_CYPIPE_EP2))
#elif defined(COMPONENT_CM55) || ((__CORTEX_M) == 55U)
    #define EDGE_IPC0_LOCAL_EP_ADDR   (2UL)
    #define EDGE_IPC0_PEER_EP_ADDR    (1UL)
    #define EDGE_IPC0_LOCAL_CLIENT_ID CM55_IPC_PIPE_CLIENT_ID
    #define EDGE_IPC0_TX_INTR_MASK    CY_IPC_INTR_MASK(CY_IPC0_INTR_CYPIPE_EP2)
    #define EDGE_IPC0_LOCAL_CHAN      CY_IPC0_CHAN_CYPIPE_EP2
    #define EDGE_IPC0_LOCAL_INTR      CY_IPC0_INTR_CYPIPE_EP2
    #define EDGE_IPC0_LOCAL_PRIOR     (1UL)
    #define EDGE_IPC0_LOCAL_MUX       (CY_IPC0_INTR_MUX(CY_IPC0_INTR_CYPIPE_EP2))
    #define EDGE_IPC0_PEER_CHAN       CY_IPC0_CHAN_CYPIPE_EP1
    #define EDGE_IPC0_PEER_INTR       CY_IPC0_INTR_CYPIPE_EP1
    #define EDGE_IPC0_PEER_PRIOR      (1UL)
    #define EDGE_IPC0_PEER_MUX        (CY_IPC0_INTR_MUX(CY_IPC0_INTR_CYPIPE_EP1))
#else
    #error "Unsupported core for edge_ipc0"
#endif


#define CY_IPC1_CHAN_CYPIPE_EP3       (6UL)
#define CY_IPC1_INTR_CYPIPE_EP3       (4UL)
#define CY_IPC1_CHAN_CYPIPE_EP4       (15UL)
#define CY_IPC1_INTR_CYPIPE_EP4       (7UL)
#define CY_IPC1_CYPIPE_INTR_MASK      (CY_IPC_CH_MASK(CY_IPC1_CHAN_CYPIPE_EP3) | \
                                        CY_IPC_CH_MASK(CY_IPC1_CHAN_CYPIPE_EP4))

#if defined(COMPONENT_CM33) || ((__CORTEX_M) == 33U)
    #define EDGE_IPC1_LOCAL_EP_ADDR   (3UL)
    #define EDGE_IPC1_PEER_EP_ADDR    (4UL)
    #define EDGE_IPC1_LOCAL_CLIENT_ID CM33_IPC_PIPE_CLIENT_ID
    #define EDGE_IPC1_TX_INTR_MASK    CY_IPC_INTR_MASK(CY_IPC1_INTR_CYPIPE_EP3)
    #define EDGE_IPC1_LOCAL_CHAN      CY_IPC1_CHAN_CYPIPE_EP3
    #define EDGE_IPC1_LOCAL_INTR      CY_IPC1_INTR_CYPIPE_EP3
    #define EDGE_IPC1_LOCAL_PRIOR     (1UL)
    #define EDGE_IPC1_LOCAL_MUX       (CY_IPC0_INTR_MUX(CY_IPC1_INTR_CYPIPE_EP3))
    #define EDGE_IPC1_PEER_CHAN       CY_IPC1_CHAN_CYPIPE_EP4
    #define EDGE_IPC1_PEER_INTR       CY_IPC1_INTR_CYPIPE_EP4
    #define EDGE_IPC1_PEER_PRIOR      (1UL)
    #define EDGE_IPC1_PEER_MUX        (CY_IPC0_INTR_MUX(CY_IPC1_INTR_CYPIPE_EP4))
#elif defined(COMPONENT_CM55) || ((__CORTEX_M) == 55U)
    #define EDGE_IPC1_LOCAL_EP_ADDR   (4UL)
    #define EDGE_IPC1_PEER_EP_ADDR    (3UL)
    #define EDGE_IPC1_LOCAL_CLIENT_ID CM55_IPC_PIPE_CLIENT_ID
    #define EDGE_IPC1_TX_INTR_MASK    CY_IPC_INTR_MASK(CY_IPC1_INTR_CYPIPE_EP4)
    #define EDGE_IPC1_LOCAL_CHAN      CY_IPC1_CHAN_CYPIPE_EP4
    #define EDGE_IPC1_LOCAL_INTR      CY_IPC1_INTR_CYPIPE_EP4
    #define EDGE_IPC1_LOCAL_PRIOR     (1UL)
    #define EDGE_IPC1_LOCAL_MUX       (CY_IPC0_INTR_MUX(CY_IPC1_INTR_CYPIPE_EP4))
    #define EDGE_IPC1_PEER_CHAN       CY_IPC1_CHAN_CYPIPE_EP3
    #define EDGE_IPC1_PEER_INTR       CY_IPC1_INTR_CYPIPE_EP3
    #define EDGE_IPC1_PEER_PRIOR      (1UL)
    #define EDGE_IPC1_PEER_MUX        (CY_IPC0_INTR_MUX(CY_IPC1_INTR_CYPIPE_EP3))
#else
    #error "Unsupported core for edge_ipc1"
#endif

struct edge_ipc_device {
    struct rt_device parent;
    cy_stc_ipc_pipe_ep_t pipe_ep_array[CY_IPC_MAX_ENDPOINTS];
    cy_ipc_pipe_callback_ptr_t cb_array[CY_IPC_CYPIPE_CLIENT_CNT];

    /* PIPE 配置信息 */
    uint32_t local_ep_addr;
    uint32_t peer_ep_addr;
    uint32_t tx_intr_mask;
    uint8_t  pipe_index;

    /* 接收缓冲 */
    rt_uint8_t rx_buffer[EDGE_IPC_RX_QUEUE_SIZE * sizeof(edge_rc_frame_t)];
    struct rt_ringbuffer rx_rb;

    /* 发送池索引 */
    volatile rt_uint32_t tx_pool_idx;

    rt_bool_t initialized;
};

/* 两个 IPC 设备实例 */
static struct edge_ipc_device g_edge_ipc_dev[2];

CY_SECTION_SHAREDMEM static edge_rc_frame_t g_edge_ipc_tx_pool[2][EDGE_IPC_FRAME_POOL_SIZE];

static void edge_ipc0_pipe_isr(void)
{
    Cy_IPC_Pipe_ExecuteCallback(EDGE_IPC0_LOCAL_EP_ADDR);
}

static void edge_ipc0_rx_callback(uint32_t* msg_data)
{
    struct edge_ipc_device* dev = &g_edge_ipc_dev[0];
    edge_rc_frame_t* rx = (edge_rc_frame_t*)msg_data;

    if (rx == RT_NULL)
        return;

    if (rx->client_id != EDGE_IPC0_LOCAL_CLIENT_ID
        || rx->magic != RC_MAGIC_WORD
        || edge_rc_checksum(rx) != rx->checksum)
        return;

    if (rt_ringbuffer_put(&dev->rx_rb, (rt_uint8_t*)rx, sizeof(edge_rc_frame_t)) != sizeof(edge_rc_frame_t))
        return;

    if (dev->parent.rx_indicate) {
        dev->parent.rx_indicate(&dev->parent, 1);
    }
}

static void edge_ipc1_pipe_isr(void)
{
    Cy_IPC_Pipe_ExecuteCallback(EDGE_IPC1_LOCAL_EP_ADDR);
}

static void edge_ipc1_rx_callback(uint32_t* msg_data)
{
    struct edge_ipc_device* dev = &g_edge_ipc_dev[1];
    edge_rc_frame_t* rx = (edge_rc_frame_t*)msg_data;

    if (rx == RT_NULL)
        return;

    if (rx->client_id != EDGE_IPC1_LOCAL_CLIENT_ID
        || rx->magic != RC_MAGIC_WORD
        || edge_rc_checksum(rx) != rx->checksum)
        return;

    if (rt_ringbuffer_put(&dev->rx_rb, (rt_uint8_t*)rx, sizeof(edge_rc_frame_t)) != sizeof(edge_rc_frame_t))
        return;

    if (dev->parent.rx_indicate) {
        dev->parent.rx_indicate(&dev->parent, 1);
    }
}

static cy_stc_ipc_pipe_config_t ipc0_config = {
    { .ipcNotifierNumber = EDGE_IPC0_LOCAL_INTR,
      .ipcNotifierPriority = EDGE_IPC0_LOCAL_PRIOR,
      .ipcNotifierMuxNumber = EDGE_IPC0_LOCAL_MUX,
      .epAddress = EDGE_IPC0_LOCAL_EP_ADDR,
      { .epChannel = EDGE_IPC0_LOCAL_CHAN,
        .epIntr = EDGE_IPC0_LOCAL_INTR,
        .epIntrmask = CY_IPC0_CYPIPE_INTR_MASK } },
    { .ipcNotifierNumber = EDGE_IPC0_PEER_INTR,
      .ipcNotifierPriority = EDGE_IPC0_PEER_PRIOR,
      .ipcNotifierMuxNumber = EDGE_IPC0_PEER_MUX,
      .epAddress = EDGE_IPC0_PEER_EP_ADDR,
      { .epChannel = EDGE_IPC0_PEER_CHAN,
        .epIntr = EDGE_IPC0_PEER_INTR,
        .epIntrmask = CY_IPC0_CYPIPE_INTR_MASK } },
    .endpointClientsCount = CY_IPC_CYPIPE_CLIENT_CNT,
    .endpointsCallbacksArray = RT_NULL,
    .userPipeIsrHandler = &edge_ipc0_pipe_isr
};

static cy_stc_ipc_pipe_config_t ipc1_config = {
    { .ipcNotifierNumber = EDGE_IPC1_LOCAL_INTR,
      .ipcNotifierPriority = EDGE_IPC1_LOCAL_PRIOR,
      .ipcNotifierMuxNumber = EDGE_IPC1_LOCAL_MUX,
      .epAddress = EDGE_IPC1_LOCAL_EP_ADDR,
      { .epChannel = EDGE_IPC1_LOCAL_CHAN,
        .epIntr = EDGE_IPC1_LOCAL_INTR,
        .epIntrmask = CY_IPC1_CYPIPE_INTR_MASK } },
    { .ipcNotifierNumber = EDGE_IPC1_PEER_INTR,
      .ipcNotifierPriority = EDGE_IPC1_PEER_PRIOR,
      .ipcNotifierMuxNumber = EDGE_IPC1_PEER_MUX,
      .epAddress = EDGE_IPC1_PEER_EP_ADDR,
      { .epChannel = EDGE_IPC1_PEER_CHAN,
        .epIntr = EDGE_IPC1_PEER_INTR,
        .epIntrmask = CY_IPC1_CYPIPE_INTR_MASK } },
    .endpointClientsCount = CY_IPC_CYPIPE_CLIENT_CNT,
    .endpointsCallbacksArray = RT_NULL,
    .userPipeIsrHandler = &edge_ipc1_pipe_isr
};

/*******************************************************************************
 * 硬件初始化
 ******************************************************************************/
static rt_err_t edge_ipc_hw_init(struct edge_ipc_device* dev,
                                  uint8_t pipe_idx,
                                  cy_stc_ipc_pipe_config_t* config)
{
    cy_en_ipc_pipe_status_t status;

    if (config == RT_NULL || pipe_idx >= 2) {
        return -RT_ERROR;
    }

    dev->local_ep_addr = config->ep0ConfigData.epAddress;
    dev->peer_ep_addr = config->ep1ConfigData.epAddress;
    dev->pipe_index = pipe_idx;
    dev->tx_pool_idx = 0;

    switch (pipe_idx) {
        case 0:
            dev->tx_intr_mask = EDGE_IPC0_TX_INTR_MASK;
            break;
        case 1:
            dev->tx_intr_mask = EDGE_IPC1_TX_INTR_MASK;
            break;
        default:
            return -RT_ERROR;
    }

    config->endpointsCallbacksArray = dev->cb_array;

    if (!dev->initialized) {
        Cy_IPC_Pipe_Config(dev->pipe_ep_array);
    }

    Cy_IPC_Pipe_Init(config);

    /* 注册接收回调 */
    {
        cy_ipc_pipe_callback_ptr_t rx_cb = RT_NULL;
        uint32_t client_id;

        switch (pipe_idx) {
            case 0:
                rx_cb = edge_ipc0_rx_callback;
                client_id = EDGE_IPC0_LOCAL_CLIENT_ID;
                break;
            case 1:
                rx_cb = edge_ipc1_rx_callback;
                client_id = EDGE_IPC1_LOCAL_CLIENT_ID;
                break;
            default:
                return -RT_ERROR;
        }

        status = Cy_IPC_Pipe_RegisterCallback(dev->local_ep_addr, rx_cb, client_id);
        if (status != CY_IPC_PIPE_SUCCESS) {
            return -RT_ERROR;
        }
    }

    dev->initialized = RT_TRUE;
    return RT_EOK;
}

static rt_err_t edge_ipc_dev_init(rt_device_t rt_dev)
{
    struct edge_ipc_device* dev = (struct edge_ipc_device*)rt_dev;

    if (dev->initialized)
        return RT_EOK;

    switch (dev->pipe_index) {
        case 0:
            return edge_ipc_hw_init(dev, 0, &ipc0_config);
        case 1:
            return edge_ipc_hw_init(dev, 1, &ipc1_config);
        default:
            return -RT_ERROR;
    }
}

static rt_err_t edge_ipc_dev_open(rt_device_t rt_dev, rt_uint16_t oflag)
{
    (void)rt_dev;
    (void)oflag;
    return RT_EOK;
}

static rt_err_t edge_ipc_dev_close(rt_device_t rt_dev)
{
    (void)rt_dev;
    return RT_EOK;
}

static rt_size_t edge_ipc_dev_read(rt_device_t rt_dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    struct edge_ipc_device* dev = (struct edge_ipc_device*)rt_dev;
    edge_rc_frame_t* frame = (edge_rc_frame_t*)buffer;
    rt_size_t read_cnt = 0;

    (void)pos;

    if (buffer == RT_NULL || size == 0) {
        return 0;
    }

    while (read_cnt < size) {
        if (rt_ringbuffer_get(&dev->rx_rb, (rt_uint8_t*)&frame[read_cnt], sizeof(edge_rc_frame_t)) != sizeof(edge_rc_frame_t)) {
            break;
        }
        read_cnt++;
    }

    return read_cnt;
}

static rt_size_t edge_ipc_dev_write(rt_device_t rt_dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    struct edge_ipc_device* dev = (struct edge_ipc_device*)rt_dev;
    const edge_rc_frame_t* frame = (const edge_rc_frame_t*)buffer;
    rt_size_t write_cnt = 0;
    cy_en_ipc_pipe_status_t status;

    (void)pos;

    if (buffer == RT_NULL || size == 0) {
        return 0;
    }

    while (write_cnt < size) {
        rt_uint32_t slot = dev->tx_pool_idx++ % EDGE_IPC_FRAME_POOL_SIZE;
        edge_rc_frame_t* tx = &g_edge_ipc_tx_pool[dev->pipe_index][slot];

        *tx = frame[write_cnt];

        
        if (write_cnt > 0) {
            rt_thread_mdelay(1);
        }

#if defined(COMPONENT_CM33) || ((__CORTEX_M) == 33U)
        tx->client_id = CM55_IPC_PIPE_CLIENT_ID;
        tx->role = RC_ROLE_M33;
#elif defined(COMPONENT_CM55) || ((__CORTEX_M) == 55U)
        tx->client_id = CM33_IPC_PIPE_CLIENT_ID;
        tx->role = RC_ROLE_M55_ECHO;
#else
    #error "Unsupported core for edge_ipc_device"
#endif
        tx->intr_mask = (rt_uint16_t)dev->tx_intr_mask;
        tx->magic = RC_MAGIC_WORD;
        tx->checksum = edge_rc_checksum(tx);
        status = Cy_IPC_Pipe_SendMessage(dev->peer_ep_addr,
                                         dev->local_ep_addr,
                                         (void*)tx,
                                         0UL);

        if (status == CY_IPC_PIPE_ERROR_SEND_BUSY) {
            uint32_t retry = 0;
            const uint32_t max_retry = 1000;

            while (retry < max_retry) {
                retry++;
                uint32_t delay_ms = (retry > 10) ? 10 : retry;
                rt_thread_delay(delay_ms);

                status = Cy_IPC_Pipe_SendMessage(dev->peer_ep_addr,
                                                dev->local_ep_addr,
                                                (void*)tx,
                                                0UL);

                if (status == CY_IPC_PIPE_SUCCESS) {
                    break;
                }

                if (status != CY_IPC_PIPE_ERROR_SEND_BUSY) {
                    break;
                }
            }
        }

        if (status != CY_IPC_PIPE_SUCCESS) {
            break;
        }
        if (dev->parent.tx_complete) {
            dev->parent.tx_complete(&dev->parent, RT_NULL);
        }
        write_cnt++;
    }

    return write_cnt;
}

static rt_err_t edge_ipc_dev_control(rt_device_t rt_dev, int cmd, void* args)
{
    struct edge_ipc_device* dev = (struct edge_ipc_device*)rt_dev;

    if (cmd == EDGE_IPC_CTRL_GET_RINGBUFFER) {
        if (args != RT_NULL) {
            *(struct rt_ringbuffer**)args = &dev->rx_rb;
            return RT_EOK;
        }
        return -RT_EINVAL;
    }

    return -RT_ENOSYS;
}

#ifdef RT_USING_DEVICE_OPS
static const struct rt_device_ops edge_ipc_dev_ops = {
    edge_ipc_dev_init,
    edge_ipc_dev_open,
    edge_ipc_dev_close,
    edge_ipc_dev_read,
    edge_ipc_dev_write,
    edge_ipc_dev_control
};
#endif

rt_device_t edge_ipc_device_find(const char* name)
{
    return rt_device_find(name);
}

int edge_ipc_device_register(void)
{
    struct edge_ipc_device* dev;
    rt_err_t result;
    dev = &g_edge_ipc_dev[0];
    rt_memset(dev, 0, sizeof(*dev));
    dev->pipe_index = 0;

    rt_ringbuffer_init(&dev->rx_rb, dev->rx_buffer, sizeof(dev->rx_buffer));

#ifdef RT_USING_DEVICE_OPS
    dev->parent.ops = &edge_ipc_dev_ops;
#else
    dev->parent.init = edge_ipc_dev_init;
    dev->parent.open = edge_ipc_dev_open;
    dev->parent.close = edge_ipc_dev_close;
    dev->parent.read = edge_ipc_dev_read;
    dev->parent.write = edge_ipc_dev_write;
    dev->parent.control = edge_ipc_dev_control;
#endif

    result = rt_device_register(&dev->parent,
                                EDGE_IPC0_DEVICE_NAME,
                                RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
    if (result != RT_EOK) {
        rt_kprintf("[IPC] Failed to register %s\n", EDGE_IPC0_DEVICE_NAME);
        return result;
    }
    rt_kprintf("[IPC] Device '%s' registered (PIPE0, M33->M55)\n", EDGE_IPC0_DEVICE_NAME);
    dev = &g_edge_ipc_dev[1];
    rt_memset(dev, 0, sizeof(*dev));
    dev->pipe_index = 1;

    rt_ringbuffer_init(&dev->rx_rb, dev->rx_buffer, sizeof(dev->rx_buffer));

#ifdef RT_USING_DEVICE_OPS
    dev->parent.ops = &edge_ipc_dev_ops;
#else
    dev->parent.init = edge_ipc_dev_init;
    dev->parent.open = edge_ipc_dev_open;
    dev->parent.close = edge_ipc_dev_close;
    dev->parent.read = edge_ipc_dev_read;
    dev->parent.write = edge_ipc_dev_write;
    dev->parent.control = edge_ipc_dev_control;
#endif

    result = rt_device_register(&dev->parent,
                                EDGE_IPC1_DEVICE_NAME,
                                RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
    if (result != RT_EOK) {
        rt_kprintf("[IPC] Failed to register %s\n", EDGE_IPC1_DEVICE_NAME);
        return result;
    }
    rt_kprintf("[IPC] Device '%s' registered (PIPE1, M55->M33)\n", EDGE_IPC1_DEVICE_NAME);

    return RT_EOK;
}
INIT_PREV_EXPORT(edge_ipc_device_register);
