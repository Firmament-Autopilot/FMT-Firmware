#ifndef __ISR__H
#define __ISR__H

#include <stddef.h>
#include <stdint.h>
#include "ar8020.h"

#define INTR_NVIC_PRIORITY_VIDEO_VSOC0          (8)
#define INTR_NVIC_PRIORITY_VIDEO_VSOC1          (8)
#define INTR_NVIC_PRIORITY_UART_DEFAULT         (5)
#define INTR_NVIC_PRIORITY_SPI_DEFAULT          (5)
#define INTR_NVIC_PRIORITY_I2C_DEFAULT          (5)
#define INTR_NVIC_PRIORITY_TIMER_DEFAULT        (9)
#define INTR_NVIC_PRIORITY_GPIO_DEFAULT         (9)
#define INTR_NVIC_PRIORITY_DMA_DEFAULT          (7)

//cpu0 interrupt priority use 5-10,
#define INTR_NVIC_PRIORITY_UART0                (5)
#define INTR_NVIC_PRIORITY_OTG_INITR0           (9)
#define INTR_NVIC_PRIORITY_OTG_INITR1           (9)
#define INTR_NVIC_PRIORITY_SRAM0                (9)
#define INTR_NVIC_PRIORITY_SRAM1                (9)
#define INTR_NVIC_PRIORITY_SD                   (5)
#define INTR_NVIC_PRIORITY_HDMI_GPIO            (6)
#define INTR_NVIC_PRIORITY_RTC                  (5)
#define INTR_NVIC_PRIORITY_GLOBAL2_INTR_VSOC0   (8)
#define INTR_NVIC_PRIORITY_GLOBAL2_INTR_VSOC1   (8)

//cpu1 interrupt priority use 5-10,
#define INTR_NVIC_PRIORITY_UART1                (5)
//cpu2 interrupt priority use 5-10,
#define INTR_NVIC_PRIORITY_VIDEO_UART10         (5)
#define INTR_NVIC_PRIORITY_UART2                (5)
#define INTR_NVIC_PRIORITY_TIMER00              (6)
#define INTR_NVIC_PRIORITY_TIMER01              (6)
#define INTR_NVIC_PRIORITY_BB_TX                (6)
#define INTR_NVIC_PRIORITY_BB_RX                (6)
#define INTR_NVIC_PRIORITY_VIDEO_ARMCM7         (5)

#define INTR_NVIC_PRIORITY_SYSTICK              (0x1f)


typedef void(*Irq_handler)(uint32_t);

int reg_IrqHandle(IRQn_Type vct, Irq_handler hdl, Irq_handler postHdl);
int rmv_IrqHandle(IRQn_Type vct);

void SYSTICK_IRQHandler(void);

void IRQHandler_16(void);
void IRQHandler_17(void);
void IRQHandler_18(void);
void IRQHandler_19(void);
void IRQHandler_20(void);
void IRQHandler_21(void);
void IRQHandler_22(void);
void IRQHandler_23(void);
void IRQHandler_24(void);
void IRQHandler_25(void);
void IRQHandler_26(void);
void IRQHandler_27(void);
void IRQHandler_28(void);
void IRQHandler_29(void);
void IRQHandler_30(void);
void IRQHandler_31(void);
void IRQHandler_32(void);
void IRQHandler_33(void);
void IRQHandler_34(void);
void IRQHandler_35(void);
void IRQHandler_36(void);
void IRQHandler_37(void);
void IRQHandler_38(void);
void IRQHandler_39(void);
void IRQHandler_40(void);
void IRQHandler_41(void);
void IRQHandler_42(void);
void IRQHandler_43(void);
void IRQHandler_44(void);
void IRQHandler_45(void);
void IRQHandler_46(void);
void IRQHandler_47(void);
void IRQHandler_48(void);
void IRQHandler_49(void);
void IRQHandler_50(void);
void IRQHandler_51(void);
void IRQHandler_52(void);
void IRQHandler_53(void);
void IRQHandler_54(void);
void IRQHandler_55(void);
void IRQHandler_56(void);
void IRQHandler_57(void);
void IRQHandler_58(void);
void IRQHandler_59(void);
void IRQHandler_60(void);
void IRQHandler_61(void);
void IRQHandler_62(void);
void IRQHandler_63(void);
void IRQHandler_64(void);
void IRQHandler_65(void);
void IRQHandler_66(void);
void IRQHandler_67(void);
void IRQHandler_68(void);
void IRQHandler_69(void);
void IRQHandler_70(void);
void IRQHandler_71(void);
void IRQHandler_72(void);
void IRQHandler_73(void);
void IRQHandler_74(void);
void IRQHandler_75(void);
void IRQHandler_76(void);
void IRQHandler_77(void);
void IRQHandler_78(void);
void IRQHandler_79(void);
void IRQHandler_80(void);
void IRQHandler_81(void);
void IRQHandler_82(void);
void IRQHandler_83(void);
void IRQHandler_84(void);
void IRQHandler_85(void);
void IRQHandler_86(void);
void IRQHandler_87(void);
void IRQHandler_88(void);
void IRQHandler_89(void);
void IRQHandler_90(void);
void IRQHandler_91(void);
void IRQHandler_92(void);
void IRQHandler_93(void);
void IRQHandler_94(void);
void IRQHandler_95(void);
void IRQHandler_96(void);
void IRQHandler_97(void);
void IRQHandler_98(void);

#endif

