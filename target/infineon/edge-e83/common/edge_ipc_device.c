#include <rtthread.h>
#include <rtdevice.h>
#include <string.h>

#include "board.h"
#include "cy_ipc_pipe.h"

#include "edge_ipc_device.h"

#define EDGE_IPC_RX_QUEUE_SIZE          (128U)

#if defined(COMPONENT_CM33) || ((__CORTEX_M) == 33U)
#define EDGE_IPC_LOCAL_EP_ADDR          CM33_IPC_PIPE_EP_ADDR
#define EDGE_IPC_PEER_EP_ADDR           CM55_IPC_PIPE_EP_ADDR
#define EDGE_IPC_LOCAL_CLIENT_ID        CM33_IPC_PIPE_CLIENT_ID
#define EDGE_IPC_TX_INTR_MASK           CY_IPC_CYPIPE_INTR_MASK_EP1
#define EDGE_IPC_LOCAL_CHAN             CY_IPC_CHAN_CYPIPE_EP1
#define EDGE_IPC_LOCAL_INTR             CY_IPC_INTR_CYPIPE_EP1
#define EDGE_IPC_LOCAL_PRIOR            CY_IPC_INTR_CYPIPE_PRIOR_EP1
#define EDGE_IPC_LOCAL_MUX              CY_IPC_INTR_CYPIPE_MUX_EP1
#define EDGE_IPC_PEER_CHAN              CY_IPC_CHAN_CYPIPE_EP2
#define EDGE_IPC_PEER_INTR              CY_IPC_INTR_CYPIPE_EP2
#define EDGE_IPC_PEER_PRIOR             CY_IPC_INTR_CYPIPE_PRIOR_EP2
#define EDGE_IPC_PEER_MUX               CY_IPC_INTR_CYPIPE_MUX_EP2
#elif defined(COMPONENT_CM55) || ((__CORTEX_M) == 55U)
#define EDGE_IPC_LOCAL_EP_ADDR          CM55_IPC_PIPE_EP_ADDR
#define EDGE_IPC_PEER_EP_ADDR           CM33_IPC_PIPE_EP_ADDR
#define EDGE_IPC_LOCAL_CLIENT_ID        CM55_IPC_PIPE_CLIENT_ID
#define EDGE_IPC_TX_INTR_MASK           CY_IPC_CYPIPE_INTR_MASK_EP2
#define EDGE_IPC_LOCAL_CHAN             CY_IPC_CHAN_CYPIPE_EP2
#define EDGE_IPC_LOCAL_INTR             CY_IPC_INTR_CYPIPE_EP2
#define EDGE_IPC_LOCAL_PRIOR            CY_IPC_INTR_CYPIPE_PRIOR_EP2
#define EDGE_IPC_LOCAL_MUX              CY_IPC_INTR_CYPIPE_MUX_EP2
#define EDGE_IPC_PEER_CHAN              CY_IPC_CHAN_CYPIPE_EP1
#define EDGE_IPC_PEER_INTR              CY_IPC_INTR_CYPIPE_EP1
#define EDGE_IPC_PEER_PRIOR             CY_IPC_INTR_CYPIPE_PRIOR_EP1
#define EDGE_IPC_PEER_MUX               CY_IPC_INTR_CYPIPE_MUX_EP1
#else
#error "Unsupported core for edge_ipc_device"
#endif

struct edge_ipc_device
{
    struct rt_device parent;
    cy_stc_ipc_pipe_ep_t pipe_ep_array[CY_IPC_MAX_ENDPOINTS];
    cy_ipc_pipe_callback_ptr_t cb_array[CY_IPC_CYPIPE_CLIENT_CNT];

    edge_rc_frame_t rx_queue[EDGE_IPC_RX_QUEUE_SIZE];
    volatile rt_uint16_t rx_head;
    volatile rt_uint16_t rx_tail;

    volatile rt_uint32_t tx_pool_idx;
    volatile rt_uint32_t stats_tx_ok;
    volatile rt_uint32_t stats_tx_err;
    volatile rt_uint32_t stats_rx_ok;
    volatile rt_uint32_t stats_rx_err;
    volatile rt_uint32_t stats_rx_drop;
    volatile rt_uint32_t stats_sema_fail;

    rt_bool_t initialized;
};

static struct edge_ipc_device g_edge_ipc_dev;
CY_SECTION_SHAREDMEM static edge_rc_frame_t g_edge_ipc_tx_pool[EDGE_IPC_FRAME_POOL_SIZE];

