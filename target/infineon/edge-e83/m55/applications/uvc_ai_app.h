#ifndef UVC_AI_APP_H
#define UVC_AI_APP_H

#include <stdint.h>
#include "usbh_uvc_stream.h"
#include "uvc_ai.h"

#ifdef __cplusplus
extern "C" {
#endif

void uvc_ai_app_enforce_mode(uint8_t *fmt, uint16_t *width, uint16_t *height);
int uvc_ai_app_start(uint16_t src_width, uint16_t src_height);
void uvc_ai_app_process_frame(const struct usbh_videoframe *frame);
void uvc_ai_app_stop(void);
void uvc_ai_app_get_latest_result(uvc_ai_result_t *result);

#ifdef __cplusplus
}
#endif

#endif /* UVC_AI_APP_H */
