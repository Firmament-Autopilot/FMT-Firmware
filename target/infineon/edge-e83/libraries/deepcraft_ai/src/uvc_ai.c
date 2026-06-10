#include <rtthread.h>
#include <string.h>
#include <stdio.h>

#include "uvc_ai.h"
#include "model.h"
#include "mtb_ml.h"
#include "usb_config.h"

#undef USB_DBG_TAG
#define USB_DBG_TAG "uvc_ai"
#include "usb_log.h"

#define UVC_AI_HALF(x)      ((x) * 0.5f)
#define UVC_AI_ROUND_FACTOR (0.5f)
#define UVC_AI_ITCM_SECTION __attribute__((section(".cy_itcm")))
#define UVC_AI_DTCM_SECTION __attribute__((section(".cy_dtcm")))
#define UVC_AI_ML_INPUT_SECTION __attribute__((section(".cy_ml_input_data")))
#define UVC_AI_SOCMEM_SECTION __attribute__((section(".cy_socmem_data")))
#define UVC_AI_ALIGN_16 __attribute__((aligned(16)))
#define UVC_AI_PAD_VALUE_U8 ((uint8_t)0)
#define UVC_AI_SRC_STRIDE_BYTES (UVC_AI_CAMERA_WIDTH * 2U)
#define UVC_AI_SRC_PAIR_COUNT (UVC_AI_CAMERA_WIDTH / 2U)
#define UVC_AI_FRAME_BYTES (UVC_AI_SRC_STRIDE_BYTES * UVC_AI_CAMERA_HEIGHT)
#define UVC_AI_TOP_RGB888_BYTES (UVC_AI_CAMERA_WIDTH * UVC_AI_CAMERA_HEIGHT * 3U)
#define UVC_AI_PAD_RGB888_BYTES ((UVC_AI_IMAGE_HEIGHT - UVC_AI_CAMERA_HEIGHT) * UVC_AI_IMAGE_WIDTH * 3U)
#define UVC_AI_MODEL_HEADER_WORD0 (0x00000024UL)
#define UVC_AI_MODEL_HEADER_WORD1 (0x334c4654UL)

static UVC_AI_ML_INPUT_SECTION UVC_AI_ALIGN_16 uint8_t g_model_input_u8[IMAI_DATAIN_COUNT];
static UVC_AI_SOCMEM_SECTION float g_model_output[IMAI_DATAOUT_COUNT];

static uint8_t g_ai_initialized;
static uint16_t g_src_width;
static uint16_t g_src_height;
static uint64_t g_last_npu_cycles;
static uint32_t g_last_score_count;
static uint8_t g_restore_unalign_trp;
static uint32_t g_saved_ccr;
static UVC_AI_SOCMEM_SECTION uint8_t g_uvc_ai_yuv_lut_ready;
static rt_tick_t g_last_ai_log_tick;
static UVC_AI_SOCMEM_SECTION int32_t g_uvc_ai_y_lut[256];
static UVC_AI_SOCMEM_SECTION int32_t g_uvc_ai_u_to_b_lut[256];
static UVC_AI_SOCMEM_SECTION int32_t g_uvc_ai_u_to_g_lut[256];
static UVC_AI_SOCMEM_SECTION int32_t g_uvc_ai_v_to_r_lut[256];
static UVC_AI_SOCMEM_SECTION int32_t g_uvc_ai_v_to_g_lut[256];

extern uint8_t __cy_ml_model_data_start__[];
extern uint8_t __cy_ml_model_data_end__[];
extern const uint8_t __cy_ml_model_data_load_start__[];
extern const uint8_t __cy_ml_model_data_load_end__[];

static inline uint8_t uvc_ai_sat_to_u8(int32_t value)
{
#if defined(__ARM_FEATURE_DSP) || defined(__ARM_FEATURE_MVE)
    return (uint8_t)__USAT(value, 8U);
#else
    if (value < 0) {
        value = 0;
    }

    if (value > 255) {
        value = 255;
    }

    return (uint8_t)value;
#endif
}

