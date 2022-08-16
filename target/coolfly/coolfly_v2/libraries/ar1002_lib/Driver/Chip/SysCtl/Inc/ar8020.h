#ifndef __AR8020_H
#define __AR8020_H


#define _EXT_DTCM_EKF2  __attribute__((section(".cf_dtcm0_ekf2")))

typedef enum
{
    SysTick_IRQn = -1,
    UART_INTR0_VECTOR_NUM = 0,                  //16
    UART_INTR1_VECTOR_NUM,                      //17
    UART_INTR2_VECTOR_NUM,                      //18
    UART_INTR3_VECTOR_NUM,                      //19
    UART_INTR4_VECTOR_NUM,                      //20
    UART_INTR5_VECTOR_NUM,                      //21
    UART_INTR6_VECTOR_NUM,                      //22
    UART_INTR7_VECTOR_NUM,                      //23
    UART_INTR8_VECTOR_NUM,                      //24
    TIMER_INTR00_VECTOR_NUM,                    //25
    TIMER_INTR01_VECTOR_NUM,                    //26
    TIMER_INTR02_VECTOR_NUM,                    //27
    TIMER_INTR03_VECTOR_NUM,                    //28
    TIMER_INTR04_VECTOR_NUM,                    //29
    TIMER_INTR05_VECTOR_NUM,                    //30
    TIMER_INTR06_VECTOR_NUM,                    //31
    TIMER_INTR07_VECTOR_NUM,                    //32
    TIMER_INTR10_VECTOR_NUM,                    //33
    TIMER_INTR11_VECTOR_NUM,                    //34
    TIMER_INTR12_VECTOR_NUM,                    //35
    TIMER_INTR13_VECTOR_NUM,                    //36
    TIMER_INTR14_VECTOR_NUM,                    //37
    TIMER_INTR15_VECTOR_NUM,                    //38
    TIMER_INTR16_VECTOR_NUM,                    //39
    TIMER_INTR17_VECTOR_NUM,                    //40
    TIMER_INTR20_VECTOR_NUM,                    //41
    TIMER_INTR21_VECTOR_NUM,                    //42
    TIMER_INTR22_VECTOR_NUM,                    //43
    TIMER_INTR23_VECTOR_NUM,                    //44
    TIMER_INTR24_VECTOR_NUM,                    //45
    TIMER_INTR25_VECTOR_NUM,                    //46
    TIMER_INTR26_VECTOR_NUM,                    //47
    TIMER_INTR27_VECTOR_NUM,                    //48
    SSI_INTR_N0_VECTOR_NUM,                     //49
    SSI_INTR_N1_VECTOR_NUM,                     //50
    SSI_INTR_N2_VECTOR_NUM,                     //51
    SSI_INTR_N3_VECTOR_NUM,                     //52
    SSI_INTR_N4_VECTOR_NUM,                     //53
    SSI_INTR_N5_VECTOR_NUM,                     //54
    SSI_INTR_N6_VECTOR_NUM,                     //55
    I2C_INTR0_VECTOR_NUM,                       //56
    I2C_INTR1_VECTOR_NUM,                       //57
    I2C_INTR2_VECTOR_NUM,                       //58
    I2C_INTR3_VECTOR_NUM,                       //59
    CAN_IRQ0_VECTOR_NUM,                        //60
    CAN_IRQ1_VECTOR_NUM,                        //61
    CAN_IRQ2_VECTOR_NUM,                        //62
    CAN_IRQ3_VECTOR_NUM,                        //63
    WDT_INTR0_VECTOR_NUM,                       //64
    WDT_INTR1_VECTOR_NUM,                       //65
    GPIO_INTR_N0_VECTOR_NUM,                    //66
    GPIO_INTR_N1_VECTOR_NUM,                    //67
    GPIO_INTR_N2_VECTOR_NUM,                    //68
    GPIO_INTR_N3_VECTOR_NUM,                    //69
    I2C_SLV_INTR_VECTOR_NUM,                    //70
    RTC_INTR_VECTOR_NUM,                        //71
    OTG_INTR0_VECTOR_NUM,                       //72
    OTG_INTR1_VECTOR_NUM,                       //73
    SD_INTR_VECTOR_NUM,                         //74
    DMA_INTR_N_VECTOR_NUM,                      //75
    VIDEO_UART9_INTR_VECTOR_NUM,                //76
    VIDEO_ARMCM7_IRQ_VECTOR_NUM,                //77
    VIDEO_UART10_INTR_VECTOR_NUM,               //78
    VIDEO_I2C_INTR_VIDEO_VECTOR_NUM,            //79
    VIDEO_SSI_INTR_VIDEO_VECTOR_NUM,            //80
    VIDEO_WDT_INTR2_VECTOR_NUM,                 //81
    VIDEO_SPI_INTR_BB_VECTOR_NUM,               //82
    VIDEO_IMGWR_FD_CH1_INTR_VECTOR_NUM,         //83
    VIDEO_IMGWR_FD_CH0_INTR_VECTOR_NUM,         //84
    VIDEO_GLOBAL2_INTR_RES_VSOC0_VECTOR_NUM,    //85
    VIDEO_GLOBAL2_INTR_RES_VSOC1_VECTOR_NUM,    //86
    BB_SRAM_READY_IRQ_0_VECTOR_NUM,             //87
    BB_SRAM_READY_IRQ_1_VECTOR_NUM,             //88
    BB_TX_ENABLE_VECTOR_NUM,                    //89
    BB_RX_ENABLE_VECTOR_NUM,                    //90
    CM7_1_FPU_IRQ0 =  75,                       //91
    CM7_1_FPU_IRQ1,                             //92
    CM7_1_FPU_IRQ2,                             //93
    CM7_1_FPU_IRQ3,                             //94
    CM7_1_FPU_IRQ4,                             //95
    CM7_1_FPU_IRQ5,                             //96
    CM7_1_CTIIRQ0,                              //97
    CM7_1_CTIIRQ1,                              //98
    CM7_2_FPU_IRQ0 = 75,                        //91
    CM7_2_FPU_IRQ1,                             //92
    CM7_2_FPU_IRQ2,                             //93
    CM7_2_FPU_IRQ3,                             //94
    CM7_2_FPU_IRQ4,                             //95
    CM7_2_FPU_IRQ5,                             //96
    CM7_2_CTIIRQ0,                              //97
    CM7_2_CTIIRQ1,                              //98
    CM7_3_FPU_IRQ0 = 75,                        //91
    CM7_3_FPU_IRQ1,                             //92
    CM7_3_FPU_IRQ2,                             //93
    CM7_3_FPU_IRQ3,                             //94
    CM7_3_FPU_IRQ4,                             //95
    CM7_3_FPU_IRQ5,                             //96
    CM7_3_CTIIRQ0,                              //97
    CM7_3_CTIIRQ1,                              //98
}IRQn_Type;


/**
 * @brief Configuration of the Cortex-M7 Processor and Core Peripherals 
 */
#define __MPU_PRESENT             1       /*!< CM7 provides an MPU                           */
#define __NVIC_PRIO_BITS          5       /*!< AR8020 CM7 uses 5 Bits for the Priority Levels*/
#define __Vendor_SysTickConfig    1       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1       /*!< FPU present                                   */
#define __ICACHE_PRESENT          1       /*!< CM7 instruction cache present                 */
#define __DCACHE_PRESENT          1       /*!< CM7 data cache present                        */


#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bits for c priority5 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bits for pre-emption priority4 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority3 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority2 bits for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority1 bits for subpriority */
#define NVIC_PRIORITYGROUP_5         ((uint32_t)0x00000002) /*!< 5 bits for pre-emption priority 0 bits for subpriority*/

#include "core_cm7.h"                 /*!< Cortex-M7 processor and core peripherals      */

#endif
