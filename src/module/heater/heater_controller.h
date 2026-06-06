#ifndef HEATER_CONTROLLER_H__
#define HEATER_CONTROLLER_H__

#include "module/ipc/uMCN.h"
#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HEATER_DEFAULT_TARGET_TEMP_DEG_C 50.0f
#define HEATER_MIN_TARGET_TEMP_DEG_C     0.0f
#define HEATER_MAX_TARGET_TEMP_DEG_C     80.0f
#define HEATER_DEFAULT_FF                0.03f
#define HEATER_DEFAULT_KP                0.8f
#define HEATER_DEFAULT_KI                0.02f
#define HEATER_DEFAULT_INTEGRAL_LIMIT    0.25f
#define HEATER_DEFAULT_CONTROL_PERIOD_MS 10U
#define HEATER_MIN_CONTROL_PERIOD_MS     5U
#define HEATER_DEFAULT_STATUS_PERIOD_MS  1000U
#define HEATER_MIN_VALID_TEMP_DEG_C      -100.0f
#define HEATER_MAX_VALID_TEMP_DEG_C      150.0f

typedef struct {
    uint32_t timestamp_ms;
    float temperature_deg_C;
    float target_temperature_deg_C;
    float duty;
    float power_ratio;
    uint32_t heater_on_ms;
    uint8_t temperature_valid;
    uint8_t heater_on;
} heater_status_t;

typedef struct {
    float target_temp_deg_C;
    float ff;
    float kp;
    float ki;
    float integral_limit;
    uint32_t control_period_ms;
    uint32_t status_period_ms;
} heater_control_params_t;

typedef fmt_err_t (*heater_read_temperature_cb)(float* temp_deg_C, void* user_data);
typedef fmt_err_t (*heater_set_power_cb)(float power_ratio, uint32_t control_period_ms, void* user_data);

typedef struct {
    const char* name;
    const char* workqueue_name;
    heater_control_params_t params;
    heater_read_temperature_cb read_temperature;
    heater_set_power_cb set_power;
    void* user_data;
} heater_controller_config_t;

MCN_DECLARE(heater_status);

fmt_err_t heater_controller_init(const heater_controller_config_t* config);

#ifdef __cplusplus
}
#endif

#endif
