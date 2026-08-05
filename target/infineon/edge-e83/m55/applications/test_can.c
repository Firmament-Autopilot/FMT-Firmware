#include <firmament.h>
#include <stdlib.h>

#include "hal/can/can.h"

static rt_device_t can_dev = RT_NULL;
static rt_sem_t rx_sem = RT_NULL;
static rt_thread_t rx_thread = RT_NULL;
static volatile bool rx_thread_run = false;

static void can_test_usage(void)
{
    rt_kprintf("can_test init\n");
    rt_kprintf("can_test deinit\n");
    rt_kprintf("can_test send <std_id> [byte0] [byte1] ... [byte7]\n");
    rt_kprintf("can_test sendext <ext_id> [byte0] [byte1] ... [byte7]\n");
    rt_kprintf("example: can_test send 0x123 0x11 0x22 0x33\n");
}

static rt_err_t can_rx_ind(rt_device_t dev, rt_size_t size)
{
    (void)dev;
    (void)size;

    if (rx_sem != RT_NULL) {
        rt_sem_release(rx_sem);
    }

    return RT_EOK;
}

static void can_dump_msg(const char* prefix, const can_msg* msg)
{
    uint32_t id = (msg->id_type == CAN_ID_EXTENDED) ? msg->ext_id : msg->std_id;

    rt_kprintf("%s ID:0x%08lX Type:%s Len:%ld Data:",
               prefix,
               (unsigned long)id,
               (msg->id_type == CAN_ID_EXTENDED) ? "EXT" : "STD",
               (long)msg->data_len);

    for (uint32_t i = 0; i < msg->data_len; i++) {
        rt_kprintf(" %02X", msg->data[i]);
    }
    rt_kprintf("\n");
}

static void can_rx_thread_entry(void* parameter)
{
    can_msg msg;

    (void)parameter;

    while (rx_thread_run) {
        if (rt_sem_take(rx_sem, RT_WAITING_FOREVER) != RT_EOK) {
            continue;
        }

        while (rx_thread_run && rt_device_read(can_dev, 0, &msg, 1) == 1) {
            can_dump_msg("CAN RX", &msg);
        }
    }
}

static int can_test_init(void)
{
    rt_err_t ret;

    if (can_dev != RT_NULL) {
        rt_kprintf("can_test already initialized\n");
        return 0;
    }

    can_dev = rt_device_find("can0");
    if (can_dev == RT_NULL) {
        rt_kprintf("cannot find can0\n");
        return -RT_ERROR;
    }

    rx_sem = rt_sem_create("canrx", 0, RT_IPC_FLAG_FIFO);
    if (rx_sem == RT_NULL) {
        rt_kprintf("create rx semaphore failed\n");
        can_dev = RT_NULL;
        return -RT_ENOMEM;
    }

    ret = rt_device_open(can_dev, RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
    if (ret != RT_EOK) {
        rt_kprintf("open can0 failed: %d\n", ret);
        rt_sem_delete(rx_sem);
        rx_sem = RT_NULL;
        can_dev = RT_NULL;
        return ret;
    }

    ret = rt_device_set_rx_indicate(can_dev, can_rx_ind);
    if (ret != RT_EOK) {
        rt_kprintf("set can rx indicate failed: %d\n", ret);
        rt_device_close(can_dev);
        rt_sem_delete(rx_sem);
        rx_sem = RT_NULL;
        can_dev = RT_NULL;
        return ret;
    }

    rx_thread_run = true;
    rx_thread = rt_thread_create("canrx",
                                 can_rx_thread_entry,
                                 RT_NULL,
                                 2048,
                                 24,
                                 10);
    if (rx_thread == RT_NULL) {
        rt_kprintf("create can rx thread failed\n");
        rx_thread_run = false;
        rt_device_set_rx_indicate(can_dev, RT_NULL);
        rt_device_close(can_dev);
        rt_sem_delete(rx_sem);
        rx_sem = RT_NULL;
        can_dev = RT_NULL;
        return -RT_ENOMEM;
    }

    rt_thread_startup(rx_thread);

    rt_kprintf("can_test init success\n");
    return 0;
}

static int can_test_deinit(void)
{
    if (can_dev == RT_NULL) {
        return 0;
    }

    rx_thread_run = false;

    if (rx_sem != RT_NULL) {
        rt_sem_release(rx_sem);
    }

    if (rx_thread != RT_NULL) {
        rt_thread_delete(rx_thread);
        rx_thread = RT_NULL;
    }

    rt_device_set_rx_indicate(can_dev, RT_NULL);
    rt_device_close(can_dev);
    can_dev = RT_NULL;

    if (rx_sem != RT_NULL) {
        rt_sem_delete(rx_sem);
        rx_sem = RT_NULL;
    }

    rt_kprintf("can_test deinit success\n");
    return 0;
}

static int can_test_send(int argc, char** argv, bool ext_id)
{
    can_msg msg;
    char* endptr;
    uint32_t id;
    int data_start;

    if (can_dev == RT_NULL) {
        rt_kprintf("please run 'can_test init' first\n");
        return -RT_ERROR;
    }

    if (argc < 3) {
        rt_kprintf("missing id\n");
        return -RT_EINVAL;
    }

    rt_memset(&msg, 0, sizeof(msg));

    id = (uint32_t)strtoul(argv[2], &endptr, 0);
    if ((endptr == argv[2]) || (*endptr != '\0')) {
        rt_kprintf("invalid id: %s\n", argv[2]);
        return -RT_EINVAL;
    }

    if (ext_id) {
        msg.id_type = CAN_ID_EXTENDED;
        msg.ext_id = id & 0x1FFFFFFFUL;
    } else {
        msg.id_type = CAN_ID_STANDARD;
        msg.std_id = id & 0x7FFUL;
    }

    msg.frame_type = CAN_FRAME_DATA;

    data_start = 3;
    msg.data_len = (argc > data_start) ? (uint32_t)(argc - data_start) : 8U;
    if (msg.data_len > 8U) {
        msg.data_len = 8U;
    }

    if (argc > data_start) {
        for (uint32_t i = 0; i < msg.data_len; i++) {
            uint32_t value = (uint32_t)strtoul(argv[data_start + i], &endptr, 0);
            if ((endptr == argv[data_start + i]) || (*endptr != '\0') || (value > 0xFFU)) {
                rt_kprintf("invalid data byte: %s\n", argv[data_start + i]);
                return -RT_EINVAL;
            }
            msg.data[i] = (uint8_t)value;
        }
    } else {
        static uint8_t seq = 0U;
        for (uint32_t i = 0; i < msg.data_len; i++) {
            msg.data[i] = (uint8_t)(seq + i);
        }
        seq++;
    }

    if (rt_device_write(can_dev, RT_WAITING_FOREVER, &msg, 1) != 1) {
        rt_kprintf("can send failed\n");
        return -RT_ERROR;
    }

    can_dump_msg("CAN TX", &msg);
    return 0;
}

static int can_test(int argc, char** argv)
{
    if (argc < 2) {
        can_test_usage();
        return -RT_EINVAL;
    }

    if (rt_strcmp(argv[1], "init") == 0) {
        return can_test_init();
    }

    if (rt_strcmp(argv[1], "deinit") == 0) {
        return can_test_deinit();
    }

    if (rt_strcmp(argv[1], "send") == 0) {
        return can_test_send(argc, argv, false);
    }

    if (rt_strcmp(argv[1], "sendext") == 0) {
        return can_test_send(argc, argv, true);
    }

    can_test_usage();
    return -RT_EINVAL;
}
MSH_CMD_EXPORT(can_test, can device test command);
