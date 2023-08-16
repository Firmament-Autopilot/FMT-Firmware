/**
  ******************************************************************************
  * @file      start.s
  * @author    Min Zhao
  * @Version    V1.1.0
  * @Date       14-September-2016
  ******************************************************************************
  */
@ #include "debuglog.h"
@ #include "interrupt.h"
@ #include "inter_core.h"

@ .equ  ITCM0,   0x00000000
@ .equ  DTCM0,   0x20000000

.equ  Local_CPUID, 0x0

.syntax unified
.cpu cortex-m7
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
  ldr   sp, =_estack      /* set stack pointer */

/* Copy the data segment initializers from flash to SRAM */  
  ldr r0, =_sdata
  ldr r1, =_edata
  ldr r2, =_sidata
  movs r3, #0
  b LoopCopyDataInit
  
CopyDataInit:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4

LoopCopyDataInit:
  adds r4, r0, r3
  cmp r4, r1
  bcc CopyDataInit

/* Zero fill the bss segment. */
  ldr r2, =_sbss
  ldr r4, =_ebss
  movs r3, #0
  b LoopFillZerobss

FillZerobss:
  str  r3, [r2]
  adds r2, r2, #4

LoopFillZerobss:
  cmp r2, r4
  bcc FillZerobss

/* Call the clock system initialization function.*/
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
* The minimal vector table for a Cortex M7. Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
* 
*******************************************************************************/
   .section  .isr_vector,"a",%progbits
  .type  g_pfnVectors, %object
  .size  g_pfnVectors, .-g_pfnVectors

   
g_pfnVectors:
  .word     _estack
  .word     Reset_Handler

  .word     NMI_Handler
  .word     hardfault_isr
  .word     default_isr
  .word     default_isr
  .word     default_isr
  .word     default_isr
  .word     default_isr
  .word     default_isr
  .word     default_isr
  .word     SVC_Handler
  .word     default_isr
  .word     default_isr
  .word     PendSV_Handler
  .word     SysTick_Handler

    /* External Interrupts */
  .word     UART0_IRQHandler
  .word     UART1_IRQHandler
  .word     UART2_IRQHandler
  .word     UART3_IRQHandler
  .word     UART4_IRQHandler
  .word     UART5_IRQHandler
  .word     UART6_IRQHandler
  .word     UART7_IRQHandler
  .word     UART8_IRQHandler
  .word     IRQHandler_25
  .word     IRQHandler_26
  .word     IRQHandler_27
  .word     IRQHandler_28
  .word     IRQHandler_29
  .word     IRQHandler_30
  .word     IRQHandler_31
  .word     IRQHandler_32
  .word     IRQHandler_33
  .word     IRQHandler_34
  .word     IRQHandler_35
  .word     IRQHandler_36
  .word     IRQHandler_37
  .word     IRQHandler_38
  .word     IRQHandler_39
  .word     IRQHandler_40
  .word     IRQHandler_41
  .word     IRQHandler_42
  .word     IRQHandler_43
  .word     IRQHandler_44
  .word     IRQHandler_45
  .word     IRQHandler_46
  .word     IRQHandler_47
  .word     IRQHandler_48
  .word     IRQHandler_49
  .word     IRQHandler_50
  .word     IRQHandler_51
  .word     IRQHandler_52
  .word     IRQHandler_53
  .word     IRQHandler_54
  .word     IRQHandler_55
  .word     IRQHandler_56
  .word     IRQHandler_57
  .word     IRQHandler_58
  .word     IRQHandler_59
  .word     IRQHandler_60
  .word     IRQHandler_61
  .word     IRQHandler_62
  .word     IRQHandler_63
  .word     IRQHandler_64
  .word     IRQHandler_65
  .word     IRQHandler_66
  .word     IRQHandler_67
  .word     IRQHandler_68
  .word     IRQHandler_69
  .word     IRQHandler_70
  .word     IRQHandler_71
  .word     IRQHandler_72
  .word     IRQHandler_73
  .word     IRQHandler_74
  .word     IRQHandler_75
  .word     IRQHandler_76
  .word     IRQHandler_77
  .word     IRQHandler_78
  .word     IRQHandler_79
  .word     IRQHandler_80
  .word     IRQHandler_81
  .word     IRQHandler_82
  .word     IRQHandler_83
  .word     IRQHandler_84
  .word     IRQHandler_85
  .word     InterCore_DebugIRQ1Handler
  .word     IRQHandler_87
  .word     IRQHandler_88
  .word     IRQHandler_89
  .word     IRQHandler_90
  .word     IRQHandler_91
  .word     IRQHandler_92
  .word     IRQHandler_93
  .word     IRQHandler_94
  .word     IRQHandler_95
  .word     IRQHandler_96
  .word     IRQHandler_97
  .word     IRQHandler_98
  .word     Local_CPUID
  
/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler. 
* As they are weak aliases, any function with the same name will override 
* this definition.
* 
*******************************************************************************/
.weak      NMI_Handler
.thumb_set NMI_Handler,Default_Handler

; .weak      hardfault_isr
; .thumb_set hardfault_isr,Default_Handler


.weak      default_isr
.thumb_set default_isr,Default_Handler

.weak      hardfault_isr
.thumb_set hardfault_isr,Default_Handler

 .weak      SVC_Handler
 .thumb_set SVC_Handler,Default_Handler

// .weak      PendSV_Handler
// .thumb_set PendSV_Handler,Default_Handler

// .weak      SysTick_Handler
// .thumb_set SysTick_Handler,Default_Handler


.weak      UART2_IRQHandler
.thumb_set UART2_IRQHandler,IRQHandler_18

.weak      UART3_IRQHandler
.thumb_set UART3_IRQHandler,IRQHandler_19

.weak      UART8_IRQHandler
.thumb_set UART8_IRQHandler,IRQHandler_24