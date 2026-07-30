#include <firmament.h>

#include "hal/can/can.h"
#include "module/task_manager/task_manager.h"

static rt_device_t can1_dev;
static rt_device_t can2_dev;

fmt_err_t task_can_init(void)
{
    can1_dev = rt_device_find("can1");
    can2_dev = rt_device_find("can2");

    rt_device_open(can1_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
    rt_device_open(can2_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);

    return FMT_EOK;
}

void task_can_entry(void* parameter)
{
    can_msg msg = {0};

    /* main loop */
    while (1) {
        while (rt_device_read(can1_dev, RT_WAITING_NO, &msg, 1) > 0) {
            printf("can1 recv msg, id:0x%x, data:", msg.std_id);
            for(uint8_t i = 0; i < msg.data_len; i++) {
                printf("%x,", msg.data[i]);
            }
            printf("\n");
        }

        // msg.std_id = 0x100;
        // msg.id_type = CAN_ID_STANDARD;
        // msg.frame_type = CAN_FRAME_DATA;
        // msg.data_len = 8;
        // msg.data[0] = 0x11;
        // msg.data[1] = 0x22;
        // msg.data[2] = 0x33;
        // msg.data[3] = 0x44;
        // msg.data[4] = 0x55;
        // msg.data[5] = 0x66;
        // msg.data[6] = 0x77;
        // msg.data[7] = 0x88;
        // rt_device_write(can1_dev, RT_WAITING_FOREVER, &msg, 1);

        // while (rt_device_read(can2_dev, RT_WAITING_NO, &msg, 1) > 0) {
        //     printf("can2 recv msg, id:0x%x, data:", msg.std_id);
        //     for(uint8_t i = 0; i < msg.data_len; i++) {
        //         printf("%x,", msg.data[i]);
        //     }
        //     printf("\n");
        // }

        // msg.std_id = 0x200;
        // msg.id_type = CAN_ID_STANDARD;
        // msg.frame_type = CAN_FRAME_DATA;
        // msg.data_len = 8;
        // msg.data[0] = 0x88;
        // msg.data[1] = 0x77;
        // msg.data[2] = 0x66;
        // msg.data[3] = 0x55;
        // msg.data[4] = 0x44;
        // msg.data[5] = 0x33;
        // msg.data[6] = 0x22;
        // msg.data[7] = 0x11;
        // rt_device_write(can2_dev, RT_WAITING_FOREVER, &msg, 1);

        sys_msleep(500);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "can",
    .init = task_can_init,
    .entry = task_can_entry,
    .priority = 25,
    .auto_start = true,
    .stack_size = 4096,
    .param = NULL,
    .dependency = NULL
};
