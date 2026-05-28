#include "drv_heater.h"
#include <rtdevice.h>
#include "hal/pin/pin.h"
#include "stm32h7xx.h"
#include "driver/imu/icm42688p.h"
#include "module/workqueue/workqueue_manager.h"

#define __STM32_PORT(port)  GPIO##port##_BASE
#define GET_PIN(PORTx, PIN) (rt_base_t)((16 * (((rt_base_t)__STM32_PORT(PORTx) - (rt_base_t)GPIOA_BASE) / (0x0400UL))) + PIN)
#define HEATER_PIN          GET_PIN(B, 9)

#define SENS_IMU_TEMP       55.0f
#define SENS_IMU_TEMP_FF    0.05f
#define SENS_IMU_TEMP_P     1.0f
#define SENS_IMU_TEMP_I     0.025f
#define HEATER_PERIOD_MS    10

static struct WorkItem heater_work;
static struct WorkItem heater_off_work;
static WorkQueue_t hp_wq = NULL;
static float temp_integral = 0.0f;
static rt_device_t pin_dev = NULL;
static rt_device_t heater_imu_spi_dev = NULL;

static void heater_set_output(rt_uint8_t status)
{
    if (pin_dev) {
        struct device_pin_status pin_sta = { HEATER_PIN, status };
        pin_dev->write(pin_dev, 0, (void*)&pin_sta, sizeof(pin_sta));
    }
}

static void heater_off_run(void* param)
{
    heater_set_output(PIN_LOW);
}

static void heater_run(void* param)
{
    float temp = 0.0f;
    uint32_t time_on_ms = 0;

    if (icm42688p_read_temp_deg_C(heater_imu_spi_dev, &temp) != RT_EOK) {
        temp_integral = 0.0f;
        heater_set_output(PIN_LOW);
        return;
    }

    // Target temp condition
    float temperature_delta = SENS_IMU_TEMP - temp;

    // P term
    float P = temperature_delta * SENS_IMU_TEMP_P;

    // I term
    temp_integral += temperature_delta * SENS_IMU_TEMP_I;
    if (temp_integral > 0.25f) temp_integral = 0.25f;
    if (temp_integral < -0.25f) temp_integral = -0.25f;

    // Feedforward term + PID
    float duty = P + temp_integral + SENS_IMU_TEMP_FF;
    if (duty > 1.0f) duty = 1.0f;
    if (duty < 0.0f) duty = 0.0f;

    // Calculate time on in milliseconds
    time_on_ms = (uint32_t)(duty * (float)HEATER_PERIOD_MS);
    if (time_on_ms > HEATER_PERIOD_MS) {
        time_on_ms = HEATER_PERIOD_MS;
    }

    // Drive the heater pin
    if (time_on_ms > 0) {
        heater_set_output(PIN_HIGH);
        if (time_on_ms < HEATER_PERIOD_MS) {
            // Schedule off time
            heater_off_work.schedule_time = SCHEDULE_DELAY(time_on_ms);
            workqueue_schedule_work(hp_wq, &heater_off_work);
        }
    } else {
        heater_set_output(PIN_LOW);
    }
}

rt_err_t drv_heater_init(const char* imu_spi_dev_name)
{
    if (imu_spi_dev_name == RT_NULL) {
        return RT_ERROR;
    }

    heater_imu_spi_dev = rt_device_find(imu_spi_dev_name);
    if (heater_imu_spi_dev == RT_NULL) {
        return RT_ERROR;
    }

    // Find the pin device and open it
    pin_dev = rt_device_find("pin");
    if (pin_dev == NULL) {
        return RT_ERROR;
    }
    if (rt_device_open(pin_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return RT_ERROR;
    }

    // Configure PB9 as push-pull output
    struct device_pin_mode pin_mode = { HEATER_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_PP };
    if (pin_dev->control(pin_dev, 0, &pin_mode) != RT_EOK) {
        return RT_ERROR;
    }

    heater_set_output(PIN_LOW);

    hp_wq = workqueue_find("wq:hp_work");
    if (hp_wq == NULL) {
        return RT_ERROR;
    }

    heater_off_work.name = "heater_off";
    heater_off_work.period = 0;
    heater_off_work.schedule_time = 0;
    heater_off_work.run = heater_off_run;

    heater_work.name = "heater_on";
    heater_work.period = HEATER_PERIOD_MS;
    heater_work.schedule_time = SCHEDULE_DELAY(HEATER_PERIOD_MS);
    heater_work.run = heater_run;

    if (workqueue_schedule_work(hp_wq, &heater_work) != FMT_EOK) {
        return RT_ERROR;
    }

    return RT_EOK;
}
