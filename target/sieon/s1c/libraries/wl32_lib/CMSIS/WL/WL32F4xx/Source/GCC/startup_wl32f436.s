;/*****************************************************************************
; * Copyright (C) 2022, wlhc Semiconductor Co., Ltd. All rights reserved.
; *
; * This software component is licensed by WLHC under BSD 3-Clause license
; * (the "License"); You may not use this file except in compliance with the
; * License. You may obtain a copy of the License at:
; *                    opensource.org/licenses/BSD-3-Clause
; *
; */
/*****************************************************************************/
/*  Startup for GCC                                                          */
/*  Version     V1.0                                                         */
/*  Date        2022-03-31                                                   */
/*  Target-mcu  WL32F436                                                     */
/*****************************************************************************/

/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
*/

.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global  g_pfnVectors
.global  Default_Handler

    .section  .isr_vector,"a",%progbits
    .type  g_pfnVectors, %object

/*
;<h> Interrupt vector table start.
*/
                .section    .isr_vector, "a", %progbits
                .align      2
                .type       __Vectors, %object
                .globl      __Vectors
g_pfnVectors:
    .word     _estack                       // Top of Stack
    .word     Reset_Handler                     // Reset Handler
    .word     NMI_Handler                       // NMI Handler
    .word     HardFault_Handler                 // Hard Fault Handler
    .word     MemManage_Handler                 // MPU Fault Handler
    .word     BusFault_Handler                  // Bus Fault Handler
    .word     UsageFault_Handler                // Usage Fault Handler
    .word     0                                 // Reserved
    .word     0                                 // Reserved
    .word     0                                 // Reserved
    .word     0                                 // Reserved
    .word     SVC_Handler                       // SVCall Handler
    .word     DebugMon_Handler                  // Debug Monitor Handler
    .word     0                                 // Reserved
    .word     PendSV_Handler                    // PendSV Handler
    .word     SysTick_Handler                   // SysTick Handler

                /* Interrupts */
    .word   IRQ000_Handler
    .word   IRQ001_Handler
    .word   IRQ002_Handler
    .word   IRQ003_Handler
    .word   IRQ004_Handler
    .word   IRQ005_Handler
    .word   IRQ006_Handler
    .word   IRQ007_Handler
    .word   IRQ008_Handler
    .word   IRQ009_Handler
    .word   IRQ010_Handler
    .word   IRQ011_Handler
    .word   IRQ012_Handler
    .word   IRQ013_Handler
    .word   IRQ014_Handler
    .word   IRQ015_Handler
    .word   IRQ016_Handler
    .word   IRQ017_Handler
    .word   IRQ018_Handler
    .word   IRQ019_Handler
    .word   IRQ020_Handler
    .word   IRQ021_Handler
    .word   IRQ022_Handler
    .word   IRQ023_Handler
    .word   IRQ024_Handler
    .word   IRQ025_Handler
    .word   IRQ026_Handler
    .word   IRQ027_Handler
    .word   IRQ028_Handler
    .word   IRQ029_Handler
    .word   IRQ030_Handler
    .word   IRQ031_Handler
    .word   IRQ032_Handler
    .word   IRQ033_Handler
    .word   IRQ034_Handler
    .word   IRQ035_Handler
    .word   IRQ036_Handler
    .word   IRQ037_Handler
    .word   IRQ038_Handler
    .word   IRQ039_Handler
    .word   IRQ040_Handler
    .word   IRQ041_Handler
    .word   IRQ042_Handler
    .word   IRQ043_Handler
    .word   IRQ044_Handler
    .word   IRQ045_Handler
    .word   IRQ046_Handler
    .word   IRQ047_Handler
    .word   IRQ048_Handler
    .word   IRQ049_Handler
    .word   IRQ050_Handler
    .word   IRQ051_Handler
    .word   IRQ052_Handler
    .word   IRQ053_Handler
    .word   IRQ054_Handler
    .word   IRQ055_Handler
    .word   IRQ056_Handler
    .word   IRQ057_Handler
    .word   IRQ058_Handler
    .word   IRQ059_Handler
    .word   IRQ060_Handler
    .word   IRQ061_Handler
    .word   IRQ062_Handler
    .word   IRQ063_Handler
    .word   IRQ064_Handler
    .word   IRQ065_Handler
    .word   IRQ066_Handler
    .word   IRQ067_Handler
    .word   IRQ068_Handler
    .word   IRQ069_Handler
    .word   IRQ070_Handler
    .word   IRQ071_Handler
    .word   IRQ072_Handler
    .word   IRQ073_Handler
    .word   IRQ074_Handler
    .word   IRQ075_Handler
    .word   IRQ076_Handler
    .word   IRQ077_Handler
    .word   IRQ078_Handler
    .word   IRQ079_Handler
    .word   IRQ080_Handler
    .word   IRQ081_Handler
    .word   IRQ082_Handler
    .word   IRQ083_Handler
    .word   IRQ084_Handler
    .word   IRQ085_Handler
    .word   IRQ086_Handler
    .word   IRQ087_Handler
    .word   IRQ088_Handler
    .word   IRQ089_Handler
    .word   IRQ090_Handler
    .word   IRQ091_Handler
    .word   IRQ092_Handler
    .word   IRQ093_Handler
    .word   IRQ094_Handler
    .word   IRQ095_Handler
    .word   IRQ096_Handler
    .word   IRQ097_Handler
    .word   IRQ098_Handler
    .word   IRQ099_Handler
    .word   IRQ100_Handler
    .word   IRQ101_Handler
    .word   IRQ102_Handler
    .word   IRQ103_Handler
    .word   IRQ104_Handler
    .word   IRQ105_Handler
    .word   IRQ106_Handler
    .word   IRQ107_Handler
    .word   IRQ108_Handler
    .word   IRQ109_Handler
    .word   IRQ110_Handler
    .word   IRQ111_Handler
    .word   IRQ112_Handler
    .word   IRQ113_Handler
    .word   IRQ114_Handler
    .word   IRQ115_Handler
    .word   IRQ116_Handler
    .word   IRQ117_Handler
    .word   IRQ118_Handler
    .word   IRQ119_Handler
    .word   IRQ120_Handler
    .word   IRQ121_Handler
    .word   IRQ122_Handler
    .word   IRQ123_Handler
    .word   IRQ124_Handler
    .word   IRQ125_Handler
    .word   IRQ126_Handler
    .word   IRQ127_Handler
    .word   IRQ128_Handler
    .word   IRQ129_Handler
    .word   IRQ130_Handler
    .word   IRQ131_Handler
    .word   IRQ132_Handler
    .word   IRQ133_Handler
    .word   IRQ134_Handler
    .word   IRQ135_Handler
    .word   IRQ136_Handler
    .word   IRQ137_Handler
    .word   IRQ138_Handler
    .word   IRQ139_Handler
    .word   IRQ140_Handler
    .word   IRQ141_Handler
    .word   IRQ142_Handler
    .word   IRQ143_Handler

    .size  g_pfnVectors, .-g_pfnVectors

    .section  .text.Reset_Handler
    .weak  Reset_Handler
    .type  Reset_Handler, %function
