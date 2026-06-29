#ifndef MOTOR_FAULT_MODEL_H__
#define MOTOR_FAULT_MODEL_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MOTOR_FAULT_MODEL_INPUT_COUNT  292U
#define MOTOR_FAULT_MODEL_OUTPUT_COUNT 5U

typedef enum {
    MOTOR_FAULT_CLASS_NORMAL = 0,
    MOTOR_FAULT_CLASS_MOTOR1_FAULT,
    MOTOR_FAULT_CLASS_MOTOR2_FAULT,
    MOTOR_FAULT_CLASS_MOTOR3_FAULT,
    MOTOR_FAULT_CLASS_MOTOR4_FAULT,
} MotorFaultClass;

typedef struct {
    uint8_t enabled;
    uint8_t initialized;
    uint8_t has_result;
    int init_result;
    int last_compute_result;
    int predicted_class;
    uint32_t last_timestamp_ms;
    float output[MOTOR_FAULT_MODEL_OUTPUT_COUNT];
} MotorFaultModelStatus;

const char* motor_fault_class_name(int class_index);
int motor_fault_detected_motor_number(int class_index);
void motor_fault_model_get_status(MotorFaultModelStatus* status);

#ifdef __cplusplus
}
#endif

#endif
