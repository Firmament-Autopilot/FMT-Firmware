#include "drv_heater.h"
#include "driver/imu/icm42688p.h"
#include "hal/pin/pin.h"
#include "module/heater/heater_controller.h"
#include "module/workqueue/workqueue_manager.h"
#include "stm32h7xx.h"
#include <rtdevice.h>

#define __STM32_PORT(port) GPIO##port##_BASE
#define GET_PIN(PORTx, PIN) \
    (rt_base_t)((16 * (((rt_base_t)__STM32_PORT(PORTx) - (rt_base_t)GPIOA_BASE) / (0x0400UL))) + PIN)
#define HEATER_PIN                   GET_PIN(B, 9)

#define V6C_HEATER_TARGET_TEMP_DEG_C 50.0f
#define V6C_HEATER_FF                0.03f
#define V6C_HEATER_KP                0.8f
#define V6C_HEATER_KI                0.02f
#define V6C_HEATER_INTEGRAL_LIMIT    0.25f
#define V6C_HEATER_CONTROL_PERIOD_MS 10U
#define V6C_HEATER_STATUS_PERIOD_MS  1000U

typedef struct {
    rt_device_t imu_spi_dev;
    rt_device_t pin_dev;
    WorkQueue_t hp_wq;
    struct WorkItem heater_off_work;
} v6c_heater_ctx_t;

static v6c_heater_ctx_t heater_ctx = { 0 };

static void heater_set_output(rt_uint8_t status)
{
    if (heater_ctx.pin_dev) {
        struct device_pin_status pin_sta = { HEATER_PIN, status };
        heater_ctx.pin_dev->write(heater_ctx.pin_dev, 0, (void*)&pin_sta, sizeof(pin_sta));
    }
}

static void heater_off_run(void* param)
{
    heater_set_output(PIN_LOW);
}

static fmt_err_t v6c_heater_read_temperature(float* temp_deg_C, void* user_data)
{
    v6c_heater_ctx_t* ctx = (v6c_heater_ctx_t*)user_data;

    if (ctx == RT_NULL || temp_deg_C == RT_NULL) {
        return FMT_EINVAL;
    }

    return icm42688p_read_temp_deg_C(ctx->imu_spi_dev, temp_deg_C) == RT_EOK ? FMT_EOK : FMT_ERROR;
}

static fmt_err_t v6c_heater_set_power(float power_ratio, uint32_t control_period_ms, void* user_data)
{
    v6c_heater_ctx_t* ctx = (v6c_heater_ctx_t*)user_data;
    uint32_t time_on_ms;

    if (ctx == RT_NULL || ctx->pin_dev == RT_NULL) {
        return FMT_EINVAL;
    }

    if (ctx->hp_wq != RT_NULL) {
        workqueue_cancel_work(ctx->hp_wq, &ctx->heater_off_work);
    }

    if (power_ratio <= 0.0f) {
        heater_set_output(PIN_LOW);
        return FMT_EOK;
    }

    if (power_ratio > 1.0f) {
        power_ratio = 1.0f;
    }

    time_on_ms = (uint32_t)(power_ratio * (float)control_period_ms);
    if (time_on_ms > control_period_ms) {
        time_on_ms = control_period_ms;
    }

    if (time_on_ms == 0) {
        heater_set_output(PIN_LOW);
        return FMT_EOK;
    }

    heater_set_output(PIN_HIGH);
    if (ctx->hp_wq == RT_NULL) {
        heater_set_output(PIN_LOW);
        return FMT_ERROR;
    }

    ctx->heater_off_work.schedule_time = SCHEDULE_DELAY(time_on_ms);
    if (workqueue_schedule_work(ctx->hp_wq, &ctx->heater_off_work) != FMT_EOK) {
        heater_set_output(PIN_LOW);
        return FMT_ERROR;
    }

    return FMT_EOK;
}

rt_err_t drv_heater_init(const char* imu_spi_dev_name)
{
    heater_controller_config_t config = {
        .name = "heater",
        .workqueue_name = "wq:hp_work",
        .params = {
            .target_temp_deg_C = V6C_HEATER_TARGET_TEMP_DEG_C,
            .ff = V6C_HEATER_FF,
            .kp = V6C_HEATER_KP,
            .ki = V6C_HEATER_KI,
            .integral_limit = V6C_HEATER_INTEGRAL_LIMIT,
            .control_period_ms = V6C_HEATER_CONTROL_PERIOD_MS,
            .status_period_ms = V6C_HEATER_STATUS_PERIOD_MS,
        },
        .read_temperature = v6c_heater_read_temperature,
        .set_power = v6c_heater_set_power,
        .user_data = &heater_ctx,
    };

    if (imu_spi_dev_name == RT_NULL) {
        return RT_ERROR;
    }

    heater_ctx.imu_spi_dev = rt_device_find(imu_spi_dev_name);
    if (heater_ctx.imu_spi_dev == RT_NULL) {
        return RT_ERROR;
    }

    heater_ctx.pin_dev = rt_device_find("pin");
    if (heater_ctx.pin_dev == RT_NULL) {
        return RT_ERROR;
    }
    if (rt_device_open(heater_ctx.pin_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return RT_ERROR;
    }

    struct device_pin_mode pin_mode = { HEATER_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_PP };
    if (heater_ctx.pin_dev->control(heater_ctx.pin_dev, 0, &pin_mode) != RT_EOK) {
        return RT_ERROR;
    }

    heater_ctx.hp_wq = workqueue_find("wq:hp_work");
    if (heater_ctx.hp_wq == RT_NULL) {
        heater_set_output(PIN_LOW);
        return RT_ERROR;
    }

    heater_ctx.heater_off_work.name = "heater_off";
    heater_ctx.heater_off_work.period = 0;
    heater_ctx.heater_off_work.schedule_time = 0;
    heater_ctx.heater_off_work.run = heater_off_run;
    heater_ctx.heater_off_work.parameter = RT_NULL;

    heater_set_output(PIN_LOW);

    return heater_controller_init(&config) == FMT_EOK ? RT_EOK : RT_ERROR;
}
