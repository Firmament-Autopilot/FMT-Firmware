#include "inter_core.h"
#include "debuglog.h"
#include "interrupt.h"
#include "string.h"
#include "ar8020.h"
#include "sys_event.h"
#include "lock.h"
#include "cpu_info.h"
#include "mpu.h"
#include "cfg_parser.h"
#include "timer.h"
#include "reg_rw.h"
#include "image_struct.h"
#include "core_cm7.h"
#include "factory.h"
#include "quad_spi_ctrl.h"

#include "local_task.h"

#include <firmament.h>

void InterCore_CopyConfigureFormFlashToSRAM(void);

static init_timer_st timer2_4 = 
{
    .base_time_group = 2,
    .time_num = 4,
    .ctrl = TIME_ENABLE | USER_DEFINED,
};

static void Timer2_4_Init(void);

static void ResetTimer2_4(void);

static void InterCore_IRQ0Handler(uint32_t u32_vectorNum);




static void Timer2_4_Init(void)
{
    TIM_RegisterTimer(timer2_4, 5);
}

static void ResetTimer2_4(void)
{
    Reg_Read32(BASE_ADDR_TIMER2 + TMRNEOI_4);
    NVIC_ClearPendingIRQ(TIMER_INTR24_VECTOR_NUM);
    TIM_StopTimer(timer2_4);
}

static void InterCore_ResetIRQ0(void)
{
    ResetTimer2_4();
}

void InterCore_IRQ0_CALL(void)
{
    INTER_CORE_MSG_ID msg = 0; 
    uint8_t buf[INTER_CORE_MSG_SHARE_MEMORY_DATA_LENGTH];
    
    // Get all the messages in the SRAM buffer
    uint8_t mem_cnt = INTER_CORE_MSG_SHARE_MEMORY_NUMBER; // Max count to avoid the endless loop risk
    while(mem_cnt--)
    {
        msg = 0;
        memset(buf, 0, sizeof(buf));

        rt_base_t level = rt_hw_interrupt_disable();
        InterCore_GetMsg(&msg, buf, sizeof(buf));
        rt_hw_interrupt_enable(level);
  
        // Message process
        if (msg != 0)
        {
            // Remove the inter-core mask to avoid the loop notification
            uint32_t event = msg & ~SYS_EVENT_INTER_CORE_MASK;

            // Notify the message as a system event to the local CPU
            SYS_EVENT_Notify_From_ISR(event, (void*)buf);
        }
        else
        {
            break;
        }
    }
}

static void InterCore_IRQ0Handler(uint32_t u32_vectorNum)
{
    InterCore_ResetIRQ0();
    intercore_irq0_callback();
}


static void InterCore_TriggerIRQ0(void)
{
    TIM_StartTimer(timer2_4);
}

static void InterCore_EnableBacktraceIRQ1(void)
{
    NVIC_SetPriority(VIDEO_GLOBAL2_INTR_RES_VSOC1_VECTOR_NUM, NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,0,0));
    NVIC_EnableIRQ(VIDEO_GLOBAL2_INTR_RES_VSOC1_VECTOR_NUM);
}


void InterCore_TriggerBacktraceIRQ1(void)
{
    *((volatile uint32_t *)(INTER_CORE_TRIGGER_REG_ADDR)) |= INTER_CORE_TRIGGER_IRQ1_BITMAP;
}


__attribute__((weak)) void cm_backtrace_fault(uint32_t fault_handler_lr, uint32_t fault_handler_sp)
{
}


void InterCore_DebugIRQ1Handler(void)
{
    *((volatile uint32_t *)(INTER_CORE_TRIGGER_REG_ADDR)) = 0;

    __asm("MOV R0, LR");
    __asm("TST LR, #4");
    __asm("ITE EQ");
    __asm("MRSEQ R1,MSP");
    __asm("MRSNE R1,PSP");
    __asm("B cm_backtrace_fault");
}

void InterCore_Init(void)
{
    // Init the SRAM data share buffer
    MPU_SetUp();

    volatile INTER_CORE_MSG_TYPE* msgPtr = (INTER_CORE_MSG_TYPE*)INTER_CORE_MSG_SHARE_MEMORY_BASE_ADDR;
    memset((void*)msgPtr, 0, sizeof(INTER_CORE_MSG_TYPE)*INTER_CORE_MSG_SHARE_MEMORY_NUMBER);
    InterCore_CopyConfigureFormFlashToSRAM();
    // // // Interrupt enable
    Timer2_4_Init();
    reg_IrqHandle(TIMER_INTR24_VECTOR_NUM, InterCore_IRQ0Handler, NULL);
    NVIC_SetPriority(TIMER_INTR24_VECTOR_NUM, NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_GLOBAL2_INTR_VSOC0,0));
    NVIC_EnableIRQ(TIMER_INTR24_VECTOR_NUM);

    if (ENUM_CPU0_ID == CPUINFO_GetLocalCpuId())
    {
        InterCore_EnableBacktraceIRQ1();
    }
}

