#include "module/heater/heater_controller.h"
#include "module/workqueue/workqueue_manager.h"

#define HEATER_DEFAULT_WORKQUEUE_NAME "wq:hp_work"

MCN_DEFINE(heater_status, sizeof(heater_status_t));

static struct WorkItem heater_work;
static WorkQueue_t heater_wq = NULL;
static heater_controller_config_t heater_cfg;
static float temp_integral = 0.0f;
static uint32_t status_last_publish_ms = 0;

static uint8_t valid_float(float value)
{
    return value == value;
}

static uint8_t valid_temperature(float value)
{
    return valid_float(value) && value >= HEATER_MIN_VALID_TEMP_DEG_C && value <= HEATER_MAX_VALID_TEMP_DEG_C;
}

static float sanitize_range(float value, float min_value, float max_value, float default_value)
{
    if (!valid_float(value) || value < min_value || value > max_value) {
        return default_value;
    }

    return value;
}

static uint32_t sanitize_period(uint32_t value, uint32_t min_value, uint32_t default_value)
{
    if (value < min_value) {
        return default_value;
    }

    return value;
}

static void sanitize_params(heater_control_params_t* params)
{
    params->target_temp_deg_C = sanitize_range(params->target_temp_deg_C,
                                               HEATER_MIN_TARGET_TEMP_DEG_C,
                                               HEATER_MAX_TARGET_TEMP_DEG_C,
                                               HEATER_DEFAULT_TARGET_TEMP_DEG_C);
    params->ff = sanitize_range(params->ff, 0.0f, 1.0f, HEATER_DEFAULT_FF);
    params->kp = sanitize_range(params->kp, 0.0f, 100.0f, HEATER_DEFAULT_KP);
    params->ki = sanitize_range(params->ki, 0.0f, 100.0f, HEATER_DEFAULT_KI);
    params->integral_limit = sanitize_range(params->integral_limit, 0.0f, 1.0f, HEATER_DEFAULT_INTEGRAL_LIMIT);
    params->control_period_ms = sanitize_period(params->control_period_ms,
                                                HEATER_MIN_CONTROL_PERIOD_MS,
                                                HEATER_DEFAULT_CONTROL_PERIOD_MS);
    params->status_period_ms = sanitize_period(params->status_period_ms,
                                               params->control_period_ms,
                                               HEATER_DEFAULT_STATUS_PERIOD_MS);
}

static int echo_heater_status(void* param)
{
    fmt_err_t err;
    heater_status_t status;

    err = mcn_copy_from_hub((McnHub*)param, &status);
    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("timestamp:%u temp:%.2f target:%.2f duty:%.3f power:%.1f%% on:%ums valid:%u heater_on:%u\n",
                   status.timestamp_ms,
                   status.temperature_deg_C,
                   status.target_temperature_deg_C,
                   status.duty,
                   status.power_ratio * 100.0f,
                   status.heater_on_ms,
                   status.temperature_valid,
                   status.heater_on);

    return 0;
}

static void publish_status(float temp, float duty, uint32_t time_on_ms, uint8_t temp_valid)
{
    uint32_t now_ms = systime_now_ms();

    if (now_ms - status_last_publish_ms < heater_cfg.params.status_period_ms) {
        return;
    }

    heater_status_t status = {
        .timestamp_ms = now_ms,
        .temperature_deg_C = temp,
        .target_temperature_deg_C = heater_cfg.params.target_temp_deg_C,
        .duty = duty,
        .power_ratio = duty,
        .heater_on_ms = time_on_ms,
        .temperature_valid = temp_valid,
        .heater_on = time_on_ms > 0 ? 1 : 0,
    };

    status_last_publish_ms = now_ms;
    mcn_publish(MCN_HUB(heater_status), &status);
}

static uint32_t power_to_on_time_ms(float duty)
{
    uint32_t time_on_ms = (uint32_t)(duty * (float)heater_cfg.params.control_period_ms);

    if (time_on_ms > heater_cfg.params.control_period_ms) {
        time_on_ms = heater_cfg.params.control_period_ms;
    }

    return time_on_ms;
}

static void heater_run(void* param)
{
    float temp = 0.0f;
    uint32_t time_on_ms;
    fmt_err_t set_res;

    if (heater_cfg.read_temperature(&temp, heater_cfg.user_data) != FMT_EOK) {
        temp_integral = 0.0f;
        heater_cfg.set_power(0.0f, heater_cfg.params.control_period_ms, heater_cfg.user_data);
        publish_status(0.0f, 0.0f, 0, 0);
        return;
    }

    if (!valid_temperature(temp)) {
        temp_integral = 0.0f;
        heater_cfg.set_power(0.0f, heater_cfg.params.control_period_ms, heater_cfg.user_data);
        publish_status(temp, 0.0f, 0, 0);
        return;
    }

    float temperature_delta = heater_cfg.params.target_temp_deg_C - temp;
    float p = temperature_delta * heater_cfg.params.kp;

    temp_integral += temperature_delta * heater_cfg.params.ki;
    if (temp_integral > heater_cfg.params.integral_limit) {
        temp_integral = heater_cfg.params.integral_limit;
    }
    if (temp_integral < -heater_cfg.params.integral_limit) {
        temp_integral = -heater_cfg.params.integral_limit;
    }

    float duty = p + temp_integral + heater_cfg.params.ff;
    if (duty > 1.0f) {
        duty = 1.0f;
    }
    if (duty < 0.0f) {
        duty = 0.0f;
    }

    time_on_ms = power_to_on_time_ms(duty);
    set_res = heater_cfg.set_power(duty, heater_cfg.params.control_period_ms, heater_cfg.user_data);
    if (set_res != FMT_EOK) {
        temp_integral = 0.0f;
        heater_cfg.set_power(0.0f, heater_cfg.params.control_period_ms, heater_cfg.user_data);
        publish_status(temp, 0.0f, 0, 1);
        return;
    }

    publish_status(temp, duty, time_on_ms, 1);
}

fmt_err_t heater_controller_init(const heater_controller_config_t* config)
{
    const char* workqueue_name;

    if (config == RT_NULL || config->read_temperature == RT_NULL || config->set_power == RT_NULL) {
        return FMT_EINVAL;
    }

    heater_cfg = *config;
    sanitize_params(&heater_cfg.params);

    workqueue_name = heater_cfg.workqueue_name != RT_NULL ? heater_cfg.workqueue_name : HEATER_DEFAULT_WORKQUEUE_NAME;
    heater_wq = workqueue_find(workqueue_name);
    if (heater_wq == RT_NULL) {
        return FMT_ERROR;
    }

    temp_integral = 0.0f;
    status_last_publish_ms = 0;

    FMT_TRY(heater_cfg.set_power(0.0f, heater_cfg.params.control_period_ms, heater_cfg.user_data));
    FMT_TRY(mcn_advertise(MCN_HUB(heater_status), echo_heater_status));

    heater_work.name = heater_cfg.name != RT_NULL ? heater_cfg.name : "heater";
    heater_work.period = heater_cfg.params.control_period_ms;
    heater_work.schedule_time = SCHEDULE_DELAY(heater_cfg.params.control_period_ms);
    heater_work.run = heater_run;
    heater_work.parameter = RT_NULL;

    return workqueue_schedule_work(heater_wq, &heater_work);
}
