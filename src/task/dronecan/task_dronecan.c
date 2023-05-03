#include <firmament.h>

#include "module/dronecan/dronecan.h"
#include "module/task_manager/task_manager.h"
#include "task/logger/task_logger.h"

void task_dronecan_entry(void* parameter)
{
 dronecan_loop();
}

fmt_err_t task_dronecan_init(void)
{
    if (dronecan_init() != RT_EOK)
        return FMT_ERROR;

    return FMT_EOK;
}

TASK_EXPORT __fmt_task_desc = {
    .name = "can",
    .init = task_dronecan_init,
    .entry = task_dronecan_entry,
    .priority = DRONECAN_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 4096 * 10,
    .param = NULL,
    .dependency = NULL
};
