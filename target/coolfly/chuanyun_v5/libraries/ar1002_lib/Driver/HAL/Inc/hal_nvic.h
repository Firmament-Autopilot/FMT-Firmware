/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_nvic.h
Description: this module contains the helper fucntions set interrupt
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/26
History:
         0.0.1    2016/12/26    The initial version of hal_nvic.h
*****************************************************************************/
#ifndef __HAL_NVIC_H
#define __HAL_NVIC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "hal_ret_type.h"

typedef enum
{
    HAL_NVIC_SYSTICK_VECTOR_NUM    =-1,
    HAL_NVIC_UART_INTR0_VECTOR_NUM = 0,                 //16
    HAL_NVIC_UART_INTR1_VECTOR_NUM,                      //17
    HAL_NVIC_UART_INTR2_VECTOR_NUM,                      //18
    HAL_NVIC_UART_INTR3_VECTOR_NUM,                      //19
    HAL_NVIC_UART_INTR4_VECTOR_NUM,                      //20
    HAL_NVIC_UART_INTR5_VECTOR_NUM,                      //21
    HAL_NVIC_UART_INTR6_VECTOR_NUM,                      //22
    HAL_NVIC_UART_INTR7_VECTOR_NUM,                      //23
    HAL_NVIC_UART_INTR8_VECTOR_NUM,                      //24
    HAL_NVIC_TIMER_INTR00_VECTOR_NUM,                    //25
    HAL_NVIC_TIMER_INTR01_VECTOR_NUM,                    //26
    HAL_NVIC_TIMER_INTR02_VECTOR_NUM,                    //27
    HAL_NVIC_TIMER_INTR03_VECTOR_NUM,                    //28
    HAL_NVIC_TIMER_INTR04_VECTOR_NUM,                    //29
    HAL_NVIC_TIMER_INTR05_VECTOR_NUM,                    //30
    HAL_NVIC_TIMER_INTR06_VECTOR_NUM,                    //31
    HAL_NVIC_TIMER_INTR07_VECTOR_NUM,                    //32
    HAL_NVIC_TIMER_INTR10_VECTOR_NUM,                    //33
    HAL_NVIC_TIMER_INTR11_VECTOR_NUM,                    //34
    HAL_NVIC_TIMER_INTR12_VECTOR_NUM,                    //35
    HAL_NVIC_TIMER_INTR13_VECTOR_NUM,                    //36
    HAL_NVIC_TIMER_INTR14_VECTOR_NUM,                    //37
    HAL_NVIC_TIMER_INTR15_VECTOR_NUM,                    //38
    HAL_NVIC_TIMER_INTR16_VECTOR_NUM,                    //39
    HAL_NVIC_TIMER_INTR17_VECTOR_NUM,                    //40
    HAL_NVIC_TIMER_INTR20_VECTOR_NUM,                    //41
    HAL_NVIC_TIMER_INTR21_VECTOR_NUM,                    //42
    HAL_NVIC_TIMER_INTR22_VECTOR_NUM,                    //43
    HAL_NVIC_TIMER_INTR23_VECTOR_NUM,                    //44
    HAL_NVIC_TIMER_INTR24_VECTOR_NUM,                    //45
    HAL_NVIC_TIMER_INTR25_VECTOR_NUM,                    //46
    HAL_NVIC_TIMER_INTR26_VECTOR_NUM,                    //47
    HAL_NVIC_TIMER_INTR27_VECTOR_NUM,                    //48
    HAL_NVIC_SSI_INTR_N0_VECTOR_NUM,                     //49
    HAL_NVIC_SSI_INTR_N1_VECTOR_NUM,                     //50
    HAL_NVIC_SSI_INTR_N2_VECTOR_NUM,                     //51
    HAL_NVIC_SSI_INTR_N3_VECTOR_NUM,                     //52
    HAL_NVIC_SSI_INTR_N4_VECTOR_NUM,                     //53
    HAL_NVIC_SSI_INTR_N5_VECTOR_NUM,                     //54
    HAL_NVIC_SSI_INTR_N6_VECTOR_NUM,                     //55
    HAL_NVIC_I2C_INTR0_VECTOR_NUM,                       //56
    HAL_NVIC_I2C_INTR1_VECTOR_NUM,                       //57
    HAL_NVIC_I2C_INTR2_VECTOR_NUM,                       //58
    HAL_NVIC_I2C_INTR3_VECTOR_NUM,                       //59
    HAL_NVIC_CAN_IRQ0_VECTOR_NUM,                        //60
    HAL_NVIC_CAN_IRQ1_VECTOR_NUM,                        //61
    HAL_NVIC_CAN_IRQ2_VECTOR_NUM,                        //62
    HAL_NVIC_CAN_IRQ3_VECTOR_NUM,                        //63
    HAL_NVIC_WDT_INTR0_VECTOR_NUM,                       //64
    HAL_NVIC_WDT_INTR1_VECTOR_NUM,                       //65
    HAL_NVIC_GPIO_INTR_N0_VECTOR_NUM,                    //66
    HAL_NVIC_GPIO_INTR_N1_VECTOR_NUM,                    //67
    HAL_NVIC_GPIO_INTR_N2_VECTOR_NUM,                    //68
    HAL_NVIC_GPIO_INTR_N3_VECTOR_NUM,                    //69
    HAL_NVIC_I2C_SLV_INTR_VECTOR_NUM,                    //70
    HAL_NVIC_RTC_INTR_VECTOR_NUM,                        //71
    HAL_NVIC_OTG_INTR0_VECTOR_NUM,                       //72
    HAL_NVIC_OTG_INTR1_VECTOR_NUM,                       //73
    HAL_NVIC_SD_INTR_VECTOR_NUM,                         //74
    HAL_NVIC_DMA_INTR_N_VECTOR_NUM,                      //75
    HAL_NVIC_VIDEO_UART9_INTR_VECTOR_NUM,                //76
    HAL_NVIC_VIDEO_ARMCM7_IRQ_VECTOR_NUM,                //77
    HAL_NVIC_VIDEO_UART10_INTR_VECTOR_NUM,               //78
    HAL_NVIC_VIDEO_I2C_INTR_VIDEO_VECTOR_NUM,            //79
    HAL_NVIC_VIDEO_SSI_INTR_VIDEO_VECTOR_NUM,            //80
    HAL_NVIC_VIDEO_WDT_INTR2_VECTOR_NUM,                 //81
    HAL_NVIC_VIDEO_SPI_INTR_BB_VECTOR_NUM,               //82
    HAL_NVIC_VIDEO_IMGWR_FD_CH1_INTR_VECTOR_NUM,         //83
    HAL_NVIC_VIDEO_IMGWR_FD_CH0_INTR_VECTOR_NUM,         //84
    HAL_NVIC_VIDEO_GLOBAL2_INTR_RES_VSOC0_VECTOR_NUM,    //85
    HAL_NVIC_VIDEO_GLOBAL2_INTR_RES_VSOC1_VECTOR_NUM,    //86
    HAL_NVIC_BB_SRAM_READY_IRQ_0_VECTOR_NUM,             //87
    HAL_NVIC_BB_SRAM_READY_IRQ_1_VECTOR_NUM,             //88
    HAL_NVIC_BB_TX_ENABLE_VECTOR_NUM,                    //89
    HAL_NVIC_BB_RX_ENABLE_VECTOR_NUM,                    //90
    HAL_NVIC_CM7_1_FPU_IRQ_NUM0 = 75,                    //91
    HAL_NVIC_CM7_1_FPU_IRQ_NUM1,                         //92
    HAL_NVIC_CM7_1_FPU_IRQ_NUM2,                         //93
    HAL_NVIC_CM7_1_FPU_IRQ_NUM3,                         //94
    HAL_NVIC_CM7_1_FPU_IRQ_NUM4,                         //95
    HAL_NVIC_CM7_1_FPU_IRQ_NUM5,                         //96
    HAL_NVIC_CM7_1_CTIIRQ_NUM0,                          //97
    HAL_NVIC_CM7_1_CTIIRQ_NUM1,                          //98
    HAL_NVIC_CM7_2_FPU_IRQ_NUM0 = 75,                    //91
    HAL_NVIC_CM7_2_FPU_IRQ_NUM1,                         //92
    HAL_NVIC_CM7_2_FPU_IRQ_NUM2,                         //93
    HAL_NVIC_CM7_2_FPU_IRQ_NUM3,                         //94
    HAL_NVIC_CM7_2_FPU_IRQ_NUM4,                         //95
    HAL_NVIC_CM7_2_FPU_IRQ_NUM5,                         //96
    HAL_NVIC_CM7_2_CTIIRQ_NUM0,                          //97
    HAL_NVIC_CM7_2_CTIIRQ_NUM1,                          //98
    HAL_NVIC_CM7_3_FPU_IRQ_NUM0 = 75,                    //91
    HAL_NVIC_CM7_3_FPU_IRQ_NUM1,                         //92
    HAL_NVIC_CM7_3_FPU_IRQ_NUM2,                         //93
    HAL_NVIC_CM7_3_FPU_IRQ_NUM3,                         //94
    HAL_NVIC_CM7_3_FPU_IRQ_NUM4,                         //95
    HAL_NVIC_CM7_3_FPU_IRQ_NUM5,                         //96
    HAL_NVIC_CM7_3_CTIIRQ_NUM0,                          //97
    HAL_NVIC_CM7_3_CTIIRQ_NUM1,                          //98
}ENUM_HAL_NVIC_IRQ_NUM;

