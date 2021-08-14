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

#ifndef __PWM_H__
#define __PWM_H__

#include "global.h"

#define TIMER_FREQUENCY	3000000						// Timer frequency: 3M
#define PWM_DEFAULT_FREQUENCY	50					// pwm default frequqncy: 50Hz
#define MAX_PWM_CHAN	8							// maximal pwm output channel number

// PWM configure command
#define PWM_CMD_SET_FREQ      0x01
#define PWM_CMD_ENABLE        0x02

// PWM channel id
#define	PWM_CHAN_1            1
#define	PWM_CHAN_2            2
#define	PWM_CHAN_3            4
#define	PWM_CHAN_4            8
#define	PWM_CHAN_5            16
#define	PWM_CHAN_6            32
#define PWM_CHAN_7            64
#define	PWM_CHAN_8            128
#define	PWM_CHAN_ALL          0xFF

typedef struct {
	float duty_cyc[MAX_PWM_CHAN];
	uint8_t chan_id;
} PWM_CHAN_MSG;

typedef struct {
	uint8_t cmd;
	int val;
} PWM_CONFIG_MSG;

uint8_t pwm_init(void);
uint8_t pwm_write(float* duty_cyc, uint8_t chan_id);
uint8_t pwm_read(float* buffer, uint8_t chan_id);
uint8_t pwm_configure(uint8_t cmd, void* args);
void handle_motor_pkt(uint16_t mask, uint16_t* value);

#endif
