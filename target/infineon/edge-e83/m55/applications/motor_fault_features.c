#include "motor_fault_features.h"

#include <math.h>

static float mf_absf(float value)
{
    return value < 0.0f ? -value : value;
}

static void append_stats(const float* values, unsigned count, float* features, unsigned* offset)
{
    float sum = 0.0f;
    float sum_sq = 0.0f;
    float min_v = values[0];
    float max_v = values[0];
    float abs_max = mf_absf(values[0]);

    for (unsigned i = 0; i < count; i++) {
        float value = values[i];
        float abs_value = mf_absf(value);

        sum += value;
        sum_sq += value * value;

        if (value < min_v) {
            min_v = value;
        }
        if (value > max_v) {
            max_v = value;
        }
        if (abs_value > abs_max) {
            abs_max = abs_value;
        }
    }

    float mean = sum / (float)count;
    float variance = sum_sq / (float)count - mean * mean;
    if (variance < 0.0f) {
        variance = 0.0f;
    }

    features[(*offset)++] = (float)count;
    features[(*offset)++] = mean;
    features[(*offset)++] = sqrtf(variance);
    features[(*offset)++] = min_v;
    features[(*offset)++] = max_v;
    features[(*offset)++] = sqrtf(sum_sq / (float)count);
    features[(*offset)++] = abs_max;
    features[(*offset)++] = values[count - 1U];
    features[(*offset)++] = values[count - 1U] - values[0];
}

static void build_pwm_derived(const MotorFaultFrame* frames,
                              unsigned frame_count,
                              float pwm_high_threshold,
                              float spread[MOTOR_FAULT_WINDOW_SIZE],
                              float minus_others[4][MOTOR_FAULT_WINDOW_SIZE],
                              float high_ratio[4])
{
    unsigned high_count[4] = { 0U, 0U, 0U, 0U };

    for (unsigned i = 0; i < frame_count; i++) {
        float cmd[4];
        float min_cmd;
        float max_cmd;

        for (unsigned motor = 0; motor < 4U; motor++) {
            cmd[motor] = frames[i].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD0 + motor];
            if (cmd[motor] > pwm_high_threshold) {
                high_count[motor]++;
            }
        }

        min_cmd = cmd[0];
        max_cmd = cmd[0];
        for (unsigned motor = 1U; motor < 4U; motor++) {
            if (cmd[motor] < min_cmd) {
                min_cmd = cmd[motor];
            }
            if (cmd[motor] > max_cmd) {
                max_cmd = cmd[motor];
            }
        }

        spread[i] = max_cmd - min_cmd;

        for (unsigned motor = 0; motor < 4U; motor++) {
            float other_sum = 0.0f;
            for (unsigned other = 0; other < 4U; other++) {
                if (other != motor) {
                    other_sum += cmd[other];
                }
            }
            minus_others[motor][i] = cmd[motor] - other_sum / 3.0f;
        }
    }

    for (unsigned motor = 0; motor < 4U; motor++) {
        high_ratio[motor] = (float)high_count[motor] / (float)frame_count;
    }
}

unsigned motor_fault_extract_features(const MotorFaultFrame* frames,
                                      unsigned frame_count,
                                      float pwm_high_threshold,
                                      float* features,
                                      unsigned feature_capacity)
{
    unsigned offset = 0U;
    float values[MOTOR_FAULT_WINDOW_SIZE];
    float spread[MOTOR_FAULT_WINDOW_SIZE];
    float minus_others[4][MOTOR_FAULT_WINDOW_SIZE];
    float high_ratio[4];

    if (frames == 0 || features == 0 || frame_count == 0U || frame_count > MOTOR_FAULT_WINDOW_SIZE) {
        return 0U;
    }

    if (feature_capacity < MOTOR_FAULT_FEATURE_COUNT) {
        return 0U;
    }

    for (unsigned signal = MOTOR_FAULT_SIGNAL_CONTROL_CMD0; signal <= MOTOR_FAULT_SIGNAL_CONTROL_CMD3; signal++) {
        for (unsigned i = 0; i < frame_count; i++) {
            values[i] = frames[i].signal[signal];
        }
        append_stats(values, frame_count, features, &offset);
    }

    build_pwm_derived(frames, frame_count, pwm_high_threshold, spread, minus_others, high_ratio);

    append_stats(spread, frame_count, features, &offset);

    for (unsigned motor = 0; motor < 4U; motor++) {
        append_stats(minus_others[motor], frame_count, features, &offset);
        features[offset++] = high_ratio[motor];
    }

    for (unsigned signal = MOTOR_FAULT_SIGNAL_INS_PHI; signal < MOTOR_FAULT_SIGNAL_COUNT; signal++) {
        for (unsigned i = 0; i < frame_count; i++) {
            values[i] = frames[i].signal[signal];
        }
        append_stats(values, frame_count, features, &offset);
    }

    return offset;
}
