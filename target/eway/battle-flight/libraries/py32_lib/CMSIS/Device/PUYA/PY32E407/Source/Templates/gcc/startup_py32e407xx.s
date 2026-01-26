/**
    ****************************************************************************
    Copyright (c) 2025, Felix Liao. All rights reserved.

    All rights reserved.
    ****************************************************************************

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the disclaimer below.

    Felix Liao's name may not be used to endorse or promote products derived from
    this software without specific prior written permission.

    DISCLAIMER: THIS SOFTWARE IS PROVIDED BY FELIX LIAO "AS IS" AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
    DISCLAIMED. IN NO EVENT SHALL FELIX LIAO BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
    EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    ****************************************************************************
 **/

    .syntax unified
    .cpu cortex-m4
    .fpu softvfp
    .thumb

.global  g_pfnVectors
.global  Default_Handler

/* start address for the initialization values of the .data section. 
defined in linker script */
.word  _sidata
/* start address for the .data section. defined in linker script */  
.word  _sdata
/* end address for the .data section. defined in linker script */
.word  _edata
/* start address for the .bss section. defined in linker script */
.word  _sbss
/* end address for the .bss section. defined in linker script */
.word  _ebss
/* stack used for SystemInit_ExtMemCtl; always internal RAM used */

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called. 
 * @param  None
 * @retval : None
*/

        .section  .text.Reset_Handler
    .weak  Reset_Handler
    .type  Reset_Handler, %function
Reset_Handler:  

/* Copy the data segment initializers from flash to SRAM */  
    movs  r1, #0
    b  LoopCopyDataInit

CopyDataInit:
    ldr  r3, =_sidata
    ldr  r3, [r3, r1]
    str  r3, [r0, r1]
    adds  r1, r1, #4
        
LoopCopyDataInit:
    ldr  r0, =_sdata
    ldr  r3, =_edata
    adds  r2, r0, r1
    cmp  r2, r3
    bcc  CopyDataInit
    ldr  r2, =_sbss
    b  LoopFillZerobss
/* Zero fill the bss segment. */  
FillZerobss:
    movs  r3, #0
    str  r3, [r2], #4
        
LoopFillZerobss:
    ldr  r3, = _ebss
    cmp  r2, r3
    bcc  FillZerobss

/* Call the clock system intitialization function.*/
    bl  SystemInit   
/* Call static constructors */
        bl __libc_init_array
/* Call the application's entry point.*/
    bl  main
    bx  lr    
.size  Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an 
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 * @param  None     
 * @retval None       
*/
        .section  .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
    b  Infinite_Loop
    .size  Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex M3. Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
* 
*******************************************************************************/
    .section  .isr_vector,"a",%progbits    
        
