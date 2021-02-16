/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <firmament.h>

#include "hal/i2c-bit-ops.h"
#include "hal/pin.h"
#include "driver/i2c_soft.h"

#define BSP_I2C1_SDA_PORT	GPIOB
#define BSP_I2C2_SDA_PORT	GPIOB

#define BSP_I2C1_SCL_PORT	GPIOB
#define BSP_I2C2_SCL_PORT	GPIOB

#define BSP_I2C1_SDA_PIN	GPIO_Pin_9
#define BSP_I2C2_SDA_PIN	GPIO_Pin_11

#define BSP_I2C1_SCL_PIN	GPIO_Pin_8
#define BSP_I2C2_SCL_PIN	GPIO_Pin_10

#define I2C_DELAY_US		(rt_uint32_t)20
#define I2C_TIMEOUT_TICKS	(rt_uint32_t)1

#define FMU_I2C1_PIN_SCL		95
#define FMU_I2C1_PIN_SDA		96
#define FMU_I2C2_PIN_SCL		47
#define FMU_I2C2_PIN_SDA		48

void stm32_set_sda(void* data, rt_int32_t state)
{
	BSP_I2C_Def _i2c = *(BSP_I2C_Def*)data;

	if(_i2c == BSP_I2C1) {
		if(state == 1)
			GPIO_SetBits(BSP_I2C1_SDA_PORT, BSP_I2C1_SDA_PIN);
		else if(state == 0)
			GPIO_ResetBits(BSP_I2C1_SDA_PORT, BSP_I2C1_SDA_PIN);
	} else if(_i2c == BSP_I2C2) {
		if(state == 1)
			GPIO_SetBits(BSP_I2C2_SDA_PORT, BSP_I2C2_SDA_PIN);
		else if(state == 0)
			GPIO_ResetBits(BSP_I2C2_SDA_PORT, BSP_I2C2_SDA_PIN);
	}
}

void stm32_set_scl(void* data, rt_int32_t state)
{
	BSP_I2C_Def _i2c = *(BSP_I2C_Def*)data;

	if(_i2c == BSP_I2C1) {
		if(state == 1)
			GPIO_SetBits(BSP_I2C1_SCL_PORT, BSP_I2C1_SCL_PIN);
		else if(state == 0)
			GPIO_ResetBits(BSP_I2C1_SCL_PORT, BSP_I2C1_SCL_PIN);
	} else if(_i2c == BSP_I2C2) {
		if(state == 1)
			GPIO_SetBits(BSP_I2C2_SCL_PORT, BSP_I2C2_SCL_PIN);
		else if(state == 0)
			GPIO_ResetBits(BSP_I2C2_SCL_PORT, BSP_I2C2_SCL_PIN);
	}
}

rt_int32_t stm32_get_sda(void* data)
{
	rt_int32_t val;
	BSP_I2C_Def _i2c = *(BSP_I2C_Def*)data;

	if(_i2c == BSP_I2C1) {
		//set input mode
		BSP_I2C1_SDA_PORT->MODER &= ~(GPIO_MODER_MODER0 << (9 * 2));
		val = GPIO_ReadInputDataBit(BSP_I2C1_SDA_PORT, BSP_I2C1_SDA_PIN);
		//set output mode
		BSP_I2C1_SDA_PORT->MODER |= ((uint32_t)GPIO_Mode_OUT << (9 * 2));
	} else if(_i2c == BSP_I2C2) {
		//set input mode
		BSP_I2C2_SDA_PORT->MODER &= ~(GPIO_MODER_MODER0 << (11 * 2));
		val = GPIO_ReadInputDataBit(BSP_I2C2_SDA_PORT, BSP_I2C2_SDA_PIN);
		//set output mode
		BSP_I2C2_SDA_PORT->MODER |= ((uint32_t)GPIO_Mode_OUT << (11 * 2));
	}

//	if(_i2c == BSP_I2C1){
//		val = GPIO_ReadInputDataBit(BSP_I2C1_SDA_PORT , BSP_I2C1_SDA_PIN);
//	}else if(_i2c == BSP_I2C2){
//		val = GPIO_ReadInputDataBit(BSP_I2C2_SDA_PORT , BSP_I2C2_SDA_PIN);
//	}

	return val;
}