typedef void(*HAL_NVIC_Irqhandler)(uint32_t);

#define HAL_NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bits for pre-emption priority 5 bits for subpriority */
#define HAL_NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bits for pre-emption priority 4 bits for subpriority */
#define HAL_NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority 3 bits for subpriority */
#define HAL_NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority 2 bits for subpriority */
#define HAL_NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority 1 bits for subpriority */
#define HAL_NVIC_PRIORITYGROUP_5         ((uint32_t)0x00000002) /*!< 5 bits for pre-emption priority 0 bits for subpriority */
/**
  * @brief  register interrupt handler and clear handler.
  * @param  e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @param  NVIC_Handler:         interrupt handler.
  * @param  NVIC_ClearHandler: clear handler.       
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_RegisterHandler(ENUM_HAL_NVIC_IRQ_NUM e_Irqn, HAL_NVIC_Irqhandler NVIC_Handler, HAL_NVIC_Irqhandler NVIC_ClearHandler);


/**
  * @brief  unregister interrupt handler and clear handler.
  * @param  e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration    
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_UNRegisterHandler(ENUM_HAL_NVIC_IRQ_NUM e_Irqn);

/**
  * @brief  Sets the priority grouping field (preemption priority and subpriority)
  *         using the required unlock sequence.
  * @param  PriorityGroup: The priority grouping bits length. 
  *         This parameter can be one of the following values:
  *         @arg HAL_NVIC_PRIORITYGROUP_0: 0 bits for preemption priority
  *                                    5 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_1: 1 bits for preemption priority
  *                                    4 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_2: 2 bits for preemption priority
  *                                    3 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_3: 3 bits for preemption priority
  *                                    2 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_4: 4 bits for preemption priority
  *                                    1 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_5: 5 bits for preemption priority
  *                                    0 bits for subpriority
  * @retval HAL_OK            function is well done.
  * @note   When the HAL_NVIC_PRIORITYGROUP_0 is selected, IRQ preemption is no more possible. 
  *         The pending IRQ priority will be managed only by the subpriority. 
  */
