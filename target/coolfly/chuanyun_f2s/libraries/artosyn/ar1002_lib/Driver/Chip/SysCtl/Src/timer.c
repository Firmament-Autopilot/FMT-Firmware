#include "timer.h"
#include <string.h>
#include "interrupt.h"
#include "reg_rw.h"
#include "debuglog.h"
#include "pll_ctrl.h"
#include "cpu_info.h"


uint8_t TIM_ClearNvic(init_timer_st time_st)
{
    uint8_t u8_TimNum = time_st.time_num;
    uint8_t u8_TimGroup = time_st.base_time_group;
    uint32_t u32_TimBaseAddr = 0;
    if(u8_TimNum > 7 || u8_TimGroup > 2)
    {
        return TIMER_NOEXISTENT;
    }
    u32_TimBaseAddr =  ( u8_TimGroup==0)? BASE_ADDR_TIMER0:((u8_TimGroup==1)? BASE_ADDR_TIMER1:BASE_ADDR_TIMER2);

    Reg_Read32(u32_TimBaseAddr + TMRNEOI_0+(u8_TimNum*0x14));

    return TIMER_SUCCESS;
}

uint8_t TIM_IntrGetIntrStatus(init_timer_st time_st)
{
    uint8_t u8_TimNum = time_st.time_num;
    uint8_t u8_TimGroup = time_st.base_time_group;
    uint32_t u32_TimBaseAddr = 0;
    
    if(u8_TimNum > 7 || u8_TimGroup > 2)
    {
        return TIMER_NOEXISTENT;
    }

    u32_TimBaseAddr =  ( u8_TimGroup==0)? BASE_ADDR_TIMER0:((u8_TimGroup==1)? BASE_ADDR_TIMER1:BASE_ADDR_TIMER2);
    
    return Reg_Read32(u32_TimBaseAddr + TIMER0_TNT_STATUS+(u8_TimNum*0x14));
}

/*
 * timer process
 */

 void TIM_ConfigCount(uint32_t addr,
                uint32_t cnt1,uint32_t cnt1_offset,
                uint32_t cnt2,uint32_t cnt2_offset)
{      
    Reg_Write32(addr + cnt1_offset,  cnt1);               // load the count1    
    Reg_Write32(addr + cnt2_offset,  cnt2);               // load the count2
}


void TIM_Config(uint32_t addr,
                uint32_t ctrl,uint32_t ctrl_offset,
                uint32_t cnt1,uint32_t cnt1_offset,
                uint32_t cnt2,uint32_t cnt2_offset)
{      
    Reg_Write32(addr + ctrl_offset,  ctrl & 0xfffffffe);  // set PWM, Mask and Timer Mode; disable Timer 
/*    Reg_Write32(addr + cnt1_offset,  cnt1);               // load the count1    
    Reg_Write32(addr + cnt2_offset,  cnt2);               // load the count2*/
    TIM_ConfigCount(addr,cnt1,cnt1_offset,cnt2,cnt2_offset);
}


uint8_t TIM_StopTimer(init_timer_st time_st)
{
    uint8_t u8_TimNum = time_st.time_num;
    uint8_t u8_TimGroup = time_st.base_time_group;
    uint8_t u8_TimCtrl = time_st.ctrl;
    uint32_t u32_TimBaseAddr = 0;
    
    if(u8_TimNum > 7 || u8_TimGroup > 2)
    {
        return TIMER_NOEXISTENT;
    }
    
    u32_TimBaseAddr =  ( u8_TimGroup==0)? BASE_ADDR_TIMER0:((u8_TimGroup==1)? BASE_ADDR_TIMER1:BASE_ADDR_TIMER2);

    Reg_Write32(u32_TimBaseAddr + CTRL_0+(u8_TimNum*0x14), u8_TimCtrl & 0xfffffffe);
    
    return TIMER_SUCCESS;
}

uint8_t TIM_StopPwm(init_timer_st time_st)
{   
     return TIM_StopTimer(time_st);
}

uint8_t TIM_StartTimer(init_timer_st time_st)
{
    uint8_t u8_TimNum = time_st.time_num;
    uint8_t u8_TimGroup = time_st.base_time_group;
    uint32_t u32_TimBaseAddr = 0;
    if(u8_TimNum > 7 || u8_TimGroup > 2)
    {
        return TIMER_NOEXISTENT;
    }
    
    u32_TimBaseAddr =  ( u8_TimGroup==0)? BASE_ADDR_TIMER0:((u8_TimGroup==1)? BASE_ADDR_TIMER1:BASE_ADDR_TIMER2);

    Reg_Write32(u32_TimBaseAddr + CTRL_0+(u8_TimNum*0x14), time_st.ctrl);   

    return TIMER_SUCCESS;
}