static inline uint32_t uvc_ai_load_u32_unaligned(const uint8_t *src)
{
#if defined(__UNALIGNED_UINT32_READ)
    return __UNALIGNED_UINT32_READ(src);
#else
    uint32_t packed;
    memcpy(&packed, src, sizeof(packed));
    return packed;
#endif
}

static inline int16_t uvc_ai_clamp_i16(int32_t value, int32_t min_v, int32_t max_v)
{
    if (value < min_v) {
        value = min_v;
    }

    if (value > max_v) {
        value = max_v;
    }

    return (int16_t)value;
}

static void uvc_ai_prepare_yuv_lut(void)
{
    uint32_t i;

    if (g_uvc_ai_yuv_lut_ready) {
        return;
    }

    for (i = 0U; i < 256U; i++) {
        int32_t y = (int32_t)i - 16;
        int32_t uv = (int32_t)i - 128;

        if (y < 0) {
            y = 0;
        }

        g_uvc_ai_y_lut[i] = 298 * y;
        g_uvc_ai_u_to_b_lut[i] = 516 * uv;
        g_uvc_ai_u_to_g_lut[i] = -100 * uv;
        g_uvc_ai_v_to_r_lut[i] = 409 * uv;
        g_uvc_ai_v_to_g_lut[i] = -208 * uv;
    }

    g_uvc_ai_yuv_lut_ready = 1U;
}

static void uvc_ai_sync_model_blob_from_flash(void)
{
    uint8_t *runtime = __cy_ml_model_data_start__;
    const uint8_t *flash = __cy_ml_model_data_load_start__;
    uintptr_t runtime_start = (uintptr_t)__cy_ml_model_data_start__;
    uintptr_t runtime_end = (uintptr_t)__cy_ml_model_data_end__;
    uintptr_t flash_start = (uintptr_t)__cy_ml_model_data_load_start__;
    uintptr_t flash_end = (uintptr_t)__cy_ml_model_data_load_end__;
    uint32_t runtime_word0;
    uint32_t runtime_word1;
    uint32_t flash_word0;
    uint32_t flash_word1;
    int blob_same;
    size_t bytes;

    if ((runtime_end <= runtime_start) || (flash_end <= flash_start)) {
        return;
    }

    bytes = (size_t)(runtime_end - runtime_start);
    if (bytes < (2U * sizeof(uint32_t))) {
        return;
    }

    if (runtime_start == flash_start) {
        return;
    }

    memcpy(&runtime_word0, runtime, sizeof(runtime_word0));
    memcpy(&runtime_word1, runtime + sizeof(uint32_t), sizeof(runtime_word1));
    memcpy(&flash_word0, flash, sizeof(flash_word0));
    memcpy(&flash_word1, flash + sizeof(uint32_t), sizeof(flash_word1));
    blob_same = (memcmp(runtime, flash, bytes) == 0);

    /*
     * On this project, startup copy of .cy_ml_model_data can be missed in some boot
     * paths. Refresh runtime model blob before IMAI_init to avoid unaligned parser faults.
     */
    if (!blob_same ||
        (runtime_word0 != flash_word0) || (runtime_word1 != flash_word1) ||
        (runtime_word0 != UVC_AI_MODEL_HEADER_WORD0) || (runtime_word1 != UVC_AI_MODEL_HEADER_WORD1)) {
        memcpy(runtime, flash, bytes);
        USB_LOG_INFO("blob sync flash->runtime=1 r=0x%08lx f=0x%08lx\r\n",
                     (unsigned long)runtime_start, (unsigned long)flash_start);
    } else {
        USB_LOG_INFO("blob sync flash->runtime=0 r=0x%08lx f=0x%08lx\r\n",
                     (unsigned long)runtime_start, (unsigned long)flash_start);
    }
}

