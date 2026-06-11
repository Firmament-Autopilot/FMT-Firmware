#include <rtthread.h>
#include <rtdevice.h>
#include "usbh_core.h"
#include "uvc_ai_app.h"

#define UVC_AI_USB_BUSID 0

static int uvc_ai_usb_host_auto_init(void)
{
    usbh_initialize(UVC_AI_USB_BUSID, USBHS_BASE, RT_NULL);
    return 0;
}
INIT_APP_EXPORT(uvc_ai_usb_host_auto_init);

static void uvc_ai_result(int argc, char **argv)
{
    uvc_ai_result_t result;
    uint32_t i;

    (void)argc;
    (void)argv;

    uvc_ai_app_get_latest_result(&result);
    if (!result.valid) {
        rt_kprintf("AI result is not ready\n");
        return;
    }

    rt_kprintf("AI inference %.1f ms, det=%u\n", result.inference_ms, result.count);
    for (i = 0U; i < result.count; i++) {
        rt_kprintf("#%lu %s %.2f%% bbox=[%d,%d,%d,%d]\n",
                   (unsigned long)i,
                   result.class_string[i],
                   result.conf[i] * 100.0f,
                   result.bbox_int16[i * 4U + 0U],
                   result.bbox_int16[i * 4U + 1U],
                   result.bbox_int16[i * 4U + 2U],
                   result.bbox_int16[i * 4U + 3U]);
    }
}
MSH_CMD_EXPORT(uvc_ai_result, show latest UVC AI result);
