/*
 * File      : hmc5883.h
 *
 *
 * Change Logs:
 * Date           Author       	Notes
 * 2017-10-19     zoujiachi   	the first version
 */

#ifndef HMC5883_H__
#define HMC5883_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

rt_err_t rt_hmc5883_init(char* i2c_device_name);

#ifdef __cplusplus
}
#endif

#endif