static UVC_AI_ITCM_SECTION void uvc_ai_yuyv_to_rgb888_320x320_u8(const uint8_t *restrict yuyv)
{
    uint32_t y;
    uint8_t *restrict dst = g_model_input_u8;
    const int32_t *restrict y_lut = g_uvc_ai_y_lut;
    const int32_t *restrict u_to_b_lut = g_uvc_ai_u_to_b_lut;
    const int32_t *restrict u_to_g_lut = g_uvc_ai_u_to_g_lut;
    const int32_t *restrict v_to_r_lut = g_uvc_ai_v_to_r_lut;
    const int32_t *restrict v_to_g_lut = g_uvc_ai_v_to_g_lut;

    if ((dst == RT_NULL) || (yuyv == RT_NULL)) {
        return;
    }

    for (y = 0U; y < UVC_AI_CAMERA_HEIGHT; y++) {
        const uint8_t *src = yuyv + y * UVC_AI_SRC_STRIDE_BYTES;
        uint32_t pair;

        for (pair = 0U; pair < UVC_AI_SRC_PAIR_COUNT; pair++) {
            uint32_t packed = uvc_ai_load_u32_unaligned(src);
            uint8_t y0 = (uint8_t)(packed & 0xffU);
            uint8_t u = (uint8_t)((packed >> 8) & 0xffU);
            uint8_t y1 = (uint8_t)((packed >> 16) & 0xffU);
            uint8_t v = (uint8_t)((packed >> 24) & 0xffU);
            int32_t y_term0 = y_lut[y0];
            int32_t y_term1 = y_lut[y1];
            int32_t u_to_b = u_to_b_lut[u];
            int32_t u_to_g = u_to_g_lut[u];
            int32_t v_to_r = v_to_r_lut[v];
            int32_t v_to_g = v_to_g_lut[v];
            int32_t uv_to_g = u_to_g + v_to_g;

            *dst++ = uvc_ai_sat_to_u8((y_term0 + v_to_r + 128) >> 8);
            *dst++ = uvc_ai_sat_to_u8((y_term0 + uv_to_g + 128) >> 8);
            *dst++ = uvc_ai_sat_to_u8((y_term0 + u_to_b + 128) >> 8);

            *dst++ = uvc_ai_sat_to_u8((y_term1 + v_to_r + 128) >> 8);
            *dst++ = uvc_ai_sat_to_u8((y_term1 + uv_to_g + 128) >> 8);
            *dst++ = uvc_ai_sat_to_u8((y_term1 + u_to_b + 128) >> 8);

            src += 4;
        }
    }
}

static uint8_t uvc_ai_get_best_class(const float *output,
                                     uint32_t score_count,
                                     uint32_t max_predictions_model,
                                     uint32_t det_index,
                                     float *best_score)
{
    uint32_t cls;
    uint8_t best_index = 0U;
    float max_value;

    if ((output == RT_NULL) || (score_count == 0U)) {
        *best_score = 0.0f;
        return 0U;
    }

    max_value = output[(4U * max_predictions_model) + det_index];
    for (cls = 1U; cls < score_count; cls++) {
        float score = output[((4U + cls) * max_predictions_model) + det_index];

        if (score > max_value) {
            max_value = score;
            best_index = (uint8_t)cls;
        }
    }

    *best_score = max_value;
    return best_index;
}

void uvc_ai_reset_result(uvc_ai_result_t *result)
{
    if (result == RT_NULL) {
        return;
    }

    memset(result, 0, sizeof(*result));
}

