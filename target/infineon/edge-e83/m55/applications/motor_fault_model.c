#include <firmament.h>
#include <string.h>

#include "motor_fault_features.h"
#include "motor_fault_model.h"

#if MOTOR_FAULT_MODEL_INPUT_COUNT != MOTOR_FAULT_FEATURE_COUNT
#error Motor fault model input count must match extracted feature count.
#endif

#ifdef MF_ENABLE_AI_MODEL
int IMAI_compute(const float* restrict data_in, float* restrict data_out);
void IMAI_finalize(void);
int IMAI_soft_reset(void);
int IMAI_init(void);
#endif

static MotorFaultModelStatus mf_model_state = {
#ifdef MF_ENABLE_AI_MODEL
    .enabled = 1U,
#else
    .enabled = 0U,
#endif
    .initialized = 0U,
    .has_result = 0U,
    .init_result = 0,
    .last_compute_result = 0,
    .predicted_class = -1,
    .last_timestamp_ms = 0U,
    .output = { 0.0f },
};

static const char* const mf_class_names[MOTOR_FAULT_MODEL_OUTPUT_COUNT] = {
    "normal",
    "motor1_fault",
    "motor2_fault",
    "motor3_fault",
    "motor4_fault",
};

const char* motor_fault_class_name(int class_index)
{
    if (class_index < 0 || class_index >= (int)MOTOR_FAULT_MODEL_OUTPUT_COUNT) {
        return "unknown";
    }

    return mf_class_names[class_index];
}

void motor_fault_model_get_status(MotorFaultModelStatus* status)
{
    if (status == RT_NULL) {
        return;
    }

    *status = mf_model_state;
}

static int mf_model_argmax(const float* output, unsigned output_count)
{
    int best_index = 0;
    float best_value;

    if (output == RT_NULL || output_count == 0U) {
        return -1;
    }

    best_value = output[0];
    for (unsigned i = 1U; i < output_count; i++) {
        if (output[i] > best_value) {
            best_value = output[i];
            best_index = (int)i;
        }
    }

    return best_index;
}

static int mf_model_init_once(void)
{
#ifdef MF_ENABLE_AI_MODEL
    if (mf_model_state.initialized) {
        return mf_model_state.init_result;
    }

    mf_model_state.init_result = IMAI_init();
    if (mf_model_state.init_result == 0) {
        mf_model_state.initialized = 1U;
    }

    return mf_model_state.init_result;
#else
    mf_model_state.init_result = -2;
    return mf_model_state.init_result;
#endif
}

void motor_fault_on_features(const float* features, unsigned feature_count, uint32_t timestamp_ms)
{
#ifdef MF_ENABLE_AI_MODEL
    if (features == RT_NULL || feature_count != MOTOR_FAULT_MODEL_INPUT_COUNT) {
        mf_model_state.last_compute_result = -2;
        return;
    }

    if (mf_model_init_once() != 0) {
        mf_model_state.last_compute_result = mf_model_state.init_result;
        return;
    }

    mf_model_state.last_compute_result = IMAI_compute(features, mf_model_state.output);
    mf_model_state.last_timestamp_ms = timestamp_ms;
    if (mf_model_state.last_compute_result == 0) {
        mf_model_state.predicted_class = mf_model_argmax(mf_model_state.output,
                                                          MOTOR_FAULT_MODEL_OUTPUT_COUNT);
        mf_model_state.has_result = 1U;
    }
#else
    (void)features;
    (void)feature_count;
    (void)timestamp_ms;

    mf_model_state.last_compute_result = -2;
#endif
}

static void mf_model_status_cmd(int argc, char** argv)
{
    MotorFaultModelStatus status;

    (void)argc;
    (void)argv;

    motor_fault_model_get_status(&status);

    rt_kprintf("motor fault model: %s\n", status.enabled ? "enabled" : "disabled");
    rt_kprintf("initialized:%u init_result:%d last_compute_result:%d\n",
               status.initialized,
               status.init_result,
               status.last_compute_result);

    if (!status.has_result) {
        rt_kprintf("last result: none\n");
        return;
    }

    rt_kprintf("last_timestamp_ms:%u class:%d %s\n",
               status.last_timestamp_ms,
               status.predicted_class,
               motor_fault_class_name(status.predicted_class));

    for (unsigned i = 0U; i < MOTOR_FAULT_MODEL_OUTPUT_COUNT; i++) {
        int value_int = (int)status.output[i];
        int value_frac = (int)((status.output[i] - value_int) * 1000000.0f);

        if (value_frac < 0) {
            value_frac = -value_frac;
        }

        rt_kprintf("out[%u]=%d.%06d\n", i, value_int, value_frac);
    }
}
MSH_CMD_EXPORT_ALIAS(mf_model_status_cmd, mf_model_status, show motor fault model status);