g_pfnVectors:
    .word  _estack                       //Top of Stack
    .word  Reset_Handler                 //Reset Handler
    .word  NMI_Handler                   //NMI Handler
    .word  HardFault_Handler             //Hard Fault Handler
    .word  MemManage_Handler             //Memory Manage Handler
    .word  BusFault_Handler              //Bus Fault Handler
    .word  UsageFault_Handler            //Usage Fault Handler
    .word  0                             //Reserved
    .word  0                             //Reserved
    .word  0                             //Reserved
    .word  0                             //Reserved
    .word  SVC_Handler                   //SVCall Handler
    .word  DebugMon_Handler              //Debug Monitor Handler
    .word  0                             //Reserved
    .word  PendSV_Handler                //PendSV Handler
    .word  SysTick_Handler               //SysTick Handler

    //External Interrupts
    .word  WWDG_IRQHandler               //Window Watchdog
    .word  PVD_IRQHandler                //PVD through EXTI Line detect
    .word  TAMPER_IRQHandler             //Tamper
    .word  RTC_IRQHandler                //RTC
    .word  FLASH_IRQHandler              //Flash
    .word  RCC_CTC_IRQHandler            //RCC & CTC
    .word  EXTI0_IRQHandler              //EXTI Line 0
    .word  EXTI1_IRQHandler              //EXTI Line 1
    .word  EXTI2_IRQHandler              //EXTI Line 2
    .word  EXTI3_IRQHandler              //EXTI Line 3
    .word  EXTI4_IRQHandler              //EXTI Line 4
    .word  DMA1_Channel1_IRQHandler      //DMA1 Channel 1
    .word  DMA1_Channel2_IRQHandler      //DMA1 Channel 2
    .word  DMA1_Channel3_IRQHandler      //DMA1 Channel 3
    .word  DMA1_Channel4_IRQHandler      //DMA1 Channel 4
    .word  DMA1_Channel5_IRQHandler      //DMA1 Channel 5
    .word  DMA1_Channel6_IRQHandler      //DMA1 Channel 6
    .word  DMA2_Channel6_IRQHandler      //DMA2 Channel 6
    .word  ADC1_2_IRQHandler             //ADC1 & ADC2
    .word  OTG1_FS_WKUP_IRQHandler       //USB OTG FS Wakeup through EXTI line
    .word  CAN1_INT0_IRQHandler          //CAN1 INT0
    .word  OTG1_FS_IRQHandler            //USB OTG FS
    .word  TIM18_IRQHandler              //TIM18
    .word  EXTI9_5_IRQHandler            //EXTI Line 9..5
    .word  TIM1_BRK_TIM9_IRQHandler      //TIM1 Break and TIM9
    .word  TIM1_UP_TIM10_IRQHandler      //TIM1 Update and TIM10
    .word  TIM1_TRG_COM_TIM11_IRQHandler //TIM1 Trigger and Commutation and TIM11
    .word  TIM1_CC_IRQHandler            //TIM1 Capture Compare
    .word  TIM2_IRQHandler               //TIM2
    .word  TIM3_IRQHandler               //TIM3
    .word  TIM4_IRQHandler               //TIM4
    .word  I2C1_EV_IRQHandler            //I2C1 Event
    .word  I2C1_ER_IRQHandler            //I2C1 Error
    .word  I2C2_EV_IRQHandler            //I2C2 Event
    .word  I2C2_ER_IRQHandler            //I2C2 Error
    .word  SPI1_IRQHandler               //SPI1
    .word  SPI2_IRQHandler               //SPI2
    .word  USART1_IRQHandler             //USART1
    .word  USART2_IRQHandler             //USART2
    .word  USART3_IRQHandler             //USART3
    .word  EXTI15_10_IRQHandler          //EXTI Line 15..10
    .word  RTC_Alarm_IRQHandler          //RTC Alarm through EXTI Line
    .word  TIM19_IRQHandler              //TIM19
    .word  TIM8_BRK_TIM12_IRQHandler     //TIM8 Break and TIM12
    .word  TIM8_UP_TIM13_IRQHandler      //TIM8 Update and TIM13
    .word  TIM8_TRG_COM_TIM14_IRQHandler //TIM8 Trigger and Commutation and TIM14
    .word  TIM8_CC_IRQHandler            //TIM8 Capture Compare
    .word  ADC3_IRQHandler               //ADC3
    .word  ESMC_IRQHandler               //ESMC
    .word  SDIO_IRQHandler               //SDIO
    .word  TIM5_IRQHandler               //TIM5
    .word  SPI3_IRQHandler               //SPI3
    .word  UART1_IRQHandler              //UART1
    .word  LPUART_IRQHandler             //LPUART
    .word  TIM6_IRQHandler               //TIM6
    .word  TIM7_IRQHandler               //TIM7
    .word  DMA2_Channel1_IRQHandler      //DMA2 Channel1
    .word  DMA2_Channel2_IRQHandler      //DMA2 Channel2
    .word  DMA2_Channel3_IRQHandler      //DMA2 Channel3
    .word  DMA2_Channel4_5_IRQHandler    //DMA2 Channel4 & Channel5
    .word  TIM15_IRQHandler              //TIM15
    .word  TIM16_IRQHandler              //TIM16
    .word  TIM17_IRQHandler              //TIM17
    .word  I2C3_EV_IRQHandler            //I2C3 Event
    .word  I2C3_ER_IRQHandler            //I2C3 Error
    .word  I2C4_EV_IRQHandler            //I2C4 Event
    .word  I2C4_ER_IRQHandler            //I2C4 Error
    .word  ETH_IRQHandler                //ETH
    .word  ETH_WKUP_IRQHandler           //ETH WKUP
    .word  RNG_IRQHandler                //RNG
    .word  AES_IRQHandler                //AES
    .word  CORDIC_IRQHandler             //CORDIC
    .word  DAC_IRQHandler                //DAC
    .word  COMP1_IRQHandler              //COMP1
    .word  COMP2_IRQHandler              //COMP2
    .word  COMP3_IRQHandler              //COMP3
    .word  COMP4_IRQHandler              //COMP4
    .word  UART2_IRQHandler              //UART2
    .word  UART3_IRQHandler              //UART3
    .word  0                             //Reserved
    .word  LPTIM_IRQHandler              //LPTIM
    .word  OTG2_FS_WKUP_IRQHandler       //USB OTG2 FS Wakeup through EXTI line interrupt
    .word  OTG2_FS_IRQHandler            //USB OTG2 FS global Interrup
    .word  CAN1_INT1_IRQHandler          //CAN1 INT1
    .word  CAN2_INT0_IRQHandler          //CAN2 INT0
    .word  CAN2_INT1_IRQHandler          //CAN2 INT1

    .type  g_pfnVectors, %object
    .size  g_pfnVectors, .-g_pfnVectors
                        
