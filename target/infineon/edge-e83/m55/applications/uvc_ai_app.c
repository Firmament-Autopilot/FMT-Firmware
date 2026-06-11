#include <rtthread.h>
#include <rthw.h>
#include <string.h>

#include "uvc_ai_app.h"
#include "usb_config.h"

#undef USB_DBG_TAG
#define USB_DBG_TAG "uvc_ai_app"
#include "usb_log.h"

#define UVC_AI_FRAME_BYTES       ((uint32_t)UVC_AI_CAMERA_WIDTH * UVC_AI_CAMERA_HEIGHT * 2U)
#define UVC_AI_WORKER_STACK_SIZE 65536U
#define UVC_AI_SOCMEM_SECTION    __attribute__((section(".cy_socmem_data")))
#define UVC_AI_WORKER_PRIORITY   8U
#define UVC_AI_WORKER_TICK       5U
#define UVC_AI_WORKER_NAME       "uvc_aiwk"

typedef struct {
    rt_bool_t started;
    rt_bool_t ai_ready;
    rt_bool_t worker_running;
    rt_bool_t worker_busy;
    uint32_t frame_counter;
    uint16_t src_width;
    uint16_t src_height;
    rt_thread_t worker_thread;
    rt_sem_t worker_sem;
    uint8_t *worker_frame_buf;
    uvc_ai_result_t latest_result;
} uvc_ai_app_ctx_t;

static UVC_AI_SOCMEM_SECTION uvc_ai_app_ctx_t g_uvc_ai_app;
static UVC_AI_SOCMEM_SECTION rt_uint8_t g_uvc_ai_worker_stack[UVC_AI_WORKER_STACK_SIZE];
static UVC_AI_SOCMEM_SECTION struct rt_thread g_uvc_ai_worker_tcb;

static void uvc_ai_app_publish_result(const uvc_ai_result_t *result)
{
    rt_base_t level;

    if (result == RT_NULL) {
        return;
    }

    level = rt_hw_interrupt_disable();
    memcpy(&g_uvc_ai_app.latest_result, result, sizeof(g_uvc_ai_app.latest_result));
    rt_hw_interrupt_enable(level);
}

void uvc_ai_app_get_latest_result(uvc_ai_result_t *result)
{
    rt_base_t level;

    if (result == RT_NULL) {
        return;
    }

    level = rt_hw_interrupt_disable();
    memcpy(result, &g_uvc_ai_app.latest_result, sizeof(*result));
    rt_hw_interrupt_enable(level);
}

static void uvc_ai_app_worker_thread_entry(void *parameter)
{
    uvc_ai_result_t result;
    int ret;

    (void)parameter;

    while (g_uvc_ai_app.worker_running) {
        if (rt_sem_take(g_uvc_ai_app.worker_sem, RT_WAITING_FOREVER) != RT_EOK) {
            continue;
        }

        if (!g_uvc_ai_app.worker_running) {
            break;
        }

        if ((!g_uvc_ai_app.ai_ready) || (g_uvc_ai_app.worker_frame_buf == RT_NULL)) {
            g_uvc_ai_app.worker_busy = RT_FALSE;
            continue;
        }

        ret = uvc_ai_process_yuyv(g_uvc_ai_app.worker_frame_buf,
                                  UVC_AI_FRAME_BYTES,
                                  &result);
        if (ret == RT_EOK) {
            uvc_ai_app_publish_result(&result);
        } else {
            USB_LOG_WRN("AI processing failed\r\n");
            uvc_ai_reset_result(&result);
            uvc_ai_app_publish_result(&result);
        }

        g_uvc_ai_app.worker_busy = RT_FALSE;
    }
}

