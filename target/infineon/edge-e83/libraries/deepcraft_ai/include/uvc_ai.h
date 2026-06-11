#ifndef UVC_AI_H
#define UVC_AI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UVC_AI_CAMERA_WIDTH      320U
#define UVC_AI_CAMERA_HEIGHT     240U
#define UVC_AI_IMAGE_WIDTH       320U
#define UVC_AI_IMAGE_HEIGHT      320U
#define UVC_AI_NUM_CLASSES       3U
#define UVC_AI_MAX_CLASS_LEN     10U
#define UVC_AI_MAX_PREDICTIONS   5U
#define UVC_AI_FRAMES_TO_SKIP    4U

typedef struct {
    uint8_t initialized;
    uint16_t src_width;
    uint16_t src_height;
} uvc_ai_config_t;

typedef struct {
    uint8_t valid;
    uint8_t count;
    float inference_ms;
    int16_t bbox_int16[UVC_AI_MAX_PREDICTIONS * 4U];
    float conf[UVC_AI_MAX_PREDICTIONS];
    uint8_t class_id[UVC_AI_MAX_PREDICTIONS];
    union {
        char label[UVC_AI_MAX_PREDICTIONS][UVC_AI_MAX_CLASS_LEN];
        char class_string[UVC_AI_MAX_PREDICTIONS][UVC_AI_MAX_CLASS_LEN];
    };
} uvc_ai_result_t;

int uvc_ai_init(const uvc_ai_config_t *config);
void uvc_ai_deinit(void);
void uvc_ai_reset_result(uvc_ai_result_t *result);
int uvc_ai_process_yuyv(const uint8_t *yuyv, uint32_t yuyv_size, uvc_ai_result_t *result);

#ifdef __cplusplus
}
#endif

#endif /* UVC_AI_H */