Reset_Handler:
    ldr r1, =_sidata
    ldr r2, =_sdata
    ldr r3, =_edata

    subs r3, r2
    ble fill_bss_start

loop_copy_data:
    subs r3, #4
    ldr r0, [r1,r3]
    str r0, [r2,r3]
    bgt loop_copy_data

fill_bss_start:
    ldr r1, =__bss_start
    ldr r2, =__bss_end
    movs r0, 0
    subs r2, r1
    ble startup_enter

loop_fill_bss:
    subs r2, #4
    str r0, [r1, r2]
    bgt loop_fill_bss

startup_enter:
    bl SystemInit
    b pass
    .word 0xFFFFFFFF
    pass:
    bl main

    /* Exception Handlers */
    .weak   NMI_Handler
    .type   NMI_Handler, %function
NMI_Handler:
    b       .
    .size   NMI_Handler, . - NMI_Handler

    .weak   MemManage_Handler
    .type   MemManage_Handler, %function
MemManage_Handler:
    b       .
    .size   MemManage_Handler, . - MemManage_Handler

    .weak   BusFault_Handler
    .type   BusFault_Handler, %function
BusFault_Handler:
    b       .
    .size   BusFault_Handler, . - BusFault_Handler

    .weak   UsageFault_Handler
    .type   UsageFault_Handler, %function
UsageFault_Handler:
    b       .
    .size   UsageFault_Handler, . - UsageFault_Handler

    .weak   SVC_Handler
    .type   SVC_Handler, %function
SVC_Handler:
    b       .
    .size   SVC_Handler, . - SVC_Handler

    .weak   DebugMon_Handler
    .type   DebugMon_Handler, %function
DebugMon_Handler:
    b       .
    .size   DebugMon_Handler, . - DebugMon_Handler

    .weak   PendSV_Handler
    .type   PendSV_Handler, %function
PendSV_Handler:
    b       .
    .size   PendSV_Handler, . - PendSV_Handler

    .weak   SysTick_Handler
    .type   SysTick_Handler, %function
SysTick_Handler:
    b       .
    .size   SysTick_Handler, . - SysTick_Handler

    /* IQR Handler */
    .section  .text.Default_Handler,"ax",%progbits
    .type  Default_Handler, %function