rt_int32_t stm32_get_scl(void* data)
{
	rt_int32_t val;
	BSP_I2C_Def _i2c = *(BSP_I2C_Def*)data;

	if(_i2c == BSP_I2C1) {
		//set input mode
		BSP_I2C1_SCL_PORT->MODER &= ~(GPIO_MODER_MODER0 << (8 * 2));
		val = GPIO_ReadInputDataBit(BSP_I2C1_SCL_PORT, BSP_I2C1_SCL_PIN);
		//set output mode
		BSP_I2C1_SCL_PORT->MODER |= ((uint32_t)GPIO_Mode_OUT << (8 * 2));
	} else if(_i2c == BSP_I2C2) {
		//set input mode
		BSP_I2C2_SCL_PORT->MODER &= ~(GPIO_MODER_MODER0 << (10 * 2));
		val = GPIO_ReadInputDataBit(BSP_I2C2_SCL_PORT, BSP_I2C2_SCL_PIN);
		//set output mode
		BSP_I2C2_SCL_PORT->MODER |= ((uint32_t)GPIO_Mode_OUT << (10 * 2));
	}

//	if(_i2c == BSP_I2C1){
//		val = GPIO_ReadInputDataBit(BSP_I2C1_SCL_PORT , BSP_I2C1_SCL_PIN);
//	}else if(_i2c == BSP_I2C2){
//		val = GPIO_ReadInputDataBit(BSP_I2C2_SCL_PORT , BSP_I2C2_SCL_PIN);
//	}

	return val;
}

void stm32_udelay(rt_uint32_t us)
{
	systime_delay_us(us);
}

rt_err_t stm32_i2c_pin_init(BSP_I2C_Def i2c_dev)
{
	rt_device_t _pin_device;
	struct device_pin_mode mode;

	_pin_device = rt_device_find("pin");

	if(_pin_device == RT_NULL) {
		return RT_EEMPTY;
	}

	if(i2c_dev == BSP_I2C1) {
		mode.pin = FMU_I2C1_PIN_SCL;
		mode.mode = PIN_MODE_OUTPUT;
		mode.otype = PIN_OUT_TYPE_PP;
		_pin_device->control(_pin_device, 0, &mode);

		mode.pin = FMU_I2C1_PIN_SDA;
		mode.mode = PIN_MODE_OUTPUT;
		mode.otype = PIN_OUT_TYPE_PP;
		_pin_device->control(_pin_device, 0, &mode);
	} else if(i2c_dev == BSP_I2C2) {
		mode.pin = FMU_I2C2_PIN_SCL;
		mode.mode = PIN_MODE_OUTPUT;
		mode.otype = PIN_OUT_TYPE_PP;
		_pin_device->control(_pin_device, 0, &mode);

		mode.pin = FMU_I2C2_PIN_SDA;
		mode.mode = PIN_MODE_OUTPUT;
		mode.otype = PIN_OUT_TYPE_PP;
		_pin_device->control(_pin_device, 0, &mode);
	} else {
		printf("do not match any i2c dev\n");
	}

	return RT_EOK;
}

struct rt_i2c_bit_ops stm32_i2c1_bit_ops = {
	(void*)NULL,
	stm32_set_sda,
	stm32_set_scl,
	stm32_get_sda,
	stm32_get_scl,
	stm32_udelay,
	I2C_DELAY_US,
	I2C_TIMEOUT_TICKS
};

struct rt_i2c_bit_ops stm32_i2c2_bit_ops = {
	(void*)NULL,
	stm32_set_sda,
	stm32_set_scl,
	stm32_get_sda,
	stm32_get_scl,
	stm32_udelay,
	I2C_DELAY_US,
	I2C_TIMEOUT_TICKS
};

