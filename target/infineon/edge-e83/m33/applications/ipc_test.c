#include <rtthread.h>
#include <rtdevice.h>
#include <string.h>

#include "edge_ipc_device.h"
#include "edge_ipc_common.h"

#define EDGE_IPC_DEMO_HZ               (500U)
#define EDGE_IPC_DEMO_PRINT_MS          (5000U)

static void cm33_dump_frame(const edge_rc_frame_t* frame)
{
    rt_kprintf("[M33][IPC] seq=%lu ch=[%u,%u,%u,%u,%u,%u,%u,%u]\r\n",
               frame->seq,
               frame->channel[0],
               frame->channel[1],
               frame->channel[2],
               frame->channel[3],
               frame->channel[4],
               frame->channel[5],
               frame->channel[6],
               frame->channel[7]);
}

static void cm33_fill_rc_frame(edge_rc_frame_t* frame, rt_uint32_t seq)
{
    rt_uint32_t i;

    frame->client_id = CM55_IPC_PIPE_CLIENT_ID;
    frame->intr_mask = (rt_uint16_t)CY_IPC_CYPIPE_INTR_MASK_EP1;
    frame->role = RC_ROLE_M33;
    frame->magic = RC_MAGIC_WORD;
    frame->seq = seq;

    for (i = 0; i < RC_CHANNEL_COUNT; i++)
    {
        frame->channel[i] = (rt_uint16_t)(1000U + (i * 100U) + (seq % 500U));
    }

    frame->checksum = edge_rc_checksum(frame);
}

static rt_bool_t cm33_verify_echo(const edge_rc_frame_t* frame)
{
    edge_rc_frame_t expected;

    if (frame->role != RC_ROLE_M55_ECHO || frame->magic != RC_MAGIC_WORD)
    {
        return RT_FALSE;
    }

    if (edge_rc_checksum(frame) != frame->checksum)
    {
        return RT_FALSE;
    }

    cm33_fill_rc_frame(&expected, frame->seq);

    if (rt_memcmp(frame->channel, expected.channel, sizeof(expected.channel)) != 0)
    {
        return RT_FALSE;
    }

    return RT_TRUE;
}

static rt_tick_t cm33_calc_delay_tick(void)
{
    rt_tick_t delay_tick;

    delay_tick = (EDGE_IPC_DEMO_HZ >= RT_TICK_PER_SECOND) ? 1U : (RT_TICK_PER_SECOND / EDGE_IPC_DEMO_HZ);
    if (delay_tick == 0U)
    {
        delay_tick = 1U;
    }

    return delay_tick;
}

void ipc_test_run(void)
{
    rt_device_t ipc_dev;
    edge_rc_frame_t tx;
    edge_rc_frame_t rx;
    edge_rc_frame_t last_ok;
    rt_tick_t delay_tick;
    rt_tick_t print_tick;
    rt_uint32_t seq = 1U;
    rt_uint32_t ok_cnt = 0;
    rt_uint32_t fail_cnt = 0;
    rt_bool_t has_ok = RT_FALSE;

    ipc_dev = edge_ipc_device_find();
    if (ipc_dev == RT_NULL)
    {
        if (edge_ipc_device_register() != RT_EOK)
        {
            rt_kprintf("[M33][IPC] device register failed\r\n");
            return;
        }

        ipc_dev = edge_ipc_device_find();
        if (ipc_dev == RT_NULL)
        {
            rt_kprintf("[M33][IPC] device not found\r\n");
            return;
        }
    }

    if (rt_device_open(ipc_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK)
    {
        rt_kprintf("[M33][IPC] open device failed\r\n");
        return;
    }

    delay_tick = cm33_calc_delay_tick();
    print_tick = rt_tick_get();
    rt_kprintf("[M33][IPC] demo start hz=%u\r\n", EDGE_IPC_DEMO_HZ);

    while (1)
    {
        rt_uint32_t wait_loop = 0;

        cm33_fill_rc_frame(&tx, seq);
        if (rt_device_write(ipc_dev, 0, &tx, 1) == 1)
        {
            while (wait_loop++ < 10U)
            {
                if (rt_device_read(ipc_dev, 0, &rx, 1) == 1)
                {
                    if (cm33_verify_echo(&rx))
                    {
                        last_ok = rx;
                        has_ok = RT_TRUE;
                        ok_cnt++;
                        break;
                    }
                    else
                    {
                        fail_cnt++;
                        rt_kprintf("[M33][IPC][ERR] verify failed: seq=%lu role=0x%02X magic=0x%08lX\r\n",
                                   rx.seq,
                                   rx.role,
                                   rx.magic);
                    }
                }
                else
                {
                    rt_thread_mdelay(1U);
                }
            }

            seq++;
        }

        if ((rt_tick_get() - print_tick) >= rt_tick_from_millisecond(EDGE_IPC_DEMO_PRINT_MS))
        {
            rt_kprintf("[M33][IPC] PASS=%lu FAIL=%lu\r\n", ok_cnt, fail_cnt);
            if (has_ok)
            {
                cm33_dump_frame(&last_ok);
            }
            print_tick = rt_tick_get();
        }

        rt_thread_delay(delay_tick);
    }
}
MSH_CMD_EXPORT(ipc_test_run, M33 ipc test);