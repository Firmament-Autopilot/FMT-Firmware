#ifndef DRV_HEATER_H__
#define DRV_HEATER_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

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

MCN_DECLARE(heater_status);

rt_err_t drv_heater_init(const char* imu_spi_dev_name);

#ifdef __cplusplus
}
#endif

#endif
