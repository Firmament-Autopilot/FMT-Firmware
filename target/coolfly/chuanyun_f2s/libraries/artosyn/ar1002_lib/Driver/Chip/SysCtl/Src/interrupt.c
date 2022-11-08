#include "interrupt.h"
#include "debuglog.h"
#include "ar8020.h"
#include "drv_systick.h"
#include "drv_usart.h"

#define MAX_IRQ_VECTROS     (99)

static Irq_handler handlers[MAX_IRQ_VECTROS] = {
    0
};

static Irq_handler postHandlers[MAX_IRQ_VECTROS] = {
    0
};

int reg_IrqHandle(IRQn_Type vct, Irq_handler hdl, Irq_handler postHdl)
{
    if(vct < MAX_IRQ_VECTROS)
    {
        handlers[vct] = hdl;
        postHandlers[vct] = postHdl;
    }
    return 1;
}

int rmv_IrqHandle(IRQn_Type vct)
{    
    if(vct < MAX_IRQ_VECTROS)
    {
        handlers[vct] = 0;
        postHandlers[vct] = 0;
    }
    return 1;
}

static inline void run_irq_hdl(IRQn_Type vct)
{    
    if(handlers[vct] != 0)
    {
        (handlers[vct])(vct);
    }
    if(postHandlers[vct] != 0)
    {
        (postHandlers[vct])(vct);
    }
}

__attribute__((weak)) void SysTicks_IncTickCount(void)
{
}

__attribute__((weak)) void osSystickHandler(void)
{
}

void SYSTICK_IRQHandler(void)
{
    SysTicks_IncTickCount();
    osSystickHandler();
}

// To replace the weak function in start.s
void default_isr(void)
{
}

// hard fault monitor, with stack frame location as input parameter.
void hard_fault_monitor(unsigned int * hardfault_args)
{
    unsigned int stacked_r0;
    unsigned int stacked_r1;
    unsigned int stacked_r2;
    unsigned int stacked_r3;
    unsigned int stacked_r12;
    unsigned int stacked_lr;
    unsigned int stacked_pc;
    unsigned int stacked_psr;
    stacked_r0 = ((unsigned long)hardfault_args[0]);
    stacked_r1 = ((unsigned long)hardfault_args[1]);
    stacked_r2 = ((unsigned long)hardfault_args[2]);
    stacked_r3 = ((unsigned long)hardfault_args[3]);
    stacked_r12 = ((unsigned long)hardfault_args[4]);
    stacked_lr = ((unsigned long)hardfault_args[5]);
    stacked_pc = ((unsigned long)hardfault_args[6]);
    stacked_psr = ((unsigned long) hardfault_args[7]);
    BOOT_Printf("Hardfault happens!\r\n");
    BOOT_Printf("R0 = %x \r\n",stacked_r0);
    BOOT_Printf("R1 = %x \r\n",stacked_r1);
    BOOT_Printf("R2 = %x \r\n",stacked_r2);
    BOOT_Printf("R3 = %x \r\n",stacked_r3);
    BOOT_Printf("R12 = %x \r\n",stacked_r12);
    BOOT_Printf("LR [R14] = %x  subroutine call return address \r\n",stacked_lr);
    BOOT_Printf("PC [R15] = %x  program counter  \r\n", stacked_pc);
    BOOT_Printf("PSR = %x \r\n",stacked_psr);
    
    while(1) {
        DLOG_Output(3000);
    };
}

// To replace the weak function in start.s
void hardfault_isr(void)
{
    __asm("TST LR, #4");
    __asm("ITE EQ");
    __asm("MRSEQ R0,MSP");
    __asm("MRSNE R0,PSP");
    __asm("B hard_fault_monitor");
}

