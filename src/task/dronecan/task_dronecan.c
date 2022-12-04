#include <firmament.h>

#include "module/dronecan/dronecan.h"
#include "module/task_manager/task_manager.h"
#include "task/logger/task_logger.h"

void task_dronecan_entry(void* parameter)
{
    static uint32_t time_start = 0;
    uint32_t time_now;
    uint32_t timestamp;

    while (1) {
        time_now = systime_now_ms();

        /* record loop start time */
        if (time_start == 0) {
            time_start = time_now;
        }
        timestamp = time_now - time_start;

        processTxRxOnce(timestamp);
        sys_msleep(10);
    }
}

fmt_err_t task_dronecan_init(void)
{
    if (dronecan_init() != RT_EOK)
        return FMT_ERROR;

    return FMT_EOK;
}

TASK_EXPORT __fmt_task_desc = {
    .name = "droencan",
    .init = task_dronecan_init,
    .entry = task_dronecan_entry,
    .priority = VEHICLE_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 1024 * 8,
    .param = NULL,
    .dependency = NULL
};
