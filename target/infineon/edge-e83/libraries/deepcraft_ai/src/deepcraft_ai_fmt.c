#define LOG_TAG "ai"

#include <firmament.h>

#include "deepcraft_ai_fmt.h"
#include "model.h"
#include "module/ipc/uMCN.h"
#include "module/sensor/sensor_hub.h"
#include "module/task_manager/task_manager.h"
#include "module/system/systime.h"

#ifndef DEEPCRAFT_AI_WAIT_IMU_TIMEOUT_MS
#define DEEPCRAFT_AI_WAIT_IMU_TIMEOUT_MS 1000
#endif

#ifndef DEEPCRAFT_AI_OUTPUT_LOG_INTERVAL_MS
#define DEEPCRAFT_AI_OUTPUT_LOG_INTERVAL_MS 2000
#endif

#ifndef DEEPCRAFT_AI_SAMPLE_INTERVAL_MS
#define DEEPCRAFT_AI_SAMPLE_INTERVAL_MS 20
#endif

#ifndef DEEPCRAFT_AI_SKIP_INIT_SAMPLES
#define DEEPCRAFT_AI_SKIP_INIT_SAMPLES 10
#endif

#define DEEPCRAFT_AI_GRAVITY_MSS 9.80665f
#define DEEPCRAFT_AI_RAD_TO_DEG  57.29577951308232f

MCN_DECLARE(sensor_imu0_0);

static const char* deepcraft_ai_label_text[] = IMAI_DATA_OUT_SYMBOLS;
static McnNode_t deepcraft_ai_imu_node;
static int deepcraft_ai_last_label = -1;
static uint32_t deepcraft_ai_last_log_time;
static uint32_t deepcraft_ai_last_sample_time;
static uint8_t deepcraft_ai_skip_samples = DEEPCRAFT_AI_SKIP_INIT_SAMPLES;

static void deepcraft_ai_fill_input(const imu_data_t* imu, float input[IMAI_DATA_IN_COUNT])
{
    input[0] = -imu->acc_B_mDs2[0] / DEEPCRAFT_AI_GRAVITY_MSS;
    input[1] = -imu->acc_B_mDs2[1] / DEEPCRAFT_AI_GRAVITY_MSS;
    input[2] = imu->acc_B_mDs2[2] / DEEPCRAFT_AI_GRAVITY_MSS;
    input[3] = -imu->gyr_B_radDs[0] * DEEPCRAFT_AI_RAD_TO_DEG;
    input[4] = -imu->gyr_B_radDs[1] * DEEPCRAFT_AI_RAD_TO_DEG;
    input[5] = imu->gyr_B_radDs[2] * DEEPCRAFT_AI_RAD_TO_DEG;
}

static void deepcraft_ai_process_output(void)
{
    float label_scores[IMAI_DATA_OUT_COUNT];
    int ret;

    do {
        ret = IMAI_dequeue(label_scores);
        if (ret == IMAI_RET_SUCCESS) {
            int best_label = 0;
            float max_score = label_scores[0];

            for (int i = 1; i < IMAI_DATA_OUT_COUNT; i++) {
                if (label_scores[i] > max_score) {
                    max_score = label_scores[i];
                    best_label = i;
                }
            }

            uint32_t now = systime_now_ms();
            if ((best_label != deepcraft_ai_last_label) ||
                (now - deepcraft_ai_last_log_time >= DEEPCRAFT_AI_OUTPUT_LOG_INTERVAL_MS)) {
                // LOG_I("output:%s score:%f", deepcraft_ai_label_text[best_label], max_score);
                deepcraft_ai_last_label = best_label;
                deepcraft_ai_last_log_time = now;
            }
        } else if (ret == IMAI_RET_ERROR) {
            LOG_E("IMAI_dequeue failed");
        }
    } while (ret == IMAI_RET_SUCCESS);
}

fmt_err_t deepcraft_ai_task_init(void)
{
    int ret = IMAI_init();

    if (ret != IMAI_RET_SUCCESS) {
        LOG_E("IMAI_init failed:%d", ret);
        return FMT_ERROR;
    }

    return FMT_EOK;
}

void deepcraft_ai_task_entry(void* parameter)
{
    (void)parameter;

    while (deepcraft_ai_imu_node == NULL) {
        if (MCN_HUB(sensor_imu0_0)->pdata != NULL) {
            deepcraft_ai_imu_node = mcn_subscribe(MCN_HUB(sensor_imu0_0), NULL);
        }

        if (deepcraft_ai_imu_node == NULL) {
            sys_msleep(DEEPCRAFT_AI_WAIT_IMU_TIMEOUT_MS);
        }
    }

    LOG_I("DeepCraft AI task started");

    while (1) {
        imu_data_t imu;
        float input[IMAI_DATA_IN_COUNT];

        if (!mcn_wait(deepcraft_ai_imu_node, RT_TICK_PER_SECOND)) {
            continue;
        }

        if (mcn_copy(MCN_HUB(sensor_imu0_0), deepcraft_ai_imu_node, &imu) != FMT_EOK) {
            continue;
        }

        if ((deepcraft_ai_last_sample_time != 0) &&
            (imu.timestamp_ms - deepcraft_ai_last_sample_time < DEEPCRAFT_AI_SAMPLE_INTERVAL_MS)) {
            continue;
        }
        deepcraft_ai_last_sample_time = imu.timestamp_ms;

        if (deepcraft_ai_skip_samples > 0) {
            deepcraft_ai_skip_samples--;
            continue;
        }

        deepcraft_ai_fill_input(&imu, input);

        if (IMAI_enqueue(input) != IMAI_RET_SUCCESS) {
            LOG_E("IMAI_enqueue failed");
            continue;
        }

        deepcraft_ai_process_output();
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "deepcraft",
    .init = deepcraft_ai_task_init,
    .entry = deepcraft_ai_task_entry,
    .priority = 24,
    .auto_start = true,
    .stack_size = 8192,
    .param = NULL,
    .dependency = NULL
};