int uvc_ai_init(const uvc_ai_config_t *config)
{
    int ret;

    if (config != RT_NULL) {
        g_src_width = (config->src_width == 0U) ? UVC_AI_CAMERA_WIDTH : config->src_width;
        g_src_height = (config->src_height == 0U) ? UVC_AI_CAMERA_HEIGHT : config->src_height;
    } else {
        g_src_width = UVC_AI_CAMERA_WIDTH;
        g_src_height = UVC_AI_CAMERA_HEIGHT;
    }

    if ((g_src_width != UVC_AI_CAMERA_WIDTH) || (g_src_height != UVC_AI_CAMERA_HEIGHT)) {
        USB_LOG_WRN("AI only supports 320x240 input, force %ux%u\r\n",
                    (unsigned)UVC_AI_CAMERA_WIDTH, (unsigned)UVC_AI_CAMERA_HEIGHT);
        g_src_width = UVC_AI_CAMERA_WIDTH;
        g_src_height = UVC_AI_CAMERA_HEIGHT;
    }

    uvc_ai_prepare_yuv_lut();

    if (g_ai_initialized) {
        return RT_EOK;
    }

    uvc_ai_sync_model_blob_from_flash();

    if ((SCB->CCR & SCB_CCR_UNALIGN_TRP_Msk) != 0U) {
        g_saved_ccr = SCB->CCR;
        SCB->CCR = g_saved_ccr & (~SCB_CCR_UNALIGN_TRP_Msk);
        __DSB();
        __ISB();
        g_restore_unalign_trp = 1U;
        USB_LOG_WRN("UNALIGN_TRP disabled for TFLM parser compatibility\r\n");
    } else {
        g_restore_unalign_trp = 0U;
    }

    ret = IMAI_init();
    if (ret != IMAI_RET_SUCCESS) {
        USB_LOG_ERR("IMAI_init failed: %d\r\n", ret);
        if (g_restore_unalign_trp) {
            SCB->CCR = g_saved_ccr;
            __DSB();
            __ISB();
            g_restore_unalign_trp = 0U;
        }
        return -RT_ERROR;
    }

    /*
     * AI input is fixed to 320x240 top area + 80-line bottom padding.
     * Keep the bottom band pre-filled once instead of clearing every frame.
     */
    memset(g_model_input_u8 + UVC_AI_TOP_RGB888_BYTES,
           UVC_AI_PAD_VALUE_U8,
           UVC_AI_PAD_RGB888_BYTES);

    mtb_ml_set_cache_mgmt_type(MTB_ML_ETHOSU_CACHE_MGMT_OUTER_LAYERS);

    g_last_npu_cycles = 0U;
    g_last_score_count = 0U;
    g_ai_initialized = 1U;
    USB_LOG_INFO("AI clocks cpu=%luMHz npu=%luMHz cache=%lu\r\n",
                 (unsigned long)(mtb_ml_cpu_clk_freq / 1000000U),
                 (unsigned long)(mtb_ml_npu_clk_freq / 1000000U),
                 (unsigned long)mtb_ml_get_cache_mgmt_type());
    USB_LOG_INFO("AI model initialized\r\n");
    return RT_EOK;
}

void uvc_ai_deinit(void)
{
    if (!g_ai_initialized) {
        return;
    }

    IMAI_finalize();
    if (g_restore_unalign_trp) {
        SCB->CCR = g_saved_ccr;
        __DSB();
        __ISB();
        g_restore_unalign_trp = 0U;
    }
    g_last_npu_cycles = 0U;
    g_last_score_count = 0U;
    g_ai_initialized = 0U;
    USB_LOG_INFO("AI model deinitialized\r\n");
}

