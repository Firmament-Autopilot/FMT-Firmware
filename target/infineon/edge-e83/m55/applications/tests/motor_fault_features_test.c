#include <math.h>
#include <stdio.h>

#include "../motor_fault_features.h"

#define ASSERT_CLOSE(actual, expected) assert_close((actual), (expected), #actual, __LINE__)
#define ASSERT_EQ(actual, expected) assert_eq((actual), (expected), #actual, __LINE__)

static int failures;

static void assert_close(float actual, float expected, const char* expr, int line)
{
    float diff = fabsf(actual - expected);
    if (diff > 0.0001f) {
        printf("FAIL line %d: %s expected %.6f got %.6f\n", line, expr, expected, actual);
        failures++;
    }
}

static void assert_eq(int actual, int expected, const char* expr, int line)
{
    if (actual != expected) {
        printf("FAIL line %d: %s expected %d got %d\n", line, expr, expected, actual);
        failures++;
    }
}

int main(void)
{
    MotorFaultFrame frames[4] = { 0 };
    float features[MOTOR_FAULT_FEATURE_COUNT] = { 0 };
    unsigned count;

    for (unsigned i = 0; i < 4; i++) {
        for (unsigned j = 0; j < MOTOR_FAULT_SIGNAL_COUNT; j++) {
            frames[i].signal[j] = (float)(i + 1);
        }
    }

    frames[0].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD0] = 1000.0f;
    frames[1].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD0] = 1100.0f;
    frames[2].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD0] = 1200.0f;
    frames[3].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD0] = 1300.0f;

    frames[0].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD1] = 900.0f;
    frames[1].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD1] = 900.0f;
    frames[2].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD1] = 900.0f;
    frames[3].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD1] = 900.0f;

    frames[0].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD2] = 1000.0f;
    frames[1].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD2] = 1050.0f;
    frames[2].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD2] = 1100.0f;
    frames[3].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD2] = 1150.0f;

    frames[0].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD3] = 1000.0f;
    frames[1].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD3] = 1000.0f;
    frames[2].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD3] = 1000.0f;
    frames[3].signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD3] = 1000.0f;

    count = motor_fault_extract_features(frames, 4, 1250.0f, features, MOTOR_FAULT_FEATURE_COUNT);
    ASSERT_EQ((int)count, MOTOR_FAULT_FEATURE_COUNT);

    ASSERT_CLOSE(features[0], 4.0f);
    ASSERT_CLOSE(features[1], 1150.0f);
    ASSERT_CLOSE(features[2], 111.803398f);
    ASSERT_CLOSE(features[3], 1000.0f);
    ASSERT_CLOSE(features[4], 1300.0f);
    ASSERT_CLOSE(features[5], sqrtf((1000.0f * 1000.0f + 1100.0f * 1100.0f + 1200.0f * 1200.0f + 1300.0f * 1300.0f) / 4.0f));
    ASSERT_CLOSE(features[6], 1300.0f);
    ASSERT_CLOSE(features[7], 1300.0f);
    ASSERT_CLOSE(features[8], 300.0f);

    ASSERT_CLOSE(features[36 + MOTOR_FAULT_STAT_MEAN], 312.5f);
    ASSERT_CLOSE(features[45 + MOTOR_FAULT_STAT_MEAN], 158.333328f);
    ASSERT_CLOSE(features[54], 0.25f);
    ASSERT_CLOSE(features[64], 0.0f);
    ASSERT_CLOSE(features[74], 0.0f);
    ASSERT_CLOSE(features[84], 0.0f);
    ASSERT_CLOSE(features[85 + MOTOR_FAULT_STAT_COUNT_VALUE], 4.0f);

    if (failures) {
        return 1;
    }

    printf("motor_fault_features_test passed\n");
    return 0;
}
