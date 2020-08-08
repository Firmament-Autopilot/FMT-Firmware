/*
 * File      : i2c_soft.h
 *
 *
 * Change Logs:
 * Date           Author       	Notes
 * 2016-6-6    		zoujiachi   	the first version
 */

#ifndef __I2C_SOFT_H__
#define __I2C_SOFT_H__

#include <rtdevice.h>

typedef enum stm32_i2c {
	BSP_I2C1 = 0,
	BSP_I2C2,
} BSP_I2C_Def;

extern struct rt_i2c_bit_ops stm32_i2c1_bit_ops;
extern struct rt_i2c_bit_ops stm32_i2c2_bit_ops;

rt_err_t stm32_i2c_pin_init(BSP_I2C_Def i2c_dev);

#endif