/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler. 
* As they are weak aliases, any function with the same name will override 
* this definition.
* 
*******************************************************************************/
    .weak      NMI_Handler
    .thumb_set NMI_Handler,Default_Handler

    .weak      HardFault_Handler
    .thumb_set HardFault_Handler,Default_Handler

    .weak      MemManage_Handler
    .thumb_set MemManage_Handler,Default_Handler

    .weak      BusFault_Handler
    .thumb_set BusFault_Handler,Default_Handler

    .weak      UsageFault_Handler
    .thumb_set UsageFault_Handler,Default_Handler

    .weak      SVC_Handler
    .thumb_set SVC_Handler,Default_Handler

    .weak      DebugMon_Handler
    .thumb_set DebugMon_Handler,Default_Handler

    .weak      PendSV_Handler
    .thumb_set PendSV_Handler,Default_Handler

    .weak      SysTick_Handler
    .thumb_set SysTick_Handler,Default_Handler

    .weak      WWDG_IRQHandler
    .thumb_set WWDG_IRQHandler,Default_Handler

    .weak      PVD_IRQHandler
    .thumb_set PVD_IRQHandler,Default_Handler

    .weak      TAMPER_IRQHandler
    .thumb_set TAMPER_IRQHandler,Default_Handler

    .weak      RTC_IRQHandler
    .thumb_set RTC_IRQHandler,Default_Handler

    .weak      FLASH_IRQHandler
    .thumb_set FLASH_IRQHandler,Default_Handler

    .weak      RCC_CTC_IRQHandler
    .thumb_set RCC_CTC_IRQHandler,Default_Handler

    .weak      EXTI0_IRQHandler
    .thumb_set EXTI0_IRQHandler,Default_Handler

    .weak      EXTI1_IRQHandler
    .thumb_set EXTI1_IRQHandler,Default_Handler

    .weak      EXTI2_IRQHandler
    .thumb_set EXTI2_IRQHandler,Default_Handler

    .weak      EXTI3_IRQHandler
    .thumb_set EXTI3_IRQHandler,Default_Handler

    .weak      EXTI4_IRQHandler
    .thumb_set EXTI4_IRQHandler,Default_Handler

    .weak      DMA1_Channel1_IRQHandler
    .thumb_set DMA1_Channel1_IRQHandler,Default_Handler

    .weak      DMA1_Channel2_IRQHandler
    .thumb_set DMA1_Channel2_IRQHandler,Default_Handler

    .weak      DMA1_Channel3_IRQHandler
    .thumb_set DMA1_Channel3_IRQHandler,Default_Handler

    .weak      DMA1_Channel4_IRQHandler
    .thumb_set DMA1_Channel4_IRQHandler,Default_Handler

    .weak      DMA1_Channel5_IRQHandler
    .thumb_set DMA1_Channel5_IRQHandler,Default_Handler

    .weak      DMA1_Channel6_IRQHandler
    .thumb_set DMA1_Channel6_IRQHandler,Default_Handler

    .weak      DMA2_Channel6_IRQHandler
    .thumb_set DMA2_Channel6_IRQHandler,Default_Handler

    .weak      ADC1_2_IRQHandler
    .thumb_set ADC1_2_IRQHandler,Default_Handler

    .weak      OTG1_FS_WKUP_IRQHandler
    .thumb_set OTG1_FS_WKUP_IRQHandler,Default_Handler

    .weak      CAN1_INT0_IRQHandler
    .thumb_set CAN1_INT0_IRQHandler,Default_Handler

    .weak      OTG1_FS_IRQHandler
    .thumb_set OTG1_FS_IRQHandler,Default_Handler

    .weak      TIM18_IRQHandler
    .thumb_set TIM18_IRQHandler,Default_Handler

    .weak      EXTI9_5_IRQHandler
    .thumb_set EXTI9_5_IRQHandler,Default_Handler

    .weak      TIM1_BRK_TIM9_IRQHandler
    .thumb_set TIM1_BRK_TIM9_IRQHandler,Default_Handler

    .weak      TIM1_UP_TIM10_IRQHandler
    .thumb_set TIM1_UP_TIM10_IRQHandler,Default_Handler

    .weak      TIM1_TRG_COM_TIM11_IRQHandler
    .thumb_set TIM1_TRG_COM_TIM11_IRQHandler,Default_Handler

    .weak      TIM1_CC_IRQHandler
    .thumb_set TIM1_CC_IRQHandler,Default_Handler

    .weak      TIM2_IRQHandler
    .thumb_set TIM2_IRQHandler,Default_Handler

    .weak      TIM3_IRQHandler
    .thumb_set TIM3_IRQHandler,Default_Handler

    .weak      TIM4_IRQHandler
    .thumb_set TIM4_IRQHandler,Default_Handler

    .weak      I2C1_EV_IRQHandler
    .thumb_set I2C1_EV_IRQHandler,Default_Handler

    .weak      I2C1_ER_IRQHandler
    .thumb_set I2C1_ER_IRQHandler,Default_Handler

    .weak      I2C2_EV_IRQHandler
    .thumb_set I2C2_EV_IRQHandler,Default_Handler

    .weak      I2C2_ER_IRQHandler
    .thumb_set I2C2_ER_IRQHandler,Default_Handler

    .weak      SPI1_IRQHandler
    .thumb_set SPI1_IRQHandler,Default_Handler

    .weak      SPI2_IRQHandler
    .thumb_set SPI2_IRQHandler,Default_Handler

    .weak      USART1_IRQHandler
    .thumb_set USART1_IRQHandler,Default_Handler

    .weak      USART2_IRQHandler
    .thumb_set USART2_IRQHandler,Default_Handler

    .weak      USART3_IRQHandler
    .thumb_set USART3_IRQHandler,Default_Handler

    .weak      EXTI15_10_IRQHandler
    .thumb_set EXTI15_10_IRQHandler,Default_Handler

    .weak      RTC_Alarm_IRQHandler
    .thumb_set RTC_Alarm_IRQHandler,Default_Handler

    .weak      TIM19_IRQHandler
    .thumb_set TIM19_IRQHandler,Default_Handler

    .weak      TIM8_BRK_TIM12_IRQHandler
    .thumb_set TIM8_BRK_TIM12_IRQHandler,Default_Handler

    .weak      TIM8_UP_TIM13_IRQHandler
    .thumb_set TIM8_UP_TIM13_IRQHandler,Default_Handler

    .weak      TIM8_TRG_COM_TIM14_IRQHandler
    .thumb_set TIM8_TRG_COM_TIM14_IRQHandler,Default_Handler

    .weak      TIM8_CC_IRQHandler
    .thumb_set TIM8_CC_IRQHandler,Default_Handler

    .weak      ADC3_IRQHandler
    .thumb_set ADC3_IRQHandler,Default_Handler

    .weak      ESMC_IRQHandler
    .thumb_set ESMC_IRQHandler,Default_Handler

    .weak      SDIO_IRQHandler
    .thumb_set SDIO_IRQHandler,Default_Handler

    .weak      TIM5_IRQHandler
    .thumb_set TIM5_IRQHandler,Default_Handler

    .weak      SPI3_IRQHandler
    .thumb_set SPI3_IRQHandler,Default_Handler

    .weak      UART1_IRQHandler
    .thumb_set UART1_IRQHandler,Default_Handler

    .weak      LPUART_IRQHandler
    .thumb_set LPUART_IRQHandler,Default_Handler

    .weak      TIM6_IRQHandler
    .thumb_set TIM6_IRQHandler,Default_Handler

    .weak      TIM7_IRQHandler
    .thumb_set TIM7_IRQHandler,Default_Handler

    .weak      DMA2_Channel1_IRQHandler
    .thumb_set DMA2_Channel1_IRQHandler,Default_Handler

    .weak      DMA2_Channel2_IRQHandler
    .thumb_set DMA2_Channel2_IRQHandler,Default_Handler

    .weak      DMA2_Channel3_IRQHandler
    .thumb_set DMA2_Channel3_IRQHandler,Default_Handler

    .weak      DMA2_Channel4_5_IRQHandler
    .thumb_set DMA2_Channel4_5_IRQHandler,Default_Handler

    .weak      TIM15_IRQHandler
    .thumb_set TIM15_IRQHandler,Default_Handler

    .weak      TIM16_IRQHandler
    .thumb_set TIM16_IRQHandler,Default_Handler

    .weak      TIM17_IRQHandler
    .thumb_set TIM17_IRQHandler,Default_Handler

    .weak      I2C3_EV_IRQHandler
    .thumb_set I2C3_EV_IRQHandler,Default_Handler

    .weak      I2C3_ER_IRQHandler
    .thumb_set I2C3_ER_IRQHandler,Default_Handler

    .weak      I2C4_EV_IRQHandler
    .thumb_set I2C4_EV_IRQHandler,Default_Handler

    .weak      I2C4_ER_IRQHandler
    .thumb_set I2C4_ER_IRQHandler,Default_Handler

    .weak      ETH_IRQHandler
    .thumb_set ETH_IRQHandler,Default_Handler

    .weak      ETH_WKUP_IRQHandler
    .thumb_set ETH_WKUP_IRQHandler,Default_Handler

    .weak      RNG_IRQHandler
    .thumb_set RNG_IRQHandler,Default_Handler

    .weak      AES_IRQHandler
    .thumb_set AES_IRQHandler,Default_Handler

    .weak      CORDIC_IRQHandler
    .thumb_set CORDIC_IRQHandler,Default_Handler

    .weak      DAC_IRQHandler
    .thumb_set DAC_IRQHandler,Default_Handler

    .weak      COMP1_IRQHandler
    .thumb_set COMP1_IRQHandler,Default_Handler

    .weak      COMP2_IRQHandler
    .thumb_set COMP2_IRQHandler,Default_Handler

    .weak      COMP3_IRQHandler
    .thumb_set COMP3_IRQHandler,Default_Handler

    .weak      COMP4_IRQHandler
    .thumb_set COMP4_IRQHandler,Default_Handler

    .weak      UART2_IRQHandler
    .thumb_set UART2_IRQHandler,Default_Handler

    .weak      UART3_IRQHandler
    .thumb_set UART3_IRQHandler,Default_Handler

    .weak      LPTIM_IRQHandler
    .thumb_set LPTIM_IRQHandler,Default_Handler

    .weak      OTG2_FS_WKUP_IRQHandler
    .thumb_set OTG2_FS_WKUP_IRQHandler,Default_Handler

    .weak      OTG2_FS_IRQHandler
    .thumb_set OTG2_FS_IRQHandler,Default_Handler

    .weak      CAN1_INT1_IRQHandler
    .thumb_set CAN1_INT1_IRQHandler,Default_Handler

    .weak      CAN2_INT0_IRQHandler
    .thumb_set CAN2_INT0_IRQHandler,Default_Handler

    .weak      CAN2_INT1_IRQHandler
    .thumb_set CAN2_INT1_IRQHandler,Default_Handler