static rt_bool_t edge_ipc_lock_sema(void)
{
    uint32_t retry = 0;

    while (retry++ < EDGE_IPC_SEMA_RETRY_MAX)
    {
        if (Cy_IPC_Sema_Set(IPC_DEMO_SEMA_NUM, false) == CY_IPC_SEMA_SUCCESS)
        {
            return RT_TRUE;
        }
    }

    return RT_FALSE;
}

static void edge_ipc_unlock_sema(void)
{
    (void)Cy_IPC_Sema_Clear(IPC_DEMO_SEMA_NUM, false);
}

static rt_bool_t edge_ipc_rx_queue_push(struct edge_ipc_device* dev, const edge_rc_frame_t* frame)
{
    rt_base_t level;
    rt_uint16_t next;

    level = rt_hw_interrupt_disable();
    next = (rt_uint16_t)((dev->rx_head + 1U) % EDGE_IPC_RX_QUEUE_SIZE);

    if (next == dev->rx_tail)
    {
        rt_hw_interrupt_enable(level);
        return RT_FALSE;
    }

    dev->rx_queue[dev->rx_head] = *frame;
    dev->rx_head = next;
    rt_hw_interrupt_enable(level);

    return RT_TRUE;
}

static rt_bool_t edge_ipc_rx_queue_pop(struct edge_ipc_device* dev, edge_rc_frame_t* frame)
{
    rt_base_t level;

    level = rt_hw_interrupt_disable();

    if (dev->rx_tail == dev->rx_head)
    {
        rt_hw_interrupt_enable(level);
        return RT_FALSE;
    }

    *frame = dev->rx_queue[dev->rx_tail];
    dev->rx_tail = (rt_uint16_t)((dev->rx_tail + 1U) % EDGE_IPC_RX_QUEUE_SIZE);

    rt_hw_interrupt_enable(level);
    return RT_TRUE;
}

static void edge_ipc_pipe_isr(void)
{
    Cy_IPC_Pipe_ExecuteCallback(EDGE_IPC_LOCAL_EP_ADDR);
}

static void edge_ipc_rx_callback(uint32_t* msg_data)
{
    struct edge_ipc_device* dev = &g_edge_ipc_dev;
    edge_rc_frame_t* rx = (edge_rc_frame_t*)msg_data;

    if (rx == RT_NULL)
    {
        dev->stats_rx_err++;
        return;
    }

    if (rx->client_id != EDGE_IPC_LOCAL_CLIENT_ID
        || rx->magic != RC_MAGIC_WORD
        || edge_rc_checksum(rx) != rx->checksum)
    {
        dev->stats_rx_err++;
        return;
    }

    if (!edge_ipc_rx_queue_push(dev, rx))
    {
        dev->stats_rx_drop++;
        return;
    }

    dev->stats_rx_ok++;

    if (dev->parent.rx_indicate)
    {
        dev->parent.rx_indicate(&dev->parent, 1);
    }
}

static rt_err_t edge_ipc_hw_init(struct edge_ipc_device* dev)
{
    cy_en_ipc_pipe_status_t status;
    cy_stc_ipc_pipe_config_t ipc_config =
    {
        {
            .ipcNotifierNumber = EDGE_IPC_LOCAL_INTR,
            .ipcNotifierPriority = EDGE_IPC_LOCAL_PRIOR,
            .ipcNotifierMuxNumber = EDGE_IPC_LOCAL_MUX,
            .epAddress = EDGE_IPC_LOCAL_EP_ADDR,
            {
                .epChannel = EDGE_IPC_LOCAL_CHAN,
                .epIntr = EDGE_IPC_LOCAL_INTR,
                .epIntrmask = CY_IPC_CYPIPE_INTR_MASK
            }
        },
        {
            .ipcNotifierNumber = EDGE_IPC_PEER_INTR,
            .ipcNotifierPriority = EDGE_IPC_PEER_PRIOR,
            .ipcNotifierMuxNumber = EDGE_IPC_PEER_MUX,
            .epAddress = EDGE_IPC_PEER_EP_ADDR,
            {
                .epChannel = EDGE_IPC_PEER_CHAN,
                .epIntr = EDGE_IPC_PEER_INTR,
                .epIntrmask = CY_IPC_CYPIPE_INTR_MASK
            }
        },
        .endpointClientsCount = CY_IPC_CYPIPE_CLIENT_CNT,
        .endpointsCallbacksArray = RT_NULL,
        .userPipeIsrHandler = &edge_ipc_pipe_isr
    };

    ipc_config.endpointsCallbacksArray = dev->cb_array;

    Cy_IPC_Pipe_Config(dev->pipe_ep_array);
    Cy_IPC_Pipe_Init(&ipc_config);

    status = Cy_IPC_Pipe_RegisterCallback(EDGE_IPC_LOCAL_EP_ADDR,
                                          &edge_ipc_rx_callback,
                                          (uint32_t)EDGE_IPC_LOCAL_CLIENT_ID);

    if (status != CY_IPC_PIPE_SUCCESS)
    {
        return -RT_ERROR;
    }

    dev->initialized = RT_TRUE;
    return RT_EOK;
}

