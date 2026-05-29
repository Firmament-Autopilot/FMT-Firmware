#ifndef DRV_HEATER_H__
#define DRV_HEATER_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

rt_err_t drv_heater_init(const char* imu_spi_dev_name);

#ifdef __cplusplus
}
#endif

#endif