void uvc_ai_app_enforce_mode(uint8_t *fmt, uint16_t *width, uint16_t *height)
{
    if ((fmt == RT_NULL) || (width == RT_NULL) || (height == RT_NULL)) {
        return;
    }

    if (*fmt != USBH_VIDEO_FORMAT_UNCOMPRESSED) {
        USB_LOG_WRN("AI mode requires YUYV, force fmt=0\r\n");
        *fmt = USBH_VIDEO_FORMAT_UNCOMPRESSED;
    }

    if ((*width != UVC_AI_CAMERA_WIDTH) || (*height != UVC_AI_CAMERA_HEIGHT)) {
        USB_LOG_WRN("AI mode requires 320x240, force %ux%u\r\n",
                    (unsigned)UVC_AI_CAMERA_WIDTH, (unsigned)UVC_AI_CAMERA_HEIGHT);
        *width = UVC_AI_CAMERA_WIDTH;
        *height = UVC_AI_CAMERA_HEIGHT;
    }
}

int uvc_ai_app_start(uint16_t src_width, uint16_t src_height)
{
    uvc_ai_config_t config;
    int ret;
    rt_err_t thread_ret;

    memset(&g_uvc_ai_app, 0, sizeof(g_uvc_ai_app));
    g_uvc_ai_app.src_width = src_width ? src_width : UVC_AI_CAMERA_WIDTH;
    g_uvc_ai_app.src_height = src_height ? src_height : UVC_AI_CAMERA_HEIGHT;
    g_uvc_ai_app.started = RT_TRUE;

    uvc_ai_reset_result(&g_uvc_ai_app.latest_result);

    config.initialized = 1U;
    config.src_width = g_uvc_ai_app.src_width;
    config.src_height = g_uvc_ai_app.src_height;

    ret = uvc_ai_init(&config);
    if (ret != RT_EOK) {
        USB_LOG_ERR("AI init failed\r\n");
        return ret;
    }

    g_uvc_ai_app.ai_ready = RT_TRUE;
    g_uvc_ai_app.worker_frame_buf = rt_malloc(UVC_AI_FRAME_BYTES);
    if (g_uvc_ai_app.worker_frame_buf != RT_NULL) {
        g_uvc_ai_app.worker_sem = rt_sem_create("uvc_aiwk", 0, RT_IPC_FLAG_FIFO);
        if (g_uvc_ai_app.worker_sem != RT_NULL) {
            g_uvc_ai_app.worker_running = RT_TRUE;
            g_uvc_ai_app.worker_busy = RT_FALSE;
            thread_ret = rt_thread_init(&g_uvc_ai_worker_tcb,
                                        UVC_AI_WORKER_NAME,
                                        uvc_ai_app_worker_thread_entry,
                                        RT_NULL,
                                        g_uvc_ai_worker_stack,
                                        sizeof(g_uvc_ai_worker_stack),
                                        UVC_AI_WORKER_PRIORITY,
                                        UVC_AI_WORKER_TICK);
            if (thread_ret == RT_EOK) {
                g_uvc_ai_app.worker_thread = &g_uvc_ai_worker_tcb;
                rt_thread_startup(g_uvc_ai_app.worker_thread);
            } else {
                g_uvc_ai_app.worker_thread = RT_NULL;
                g_uvc_ai_app.worker_running = RT_FALSE;
                rt_sem_delete(g_uvc_ai_app.worker_sem);
                g_uvc_ai_app.worker_sem = RT_NULL;
                USB_LOG_WRN("AI worker thread init failed (%d), fallback to sync\r\n", thread_ret);
            }
        } else {
            USB_LOG_WRN("AI worker semaphore create failed, fallback to sync\r\n");
        }
    } else {
        USB_LOG_WRN("AI worker buffer alloc failed, fallback to sync\r\n");
    }

    if ((g_uvc_ai_app.worker_thread == RT_NULL) || (g_uvc_ai_app.worker_sem == RT_NULL)) {
        if (g_uvc_ai_app.worker_sem != RT_NULL) {
            rt_sem_delete(g_uvc_ai_app.worker_sem);
            g_uvc_ai_app.worker_sem = RT_NULL;
        }
        if (g_uvc_ai_app.worker_frame_buf != RT_NULL) {
            rt_free(g_uvc_ai_app.worker_frame_buf);
            g_uvc_ai_app.worker_frame_buf = RT_NULL;
        }
    }

    USB_LOG_INFO("AI app started (%s)\r\n",
                 (g_uvc_ai_app.worker_thread != RT_NULL) ? "async" : "sync");

    return RT_EOK;
}

