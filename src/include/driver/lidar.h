
#ifndef __LIDAR_SENSOR_H__
#define __LIDAR_SENSOR_H__

#include "stm32f4xx.h"
#include <rtthread.h>

rt_err_t rt_lidar_init(char* i2c_device_name);

#endif