HAL_RET_T HAL_NVIC_SetPriorityGrouping(uint32_t u32_priorityGroup);
/**
  * @brief  Sets the priority of an interrupt.
  * @param  e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @param  PreemptPriority: The preemption priority for the e_Irqn channel.
  * @param  SubPriority: the subpriority level for the IRQ channel.       
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_SetPriority(ENUM_HAL_NVIC_IRQ_NUM e_Irqn, uint32_t u32_preemptPriority, uint32_t u32_subPriority);
/**
  * @brief  Enables a device specific interrupt in the NVIC interrupt controller. 
  * @param  e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @retval HAL_OK            function is well done.
  * @note   To configure interrupts priority correctly, the HAL_NVIC_PRIORITYGROUPConfig()
  *         function should be called before.
  */
HAL_RET_T HAL_NVIC_EnableIrq(ENUM_HAL_NVIC_IRQ_NUM e_Irqn);
/**
  * @brief  Disables a device specific interrupt in the NVIC interrupt controller.
  * @param  e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_DisableIrq(ENUM_HAL_NVIC_IRQ_NUM e_Irqn);
/**
  * @brief  Gets the priority grouping field from the NVIC Interrupt Controller.
  * @param  p_retPriorityGroup: Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field)
  * @retval HAL_OK             function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_GetPriorityGrouping(uint32_t *p_retPriorityGroup);
/**
  * @brief  Gets the priority of an interrupt.
  * @param  e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @param  PriorityGroup: the priority grouping bits length.
  *         This parameter can be one of the following values:
  *         @arg HAL_NVIC_PRIORITYGROUP_0: 0 bits for preemption priority
  *                                    5 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_1: 1 bits for preemption priority
  *                                    4 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_2: 2 bits for preemption priority
  *                                    3 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_3: 3 bits for preemption priority
  *                                    2 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_4: 4 bits for preemption priority
  *                                    1 bits for subpriority
  *         @arg HAL_NVIC_PRIORITYGROUP_5: 5 bits for preemption priority
  *                                    0 bits for subpriority
  * @param  pPreemptPriority: Pointer on the Preemptive priority value (starting from 0).
  * @param  pSubPriority: Pointer on the Subpriority value (starting from 0).
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_GetPriority(ENUM_HAL_NVIC_IRQ_NUM e_Irqn, uint32_t PriorityGroup, uint32_t *p_preemptPriority, uint32_t *p_subPriority);
/**
  * @brief  Sets Pending bit of an external interrupt.
  * @param  e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_SetPendingIrq(ENUM_HAL_NVIC_IRQ_NUM e_Irqn);
/**
  * @brief  Gets Pending Interrupt (reads the pending register in the NVIC 
  *         and returns the pending bit for the specified interrupt).
  * @param  e_Irqn： External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @param  p_retPending  Pointer on the get pending.
  *               status  - 0  Interrupt status is not pending.
  *                       - 1  Interrupt status is pending.
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_GetPendingIrq(ENUM_HAL_NVIC_IRQ_NUM e_Irqn,uint32_t *p_retPending);
/**
  * @brief  Clears the pending bit of an external interrupt.
  * @param  e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_ClearPendingIrq(ENUM_HAL_NVIC_IRQ_NUM e_Irqn);
/**
  * @brief Gets active interrupt ( reads the active register in NVIC and returns the active bit).
  * @param e_Irqn: External interrupt number.This parameter can be an enumerator of ENUM_HAL_NVIC_IRQ_NUM enumeration
  * @param  p_retActive: Pointer on the get active pending.
  *                      status   - 0  Interrupt status is not pending.
  *                               - 1  Interrupt status is pending.
  * @retval HAL_OK            function is well done.
  * @note   None
  */
HAL_RET_T HAL_NVIC_GetActive(ENUM_HAL_NVIC_IRQ_NUM e_Irqn, uint32_t *p_retActive);

#ifdef __cplusplus
}
#endif

#endif 

