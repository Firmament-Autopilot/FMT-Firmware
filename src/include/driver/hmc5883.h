/*
 * File      : hmc5883.h
 *
 *
 * Change Logs:
 * Date           Author       	Notes
 * 2017-10-19     zoujiachi   	the first version
 */

#ifndef __HMC5883_H__
#define __HMC5883_H__

#include "stm32f4xx.h"
#include <rtthread.h>

rt_err_t rt_hmc5883_init(char* i2c_device_name);

#endif
