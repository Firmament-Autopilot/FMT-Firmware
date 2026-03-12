/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-13     Rbb666       first version
 */

#ifndef __PWM_CONFIG_H__
#define __PWM_CONFIG_H__

#include <rtthread.h>
#include <board.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BSP_USING_PWM5

#ifndef TCPWM_0_GRP_0_PWM_5_CONFIG
#define TCPWM_0_GRP_0_PWM_5_CONFIG \
{                                                       \
    .tcpwm_pwm_config = &tcpwm_0_group_0_cnt_5_config,\
    .base             = TCPWM0,\
    .cntNum           = 5,\
    .name             = "pwm5",\
    .clk_dst          = CYBSP_PWM_CLK_DIV_GRP_NUM,\
    .clk_divType      = CY_SYSCLK_DIV_16_5_BIT,\
    .clk_divNum       = 1U,\
}
#endif /* TCPWM_0_GRP_0_PWM_5_CONFIG */

#endif /* BSP_USING_PWM5 */

#ifdef BSP_USING_PWM18

#ifndef TCPWM_0_GRP_1_PWM_9_CONFIG
#define TCPWM_0_GRP_1_PWM_9_CONFIG \
{                                                       \
    .tcpwm_pwm_config = &tcpwm_0_group_1_cnt_9_config,\
    .base             = TCPWM0,\
    .cntNum           = 265UL,\
    .name             = "pwm18",\
    .clk_dst          = PERI_0_GROUP_1_DIV_8_4_GRP_NUM,\
    .clk_divType      = CY_SYSCLK_DIV_8_BIT,\
    .clk_divNum       = 4U,\
}
#endif /* TCPWM_0_GRP_1_PWM_9_CONFIG */

#endif /* BSP_USING_PWM18 */

#ifdef __cplusplus
}
#endif

#endif /* __PWM_CONFIG_H__ */