Default_Handler:
    b  .
    .size  Default_Handler, . - Default_Handler

    .macro  IRQ handler
    .weak   \handler
    .set    \handler, Default_Handler
    .endm

    IRQ     IRQ000_Handler
    IRQ     IRQ001_Handler
    IRQ     IRQ002_Handler
    IRQ     IRQ003_Handler
    IRQ     IRQ004_Handler
    IRQ     IRQ005_Handler
    IRQ     IRQ006_Handler
    IRQ     IRQ007_Handler
    IRQ     IRQ008_Handler
    IRQ     IRQ009_Handler
    IRQ     IRQ010_Handler
    IRQ     IRQ011_Handler
    IRQ     IRQ012_Handler
    IRQ     IRQ013_Handler
    IRQ     IRQ014_Handler
    IRQ     IRQ015_Handler
    IRQ     IRQ016_Handler
    IRQ     IRQ017_Handler
    IRQ     IRQ018_Handler
    IRQ     IRQ019_Handler
    IRQ     IRQ020_Handler
    IRQ     IRQ021_Handler
    IRQ     IRQ022_Handler
    IRQ     IRQ023_Handler
    IRQ     IRQ024_Handler
    IRQ     IRQ025_Handler
    IRQ     IRQ026_Handler
    IRQ     IRQ027_Handler
    IRQ     IRQ028_Handler
    IRQ     IRQ029_Handler
    IRQ     IRQ030_Handler
    IRQ     IRQ031_Handler
    IRQ     IRQ032_Handler
    IRQ     IRQ033_Handler
    IRQ     IRQ034_Handler
    IRQ     IRQ035_Handler
    IRQ     IRQ036_Handler
    IRQ     IRQ037_Handler
    IRQ     IRQ038_Handler
    IRQ     IRQ039_Handler
    IRQ     IRQ040_Handler
    IRQ     IRQ041_Handler
    IRQ     IRQ042_Handler
    IRQ     IRQ043_Handler
    IRQ     IRQ044_Handler
    IRQ     IRQ045_Handler
    IRQ     IRQ046_Handler
    IRQ     IRQ047_Handler
    IRQ     IRQ048_Handler
    IRQ     IRQ049_Handler
    IRQ     IRQ050_Handler
    IRQ     IRQ051_Handler
    IRQ     IRQ052_Handler
    IRQ     IRQ053_Handler
    IRQ     IRQ054_Handler
    IRQ     IRQ055_Handler
    IRQ     IRQ056_Handler
    IRQ     IRQ057_Handler
    IRQ     IRQ058_Handler
    IRQ     IRQ059_Handler
    IRQ     IRQ060_Handler
    IRQ     IRQ061_Handler
    IRQ     IRQ062_Handler
    IRQ     IRQ063_Handler
    IRQ     IRQ064_Handler
    IRQ     IRQ065_Handler
    IRQ     IRQ066_Handler
    IRQ     IRQ067_Handler
    IRQ     IRQ068_Handler
    IRQ     IRQ069_Handler
    IRQ     IRQ070_Handler
    IRQ     IRQ071_Handler
    IRQ     IRQ072_Handler
    IRQ     IRQ073_Handler
    IRQ     IRQ074_Handler
    IRQ     IRQ075_Handler
    IRQ     IRQ076_Handler
    IRQ     IRQ077_Handler
    IRQ     IRQ078_Handler
    IRQ     IRQ079_Handler
    IRQ     IRQ080_Handler
    IRQ     IRQ081_Handler
    IRQ     IRQ082_Handler
    IRQ     IRQ083_Handler
    IRQ     IRQ084_Handler
    IRQ     IRQ085_Handler
    IRQ     IRQ086_Handler
    IRQ     IRQ087_Handler
    IRQ     IRQ088_Handler
    IRQ     IRQ089_Handler
    IRQ     IRQ090_Handler
    IRQ     IRQ091_Handler
    IRQ     IRQ092_Handler
    IRQ     IRQ093_Handler
    IRQ     IRQ094_Handler
    IRQ     IRQ095_Handler
    IRQ     IRQ096_Handler
    IRQ     IRQ097_Handler
    IRQ     IRQ098_Handler
    IRQ     IRQ099_Handler
    IRQ     IRQ100_Handler
    IRQ     IRQ101_Handler
    IRQ     IRQ102_Handler
    IRQ     IRQ103_Handler
    IRQ     IRQ104_Handler
    IRQ     IRQ105_Handler
    IRQ     IRQ106_Handler
    IRQ     IRQ107_Handler
    IRQ     IRQ108_Handler
    IRQ     IRQ109_Handler
    IRQ     IRQ110_Handler
    IRQ     IRQ111_Handler
    IRQ     IRQ112_Handler
    IRQ     IRQ113_Handler
    IRQ     IRQ114_Handler
    IRQ     IRQ115_Handler
    IRQ     IRQ116_Handler
    IRQ     IRQ117_Handler
    IRQ     IRQ118_Handler
    IRQ     IRQ119_Handler
    IRQ     IRQ120_Handler
    IRQ     IRQ121_Handler
    IRQ     IRQ122_Handler
    IRQ     IRQ123_Handler
    IRQ     IRQ124_Handler
    IRQ     IRQ125_Handler
    IRQ     IRQ126_Handler
    IRQ     IRQ127_Handler
    IRQ     IRQ128_Handler
    IRQ     IRQ129_Handler
    IRQ     IRQ130_Handler
    IRQ     IRQ131_Handler
    IRQ     IRQ132_Handler
    IRQ     IRQ133_Handler
    IRQ     IRQ134_Handler
    IRQ     IRQ135_Handler
    IRQ     IRQ136_Handler
    IRQ     IRQ137_Handler
    IRQ     IRQ138_Handler
    IRQ     IRQ139_Handler
    IRQ     IRQ140_Handler
    IRQ     IRQ141_Handler
    IRQ     IRQ142_Handler
    IRQ     IRQ143_Handler