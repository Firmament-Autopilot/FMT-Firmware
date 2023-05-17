#include <firmament.h>

#include "drv_timer.h"
#include "module/dronecan/dronecan.h"
#include "module/task_manager/task_manager.h"
#include "task/logger/task_logger.h"

static struct rt_timer timer_dronecan;
static struct rt_event event_dronecan;

#define EVENT_DRONECAN_UPDATE (1 << 0)

static void timer_dronecan_update(void* parameter)
{
    rt_event_send(&event_dronecan, EVENT_DRONECAN_UPDATE);
}

void task_dronecan_entry(void* parameter)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;

    uint32_t time_now;
    uint32_t timestamp;
    static uint32_t time_start = 0;

    uint32_t wait_set = EVENT_DRONECAN_UPDATE;

    while (1) {

        res = rt_event_recv(&event_dronecan, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);
        if (res == RT_EOK) {
            if (recv_set & EVENT_DRONECAN_UPDATE) {
                time_now = systime_now_ms();
                /* record loop start time */
                if (time_start == 0) {
                    time_start = time_now;
                }

                dronecan_loop(time_now);
            }
        }
    }
}

fmt_err_t task_dronecan_init(void)
{

    if (dronecan_init() != RT_EOK)
        return FMT_ERROR;

    /* create event */
    if (rt_event_init(&event_dronecan, "dronecan", RT_IPC_FLAG_FIFO) != RT_EOK) {
        return FMT_ERROR;
    }
    // drv_timer_init();

    /* register timer event */
    rt_timer_init(&timer_dronecan, "dronecan", timer_dronecan_update, RT_NULL, 1, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    if (rt_timer_start(&timer_dronecan) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

TASK_EXPORT __fmt_task_desc = {
    .name = "dronecan",
    .init = task_dronecan_init,
    .entry = task_dronecan_entry,
    .priority = DRONECAN_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 4096 * 10,
    .param = NULL,
    .dependency = NULL
};

// void TIM6_DAC_IRQHandler()
// {
//     if (LL_TIM_IsActiveFlag_UPDATE(TIM6)) {
//         LL_TIM_ClearFlag_UPDATE(TIM6);

//         rt_event_send(&event_dronecan, EVENT_DRONECAN_UPDATE);
//     }
// }