UVC_AI_ITCM_SECTION int uvc_ai_process_yuyv(const uint8_t *yuyv, uint32_t yuyv_size, uvc_ai_result_t *result)
{
    IMAI_api_def *api_def;
    uint32_t min_frame_size;
    uint32_t max_predictions_model;
    uint32_t max_predictions;
    uint32_t output_columns;
    uint32_t detection_flag_index;
    uint32_t score_count;
    uint32_t i;
    uint64_t npu_cycles_before;
    uint64_t npu_cycles_after;
    uint64_t npu_cycles_delta;
    rt_tick_t prep_start_tick;
    rt_tick_t prep_end_tick;
    rt_tick_t start_tick;
    rt_tick_t end_tick;
    rt_tick_t log_delta_tick;
    rt_tick_t log_now_tick;
    float prep_ms;
    float npu_ms;

    if ((!g_ai_initialized) || (yuyv == RT_NULL) || (result == RT_NULL)) {
        return -RT_EINVAL;
    }

    min_frame_size = UVC_AI_FRAME_BYTES;
    if (yuyv_size < min_frame_size) {
        USB_LOG_WRN("AI frame too small: %lu < %lu\r\n",
                    (unsigned long)yuyv_size, (unsigned long)min_frame_size);
        return -RT_EINVAL;
    }

    prep_start_tick = rt_tick_get();
    uvc_ai_yuyv_to_rgb888_320x320_u8(yuyv);
    prep_end_tick = rt_tick_get();

    npu_cycles_before = mtb_ml_npu_cycles;
    start_tick = rt_tick_get();
    IMAI_compute(g_model_input_u8, g_model_output);
    end_tick = rt_tick_get();
    npu_cycles_after = mtb_ml_npu_cycles;

    uvc_ai_reset_result(result);

    api_def = IMAI_api();
    if ((api_def == RT_NULL) || (api_def->func_count <= 0)) {
        USB_LOG_ERR("IMAI_api metadata unavailable\r\n");
        return -RT_ERROR;
    }

    max_predictions_model = (uint32_t)api_def->func_list[0].param_list[1].shape[0].size;
    output_columns = (uint32_t)api_def->func_list[0].param_list[1].shape[1].size;
    if ((max_predictions_model == 0U) || (output_columns < 6U)) {
        USB_LOG_ERR("Invalid model output shape\r\n");
        return -RT_ERROR;
    }

    max_predictions = max_predictions_model;
    if (max_predictions > UVC_AI_MAX_PREDICTIONS) {
        max_predictions = UVC_AI_MAX_PREDICTIONS;
    }

    detection_flag_index = output_columns - 1U;
    score_count = output_columns - 5U;
    if (score_count == 0U) {
        USB_LOG_ERR("Model output has no class scores\r\n");
        return -RT_ERROR;
    }
    if ((score_count != UVC_AI_NUM_CLASSES) && (score_count != g_last_score_count)) {
        USB_LOG_WRN("Model class count=%lu (default=%u), using runtime class metadata\r\n",
                    (unsigned long)score_count, (unsigned)UVC_AI_NUM_CLASSES);
        g_last_score_count = score_count;
    }

    for (i = 0U; i < max_predictions; i++) {
        float detection_flag = g_model_output[detection_flag_index * max_predictions_model + i];
        float x;
        float y;
        float w;
        float h;
        float best_score = 0.0f;
        uint8_t best_class;
        const char *label;
        uint32_t label_idx;
        int32_t xmin;
        int32_t ymin;
        int32_t xmax;
        int32_t ymax;
        uint32_t out_idx;

        if (detection_flag == 0.0f) {
            break;
        }

        out_idx = result->count;
        if (out_idx >= UVC_AI_MAX_PREDICTIONS) {
            break;
        }

        x = g_model_output[0U * max_predictions_model + i];
        y = g_model_output[1U * max_predictions_model + i];
        w = g_model_output[2U * max_predictions_model + i];
        h = g_model_output[3U * max_predictions_model + i];

        best_class = uvc_ai_get_best_class(g_model_output,
                                           score_count,
                                           max_predictions_model,
                                           i,
                                           &best_score);

        label = "Unknown";
        label_idx = (uint32_t)best_class + 4U;
        if ((label_idx < detection_flag_index) &&
            (api_def->func_list[0].param_list[1].shape != RT_NULL) &&
            (api_def->func_list[0].param_list[1].shape[1].labels != RT_NULL) &&
            (api_def->func_list[0].param_list[1].shape[1].labels[label_idx] != RT_NULL)) {
            label = api_def->func_list[0].param_list[1].shape[1].labels[label_idx];
        } else if (score_count == 1U) {
            label = "Face";
        }

        if (label == RT_NULL) {
            label = "Unknown";
        }

        (void)snprintf(result->class_string[out_idx], UVC_AI_MAX_CLASS_LEN, "%s", label);
        result->class_id[out_idx] = best_class;
        result->conf[out_idx] = best_score;

        xmin = (int32_t)((x - UVC_AI_HALF(w)) * UVC_AI_IMAGE_WIDTH + UVC_AI_ROUND_FACTOR);
        ymin = (int32_t)((y - UVC_AI_HALF(h)) * UVC_AI_IMAGE_WIDTH + UVC_AI_ROUND_FACTOR);
        xmax = (int32_t)((x + UVC_AI_HALF(w)) * UVC_AI_IMAGE_WIDTH + UVC_AI_ROUND_FACTOR);
        ymax = (int32_t)((y + UVC_AI_HALF(h)) * UVC_AI_IMAGE_WIDTH + UVC_AI_ROUND_FACTOR);

        result->bbox_int16[out_idx * 4U + 0U] = uvc_ai_clamp_i16(xmin, 0, (int32_t)UVC_AI_IMAGE_WIDTH - 1);
        result->bbox_int16[out_idx * 4U + 1U] = uvc_ai_clamp_i16(ymin, 0, (int32_t)UVC_AI_IMAGE_HEIGHT - 1);
        result->bbox_int16[out_idx * 4U + 2U] = uvc_ai_clamp_i16(xmax, 0, (int32_t)UVC_AI_IMAGE_WIDTH - 1);
        result->bbox_int16[out_idx * 4U + 3U] = uvc_ai_clamp_i16(ymax, 0, (int32_t)UVC_AI_IMAGE_HEIGHT - 1);
        result->count = (uint8_t)(out_idx + 1U);
    }

    result->valid = 1U;
    prep_ms = ((float)(prep_end_tick - prep_start_tick) * 1000.0f) / (float)RT_TICK_PER_SECOND;
    result->inference_ms = ((float)(end_tick - start_tick) * 1000.0f) / (float)RT_TICK_PER_SECOND;

    if (npu_cycles_after >= npu_cycles_before) {
        npu_cycles_delta = npu_cycles_after - npu_cycles_before;
    } else {
        npu_cycles_delta = 0U;
    }

    if (npu_cycles_after >= g_last_npu_cycles) {
        g_last_npu_cycles = npu_cycles_after;
    } else {
        /* PMU counter could reset after re-init/overflow. */
        g_last_npu_cycles = 0U;
    }

    if (mtb_ml_npu_clk_freq != 0U) {
        npu_ms = ((float)npu_cycles_delta * 1000.0f) / (float)mtb_ml_npu_clk_freq;
    } else {
        npu_ms = 0.0f;
    }

    log_now_tick = rt_tick_get();
    log_delta_tick = log_now_tick - g_last_ai_log_tick;
    if ((g_last_ai_log_tick == 0U) || (log_delta_tick >= (3U * RT_TICK_PER_SECOND))) {
        USB_LOG_INFO("AI inference %.1f ms (prep %.1f ms, npu %.1f ms), det=%u\r\n",
                     result->inference_ms, prep_ms, npu_ms, result->count);
        for (i = 0U; i < result->count; i++) {
            USB_LOG_INFO("AI #%lu %s %.2f%% bbox=[%d,%d,%d,%d]\r\n",
                         (unsigned long)i,
                         result->class_string[i],
                         result->conf[i] * 100.0f,
                         result->bbox_int16[i * 4U + 0U],
                         result->bbox_int16[i * 4U + 1U],
                         result->bbox_int16[i * 4U + 2U],
                         result->bbox_int16[i * 4U + 3U]);
        }
        g_last_ai_log_tick = log_now_tick;
    }

    return RT_EOK;
}