void IRQHandler_16(void)  { run_irq_hdl(UART_INTR0_VECTOR_NUM);  }
void IRQHandler_17(void)  { run_irq_hdl(UART_INTR1_VECTOR_NUM);  }
void IRQHandler_18(void)  { run_irq_hdl(UART_INTR2_VECTOR_NUM);  }
void IRQHandler_19(void)  { run_irq_hdl(UART_INTR3_VECTOR_NUM);  }
void IRQHandler_20(void)  { run_irq_hdl(UART_INTR4_VECTOR_NUM);  }
void IRQHandler_21(void)  { run_irq_hdl(UART_INTR5_VECTOR_NUM);  }
void IRQHandler_22(void)  { run_irq_hdl(UART_INTR6_VECTOR_NUM);  }
void IRQHandler_23(void)  { run_irq_hdl(UART_INTR7_VECTOR_NUM);  }
void IRQHandler_24(void)  { run_irq_hdl(UART_INTR8_VECTOR_NUM);  }
void IRQHandler_25(void)  { run_irq_hdl(TIMER_INTR00_VECTOR_NUM);  }
void IRQHandler_26(void)  { run_irq_hdl(TIMER_INTR01_VECTOR_NUM);  }
void IRQHandler_27(void)  { run_irq_hdl(TIMER_INTR02_VECTOR_NUM);  }
void IRQHandler_28(void)  { run_irq_hdl(TIMER_INTR03_VECTOR_NUM);  }
void IRQHandler_29(void)  { run_irq_hdl(TIMER_INTR04_VECTOR_NUM);  }
void IRQHandler_30(void)  { run_irq_hdl(TIMER_INTR05_VECTOR_NUM);  }
void IRQHandler_31(void)  { run_irq_hdl(TIMER_INTR06_VECTOR_NUM);  }
void IRQHandler_32(void)  { run_irq_hdl(TIMER_INTR07_VECTOR_NUM);  }
void IRQHandler_33(void)  { run_irq_hdl(TIMER_INTR10_VECTOR_NUM);  }
void IRQHandler_34(void)  { run_irq_hdl(TIMER_INTR11_VECTOR_NUM);  }
void IRQHandler_35(void)  { run_irq_hdl(TIMER_INTR12_VECTOR_NUM);  }
void IRQHandler_36(void)  { run_irq_hdl(TIMER_INTR13_VECTOR_NUM);  }
void IRQHandler_37(void)  { run_irq_hdl(TIMER_INTR14_VECTOR_NUM);  }
void IRQHandler_38(void)  { run_irq_hdl(TIMER_INTR15_VECTOR_NUM);  }
void IRQHandler_39(void)  { run_irq_hdl(TIMER_INTR16_VECTOR_NUM);  }
void IRQHandler_40(void)  { run_irq_hdl(TIMER_INTR17_VECTOR_NUM);  }
void IRQHandler_41(void)  { run_irq_hdl(TIMER_INTR20_VECTOR_NUM);  }
void IRQHandler_42(void)  { run_irq_hdl(TIMER_INTR21_VECTOR_NUM);  }
void IRQHandler_43(void)  { run_irq_hdl(TIMER_INTR22_VECTOR_NUM);  }
void IRQHandler_44(void)  { run_irq_hdl(TIMER_INTR23_VECTOR_NUM);  }
void IRQHandler_45(void)  { run_irq_hdl(TIMER_INTR24_VECTOR_NUM);  }
void IRQHandler_46(void)  { run_irq_hdl(TIMER_INTR25_VECTOR_NUM);  }
void IRQHandler_47(void)  { run_irq_hdl(TIMER_INTR26_VECTOR_NUM);  }
void IRQHandler_48(void)  { run_irq_hdl(TIMER_INTR27_VECTOR_NUM);  }
void IRQHandler_49(void)  { run_irq_hdl(SSI_INTR_N0_VECTOR_NUM);  }
void IRQHandler_50(void)  { run_irq_hdl(SSI_INTR_N1_VECTOR_NUM);  }
void IRQHandler_51(void)  { run_irq_hdl(SSI_INTR_N2_VECTOR_NUM);  }
void IRQHandler_52(void)  { run_irq_hdl(SSI_INTR_N3_VECTOR_NUM);  }
void IRQHandler_53(void)  { run_irq_hdl(SSI_INTR_N4_VECTOR_NUM);  }
void IRQHandler_54(void)  { run_irq_hdl(SSI_INTR_N5_VECTOR_NUM);  }
void IRQHandler_55(void)  { run_irq_hdl(SSI_INTR_N6_VECTOR_NUM);  }
void IRQHandler_56(void)  { run_irq_hdl(I2C_INTR0_VECTOR_NUM);  }
void IRQHandler_57(void)  { run_irq_hdl(I2C_INTR1_VECTOR_NUM);  }
void IRQHandler_58(void)  { run_irq_hdl(I2C_INTR2_VECTOR_NUM);  }
void IRQHandler_59(void)  { run_irq_hdl(I2C_INTR3_VECTOR_NUM);  }
void IRQHandler_60(void)  { run_irq_hdl(CAN_IRQ0_VECTOR_NUM);  }
void IRQHandler_61(void)  { run_irq_hdl(CAN_IRQ1_VECTOR_NUM);  }
void IRQHandler_62(void)  { run_irq_hdl(CAN_IRQ2_VECTOR_NUM);  }
void IRQHandler_63(void)  { run_irq_hdl(CAN_IRQ3_VECTOR_NUM);  }
void IRQHandler_64(void)  { run_irq_hdl(WDT_INTR0_VECTOR_NUM);  }
void IRQHandler_65(void)  { run_irq_hdl(WDT_INTR1_VECTOR_NUM);  }
void IRQHandler_66(void)  { run_irq_hdl(GPIO_INTR_N0_VECTOR_NUM);  }
void IRQHandler_67(void)  { run_irq_hdl(GPIO_INTR_N1_VECTOR_NUM);  }
void IRQHandler_68(void)  { run_irq_hdl(GPIO_INTR_N2_VECTOR_NUM);  }
void IRQHandler_69(void)  { run_irq_hdl(GPIO_INTR_N3_VECTOR_NUM);  }
void IRQHandler_70(void)  { run_irq_hdl(I2C_SLV_INTR_VECTOR_NUM);  }
void IRQHandler_71(void)  { run_irq_hdl(RTC_INTR_VECTOR_NUM);  }
void IRQHandler_72(void)  { run_irq_hdl(OTG_INTR0_VECTOR_NUM);  }
void IRQHandler_73(void)  { run_irq_hdl(OTG_INTR1_VECTOR_NUM);  }
void IRQHandler_74(void)  { run_irq_hdl(SD_INTR_VECTOR_NUM);  }
void IRQHandler_75(void)  { run_irq_hdl(DMA_INTR_N_VECTOR_NUM);  }
void IRQHandler_76(void)  { run_irq_hdl(VIDEO_UART9_INTR_VECTOR_NUM);  }
void IRQHandler_77(void)  { run_irq_hdl(VIDEO_ARMCM7_IRQ_VECTOR_NUM);  }
void IRQHandler_78(void)  { run_irq_hdl(VIDEO_UART10_INTR_VECTOR_NUM);  }
void IRQHandler_79(void)  { run_irq_hdl(VIDEO_I2C_INTR_VIDEO_VECTOR_NUM);  }
void IRQHandler_80(void)  { run_irq_hdl(VIDEO_SSI_INTR_VIDEO_VECTOR_NUM);  }
void IRQHandler_81(void)  { run_irq_hdl(VIDEO_WDT_INTR2_VECTOR_NUM);  }
void IRQHandler_82(void)  { run_irq_hdl(VIDEO_SPI_INTR_BB_VECTOR_NUM);  }
void IRQHandler_83(void)  { run_irq_hdl(VIDEO_IMGWR_FD_CH1_INTR_VECTOR_NUM);  }
void IRQHandler_84(void)  { run_irq_hdl(VIDEO_IMGWR_FD_CH0_INTR_VECTOR_NUM);  }
void IRQHandler_85(void)  { run_irq_hdl(VIDEO_GLOBAL2_INTR_RES_VSOC0_VECTOR_NUM);  }
void IRQHandler_86(void)  { run_irq_hdl(VIDEO_GLOBAL2_INTR_RES_VSOC1_VECTOR_NUM);  }
void IRQHandler_87(void)  { run_irq_hdl(BB_SRAM_READY_IRQ_0_VECTOR_NUM);  }
void IRQHandler_88(void)  { run_irq_hdl(BB_SRAM_READY_IRQ_1_VECTOR_NUM);  }
void IRQHandler_89(void)  { run_irq_hdl(BB_TX_ENABLE_VECTOR_NUM);  }
void IRQHandler_90(void)  { run_irq_hdl(BB_RX_ENABLE_VECTOR_NUM);  }
void IRQHandler_91(void)  { run_irq_hdl(CM7_1_FPU_IRQ0);  }
void IRQHandler_92(void)  { run_irq_hdl(CM7_1_FPU_IRQ1);  }
void IRQHandler_93(void)  { run_irq_hdl(CM7_1_FPU_IRQ2);  }
void IRQHandler_94(void)  { run_irq_hdl(CM7_1_FPU_IRQ3);  }
void IRQHandler_95(void)  { run_irq_hdl(CM7_1_FPU_IRQ4);  }
void IRQHandler_96(void)  { run_irq_hdl(CM7_1_FPU_IRQ5);  }
void IRQHandler_97(void)  { run_irq_hdl(CM7_1_CTIIRQ0);  }
void IRQHandler_98(void)  { run_irq_hdl(CM7_1_CTIIRQ1);  }