uint8_t InterCore_SendMsg(INTER_CORE_CPU_ID dst, INTER_CORE_MSG_ID msg, uint8_t* buf, uint32_t length)
{
    uint8_t i = 0;
    volatile INTER_CORE_MSG_TYPE* msgPtr = (INTER_CORE_MSG_TYPE*)INTER_CORE_MSG_SHARE_MEMORY_BASE_ADDR;
    ENUM_CPU_ID cpuid = CPUINFO_GetLocalCpuId();
    uint8_t start_idx = (cpuid * INTER_CORE_MSG_EACH_CPU_NUMBER);
    uint8_t end_idx   = (cpuid + 1) * INTER_CORE_MSG_EACH_CPU_NUMBER;

    // Parse the SRAM data buffer to find the section can be used
    uint8_t found = 0;
    for(i = start_idx ; i < end_idx; i++)
    {
        //Lock((uint32_t*)(&(msgPtr[i].lock)));
         uint32_t dataAccessed = (msgPtr[i].cpu0DataAccessed | msgPtr[i].cpu2DataAccessed);
        if(dataAccessed == msgPtr[i].enDstCpuID)
        {
            found = 1;
        }
        //UnLock((uint32_t*)(&(msgPtr[i].lock)));

        if (found)
        {
            break;
        }
    }

    // Check whether the right section is found
    if (0 == found)
    {
        DLOG_Warning("SRAM inter CPU share memory buffer is full!");
        return 0;
    }

    // Set the other parameters
    msgPtr[i].enSrcCpuID = (1 << cpuid);
    msgPtr[i].enDstCpuID = (dst & (~(msgPtr[i].enSrcCpuID)));    // Unmask the local CPU ID

    msgPtr[i].enMsgID = msg;
    memcpy((void*)(msgPtr[i].data), (void*)buf, (length <= sizeof(msgPtr[i].data)) ? length : sizeof(msgPtr[i].data));
    msgPtr[i].cpu0DataAccessed = 0;
    msgPtr[i].cpu1DataAccessed = 0;
    msgPtr[i].cpu2DataAccessed = 0;

    // Trigger the interrupt
    InterCore_TriggerIRQ0();

    return 1;
}

uint8_t InterCore_GetMsg(INTER_CORE_MSG_ID* msg_p, uint8_t* buf, uint32_t max_length)
{
    uint8_t i = 0;
    INTER_CORE_CPU_ID dst_filter;
    volatile uint32_t * pAccessed;
    ENUM_CPU_ID local_id = CPUINFO_GetLocalCpuId();
    volatile INTER_CORE_MSG_TYPE* msgPtr = (INTER_CORE_MSG_TYPE*)INTER_CORE_MSG_SHARE_MEMORY_BASE_ADDR;

    // Check the input pointers
    if ((msg_p == NULL) || (buf == NULL))
    {
        DLOG_Error("Null Pointer!");
        return 0;
    }

    // Filter to filter out other CPU's data
    dst_filter = (1 << local_id);

    // Check the data buffer to find the current CPU's data
    for(i = 0 ; i < INTER_CORE_MSG_SHARE_MEMORY_NUMBER; i++)
    {
// #ifdef INTER_CORE_DEBUG_LOG_ENABLE
//         DLOG_Info("msgPtr[%d].dataAccessed 0x%lx, msgPtr[%d].enDstCpuID 0x%x", i, msgPtr[i].cpu0DataAccessed, i, msgPtr[i].enDstCpuID);
// #endif
        pAccessed = &(msgPtr[i].cpu0DataAccessed) + local_id;
        if((*pAccessed == 0) && ((msgPtr[i].enDstCpuID & dst_filter) != 0))
        {
            break;
        }
    }

    // Check whether some message is found
    if (i == INTER_CORE_MSG_SHARE_MEMORY_NUMBER)
    {
// #ifdef INTER_CORE_DEBUG_LOG_ENABLE
        // DLOG_Info("No specified inter CPU message!");
// #endif
        return 0;
    }
    //else
    //{
        //DLOG_Info("Matched inter CPU message 0x%x!", msgPtr[i].enMsgID);
    //}

    // Retrieve the message data
    *msg_p = msgPtr[i].enMsgID;
    memcpy((void*)buf, (void*)(msgPtr[i].data), (max_length <= sizeof(msgPtr[i].data)) ?  max_length : sizeof(msgPtr[i].data));

    // Set the data accessed flag of the current CPU
    // Add lock to avoid multi CPU conflict
    //Lock((uint32_t*)(&(msgPtr[i].lock)));
    *pAccessed = dst_filter;

    __asm volatile ("dsb 0xF":::"memory");
    __asm volatile ("dmb 0xF":::"memory");

    if (*pAccessed != dst_filter)
    {
        DLOG_Error("sram write fail: %p  %lx", (void *)*pAccessed, (uint32_t)dst_filter);
    }
    //UnLock((uint32_t*)(&(msgPtr[i].lock)));

    return 1;
}