uint8_t TIM_StartPwm(init_timer_st time_st)
{
    return TIM_StartTimer(time_st);
}

uint8_t TIM_RegisterTimer(init_timer_st time_st, uint32_t time_us) 
{
    uint8_t u8_TimNum = time_st.time_num;
    uint8_t u8_TimCtrl = time_st.ctrl;
    uint8_t u8_TimGroup = time_st.base_time_group;
    uint32_t u32_TimBaseAddr = 0;
    uint16_t u16_TimerClock = 0;
    PLLCTRL_GetCoreClk((uint16_t*)&u16_TimerClock, ENUM_CPU0_ID);
    u16_TimerClock = u16_TimerClock >> 1; 
    if (0 == u16_TimerClock)
    {
        return TIMER_GETCLOCKFAIL;
    }
    uint32_t u32_Tim = u16_TimerClock * time_us;
    
    if(u8_TimNum > 7 || time_st.base_time_group > 2)
    {
        return TIMER_NOEXISTENT;
    }
    
    u32_TimBaseAddr =  ( u8_TimGroup==0)? BASE_ADDR_TIMER0:((u8_TimGroup==1)? BASE_ADDR_TIMER1:BASE_ADDR_TIMER2);
    
    TIM_Config(u32_TimBaseAddr, u8_TimCtrl, CTRL_0+(u8_TimNum*0x14),
                     u32_Tim, CNT1_0+(u8_TimNum*0x14),
                     0x00, CNT2_0+(u8_TimNum*0x04));

    return TIMER_SUCCESS;
}

uint8_t TIM_RegisterPwm(init_timer_st time_st, uint32_t low_us, uint32_t high_us) 
{
    uint8_t u8_TimNum = time_st.time_num;
    uint8_t u8_TimCtrl = time_st.ctrl;
    uint8_t u8_TimGroup = time_st.base_time_group;
    uint32_t u32_TimBaseAddr = 0;
    uint16_t u16_TimerClock = 0; 
    PLLCTRL_GetCoreClk((uint16_t*)&u16_TimerClock, ENUM_CPU0_ID);
    u16_TimerClock = u16_TimerClock >> 1; 
    if (0 == u16_TimerClock)
    {
        return TIMER_GETCLOCKFAIL;
    }

    uint32_t u32_TimLow = u16_TimerClock * low_us - 1;
    uint32_t u32_TimHigh = u16_TimerClock * high_us - 1;

    
    if(u8_TimNum > 7 || time_st.base_time_group > 2)
    {
        return TIMER_NOEXISTENT;
    }
    
    u32_TimBaseAddr =  ( u8_TimGroup==0)? BASE_ADDR_TIMER0:((u8_TimGroup==1)? BASE_ADDR_TIMER1:BASE_ADDR_TIMER2);

    TIM_Config(u32_TimBaseAddr, u8_TimCtrl, CTRL_0+(u8_TimNum*0x14),
                     u32_TimLow, CNT1_0+(u8_TimNum*0x14),
                     u32_TimHigh, CNT2_0+(u8_TimNum*0x04));

    return TIMER_SUCCESS;
}

uint8_t TIM_ModifyPwmCount(init_timer_st time_st, uint32_t low_us, uint32_t high_us)
{
    uint8_t u8_TimNum = time_st.time_num;
    // uint8_t u8_TimCtrl = time_st.ctrl;
    uint8_t u8_TimGroup = time_st.base_time_group;
    uint32_t u32_TimBaseAddr = 0;
    int16_t u16_TimerClock = 0; 
    PLLCTRL_GetCoreClk((uint16_t*)&u16_TimerClock, ENUM_CPU0_ID);
    u16_TimerClock = u16_TimerClock >> 1; 
    if (0 == u16_TimerClock)
    {
        return TIMER_GETCLOCKFAIL;
    }
    uint32_t u32_TimLow = u16_TimerClock * low_us;
    uint32_t u32_TimHigh = u16_TimerClock * high_us;
    
    if(u8_TimNum > 7 || time_st.base_time_group > 2)
    {
        return TIMER_NOEXISTENT;
    }
    
    u32_TimBaseAddr =  ( u8_TimGroup==0)? BASE_ADDR_TIMER0:((u8_TimGroup==1)? BASE_ADDR_TIMER1:BASE_ADDR_TIMER2);
    
    TIM_ConfigCount(u32_TimBaseAddr, u32_TimLow, CNT1_0+(u8_TimNum*0x14),u32_TimHigh, CNT2_0+(u8_TimNum*0x04));

    return TIMER_SUCCESS;
}