static rt_err_t edge_ipc_dev_init(rt_device_t rt_dev)
{
    struct edge_ipc_device* dev = (struct edge_ipc_device*)rt_dev;

    if (dev->initialized)
    {
        return RT_EOK;
    }

    return edge_ipc_hw_init(dev);
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

    if (buffer == RT_NULL || size == 0)
    {
        return 0;
    }

    while (read_cnt < size)
    {
        if (!edge_ipc_rx_queue_pop(dev, &frame[read_cnt]))
        {
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

    if (buffer == RT_NULL || size == 0)
    {
        return 0;
    }

    while (write_cnt < size)
    {
        edge_rc_frame_t* tx;
        rt_uint32_t slot = dev->tx_pool_idx++ % EDGE_IPC_FRAME_POOL_SIZE;

        tx = &g_edge_ipc_tx_pool[slot];
        *tx = frame[write_cnt];
        tx->client_id = EDGE_IPC_LOCAL_CLIENT_ID == CM33_IPC_PIPE_CLIENT_ID ? CM55_IPC_PIPE_CLIENT_ID : CM33_IPC_PIPE_CLIENT_ID;
        tx->intr_mask = (rt_uint16_t)EDGE_IPC_TX_INTR_MASK;
        tx->magic = RC_MAGIC_WORD;
        tx->checksum = edge_rc_checksum(tx);

        if (!edge_ipc_lock_sema())
        {
            dev->stats_sema_fail++;
            break;
        }

        status = Cy_IPC_Pipe_SendMessage(EDGE_IPC_PEER_EP_ADDR,
                                         EDGE_IPC_LOCAL_EP_ADDR,
                                         (void*)tx,
                                         0UL);
        edge_ipc_unlock_sema();

        if (status != CY_IPC_PIPE_SUCCESS)
        {
            dev->stats_tx_err++;
            break;
        }

        dev->stats_tx_ok++;
        write_cnt++;
    }

    return write_cnt;
}

static rt_err_t edge_ipc_dev_control(rt_device_t rt_dev, int cmd, void* args)
{
    struct edge_ipc_device* dev = (struct edge_ipc_device*)rt_dev;

    if (cmd == EDGE_IPC_CTRL_GET_STATS)
    {
        edge_ipc_device_stats_t* stats = (edge_ipc_device_stats_t*)args;

        if (stats == RT_NULL)
        {
            return -RT_EINVAL;
        }

        stats->tx_ok = dev->stats_tx_ok;
        stats->tx_err = dev->stats_tx_err;
        stats->rx_ok = dev->stats_rx_ok;
        stats->rx_err = dev->stats_rx_err;
        stats->rx_drop = dev->stats_rx_drop;
        stats->sema_fail = dev->stats_sema_fail;

        return RT_EOK;
    }

    return -RT_ENOSYS;
}

#ifdef RT_USING_DEVICE_OPS
static const struct rt_device_ops edge_ipc_dev_ops =
{
    edge_ipc_dev_init,
    edge_ipc_dev_open,
    edge_ipc_dev_close,
    edge_ipc_dev_read,
    edge_ipc_dev_write,
    edge_ipc_dev_control
};
#endif

rt_device_t edge_ipc_device_find(void)
{
    return rt_device_find(EDGE_IPC_DEVICE_NAME);
}

int edge_ipc_device_register(void)
{
    struct edge_ipc_device* dev = &g_edge_ipc_dev;

    rt_memset(dev, 0, sizeof(*dev));

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

    return rt_device_register(&dev->parent,
                              EDGE_IPC_DEVICE_NAME,
                              RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
}
INIT_PREV_EXPORT(edge_ipc_device_register);
