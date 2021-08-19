
#ifndef LIDAR_SENSOR_H__
#define LIDAR_SENSOR_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

rt_err_t rt_lidar_init(char* i2c_device_name);

#ifdef __cplusplus
}
#endif

#endif