void uvc_ai_app_process_frame(const struct usbh_videoframe *frame)
{
    int ret;

    if ((!g_uvc_ai_app.started) || (!g_uvc_ai_app.ai_ready) || (frame == RT_NULL)) {
        return;
    }

    if (frame->frame_format != USBH_VIDEO_FORMAT_UNCOMPRESSED) {
        return;
    }

    g_uvc_ai_app.frame_counter++;
    if ((g_uvc_ai_app.frame_counter % UVC_AI_FRAMES_TO_SKIP) != 0U) {
        return;
    }

    if ((g_uvc_ai_app.worker_thread != RT_NULL) &&
        (g_uvc_ai_app.worker_sem != RT_NULL) &&
        (g_uvc_ai_app.worker_frame_buf != RT_NULL)) {
        if (frame->frame_size < UVC_AI_FRAME_BYTES) {
            return;
        }

        if (g_uvc_ai_app.worker_busy) {
            return;
        }

        g_uvc_ai_app.worker_busy = RT_TRUE;
        memcpy(g_uvc_ai_app.worker_frame_buf, frame->frame_buf, UVC_AI_FRAME_BYTES);
        if (rt_sem_release(g_uvc_ai_app.worker_sem) != RT_EOK) {
            g_uvc_ai_app.worker_busy = RT_FALSE;
        }
        return;
    }

    ret = uvc_ai_process_yuyv(frame->frame_buf, frame->frame_size, &g_uvc_ai_app.latest_result);
    if (ret != RT_EOK) {
        USB_LOG_WRN("AI processing failed\r\n");
    }
}

void uvc_ai_app_stop(void)
{
    uint32_t wait_ms = 200U;
    uint32_t detach_wait_ms = 200U;

    if (!g_uvc_ai_app.started) {
        return;
    }

    if (g_uvc_ai_app.worker_thread != RT_NULL) {
        g_uvc_ai_app.worker_running = RT_FALSE;
        if (g_uvc_ai_app.worker_sem != RT_NULL) {
            (void)rt_sem_release(g_uvc_ai_app.worker_sem);
        }

        while (g_uvc_ai_app.worker_busy && (wait_ms > 0U)) {
            rt_thread_mdelay(10);
            wait_ms = (wait_ms >= 10U) ? (wait_ms - 10U) : 0U;
        }

        while (detach_wait_ms > 0U) {
            rt_err_t detach_ret = rt_thread_detach(&g_uvc_ai_worker_tcb);

            if (detach_ret == RT_EOK) {
                break;
            }

            rt_thread_mdelay(10);
            detach_wait_ms -= 10U;
        }
        g_uvc_ai_app.worker_thread = RT_NULL;
    }

    if (g_uvc_ai_app.worker_sem != RT_NULL) {
        rt_sem_delete(g_uvc_ai_app.worker_sem);
        g_uvc_ai_app.worker_sem = RT_NULL;
    }

    if (g_uvc_ai_app.worker_frame_buf != RT_NULL) {
        rt_free(g_uvc_ai_app.worker_frame_buf);
        g_uvc_ai_app.worker_frame_buf = RT_NULL;
    }
    g_uvc_ai_app.worker_busy = RT_FALSE;

    if (g_uvc_ai_app.ai_ready) {
        uvc_ai_deinit();
        g_uvc_ai_app.ai_ready = RT_FALSE;
    }

    g_uvc_ai_app.started = RT_FALSE;
    uvc_ai_reset_result(&g_uvc_ai_app.latest_result);
    USB_LOG_INFO("AI app stopped\r\n");
}
