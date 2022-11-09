//====================================================
// Timer Driver
//====================================================

#ifndef _TIMER_H
#define _TIMER_H

#include <stdint.h>

typedef struct init_timer
{
    uint8_t base_time_group;
    uint8_t time_num;
    uint8_t ctrl;
    uint8_t reserved;

} init_timer_st;

typedef struct timer_handle
{
    uint32_t count;
    uint32_t overflow;
    uint32_t reload;
    uint32_t data;
    uint32_t base_time;
    void (*function)(void);
    
} timer_handle_st;

enum timer_error
{
    TIMER_SUCCESS = 0,
    TIMER_FULL,
    TIMER_NOT_TIME,
    TIMER_NOEXISTENT,
    TIMER_GETCLOCKFAIL
};
/*
#define TIMER_SUCCESS 0
#define TIMER_FULL -1
#define TIMER_NOT_TIME -2
#define TIMER_NOEXISTENT -3
*/
#define TIME_ENABLE 1
#define TIME_INT_MASK (0x1 << 2) 
#define TIME_PWM_ENABLE (0x1 << 3)
#define USER_DEFINED (0x1 << 1)

#define TIEM_DISABLE 0


#define BASE_ADDR_TIMER0 0x40000000
#define BASE_ADDR_TIMER1 0x40040000
#define BASE_ADDR_TIMER2 0x40080000

#define TMREOI 0xa4

#define TMRNEOI_0         0x0C 
#define TMRNEOI_1         0x20 
#define TMRNEOI_2         0x34 
#define TMRNEOI_3         0x48 
#define TMRNEOI_4         0x5C 
#define TMRNEOI_5         0x70 
#define TMRNEOI_6         0x84 
#define TMRNEOI_7         0x98 

#define CTRL_0            0x08
#define CTRL_1            0x1C
#define CTRL_2            0x30
#define CTRL_3            0x44
#define CTRL_4            0x58
#define CTRL_5            0x6C
#define CTRL_6            0x80
#define CTRL_7            0x94


#define TIMER0_TNT_STATUS 0x10
#define TIMER1_TNT_STATUS 0x24
#define TIMER2_TNT_STATUS 0x38
#define TIMER3_TNT_STATUS 0x4C
#define TIMER4_TNT_STATUS 0x60
#define TIMER5_TNT_STATUS 0x74
#define TIMER6_TNT_STATUS 0x88
#define TIMER7_TNT_STATUS 0x9C

#define CNT1_0            0x00
#define CNT1_1            0x14
#define CNT1_2            0x28
#define CNT1_3            0x3C
#define CNT1_4            0x50
#define CNT1_5            0x64
#define CNT1_6            0x78
#define CNT1_7            0x8C

#define CNT2_0            0xB0
#define CNT2_1            0xB4
#define CNT2_2            0xB8
#define CNT2_3            0xBC
#define CNT2_4            0xC0
#define CNT2_5            0xC4
#define CNT2_6            0xC8
#define CNT2_7            0xCC

 
uint8_t TIM_RegisterTimer(init_timer_st time_st, uint32_t time_us);
uint8_t TIM_StartTimer(init_timer_st time_st);
uint8_t TIM_StopTimer(init_timer_st time_st);
uint8_t TIM_ClearNvic(init_timer_st time_st);
uint8_t TIM_IntrGetIntrStatus(init_timer_st time_st);


uint8_t TIM_RegisterPwm(init_timer_st time_st, uint32_t low_us, uint32_t high_us);
uint8_t TIM_StartPwm(init_timer_st time_st);
uint8_t TIM_StopPwm(init_timer_st time_st);
uint8_t TIM_ModifyPwmCount(init_timer_st time_st, uint32_t low_us, uint32_t high_us);


#endif
