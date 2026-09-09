/***************************************************************************//**
* PSE846GPS2DBZC4A device header with secure MMIO offsets
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef _PSE846GPS2DBZC4A_S_H_
#define _PSE846GPS2DBZC4A_S_H_

/**
* \addtogroup group_device PSE846GPS2DBZC4A
* \{
*/

/**
* \addtogroup Configuration_of_CMSIS
* \{
*/

/*******************************************************************************
*                         Interrupt Number Definition
*******************************************************************************/

typedef enum {
#if defined(COMPONENT_CM0P)
  /* ARM Cortex-M0+ Core Interrupt Numbers */
  Reset_IRQn                        = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn               = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn                    = -13,      /*!< -13 Hard Fault, all classes of Fault */
  SVCall_IRQn                       =  -5,      /*!<  -5 System Service Call via SVC instruction */
  PendSV_IRQn                       =  -2,      /*!<  -2 Pendable request for system service */
  SysTick_IRQn                      =  -1,      /*!<  -1 System Tick Timer */
  /* CM0PLUS Peripheral Interrupt Numbers */
  m33syscpuss_interrupts_ipc_dpslp_0_IRQn =   1, /*!<   1 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #0 */
  m33syscpuss_interrupts_ipc_dpslp_1_IRQn =   2, /*!<   2 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #1 */
  m33syscpuss_interrupts_ipc_dpslp_2_IRQn =   3, /*!<   3 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #2 */
  m33syscpuss_interrupts_ipc_dpslp_3_IRQn =   4, /*!<   4 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #3 */
  m33syscpuss_interrupts_ipc_dpslp_4_IRQn =   5, /*!<   5 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #4 */
  m33syscpuss_interrupts_ipc_dpslp_5_IRQn =   6, /*!<   6 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #5 */
  m33syscpuss_interrupts_ipc_dpslp_6_IRQn =   7, /*!<   7 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #6 */
  m33syscpuss_interrupts_ipc_dpslp_7_IRQn =   8, /*!<   8 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #7 */
  unconnected_IRQn                  =1023       /*!< 1023 Unconnected */
#elif defined(COMPONENT_CM33)
  /* ARM Cortex-M33 Core Interrupt Numbers */
  Reset_IRQn                        = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn               = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn                    = -13,      /*!< -13 Hard Fault, all classes of Fault */
  MemoryManagement_IRQn             = -12,      /*!< -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn                     = -11,      /*!< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn                   = -10,      /*!< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SecureFault_IRQn                  =  -9,      /*!<  -9 Secure Fault Interrupt */
  SVCall_IRQn                       =  -5,      /*!<  -5 System Service Call via SVC instruction */
  DebugMonitor_IRQn                 =  -4,      /*!<  -4 Debug Monitor */
  PendSV_IRQn                       =  -2,      /*!<  -2 Pendable request for system service */
  SysTick_IRQn                      =  -1,      /*!<  -1 System Tick Timer */
  /* CM33 Peripheral Interrupt Numbers */
  ioss_interrupts_gpio_0_IRQn       =   0,      /*!<   0 [DeepSleep] GPIO Port Interrupt #0 */
  ioss_interrupts_gpio_2_IRQn       =   1,      /*!<   1 [DeepSleep] GPIO Port Interrupt #2 */
  ioss_interrupts_gpio_3_IRQn       =   2,      /*!<   2 [DeepSleep] GPIO Port Interrupt #3 */
  ioss_interrupts_gpio_5_IRQn       =   3,      /*!<   3 [DeepSleep] GPIO Port Interrupt #5 */
  ioss_interrupts_gpio_6_IRQn       =   4,      /*!<   4 [DeepSleep] GPIO Port Interrupt #6 */
  ioss_interrupts_gpio_7_IRQn       =   5,      /*!<   5 [DeepSleep] GPIO Port Interrupt #7 */
  ioss_interrupts_gpio_8_IRQn       =   6,      /*!<   6 [DeepSleep] GPIO Port Interrupt #8 */
  ioss_interrupts_gpio_9_IRQn       =   7,      /*!<   7 [DeepSleep] GPIO Port Interrupt #9 */
  ioss_interrupts_gpio_10_IRQn      =   8,      /*!<   8 [DeepSleep] GPIO Port Interrupt #10 */
  ioss_interrupts_gpio_11_IRQn      =   9,      /*!<   9 [DeepSleep] GPIO Port Interrupt #11 */
  ioss_interrupts_gpio_12_IRQn      =  10,      /*!<  10 [DeepSleep] GPIO Port Interrupt #12 */
  ioss_interrupts_gpio_13_IRQn      =  11,      /*!<  11 [DeepSleep] GPIO Port Interrupt #13 */
  ioss_interrupts_gpio_14_IRQn      =  12,      /*!<  12 [DeepSleep] GPIO Port Interrupt #14 */
  ioss_interrupts_gpio_15_IRQn      =  13,      /*!<  13 [DeepSleep] GPIO Port Interrupt #15 */
  ioss_interrupts_gpio_16_IRQn      =  14,      /*!<  14 [DeepSleep] GPIO Port Interrupt #16 */
  ioss_interrupts_gpio_17_IRQn      =  15,      /*!<  15 [DeepSleep] GPIO Port Interrupt #17 */
  ioss_interrupts_gpio_18_IRQn      =  16,      /*!<  16 [DeepSleep] GPIO Port Interrupt #18 */
  ioss_interrupts_gpio_19_IRQn      =  17,      /*!<  17 [DeepSleep] GPIO Port Interrupt #19 */
  ioss_interrupts_gpio_20_IRQn      =  18,      /*!<  18 [DeepSleep] GPIO Port Interrupt #20 */
  ioss_interrupts_gpio_21_IRQn      =  19,      /*!<  19 [DeepSleep] GPIO Port Interrupt #21 */
  ioss_interrupts_sec_gpio_0_IRQn   =  20,      /*!<  20 [DeepSleep] GPIO Port Secure Interrupt #0 */
  ioss_interrupts_sec_gpio_2_IRQn   =  21,      /*!<  21 [DeepSleep] GPIO Port Secure Interrupt #2 */
  ioss_interrupts_sec_gpio_3_IRQn   =  22,      /*!<  22 [DeepSleep] GPIO Port Secure Interrupt #3 */
  ioss_interrupts_sec_gpio_5_IRQn   =  23,      /*!<  23 [DeepSleep] GPIO Port Secure Interrupt #5 */
  ioss_interrupts_sec_gpio_6_IRQn   =  24,      /*!<  24 [DeepSleep] GPIO Port Secure Interrupt #6 */
  ioss_interrupts_sec_gpio_7_IRQn   =  25,      /*!<  25 [DeepSleep] GPIO Port Secure Interrupt #7 */
  ioss_interrupts_sec_gpio_8_IRQn   =  26,      /*!<  26 [DeepSleep] GPIO Port Secure Interrupt #8 */
  ioss_interrupts_sec_gpio_9_IRQn   =  27,      /*!<  27 [DeepSleep] GPIO Port Secure Interrupt #9 */
  ioss_interrupts_sec_gpio_10_IRQn  =  28,      /*!<  28 [DeepSleep] GPIO Port Secure Interrupt #10 */
  ioss_interrupts_sec_gpio_11_IRQn  =  29,      /*!<  29 [DeepSleep] GPIO Port Secure Interrupt #11 */
  ioss_interrupts_sec_gpio_12_IRQn  =  30,      /*!<  30 [DeepSleep] GPIO Port Secure Interrupt #12 */
  ioss_interrupts_sec_gpio_13_IRQn  =  31,      /*!<  31 [DeepSleep] GPIO Port Secure Interrupt #13 */
  ioss_interrupts_sec_gpio_14_IRQn  =  32,      /*!<  32 [DeepSleep] GPIO Port Secure Interrupt #14 */
  ioss_interrupts_sec_gpio_15_IRQn  =  33,      /*!<  33 [DeepSleep] GPIO Port Secure Interrupt #15 */
  ioss_interrupts_sec_gpio_16_IRQn  =  34,      /*!<  34 [DeepSleep] GPIO Port Secure Interrupt #16 */
  ioss_interrupts_sec_gpio_17_IRQn  =  35,      /*!<  35 [DeepSleep] GPIO Port Secure Interrupt #17 */
  ioss_interrupts_sec_gpio_18_IRQn  =  36,      /*!<  36 [DeepSleep] GPIO Port Secure Interrupt #18 */
  ioss_interrupts_sec_gpio_19_IRQn  =  37,      /*!<  37 [DeepSleep] GPIO Port Secure Interrupt #19 */
  ioss_interrupts_sec_gpio_20_IRQn  =  38,      /*!<  38 [DeepSleep] GPIO Port Secure Interrupt #20 */
  ioss_interrupts_sec_gpio_21_IRQn  =  39,      /*!<  39 [DeepSleep] GPIO Port Secure Interrupt #21 */
  ioss_interrupt_vdd_IRQn           =  40,      /*!<  40 [DeepSleep] GPIO Supply Detect Interrupt */
  ioss_interrupt_gpio_IRQn          =  41,      /*!<  41 [DeepSleep] GPIO All Ports */
  ioss_interrupt_sec_gpio_IRQn      =  42,      /*!<  42 [DeepSleep] GPIO All Ports - Secured version */
  scb_0_interrupt_IRQn              =  43,      /*!<  43 [DeepSleep] Serial Communication Block #0 (DeepSleep capable) */
  srss_interrupt_IRQn               =  44,      /*!<  44 [DeepSleep] Other combined Interrupts for srss (LVD, CLKCAL) */
  lpcomp_interrupt_IRQn             =  45,      /*!<  45 [DeepSleep] LPCOMP */
  m55appcpuss_interrupts_ipc_dpslp_0_IRQn =  46, /*!<  46 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #0 */
  m55appcpuss_interrupts_ipc_dpslp_1_IRQn =  47, /*!<  47 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #1 */
  m55appcpuss_interrupts_ipc_dpslp_2_IRQn =  48, /*!<  48 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #2 */
  m55appcpuss_interrupts_ipc_dpslp_3_IRQn =  49, /*!<  49 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #3 */
  m55appcpuss_interrupts_ipc_dpslp_4_IRQn =  50, /*!<  50 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #4 */
  m55appcpuss_interrupts_ipc_dpslp_5_IRQn =  51, /*!<  51 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #5 */
  m55appcpuss_interrupts_ipc_dpslp_6_IRQn =  52, /*!<  52 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #6 */
  m55appcpuss_interrupts_ipc_dpslp_7_IRQn =  53, /*!<  53 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #7 */
  srss_interrupt_wdt_IRQn           =  54,      /*!<  54 [DeepSleep] Interrupt for WDT */
  srss_interrupt_mcwdt_0_IRQn       =  55,      /*!<  55 [DeepSleep] Interrupt for MCWDT[] */
  srss_interrupt_rtc_IRQn           =  56,      /*!<  56 [DeepSleep] Interrupt for RTC */
  pass_interrupt_lppass_IRQn        =  57,      /*!<  57 [DeepSleep] LPPASS interrupt */
  pass_interrupt_fifo_IRQn          =  58,      /*!<  58 [DeepSleep] LPPASS FIFO interrupt */
  ioss_interrupts_gpio_1_IRQn       =  59,      /*!<  59 [Active] GPIO Port Interrupt #1 (SMIF0) */
  ioss_interrupts_gpio_4_IRQn       =  60,      /*!<  60 [Active] GPIO Port Interrupt #4 (SMIF1) */
  srss_interrupt_main_ppu_IRQn      =  63,      /*!<  63 [Active] Interrupt from Main PPU */
  srss_interrupt_srss_pd1_ppu_IRQn  =  64,      /*!<  64 [Active] Interrupt from PD1 PPU */
  m33syscpuss_interrupt_ppu_sramc0_IRQn =  65,  /*!<  65 [Active] PPU SRAM0 */
  m33syscpuss_interrupt_ppu_sramc1_IRQn =  66,  /*!<  66 [Active] PPU SRAM1 */
  m33syscpuss_interrupt_ppu_cpuss_IRQn =  67,   /*!<  67 [Active] cpuss[0] PPU Interrupt */
  mxu55_interrupt_ppu_IRQn          =  68,      /*!<  68 [Active] Interrupt requests of mxu55.PPU */
  socmem_interrupt_ppu_IRQn         =  69,      /*!<  69 [Active] Interrupt requests of socmem.PPU */
  m33syscpuss_interrupts_ipc_dpslp_0_IRQn =  70, /*!<  70 [Active] m33syscpuss Inter Process Communication Interrupt #0 */
  m33syscpuss_interrupts_ipc_dpslp_1_IRQn =  71, /*!<  71 [Active] m33syscpuss Inter Process Communication Interrupt #1 */
  m33syscpuss_interrupts_ipc_dpslp_2_IRQn =  72, /*!<  72 [Active] m33syscpuss Inter Process Communication Interrupt #2 */
  m33syscpuss_interrupts_ipc_dpslp_3_IRQn =  73, /*!<  73 [Active] m33syscpuss Inter Process Communication Interrupt #3 */
  m33syscpuss_interrupts_ipc_dpslp_4_IRQn =  74, /*!<  74 [Active] m33syscpuss Inter Process Communication Interrupt #4 */
  m33syscpuss_interrupts_ipc_dpslp_5_IRQn =  75, /*!<  75 [Active] m33syscpuss Inter Process Communication Interrupt #5 */
  m33syscpuss_interrupts_ipc_dpslp_6_IRQn =  76, /*!<  76 [Active] m33syscpuss Inter Process Communication Interrupt #6 */
  m33syscpuss_interrupts_ipc_dpslp_7_IRQn =  77, /*!<  77 [Active] m33syscpuss Inter Process Communication Interrupt #7 */
  mxnnlite_interrupt_mxnnlite_IRQn  =  78,      /*!<  78 [Active] Interrupt of MXNNLITE */
  m33syscpuss_interrupts_cm33_0_cti_0_IRQn =  79, /*!<  79 [Active]  */
  m33syscpuss_interrupts_cm33_0_cti_1_IRQn =  80, /*!<  80 [Active]  */
  m33syscpuss_interrupt_cm33_0_fp_IRQn =  81,   /*!<  81 [Active] CM33 0 Floating Point Interrupt */
  m33syscpuss_interrupts_dw0_0_IRQn =  82,      /*!<  82 [Active] cpuss[0] DataWire #0, Channel #0 */
  m33syscpuss_interrupts_dw0_1_IRQn =  83,      /*!<  83 [Active] cpuss[0] DataWire #0, Channel #1 */
  m33syscpuss_interrupts_dw0_2_IRQn =  84,      /*!<  84 [Active] cpuss[0] DataWire #0, Channel #2 */
  m33syscpuss_interrupts_dw0_3_IRQn =  85,      /*!<  85 [Active] cpuss[0] DataWire #0, Channel #3 */
  m33syscpuss_interrupts_dw0_4_IRQn =  86,      /*!<  86 [Active] cpuss[0] DataWire #0, Channel #4 */
  m33syscpuss_interrupts_dw0_5_IRQn =  87,      /*!<  87 [Active] cpuss[0] DataWire #0, Channel #5 */
  m33syscpuss_interrupts_dw0_6_IRQn =  88,      /*!<  88 [Active] cpuss[0] DataWire #0, Channel #6 */
  m33syscpuss_interrupts_dw0_7_IRQn =  89,      /*!<  89 [Active] cpuss[0] DataWire #0, Channel #7 */
  m33syscpuss_interrupts_dw0_8_IRQn =  90,      /*!<  90 [Active] cpuss[0] DataWire #0, Channel #8 */
  m33syscpuss_interrupts_dw0_9_IRQn =  91,      /*!<  91 [Active] cpuss[0] DataWire #0, Channel #9 */
  m33syscpuss_interrupts_dw0_10_IRQn =  92,     /*!<  92 [Active] cpuss[0] DataWire #0, Channel #10 */
  m33syscpuss_interrupts_dw0_11_IRQn =  93,     /*!<  93 [Active] cpuss[0] DataWire #0, Channel #11 */
  m33syscpuss_interrupts_dw0_12_IRQn =  94,     /*!<  94 [Active] cpuss[0] DataWire #0, Channel #12 */
  m33syscpuss_interrupts_dw0_13_IRQn =  95,     /*!<  95 [Active] cpuss[0] DataWire #0, Channel #13 */
  m33syscpuss_interrupts_dw0_14_IRQn =  96,     /*!<  96 [Active] cpuss[0] DataWire #0, Channel #14 */
  m33syscpuss_interrupts_dw0_15_IRQn =  97,     /*!<  97 [Active] cpuss[0] DataWire #0, Channel #15 */
  m55appcpuss_interrupts_axidmac_0_IRQn =  98,  /*!<  98 [Active]  */
  m55appcpuss_interrupts_axidmac_1_IRQn =  99,  /*!<  99 [Active]  */
  m55appcpuss_interrupts_axidmac_2_IRQn = 100,  /*!< 100 [Active]  */
  m55appcpuss_interrupts_axidmac_3_IRQn = 101,  /*!< 101 [Active]  */
  smif_0_smif0_interrupt_nsec_IRQn  = 102,      /*!< 102 [Active] SMIF0 Port0 non-secure interrupt */
  smif_0_smif0_interrupt_sec_IRQn   = 103,      /*!< 103 [Active] SMIF0 Port0 secure interrupt */
  smif_1_smif0_interrupt_nsec_IRQn  = 104,      /*!< 104 [Active] SMIF1 Port0 non-secure interrupt */
  smif_1_smif0_interrupt_sec_IRQn   = 105,      /*!< 105 [Active] SMIF1 Port0 secure interrupt */
  canfd_0_interrupts0_0_IRQn        = 106,      /*!< 106 [Active] CAN #0, Interrupt0, Channel#0 */
  canfd_0_interrupts1_0_IRQn        = 107,      /*!< 107 [Active] CAN #0, Interrupt1, Channel#0 */
  canfd_0_interrupts0_1_IRQn        = 108,      /*!< 108 [Active] CAN #0, Interrupt0, Channel#1 */
  canfd_0_interrupts1_1_IRQn        = 109,      /*!< 109 [Active] CAN #0, Interrupt1, Channel#1 */
  tcpwm_0_interrupts_0_IRQn         = 110,      /*!< 110 [Active] TCPWM, 32-bit Counter #0 */
  tcpwm_0_interrupts_1_IRQn         = 111,      /*!< 111 [Active] TCPWM, 32-bit Counter #1 */
  tcpwm_0_interrupts_2_IRQn         = 112,      /*!< 112 [Active] TCPWM, 32-bit Counter #2 */
  tcpwm_0_interrupts_3_IRQn         = 113,      /*!< 113 [Active] TCPWM, 32-bit Counter #3 */
  tcpwm_0_interrupts_4_IRQn         = 114,      /*!< 114 [Active] TCPWM, 32-bit Counter #4 */
  tcpwm_0_interrupts_5_IRQn         = 115,      /*!< 115 [Active] TCPWM, 32-bit Counter #5 */
  tcpwm_0_interrupts_6_IRQn         = 116,      /*!< 116 [Active] TCPWM, 32-bit Counter #6 */
  tcpwm_0_interrupts_7_IRQn         = 117,      /*!< 117 [Active] TCPWM, 32-bit Counter #7 */
  tcpwm_0_interrupts_256_IRQn       = 118,      /*!< 118 [Active] TCPWM, 16-bit Counter #0 */
  tcpwm_0_interrupts_257_IRQn       = 119,      /*!< 119 [Active] TCPWM, 16-bit Counter #1 */
  tcpwm_0_interrupts_258_IRQn       = 120,      /*!< 120 [Active] TCPWM, 16-bit Counter #2 */
  tcpwm_0_interrupts_259_IRQn       = 121,      /*!< 121 [Active] TCPWM, 16-bit Counter #3 */
  tcpwm_0_interrupts_260_IRQn       = 122,      /*!< 122 [Active] TCPWM, 16-bit Counter #4 */
  tcpwm_0_interrupts_261_IRQn       = 123,      /*!< 123 [Active] TCPWM, 16-bit Counter #5 */
  tcpwm_0_interrupts_262_IRQn       = 124,      /*!< 124 [Active] TCPWM, 16-bit Counter #6 */
  tcpwm_0_interrupts_263_IRQn       = 125,      /*!< 125 [Active] TCPWM, 16-bit Counter #7 */
  tcpwm_0_interrupts_264_IRQn       = 126,      /*!< 126 [Active] TCPWM, 16-bit Counter #8 */
  tcpwm_0_interrupts_265_IRQn       = 127,      /*!< 127 [Active] TCPWM, 16-bit Counter #9 */
  tcpwm_0_interrupts_266_IRQn       = 128,      /*!< 128 [Active] TCPWM, 16-bit Counter #10 */
  tcpwm_0_interrupts_267_IRQn       = 129,      /*!< 129 [Active] TCPWM, 16-bit Counter #11 */
  tcpwm_0_interrupts_268_IRQn       = 130,      /*!< 130 [Active] TCPWM, 16-bit Counter #12 */
  tcpwm_0_interrupts_269_IRQn       = 131,      /*!< 131 [Active] TCPWM, 16-bit Counter #13 */
  tcpwm_0_interrupts_270_IRQn       = 132,      /*!< 132 [Active] TCPWM, 16-bit Counter #14 */
  tcpwm_0_interrupts_271_IRQn       = 133,      /*!< 133 [Active] TCPWM, 16-bit Counter #15 */
  tcpwm_0_interrupts_272_IRQn       = 134,      /*!< 134 [Active] TCPWM, 16-bit Counter #16 */
  tcpwm_0_interrupts_273_IRQn       = 135,      /*!< 135 [Active] TCPWM, 16-bit Counter #17 */
  tcpwm_0_interrupts_274_IRQn       = 136,      /*!< 136 [Active] TCPWM, 16-bit Counter #18 */
  tcpwm_0_interrupts_275_IRQn       = 137,      /*!< 137 [Active] TCPWM, 16-bit Counter #19 */
  tcpwm_0_interrupts_276_IRQn       = 138,      /*!< 138 [Active] TCPWM, 16-bit Counter #20 */
  tcpwm_0_interrupts_277_IRQn       = 139,      /*!< 139 [Active] TCPWM, 16-bit Counter #21 */
  tcpwm_0_interrupts_278_IRQn       = 140,      /*!< 140 [Active] TCPWM, 16-bit Counter #22 */
  tcpwm_0_interrupts_279_IRQn       = 141,      /*!< 141 [Active] TCPWM, 16-bit Counter #23 */
  scb_1_interrupt_IRQn              = 142,      /*!< 142 [Active] SCB#1 Interrupt */
  scb_2_interrupt_IRQn              = 143,      /*!< 143 [Active] SCB#2 Interrupt */
  scb_3_interrupt_IRQn              = 144,      /*!< 144 [Active] SCB#3 Interrupt */
  scb_4_interrupt_IRQn              = 145,      /*!< 145 [Active] SCB#4 Interrupt */
  scb_5_interrupt_IRQn              = 146,      /*!< 146 [Active] SCB#5 Interrupt */
  scb_6_interrupt_IRQn              = 147,      /*!< 147 [Active] SCB#6 Interrupt */
  scb_7_interrupt_IRQn              = 148,      /*!< 148 [Active] SCB#7 Interrupt */
  scb_8_interrupt_IRQn              = 149,      /*!< 149 [Active] SCB#8 Interrupt */
  scb_9_interrupt_IRQn              = 150,      /*!< 150 [Active] SCB#9 Interrupt */
  scb_10_interrupt_IRQn             = 151,      /*!< 151 [Active] SCB#10 Interrupt */
  scb_11_interrupt_IRQn             = 152,      /*!< 152 [Active] SCB#11 Interrupt */
  mxu55_interrupt_npu_IRQn          = 153,      /*!< 153 [Active] Interrupt requests of armu55 (NPU) */
  sdhc_0_interrupt_general_IRQn     = 154,      /*!< 154 [Active] SDHC0 */
  sdhc_0_interrupt_wakeup_IRQn      = 155,      /*!< 155 [Active] SDHC0 */
  sdhc_1_interrupt_general_IRQn     = 156,      /*!< 156 [Active] SDHC1 */
  sdhc_1_interrupt_wakeup_IRQn      = 157,      /*!< 157 [Active] SDHC1 */
  tdm_0_interrupts_rx_0_IRQn        = 158,      /*!< 158 [Active] TDM0 Audio interrupt RX Structure#0 */
  tdm_0_interrupts_tx_0_IRQn        = 159,      /*!< 159 [Active] TDM0 Audio interrupt TX Structure#0 */
  tdm_0_interrupts_rx_1_IRQn        = 160,      /*!< 160 [Active] TDM0 Audio interrupt RX Structure#1 */
  tdm_0_interrupts_tx_1_IRQn        = 161,      /*!< 161 [Active] TDM0 Audio interrupt TX Structure#1 */
  gfxss_interrupt_gpu_IRQn          = 162,      /*!< 162 [Active] Interrupt from GPU. */
  gfxss_interrupt_dc_IRQn           = 163,      /*!< 163 [Active] Interrupt from DC. */
  gfxss_interrupt_mipidsi_IRQn      = 164,      /*!< 164 [Active] Interrupt from MIPIDSI. */
  pdm_0_interrupts_0_IRQn           = 165,      /*!< 165 [Active] PDM interrupt Structure#0 */
  pdm_0_interrupts_1_IRQn           = 166,      /*!< 166 [Active] PDM interrupt Structure#1 */
  pdm_0_interrupts_2_IRQn           = 167,      /*!< 167 [Active] PDM interrupt Structure#2 */
  pdm_0_interrupts_3_IRQn           = 168,      /*!< 168 [Active] PDM interrupt Structure#3 */
  pdm_0_interrupts_4_IRQn           = 169,      /*!< 169 [Active] PDM interrupt Structure#4 */
  pdm_0_interrupts_5_IRQn           = 170,      /*!< 170 [Active] PDM interrupt Structure#5 */
  eth_interrupt_eth_0_IRQn          = 171,      /*!< 171 [Active] ETH Interrupt#0 */
  eth_interrupt_eth_1_IRQn          = 172,      /*!< 172 [Active] ETH Interrupt#1 */
  eth_interrupt_eth_2_IRQn          = 173,      /*!< 173 [Active] ETH Interrupt#2 */
  usbhs_interrupt_usbhsctrl_IRQn    = 174,      /*!< 174 [Active] Interrupt of Controller core */
  usbhs_interrupt_usbhsss_IRQn      = 175,      /*!< 175 [Active] Interrupt of Subsystem */
  i3c_interrupt_IRQn                = 176,      /*!< 176 [Active] I3C Interrupt */
  m33syscpuss_interrupt_msc_IRQn    = 177,      /*!< 177 [Active]  */
  crypto_interrupt_IRQn             = 178,      /*!< 178 [Active] Crypto Interrupt */
  m33syscpuss_interrupts_fault_0_IRQn = 179,    /*!< 179 [Active]  */
  m33syscpuss_interrupts_fault_1_IRQn = 180,    /*!< 180 [Active]  */
  m33syscpuss_interrupts_dw1_0_IRQn = 181,      /*!< 181 [Active] cpuss[0] DataWire #1, Channel #0 */
  m33syscpuss_interrupts_dw1_1_IRQn = 182,      /*!< 182 [Active] cpuss[0] DataWire #1, Channel #1 */
  m33syscpuss_interrupts_dw1_2_IRQn = 183,      /*!< 183 [Active] cpuss[0] DataWire #1, Channel #2 */
  m33syscpuss_interrupts_dw1_3_IRQn = 184,      /*!< 184 [Active] cpuss[0] DataWire #1, Channel #3 */
  m33syscpuss_interrupts_dw1_4_IRQn = 185,      /*!< 185 [Active] cpuss[0] DataWire #1, Channel #4 */
  m33syscpuss_interrupts_dw1_5_IRQn = 186,      /*!< 186 [Active] cpuss[0] DataWire #1, Channel #5 */
  m33syscpuss_interrupts_dw1_6_IRQn = 187,      /*!< 187 [Active] cpuss[0] DataWire #1, Channel #6 */
  m33syscpuss_interrupts_dw1_7_IRQn = 188,      /*!< 188 [Active] cpuss[0] DataWire #1, Channel #7 */
  m33syscpuss_interrupts_dw1_8_IRQn = 189,      /*!< 189 [Active] cpuss[0] DataWire #1, Channel #8 */
  m33syscpuss_interrupts_dw1_9_IRQn = 190,      /*!< 190 [Active] cpuss[0] DataWire #1, Channel #9 */
  m33syscpuss_interrupts_dw1_10_IRQn = 191,     /*!< 191 [Active] cpuss[0] DataWire #1, Channel #10 */
  m33syscpuss_interrupts_dw1_11_IRQn = 192,     /*!< 192 [Active] cpuss[0] DataWire #1, Channel #11 */
  m33syscpuss_interrupts_dw1_12_IRQn = 193,     /*!< 193 [Active] cpuss[0] DataWire #1, Channel #12 */
  m33syscpuss_interrupts_dw1_13_IRQn = 194,     /*!< 194 [Active] cpuss[0] DataWire #1, Channel #13 */
  m33syscpuss_interrupts_dw1_14_IRQn = 195,     /*!< 195 [Active] cpuss[0] DataWire #1, Channel #14 */
  m33syscpuss_interrupts_dw1_15_IRQn = 196,     /*!< 196 [Active] cpuss[0] DataWire #1, Channel #15 */
  unconnected_IRQn                  =1023       /*!< 1023 Unconnected */
#elif defined(COMPONENT_CM55)
  /* ARM Cortex-M55 Core Interrupt Numbers */
  Reset_IRQn                        = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn               = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn                    = -13,      /*!< -13 Hard Fault, all classes of Fault */
  MemoryManagement_IRQn             = -12,      /*!< -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn                     = -11,      /*!< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn                   = -10,      /*!< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SecureFault_IRQn                  =  -9,      /*!<  -9 Secure Fault Interrupt */
  SVCall_IRQn                       =  -5,      /*!<  -5 System Service Call via SVC instruction */
  DebugMonitor_IRQn                 =  -4,      /*!<  -4 Debug Monitor */
  PendSV_IRQn                       =  -2,      /*!<  -2 Pendable request for system service */
  SysTick_IRQn                      =  -1,      /*!<  -1 System Tick Timer */
  /* CM55 Peripheral Interrupt Numbers */
  ioss_interrupts_gpio_0_IRQn       =   0,      /*!<   0 [DeepSleep] GPIO Port Interrupt #0 */
  ioss_interrupts_gpio_2_IRQn       =   1,      /*!<   1 [DeepSleep] GPIO Port Interrupt #2 */
  ioss_interrupts_gpio_3_IRQn       =   2,      /*!<   2 [DeepSleep] GPIO Port Interrupt #3 */
  ioss_interrupts_gpio_5_IRQn       =   3,      /*!<   3 [DeepSleep] GPIO Port Interrupt #5 */
  ioss_interrupts_gpio_6_IRQn       =   4,      /*!<   4 [DeepSleep] GPIO Port Interrupt #6 */
  ioss_interrupts_gpio_7_IRQn       =   5,      /*!<   5 [DeepSleep] GPIO Port Interrupt #7 */
  ioss_interrupts_gpio_8_IRQn       =   6,      /*!<   6 [DeepSleep] GPIO Port Interrupt #8 */
  ioss_interrupts_gpio_9_IRQn       =   7,      /*!<   7 [DeepSleep] GPIO Port Interrupt #9 */
  ioss_interrupts_gpio_10_IRQn      =   8,      /*!<   8 [DeepSleep] GPIO Port Interrupt #10 */
  ioss_interrupts_gpio_11_IRQn      =   9,      /*!<   9 [DeepSleep] GPIO Port Interrupt #11 */
  ioss_interrupts_gpio_12_IRQn      =  10,      /*!<  10 [DeepSleep] GPIO Port Interrupt #12 */
  ioss_interrupts_gpio_13_IRQn      =  11,      /*!<  11 [DeepSleep] GPIO Port Interrupt #13 */
  ioss_interrupts_gpio_14_IRQn      =  12,      /*!<  12 [DeepSleep] GPIO Port Interrupt #14 */
  ioss_interrupts_gpio_15_IRQn      =  13,      /*!<  13 [DeepSleep] GPIO Port Interrupt #15 */
  ioss_interrupts_gpio_16_IRQn      =  14,      /*!<  14 [DeepSleep] GPIO Port Interrupt #16 */
  ioss_interrupts_gpio_17_IRQn      =  15,      /*!<  15 [DeepSleep] GPIO Port Interrupt #17 */
  ioss_interrupts_gpio_18_IRQn      =  16,      /*!<  16 [DeepSleep] GPIO Port Interrupt #18 */
  ioss_interrupts_gpio_19_IRQn      =  17,      /*!<  17 [DeepSleep] GPIO Port Interrupt #19 */
  ioss_interrupts_gpio_20_IRQn      =  18,      /*!<  18 [DeepSleep] GPIO Port Interrupt #20 */
  ioss_interrupts_gpio_21_IRQn      =  19,      /*!<  19 [DeepSleep] GPIO Port Interrupt #21 */
  ioss_interrupt_vdd_IRQn           =  20,      /*!<  20 [DeepSleep] GPIO Supply Detect Interrupt */
  ioss_interrupt_gpio_IRQn          =  21,      /*!<  21 [DeepSleep] GPIO All Ports */
  scb_0_interrupt_IRQn              =  22,      /*!<  22 [DeepSleep] Serial Communication Block #0 (DeepSleep capable) */
  srss_interrupt_IRQn               =  23,      /*!<  23 [DeepSleep] Other combined Interrupts for srss (LVD, CLKCAL) */
  lpcomp_interrupt_IRQn             =  24,      /*!<  24 [DeepSleep] LPCOMP */
  m33syscpuss_interrupts_ipc_dpslp_0_IRQn =  25, /*!<  25 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #0 */
  m33syscpuss_interrupts_ipc_dpslp_1_IRQn =  26, /*!<  26 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #1 */
  m33syscpuss_interrupts_ipc_dpslp_2_IRQn =  27, /*!<  27 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #2 */
  m33syscpuss_interrupts_ipc_dpslp_3_IRQn =  28, /*!<  28 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #3 */
  m33syscpuss_interrupts_ipc_dpslp_4_IRQn =  29, /*!<  29 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #4 */
  m33syscpuss_interrupts_ipc_dpslp_5_IRQn =  30, /*!<  30 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #5 */
  m33syscpuss_interrupts_ipc_dpslp_6_IRQn =  31, /*!<  31 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #6 */
  m33syscpuss_interrupts_ipc_dpslp_7_IRQn =  32, /*!<  32 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #7 */
  srss_interrupt_wdt_IRQn           =  33,      /*!<  33 [DeepSleep] Interrupt for WDT */
  srss_interrupt_mcwdt_1_IRQn       =  34,      /*!<  34 [DeepSleep] Interrupt for MCWDT[] */
  srss_interrupt_rtc_IRQn           =  35,      /*!<  35 [DeepSleep] Interrupt from RTC */
  pass_interrupt_lppass_IRQn        =  36,      /*!<  36 [DeepSleep] LPPASS interrupt */
  pass_interrupt_fifo_IRQn          =  37,      /*!<  37 [DeepSleep] LPPASS FIFO interrupt */
  mxu55_interrupt_npu_IRQn          =  38,      /*!<  38 [DeepSleep] Interrupt requests of armu55 (NPU) */
  ioss_interrupts_gpio_1_IRQn       =  39,      /*!<  39 [Active] GPIO Port Interrupt #1 */
  ioss_interrupts_gpio_4_IRQn       =  40,      /*!<  40 [Active] GPIO Port Interrupt #4 */
  srss_interrupt_main_ppu_IRQn      =  41,      /*!<  41 [Active] Interrupt from Main PPU */
  srss_interrupt_srss_pd1_ppu_IRQn  =  42,      /*!<  42 [Active] Interrupt from PD1 PPU */
  m55appcpuss_interrupt_ppu_appcpuss_IRQn =  43, /*!<  43 [Active] PPU APPCPUSS */
  m55appcpuss_interrupt_ppu_cm55_0_IRQn =  44,  /*!<  44 [Active] PPU CM55 */
  mxu55_interrupt_ppu_IRQn          =  45,      /*!<  45 [Active] Interrupt requests of mxu55.PPU */
  socmem_interrupt_ppu_IRQn         =  46,      /*!<  46 [Active] Interrupt requests of socmem.PPU */
  m55appcpuss_interrupts_ipc_dpslp_0_IRQn =  47, /*!<  47 [Active] m55appcpuss Inter Process Communication Interrupt #0 */
  m55appcpuss_interrupts_ipc_dpslp_1_IRQn =  48, /*!<  48 [Active] m55appcpuss Inter Process Communication Interrupt #1 */
  m55appcpuss_interrupts_ipc_dpslp_2_IRQn =  49, /*!<  49 [Active] m55appcpuss Inter Process Communication Interrupt #2 */
  m55appcpuss_interrupts_ipc_dpslp_3_IRQn =  50, /*!<  50 [Active] m55appcpuss Inter Process Communication Interrupt #3 */
  m55appcpuss_interrupts_ipc_dpslp_4_IRQn =  51, /*!<  51 [Active] m55appcpuss Inter Process Communication Interrupt #4 */
  m55appcpuss_interrupts_ipc_dpslp_5_IRQn =  52, /*!<  52 [Active] m55appcpuss Inter Process Communication Interrupt #5 */
  m55appcpuss_interrupts_ipc_dpslp_6_IRQn =  53, /*!<  53 [Active] m55appcpuss Inter Process Communication Interrupt #6 */
  m55appcpuss_interrupts_ipc_dpslp_7_IRQn =  54, /*!<  54 [Active] m55appcpuss Inter Process Communication Interrupt #7 */
  mxnnlite_interrupt_mxnnlite_IRQn  =  55,      /*!<  55 [Active] Interrupt of MXNNLITE */
  m55appcpuss_interrupt_cm55_0_fp_IRQn =  56,   /*!<  56 [Active] CM33 0 Floating Point Interrupt */
  m55appcpuss_interrupts_cm55_0_cti_0_IRQn =  57, /*!<  57 [Active]  */
  m55appcpuss_interrupts_cm55_0_cti_1_IRQn =  58, /*!<  58 [Active]  */
  m55appcpuss_interrupt_msc_IRQn    =  59,      /*!<  59 [Active]  */
  m33syscpuss_interrupts_dw0_0_IRQn =  60,      /*!<  60 [Active] cpuss[0] DataWire #0, Channel #0 */
  m33syscpuss_interrupts_dw0_1_IRQn =  61,      /*!<  61 [Active] cpuss[0] DataWire #0, Channel #1 */
  m33syscpuss_interrupts_dw0_2_IRQn =  62,      /*!<  62 [Active] cpuss[0] DataWire #0, Channel #2 */
  m33syscpuss_interrupts_dw0_3_IRQn =  63,      /*!<  63 [Active] cpuss[0] DataWire #0, Channel #3 */
  m33syscpuss_interrupts_dw0_4_IRQn =  64,      /*!<  64 [Active] cpuss[0] DataWire #0, Channel #4 */
  m33syscpuss_interrupts_dw0_5_IRQn =  65,      /*!<  65 [Active] cpuss[0] DataWire #0, Channel #5 */
  m33syscpuss_interrupts_dw0_6_IRQn =  66,      /*!<  66 [Active] cpuss[0] DataWire #0, Channel #6 */
  m33syscpuss_interrupts_dw0_7_IRQn =  67,      /*!<  67 [Active] cpuss[0] DataWire #0, Channel #7 */
  m33syscpuss_interrupts_dw0_8_IRQn =  68,      /*!<  68 [Active] cpuss[0] DataWire #0, Channel #8 */
  m33syscpuss_interrupts_dw0_9_IRQn =  69,      /*!<  69 [Active] cpuss[0] DataWire #0, Channel #9 */
  m33syscpuss_interrupts_dw0_10_IRQn =  70,     /*!<  70 [Active] cpuss[0] DataWire #0, Channel #10 */
  m33syscpuss_interrupts_dw0_11_IRQn =  71,     /*!<  71 [Active] cpuss[0] DataWire #0, Channel #11 */
  m33syscpuss_interrupts_dw0_12_IRQn =  72,     /*!<  72 [Active] cpuss[0] DataWire #0, Channel #12 */
  m33syscpuss_interrupts_dw0_13_IRQn =  73,     /*!<  73 [Active] cpuss[0] DataWire #0, Channel #13 */
  m33syscpuss_interrupts_dw0_14_IRQn =  74,     /*!<  74 [Active] cpuss[0] DataWire #0, Channel #14 */
  m33syscpuss_interrupts_dw0_15_IRQn =  75,     /*!<  75 [Active] cpuss[0] DataWire #0, Channel #15 */
  m55appcpuss_interrupts_axidmac_0_IRQn =  76,  /*!<  76 [Active]  */
  m55appcpuss_interrupts_axidmac_1_IRQn =  77,  /*!<  77 [Active]  */
  m55appcpuss_interrupts_axidmac_2_IRQn =  78,  /*!<  78 [Active]  */
  m55appcpuss_interrupts_axidmac_3_IRQn =  79,  /*!<  79 [Active]  */
  smif_0_smif0_interrupt_nsec_IRQn  =  80,      /*!<  80 [Active] SMIF0 Port0 non-secure interrupt */
  smif_0_smif0_interrupt_sec_IRQn   =  81,      /*!<  81 [Active] SMIF0 Port0 secure interrupt */
  smif_1_smif0_interrupt_nsec_IRQn  =  82,      /*!<  82 [Active] SMIF1 Port0 non-secure interrupt */
  smif_1_smif0_interrupt_sec_IRQn   =  83,      /*!<  83 [Active] SMIF1 Port0 secure interrupt */
  canfd_0_interrupts0_0_IRQn        =  84,      /*!<  84 [Active] CAN #0, Interrupt0, Channel#0 */
  canfd_0_interrupts1_0_IRQn        =  85,      /*!<  85 [Active] CAN #0, Interrupt1, Channel#0 */
  canfd_0_interrupts0_1_IRQn        =  86,      /*!<  86 [Active] CAN #0, Interrupt0, Channel#1 */
  canfd_0_interrupts1_1_IRQn        =  87,      /*!<  87 [Active] CAN #0, Interrupt1, Channel#1 */
  tcpwm_0_interrupts_0_IRQn         =  88,      /*!<  88 [Active] TCPWM, 32-bit Counter #0 */
  tcpwm_0_interrupts_1_IRQn         =  89,      /*!<  89 [Active] TCPWM, 32-bit Counter #1 */
  tcpwm_0_interrupts_2_IRQn         =  90,      /*!<  90 [Active] TCPWM, 32-bit Counter #2 */
  tcpwm_0_interrupts_3_IRQn         =  91,      /*!<  91 [Active] TCPWM, 32-bit Counter #3 */
  tcpwm_0_interrupts_4_IRQn         =  92,      /*!<  92 [Active] TCPWM, 32-bit Counter #4 */
  tcpwm_0_interrupts_5_IRQn         =  93,      /*!<  93 [Active] TCPWM, 32-bit Counter #5 */
  tcpwm_0_interrupts_6_IRQn         =  94,      /*!<  94 [Active] TCPWM, 32-bit Counter #6 */
  tcpwm_0_interrupts_7_IRQn         =  95,      /*!<  95 [Active] TCPWM, 32-bit Counter #7 */
  tcpwm_0_interrupts_256_IRQn       =  96,      /*!<  96 [Active] TCPWM, 16-bit Counter #0 */
  tcpwm_0_interrupts_257_IRQn       =  97,      /*!<  97 [Active] TCPWM, 16-bit Counter #1 */
  tcpwm_0_interrupts_258_IRQn       =  98,      /*!<  98 [Active] TCPWM, 16-bit Counter #2 */
  tcpwm_0_interrupts_259_IRQn       =  99,      /*!<  99 [Active] TCPWM, 16-bit Counter #3 */
  tcpwm_0_interrupts_260_IRQn       = 100,      /*!< 100 [Active] TCPWM, 16-bit Counter #4 */
  tcpwm_0_interrupts_261_IRQn       = 101,      /*!< 101 [Active] TCPWM, 16-bit Counter #5 */
  tcpwm_0_interrupts_262_IRQn       = 102,      /*!< 102 [Active] TCPWM, 16-bit Counter #6 */
  tcpwm_0_interrupts_263_IRQn       = 103,      /*!< 103 [Active] TCPWM, 16-bit Counter #7 */
  tcpwm_0_interrupts_264_IRQn       = 104,      /*!< 104 [Active] TCPWM, 16-bit Counter #8 */
  tcpwm_0_interrupts_265_IRQn       = 105,      /*!< 105 [Active] TCPWM, 16-bit Counter #9 */
  tcpwm_0_interrupts_266_IRQn       = 106,      /*!< 106 [Active] TCPWM, 16-bit Counter #10 */
  tcpwm_0_interrupts_267_IRQn       = 107,      /*!< 107 [Active] TCPWM, 16-bit Counter #11 */
  tcpwm_0_interrupts_268_IRQn       = 108,      /*!< 108 [Active] TCPWM, 16-bit Counter #12 */
  tcpwm_0_interrupts_269_IRQn       = 109,      /*!< 109 [Active] TCPWM, 16-bit Counter #13 */
  tcpwm_0_interrupts_270_IRQn       = 110,      /*!< 110 [Active] TCPWM, 16-bit Counter #14 */
  tcpwm_0_interrupts_271_IRQn       = 111,      /*!< 111 [Active] TCPWM, 16-bit Counter #15 */
  tcpwm_0_interrupts_272_IRQn       = 112,      /*!< 112 [Active] TCPWM, 16-bit Counter #16 */
  tcpwm_0_interrupts_273_IRQn       = 113,      /*!< 113 [Active] TCPWM, 16-bit Counter #17 */
  tcpwm_0_interrupts_274_IRQn       = 114,      /*!< 114 [Active] TCPWM, 16-bit Counter #18 */
  tcpwm_0_interrupts_275_IRQn       = 115,      /*!< 115 [Active] TCPWM, 16-bit Counter #19 */
  tcpwm_0_interrupts_276_IRQn       = 116,      /*!< 116 [Active] TCPWM, 16-bit Counter #20 */
  tcpwm_0_interrupts_277_IRQn       = 117,      /*!< 117 [Active] TCPWM, 16-bit Counter #21 */
  tcpwm_0_interrupts_278_IRQn       = 118,      /*!< 118 [Active] TCPWM, 16-bit Counter #22 */
  tcpwm_0_interrupts_279_IRQn       = 119,      /*!< 119 [Active] TCPWM, 16-bit Counter #23 */
  scb_1_interrupt_IRQn              = 120,      /*!< 120 [Active] SCB#1 Interrupt */
  scb_2_interrupt_IRQn              = 121,      /*!< 121 [Active] SCB#2 Interrupt */
  scb_3_interrupt_IRQn              = 122,      /*!< 122 [Active] SCB#3 Interrupt */
  scb_4_interrupt_IRQn              = 123,      /*!< 123 [Active] SCB#4 Interrupt */
  scb_5_interrupt_IRQn              = 124,      /*!< 124 [Active] SCB#5 Interrupt */
  scb_6_interrupt_IRQn              = 125,      /*!< 125 [Active] SCB#6 Interrupt */
  scb_7_interrupt_IRQn              = 126,      /*!< 126 [Active] SCB#7 Interrupt */
  scb_8_interrupt_IRQn              = 127,      /*!< 127 [Active] SCB#8 Interrupt */
  scb_9_interrupt_IRQn              = 128,      /*!< 128 [Active] SCB#9 Interrupt */
  scb_10_interrupt_IRQn             = 129,      /*!< 129 [Active] SCB#10 Interrupt */
  scb_11_interrupt_IRQn             = 130,      /*!< 130 [Active] SCB#11 Interrupt */
  sdhc_0_interrupt_general_IRQn     = 131,      /*!< 131 [Active] SDHC0 */
  sdhc_0_interrupt_wakeup_IRQn      = 132,      /*!< 132 [Active] SDHC0 */
  sdhc_1_interrupt_general_IRQn     = 133,      /*!< 133 [Active] SDHC1 */
  sdhc_1_interrupt_wakeup_IRQn      = 134,      /*!< 134 [Active] SDHC1 */
  tdm_0_interrupts_rx_0_IRQn        = 135,      /*!< 135 [Active] TDM0 Audio interrupt RX Structure#0 */
  tdm_0_interrupts_tx_0_IRQn        = 136,      /*!< 136 [Active] TDM0 Audio interrupt TX Structure#0 */
  tdm_0_interrupts_rx_1_IRQn        = 137,      /*!< 137 [Active] TDM0 Audio interrupt RX Structure#1 */
  tdm_0_interrupts_tx_1_IRQn        = 138,      /*!< 138 [Active] TDM0 Audio interrupt TX Structure#1 */
  gfxss_interrupt_gpu_IRQn          = 139,      /*!< 139 [Active] Interrupt from GPU. */
  gfxss_interrupt_dc_IRQn           = 140,      /*!< 140 [Active] Interrupt from DC. */
  gfxss_interrupt_mipidsi_IRQn      = 141,      /*!< 141 [Active] Interrupt from MIPIDSI. */
  pdm_0_interrupts_0_IRQn           = 142,      /*!< 142 [Active] PDM interrupt Structure#0 */
  pdm_0_interrupts_1_IRQn           = 143,      /*!< 143 [Active] PDM interrupt Structure#1 */
  pdm_0_interrupts_2_IRQn           = 144,      /*!< 144 [Active] PDM interrupt Structure#2 */
  pdm_0_interrupts_3_IRQn           = 145,      /*!< 145 [Active] PDM interrupt Structure#3 */
  pdm_0_interrupts_4_IRQn           = 146,      /*!< 146 [Active] PDM interrupt Structure#4 */
  pdm_0_interrupts_5_IRQn           = 147,      /*!< 147 [Active] PDM interrupt Structure#5 */
  eth_interrupt_eth_0_IRQn          = 148,      /*!< 148 [Active] ETH Interrupt#0 */
  eth_interrupt_eth_1_IRQn          = 149,      /*!< 149 [Active] ETH Interrupt#1 */
  eth_interrupt_eth_2_IRQn          = 150,      /*!< 150 [Active] ETH Interrupt#2 */
  usbhs_interrupt_usbhsctrl_IRQn    = 151,      /*!< 151 [Active] Interrupt of Controller core */
  usbhs_interrupt_usbhsss_IRQn      = 152,      /*!< 152 [Active] Interrupt of Subsystem */
  i3c_interrupt_IRQn                = 153,      /*!< 153 [Active] I3C Interrupt */
  crypto_interrupt_IRQn             = 154,      /*!< 154 [Active] Crypto Interrupt */
  m33syscpuss_interrupts_fault_0_IRQn = 155,    /*!< 155 [Active]  */
  m33syscpuss_interrupts_fault_1_IRQn = 156,    /*!< 156 [Active]  */
  m55appcpuss_interrupt_ahb2axi_buff_err_IRQn = 157, /*!< 157 [Active] Interrupt from xhb500 ahb to axi bridge */
  m33syscpuss_interrupts_dw1_0_IRQn = 158,      /*!< 158 [Active] cpuss[0] DataWire #1, Channel #0 */
  m33syscpuss_interrupts_dw1_1_IRQn = 159,      /*!< 159 [Active] cpuss[0] DataWire #1, Channel #1 */
  m33syscpuss_interrupts_dw1_2_IRQn = 160,      /*!< 160 [Active] cpuss[0] DataWire #1, Channel #2 */
  m33syscpuss_interrupts_dw1_3_IRQn = 161,      /*!< 161 [Active] cpuss[0] DataWire #1, Channel #3 */
  m33syscpuss_interrupts_dw1_4_IRQn = 162,      /*!< 162 [Active] cpuss[0] DataWire #1, Channel #4 */
  m33syscpuss_interrupts_dw1_5_IRQn = 163,      /*!< 163 [Active] cpuss[0] DataWire #1, Channel #5 */
  m33syscpuss_interrupts_dw1_6_IRQn = 164,      /*!< 164 [Active] cpuss[0] DataWire #1, Channel #6 */
  m33syscpuss_interrupts_dw1_7_IRQn = 165,      /*!< 165 [Active] cpuss[0] DataWire #1, Channel #7 */
  m33syscpuss_interrupts_dw1_8_IRQn = 166,      /*!< 166 [Active] cpuss[0] DataWire #1, Channel #8 */
  m33syscpuss_interrupts_dw1_9_IRQn = 167,      /*!< 167 [Active] cpuss[0] DataWire #1, Channel #9 */
  m33syscpuss_interrupts_dw1_10_IRQn = 168,     /*!< 168 [Active] cpuss[0] DataWire #1, Channel #10 */
  m33syscpuss_interrupts_dw1_11_IRQn = 169,     /*!< 169 [Active] cpuss[0] DataWire #1, Channel #11 */
  m33syscpuss_interrupts_dw1_12_IRQn = 170,     /*!< 170 [Active] cpuss[0] DataWire #1, Channel #12 */
  m33syscpuss_interrupts_dw1_13_IRQn = 171,     /*!< 171 [Active] cpuss[0] DataWire #1, Channel #13 */
  m33syscpuss_interrupts_dw1_14_IRQn = 172,     /*!< 172 [Active] cpuss[0] DataWire #1, Channel #14 */
  m33syscpuss_interrupts_dw1_15_IRQn = 173,     /*!< 173 [Active] cpuss[0] DataWire #1, Channel #15 */
  unconnected_IRQn                  =1023       /*!< 1023 Unconnected */
#endif
} IRQn_Type;


/*******************************************************************************
*                    Processor and Core Peripheral Section
*******************************************************************************/

#if defined(COMPONENT_CM0P)
/* Configuration of the ARM Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV                   0x0001U /*!< CM0PLUS Core Revision */
#define __NVIC_PRIO_BITS                3       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  1       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   1       /*!< MPU present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm0plus.h"                       /*!< ARM Cortex-M0+ processor and core peripherals */

#elif defined(COMPONENT_CM33)
/* Configuration of the ARM Cortex-M33 Processor and Core Peripherals */
#define __CM33_REV                      0x0001U /*!< CM33 Core Revision */
#define __NVIC_PRIO_BITS                3       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  1       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   1       /*!< MPU present or not */
#define __FPU_PRESENT                   1       /*!< FPU present or not */
#define __CM0P_PRESENT                  0       /*!< CM0P present or not */
#define __DTCM_PRESENT                  0       /*!< Data Tightly Coupled Memory is present or not */
#define __ICACHE_PRESENT                0       /*!< Instruction Cache present or not */
#define __DCACHE_PRESENT                0       /*!< Data Cache present or not */
#define __DSP_PRESENT                   1       /*!< DSP extension present or not */
#define __SAUREGION_PRESENT             1       /*!< SAU regions present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm33.h"                          /*!< ARM Cortex-M33 processor and core peripherals */

#elif defined(COMPONENT_CM55)
/* Configuration of the ARM Cortex-M55 Processor and Core Peripherals */
#define __CM55_REV                      0x0002U /*!< CM55 Core Revision */
#define __NVIC_PRIO_BITS                3       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  1       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   1       /*!< MPU present or not */
#define __FPU_PRESENT                   1       /*!< FPU present or not */
#define __CM0P_PRESENT                  0       /*!< CM0P present or not */
#define __DTCM_PRESENT                  1       /*!< Data Tightly Coupled Memory is present or not */
#define __ICACHE_PRESENT                1       /*!< Instruction Cache present or not */
#define __DCACHE_PRESENT                1       /*!< Data Cache present or not */
#define __DSP_PRESENT                   1       /*!< DSP extension present or not */
#define __SAUREGION_PRESENT             0       /*!< SAU regions present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm55.h"                          /*!< ARM Cortex-M55 processor and core peripherals */

#endif

/* Memory Blocks */
#define CY_ROM_M0_BASE                  0x10000000UL
#define CY_ROM_M0_CBUS_BASE             0x10000000UL
#define CY_ROM_M0_SIZE                  0x00010000UL
#define CY_ROM_M0_NS_SBUS_BASE          0x00000000UL
#define CY_ROM_M0_NS_CBUS_BASE          0x00000000UL
#define CY_ROM_M0_S_SBUS_BASE           0x10000000UL
#define CY_ROM_M0_S_CBUS_BASE           0x10000000UL
#define CY_CM55_ITCM_INTERNAL_BASE      0x10000000UL
#define CY_CM55_ITCM_INTERNAL_CBUS_BASE 0x10000000UL
#define CY_CM55_ITCM_INTERNAL_SIZE      0x00040000UL
#define CY_CM55_ITCM_INTERNAL_NS_SBUS_BASE 0x00000000UL
#define CY_CM55_ITCM_INTERNAL_NS_CBUS_BASE 0x00000000UL
#define CY_CM55_ITCM_INTERNAL_S_SBUS_BASE 0x10000000UL
#define CY_CM55_ITCM_INTERNAL_S_CBUS_BASE 0x10000000UL
#define CY_CM55_DTCM_INTERNAL_BASE      0x30000000UL
#define CY_CM55_DTCM_INTERNAL_SIZE      0x00040000UL
#define CY_CM55_DTCM_INTERNAL_NS_SBUS_BASE 0x20000000UL
#define CY_CM55_DTCM_INTERNAL_S_SBUS_BASE 0x30000000UL
#define CY_RRAM_BASE                    0x32000000UL
#define CY_RRAM_CBUS_BASE               0x12000000UL
#define CY_RRAM_SIZE                    0x00080000UL
#define CY_RRAM_NS_SBUS_BASE            0x22000000UL
#define CY_RRAM_NS_CBUS_BASE            0x02000000UL
#define CY_RRAM_S_SBUS_BASE             0x32000000UL
#define CY_RRAM_S_CBUS_BASE             0x12000000UL
#define CY_SOCMEM_RAM_BASE              0x36000000UL
#define CY_SOCMEM_RAM_CBUS_BASE         0x16000000UL
#define CY_SOCMEM_RAM_SIZE              0x00500000UL
#define CY_SOCMEM_RAM_NS_SBUS_BASE      0x26000000UL
#define CY_SOCMEM_RAM_NS_CBUS_BASE      0x06000000UL
#define CY_SOCMEM_RAM_S_SBUS_BASE       0x36000000UL
#define CY_SOCMEM_RAM_S_CBUS_BASE       0x16000000UL
#define CY_CAN0MRAM_BASE                0x52850000UL
#define CY_CAN0MRAM_CBUS_BASE           0x52850000UL
#define CY_CAN0MRAM_SIZE                0x00010000UL
#define CY_CAN0MRAM_NS_SBUS_BASE        0x42850000UL
#define CY_CAN0MRAM_NS_CBUS_BASE        0x42850000UL
#define CY_CAN0MRAM_S_SBUS_BASE         0x52850000UL
#define CY_CAN0MRAM_S_CBUS_BASE         0x52850000UL
#define CY_CM55_ITCM_BASE               0x58000000UL
#define CY_CM55_ITCM_CBUS_BASE          0x78000000UL
#define CY_CM55_ITCM_SIZE               0x00040000UL
#define CY_CM55_ITCM_NS_SBUS_BASE       0x48000000UL
#define CY_CM55_ITCM_NS_CBUS_BASE       0x68000000UL
#define CY_CM55_ITCM_S_SBUS_BASE        0x58000000UL
#define CY_CM55_ITCM_S_CBUS_BASE        0x78000000UL
#define CY_CM55_DTCM_BASE               0x58040000UL
#define CY_CM55_DTCM_CBUS_BASE          0x78040000UL
#define CY_CM55_DTCM_SIZE               0x00040000UL
#define CY_CM55_DTCM_NS_SBUS_BASE       0x48040000UL
#define CY_CM55_DTCM_NS_CBUS_BASE       0x68040000UL
#define CY_CM55_DTCM_S_SBUS_BASE        0x58040000UL
#define CY_CM55_DTCM_S_CBUS_BASE        0x78040000UL
#define CY_XIP_PORT0_BASE               0x70000000UL
#define CY_XIP_PORT0_CBUS_BASE          0x18000000UL
#define CY_XIP_PORT0_SIZE               0x04000000UL
#define CY_XIP_PORT0_NS_SBUS_BASE       0x60000000UL
#define CY_XIP_PORT0_NS_CBUS_BASE       0x08000000UL
#define CY_XIP_PORT0_S_SBUS_BASE        0x70000000UL
#define CY_XIP_PORT0_S_CBUS_BASE        0x18000000UL
#define CY_XIP_PORT1_BASE               0x74000000UL
#define CY_XIP_PORT1_CBUS_BASE          0x1C000000UL
#define CY_XIP_PORT1_SIZE               0x04000000UL
#define CY_XIP_PORT1_NS_SBUS_BASE       0x64000000UL
#define CY_XIP_PORT1_NS_CBUS_BASE       0x0C000000UL
#define CY_XIP_PORT1_S_SBUS_BASE        0x74000000UL
#define CY_XIP_PORT1_S_CBUS_BASE        0x1C000000UL
#define CY_SRAM_BASE                    0x34000000UL
#define CY_SRAM_CBUS_BASE               0x14000000UL
#define CY_SRAM_SIZE                    0x00100000UL
#define CY_SRAM_NS_SBUS_BASE            0x24000000UL
#define CY_SRAM_NS_CBUS_BASE            0x04000000UL
#define CY_SRAM_S_SBUS_BASE             0x34000000UL
#define CY_SRAM_S_CBUS_BASE             0x14000000UL


/* IP List */
#define CY_IP_MXTTCANFD                 1u
#define CY_IP_MXTTCANFD_INSTANCES       1u
#define CY_IP_MXTTCANFD_VERSION         4u
#define CY_IP_MXTTCANFD_VERSION_MINOR   0u
#define CY_IP_MXCRYPTO                  1u
#define CY_IP_MXCRYPTO_INSTANCES        1u
#define CY_IP_MXCRYPTO_VERSION          2u
#define CY_IP_MXCRYPTO_VERSION_MINOR    1u
#define CY_IP_MXDEBUG600                1u
#define CY_IP_MXDEBUG600_INSTANCES      1u
#define CY_IP_MXDEBUG600_VERSION        1u
#define CY_IP_MXDEBUG600_VERSION_MINOR  2u
#define CY_IP_MXDFT                     1u
#define CY_IP_MXDFT_INSTANCES           1u
#define CY_IP_MXDFT_VERSION             3u
#define CY_IP_MXDFT_VERSION_MINOR       1u
#define CY_IP_MXETH                     1u
#define CY_IP_MXETH_INSTANCES           1u
#define CY_IP_MXETH_VERSION             3u
#define CY_IP_MXETH_VERSION_MINOR       0u
#define CY_IP_MXS22GFXSS                1u
#define CY_IP_MXS22GFXSS_INSTANCES      1u
#define CY_IP_MXS22GFXSS_VERSION        1u
#define CY_IP_MXS22GFXSS_VERSION_MINOR  0u
#define CY_IP_MXI3C                     1u
#define CY_IP_MXI3C_INSTANCES           1u
#define CY_IP_MXI3C_VERSION             1u
#define CY_IP_MXI3C_VERSION_MINOR       1u
#define CY_IP_MXS22IOSS                 1u
#define CY_IP_MXS22IOSS_INSTANCES       1u
#define CY_IP_MXS22IOSS_VERSION         1u
#define CY_IP_MXS22IOSS_VERSION_MINOR   0u
#define CY_IP_MXS22LPCOMP               1u
#define CY_IP_MXS22LPCOMP_INSTANCES     1u
#define CY_IP_MXS22LPCOMP_VERSION       1u
#define CY_IP_MXS22LPCOMP_VERSION_MINOR 0u
#define CY_IP_M0SECCPUSS                1u
#define CY_IP_M0SECCPUSS_INSTANCES      1u
#define CY_IP_M0SECCPUSS_VERSION        2u
#define CY_IP_M0SECCPUSS_VERSION_MINOR  0u
#define CY_IP_M33SYSCPUSS               1u
#define CY_IP_M33SYSCPUSS_INSTANCES     1u
#define CY_IP_M33SYSCPUSS_VERSION       2u
#define CY_IP_M33SYSCPUSS_VERSION_MINOR 2u
#define CY_IP_M55APPCPUSS               1u
#define CY_IP_M55APPCPUSS_INSTANCES     1u
#define CY_IP_M55APPCPUSS_VERSION       1u
#define CY_IP_M55APPCPUSS_VERSION_MINOR 1u
#define CY_IP_MXCM33                    1u
#define CY_IP_MXCM33_INSTANCES          1u
#define CY_IP_MXCM33_VERSION            2u
#define CY_IP_MXCM33_VERSION_MINOR      1u
#define CY_IP_MXCM55                    1u
#define CY_IP_MXCM55_INSTANCES          1u
#define CY_IP_MXCM55_VERSION            1u
#define CY_IP_MXCM55_VERSION_MINOR      0u
#define CY_IP_MXDW                      1u
#define CY_IP_MXDW_INSTANCES            2u
#define CY_IP_MXDW_VERSION              1u
#define CY_IP_MXDW_VERSION_MINOR        0u
#define CY_IP_MXFAULT                   1u
#define CY_IP_MXFAULT_INSTANCES         1u
#define CY_IP_MXFAULT_VERSION           1u
#define CY_IP_MXFAULT_VERSION_MINOR     0u
#define CY_IP_MXIPC                     1u
#define CY_IP_MXIPC_INSTANCES           2u
#define CY_IP_MXIPC_VERSION             1u
#define CY_IP_MXIPC_VERSION_MINOR       0u
#define CY_IP_MXNNLITE                  1u
#define CY_IP_MXNNLITE_INSTANCES        1u
#define CY_IP_MXNNLITE_VERSION          2u
#define CY_IP_MXNNLITE_VERSION_MINOR    0u
#define CY_IP_MXS22RRAMC                1u
#define CY_IP_MXS22RRAMC_INSTANCES      1u
#define CY_IP_MXS22RRAMC_VERSION        1u
#define CY_IP_MXS22RRAMC_VERSION_MINOR  0u
#define CY_IP_MXSRAMC                   1u
#define CY_IP_MXSRAMC_INSTANCES         2u
#define CY_IP_MXSRAMC_VERSION           2u
#define CY_IP_MXSRAMC_VERSION_MINOR     1u
#define CY_IP_MXU55                     1u
#define CY_IP_MXU55_INSTANCES           1u
#define CY_IP_MXU55_VERSION             1u
#define CY_IP_MXU55_VERSION_MINOR       0u
#define CY_IP_MXS22LPPASS               1u
#define CY_IP_MXS22LPPASS_INSTANCES     1u
#define CY_IP_MXS22LPPASS_VERSION       1u
#define CY_IP_MXS22LPPASS_VERSION_MINOR 1u
#define CY_IP_MXS22LPPASS_SAR           1u
#define CY_IP_MXS22LPPASS_SAR_INSTANCES 1u
#define CY_IP_MXS22LPPASS_SAR_VERSION   1u
#define CY_IP_MXS22LPPASS_SAR_VERSION_MINOR 1u
#define CY_IP_MXS22LPPASS_DAC           1u
#define CY_IP_MXS22LPPASS_DAC_INSTANCES 2u
#define CY_IP_MXS22LPPASS_DAC_VERSION   1u
#define CY_IP_MXS22LPPASS_DAC_VERSION_MINOR 1u
#define CY_IP_MXS22LPPASS_PTC           1u
#define CY_IP_MXS22LPPASS_PTC_INSTANCES 1u
#define CY_IP_MXS22LPPASS_PTC_VERSION   1u
#define CY_IP_MXS22LPPASS_PTC_VERSION_MINOR 1u
#define CY_IP_MXS22LPPASS_CTB           1u
#define CY_IP_MXS22LPPASS_CTB_INSTANCES 2u
#define CY_IP_MXS22LPPASS_CTB_VERSION   1u
#define CY_IP_MXS22LPPASS_CTB_VERSION_MINOR 1u
#define CY_IP_MXPDM                     1u
#define CY_IP_MXPDM_INSTANCES           1u
#define CY_IP_MXPDM_VERSION             1u
#define CY_IP_MXPDM_VERSION_MINOR       1u
#define CY_IP_MXSPERI                   1u
#define CY_IP_MXSPERI_INSTANCES         2u
#define CY_IP_MXSPERI_VERSION           2u
#define CY_IP_MXSPERI_VERSION_MINOR     1u
#define CY_IP_MXSPERI_TR                1u
#define CY_IP_MXSPERI_TR_INSTANCES      1u
#define CY_IP_MXSPERI_TR_VERSION        2u
#define CY_IP_MXSPERI_TR_VERSION_MINOR  1u
#define CY_IP_MXSAXIDMAC                1u
#define CY_IP_MXSAXIDMAC_INSTANCES      1u
#define CY_IP_MXSAXIDMAC_VERSION        1u
#define CY_IP_MXSAXIDMAC_VERSION_MINOR  0u
#define CY_IP_MXS22SCB                  1u
#define CY_IP_MXS22SCB_INSTANCES        12u
#define CY_IP_MXS22SCB_VERSION          1u
#define CY_IP_MXS22SCB_VERSION_MINOR    0u
#define CY_IP_MXSDHC                    1u
#define CY_IP_MXSDHC_INSTANCES          2u
#define CY_IP_MXSDHC_VERSION            2u
#define CY_IP_MXSDHC_VERSION_MINOR      0u
#define CY_IP_MXSMIF                    1u
#define CY_IP_MXSMIF_INSTANCES          2u
#define CY_IP_MXSMIF_VERSION            6u
#define CY_IP_MXSMIF_VERSION_MINOR      0u
#define CY_IP_MXSOCMEM                  1u
#define CY_IP_MXSOCMEM_INSTANCES        1u
#define CY_IP_MXSOCMEM_VERSION          1u
#define CY_IP_MXSOCMEM_VERSION_MINOR    0u
#define CY_IP_MXS22SRSS                 1u
#define CY_IP_MXS22SRSS_INSTANCES       1u
#define CY_IP_MXS22SRSS_VERSION         1u
#define CY_IP_MXS22SRSS_VERSION_MINOR   1u
#define CY_IP_MXTCPWM                   1u
#define CY_IP_MXTCPWM_INSTANCES         1u
#define CY_IP_MXTCPWM_VERSION           2u
#define CY_IP_MXTCPWM_VERSION_MINOR     0u
#define CY_IP_MXTDM                     1u
#define CY_IP_MXTDM_INSTANCES           1u
#define CY_IP_MXTDM_VERSION             3u
#define CY_IP_MXTDM_VERSION_MINOR       0u
#define CY_IP_MXS22USBHS                1u
#define CY_IP_MXS22USBHS_INSTANCES      1u
#define CY_IP_MXS22USBHS_VERSION        1u
#define CY_IP_MXS22USBHS_VERSION_MINOR  0u

#define CY_DEVICE_PSE84
#define CY_DEVICE_SERIES_PSE8XXGP
#define CY_DEVICE_IFX_SECURITY_EPC2
#define CY_PDL_TZ_ENABLED
#define CY_SILICON_ID                   0xED942115UL
#define CY_HF_CLK_MAX_FREQ              400000000UL


#include "system_edge.h"

#include "pse84_config.h"
#include "gpio_pse84_bga_220.h"

/*******************************************************************************
*                                   MAIN_NVM
*******************************************************************************/

#define MAIN_NVM_BASE                           0x12000000UL
#define MAIN_NVM                                ((MAIN_NVM_Type*) MAIN_NVM_BASE)                                  /* 0x12000000 */

/*******************************************************************************
*                              NON_SECURE_SFLASH
*******************************************************************************/

#define NON_SECURE_SFLASH_BASE                  0x13C2B000UL
#define NON_SECURE_SFLASH                       ((NON_SECURE_SFLASH_Type*) NON_SECURE_SFLASH_BASE)                /* 0x13C2B000 */

/*******************************************************************************
*                                     PERI
*******************************************************************************/

#define PERI0_BASE                              0x52000000UL
#define PERI1_BASE                              0x54000000UL
#define PERI0                                   ((PERI_Type*) PERI0_BASE)                                         /* 0x52000000 */
#define PERI1                                   ((PERI_Type*) PERI1_BASE)                                         /* 0x54000000 */
#define PERI0_GR0                               ((PERI_GR_Type*) &PERI0->GR[0])                                   /* 0x52004000 */
#define PERI0_GR1                               ((PERI_GR_Type*) &PERI0->GR[1])                                   /* 0x52004040 */
#define PERI0_GR2                               ((PERI_GR_Type*) &PERI0->GR[2])                                   /* 0x52004080 */
#define PERI0_GR3                               ((PERI_GR_Type*) &PERI0->GR[3])                                   /* 0x520040C0 */
#define PERI0_GR4                               ((PERI_GR_Type*) &PERI0->GR[4])                                   /* 0x52004100 */
#define PERI0_GR5                               ((PERI_GR_Type*) &PERI0->GR[5])                                   /* 0x52004140 */
#define PERI1_GR0                               ((PERI_GR_Type*) &PERI1->GR[0])                                   /* 0x54004000 */
#define PERI1_GR1                               ((PERI_GR_Type*) &PERI1->GR[1])                                   /* 0x54004040 */
#define PERI1_GR2                               ((PERI_GR_Type*) &PERI1->GR[2])                                   /* 0x54004080 */
#define PERI1_GR3                               ((PERI_GR_Type*) &PERI1->GR[3])                                   /* 0x540040C0 */
#define PERI1_GR4                               ((PERI_GR_Type*) &PERI1->GR[4])                                   /* 0x54004100 */
#define PERI0_TR_GR0                            ((PERI_TR_GR_Type*) &PERI0->TR_GR[0])                             /* 0x52008000 */
#define PERI0_TR_GR1                            ((PERI_TR_GR_Type*) &PERI0->TR_GR[1])                             /* 0x52008400 */
#define PERI0_TR_GR2                            ((PERI_TR_GR_Type*) &PERI0->TR_GR[2])                             /* 0x52008800 */
#define PERI0_TR_GR3                            ((PERI_TR_GR_Type*) &PERI0->TR_GR[3])                             /* 0x52008C00 */
#define PERI0_TR_GR4                            ((PERI_TR_GR_Type*) &PERI0->TR_GR[4])                             /* 0x52009000 */
#define PERI0_TR_GR5                            ((PERI_TR_GR_Type*) &PERI0->TR_GR[5])                             /* 0x52009400 */
#define PERI1_TR_GR0                            ((PERI_TR_GR_Type*) &PERI1->TR_GR[0])                             /* 0x54008000 */
#define PERI1_TR_GR1                            ((PERI_TR_GR_Type*) &PERI1->TR_GR[1])                             /* 0x54008400 */
#define PERI1_TR_GR2                            ((PERI_TR_GR_Type*) &PERI1->TR_GR[2])                             /* 0x54008800 */
#define PERI0_TR_1TO1_GR0                       ((PERI_TR_1TO1_GR_Type*) &PERI0->TR_1TO1_GR[0])                   /* 0x5200C000 */

/*******************************************************************************
*                                     PPC
*******************************************************************************/

#define PPC0_BASE                               0x52020000UL
#define PPC1_BASE                               0x54020000UL
#define PPC0                                    ((PPC_Type*) PPC0_BASE)                                           /* 0x52020000 */
#define PPC1                                    ((PPC_Type*) PPC1_BASE)                                           /* 0x54020000 */
#define PPC0_R_ADDR0                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[0])                             /* 0x52025000 */
#define PPC0_R_ADDR1                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[1])                             /* 0x52025004 */
#define PPC0_R_ADDR2                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[2])                             /* 0x52025008 */
#define PPC0_R_ADDR3                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[3])                             /* 0x5202500C */
#define PPC0_R_ADDR4                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[4])                             /* 0x52025010 */
#define PPC0_R_ADDR5                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[5])                             /* 0x52025014 */
#define PPC0_R_ADDR6                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[6])                             /* 0x52025018 */
#define PPC0_R_ADDR7                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[7])                             /* 0x5202501C */
#define PPC0_R_ADDR8                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[8])                             /* 0x52025020 */
#define PPC0_R_ADDR9                            ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[9])                             /* 0x52025024 */
#define PPC0_R_ADDR10                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[10])                            /* 0x52025028 */
#define PPC0_R_ADDR11                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[11])                            /* 0x5202502C */
#define PPC0_R_ADDR12                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[12])                            /* 0x52025030 */
#define PPC0_R_ADDR13                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[13])                            /* 0x52025034 */
#define PPC0_R_ADDR14                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[14])                            /* 0x52025038 */
#define PPC0_R_ADDR15                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[15])                            /* 0x5202503C */
#define PPC0_R_ADDR16                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[16])                            /* 0x52025040 */
#define PPC0_R_ADDR17                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[17])                            /* 0x52025044 */
#define PPC0_R_ADDR18                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[18])                            /* 0x52025048 */
#define PPC0_R_ADDR19                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[19])                            /* 0x5202504C */
#define PPC0_R_ADDR20                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[20])                            /* 0x52025050 */
#define PPC0_R_ADDR21                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[21])                            /* 0x52025054 */
#define PPC0_R_ADDR22                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[22])                            /* 0x52025058 */
#define PPC0_R_ADDR23                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[23])                            /* 0x5202505C */
#define PPC0_R_ADDR24                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[24])                            /* 0x52025060 */
#define PPC0_R_ADDR25                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[25])                            /* 0x52025064 */
#define PPC0_R_ADDR26                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[26])                            /* 0x52025068 */
#define PPC0_R_ADDR27                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[27])                            /* 0x5202506C */
#define PPC0_R_ADDR28                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[28])                            /* 0x52025070 */
#define PPC0_R_ADDR29                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[29])                            /* 0x52025074 */
#define PPC0_R_ADDR30                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[30])                            /* 0x52025078 */
#define PPC0_R_ADDR31                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[31])                            /* 0x5202507C */
#define PPC0_R_ADDR32                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[32])                            /* 0x52025080 */
#define PPC0_R_ADDR33                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[33])                            /* 0x52025084 */
#define PPC0_R_ADDR34                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[34])                            /* 0x52025088 */
#define PPC0_R_ADDR35                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[35])                            /* 0x5202508C */
#define PPC0_R_ADDR36                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[36])                            /* 0x52025090 */
#define PPC0_R_ADDR37                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[37])                            /* 0x52025094 */
#define PPC0_R_ADDR38                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[38])                            /* 0x52025098 */
#define PPC0_R_ADDR39                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[39])                            /* 0x5202509C */
#define PPC0_R_ADDR40                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[40])                            /* 0x520250A0 */
#define PPC0_R_ADDR41                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[41])                            /* 0x520250A4 */
#define PPC0_R_ADDR42                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[42])                            /* 0x520250A8 */
#define PPC0_R_ADDR43                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[43])                            /* 0x520250AC */
#define PPC0_R_ADDR44                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[44])                            /* 0x520250B0 */
#define PPC0_R_ADDR45                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[45])                            /* 0x520250B4 */
#define PPC0_R_ADDR46                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[46])                            /* 0x520250B8 */
#define PPC0_R_ADDR47                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[47])                            /* 0x520250BC */
#define PPC0_R_ADDR48                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[48])                            /* 0x520250C0 */
#define PPC0_R_ADDR49                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[49])                            /* 0x520250C4 */
#define PPC0_R_ADDR50                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[50])                            /* 0x520250C8 */
#define PPC0_R_ADDR51                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[51])                            /* 0x520250CC */
#define PPC0_R_ADDR52                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[52])                            /* 0x520250D0 */
#define PPC0_R_ADDR53                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[53])                            /* 0x520250D4 */
#define PPC0_R_ADDR54                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[54])                            /* 0x520250D8 */
#define PPC0_R_ADDR55                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[55])                            /* 0x520250DC */
#define PPC0_R_ADDR56                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[56])                            /* 0x520250E0 */
#define PPC0_R_ADDR57                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[57])                            /* 0x520250E4 */
#define PPC0_R_ADDR58                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[58])                            /* 0x520250E8 */
#define PPC0_R_ADDR59                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[59])                            /* 0x520250EC */
#define PPC0_R_ADDR60                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[60])                            /* 0x520250F0 */
#define PPC0_R_ADDR61                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[61])                            /* 0x520250F4 */
#define PPC0_R_ADDR62                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[62])                            /* 0x520250F8 */
#define PPC0_R_ADDR63                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[63])                            /* 0x520250FC */
#define PPC0_R_ADDR64                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[64])                            /* 0x52025100 */
#define PPC0_R_ADDR65                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[65])                            /* 0x52025104 */
#define PPC0_R_ADDR66                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[66])                            /* 0x52025108 */
#define PPC0_R_ADDR67                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[67])                            /* 0x5202510C */
#define PPC0_R_ADDR68                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[68])                            /* 0x52025110 */
#define PPC0_R_ADDR69                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[69])                            /* 0x52025114 */
#define PPC0_R_ADDR70                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[70])                            /* 0x52025118 */
#define PPC0_R_ADDR71                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[71])                            /* 0x5202511C */
#define PPC0_R_ADDR72                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[72])                            /* 0x52025120 */
#define PPC0_R_ADDR73                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[73])                            /* 0x52025124 */
#define PPC0_R_ADDR74                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[74])                            /* 0x52025128 */
#define PPC0_R_ADDR75                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[75])                            /* 0x5202512C */
#define PPC0_R_ADDR76                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[76])                            /* 0x52025130 */
#define PPC0_R_ADDR77                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[77])                            /* 0x52025134 */
#define PPC0_R_ADDR78                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[78])                            /* 0x52025138 */
#define PPC0_R_ADDR79                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[79])                            /* 0x5202513C */
#define PPC0_R_ADDR80                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[80])                            /* 0x52025140 */
#define PPC0_R_ADDR81                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[81])                            /* 0x52025144 */
#define PPC0_R_ADDR82                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[82])                            /* 0x52025148 */
#define PPC0_R_ADDR83                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[83])                            /* 0x5202514C */
#define PPC0_R_ADDR84                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[84])                            /* 0x52025150 */
#define PPC0_R_ADDR85                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[85])                            /* 0x52025154 */
#define PPC0_R_ADDR86                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[86])                            /* 0x52025158 */
#define PPC0_R_ADDR87                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[87])                            /* 0x5202515C */
#define PPC0_R_ADDR88                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[88])                            /* 0x52025160 */
#define PPC0_R_ADDR89                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[89])                            /* 0x52025164 */
#define PPC0_R_ADDR90                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[90])                            /* 0x52025168 */
#define PPC0_R_ADDR91                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[91])                            /* 0x5202516C */
#define PPC0_R_ADDR92                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[92])                            /* 0x52025170 */
#define PPC0_R_ADDR93                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[93])                            /* 0x52025174 */
#define PPC0_R_ADDR94                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[94])                            /* 0x52025178 */
#define PPC0_R_ADDR95                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[95])                            /* 0x5202517C */
#define PPC0_R_ADDR96                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[96])                            /* 0x52025180 */
#define PPC0_R_ADDR97                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[97])                            /* 0x52025184 */
#define PPC0_R_ADDR98                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[98])                            /* 0x52025188 */
#define PPC0_R_ADDR99                           ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[99])                            /* 0x5202518C */
#define PPC0_R_ADDR100                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[100])                           /* 0x52025190 */
#define PPC0_R_ADDR101                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[101])                           /* 0x52025194 */
#define PPC0_R_ADDR102                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[102])                           /* 0x52025198 */
#define PPC0_R_ADDR103                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[103])                           /* 0x5202519C */
#define PPC0_R_ADDR104                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[104])                           /* 0x520251A0 */
#define PPC0_R_ADDR105                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[105])                           /* 0x520251A4 */
#define PPC0_R_ADDR106                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[106])                           /* 0x520251A8 */
#define PPC0_R_ADDR107                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[107])                           /* 0x520251AC */
#define PPC0_R_ADDR108                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[108])                           /* 0x520251B0 */
#define PPC0_R_ADDR109                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[109])                           /* 0x520251B4 */
#define PPC0_R_ADDR110                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[110])                           /* 0x520251B8 */
#define PPC0_R_ADDR111                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[111])                           /* 0x520251BC */
#define PPC0_R_ADDR112                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[112])                           /* 0x520251C0 */
#define PPC0_R_ADDR113                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[113])                           /* 0x520251C4 */
#define PPC0_R_ADDR114                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[114])                           /* 0x520251C8 */
#define PPC0_R_ADDR115                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[115])                           /* 0x520251CC */
#define PPC0_R_ADDR116                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[116])                           /* 0x520251D0 */
#define PPC0_R_ADDR117                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[117])                           /* 0x520251D4 */
#define PPC0_R_ADDR118                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[118])                           /* 0x520251D8 */
#define PPC0_R_ADDR119                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[119])                           /* 0x520251DC */
#define PPC0_R_ADDR120                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[120])                           /* 0x520251E0 */
#define PPC0_R_ADDR121                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[121])                           /* 0x520251E4 */
#define PPC0_R_ADDR122                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[122])                           /* 0x520251E8 */
#define PPC0_R_ADDR123                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[123])                           /* 0x520251EC */
#define PPC0_R_ADDR124                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[124])                           /* 0x520251F0 */
#define PPC0_R_ADDR125                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[125])                           /* 0x520251F4 */
#define PPC0_R_ADDR126                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[126])                           /* 0x520251F8 */
#define PPC0_R_ADDR127                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[127])                           /* 0x520251FC */
#define PPC0_R_ADDR128                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[128])                           /* 0x52025200 */
#define PPC0_R_ADDR129                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[129])                           /* 0x52025204 */
#define PPC0_R_ADDR130                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[130])                           /* 0x52025208 */
#define PPC0_R_ADDR131                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[131])                           /* 0x5202520C */
#define PPC0_R_ADDR132                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[132])                           /* 0x52025210 */
#define PPC0_R_ADDR133                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[133])                           /* 0x52025214 */
#define PPC0_R_ADDR134                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[134])                           /* 0x52025218 */
#define PPC0_R_ADDR135                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[135])                           /* 0x5202521C */
#define PPC0_R_ADDR136                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[136])                           /* 0x52025220 */
#define PPC0_R_ADDR137                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[137])                           /* 0x52025224 */
#define PPC0_R_ADDR138                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[138])                           /* 0x52025228 */
#define PPC0_R_ADDR139                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[139])                           /* 0x5202522C */
#define PPC0_R_ADDR140                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[140])                           /* 0x52025230 */
#define PPC0_R_ADDR141                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[141])                           /* 0x52025234 */
#define PPC0_R_ADDR142                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[142])                           /* 0x52025238 */
#define PPC0_R_ADDR143                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[143])                           /* 0x5202523C */
#define PPC0_R_ADDR144                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[144])                           /* 0x52025240 */
#define PPC0_R_ADDR145                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[145])                           /* 0x52025244 */
#define PPC0_R_ADDR146                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[146])                           /* 0x52025248 */
#define PPC0_R_ADDR147                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[147])                           /* 0x5202524C */
#define PPC0_R_ADDR148                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[148])                           /* 0x52025250 */
#define PPC0_R_ADDR149                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[149])                           /* 0x52025254 */
#define PPC0_R_ADDR150                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[150])                           /* 0x52025258 */
#define PPC0_R_ADDR151                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[151])                           /* 0x5202525C */
#define PPC0_R_ADDR152                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[152])                           /* 0x52025260 */
#define PPC0_R_ADDR153                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[153])                           /* 0x52025264 */
#define PPC0_R_ADDR154                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[154])                           /* 0x52025268 */
#define PPC0_R_ADDR155                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[155])                           /* 0x5202526C */
#define PPC0_R_ADDR156                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[156])                           /* 0x52025270 */
#define PPC0_R_ADDR157                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[157])                           /* 0x52025274 */
#define PPC0_R_ADDR158                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[158])                           /* 0x52025278 */
#define PPC0_R_ADDR159                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[159])                           /* 0x5202527C */
#define PPC0_R_ADDR160                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[160])                           /* 0x52025280 */
#define PPC0_R_ADDR161                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[161])                           /* 0x52025284 */
#define PPC0_R_ADDR162                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[162])                           /* 0x52025288 */
#define PPC0_R_ADDR163                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[163])                           /* 0x5202528C */
#define PPC0_R_ADDR164                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[164])                           /* 0x52025290 */
#define PPC0_R_ADDR165                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[165])                           /* 0x52025294 */
#define PPC0_R_ADDR166                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[166])                           /* 0x52025298 */
#define PPC0_R_ADDR167                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[167])                           /* 0x5202529C */
#define PPC0_R_ADDR168                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[168])                           /* 0x520252A0 */
#define PPC0_R_ADDR169                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[169])                           /* 0x520252A4 */
#define PPC0_R_ADDR170                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[170])                           /* 0x520252A8 */
#define PPC0_R_ADDR171                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[171])                           /* 0x520252AC */
#define PPC0_R_ADDR172                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[172])                           /* 0x520252B0 */
#define PPC0_R_ADDR173                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[173])                           /* 0x520252B4 */
#define PPC0_R_ADDR174                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[174])                           /* 0x520252B8 */
#define PPC0_R_ADDR175                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[175])                           /* 0x520252BC */
#define PPC0_R_ADDR176                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[176])                           /* 0x520252C0 */
#define PPC0_R_ADDR177                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[177])                           /* 0x520252C4 */
#define PPC0_R_ADDR178                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[178])                           /* 0x520252C8 */
#define PPC0_R_ADDR179                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[179])                           /* 0x520252CC */
#define PPC0_R_ADDR180                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[180])                           /* 0x520252D0 */
#define PPC0_R_ADDR181                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[181])                           /* 0x520252D4 */
#define PPC0_R_ADDR182                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[182])                           /* 0x520252D8 */
#define PPC0_R_ADDR183                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[183])                           /* 0x520252DC */
#define PPC0_R_ADDR184                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[184])                           /* 0x520252E0 */
#define PPC0_R_ADDR185                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[185])                           /* 0x520252E4 */
#define PPC0_R_ADDR186                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[186])                           /* 0x520252E8 */
#define PPC0_R_ADDR187                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[187])                           /* 0x520252EC */
#define PPC0_R_ADDR188                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[188])                           /* 0x520252F0 */
#define PPC0_R_ADDR189                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[189])                           /* 0x520252F4 */
#define PPC0_R_ADDR190                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[190])                           /* 0x520252F8 */
#define PPC0_R_ADDR191                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[191])                           /* 0x520252FC */
#define PPC0_R_ADDR192                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[192])                           /* 0x52025300 */
#define PPC0_R_ADDR193                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[193])                           /* 0x52025304 */
#define PPC0_R_ADDR194                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[194])                           /* 0x52025308 */
#define PPC0_R_ADDR195                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[195])                           /* 0x5202530C */
#define PPC0_R_ADDR196                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[196])                           /* 0x52025310 */
#define PPC0_R_ADDR197                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[197])                           /* 0x52025314 */
#define PPC0_R_ADDR198                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[198])                           /* 0x52025318 */
#define PPC0_R_ADDR199                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[199])                           /* 0x5202531C */
#define PPC0_R_ADDR200                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[200])                           /* 0x52025320 */
#define PPC0_R_ADDR201                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[201])                           /* 0x52025324 */
#define PPC0_R_ADDR202                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[202])                           /* 0x52025328 */
#define PPC0_R_ADDR203                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[203])                           /* 0x5202532C */
#define PPC0_R_ADDR204                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[204])                           /* 0x52025330 */
#define PPC0_R_ADDR205                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[205])                           /* 0x52025334 */
#define PPC0_R_ADDR206                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[206])                           /* 0x52025338 */
#define PPC0_R_ADDR207                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[207])                           /* 0x5202533C */
#define PPC0_R_ADDR208                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[208])                           /* 0x52025340 */
#define PPC0_R_ADDR209                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[209])                           /* 0x52025344 */
#define PPC0_R_ADDR210                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[210])                           /* 0x52025348 */
#define PPC0_R_ADDR211                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[211])                           /* 0x5202534C */
#define PPC0_R_ADDR212                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[212])                           /* 0x52025350 */
#define PPC0_R_ADDR213                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[213])                           /* 0x52025354 */
#define PPC0_R_ADDR214                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[214])                           /* 0x52025358 */
#define PPC0_R_ADDR215                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[215])                           /* 0x5202535C */
#define PPC0_R_ADDR216                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[216])                           /* 0x52025360 */
#define PPC0_R_ADDR217                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[217])                           /* 0x52025364 */
#define PPC0_R_ADDR218                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[218])                           /* 0x52025368 */
#define PPC0_R_ADDR219                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[219])                           /* 0x5202536C */
#define PPC0_R_ADDR220                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[220])                           /* 0x52025370 */
#define PPC0_R_ADDR221                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[221])                           /* 0x52025374 */
#define PPC0_R_ADDR222                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[222])                           /* 0x52025378 */
#define PPC0_R_ADDR223                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[223])                           /* 0x5202537C */
#define PPC0_R_ADDR224                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[224])                           /* 0x52025380 */
#define PPC0_R_ADDR225                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[225])                           /* 0x52025384 */
#define PPC0_R_ADDR226                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[226])                           /* 0x52025388 */
#define PPC0_R_ADDR227                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[227])                           /* 0x5202538C */
#define PPC0_R_ADDR228                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[228])                           /* 0x52025390 */
#define PPC0_R_ADDR229                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[229])                           /* 0x52025394 */
#define PPC0_R_ADDR230                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[230])                           /* 0x52025398 */
#define PPC0_R_ADDR231                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[231])                           /* 0x5202539C */
#define PPC0_R_ADDR232                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[232])                           /* 0x520253A0 */
#define PPC0_R_ADDR233                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[233])                           /* 0x520253A4 */
#define PPC0_R_ADDR234                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[234])                           /* 0x520253A8 */
#define PPC0_R_ADDR235                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[235])                           /* 0x520253AC */
#define PPC0_R_ADDR236                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[236])                           /* 0x520253B0 */
#define PPC0_R_ADDR237                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[237])                           /* 0x520253B4 */
#define PPC0_R_ADDR238                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[238])                           /* 0x520253B8 */
#define PPC0_R_ADDR239                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[239])                           /* 0x520253BC */
#define PPC0_R_ADDR240                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[240])                           /* 0x520253C0 */
#define PPC0_R_ADDR241                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[241])                           /* 0x520253C4 */
#define PPC0_R_ADDR242                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[242])                           /* 0x520253C8 */
#define PPC0_R_ADDR243                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[243])                           /* 0x520253CC */
#define PPC0_R_ADDR244                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[244])                           /* 0x520253D0 */
#define PPC0_R_ADDR245                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[245])                           /* 0x520253D4 */
#define PPC0_R_ADDR246                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[246])                           /* 0x520253D8 */
#define PPC0_R_ADDR247                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[247])                           /* 0x520253DC */
#define PPC0_R_ADDR248                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[248])                           /* 0x520253E0 */
#define PPC0_R_ADDR249                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[249])                           /* 0x520253E4 */
#define PPC0_R_ADDR250                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[250])                           /* 0x520253E8 */
#define PPC0_R_ADDR251                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[251])                           /* 0x520253EC */
#define PPC0_R_ADDR252                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[252])                           /* 0x520253F0 */
#define PPC0_R_ADDR253                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[253])                           /* 0x520253F4 */
#define PPC0_R_ADDR254                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[254])                           /* 0x520253F8 */
#define PPC0_R_ADDR255                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[255])                           /* 0x520253FC */
#define PPC0_R_ADDR256                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[256])                           /* 0x52025400 */
#define PPC0_R_ADDR257                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[257])                           /* 0x52025404 */
#define PPC0_R_ADDR258                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[258])                           /* 0x52025408 */
#define PPC0_R_ADDR259                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[259])                           /* 0x5202540C */
#define PPC0_R_ADDR260                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[260])                           /* 0x52025410 */
#define PPC0_R_ADDR261                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[261])                           /* 0x52025414 */
#define PPC0_R_ADDR262                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[262])                           /* 0x52025418 */
#define PPC0_R_ADDR263                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[263])                           /* 0x5202541C */
#define PPC0_R_ADDR264                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[264])                           /* 0x52025420 */
#define PPC0_R_ADDR265                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[265])                           /* 0x52025424 */
#define PPC0_R_ADDR266                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[266])                           /* 0x52025428 */
#define PPC0_R_ADDR267                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[267])                           /* 0x5202542C */
#define PPC0_R_ADDR268                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[268])                           /* 0x52025430 */
#define PPC0_R_ADDR269                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[269])                           /* 0x52025434 */
#define PPC0_R_ADDR270                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[270])                           /* 0x52025438 */
#define PPC0_R_ADDR271                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[271])                           /* 0x5202543C */
#define PPC0_R_ADDR272                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[272])                           /* 0x52025440 */
#define PPC0_R_ADDR273                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[273])                           /* 0x52025444 */
#define PPC0_R_ADDR274                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[274])                           /* 0x52025448 */
#define PPC0_R_ADDR275                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[275])                           /* 0x5202544C */
#define PPC0_R_ADDR276                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[276])                           /* 0x52025450 */
#define PPC0_R_ADDR277                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[277])                           /* 0x52025454 */
#define PPC0_R_ADDR278                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[278])                           /* 0x52025458 */
#define PPC0_R_ADDR279                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[279])                           /* 0x5202545C */
#define PPC0_R_ADDR280                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[280])                           /* 0x52025460 */
#define PPC0_R_ADDR281                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[281])                           /* 0x52025464 */
#define PPC0_R_ADDR282                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[282])                           /* 0x52025468 */
#define PPC0_R_ADDR283                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[283])                           /* 0x5202546C */
#define PPC0_R_ADDR284                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[284])                           /* 0x52025470 */
#define PPC0_R_ADDR285                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[285])                           /* 0x52025474 */
#define PPC0_R_ADDR286                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[286])                           /* 0x52025478 */
#define PPC0_R_ADDR287                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[287])                           /* 0x5202547C */
#define PPC0_R_ADDR288                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[288])                           /* 0x52025480 */
#define PPC0_R_ADDR289                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[289])                           /* 0x52025484 */
#define PPC0_R_ADDR290                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[290])                           /* 0x52025488 */
#define PPC0_R_ADDR291                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[291])                           /* 0x5202548C */
#define PPC0_R_ADDR292                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[292])                           /* 0x52025490 */
#define PPC0_R_ADDR293                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[293])                           /* 0x52025494 */
#define PPC0_R_ADDR294                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[294])                           /* 0x52025498 */
#define PPC0_R_ADDR295                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[295])                           /* 0x5202549C */
#define PPC0_R_ADDR296                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[296])                           /* 0x520254A0 */
#define PPC0_R_ADDR297                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[297])                           /* 0x520254A4 */
#define PPC0_R_ADDR298                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[298])                           /* 0x520254A8 */
#define PPC0_R_ADDR299                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[299])                           /* 0x520254AC */
#define PPC0_R_ADDR300                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[300])                           /* 0x520254B0 */
#define PPC0_R_ADDR301                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[301])                           /* 0x520254B4 */
#define PPC0_R_ADDR302                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[302])                           /* 0x520254B8 */
#define PPC0_R_ADDR303                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[303])                           /* 0x520254BC */
#define PPC0_R_ADDR304                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[304])                           /* 0x520254C0 */
#define PPC0_R_ADDR305                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[305])                           /* 0x520254C4 */
#define PPC0_R_ADDR306                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[306])                           /* 0x520254C8 */
#define PPC0_R_ADDR307                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[307])                           /* 0x520254CC */
#define PPC0_R_ADDR308                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[308])                           /* 0x520254D0 */
#define PPC0_R_ADDR309                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[309])                           /* 0x520254D4 */
#define PPC0_R_ADDR310                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[310])                           /* 0x520254D8 */
#define PPC0_R_ADDR311                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[311])                           /* 0x520254DC */
#define PPC0_R_ADDR312                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[312])                           /* 0x520254E0 */
#define PPC0_R_ADDR313                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[313])                           /* 0x520254E4 */
#define PPC0_R_ADDR314                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[314])                           /* 0x520254E8 */
#define PPC0_R_ADDR315                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[315])                           /* 0x520254EC */
#define PPC0_R_ADDR316                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[316])                           /* 0x520254F0 */
#define PPC0_R_ADDR317                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[317])                           /* 0x520254F4 */
#define PPC0_R_ADDR318                          ((PPC_R_ADDR_Type*) &PPC0->R_ADDR[318])                           /* 0x520254F8 */
#define PPC1_R_ADDR0                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[0])                             /* 0x54025000 */
#define PPC1_R_ADDR1                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[1])                             /* 0x54025004 */
#define PPC1_R_ADDR2                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[2])                             /* 0x54025008 */
#define PPC1_R_ADDR3                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[3])                             /* 0x5402500C */
#define PPC1_R_ADDR4                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[4])                             /* 0x54025010 */
#define PPC1_R_ADDR5                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[5])                             /* 0x54025014 */
#define PPC1_R_ADDR6                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[6])                             /* 0x54025018 */
#define PPC1_R_ADDR7                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[7])                             /* 0x5402501C */
#define PPC1_R_ADDR8                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[8])                             /* 0x54025020 */
#define PPC1_R_ADDR9                            ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[9])                             /* 0x54025024 */
#define PPC1_R_ADDR10                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[10])                            /* 0x54025028 */
#define PPC1_R_ADDR11                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[11])                            /* 0x5402502C */
#define PPC1_R_ADDR12                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[12])                            /* 0x54025030 */
#define PPC1_R_ADDR13                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[13])                            /* 0x54025034 */
#define PPC1_R_ADDR14                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[14])                            /* 0x54025038 */
#define PPC1_R_ADDR15                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[15])                            /* 0x5402503C */
#define PPC1_R_ADDR16                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[16])                            /* 0x54025040 */
#define PPC1_R_ADDR17                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[17])                            /* 0x54025044 */
#define PPC1_R_ADDR18                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[18])                            /* 0x54025048 */
#define PPC1_R_ADDR19                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[19])                            /* 0x5402504C */
#define PPC1_R_ADDR20                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[20])                            /* 0x54025050 */
#define PPC1_R_ADDR21                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[21])                            /* 0x54025054 */
#define PPC1_R_ADDR22                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[22])                            /* 0x54025058 */
#define PPC1_R_ADDR23                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[23])                            /* 0x5402505C */
#define PPC1_R_ADDR24                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[24])                            /* 0x54025060 */
#define PPC1_R_ADDR25                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[25])                            /* 0x54025064 */
#define PPC1_R_ADDR26                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[26])                            /* 0x54025068 */
#define PPC1_R_ADDR27                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[27])                            /* 0x5402506C */
#define PPC1_R_ADDR28                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[28])                            /* 0x54025070 */
#define PPC1_R_ADDR29                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[29])                            /* 0x54025074 */
#define PPC1_R_ADDR30                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[30])                            /* 0x54025078 */
#define PPC1_R_ADDR31                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[31])                            /* 0x5402507C */
#define PPC1_R_ADDR32                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[32])                            /* 0x54025080 */
#define PPC1_R_ADDR33                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[33])                            /* 0x54025084 */
#define PPC1_R_ADDR34                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[34])                            /* 0x54025088 */
#define PPC1_R_ADDR35                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[35])                            /* 0x5402508C */
#define PPC1_R_ADDR36                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[36])                            /* 0x54025090 */
#define PPC1_R_ADDR37                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[37])                            /* 0x54025094 */
#define PPC1_R_ADDR38                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[38])                            /* 0x54025098 */
#define PPC1_R_ADDR39                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[39])                            /* 0x5402509C */
#define PPC1_R_ADDR40                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[40])                            /* 0x540250A0 */
#define PPC1_R_ADDR41                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[41])                            /* 0x540250A4 */
#define PPC1_R_ADDR42                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[42])                            /* 0x540250A8 */
#define PPC1_R_ADDR43                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[43])                            /* 0x540250AC */
#define PPC1_R_ADDR44                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[44])                            /* 0x540250B0 */
#define PPC1_R_ADDR45                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[45])                            /* 0x540250B4 */
#define PPC1_R_ADDR46                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[46])                            /* 0x540250B8 */
#define PPC1_R_ADDR47                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[47])                            /* 0x540250BC */
#define PPC1_R_ADDR48                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[48])                            /* 0x540250C0 */
#define PPC1_R_ADDR49                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[49])                            /* 0x540250C4 */
#define PPC1_R_ADDR50                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[50])                            /* 0x540250C8 */
#define PPC1_R_ADDR51                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[51])                            /* 0x540250CC */
#define PPC1_R_ADDR52                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[52])                            /* 0x540250D0 */
#define PPC1_R_ADDR53                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[53])                            /* 0x540250D4 */
#define PPC1_R_ADDR54                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[54])                            /* 0x540250D8 */
#define PPC1_R_ADDR55                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[55])                            /* 0x540250DC */
#define PPC1_R_ADDR56                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[56])                            /* 0x540250E0 */
#define PPC1_R_ADDR57                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[57])                            /* 0x540250E4 */
#define PPC1_R_ADDR58                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[58])                            /* 0x540250E8 */
#define PPC1_R_ADDR59                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[59])                            /* 0x540250EC */
#define PPC1_R_ADDR60                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[60])                            /* 0x540250F0 */
#define PPC1_R_ADDR61                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[61])                            /* 0x540250F4 */
#define PPC1_R_ADDR62                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[62])                            /* 0x540250F8 */
#define PPC1_R_ADDR63                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[63])                            /* 0x540250FC */
#define PPC1_R_ADDR64                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[64])                            /* 0x54025100 */
#define PPC1_R_ADDR65                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[65])                            /* 0x54025104 */
#define PPC1_R_ADDR66                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[66])                            /* 0x54025108 */
#define PPC1_R_ADDR67                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[67])                            /* 0x5402510C */
#define PPC1_R_ADDR68                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[68])                            /* 0x54025110 */
#define PPC1_R_ADDR69                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[69])                            /* 0x54025114 */
#define PPC1_R_ADDR70                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[70])                            /* 0x54025118 */
#define PPC1_R_ADDR71                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[71])                            /* 0x5402511C */
#define PPC1_R_ADDR72                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[72])                            /* 0x54025120 */
#define PPC1_R_ADDR73                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[73])                            /* 0x54025124 */
#define PPC1_R_ADDR74                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[74])                            /* 0x54025128 */
#define PPC1_R_ADDR75                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[75])                            /* 0x5402512C */
#define PPC1_R_ADDR76                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[76])                            /* 0x54025130 */
#define PPC1_R_ADDR77                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[77])                            /* 0x54025134 */
#define PPC1_R_ADDR78                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[78])                            /* 0x54025138 */
#define PPC1_R_ADDR79                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[79])                            /* 0x5402513C */
#define PPC1_R_ADDR80                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[80])                            /* 0x54025140 */
#define PPC1_R_ADDR81                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[81])                            /* 0x54025144 */
#define PPC1_R_ADDR82                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[82])                            /* 0x54025148 */
#define PPC1_R_ADDR83                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[83])                            /* 0x5402514C */
#define PPC1_R_ADDR84                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[84])                            /* 0x54025150 */
#define PPC1_R_ADDR85                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[85])                            /* 0x54025154 */
#define PPC1_R_ADDR86                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[86])                            /* 0x54025158 */
#define PPC1_R_ADDR87                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[87])                            /* 0x5402515C */
#define PPC1_R_ADDR88                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[88])                            /* 0x54025160 */
#define PPC1_R_ADDR89                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[89])                            /* 0x54025164 */
#define PPC1_R_ADDR90                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[90])                            /* 0x54025168 */
#define PPC1_R_ADDR91                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[91])                            /* 0x5402516C */
#define PPC1_R_ADDR92                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[92])                            /* 0x54025170 */
#define PPC1_R_ADDR93                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[93])                            /* 0x54025174 */
#define PPC1_R_ADDR94                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[94])                            /* 0x54025178 */
#define PPC1_R_ADDR95                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[95])                            /* 0x5402517C */
#define PPC1_R_ADDR96                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[96])                            /* 0x54025180 */
#define PPC1_R_ADDR97                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[97])                            /* 0x54025184 */
#define PPC1_R_ADDR98                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[98])                            /* 0x54025188 */
#define PPC1_R_ADDR99                           ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[99])                            /* 0x5402518C */
#define PPC1_R_ADDR100                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[100])                           /* 0x54025190 */
#define PPC1_R_ADDR101                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[101])                           /* 0x54025194 */
#define PPC1_R_ADDR102                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[102])                           /* 0x54025198 */
#define PPC1_R_ADDR103                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[103])                           /* 0x5402519C */
#define PPC1_R_ADDR104                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[104])                           /* 0x540251A0 */
#define PPC1_R_ADDR105                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[105])                           /* 0x540251A4 */
#define PPC1_R_ADDR106                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[106])                           /* 0x540251A8 */
#define PPC1_R_ADDR107                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[107])                           /* 0x540251AC */
#define PPC1_R_ADDR108                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[108])                           /* 0x540251B0 */
#define PPC1_R_ADDR109                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[109])                           /* 0x540251B4 */
#define PPC1_R_ADDR110                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[110])                           /* 0x540251B8 */
#define PPC1_R_ADDR111                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[111])                           /* 0x540251BC */
#define PPC1_R_ADDR112                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[112])                           /* 0x540251C0 */
#define PPC1_R_ADDR113                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[113])                           /* 0x540251C4 */
#define PPC1_R_ADDR114                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[114])                           /* 0x540251C8 */
#define PPC1_R_ADDR115                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[115])                           /* 0x540251CC */
#define PPC1_R_ADDR116                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[116])                           /* 0x540251D0 */
#define PPC1_R_ADDR117                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[117])                           /* 0x540251D4 */
#define PPC1_R_ADDR118                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[118])                           /* 0x540251D8 */
#define PPC1_R_ADDR119                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[119])                           /* 0x540251DC */
#define PPC1_R_ADDR120                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[120])                           /* 0x540251E0 */
#define PPC1_R_ADDR121                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[121])                           /* 0x540251E4 */
#define PPC1_R_ADDR122                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[122])                           /* 0x540251E8 */
#define PPC1_R_ADDR123                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[123])                           /* 0x540251EC */
#define PPC1_R_ADDR124                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[124])                           /* 0x540251F0 */
#define PPC1_R_ADDR125                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[125])                           /* 0x540251F4 */
#define PPC1_R_ADDR126                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[126])                           /* 0x540251F8 */
#define PPC1_R_ADDR127                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[127])                           /* 0x540251FC */
#define PPC1_R_ADDR128                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[128])                           /* 0x54025200 */
#define PPC1_R_ADDR129                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[129])                           /* 0x54025204 */
#define PPC1_R_ADDR130                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[130])                           /* 0x54025208 */
#define PPC1_R_ADDR131                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[131])                           /* 0x5402520C */
#define PPC1_R_ADDR132                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[132])                           /* 0x54025210 */
#define PPC1_R_ADDR133                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[133])                           /* 0x54025214 */
#define PPC1_R_ADDR134                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[134])                           /* 0x54025218 */
#define PPC1_R_ADDR135                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[135])                           /* 0x5402521C */
#define PPC1_R_ADDR136                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[136])                           /* 0x54025220 */
#define PPC1_R_ADDR137                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[137])                           /* 0x54025224 */
#define PPC1_R_ADDR138                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[138])                           /* 0x54025228 */
#define PPC1_R_ADDR139                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[139])                           /* 0x5402522C */
#define PPC1_R_ADDR140                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[140])                           /* 0x54025230 */
#define PPC1_R_ADDR141                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[141])                           /* 0x54025234 */
#define PPC1_R_ADDR142                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[142])                           /* 0x54025238 */
#define PPC1_R_ADDR143                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[143])                           /* 0x5402523C */
#define PPC1_R_ADDR144                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[144])                           /* 0x54025240 */
#define PPC1_R_ADDR145                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[145])                           /* 0x54025244 */
#define PPC1_R_ADDR146                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[146])                           /* 0x54025248 */
#define PPC1_R_ADDR147                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[147])                           /* 0x5402524C */
#define PPC1_R_ADDR148                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[148])                           /* 0x54025250 */
#define PPC1_R_ADDR149                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[149])                           /* 0x54025254 */
#define PPC1_R_ADDR150                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[150])                           /* 0x54025258 */
#define PPC1_R_ADDR151                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[151])                           /* 0x5402525C */
#define PPC1_R_ADDR152                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[152])                           /* 0x54025260 */
#define PPC1_R_ADDR153                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[153])                           /* 0x54025264 */
#define PPC1_R_ADDR154                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[154])                           /* 0x54025268 */
#define PPC1_R_ADDR155                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[155])                           /* 0x5402526C */
#define PPC1_R_ADDR156                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[156])                           /* 0x54025270 */
#define PPC1_R_ADDR157                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[157])                           /* 0x54025274 */
#define PPC1_R_ADDR158                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[158])                           /* 0x54025278 */
#define PPC1_R_ADDR159                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[159])                           /* 0x5402527C */
#define PPC1_R_ADDR160                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[160])                           /* 0x54025280 */
#define PPC1_R_ADDR161                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[161])                           /* 0x54025284 */
#define PPC1_R_ADDR162                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[162])                           /* 0x54025288 */
#define PPC1_R_ADDR163                          ((PPC_R_ADDR_Type*) &PPC1->R_ADDR[163])                           /* 0x5402528C */
#define PPC0_R_ATT0                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[0])                               /* 0x52026000 */
#define PPC0_R_ATT1                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[1])                               /* 0x52026004 */
#define PPC0_R_ATT2                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[2])                               /* 0x52026008 */
#define PPC0_R_ATT3                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[3])                               /* 0x5202600C */
#define PPC0_R_ATT4                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[4])                               /* 0x52026010 */
#define PPC0_R_ATT5                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[5])                               /* 0x52026014 */
#define PPC0_R_ATT6                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[6])                               /* 0x52026018 */
#define PPC0_R_ATT7                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[7])                               /* 0x5202601C */
#define PPC0_R_ATT8                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[8])                               /* 0x52026020 */
#define PPC0_R_ATT9                             ((PPC_R_ATT_Type*) &PPC0->R_ATT[9])                               /* 0x52026024 */
#define PPC0_R_ATT10                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[10])                              /* 0x52026028 */
#define PPC0_R_ATT11                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[11])                              /* 0x5202602C */
#define PPC0_R_ATT12                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[12])                              /* 0x52026030 */
#define PPC0_R_ATT13                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[13])                              /* 0x52026034 */
#define PPC0_R_ATT14                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[14])                              /* 0x52026038 */
#define PPC0_R_ATT15                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[15])                              /* 0x5202603C */
#define PPC0_R_ATT16                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[16])                              /* 0x52026040 */
#define PPC0_R_ATT17                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[17])                              /* 0x52026044 */
#define PPC0_R_ATT18                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[18])                              /* 0x52026048 */
#define PPC0_R_ATT19                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[19])                              /* 0x5202604C */
#define PPC0_R_ATT20                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[20])                              /* 0x52026050 */
#define PPC0_R_ATT21                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[21])                              /* 0x52026054 */
#define PPC0_R_ATT22                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[22])                              /* 0x52026058 */
#define PPC0_R_ATT23                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[23])                              /* 0x5202605C */
#define PPC0_R_ATT24                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[24])                              /* 0x52026060 */
#define PPC0_R_ATT25                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[25])                              /* 0x52026064 */
#define PPC0_R_ATT26                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[26])                              /* 0x52026068 */
#define PPC0_R_ATT27                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[27])                              /* 0x5202606C */
#define PPC0_R_ATT28                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[28])                              /* 0x52026070 */
#define PPC0_R_ATT29                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[29])                              /* 0x52026074 */
#define PPC0_R_ATT30                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[30])                              /* 0x52026078 */
#define PPC0_R_ATT31                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[31])                              /* 0x5202607C */
#define PPC0_R_ATT32                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[32])                              /* 0x52026080 */
#define PPC0_R_ATT33                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[33])                              /* 0x52026084 */
#define PPC0_R_ATT34                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[34])                              /* 0x52026088 */
#define PPC0_R_ATT35                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[35])                              /* 0x5202608C */
#define PPC0_R_ATT36                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[36])                              /* 0x52026090 */
#define PPC0_R_ATT37                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[37])                              /* 0x52026094 */
#define PPC0_R_ATT38                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[38])                              /* 0x52026098 */
#define PPC0_R_ATT39                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[39])                              /* 0x5202609C */
#define PPC0_R_ATT40                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[40])                              /* 0x520260A0 */
#define PPC0_R_ATT41                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[41])                              /* 0x520260A4 */
#define PPC0_R_ATT42                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[42])                              /* 0x520260A8 */
#define PPC0_R_ATT43                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[43])                              /* 0x520260AC */
#define PPC0_R_ATT44                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[44])                              /* 0x520260B0 */
#define PPC0_R_ATT45                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[45])                              /* 0x520260B4 */
#define PPC0_R_ATT46                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[46])                              /* 0x520260B8 */
#define PPC0_R_ATT47                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[47])                              /* 0x520260BC */
#define PPC0_R_ATT48                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[48])                              /* 0x520260C0 */
#define PPC0_R_ATT49                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[49])                              /* 0x520260C4 */
#define PPC0_R_ATT50                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[50])                              /* 0x520260C8 */
#define PPC0_R_ATT51                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[51])                              /* 0x520260CC */
#define PPC0_R_ATT52                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[52])                              /* 0x520260D0 */
#define PPC0_R_ATT53                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[53])                              /* 0x520260D4 */
#define PPC0_R_ATT54                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[54])                              /* 0x520260D8 */
#define PPC0_R_ATT55                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[55])                              /* 0x520260DC */
#define PPC0_R_ATT56                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[56])                              /* 0x520260E0 */
#define PPC0_R_ATT57                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[57])                              /* 0x520260E4 */
#define PPC0_R_ATT58                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[58])                              /* 0x520260E8 */
#define PPC0_R_ATT59                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[59])                              /* 0x520260EC */
#define PPC0_R_ATT60                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[60])                              /* 0x520260F0 */
#define PPC0_R_ATT61                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[61])                              /* 0x520260F4 */
#define PPC0_R_ATT62                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[62])                              /* 0x520260F8 */
#define PPC0_R_ATT63                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[63])                              /* 0x520260FC */
#define PPC0_R_ATT64                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[64])                              /* 0x52026100 */
#define PPC0_R_ATT65                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[65])                              /* 0x52026104 */
#define PPC0_R_ATT66                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[66])                              /* 0x52026108 */
#define PPC0_R_ATT67                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[67])                              /* 0x5202610C */
#define PPC0_R_ATT68                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[68])                              /* 0x52026110 */
#define PPC0_R_ATT69                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[69])                              /* 0x52026114 */
#define PPC0_R_ATT70                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[70])                              /* 0x52026118 */
#define PPC0_R_ATT71                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[71])                              /* 0x5202611C */
#define PPC0_R_ATT72                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[72])                              /* 0x52026120 */
#define PPC0_R_ATT73                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[73])                              /* 0x52026124 */
#define PPC0_R_ATT74                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[74])                              /* 0x52026128 */
#define PPC0_R_ATT75                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[75])                              /* 0x5202612C */
#define PPC0_R_ATT76                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[76])                              /* 0x52026130 */
#define PPC0_R_ATT77                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[77])                              /* 0x52026134 */
#define PPC0_R_ATT78                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[78])                              /* 0x52026138 */
#define PPC0_R_ATT79                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[79])                              /* 0x5202613C */
#define PPC0_R_ATT80                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[80])                              /* 0x52026140 */
#define PPC0_R_ATT81                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[81])                              /* 0x52026144 */
#define PPC0_R_ATT82                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[82])                              /* 0x52026148 */
#define PPC0_R_ATT83                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[83])                              /* 0x5202614C */
#define PPC0_R_ATT84                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[84])                              /* 0x52026150 */
#define PPC0_R_ATT85                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[85])                              /* 0x52026154 */
#define PPC0_R_ATT86                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[86])                              /* 0x52026158 */
#define PPC0_R_ATT87                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[87])                              /* 0x5202615C */
#define PPC0_R_ATT88                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[88])                              /* 0x52026160 */
#define PPC0_R_ATT89                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[89])                              /* 0x52026164 */
#define PPC0_R_ATT90                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[90])                              /* 0x52026168 */
#define PPC0_R_ATT91                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[91])                              /* 0x5202616C */
#define PPC0_R_ATT92                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[92])                              /* 0x52026170 */
#define PPC0_R_ATT93                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[93])                              /* 0x52026174 */
#define PPC0_R_ATT94                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[94])                              /* 0x52026178 */
#define PPC0_R_ATT95                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[95])                              /* 0x5202617C */
#define PPC0_R_ATT96                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[96])                              /* 0x52026180 */
#define PPC0_R_ATT97                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[97])                              /* 0x52026184 */
#define PPC0_R_ATT98                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[98])                              /* 0x52026188 */
#define PPC0_R_ATT99                            ((PPC_R_ATT_Type*) &PPC0->R_ATT[99])                              /* 0x5202618C */
#define PPC0_R_ATT100                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[100])                             /* 0x52026190 */
#define PPC0_R_ATT101                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[101])                             /* 0x52026194 */
#define PPC0_R_ATT102                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[102])                             /* 0x52026198 */
#define PPC0_R_ATT103                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[103])                             /* 0x5202619C */
#define PPC0_R_ATT104                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[104])                             /* 0x520261A0 */
#define PPC0_R_ATT105                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[105])                             /* 0x520261A4 */
#define PPC0_R_ATT106                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[106])                             /* 0x520261A8 */
#define PPC0_R_ATT107                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[107])                             /* 0x520261AC */
#define PPC0_R_ATT108                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[108])                             /* 0x520261B0 */
#define PPC0_R_ATT109                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[109])                             /* 0x520261B4 */
#define PPC0_R_ATT110                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[110])                             /* 0x520261B8 */
#define PPC0_R_ATT111                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[111])                             /* 0x520261BC */
#define PPC0_R_ATT112                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[112])                             /* 0x520261C0 */
#define PPC0_R_ATT113                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[113])                             /* 0x520261C4 */
#define PPC0_R_ATT114                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[114])                             /* 0x520261C8 */
#define PPC0_R_ATT115                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[115])                             /* 0x520261CC */
#define PPC0_R_ATT116                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[116])                             /* 0x520261D0 */
#define PPC0_R_ATT117                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[117])                             /* 0x520261D4 */
#define PPC0_R_ATT118                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[118])                             /* 0x520261D8 */
#define PPC0_R_ATT119                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[119])                             /* 0x520261DC */
#define PPC0_R_ATT120                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[120])                             /* 0x520261E0 */
#define PPC0_R_ATT121                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[121])                             /* 0x520261E4 */
#define PPC0_R_ATT122                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[122])                             /* 0x520261E8 */
#define PPC0_R_ATT123                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[123])                             /* 0x520261EC */
#define PPC0_R_ATT124                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[124])                             /* 0x520261F0 */
#define PPC0_R_ATT125                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[125])                             /* 0x520261F4 */
#define PPC0_R_ATT126                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[126])                             /* 0x520261F8 */
#define PPC0_R_ATT127                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[127])                             /* 0x520261FC */
#define PPC0_R_ATT128                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[128])                             /* 0x52026200 */
#define PPC0_R_ATT129                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[129])                             /* 0x52026204 */
#define PPC0_R_ATT130                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[130])                             /* 0x52026208 */
#define PPC0_R_ATT131                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[131])                             /* 0x5202620C */
#define PPC0_R_ATT132                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[132])                             /* 0x52026210 */
#define PPC0_R_ATT133                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[133])                             /* 0x52026214 */
#define PPC0_R_ATT134                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[134])                             /* 0x52026218 */
#define PPC0_R_ATT135                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[135])                             /* 0x5202621C */
#define PPC0_R_ATT136                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[136])                             /* 0x52026220 */
#define PPC0_R_ATT137                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[137])                             /* 0x52026224 */
#define PPC0_R_ATT138                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[138])                             /* 0x52026228 */
#define PPC0_R_ATT139                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[139])                             /* 0x5202622C */
#define PPC0_R_ATT140                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[140])                             /* 0x52026230 */
#define PPC0_R_ATT141                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[141])                             /* 0x52026234 */
#define PPC0_R_ATT142                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[142])                             /* 0x52026238 */
#define PPC0_R_ATT143                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[143])                             /* 0x5202623C */
#define PPC0_R_ATT144                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[144])                             /* 0x52026240 */
#define PPC0_R_ATT145                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[145])                             /* 0x52026244 */
#define PPC0_R_ATT146                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[146])                             /* 0x52026248 */
#define PPC0_R_ATT147                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[147])                             /* 0x5202624C */
#define PPC0_R_ATT148                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[148])                             /* 0x52026250 */
#define PPC0_R_ATT149                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[149])                             /* 0x52026254 */
#define PPC0_R_ATT150                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[150])                             /* 0x52026258 */
#define PPC0_R_ATT151                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[151])                             /* 0x5202625C */
#define PPC0_R_ATT152                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[152])                             /* 0x52026260 */
#define PPC0_R_ATT153                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[153])                             /* 0x52026264 */
#define PPC0_R_ATT154                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[154])                             /* 0x52026268 */
#define PPC0_R_ATT155                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[155])                             /* 0x5202626C */
#define PPC0_R_ATT156                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[156])                             /* 0x52026270 */
#define PPC0_R_ATT157                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[157])                             /* 0x52026274 */
#define PPC0_R_ATT158                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[158])                             /* 0x52026278 */
#define PPC0_R_ATT159                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[159])                             /* 0x5202627C */
#define PPC0_R_ATT160                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[160])                             /* 0x52026280 */
#define PPC0_R_ATT161                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[161])                             /* 0x52026284 */
#define PPC0_R_ATT162                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[162])                             /* 0x52026288 */
#define PPC0_R_ATT163                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[163])                             /* 0x5202628C */
#define PPC0_R_ATT164                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[164])                             /* 0x52026290 */
#define PPC0_R_ATT165                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[165])                             /* 0x52026294 */
#define PPC0_R_ATT166                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[166])                             /* 0x52026298 */
#define PPC0_R_ATT167                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[167])                             /* 0x5202629C */
#define PPC0_R_ATT168                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[168])                             /* 0x520262A0 */
#define PPC0_R_ATT169                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[169])                             /* 0x520262A4 */
#define PPC0_R_ATT170                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[170])                             /* 0x520262A8 */
#define PPC0_R_ATT171                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[171])                             /* 0x520262AC */
#define PPC0_R_ATT172                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[172])                             /* 0x520262B0 */
#define PPC0_R_ATT173                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[173])                             /* 0x520262B4 */
#define PPC0_R_ATT174                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[174])                             /* 0x520262B8 */
#define PPC0_R_ATT175                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[175])                             /* 0x520262BC */
#define PPC0_R_ATT176                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[176])                             /* 0x520262C0 */
#define PPC0_R_ATT177                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[177])                             /* 0x520262C4 */
#define PPC0_R_ATT178                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[178])                             /* 0x520262C8 */
#define PPC0_R_ATT179                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[179])                             /* 0x520262CC */
#define PPC0_R_ATT180                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[180])                             /* 0x520262D0 */
#define PPC0_R_ATT181                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[181])                             /* 0x520262D4 */
#define PPC0_R_ATT182                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[182])                             /* 0x520262D8 */
#define PPC0_R_ATT183                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[183])                             /* 0x520262DC */
#define PPC0_R_ATT184                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[184])                             /* 0x520262E0 */
#define PPC0_R_ATT185                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[185])                             /* 0x520262E4 */
#define PPC0_R_ATT186                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[186])                             /* 0x520262E8 */
#define PPC0_R_ATT187                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[187])                             /* 0x520262EC */
#define PPC0_R_ATT188                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[188])                             /* 0x520262F0 */
#define PPC0_R_ATT189                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[189])                             /* 0x520262F4 */
#define PPC0_R_ATT190                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[190])                             /* 0x520262F8 */
#define PPC0_R_ATT191                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[191])                             /* 0x520262FC */
#define PPC0_R_ATT192                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[192])                             /* 0x52026300 */
#define PPC0_R_ATT193                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[193])                             /* 0x52026304 */
#define PPC0_R_ATT194                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[194])                             /* 0x52026308 */
#define PPC0_R_ATT195                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[195])                             /* 0x5202630C */
#define PPC0_R_ATT196                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[196])                             /* 0x52026310 */
#define PPC0_R_ATT197                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[197])                             /* 0x52026314 */
#define PPC0_R_ATT198                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[198])                             /* 0x52026318 */
#define PPC0_R_ATT199                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[199])                             /* 0x5202631C */
#define PPC0_R_ATT200                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[200])                             /* 0x52026320 */
#define PPC0_R_ATT201                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[201])                             /* 0x52026324 */
#define PPC0_R_ATT202                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[202])                             /* 0x52026328 */
#define PPC0_R_ATT203                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[203])                             /* 0x5202632C */
#define PPC0_R_ATT204                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[204])                             /* 0x52026330 */
#define PPC0_R_ATT205                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[205])                             /* 0x52026334 */
#define PPC0_R_ATT206                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[206])                             /* 0x52026338 */
#define PPC0_R_ATT207                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[207])                             /* 0x5202633C */
#define PPC0_R_ATT208                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[208])                             /* 0x52026340 */
#define PPC0_R_ATT209                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[209])                             /* 0x52026344 */
#define PPC0_R_ATT210                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[210])                             /* 0x52026348 */
#define PPC0_R_ATT211                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[211])                             /* 0x5202634C */
#define PPC0_R_ATT212                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[212])                             /* 0x52026350 */
#define PPC0_R_ATT213                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[213])                             /* 0x52026354 */
#define PPC0_R_ATT214                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[214])                             /* 0x52026358 */
#define PPC0_R_ATT215                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[215])                             /* 0x5202635C */
#define PPC0_R_ATT216                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[216])                             /* 0x52026360 */
#define PPC0_R_ATT217                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[217])                             /* 0x52026364 */
#define PPC0_R_ATT218                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[218])                             /* 0x52026368 */
#define PPC0_R_ATT219                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[219])                             /* 0x5202636C */
#define PPC0_R_ATT220                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[220])                             /* 0x52026370 */
#define PPC0_R_ATT221                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[221])                             /* 0x52026374 */
#define PPC0_R_ATT222                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[222])                             /* 0x52026378 */
#define PPC0_R_ATT223                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[223])                             /* 0x5202637C */
#define PPC0_R_ATT224                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[224])                             /* 0x52026380 */
#define PPC0_R_ATT225                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[225])                             /* 0x52026384 */
#define PPC0_R_ATT226                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[226])                             /* 0x52026388 */
#define PPC0_R_ATT227                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[227])                             /* 0x5202638C */
#define PPC0_R_ATT228                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[228])                             /* 0x52026390 */
#define PPC0_R_ATT229                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[229])                             /* 0x52026394 */
#define PPC0_R_ATT230                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[230])                             /* 0x52026398 */
#define PPC0_R_ATT231                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[231])                             /* 0x5202639C */
#define PPC0_R_ATT232                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[232])                             /* 0x520263A0 */
#define PPC0_R_ATT233                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[233])                             /* 0x520263A4 */
#define PPC0_R_ATT234                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[234])                             /* 0x520263A8 */
#define PPC0_R_ATT235                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[235])                             /* 0x520263AC */
#define PPC0_R_ATT236                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[236])                             /* 0x520263B0 */
#define PPC0_R_ATT237                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[237])                             /* 0x520263B4 */
#define PPC0_R_ATT238                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[238])                             /* 0x520263B8 */
#define PPC0_R_ATT239                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[239])                             /* 0x520263BC */
#define PPC0_R_ATT240                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[240])                             /* 0x520263C0 */
#define PPC0_R_ATT241                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[241])                             /* 0x520263C4 */
#define PPC0_R_ATT242                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[242])                             /* 0x520263C8 */
#define PPC0_R_ATT243                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[243])                             /* 0x520263CC */
#define PPC0_R_ATT244                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[244])                             /* 0x520263D0 */
#define PPC0_R_ATT245                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[245])                             /* 0x520263D4 */
#define PPC0_R_ATT246                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[246])                             /* 0x520263D8 */
#define PPC0_R_ATT247                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[247])                             /* 0x520263DC */
#define PPC0_R_ATT248                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[248])                             /* 0x520263E0 */
#define PPC0_R_ATT249                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[249])                             /* 0x520263E4 */
#define PPC0_R_ATT250                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[250])                             /* 0x520263E8 */
#define PPC0_R_ATT251                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[251])                             /* 0x520263EC */
#define PPC0_R_ATT252                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[252])                             /* 0x520263F0 */
#define PPC0_R_ATT253                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[253])                             /* 0x520263F4 */
#define PPC0_R_ATT254                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[254])                             /* 0x520263F8 */
#define PPC0_R_ATT255                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[255])                             /* 0x520263FC */
#define PPC0_R_ATT256                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[256])                             /* 0x52026400 */
#define PPC0_R_ATT257                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[257])                             /* 0x52026404 */
#define PPC0_R_ATT258                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[258])                             /* 0x52026408 */
#define PPC0_R_ATT259                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[259])                             /* 0x5202640C */
#define PPC0_R_ATT260                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[260])                             /* 0x52026410 */
#define PPC0_R_ATT261                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[261])                             /* 0x52026414 */
#define PPC0_R_ATT262                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[262])                             /* 0x52026418 */
#define PPC0_R_ATT263                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[263])                             /* 0x5202641C */
#define PPC0_R_ATT264                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[264])                             /* 0x52026420 */
#define PPC0_R_ATT265                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[265])                             /* 0x52026424 */
#define PPC0_R_ATT266                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[266])                             /* 0x52026428 */
#define PPC0_R_ATT267                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[267])                             /* 0x5202642C */
#define PPC0_R_ATT268                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[268])                             /* 0x52026430 */
#define PPC0_R_ATT269                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[269])                             /* 0x52026434 */
#define PPC0_R_ATT270                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[270])                             /* 0x52026438 */
#define PPC0_R_ATT271                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[271])                             /* 0x5202643C */
#define PPC0_R_ATT272                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[272])                             /* 0x52026440 */
#define PPC0_R_ATT273                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[273])                             /* 0x52026444 */
#define PPC0_R_ATT274                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[274])                             /* 0x52026448 */
#define PPC0_R_ATT275                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[275])                             /* 0x5202644C */
#define PPC0_R_ATT276                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[276])                             /* 0x52026450 */
#define PPC0_R_ATT277                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[277])                             /* 0x52026454 */
#define PPC0_R_ATT278                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[278])                             /* 0x52026458 */
#define PPC0_R_ATT279                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[279])                             /* 0x5202645C */
#define PPC0_R_ATT280                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[280])                             /* 0x52026460 */
#define PPC0_R_ATT281                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[281])                             /* 0x52026464 */
#define PPC0_R_ATT282                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[282])                             /* 0x52026468 */
#define PPC0_R_ATT283                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[283])                             /* 0x5202646C */
#define PPC0_R_ATT284                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[284])                             /* 0x52026470 */
#define PPC0_R_ATT285                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[285])                             /* 0x52026474 */
#define PPC0_R_ATT286                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[286])                             /* 0x52026478 */
#define PPC0_R_ATT287                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[287])                             /* 0x5202647C */
#define PPC0_R_ATT288                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[288])                             /* 0x52026480 */
#define PPC0_R_ATT289                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[289])                             /* 0x52026484 */
#define PPC0_R_ATT290                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[290])                             /* 0x52026488 */
#define PPC0_R_ATT291                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[291])                             /* 0x5202648C */
#define PPC0_R_ATT292                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[292])                             /* 0x52026490 */
#define PPC0_R_ATT293                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[293])                             /* 0x52026494 */
#define PPC0_R_ATT294                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[294])                             /* 0x52026498 */
#define PPC0_R_ATT295                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[295])                             /* 0x5202649C */
#define PPC0_R_ATT296                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[296])                             /* 0x520264A0 */
#define PPC0_R_ATT297                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[297])                             /* 0x520264A4 */
#define PPC0_R_ATT298                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[298])                             /* 0x520264A8 */
#define PPC0_R_ATT299                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[299])                             /* 0x520264AC */
#define PPC0_R_ATT300                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[300])                             /* 0x520264B0 */
#define PPC0_R_ATT301                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[301])                             /* 0x520264B4 */
#define PPC0_R_ATT302                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[302])                             /* 0x520264B8 */
#define PPC0_R_ATT303                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[303])                             /* 0x520264BC */
#define PPC0_R_ATT304                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[304])                             /* 0x520264C0 */
#define PPC0_R_ATT305                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[305])                             /* 0x520264C4 */
#define PPC0_R_ATT306                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[306])                             /* 0x520264C8 */
#define PPC0_R_ATT307                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[307])                             /* 0x520264CC */
#define PPC0_R_ATT308                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[308])                             /* 0x520264D0 */
#define PPC0_R_ATT309                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[309])                             /* 0x520264D4 */
#define PPC0_R_ATT310                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[310])                             /* 0x520264D8 */
#define PPC0_R_ATT311                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[311])                             /* 0x520264DC */
#define PPC0_R_ATT312                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[312])                             /* 0x520264E0 */
#define PPC0_R_ATT313                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[313])                             /* 0x520264E4 */
#define PPC0_R_ATT314                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[314])                             /* 0x520264E8 */
#define PPC0_R_ATT315                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[315])                             /* 0x520264EC */
#define PPC0_R_ATT316                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[316])                             /* 0x520264F0 */
#define PPC0_R_ATT317                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[317])                             /* 0x520264F4 */
#define PPC0_R_ATT318                           ((PPC_R_ATT_Type*) &PPC0->R_ATT[318])                             /* 0x520264F8 */
#define PPC1_R_ATT0                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[0])                               /* 0x54026000 */
#define PPC1_R_ATT1                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[1])                               /* 0x54026004 */
#define PPC1_R_ATT2                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[2])                               /* 0x54026008 */
#define PPC1_R_ATT3                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[3])                               /* 0x5402600C */
#define PPC1_R_ATT4                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[4])                               /* 0x54026010 */
#define PPC1_R_ATT5                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[5])                               /* 0x54026014 */
#define PPC1_R_ATT6                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[6])                               /* 0x54026018 */
#define PPC1_R_ATT7                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[7])                               /* 0x5402601C */
#define PPC1_R_ATT8                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[8])                               /* 0x54026020 */
#define PPC1_R_ATT9                             ((PPC_R_ATT_Type*) &PPC1->R_ATT[9])                               /* 0x54026024 */
#define PPC1_R_ATT10                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[10])                              /* 0x54026028 */
#define PPC1_R_ATT11                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[11])                              /* 0x5402602C */
#define PPC1_R_ATT12                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[12])                              /* 0x54026030 */
#define PPC1_R_ATT13                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[13])                              /* 0x54026034 */
#define PPC1_R_ATT14                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[14])                              /* 0x54026038 */
#define PPC1_R_ATT15                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[15])                              /* 0x5402603C */
#define PPC1_R_ATT16                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[16])                              /* 0x54026040 */
#define PPC1_R_ATT17                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[17])                              /* 0x54026044 */
#define PPC1_R_ATT18                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[18])                              /* 0x54026048 */
#define PPC1_R_ATT19                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[19])                              /* 0x5402604C */
#define PPC1_R_ATT20                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[20])                              /* 0x54026050 */
#define PPC1_R_ATT21                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[21])                              /* 0x54026054 */
#define PPC1_R_ATT22                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[22])                              /* 0x54026058 */
#define PPC1_R_ATT23                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[23])                              /* 0x5402605C */
#define PPC1_R_ATT24                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[24])                              /* 0x54026060 */
#define PPC1_R_ATT25                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[25])                              /* 0x54026064 */
#define PPC1_R_ATT26                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[26])                              /* 0x54026068 */
#define PPC1_R_ATT27                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[27])                              /* 0x5402606C */
#define PPC1_R_ATT28                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[28])                              /* 0x54026070 */
#define PPC1_R_ATT29                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[29])                              /* 0x54026074 */
#define PPC1_R_ATT30                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[30])                              /* 0x54026078 */
#define PPC1_R_ATT31                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[31])                              /* 0x5402607C */
#define PPC1_R_ATT32                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[32])                              /* 0x54026080 */
#define PPC1_R_ATT33                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[33])                              /* 0x54026084 */
#define PPC1_R_ATT34                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[34])                              /* 0x54026088 */
#define PPC1_R_ATT35                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[35])                              /* 0x5402608C */
#define PPC1_R_ATT36                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[36])                              /* 0x54026090 */
#define PPC1_R_ATT37                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[37])                              /* 0x54026094 */
#define PPC1_R_ATT38                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[38])                              /* 0x54026098 */
#define PPC1_R_ATT39                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[39])                              /* 0x5402609C */
#define PPC1_R_ATT40                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[40])                              /* 0x540260A0 */
#define PPC1_R_ATT41                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[41])                              /* 0x540260A4 */
#define PPC1_R_ATT42                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[42])                              /* 0x540260A8 */
#define PPC1_R_ATT43                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[43])                              /* 0x540260AC */
#define PPC1_R_ATT44                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[44])                              /* 0x540260B0 */
#define PPC1_R_ATT45                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[45])                              /* 0x540260B4 */
#define PPC1_R_ATT46                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[46])                              /* 0x540260B8 */
#define PPC1_R_ATT47                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[47])                              /* 0x540260BC */
#define PPC1_R_ATT48                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[48])                              /* 0x540260C0 */
#define PPC1_R_ATT49                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[49])                              /* 0x540260C4 */
#define PPC1_R_ATT50                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[50])                              /* 0x540260C8 */
#define PPC1_R_ATT51                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[51])                              /* 0x540260CC */
#define PPC1_R_ATT52                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[52])                              /* 0x540260D0 */
#define PPC1_R_ATT53                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[53])                              /* 0x540260D4 */
#define PPC1_R_ATT54                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[54])                              /* 0x540260D8 */
#define PPC1_R_ATT55                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[55])                              /* 0x540260DC */
#define PPC1_R_ATT56                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[56])                              /* 0x540260E0 */
#define PPC1_R_ATT57                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[57])                              /* 0x540260E4 */
#define PPC1_R_ATT58                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[58])                              /* 0x540260E8 */
#define PPC1_R_ATT59                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[59])                              /* 0x540260EC */
#define PPC1_R_ATT60                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[60])                              /* 0x540260F0 */
#define PPC1_R_ATT61                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[61])                              /* 0x540260F4 */
#define PPC1_R_ATT62                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[62])                              /* 0x540260F8 */
#define PPC1_R_ATT63                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[63])                              /* 0x540260FC */
#define PPC1_R_ATT64                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[64])                              /* 0x54026100 */
#define PPC1_R_ATT65                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[65])                              /* 0x54026104 */
#define PPC1_R_ATT66                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[66])                              /* 0x54026108 */
#define PPC1_R_ATT67                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[67])                              /* 0x5402610C */
#define PPC1_R_ATT68                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[68])                              /* 0x54026110 */
#define PPC1_R_ATT69                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[69])                              /* 0x54026114 */
#define PPC1_R_ATT70                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[70])                              /* 0x54026118 */
#define PPC1_R_ATT71                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[71])                              /* 0x5402611C */
#define PPC1_R_ATT72                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[72])                              /* 0x54026120 */
#define PPC1_R_ATT73                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[73])                              /* 0x54026124 */
#define PPC1_R_ATT74                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[74])                              /* 0x54026128 */
#define PPC1_R_ATT75                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[75])                              /* 0x5402612C */
#define PPC1_R_ATT76                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[76])                              /* 0x54026130 */
#define PPC1_R_ATT77                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[77])                              /* 0x54026134 */
#define PPC1_R_ATT78                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[78])                              /* 0x54026138 */
#define PPC1_R_ATT79                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[79])                              /* 0x5402613C */
#define PPC1_R_ATT80                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[80])                              /* 0x54026140 */
#define PPC1_R_ATT81                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[81])                              /* 0x54026144 */
#define PPC1_R_ATT82                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[82])                              /* 0x54026148 */
#define PPC1_R_ATT83                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[83])                              /* 0x5402614C */
#define PPC1_R_ATT84                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[84])                              /* 0x54026150 */
#define PPC1_R_ATT85                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[85])                              /* 0x54026154 */
#define PPC1_R_ATT86                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[86])                              /* 0x54026158 */
#define PPC1_R_ATT87                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[87])                              /* 0x5402615C */
#define PPC1_R_ATT88                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[88])                              /* 0x54026160 */
#define PPC1_R_ATT89                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[89])                              /* 0x54026164 */
#define PPC1_R_ATT90                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[90])                              /* 0x54026168 */
#define PPC1_R_ATT91                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[91])                              /* 0x5402616C */
#define PPC1_R_ATT92                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[92])                              /* 0x54026170 */
#define PPC1_R_ATT93                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[93])                              /* 0x54026174 */
#define PPC1_R_ATT94                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[94])                              /* 0x54026178 */
#define PPC1_R_ATT95                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[95])                              /* 0x5402617C */
#define PPC1_R_ATT96                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[96])                              /* 0x54026180 */
#define PPC1_R_ATT97                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[97])                              /* 0x54026184 */
#define PPC1_R_ATT98                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[98])                              /* 0x54026188 */
#define PPC1_R_ATT99                            ((PPC_R_ATT_Type*) &PPC1->R_ATT[99])                              /* 0x5402618C */
#define PPC1_R_ATT100                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[100])                             /* 0x54026190 */
#define PPC1_R_ATT101                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[101])                             /* 0x54026194 */
#define PPC1_R_ATT102                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[102])                             /* 0x54026198 */
#define PPC1_R_ATT103                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[103])                             /* 0x5402619C */
#define PPC1_R_ATT104                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[104])                             /* 0x540261A0 */
#define PPC1_R_ATT105                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[105])                             /* 0x540261A4 */
#define PPC1_R_ATT106                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[106])                             /* 0x540261A8 */
#define PPC1_R_ATT107                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[107])                             /* 0x540261AC */
#define PPC1_R_ATT108                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[108])                             /* 0x540261B0 */
#define PPC1_R_ATT109                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[109])                             /* 0x540261B4 */
#define PPC1_R_ATT110                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[110])                             /* 0x540261B8 */
#define PPC1_R_ATT111                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[111])                             /* 0x540261BC */
#define PPC1_R_ATT112                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[112])                             /* 0x540261C0 */
#define PPC1_R_ATT113                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[113])                             /* 0x540261C4 */
#define PPC1_R_ATT114                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[114])                             /* 0x540261C8 */
#define PPC1_R_ATT115                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[115])                             /* 0x540261CC */
#define PPC1_R_ATT116                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[116])                             /* 0x540261D0 */
#define PPC1_R_ATT117                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[117])                             /* 0x540261D4 */
#define PPC1_R_ATT118                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[118])                             /* 0x540261D8 */
#define PPC1_R_ATT119                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[119])                             /* 0x540261DC */
#define PPC1_R_ATT120                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[120])                             /* 0x540261E0 */
#define PPC1_R_ATT121                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[121])                             /* 0x540261E4 */
#define PPC1_R_ATT122                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[122])                             /* 0x540261E8 */
#define PPC1_R_ATT123                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[123])                             /* 0x540261EC */
#define PPC1_R_ATT124                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[124])                             /* 0x540261F0 */
#define PPC1_R_ATT125                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[125])                             /* 0x540261F4 */
#define PPC1_R_ATT126                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[126])                             /* 0x540261F8 */
#define PPC1_R_ATT127                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[127])                             /* 0x540261FC */
#define PPC1_R_ATT128                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[128])                             /* 0x54026200 */
#define PPC1_R_ATT129                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[129])                             /* 0x54026204 */
#define PPC1_R_ATT130                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[130])                             /* 0x54026208 */
#define PPC1_R_ATT131                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[131])                             /* 0x5402620C */
#define PPC1_R_ATT132                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[132])                             /* 0x54026210 */
#define PPC1_R_ATT133                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[133])                             /* 0x54026214 */
#define PPC1_R_ATT134                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[134])                             /* 0x54026218 */
#define PPC1_R_ATT135                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[135])                             /* 0x5402621C */
#define PPC1_R_ATT136                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[136])                             /* 0x54026220 */
#define PPC1_R_ATT137                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[137])                             /* 0x54026224 */
#define PPC1_R_ATT138                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[138])                             /* 0x54026228 */
#define PPC1_R_ATT139                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[139])                             /* 0x5402622C */
#define PPC1_R_ATT140                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[140])                             /* 0x54026230 */
#define PPC1_R_ATT141                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[141])                             /* 0x54026234 */
#define PPC1_R_ATT142                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[142])                             /* 0x54026238 */
#define PPC1_R_ATT143                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[143])                             /* 0x5402623C */
#define PPC1_R_ATT144                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[144])                             /* 0x54026240 */
#define PPC1_R_ATT145                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[145])                             /* 0x54026244 */
#define PPC1_R_ATT146                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[146])                             /* 0x54026248 */
#define PPC1_R_ATT147                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[147])                             /* 0x5402624C */
#define PPC1_R_ATT148                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[148])                             /* 0x54026250 */
#define PPC1_R_ATT149                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[149])                             /* 0x54026254 */
#define PPC1_R_ATT150                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[150])                             /* 0x54026258 */
#define PPC1_R_ATT151                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[151])                             /* 0x5402625C */
#define PPC1_R_ATT152                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[152])                             /* 0x54026260 */
#define PPC1_R_ATT153                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[153])                             /* 0x54026264 */
#define PPC1_R_ATT154                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[154])                             /* 0x54026268 */
#define PPC1_R_ATT155                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[155])                             /* 0x5402626C */
#define PPC1_R_ATT156                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[156])                             /* 0x54026270 */
#define PPC1_R_ATT157                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[157])                             /* 0x54026274 */
#define PPC1_R_ATT158                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[158])                             /* 0x54026278 */
#define PPC1_R_ATT159                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[159])                             /* 0x5402627C */
#define PPC1_R_ATT160                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[160])                             /* 0x54026280 */
#define PPC1_R_ATT161                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[161])                             /* 0x54026284 */
#define PPC1_R_ATT162                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[162])                             /* 0x54026288 */
#define PPC1_R_ATT163                           ((PPC_R_ATT_Type*) &PPC1->R_ATT[163])                             /* 0x5402628C */

/*******************************************************************************
*                                  PERI_PCLK
*******************************************************************************/

#define PERI_PCLK0_BASE                         0x52040000UL
#define PERI_PCLK1_BASE                         0x54040000UL
#define PERI_PCLK0                              ((PERI_PCLK_Type*) PERI_PCLK0_BASE)                               /* 0x52040000 */
#define PERI_PCLK1                              ((PERI_PCLK_Type*) PERI_PCLK1_BASE)                               /* 0x54040000 */
#define PERI_PCLK0_GR0                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[0])                         /* 0x52040000 */
#define PERI_PCLK0_GR1                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[1])                         /* 0x52042000 */
#define PERI_PCLK0_GR2                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[2])                         /* 0x52044000 */
#define PERI_PCLK0_GR3                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[3])                         /* 0x52046000 */
#define PERI_PCLK0_GR4                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[4])                         /* 0x52048000 */
#define PERI_PCLK0_GR5                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[5])                         /* 0x5204A000 */
#define PERI_PCLK0_GR6                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[6])                         /* 0x5204C000 */
#define PERI_PCLK0_GR7                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[7])                         /* 0x5204E000 */
#define PERI_PCLK0_GR8                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[8])                         /* 0x52050000 */
#define PERI_PCLK0_GR9                          ((PERI_PCLK_GR_Type*) &PERI_PCLK0->GR[9])                         /* 0x52052000 */
#define PERI_PCLK1_GR0                          ((PERI_PCLK_GR_Type*) &PERI_PCLK1->GR[0])                         /* 0x54040000 */
#define PERI_PCLK1_GR1                          ((PERI_PCLK_GR_Type*) &PERI_PCLK1->GR[1])                         /* 0x54042000 */
#define PERI_PCLK1_GR2                          ((PERI_PCLK_GR_Type*) &PERI_PCLK1->GR[2])                         /* 0x54044000 */
#define PERI_PCLK1_GR3                          ((PERI_PCLK_GR_Type*) &PERI_PCLK1->GR[3])                         /* 0x54046000 */
#define PERI_PCLK1_GR4                          ((PERI_PCLK_GR_Type*) &PERI_PCLK1->GR[4])                         /* 0x54048000 */
#define PERI_PCLK1_GR5                          ((PERI_PCLK_GR_Type*) &PERI_PCLK1->GR[5])                         /* 0x5404A000 */

/*******************************************************************************
*                                    RRAMC
*******************************************************************************/

#define RRAMC0_BASE                             0x52200000UL
#define RRAMC0                                  ((RRAMC_Type*) RRAMC0_BASE)                                       /* 0x52200000 */
#define RRAMC0_RRAM_EXTRA_AREA                  ((RRAMC_RRAM_EXTRA_AREA_Type*) &RRAMC0->RRAM_EXTRA_AREA)          /* 0x52200000 */
#define RRAMC0_RRAMC0                           ((RRAMC_RRAMC_Type*) &RRAMC0->RRAMC[0])                           /* 0x52210000 */
#define RRAMC0_MPC0                             ((RRAMC_MPC_Type*) &RRAMC0->MPC[0])                               /* 0x52211000 */
#define RRAMC0_MPC1                             ((RRAMC_MPC_Type*) &RRAMC0->MPC[1])                               /* 0x52212000 */
#define RRAMC0_RRAM_SFR                         ((RRAMC_RRAM_SFR_Type*) &RRAMC0->RRAM_SFR)                        /* 0x52213000 */

/*******************************************************************************
*                                   RAMC_PPU
*******************************************************************************/

#define RAMC_PPU0_BASE                          0x52220000UL
#define RAMC_PPU1_BASE                          0x52221000UL
#define RAMC_PPU0                               ((RAMC_PPU_Type*) RAMC_PPU0_BASE)                                 /* 0x52220000 */
#define RAMC_PPU1                               ((RAMC_PPU_Type*) RAMC_PPU1_BASE)                                 /* 0x52221000 */

/*******************************************************************************
*                                    ICACHE
*******************************************************************************/

#define ICACHE0_BASE                            0x52223000UL
#define ICACHE0                                 ((ICACHE_Type*) ICACHE0_BASE)                                     /* 0x52223000 */

/*******************************************************************************
*                                  CPUSS_PPU
*******************************************************************************/

#define CPUSS_PPU_BASE                          0x52225000UL
#define CPUSS_PPU                               ((CPUSS_PPU_Type*) CPUSS_PPU_BASE)                                /* 0x52225000 */

/*******************************************************************************
*                                     RAMC
*******************************************************************************/

#define RAMC0_BASE                              0x52230000UL
#define RAMC1_BASE                              0x52240000UL
#define RAMC0                                   ((RAMC_Type*) RAMC0_BASE)                                         /* 0x52230000 */
#define RAMC1                                   ((RAMC_Type*) RAMC1_BASE)                                         /* 0x52240000 */
#define RAMC0_MPC0                              ((RAMC_MPC_Type*) &RAMC0->MPC[0])                                 /* 0x52234000 */
#define RAMC1_MPC0                              ((RAMC_MPC_Type*) &RAMC1->MPC[0])                                 /* 0x52244000 */

/*******************************************************************************
*                                    MXCM33
*******************************************************************************/

#define MXCM33_BASE                             0x52260000UL
#define MXCM33                                  ((MXCM33_Type*) MXCM33_BASE)                                      /* 0x52260000 */

/*******************************************************************************
*                                      DW
*******************************************************************************/

#define DW0_BASE                                0x52270000UL
#define DW1_BASE                                0x52280000UL
#define DW0                                     ((DW_Type*) DW0_BASE)                                             /* 0x52270000 */
#define DW1                                     ((DW_Type*) DW1_BASE)                                             /* 0x52280000 */
#define DW0_CH_STRUCT0                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[0])                         /* 0x52278000 */
#define DW0_CH_STRUCT1                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[1])                         /* 0x52278040 */
#define DW0_CH_STRUCT2                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[2])                         /* 0x52278080 */
#define DW0_CH_STRUCT3                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[3])                         /* 0x522780C0 */
#define DW0_CH_STRUCT4                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[4])                         /* 0x52278100 */
#define DW0_CH_STRUCT5                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[5])                         /* 0x52278140 */
#define DW0_CH_STRUCT6                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[6])                         /* 0x52278180 */
#define DW0_CH_STRUCT7                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[7])                         /* 0x522781C0 */
#define DW0_CH_STRUCT8                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[8])                         /* 0x52278200 */
#define DW0_CH_STRUCT9                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[9])                         /* 0x52278240 */
#define DW0_CH_STRUCT10                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[10])                        /* 0x52278280 */
#define DW0_CH_STRUCT11                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[11])                        /* 0x522782C0 */
#define DW0_CH_STRUCT12                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[12])                        /* 0x52278300 */
#define DW0_CH_STRUCT13                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[13])                        /* 0x52278340 */
#define DW0_CH_STRUCT14                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[14])                        /* 0x52278380 */
#define DW0_CH_STRUCT15                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[15])                        /* 0x522783C0 */
#define DW1_CH_STRUCT0                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[0])                         /* 0x52288000 */
#define DW1_CH_STRUCT1                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[1])                         /* 0x52288040 */
#define DW1_CH_STRUCT2                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[2])                         /* 0x52288080 */
#define DW1_CH_STRUCT3                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[3])                         /* 0x522880C0 */
#define DW1_CH_STRUCT4                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[4])                         /* 0x52288100 */
#define DW1_CH_STRUCT5                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[5])                         /* 0x52288140 */
#define DW1_CH_STRUCT6                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[6])                         /* 0x52288180 */
#define DW1_CH_STRUCT7                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[7])                         /* 0x522881C0 */
#define DW1_CH_STRUCT8                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[8])                         /* 0x52288200 */
#define DW1_CH_STRUCT9                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[9])                         /* 0x52288240 */
#define DW1_CH_STRUCT10                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[10])                        /* 0x52288280 */
#define DW1_CH_STRUCT11                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[11])                        /* 0x522882C0 */
#define DW1_CH_STRUCT12                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[12])                        /* 0x52288300 */
#define DW1_CH_STRUCT13                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[13])                        /* 0x52288340 */
#define DW1_CH_STRUCT14                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[14])                        /* 0x52288380 */
#define DW1_CH_STRUCT15                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[15])                        /* 0x522883C0 */

/*******************************************************************************
*                                    CPUSS
*******************************************************************************/

#define CPUSS_BASE                              0x52290000UL
#define CPUSS                                   ((CPUSS_Type*) CPUSS_BASE)                                        /* 0x52290000 */

/*******************************************************************************
*                                  MS_CTL_2_1
*******************************************************************************/

#define MS_CTL_2_1_BASE                         0x52294000UL
#define MS_CTL_2_1                              ((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)                              /* 0x52294000 */
#define MS0                                     ((MS_Type*) &MS_CTL_2_1->MS[0])                                   /* 0x52294000 */
#define MS4                                     ((MS_Type*) &MS_CTL_2_1->MS[4])                                   /* 0x52294040 */
#define MS5                                     ((MS_Type*) &MS_CTL_2_1->MS[5])                                   /* 0x52294050 */
#define MS6                                     ((MS_Type*) &MS_CTL_2_1->MS[6])                                   /* 0x52294060 */
#define MS7                                     ((MS_Type*) &MS_CTL_2_1->MS[7])                                   /* 0x52294070 */
#define MS8                                     ((MS_Type*) &MS_CTL_2_1->MS[8])                                   /* 0x52294080 */
#define MS9                                     ((MS_Type*) &MS_CTL_2_1->MS[9])                                   /* 0x52294090 */
#define MS10                                    ((MS_Type*) &MS_CTL_2_1->MS[10])                                  /* 0x522940A0 */
#define MS11                                    ((MS_Type*) &MS_CTL_2_1->MS[11])                                  /* 0x522940B0 */
#define MS29                                    ((MS_Type*) &MS_CTL_2_1->MS[29])                                  /* 0x522941D0 */
#define MS31                                    ((MS_Type*) &MS_CTL_2_1->MS[31])                                  /* 0x522941F0 */
#define MS_PC0                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[0])                             /* 0x52295000 */
#define MS_PC4                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[4])                             /* 0x52295040 */
#define MS_PC5                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[5])                             /* 0x52295050 */
#define MS_PC6                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[6])                             /* 0x52295060 */
#define MS_PC7                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[7])                             /* 0x52295070 */
#define MS_PC8                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[8])                             /* 0x52295080 */
#define MS_PC9                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[9])                             /* 0x52295090 */
#define MS_PC10                                 ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[10])                            /* 0x522950A0 */
#define MS_PC11                                 ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[11])                            /* 0x522950B0 */
#define MS_PC29                                 ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[29])                            /* 0x522951D0 */
#define MS_PC31                                 ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[31])                            /* 0x522951F0 */

/*******************************************************************************
*                                 CPUSS_SL_CTL
*******************************************************************************/

#define CPUSS_SL_CTL_BASE                       0x52298000UL
#define CPUSS_SL_CTL                            ((CPUSS_SL_CTL_Type*) CPUSS_SL_CTL_BASE)                          /* 0x52298000 */

/*******************************************************************************
*                                     IPC
*******************************************************************************/

#define IPC0_BASE                               0x522A0000UL
#define IPC1_BASE                               0x541D0000UL
#define IPC0                                    ((IPC_Type*) IPC0_BASE)                                           /* 0x522A0000 */
#define IPC1                                    ((IPC_Type*) IPC1_BASE)                                           /* 0x541D0000 */
#define IPC0_STRUCT0                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[0])                             /* 0x522A0000 */
#define IPC0_STRUCT1                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[1])                             /* 0x522A0020 */
#define IPC0_STRUCT2                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[2])                             /* 0x522A0040 */
#define IPC0_STRUCT3                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[3])                             /* 0x522A0060 */
#define IPC0_STRUCT4                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[4])                             /* 0x522A0080 */
#define IPC0_STRUCT5                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[5])                             /* 0x522A00A0 */
#define IPC0_STRUCT6                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[6])                             /* 0x522A00C0 */
#define IPC0_STRUCT7                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[7])                             /* 0x522A00E0 */
#define IPC0_STRUCT8                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[8])                             /* 0x522A0100 */
#define IPC0_STRUCT9                            ((IPC_STRUCT_Type*) &IPC0->STRUCT[9])                             /* 0x522A0120 */
#define IPC0_STRUCT10                           ((IPC_STRUCT_Type*) &IPC0->STRUCT[10])                            /* 0x522A0140 */
#define IPC0_STRUCT11                           ((IPC_STRUCT_Type*) &IPC0->STRUCT[11])                            /* 0x522A0160 */
#define IPC0_STRUCT12                           ((IPC_STRUCT_Type*) &IPC0->STRUCT[12])                            /* 0x522A0180 */
#define IPC0_STRUCT13                           ((IPC_STRUCT_Type*) &IPC0->STRUCT[13])                            /* 0x522A01A0 */
#define IPC0_STRUCT14                           ((IPC_STRUCT_Type*) &IPC0->STRUCT[14])                            /* 0x522A01C0 */
#define IPC0_STRUCT15                           ((IPC_STRUCT_Type*) &IPC0->STRUCT[15])                            /* 0x522A01E0 */
#define IPC1_STRUCT0                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[0])                             /* 0x541D0000 */
#define IPC1_STRUCT1                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[1])                             /* 0x541D0020 */
#define IPC1_STRUCT2                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[2])                             /* 0x541D0040 */
#define IPC1_STRUCT3                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[3])                             /* 0x541D0060 */
#define IPC1_STRUCT4                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[4])                             /* 0x541D0080 */
#define IPC1_STRUCT5                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[5])                             /* 0x541D00A0 */
#define IPC1_STRUCT6                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[6])                             /* 0x541D00C0 */
#define IPC1_STRUCT7                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[7])                             /* 0x541D00E0 */
#define IPC1_STRUCT8                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[8])                             /* 0x541D0100 */
#define IPC1_STRUCT9                            ((IPC_STRUCT_Type*) &IPC1->STRUCT[9])                             /* 0x541D0120 */
#define IPC1_STRUCT10                           ((IPC_STRUCT_Type*) &IPC1->STRUCT[10])                            /* 0x541D0140 */
#define IPC1_STRUCT11                           ((IPC_STRUCT_Type*) &IPC1->STRUCT[11])                            /* 0x541D0160 */
#define IPC1_STRUCT12                           ((IPC_STRUCT_Type*) &IPC1->STRUCT[12])                            /* 0x541D0180 */
#define IPC1_STRUCT13                           ((IPC_STRUCT_Type*) &IPC1->STRUCT[13])                            /* 0x541D01A0 */
#define IPC1_STRUCT14                           ((IPC_STRUCT_Type*) &IPC1->STRUCT[14])                            /* 0x541D01C0 */
#define IPC1_STRUCT15                           ((IPC_STRUCT_Type*) &IPC1->STRUCT[15])                            /* 0x541D01E0 */
#define IPC0_INTR_STRUCT0                       ((IPC_INTR_STRUCT_Type*) &IPC0->INTR_STRUCT[0])                   /* 0x522A1000 */
#define IPC0_INTR_STRUCT1                       ((IPC_INTR_STRUCT_Type*) &IPC0->INTR_STRUCT[1])                   /* 0x522A1020 */
#define IPC0_INTR_STRUCT2                       ((IPC_INTR_STRUCT_Type*) &IPC0->INTR_STRUCT[2])                   /* 0x522A1040 */
#define IPC0_INTR_STRUCT3                       ((IPC_INTR_STRUCT_Type*) &IPC0->INTR_STRUCT[3])                   /* 0x522A1060 */
#define IPC0_INTR_STRUCT4                       ((IPC_INTR_STRUCT_Type*) &IPC0->INTR_STRUCT[4])                   /* 0x522A1080 */
#define IPC0_INTR_STRUCT5                       ((IPC_INTR_STRUCT_Type*) &IPC0->INTR_STRUCT[5])                   /* 0x522A10A0 */
#define IPC0_INTR_STRUCT6                       ((IPC_INTR_STRUCT_Type*) &IPC0->INTR_STRUCT[6])                   /* 0x522A10C0 */
#define IPC0_INTR_STRUCT7                       ((IPC_INTR_STRUCT_Type*) &IPC0->INTR_STRUCT[7])                   /* 0x522A10E0 */
#define IPC1_INTR_STRUCT0                       ((IPC_INTR_STRUCT_Type*) &IPC1->INTR_STRUCT[0])                   /* 0x541D1000 */
#define IPC1_INTR_STRUCT1                       ((IPC_INTR_STRUCT_Type*) &IPC1->INTR_STRUCT[1])                   /* 0x541D1020 */
#define IPC1_INTR_STRUCT2                       ((IPC_INTR_STRUCT_Type*) &IPC1->INTR_STRUCT[2])                   /* 0x541D1040 */
#define IPC1_INTR_STRUCT3                       ((IPC_INTR_STRUCT_Type*) &IPC1->INTR_STRUCT[3])                   /* 0x541D1060 */
#define IPC1_INTR_STRUCT4                       ((IPC_INTR_STRUCT_Type*) &IPC1->INTR_STRUCT[4])                   /* 0x541D1080 */
#define IPC1_INTR_STRUCT5                       ((IPC_INTR_STRUCT_Type*) &IPC1->INTR_STRUCT[5])                   /* 0x541D10A0 */
#define IPC1_INTR_STRUCT6                       ((IPC_INTR_STRUCT_Type*) &IPC1->INTR_STRUCT[6])                   /* 0x541D10C0 */
#define IPC1_INTR_STRUCT7                       ((IPC_INTR_STRUCT_Type*) &IPC1->INTR_STRUCT[7])                   /* 0x541D10E0 */

/*******************************************************************************
*                                    FAULT
*******************************************************************************/

#define FAULT_BASE                              0x522B0000UL
#define FAULT                                   ((FAULT_Type*) FAULT_BASE)                                        /* 0x522B0000 */
#define FAULT_STRUCT0                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[0])                          /* 0x522B0000 */
#define FAULT_STRUCT1                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[1])                          /* 0x522B0100 */

/*******************************************************************************
*                                     SRSS
*******************************************************************************/

#define SRSS_BASE                               0x52400000UL
#define SRSS                                    ((SRSS_Type*) SRSS_BASE)                                          /* 0x52400000 */
#define CLK_ECO                                 ((CLK_ECO_Type*) &SRSS->CLK_ECO_STRUCT)                           /* 0x52401360 */
#define CSV_HF                                  ((CSV_HF_Type*) &SRSS->CSV_HF_STRUCT)                             /* 0x52401400 */
#define CSV_HF_CSV0                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[0])                  /* 0x52401400 */
#define CSV_HF_CSV1                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[1])                  /* 0x52401410 */
#define CSV_HF_CSV2                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[2])                  /* 0x52401420 */
#define CSV_HF_CSV3                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[3])                  /* 0x52401430 */
#define CSV_HF_CSV4                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[4])                  /* 0x52401440 */
#define CSV_HF_CSV5                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[5])                  /* 0x52401450 */
#define CSV_HF_CSV6                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[6])                  /* 0x52401460 */
#define CSV_HF_CSV7                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[7])                  /* 0x52401470 */
#define CSV_HF_CSV8                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[8])                  /* 0x52401480 */
#define CSV_HF_CSV9                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[9])                  /* 0x52401490 */
#define CSV_HF_CSV10                            ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[10])                 /* 0x524014A0 */
#define CSV_HF_CSV11                            ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[11])                 /* 0x524014B0 */
#define CSV_HF_CSV12                            ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[12])                 /* 0x524014C0 */
#define CSV_HF_CSV13                            ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[13])                 /* 0x524014D0 */
#define CSV_REF                                 ((CSV_REF_Type*) &SRSS->CSV_REF_STRUCT)                           /* 0x52401510 */
#define CSV_REF_CSV                             ((CSV_REF_CSV_Type*) &SRSS->CSV_REF_STRUCT.CSV)                   /* 0x52401510 */
#define CSV_LF                                  ((CSV_LF_Type*) &SRSS->CSV_LF_STRUCT)                             /* 0x52401530 */
#define CSV_LF_CSV                              ((CSV_LF_CSV_Type*) &SRSS->CSV_LF_STRUCT.CSV)                     /* 0x52401530 */
#define CLK_DPLL_LP0                            ((CLK_DPLL_LP_Type*) &SRSS->CLK_DPLL_LP[0])                       /* 0x52401600 */
#define CLK_DPLL_LP1                            ((CLK_DPLL_LP_Type*) &SRSS->CLK_DPLL_LP[1])                       /* 0x52401620 */
#define CLK_DPLL_HP0                            ((CLK_DPLL_HP_Type*) &SRSS->CLK_DPLL_HP[0])                       /* 0x52401800 */
#define CLK_TRIM_DPLL_LP0                       ((CLK_TRIM_DPLL_LP_Type*) &SRSS->CLK_TRIM_DPLL_LP[0])             /* 0x52403200 */
#define CLK_TRIM_DPLL_LP1                       ((CLK_TRIM_DPLL_LP_Type*) &SRSS->CLK_TRIM_DPLL_LP[1])             /* 0x52403220 */
#define RAM_TRIM                                ((RAM_TRIM_Type*) &SRSS->RAM_TRIM_STRUCT)                         /* 0x52404000 */
#define MCWDT_STRUCT0                           ((MCWDT_STRUCT_Type*) &SRSS->MCWDT_STRUCT[0])                     /* 0x5240D000 */
#define MCWDT_STRUCT1                           ((MCWDT_STRUCT_Type*) &SRSS->MCWDT_STRUCT[1])                     /* 0x5240D040 */

/*******************************************************************************
*                                   PWRMODE
*******************************************************************************/

#define PWRMODE_BASE                            0x52410000UL
#define PWRMODE                                 ((PWRMODE_Type*) PWRMODE_BASE)                                    /* 0x52410000 */
#define PWRMODE_PD0                             ((PWRMODE_PD_Type*) &PWRMODE->PD[0])                              /* 0x52410000 */
#define PWRMODE_PD1                             ((PWRMODE_PD_Type*) &PWRMODE->PD[1])                              /* 0x52410010 */
#define PWRMODE_PD2                             ((PWRMODE_PD_Type*) &PWRMODE->PD[2])                              /* 0x52410020 */
#define PWRMODE_PD3                             ((PWRMODE_PD_Type*) &PWRMODE->PD[3])                              /* 0x52410030 */
#define PWRMODE_PD4                             ((PWRMODE_PD_Type*) &PWRMODE->PD[4])                              /* 0x52410040 */
#define PWRMODE_PD5                             ((PWRMODE_PD_Type*) &PWRMODE->PD[5])                              /* 0x52410050 */
#define PWRMODE_PD6                             ((PWRMODE_PD_Type*) &PWRMODE->PD[6])                              /* 0x52410060 */
#define PWRMODE_PD7                             ((PWRMODE_PD_Type*) &PWRMODE->PD[7])                              /* 0x52410070 */
#define PWRMODE_PD8                             ((PWRMODE_PD_Type*) &PWRMODE->PD[8])                              /* 0x52410080 */
#define PWRMODE_PD9                             ((PWRMODE_PD_Type*) &PWRMODE->PD[9])                              /* 0x52410090 */
#define PWRMODE_PD10                            ((PWRMODE_PD_Type*) &PWRMODE->PD[10])                             /* 0x524100A0 */
#define PWRMODE_PD11                            ((PWRMODE_PD_Type*) &PWRMODE->PD[11])                             /* 0x524100B0 */
#define PWRMODE_PD12                            ((PWRMODE_PD_Type*) &PWRMODE->PD[12])                             /* 0x524100C0 */
#define PWRMODE_PD13                            ((PWRMODE_PD_Type*) &PWRMODE->PD[13])                             /* 0x524100D0 */
#define PWRMODE_PD14                            ((PWRMODE_PD_Type*) &PWRMODE->PD[14])                             /* 0x524100E0 */
#define PWRMODE_PD15                            ((PWRMODE_PD_Type*) &PWRMODE->PD[15])                             /* 0x524100F0 */
#define PWRMODE_PPU_MAIN                        ((PWRMODE_PPU_MAIN_Type*) &PWRMODE->PPU_MAIN)                     /* 0x52411000 */
#define PWRMODE_PPU_MAIN_PPU                    ((PWRMODE_PPU_MAIN_PPU_Type*) &PWRMODE->PPU_MAIN.PPU)             /* 0x52411000 */
#define PWRMODE_PPU_PD1                         ((PWRMODE_PPU_PD1_Type*) &PWRMODE->PPU_PD1)                       /* 0x52413000 */
#define PWRMODE_PPU_PD1_PPU_MAIN                ((PWRMODE_PPU_PD1_PPU_MAIN_Type*) &PWRMODE->PPU_PD1.PPU_MAIN)     /* 0x52413000 */
#define PWRMODE_PD0_CTRL                        ((PWRMODE_PD0_CTRL_Type*) &PWRMODE->PD0_CTRL)                     /* 0x52414000 */
#define PWRMODE_PD0_CTRL_PD                     ((PWRMODE_PD0_CTRL_PD_Type*) &PWRMODE->PD0_CTRL.PD)               /* 0x52414000 */
#define PWRMODE_PD1_CTRL                        ((PWRMODE_PD1_CTRL_Type*) &PWRMODE->PD1_CTRL)                     /* 0x52415000 */
#define PWRMODE_PD1_CTRL_PD                     ((PWRMODE_PD1_CTRL_PD_Type*) &PWRMODE->PD1_CTRL.PD)               /* 0x52415000 */

/*******************************************************************************
*                                     RTC
*******************************************************************************/

#define RTC_BASE                                0x52420000UL
#define RTC                                     ((RTC_Type*) RTC_BASE)                                            /* 0x52420000 */

/*******************************************************************************
*                                   DEBUG600
*******************************************************************************/

#define DEBUG600_BASE                           0x52430000UL
#define DEBUG600                                ((DEBUG600_Type*) DEBUG600_BASE)                                  /* 0x52430000 */

/*******************************************************************************
*                              M0SECCPUSS_STATUS
*******************************************************************************/

#define M0SECCPUSS_STATUS_BASE                  0x52430100UL
#define M0SECCPUSS_STATUS                       ((M0SECCPUSS_STATUS_Type*) M0SECCPUSS_STATUS_BASE)                /* 0x52430100 */

/*******************************************************************************
*                                    CRYPTO
*******************************************************************************/

#define CRYPTO_BASE                             0x52440000UL
#define CRYPTO                                  ((CRYPTO_V2_Type*) CRYPTO_BASE)                                   /* 0x52440000 */

/*******************************************************************************
*                                    HSIOM
*******************************************************************************/

#define HSIOM_BASE                              0x52800000UL
#define HSIOM                                   ((HSIOM_Type*) HSIOM_BASE)                                        /* 0x52800000 */
#define HSIOM_PRT0                              ((HSIOM_PRT_Type*) &HSIOM->PRT[0])                                /* 0x52800000 */
#define HSIOM_PRT1                              ((HSIOM_PRT_Type*) &HSIOM->PRT[1])                                /* 0x52800010 */
#define HSIOM_PRT2                              ((HSIOM_PRT_Type*) &HSIOM->PRT[2])                                /* 0x52800020 */
#define HSIOM_PRT3                              ((HSIOM_PRT_Type*) &HSIOM->PRT[3])                                /* 0x52800030 */
#define HSIOM_PRT4                              ((HSIOM_PRT_Type*) &HSIOM->PRT[4])                                /* 0x52800040 */
#define HSIOM_PRT5                              ((HSIOM_PRT_Type*) &HSIOM->PRT[5])                                /* 0x52800050 */
#define HSIOM_PRT6                              ((HSIOM_PRT_Type*) &HSIOM->PRT[6])                                /* 0x52800060 */
#define HSIOM_PRT7                              ((HSIOM_PRT_Type*) &HSIOM->PRT[7])                                /* 0x52800070 */
#define HSIOM_PRT8                              ((HSIOM_PRT_Type*) &HSIOM->PRT[8])                                /* 0x52800080 */
#define HSIOM_PRT9                              ((HSIOM_PRT_Type*) &HSIOM->PRT[9])                                /* 0x52800090 */
#define HSIOM_PRT10                             ((HSIOM_PRT_Type*) &HSIOM->PRT[10])                               /* 0x528000A0 */
#define HSIOM_PRT11                             ((HSIOM_PRT_Type*) &HSIOM->PRT[11])                               /* 0x528000B0 */
#define HSIOM_PRT12                             ((HSIOM_PRT_Type*) &HSIOM->PRT[12])                               /* 0x528000C0 */
#define HSIOM_PRT13                             ((HSIOM_PRT_Type*) &HSIOM->PRT[13])                               /* 0x528000D0 */
#define HSIOM_PRT14                             ((HSIOM_PRT_Type*) &HSIOM->PRT[14])                               /* 0x528000E0 */
#define HSIOM_PRT15                             ((HSIOM_PRT_Type*) &HSIOM->PRT[15])                               /* 0x528000F0 */
#define HSIOM_PRT16                             ((HSIOM_PRT_Type*) &HSIOM->PRT[16])                               /* 0x52800100 */
#define HSIOM_PRT17                             ((HSIOM_PRT_Type*) &HSIOM->PRT[17])                               /* 0x52800110 */
#define HSIOM_PRT18                             ((HSIOM_PRT_Type*) &HSIOM->PRT[18])                               /* 0x52800120 */
#define HSIOM_PRT19                             ((HSIOM_PRT_Type*) &HSIOM->PRT[19])                               /* 0x52800130 */
#define HSIOM_PRT20                             ((HSIOM_PRT_Type*) &HSIOM->PRT[20])                               /* 0x52800140 */
#define HSIOM_PRT21                             ((HSIOM_PRT_Type*) &HSIOM->PRT[21])                               /* 0x52800150 */
#define HSIOM_SECURE_PRT0                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[0])                  /* 0x52801000 */
#define HSIOM_SECURE_PRT1                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[1])                  /* 0x52801010 */
#define HSIOM_SECURE_PRT2                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[2])                  /* 0x52801020 */
#define HSIOM_SECURE_PRT3                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[3])                  /* 0x52801030 */
#define HSIOM_SECURE_PRT4                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[4])                  /* 0x52801040 */
#define HSIOM_SECURE_PRT5                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[5])                  /* 0x52801050 */
#define HSIOM_SECURE_PRT6                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[6])                  /* 0x52801060 */
#define HSIOM_SECURE_PRT7                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[7])                  /* 0x52801070 */
#define HSIOM_SECURE_PRT8                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[8])                  /* 0x52801080 */
#define HSIOM_SECURE_PRT9                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[9])                  /* 0x52801090 */
#define HSIOM_SECURE_PRT10                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[10])                 /* 0x528010A0 */
#define HSIOM_SECURE_PRT11                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[11])                 /* 0x528010B0 */
#define HSIOM_SECURE_PRT12                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[12])                 /* 0x528010C0 */
#define HSIOM_SECURE_PRT13                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[13])                 /* 0x528010D0 */
#define HSIOM_SECURE_PRT14                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[14])                 /* 0x528010E0 */
#define HSIOM_SECURE_PRT15                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[15])                 /* 0x528010F0 */
#define HSIOM_SECURE_PRT16                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[16])                 /* 0x52801100 */
#define HSIOM_SECURE_PRT17                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[17])                 /* 0x52801110 */
#define HSIOM_SECURE_PRT18                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[18])                 /* 0x52801120 */
#define HSIOM_SECURE_PRT19                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[19])                 /* 0x52801130 */
#define HSIOM_SECURE_PRT20                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[20])                 /* 0x52801140 */
#define HSIOM_SECURE_PRT21                      ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[21])                 /* 0x52801150 */

/*******************************************************************************
*                                     GPIO
*******************************************************************************/

#define GPIO_BASE                               0x52810000UL
#define GPIO                                    ((GPIO_Type*) GPIO_BASE)                                          /* 0x52810000 */
#define GPIO_PRT0                               ((GPIO_PRT_Type*) &GPIO->PRT[0])                                  /* 0x52810000 */
#define GPIO_PRT1                               ((GPIO_PRT_Type*) &GPIO->PRT[1])                                  /* 0x52810080 */
#define GPIO_PRT2                               ((GPIO_PRT_Type*) &GPIO->PRT[2])                                  /* 0x52810100 */
#define GPIO_PRT3                               ((GPIO_PRT_Type*) &GPIO->PRT[3])                                  /* 0x52810180 */
#define GPIO_PRT4                               ((GPIO_PRT_Type*) &GPIO->PRT[4])                                  /* 0x52810200 */
#define GPIO_PRT5                               ((GPIO_PRT_Type*) &GPIO->PRT[5])                                  /* 0x52810280 */
#define GPIO_PRT6                               ((GPIO_PRT_Type*) &GPIO->PRT[6])                                  /* 0x52810300 */
#define GPIO_PRT7                               ((GPIO_PRT_Type*) &GPIO->PRT[7])                                  /* 0x52810380 */
#define GPIO_PRT8                               ((GPIO_PRT_Type*) &GPIO->PRT[8])                                  /* 0x52810400 */
#define GPIO_PRT9                               ((GPIO_PRT_Type*) &GPIO->PRT[9])                                  /* 0x52810480 */
#define GPIO_PRT10                              ((GPIO_PRT_Type*) &GPIO->PRT[10])                                 /* 0x52810500 */
#define GPIO_PRT11                              ((GPIO_PRT_Type*) &GPIO->PRT[11])                                 /* 0x52810580 */
#define GPIO_PRT12                              ((GPIO_PRT_Type*) &GPIO->PRT[12])                                 /* 0x52810600 */
#define GPIO_PRT13                              ((GPIO_PRT_Type*) &GPIO->PRT[13])                                 /* 0x52810680 */
#define GPIO_PRT14                              ((GPIO_PRT_Type*) &GPIO->PRT[14])                                 /* 0x52810700 */
#define GPIO_PRT15                              ((GPIO_PRT_Type*) &GPIO->PRT[15])                                 /* 0x52810780 */
#define GPIO_PRT16                              ((GPIO_PRT_Type*) &GPIO->PRT[16])                                 /* 0x52810800 */
#define GPIO_PRT17                              ((GPIO_PRT_Type*) &GPIO->PRT[17])                                 /* 0x52810880 */
#define GPIO_PRT18                              ((GPIO_PRT_Type*) &GPIO->PRT[18])                                 /* 0x52810900 */
#define GPIO_PRT19                              ((GPIO_PRT_Type*) &GPIO->PRT[19])                                 /* 0x52810980 */
#define GPIO_PRT20                              ((GPIO_PRT_Type*) &GPIO->PRT[20])                                 /* 0x52810A00 */
#define GPIO_PRT21                              ((GPIO_PRT_Type*) &GPIO->PRT[21])                                 /* 0x52810A80 */

/*******************************************************************************
*                                   SMARTIO
*******************************************************************************/

#define SMARTIO_BASE                            0x52820000UL
#define SMARTIO                                 ((SMARTIO_Type*) SMARTIO_BASE)                                    /* 0x52820000 */
#define SMARTIO_PRT11                           ((SMARTIO_PRT_Type*) &SMARTIO->PRT[11])                           /* 0x52820B00 */
#define SMARTIO_PRT17                           ((SMARTIO_PRT_Type*) &SMARTIO->PRT[17])                           /* 0x52821100 */

/*******************************************************************************
*                                    CANFD
*******************************************************************************/

#define CANFD0_BASE                             0x52840000UL
#define CANFD0                                  ((CANFD_Type*) CANFD0_BASE)                                       /* 0x52840000 */
#define CANFD0_CH0                              ((CANFD_CH_Type*) &CANFD0->CH[0])                                 /* 0x52840000 */
#define CANFD0_CH1                              ((CANFD_CH_Type*) &CANFD0->CH[1])                                 /* 0x52840200 */
#define CANFD0_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[0].M_TTCAN)                 /* 0x52840000 */
#define CANFD0_CH1_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[1].M_TTCAN)                 /* 0x52840200 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM0_BASE                             0x52860000UL
#define TCPWM0                                  ((TCPWM_Type*) TCPWM0_BASE)                                       /* 0x52860000 */
#define TCPWM0_GRP0                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[0])                               /* 0x52860000 */
#define TCPWM0_GRP1                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[1])                               /* 0x52868000 */
#define TCPWM0_GRP0_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[0])                    /* 0x52860000 */
#define TCPWM0_GRP0_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[1])                    /* 0x52860080 */
#define TCPWM0_GRP0_CNT2                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[2])                    /* 0x52860100 */
#define TCPWM0_GRP0_CNT3                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[3])                    /* 0x52860180 */
#define TCPWM0_GRP0_CNT4                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[4])                    /* 0x52860200 */
#define TCPWM0_GRP0_CNT5                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[5])                    /* 0x52860280 */
#define TCPWM0_GRP0_CNT6                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[6])                    /* 0x52860300 */
#define TCPWM0_GRP0_CNT7                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[7])                    /* 0x52860380 */
#define TCPWM0_GRP1_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[0])                    /* 0x52868000 */
#define TCPWM0_GRP1_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[1])                    /* 0x52868080 */
#define TCPWM0_GRP1_CNT2                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[2])                    /* 0x52868100 */
#define TCPWM0_GRP1_CNT3                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[3])                    /* 0x52868180 */
#define TCPWM0_GRP1_CNT4                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[4])                    /* 0x52868200 */
#define TCPWM0_GRP1_CNT5                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[5])                    /* 0x52868280 */
#define TCPWM0_GRP1_CNT6                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[6])                    /* 0x52868300 */
#define TCPWM0_GRP1_CNT7                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[7])                    /* 0x52868380 */
#define TCPWM0_GRP1_CNT8                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[8])                    /* 0x52868400 */
#define TCPWM0_GRP1_CNT9                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[9])                    /* 0x52868480 */
#define TCPWM0_GRP1_CNT10                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[10])                   /* 0x52868500 */
#define TCPWM0_GRP1_CNT11                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[11])                   /* 0x52868580 */
#define TCPWM0_GRP1_CNT12                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[12])                   /* 0x52868600 */
#define TCPWM0_GRP1_CNT13                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[13])                   /* 0x52868680 */
#define TCPWM0_GRP1_CNT14                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[14])                   /* 0x52868700 */
#define TCPWM0_GRP1_CNT15                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[15])                   /* 0x52868780 */
#define TCPWM0_GRP1_CNT16                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[16])                   /* 0x52868800 */
#define TCPWM0_GRP1_CNT17                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[17])                   /* 0x52868880 */
#define TCPWM0_GRP1_CNT18                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[18])                   /* 0x52868900 */
#define TCPWM0_GRP1_CNT19                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[19])                   /* 0x52868980 */
#define TCPWM0_GRP1_CNT20                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[20])                   /* 0x52868A00 */
#define TCPWM0_GRP1_CNT21                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[21])                   /* 0x52868A80 */
#define TCPWM0_GRP1_CNT22                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[22])                   /* 0x52868B00 */
#define TCPWM0_GRP1_CNT23                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[23])                   /* 0x52868B80 */

/*******************************************************************************
*                                    LPCOMP
*******************************************************************************/

#define LPCOMP_BASE                             0x52880000UL
#define LPCOMP                                  ((LPCOMP_Type*) LPCOMP_BASE)                                      /* 0x52880000 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x52990000UL
#define SCB2_BASE                               0x529A0000UL
#define SCB3_BASE                               0x529B0000UL
#define SCB4_BASE                               0x529C0000UL
#define SCB5_BASE                               0x529D0000UL
#define SCB6_BASE                               0x529E0000UL
#define SCB7_BASE                               0x529F0000UL
#define SCB8_BASE                               0x52A00000UL
#define SCB9_BASE                               0x52A10000UL
#define SCB10_BASE                              0x52A20000UL
#define SCB11_BASE                              0x52A30000UL
#define SCB1_BASE                               0x52D00000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x52990000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x529A0000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x529B0000 */
#define SCB4                                    ((CySCB_Type*) SCB4_BASE)                                         /* 0x529C0000 */
#define SCB5                                    ((CySCB_Type*) SCB5_BASE)                                         /* 0x529D0000 */
#define SCB6                                    ((CySCB_Type*) SCB6_BASE)                                         /* 0x529E0000 */
#define SCB7                                    ((CySCB_Type*) SCB7_BASE)                                         /* 0x529F0000 */
#define SCB8                                    ((CySCB_Type*) SCB8_BASE)                                         /* 0x52A00000 */
#define SCB9                                    ((CySCB_Type*) SCB9_BASE)                                         /* 0x52A10000 */
#define SCB10                                   ((CySCB_Type*) SCB10_BASE)                                        /* 0x52A20000 */
#define SCB11                                   ((CySCB_Type*) SCB11_BASE)                                        /* 0x52A30000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x52D00000 */

/*******************************************************************************
*                                     I3C
*******************************************************************************/

#define I3C_BASE                                0x52A50000UL
#define I3C                                     ((I3C_Type*) I3C_BASE)                                            /* 0x52A50000 */
#define I3C_CORE                                ((I3C_CORE_Type*) &I3C->CORE)                                     /* 0x52A50000 */

/*******************************************************************************
*                                     ETH
*******************************************************************************/

#define ETH0_BASE                               0x52C10000UL
#define ETH0                                    ((ETH_Type*) ETH0_BASE)                                           /* 0x52C10000 */

/*******************************************************************************
*                                 MXNNLITE_2_0
*******************************************************************************/

#define MXNNLITE_2_0_BASE                       0x52D80000UL
#define MXNNLITE_2_0                            ((MXNNLITE_2_0_Type*) MXNNLITE_2_0_BASE)                          /* 0x52D80000 */

/*******************************************************************************
*                                     CTBL
*******************************************************************************/

#define CTBL0_BASE                              0x52E00000UL
#define CTBL1_BASE                              0x52E10000UL
#define CTBL0                                   ((CTBL_Type*) CTBL0_BASE)                                         /* 0x52E00000 */
#define CTBL1                                   ((CTBL_Type*) CTBL1_BASE)                                         /* 0x52E10000 */
#define CTBL0_STA                               ((CTBL_STA_Type*) &CTBL0->STA)                                    /* 0x52E00400 */
#define CTBL1_STA                               ((CTBL_STA_Type*) &CTBL1->STA)                                    /* 0x52E10400 */
#define CTBL0_DYN0                              ((CTBL_DYN_Type*) &CTBL0->DYN[0])                                 /* 0x52E00600 */
#define CTBL0_DYN1                              ((CTBL_DYN_Type*) &CTBL0->DYN[1])                                 /* 0x52E00610 */
#define CTBL0_DYN2                              ((CTBL_DYN_Type*) &CTBL0->DYN[2])                                 /* 0x52E00620 */
#define CTBL0_DYN3                              ((CTBL_DYN_Type*) &CTBL0->DYN[3])                                 /* 0x52E00630 */
#define CTBL0_DYN4                              ((CTBL_DYN_Type*) &CTBL0->DYN[4])                                 /* 0x52E00640 */
#define CTBL0_DYN5                              ((CTBL_DYN_Type*) &CTBL0->DYN[5])                                 /* 0x52E00650 */
#define CTBL0_DYN6                              ((CTBL_DYN_Type*) &CTBL0->DYN[6])                                 /* 0x52E00660 */
#define CTBL0_DYN7                              ((CTBL_DYN_Type*) &CTBL0->DYN[7])                                 /* 0x52E00670 */
#define CTBL1_DYN0                              ((CTBL_DYN_Type*) &CTBL1->DYN[0])                                 /* 0x52E10600 */
#define CTBL1_DYN1                              ((CTBL_DYN_Type*) &CTBL1->DYN[1])                                 /* 0x52E10610 */
#define CTBL1_DYN2                              ((CTBL_DYN_Type*) &CTBL1->DYN[2])                                 /* 0x52E10620 */
#define CTBL1_DYN3                              ((CTBL_DYN_Type*) &CTBL1->DYN[3])                                 /* 0x52E10630 */
#define CTBL1_DYN4                              ((CTBL_DYN_Type*) &CTBL1->DYN[4])                                 /* 0x52E10640 */
#define CTBL1_DYN5                              ((CTBL_DYN_Type*) &CTBL1->DYN[5])                                 /* 0x52E10650 */
#define CTBL1_DYN6                              ((CTBL_DYN_Type*) &CTBL1->DYN[6])                                 /* 0x52E10660 */
#define CTBL1_DYN7                              ((CTBL_DYN_Type*) &CTBL1->DYN[7])                                 /* 0x52E10670 */
#define CTBL0_TRIM                              ((CTBL_TRIM_Type*) &CTBL0->TRIM)                                  /* 0x52E00F00 */
#define CTBL1_TRIM                              ((CTBL_TRIM_Type*) &CTBL1->TRIM)                                  /* 0x52E10F00 */

/*******************************************************************************
*                                     PTC
*******************************************************************************/

#define PTC_BASE                                0x52E40000UL
#define PTC                                     ((PTC_Type*) PTC_BASE)                                            /* 0x52E40000 */
#define PTC_STA                                 ((PTC_STA_Type*) &PTC->STA)                                       /* 0x52E40400 */
#define PTC_DYN0                                ((PTC_DYN_Type*) &PTC->DYN[0])                                    /* 0x52E40600 */
#define PTC_DYN1                                ((PTC_DYN_Type*) &PTC->DYN[1])                                    /* 0x52E40610 */
#define PTC_DYN2                                ((PTC_DYN_Type*) &PTC->DYN[2])                                    /* 0x52E40620 */
#define PTC_DYN3                                ((PTC_DYN_Type*) &PTC->DYN[3])                                    /* 0x52E40630 */
#define PTC_DYN4                                ((PTC_DYN_Type*) &PTC->DYN[4])                                    /* 0x52E40640 */
#define PTC_DYN5                                ((PTC_DYN_Type*) &PTC->DYN[5])                                    /* 0x52E40650 */
#define PTC_DYN6                                ((PTC_DYN_Type*) &PTC->DYN[6])                                    /* 0x52E40660 */
#define PTC_DYN7                                ((PTC_DYN_Type*) &PTC->DYN[7])                                    /* 0x52E40670 */
#define PTC_PP0                                 ((PTC_PP_Type*) &PTC->PP[0])                                      /* 0x52E40700 */
#define PTC_PP1                                 ((PTC_PP_Type*) &PTC->PP[1])                                      /* 0x52E40710 */
#define PTC_TRIM                                ((PTC_TRIM_Type*) &PTC->TRIM)                                     /* 0x52E40F00 */

/*******************************************************************************
*                                     DAC
*******************************************************************************/

#define DAC0_BASE                               0x52E60000UL
#define DAC1_BASE                               0x52E70000UL
#define DAC0                                    ((DAC_Type*) DAC0_BASE)                                           /* 0x52E60000 */
#define DAC1                                    ((DAC_Type*) DAC1_BASE)                                           /* 0x52E70000 */
#define DAC0_STA                                ((DAC_STA_Type*) &DAC0->STA)                                      /* 0x52E60800 */
#define DAC1_STA                                ((DAC_STA_Type*) &DAC1->STA)                                      /* 0x52E70800 */
#define DAC0_TRIM                               ((DAC_TRIM_Type*) &DAC0->TRIM)                                    /* 0x52E60F00 */
#define DAC1_TRIM                               ((DAC_TRIM_Type*) &DAC1->TRIM)                                    /* 0x52E70F00 */

/*******************************************************************************
*                                     SAR
*******************************************************************************/

#define SAR_BASE                                0x52E80000UL
#define SAR                                     ((SAR_Type*) SAR_BASE)                                            /* 0x52E80000 */
#define SAR_STA                                 ((SAR_STA_Type*) &SAR->STA)                                       /* 0x52E80400 */
#define SAR_FIR00                               ((SAR_FIR0_Type*) &SAR->FIR0[0])                                  /* 0x52E80600 */
#define SAR_FIR01                               ((SAR_FIR0_Type*) &SAR->FIR0[1])                                  /* 0x52E80608 */
#define SAR_FIR02                               ((SAR_FIR0_Type*) &SAR->FIR0[2])                                  /* 0x52E80610 */
#define SAR_FIR03                               ((SAR_FIR0_Type*) &SAR->FIR0[3])                                  /* 0x52E80618 */
#define SAR_FIR04                               ((SAR_FIR0_Type*) &SAR->FIR0[4])                                  /* 0x52E80620 */
#define SAR_FIR05                               ((SAR_FIR0_Type*) &SAR->FIR0[5])                                  /* 0x52E80628 */
#define SAR_FIR06                               ((SAR_FIR0_Type*) &SAR->FIR0[6])                                  /* 0x52E80630 */
#define SAR_FIR07                               ((SAR_FIR0_Type*) &SAR->FIR0[7])                                  /* 0x52E80638 */
#define SAR_FIR08                               ((SAR_FIR0_Type*) &SAR->FIR0[8])                                  /* 0x52E80640 */
#define SAR_FIR09                               ((SAR_FIR0_Type*) &SAR->FIR0[9])                                  /* 0x52E80648 */
#define SAR_FIR010                              ((SAR_FIR0_Type*) &SAR->FIR0[10])                                 /* 0x52E80650 */
#define SAR_FIR011                              ((SAR_FIR0_Type*) &SAR->FIR0[11])                                 /* 0x52E80658 */
#define SAR_FIR012                              ((SAR_FIR0_Type*) &SAR->FIR0[12])                                 /* 0x52E80660 */
#define SAR_FIR013                              ((SAR_FIR0_Type*) &SAR->FIR0[13])                                 /* 0x52E80668 */
#define SAR_FIR014                              ((SAR_FIR0_Type*) &SAR->FIR0[14])                                 /* 0x52E80670 */
#define SAR_FIR015                              ((SAR_FIR0_Type*) &SAR->FIR0[15])                                 /* 0x52E80678 */
#define SAR_FIR016                              ((SAR_FIR0_Type*) &SAR->FIR0[16])                                 /* 0x52E80680 */
#define SAR_FIR017                              ((SAR_FIR0_Type*) &SAR->FIR0[17])                                 /* 0x52E80688 */
#define SAR_FIR018                              ((SAR_FIR0_Type*) &SAR->FIR0[18])                                 /* 0x52E80690 */
#define SAR_FIR019                              ((SAR_FIR0_Type*) &SAR->FIR0[19])                                 /* 0x52E80698 */
#define SAR_FIR020                              ((SAR_FIR0_Type*) &SAR->FIR0[20])                                 /* 0x52E806A0 */
#define SAR_FIR021                              ((SAR_FIR0_Type*) &SAR->FIR0[21])                                 /* 0x52E806A8 */
#define SAR_FIR022                              ((SAR_FIR0_Type*) &SAR->FIR0[22])                                 /* 0x52E806B0 */
#define SAR_FIR023                              ((SAR_FIR0_Type*) &SAR->FIR0[23])                                 /* 0x52E806B8 */
#define SAR_FIR024                              ((SAR_FIR0_Type*) &SAR->FIR0[24])                                 /* 0x52E806C0 */
#define SAR_FIR025                              ((SAR_FIR0_Type*) &SAR->FIR0[25])                                 /* 0x52E806C8 */
#define SAR_FIR026                              ((SAR_FIR0_Type*) &SAR->FIR0[26])                                 /* 0x52E806D0 */
#define SAR_FIR027                              ((SAR_FIR0_Type*) &SAR->FIR0[27])                                 /* 0x52E806D8 */
#define SAR_FIR028                              ((SAR_FIR0_Type*) &SAR->FIR0[28])                                 /* 0x52E806E0 */
#define SAR_FIR029                              ((SAR_FIR0_Type*) &SAR->FIR0[29])                                 /* 0x52E806E8 */
#define SAR_FIR030                              ((SAR_FIR0_Type*) &SAR->FIR0[30])                                 /* 0x52E806F0 */
#define SAR_FIR031                              ((SAR_FIR0_Type*) &SAR->FIR0[31])                                 /* 0x52E806F8 */
#define SAR_FIR032                              ((SAR_FIR0_Type*) &SAR->FIR0[32])                                 /* 0x52E80700 */
#define SAR_FIR033                              ((SAR_FIR0_Type*) &SAR->FIR0[33])                                 /* 0x52E80708 */
#define SAR_FIR034                              ((SAR_FIR0_Type*) &SAR->FIR0[34])                                 /* 0x52E80710 */
#define SAR_FIR035                              ((SAR_FIR0_Type*) &SAR->FIR0[35])                                 /* 0x52E80718 */
#define SAR_FIR036                              ((SAR_FIR0_Type*) &SAR->FIR0[36])                                 /* 0x52E80720 */
#define SAR_FIR037                              ((SAR_FIR0_Type*) &SAR->FIR0[37])                                 /* 0x52E80728 */
#define SAR_FIR038                              ((SAR_FIR0_Type*) &SAR->FIR0[38])                                 /* 0x52E80730 */
#define SAR_FIR039                              ((SAR_FIR0_Type*) &SAR->FIR0[39])                                 /* 0x52E80738 */
#define SAR_FIR040                              ((SAR_FIR0_Type*) &SAR->FIR0[40])                                 /* 0x52E80740 */
#define SAR_FIR041                              ((SAR_FIR0_Type*) &SAR->FIR0[41])                                 /* 0x52E80748 */
#define SAR_FIR042                              ((SAR_FIR0_Type*) &SAR->FIR0[42])                                 /* 0x52E80750 */
#define SAR_FIR043                              ((SAR_FIR0_Type*) &SAR->FIR0[43])                                 /* 0x52E80758 */
#define SAR_FIR044                              ((SAR_FIR0_Type*) &SAR->FIR0[44])                                 /* 0x52E80760 */
#define SAR_FIR045                              ((SAR_FIR0_Type*) &SAR->FIR0[45])                                 /* 0x52E80768 */
#define SAR_FIR046                              ((SAR_FIR0_Type*) &SAR->FIR0[46])                                 /* 0x52E80770 */
#define SAR_FIR047                              ((SAR_FIR0_Type*) &SAR->FIR0[47])                                 /* 0x52E80778 */
#define SAR_FIR048                              ((SAR_FIR0_Type*) &SAR->FIR0[48])                                 /* 0x52E80780 */
#define SAR_FIR049                              ((SAR_FIR0_Type*) &SAR->FIR0[49])                                 /* 0x52E80788 */
#define SAR_FIR050                              ((SAR_FIR0_Type*) &SAR->FIR0[50])                                 /* 0x52E80790 */
#define SAR_FIR051                              ((SAR_FIR0_Type*) &SAR->FIR0[51])                                 /* 0x52E80798 */
#define SAR_FIR052                              ((SAR_FIR0_Type*) &SAR->FIR0[52])                                 /* 0x52E807A0 */
#define SAR_FIR053                              ((SAR_FIR0_Type*) &SAR->FIR0[53])                                 /* 0x52E807A8 */
#define SAR_FIR054                              ((SAR_FIR0_Type*) &SAR->FIR0[54])                                 /* 0x52E807B0 */
#define SAR_FIR055                              ((SAR_FIR0_Type*) &SAR->FIR0[55])                                 /* 0x52E807B8 */
#define SAR_FIR056                              ((SAR_FIR0_Type*) &SAR->FIR0[56])                                 /* 0x52E807C0 */
#define SAR_FIR057                              ((SAR_FIR0_Type*) &SAR->FIR0[57])                                 /* 0x52E807C8 */
#define SAR_FIR058                              ((SAR_FIR0_Type*) &SAR->FIR0[58])                                 /* 0x52E807D0 */
#define SAR_FIR059                              ((SAR_FIR0_Type*) &SAR->FIR0[59])                                 /* 0x52E807D8 */
#define SAR_FIR060                              ((SAR_FIR0_Type*) &SAR->FIR0[60])                                 /* 0x52E807E0 */
#define SAR_FIR061                              ((SAR_FIR0_Type*) &SAR->FIR0[61])                                 /* 0x52E807E8 */
#define SAR_FIR062                              ((SAR_FIR0_Type*) &SAR->FIR0[62])                                 /* 0x52E807F0 */
#define SAR_FIR063                              ((SAR_FIR0_Type*) &SAR->FIR0[63])                                 /* 0x52E807F8 */
#define SAR_FIR10                               ((SAR_FIR1_Type*) &SAR->FIR1[0])                                  /* 0x52E80800 */
#define SAR_FIR11                               ((SAR_FIR1_Type*) &SAR->FIR1[1])                                  /* 0x52E80808 */
#define SAR_FIR12                               ((SAR_FIR1_Type*) &SAR->FIR1[2])                                  /* 0x52E80810 */
#define SAR_FIR13                               ((SAR_FIR1_Type*) &SAR->FIR1[3])                                  /* 0x52E80818 */
#define SAR_FIR14                               ((SAR_FIR1_Type*) &SAR->FIR1[4])                                  /* 0x52E80820 */
#define SAR_FIR15                               ((SAR_FIR1_Type*) &SAR->FIR1[5])                                  /* 0x52E80828 */
#define SAR_FIR16                               ((SAR_FIR1_Type*) &SAR->FIR1[6])                                  /* 0x52E80830 */
#define SAR_FIR17                               ((SAR_FIR1_Type*) &SAR->FIR1[7])                                  /* 0x52E80838 */
#define SAR_FIR18                               ((SAR_FIR1_Type*) &SAR->FIR1[8])                                  /* 0x52E80840 */
#define SAR_FIR19                               ((SAR_FIR1_Type*) &SAR->FIR1[9])                                  /* 0x52E80848 */
#define SAR_FIR110                              ((SAR_FIR1_Type*) &SAR->FIR1[10])                                 /* 0x52E80850 */
#define SAR_FIR111                              ((SAR_FIR1_Type*) &SAR->FIR1[11])                                 /* 0x52E80858 */
#define SAR_FIR112                              ((SAR_FIR1_Type*) &SAR->FIR1[12])                                 /* 0x52E80860 */
#define SAR_FIR113                              ((SAR_FIR1_Type*) &SAR->FIR1[13])                                 /* 0x52E80868 */
#define SAR_FIR114                              ((SAR_FIR1_Type*) &SAR->FIR1[14])                                 /* 0x52E80870 */
#define SAR_FIR115                              ((SAR_FIR1_Type*) &SAR->FIR1[15])                                 /* 0x52E80878 */
#define SAR_FIR116                              ((SAR_FIR1_Type*) &SAR->FIR1[16])                                 /* 0x52E80880 */
#define SAR_FIR117                              ((SAR_FIR1_Type*) &SAR->FIR1[17])                                 /* 0x52E80888 */
#define SAR_FIR118                              ((SAR_FIR1_Type*) &SAR->FIR1[18])                                 /* 0x52E80890 */
#define SAR_FIR119                              ((SAR_FIR1_Type*) &SAR->FIR1[19])                                 /* 0x52E80898 */
#define SAR_FIR120                              ((SAR_FIR1_Type*) &SAR->FIR1[20])                                 /* 0x52E808A0 */
#define SAR_FIR121                              ((SAR_FIR1_Type*) &SAR->FIR1[21])                                 /* 0x52E808A8 */
#define SAR_FIR122                              ((SAR_FIR1_Type*) &SAR->FIR1[22])                                 /* 0x52E808B0 */
#define SAR_FIR123                              ((SAR_FIR1_Type*) &SAR->FIR1[23])                                 /* 0x52E808B8 */
#define SAR_FIR124                              ((SAR_FIR1_Type*) &SAR->FIR1[24])                                 /* 0x52E808C0 */
#define SAR_FIR125                              ((SAR_FIR1_Type*) &SAR->FIR1[25])                                 /* 0x52E808C8 */
#define SAR_FIR126                              ((SAR_FIR1_Type*) &SAR->FIR1[26])                                 /* 0x52E808D0 */
#define SAR_FIR127                              ((SAR_FIR1_Type*) &SAR->FIR1[27])                                 /* 0x52E808D8 */
#define SAR_FIR128                              ((SAR_FIR1_Type*) &SAR->FIR1[28])                                 /* 0x52E808E0 */
#define SAR_FIR129                              ((SAR_FIR1_Type*) &SAR->FIR1[29])                                 /* 0x52E808E8 */
#define SAR_FIR130                              ((SAR_FIR1_Type*) &SAR->FIR1[30])                                 /* 0x52E808F0 */
#define SAR_FIR131                              ((SAR_FIR1_Type*) &SAR->FIR1[31])                                 /* 0x52E808F8 */
#define SAR_FIR132                              ((SAR_FIR1_Type*) &SAR->FIR1[32])                                 /* 0x52E80900 */
#define SAR_FIR133                              ((SAR_FIR1_Type*) &SAR->FIR1[33])                                 /* 0x52E80908 */
#define SAR_FIR134                              ((SAR_FIR1_Type*) &SAR->FIR1[34])                                 /* 0x52E80910 */
#define SAR_FIR135                              ((SAR_FIR1_Type*) &SAR->FIR1[35])                                 /* 0x52E80918 */
#define SAR_FIR136                              ((SAR_FIR1_Type*) &SAR->FIR1[36])                                 /* 0x52E80920 */
#define SAR_FIR137                              ((SAR_FIR1_Type*) &SAR->FIR1[37])                                 /* 0x52E80928 */
#define SAR_FIR138                              ((SAR_FIR1_Type*) &SAR->FIR1[38])                                 /* 0x52E80930 */
#define SAR_FIR139                              ((SAR_FIR1_Type*) &SAR->FIR1[39])                                 /* 0x52E80938 */
#define SAR_FIR140                              ((SAR_FIR1_Type*) &SAR->FIR1[40])                                 /* 0x52E80940 */
#define SAR_FIR141                              ((SAR_FIR1_Type*) &SAR->FIR1[41])                                 /* 0x52E80948 */
#define SAR_FIR142                              ((SAR_FIR1_Type*) &SAR->FIR1[42])                                 /* 0x52E80950 */
#define SAR_FIR143                              ((SAR_FIR1_Type*) &SAR->FIR1[43])                                 /* 0x52E80958 */
#define SAR_FIR144                              ((SAR_FIR1_Type*) &SAR->FIR1[44])                                 /* 0x52E80960 */
#define SAR_FIR145                              ((SAR_FIR1_Type*) &SAR->FIR1[45])                                 /* 0x52E80968 */
#define SAR_FIR146                              ((SAR_FIR1_Type*) &SAR->FIR1[46])                                 /* 0x52E80970 */
#define SAR_FIR147                              ((SAR_FIR1_Type*) &SAR->FIR1[47])                                 /* 0x52E80978 */
#define SAR_FIR148                              ((SAR_FIR1_Type*) &SAR->FIR1[48])                                 /* 0x52E80980 */
#define SAR_FIR149                              ((SAR_FIR1_Type*) &SAR->FIR1[49])                                 /* 0x52E80988 */
#define SAR_FIR150                              ((SAR_FIR1_Type*) &SAR->FIR1[50])                                 /* 0x52E80990 */
#define SAR_FIR151                              ((SAR_FIR1_Type*) &SAR->FIR1[51])                                 /* 0x52E80998 */
#define SAR_FIR152                              ((SAR_FIR1_Type*) &SAR->FIR1[52])                                 /* 0x52E809A0 */
#define SAR_FIR153                              ((SAR_FIR1_Type*) &SAR->FIR1[53])                                 /* 0x52E809A8 */
#define SAR_FIR154                              ((SAR_FIR1_Type*) &SAR->FIR1[54])                                 /* 0x52E809B0 */
#define SAR_FIR155                              ((SAR_FIR1_Type*) &SAR->FIR1[55])                                 /* 0x52E809B8 */
#define SAR_FIR156                              ((SAR_FIR1_Type*) &SAR->FIR1[56])                                 /* 0x52E809C0 */
#define SAR_FIR157                              ((SAR_FIR1_Type*) &SAR->FIR1[57])                                 /* 0x52E809C8 */
#define SAR_FIR158                              ((SAR_FIR1_Type*) &SAR->FIR1[58])                                 /* 0x52E809D0 */
#define SAR_FIR159                              ((SAR_FIR1_Type*) &SAR->FIR1[59])                                 /* 0x52E809D8 */
#define SAR_FIR160                              ((SAR_FIR1_Type*) &SAR->FIR1[60])                                 /* 0x52E809E0 */
#define SAR_FIR161                              ((SAR_FIR1_Type*) &SAR->FIR1[61])                                 /* 0x52E809E8 */
#define SAR_FIR162                              ((SAR_FIR1_Type*) &SAR->FIR1[62])                                 /* 0x52E809F0 */
#define SAR_FIR163                              ((SAR_FIR1_Type*) &SAR->FIR1[63])                                 /* 0x52E809F8 */
#define SAR_HS_CAL_MEM                          ((SAR_HS_CAL_MEM_Type*) &SAR->HS_CAL_MEM)                         /* 0x52E80C00 */
#define SAR_LP_CAL_MEM                          ((SAR_LP_CAL_MEM_Type*) &SAR->LP_CAL_MEM)                         /* 0x52E80C80 */
#define SAR_TRIM                                ((SAR_TRIM_Type*) &SAR->TRIM)                                     /* 0x52E80F00 */

/*******************************************************************************
*                                    ACTRLR
*******************************************************************************/

#define ACTRLR_BASE                             0x52ED0000UL
#define ACTRLR                                  ((ACTRLR_Type*) ACTRLR_BASE)                                      /* 0x52ED0000 */
#define ACTRLR_TTCFG0                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[0])                          /* 0x52ED0800 */
#define ACTRLR_TTCFG1                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[1])                          /* 0x52ED0820 */
#define ACTRLR_TTCFG2                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[2])                          /* 0x52ED0840 */
#define ACTRLR_TTCFG3                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[3])                          /* 0x52ED0860 */
#define ACTRLR_TTCFG4                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[4])                          /* 0x52ED0880 */
#define ACTRLR_TTCFG5                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[5])                          /* 0x52ED08A0 */
#define ACTRLR_TTCFG6                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[6])                          /* 0x52ED08C0 */
#define ACTRLR_TTCFG7                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[7])                          /* 0x52ED08E0 */
#define ACTRLR_TTCFG8                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[8])                          /* 0x52ED0900 */
#define ACTRLR_TTCFG9                           ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[9])                          /* 0x52ED0920 */
#define ACTRLR_TTCFG10                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[10])                         /* 0x52ED0940 */
#define ACTRLR_TTCFG11                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[11])                         /* 0x52ED0960 */
#define ACTRLR_TTCFG12                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[12])                         /* 0x52ED0980 */
#define ACTRLR_TTCFG13                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[13])                         /* 0x52ED09A0 */
#define ACTRLR_TTCFG14                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[14])                         /* 0x52ED09C0 */
#define ACTRLR_TTCFG15                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[15])                         /* 0x52ED09E0 */
#define ACTRLR_TTCFG16                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[16])                         /* 0x52ED0A00 */
#define ACTRLR_TTCFG17                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[17])                         /* 0x52ED0A20 */
#define ACTRLR_TTCFG18                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[18])                         /* 0x52ED0A40 */
#define ACTRLR_TTCFG19                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[19])                         /* 0x52ED0A60 */
#define ACTRLR_TTCFG20                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[20])                         /* 0x52ED0A80 */
#define ACTRLR_TTCFG21                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[21])                         /* 0x52ED0AA0 */
#define ACTRLR_TTCFG22                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[22])                         /* 0x52ED0AC0 */
#define ACTRLR_TTCFG23                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[23])                         /* 0x52ED0AE0 */
#define ACTRLR_TTCFG24                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[24])                         /* 0x52ED0B00 */
#define ACTRLR_TTCFG25                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[25])                         /* 0x52ED0B20 */
#define ACTRLR_TTCFG26                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[26])                         /* 0x52ED0B40 */
#define ACTRLR_TTCFG27                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[27])                         /* 0x52ED0B60 */
#define ACTRLR_TTCFG28                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[28])                         /* 0x52ED0B80 */
#define ACTRLR_TTCFG29                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[29])                         /* 0x52ED0BA0 */
#define ACTRLR_TTCFG30                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[30])                         /* 0x52ED0BC0 */
#define ACTRLR_TTCFG31                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[31])                         /* 0x52ED0BE0 */
#define ACTRLR_TTCFG32                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[32])                         /* 0x52ED0C00 */
#define ACTRLR_TTCFG33                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[33])                         /* 0x52ED0C20 */
#define ACTRLR_TTCFG34                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[34])                         /* 0x52ED0C40 */
#define ACTRLR_TTCFG35                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[35])                         /* 0x52ED0C60 */
#define ACTRLR_TTCFG36                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[36])                         /* 0x52ED0C80 */
#define ACTRLR_TTCFG37                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[37])                         /* 0x52ED0CA0 */
#define ACTRLR_TTCFG38                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[38])                         /* 0x52ED0CC0 */
#define ACTRLR_TTCFG39                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[39])                         /* 0x52ED0CE0 */
#define ACTRLR_TTCFG40                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[40])                         /* 0x52ED0D00 */
#define ACTRLR_TTCFG41                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[41])                         /* 0x52ED0D20 */
#define ACTRLR_TTCFG42                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[42])                         /* 0x52ED0D40 */
#define ACTRLR_TTCFG43                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[43])                         /* 0x52ED0D60 */
#define ACTRLR_TTCFG44                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[44])                         /* 0x52ED0D80 */
#define ACTRLR_TTCFG45                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[45])                         /* 0x52ED0DA0 */
#define ACTRLR_TTCFG46                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[46])                         /* 0x52ED0DC0 */
#define ACTRLR_TTCFG47                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[47])                         /* 0x52ED0DE0 */
#define ACTRLR_TTCFG48                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[48])                         /* 0x52ED0E00 */
#define ACTRLR_TTCFG49                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[49])                         /* 0x52ED0E20 */
#define ACTRLR_TTCFG50                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[50])                         /* 0x52ED0E40 */
#define ACTRLR_TTCFG51                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[51])                         /* 0x52ED0E60 */
#define ACTRLR_TTCFG52                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[52])                         /* 0x52ED0E80 */
#define ACTRLR_TTCFG53                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[53])                         /* 0x52ED0EA0 */
#define ACTRLR_TTCFG54                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[54])                         /* 0x52ED0EC0 */
#define ACTRLR_TTCFG55                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[55])                         /* 0x52ED0EE0 */
#define ACTRLR_TTCFG56                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[56])                         /* 0x52ED0F00 */
#define ACTRLR_TTCFG57                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[57])                         /* 0x52ED0F20 */
#define ACTRLR_TTCFG58                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[58])                         /* 0x52ED0F40 */
#define ACTRLR_TTCFG59                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[59])                         /* 0x52ED0F60 */
#define ACTRLR_TTCFG60                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[60])                         /* 0x52ED0F80 */
#define ACTRLR_TTCFG61                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[61])                         /* 0x52ED0FA0 */
#define ACTRLR_TTCFG62                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[62])                         /* 0x52ED0FC0 */
#define ACTRLR_TTCFG63                          ((ACTRLR_TTCFG_Type*) &ACTRLR->TTCFG[63])                         /* 0x52ED0FE0 */

/*******************************************************************************
*                                    INFRA
*******************************************************************************/

#define INFRA_BASE                              0x52EE0000UL
#define INFRA                                   ((INFRA_Type*) INFRA_BASE)                                        /* 0x52EE0000 */
#define INFRA_LPOSC                             ((INFRA_LPOSC_Type*) &INFRA->LPOSC)                               /* 0x52EE0100 */
#define INFRA_AREF                              ((INFRA_AREF_Type*) &INFRA->AREF)                                 /* 0x52EE0200 */
#define INFRA_PRB                               ((INFRA_PRB_Type*) &INFRA->PRB)                                   /* 0x52EE0300 */
#define INFRA_TIMER                             ((INFRA_TIMER_Type*) &INFRA->TIMER)                               /* 0x52EE0400 */

/*******************************************************************************
*                                 LPPASS_MMIO
*******************************************************************************/

#define LPPASS_MMIO_BASE                        0x52EF0000UL
#define LPPASS_MMIO                             ((LPPASS_MMIO_Type*) LPPASS_MMIO_BASE)                            /* 0x52EF0000 */
#define LPPASS_MMIO_STA                         ((LPPASS_MMIO_STA_Type*) &LPPASS_MMIO->STA)                       /* 0x52EF0400 */

/*******************************************************************************
*                                 PPU_APPCPUSS
*******************************************************************************/

#define PPU_APPCPUSS_BASE                       0x54100000UL
#define PPU_APPCPUSS                            ((PPU_APPCPUSS_Type*) PPU_APPCPUSS_BASE)                          /* 0x54100000 */

/*******************************************************************************
*                                  PPU_CM55_0
*******************************************************************************/

#define PPU_CM55_0_BASE                         0x54101000UL
#define PPU_CM55_0                              ((PPU_CM55_0_Type*) PPU_CM55_0_BASE)                              /* 0x54101000 */

/*******************************************************************************
*                                      PD
*******************************************************************************/

#define PD_CTL_BASE                             0x54103000UL
#define PD_CTL                                  ((PD_Type*) PD_CTL_BASE)                                          /* 0x54103000 */

/*******************************************************************************
*                                    MXCM55
*******************************************************************************/

#define MXCM55_BASE                             0x54160000UL
#define MXCM55                                  ((MXCM55_Type*) MXCM55_BASE)                                      /* 0x54160000 */

/*******************************************************************************
*                                  SAXI_DMAC
*******************************************************************************/

#define SAXI_DMAC_BASE                          0x541A0000UL
#define SAXI_DMAC                               ((SAXI_DMAC_Type*) SAXI_DMAC_BASE)                                /* 0x541A0000 */
#define SAXI_DMAC_CH0                           ((SAXI_DMAC_CH_Type*) &SAXI_DMAC->CH[0])                          /* 0x541A1000 */
#define SAXI_DMAC_CH1                           ((SAXI_DMAC_CH_Type*) &SAXI_DMAC->CH[1])                          /* 0x541A1100 */
#define SAXI_DMAC_CH2                           ((SAXI_DMAC_CH_Type*) &SAXI_DMAC->CH[2])                          /* 0x541A1200 */
#define SAXI_DMAC_CH3                           ((SAXI_DMAC_CH_Type*) &SAXI_DMAC->CH[3])                          /* 0x541A1300 */

/*******************************************************************************
*                                   APPCPUSS
*******************************************************************************/

#define APPCPUSS_BASE                           0x541C0000UL
#define APPCPUSS                                ((APPCPUSS_Type*) APPCPUSS_BASE)                                  /* 0x541C0000 */

/*******************************************************************************
*                                    MS_CTL
*******************************************************************************/

#define MS_CTL_BASE                             0x541C4000UL
#define MS_CTL                                  ((MS_CTL_Type*) MS_CTL_BASE)                                      /* 0x541C4000 */
#define MS_CTL_MS13                             ((MS_CTL_MS_Type*) &MS_CTL->MS[13])                               /* 0x541C40D0 */
#define MS_CTL_MS14                             ((MS_CTL_MS_Type*) &MS_CTL->MS[14])                               /* 0x541C40E0 */
#define MS_CTL_MS15                             ((MS_CTL_MS_Type*) &MS_CTL->MS[15])                               /* 0x541C40F0 */
#define MS_CTL_MS19                             ((MS_CTL_MS_Type*) &MS_CTL->MS[19])                               /* 0x541C4130 */
#define MS_CTL_MS23                             ((MS_CTL_MS_Type*) &MS_CTL->MS[23])                               /* 0x541C4170 */
#define MS_CTL_MS25                             ((MS_CTL_MS_Type*) &MS_CTL->MS[25])                               /* 0x541C4190 */
#define MS_CTL_MS26                             ((MS_CTL_MS_Type*) &MS_CTL->MS[26])                               /* 0x541C41A0 */
#define MS_CTL_MS27                             ((MS_CTL_MS_Type*) &MS_CTL->MS[27])                               /* 0x541C41B0 */
#define MS_CTL_MS28                             ((MS_CTL_MS_Type*) &MS_CTL->MS[28])                               /* 0x541C41C0 */
#define MS_CTL_MS_PC13                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[13])                         /* 0x541C50D0 */
#define MS_CTL_MS_PC14                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[14])                         /* 0x541C50E0 */
#define MS_CTL_MS_PC15                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[15])                         /* 0x541C50F0 */
#define MS_CTL_MS_PC19                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[19])                         /* 0x541C5130 */
#define MS_CTL_MS_PC23                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[23])                         /* 0x541C5170 */
#define MS_CTL_MS_PC25                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[25])                         /* 0x541C5190 */
#define MS_CTL_MS_PC26                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[26])                         /* 0x541C51A0 */
#define MS_CTL_MS_PC27                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[27])                         /* 0x541C51B0 */
#define MS_CTL_MS_PC28                          ((MS_CTL_MS_PC_Type*) &MS_CTL->MS_PC[28])                         /* 0x541C51C0 */

/*******************************************************************************
*                               APPCPUSS_SL_CTL
*******************************************************************************/

#define APPCPUSS_SL_CTL_BASE                    0x541C8000UL
#define APPCPUSS_SL_CTL                         ((APPCPUSS_SL_CTL_Type*) APPCPUSS_SL_CTL_BASE)                    /* 0x541C8000 */

/*******************************************************************************
*                                     PDM
*******************************************************************************/

#define PDM0_BASE                               0x54400000UL
#define PDM0                                    ((PDM_Type*) PDM0_BASE)                                           /* 0x54400000 */
#define PDM0_CH0                                ((PDM_CH_Type*) &PDM0->CH[0])                                     /* 0x54408000 */
#define PDM0_CH1                                ((PDM_CH_Type*) &PDM0->CH[1])                                     /* 0x54408100 */
#define PDM0_CH2                                ((PDM_CH_Type*) &PDM0->CH[2])                                     /* 0x54408200 */
#define PDM0_CH3                                ((PDM_CH_Type*) &PDM0->CH[3])                                     /* 0x54408300 */
#define PDM0_CH4                                ((PDM_CH_Type*) &PDM0->CH[4])                                     /* 0x54408400 */
#define PDM0_CH5                                ((PDM_CH_Type*) &PDM0->CH[5])                                     /* 0x54408500 */

/*******************************************************************************
*                                     TDM
*******************************************************************************/

#define TDM0_BASE                               0x54410000UL
#define TDM0                                    ((TDM_Type*) TDM0_BASE)                                           /* 0x54410000 */
#define TDM0_TDM_STRUCT0                        ((TDM_TDM_STRUCT_Type*) &TDM0->TDM_STRUCT[0])                     /* 0x54418000 */
#define TDM0_TDM_STRUCT1                        ((TDM_TDM_STRUCT_Type*) &TDM0->TDM_STRUCT[1])                     /* 0x54418200 */
#define TDM0_TDM_STRUCT0_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM0->TDM_STRUCT[0].TDM_TX_STRUCT) /* 0x54418000 */
#define TDM0_TDM_STRUCT1_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM0->TDM_STRUCT[1].TDM_TX_STRUCT) /* 0x54418200 */
#define TDM0_TDM_STRUCT0_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM0->TDM_STRUCT[0].TDM_RX_STRUCT) /* 0x54418100 */
#define TDM0_TDM_STRUCT1_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM0->TDM_STRUCT[1].TDM_RX_STRUCT) /* 0x54418300 */

/*******************************************************************************
*                                     SMIF
*******************************************************************************/

#define SMIF0_BASE                              0x54440000UL
#define SMIF1_BASE                              0x54480000UL
#define SMIF0                                   ((SMIF_STRUCT_Type*) SMIF0_BASE)                                  /* 0x54440000 */
#define SMIF1                                   ((SMIF_STRUCT_Type*) SMIF1_BASE)                                  /* 0x54480000 */
#define SMIF0_CACHE_BLOCK                       ((SMIF_CACHE_BLOCK_Type*) &SMIF0->CACHE_BLOCK)                    /* 0x54450000 */
#define SMIF1_CACHE_BLOCK                       ((SMIF_CACHE_BLOCK_Type*) &SMIF1->CACHE_BLOCK)                    /* 0x54490000 */
#define SMIF0_CACHE_BLOCK_MMIO                  ((SMIF_CACHE_BLOCK_MMIO_Type*) &SMIF0->CACHE_BLOCK.MMIO)          /* 0x54452000 */
#define SMIF1_CACHE_BLOCK_MMIO                  ((SMIF_CACHE_BLOCK_MMIO_Type*) &SMIF1->CACHE_BLOCK.MMIO)          /* 0x54492000 */
#define SMIF0_CACHE_BLOCK_CACHEBLK_AHB          ((SMIF_CACHE_BLOCK_CACHEBLK_AHB_Type*) &SMIF0->CACHE_BLOCK.CACHEBLK_AHB) /* 0x54454000 */
#define SMIF1_CACHE_BLOCK_CACHEBLK_AHB          ((SMIF_CACHE_BLOCK_CACHEBLK_AHB_Type*) &SMIF1->CACHE_BLOCK.CACHEBLK_AHB) /* 0x54494000 */
#define SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0     ((SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_Type*) &SMIF0->CACHE_BLOCK.CACHEBLK_AHB.MPC[0]) /* 0x54454000 */
#define SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0     ((SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_Type*) &SMIF1->CACHE_BLOCK.CACHEBLK_AHB.MPC[0]) /* 0x54494000 */
#define SMIF0_CORE                              ((SMIF_CORE_Type*) &SMIF0->CORE)                                  /* 0x54460000 */
#define SMIF1_CORE                              ((SMIF_CORE_Type*) &SMIF1->CORE)                                  /* 0x544A0000 */
#define SMIF0_CORE_SMIF_CRYPTO0                 ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE.SMIF_CRYPTO_BLOCK[0]) /* 0x54460200 */
#define SMIF0_CORE_SMIF_CRYPTO1                 ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE.SMIF_CRYPTO_BLOCK[1]) /* 0x54460280 */
#define SMIF0_CORE_SMIF_CRYPTO2                 ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE.SMIF_CRYPTO_BLOCK[2]) /* 0x54460300 */
#define SMIF0_CORE_SMIF_CRYPTO3                 ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE.SMIF_CRYPTO_BLOCK[3]) /* 0x54460380 */
#define SMIF1_CORE_SMIF_CRYPTO0                 ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF1->CORE.SMIF_CRYPTO_BLOCK[0]) /* 0x544A0200 */
#define SMIF1_CORE_SMIF_CRYPTO1                 ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF1->CORE.SMIF_CRYPTO_BLOCK[1]) /* 0x544A0280 */
#define SMIF1_CORE_SMIF_CRYPTO2                 ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF1->CORE.SMIF_CRYPTO_BLOCK[2]) /* 0x544A0300 */
#define SMIF1_CORE_SMIF_CRYPTO3                 ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF1->CORE.SMIF_CRYPTO_BLOCK[3]) /* 0x544A0380 */
#define SMIF0_CORE_DEVICE0                      ((SMIF_CORE_DEVICE_Type*) &SMIF0->CORE.DEVICE[0])                 /* 0x54460800 */
#define SMIF0_CORE_DEVICE1                      ((SMIF_CORE_DEVICE_Type*) &SMIF0->CORE.DEVICE[1])                 /* 0x54460880 */
#define SMIF0_CORE_DEVICE2                      ((SMIF_CORE_DEVICE_Type*) &SMIF0->CORE.DEVICE[2])                 /* 0x54460900 */
#define SMIF0_CORE_DEVICE3                      ((SMIF_CORE_DEVICE_Type*) &SMIF0->CORE.DEVICE[3])                 /* 0x54460980 */
#define SMIF1_CORE_DEVICE0                      ((SMIF_CORE_DEVICE_Type*) &SMIF1->CORE.DEVICE[0])                 /* 0x544A0800 */
#define SMIF1_CORE_DEVICE1                      ((SMIF_CORE_DEVICE_Type*) &SMIF1->CORE.DEVICE[1])                 /* 0x544A0880 */
#define SMIF1_CORE_DEVICE2                      ((SMIF_CORE_DEVICE_Type*) &SMIF1->CORE.DEVICE[2])                 /* 0x544A0900 */
#define SMIF1_CORE_DEVICE3                      ((SMIF_CORE_DEVICE_Type*) &SMIF1->CORE.DEVICE[3])                 /* 0x544A0980 */
#define SMIF0_CORE_AXI                          ((SMIF_CORE_AXI_Type*) &SMIF0->CORE.AXI)                          /* 0x54463000 */
#define SMIF1_CORE_AXI                          ((SMIF_CORE_AXI_Type*) &SMIF1->CORE.AXI)                          /* 0x544A3000 */
#define SMIF0_CORE_AXI_MPC0                     ((SMIF_CORE_AXI_MPC_Type*) &SMIF0->CORE.AXI.MPC[0])               /* 0x54463000 */
#define SMIF1_CORE_AXI_MPC0                     ((SMIF_CORE_AXI_MPC_Type*) &SMIF1->CORE.AXI.MPC[0])               /* 0x544A3000 */
#define SMIF0_CORE_SMIF_HSIOM                   ((SMIF_CORE_SMIF_HSIOM_Type*) &SMIF0->CORE.SMIF_HSIOM)            /* 0x54464000 */
#define SMIF1_CORE_SMIF_HSIOM                   ((SMIF_CORE_SMIF_HSIOM_Type*) &SMIF1->CORE.SMIF_HSIOM)            /* 0x544A4000 */
#define SMIF0_CORE_SMIF_HSIOM_SMIF_PRT0         ((SMIF_CORE_SMIF_HSIOM_SMIF_PRT_Type*) &SMIF0->CORE.SMIF_HSIOM.SMIF_PRT[0]) /* 0x54464000 */
#define SMIF0_CORE_SMIF_HSIOM_SMIF_PRT1         ((SMIF_CORE_SMIF_HSIOM_SMIF_PRT_Type*) &SMIF0->CORE.SMIF_HSIOM.SMIF_PRT[1]) /* 0x54464010 */
#define SMIF0_CORE_SMIF_HSIOM_SMIF_PRT2         ((SMIF_CORE_SMIF_HSIOM_SMIF_PRT_Type*) &SMIF0->CORE.SMIF_HSIOM.SMIF_PRT[2]) /* 0x54464020 */
#define SMIF1_CORE_SMIF_HSIOM_SMIF_PRT0         ((SMIF_CORE_SMIF_HSIOM_SMIF_PRT_Type*) &SMIF1->CORE.SMIF_HSIOM.SMIF_PRT[0]) /* 0x544A4000 */
#define SMIF1_CORE_SMIF_HSIOM_SMIF_PRT1         ((SMIF_CORE_SMIF_HSIOM_SMIF_PRT_Type*) &SMIF1->CORE.SMIF_HSIOM.SMIF_PRT[1]) /* 0x544A4010 */
#define SMIF1_CORE_SMIF_HSIOM_SMIF_PRT2         ((SMIF_CORE_SMIF_HSIOM_SMIF_PRT_Type*) &SMIF1->CORE.SMIF_HSIOM.SMIF_PRT[2]) /* 0x544A4020 */
#define SMIF0_CORE_SMIF_HSIOM_SMIF_SECURE_PRT0  ((SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_Type*) &SMIF0->CORE.SMIF_HSIOM.SMIF_SECURE_PRT[0]) /* 0x54465000 */
#define SMIF0_CORE_SMIF_HSIOM_SMIF_SECURE_PRT1  ((SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_Type*) &SMIF0->CORE.SMIF_HSIOM.SMIF_SECURE_PRT[1]) /* 0x54465010 */
#define SMIF0_CORE_SMIF_HSIOM_SMIF_SECURE_PRT2  ((SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_Type*) &SMIF0->CORE.SMIF_HSIOM.SMIF_SECURE_PRT[2]) /* 0x54465020 */
#define SMIF1_CORE_SMIF_HSIOM_SMIF_SECURE_PRT0  ((SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_Type*) &SMIF1->CORE.SMIF_HSIOM.SMIF_SECURE_PRT[0]) /* 0x544A5000 */
#define SMIF1_CORE_SMIF_HSIOM_SMIF_SECURE_PRT1  ((SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_Type*) &SMIF1->CORE.SMIF_HSIOM.SMIF_SECURE_PRT[1]) /* 0x544A5010 */
#define SMIF1_CORE_SMIF_HSIOM_SMIF_SECURE_PRT2  ((SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_Type*) &SMIF1->CORE.SMIF_HSIOM.SMIF_SECURE_PRT[2]) /* 0x544A5020 */
#define SMIF0_CORE_SMIF_GPIO                    ((SMIF_CORE_SMIF_GPIO_Type*) &SMIF0->CORE.SMIF_GPIO)              /* 0x54470000 */
#define SMIF1_CORE_SMIF_GPIO                    ((SMIF_CORE_SMIF_GPIO_Type*) &SMIF1->CORE.SMIF_GPIO)              /* 0x544B0000 */
#define SMIF0_CORE_SMIF_GPIO_SMIF_PRT0          ((SMIF_CORE_SMIF_GPIO_SMIF_PRT_Type*) &SMIF0->CORE.SMIF_GPIO.SMIF_PRT[0]) /* 0x54470000 */
#define SMIF0_CORE_SMIF_GPIO_SMIF_PRT1          ((SMIF_CORE_SMIF_GPIO_SMIF_PRT_Type*) &SMIF0->CORE.SMIF_GPIO.SMIF_PRT[1]) /* 0x54470080 */
#define SMIF0_CORE_SMIF_GPIO_SMIF_PRT2          ((SMIF_CORE_SMIF_GPIO_SMIF_PRT_Type*) &SMIF0->CORE.SMIF_GPIO.SMIF_PRT[2]) /* 0x54470100 */
#define SMIF1_CORE_SMIF_GPIO_SMIF_PRT0          ((SMIF_CORE_SMIF_GPIO_SMIF_PRT_Type*) &SMIF1->CORE.SMIF_GPIO.SMIF_PRT[0]) /* 0x544B0000 */
#define SMIF1_CORE_SMIF_GPIO_SMIF_PRT1          ((SMIF_CORE_SMIF_GPIO_SMIF_PRT_Type*) &SMIF1->CORE.SMIF_GPIO.SMIF_PRT[1]) /* 0x544B0080 */
#define SMIF1_CORE_SMIF_GPIO_SMIF_PRT2          ((SMIF_CORE_SMIF_GPIO_SMIF_PRT_Type*) &SMIF1->CORE.SMIF_GPIO.SMIF_PRT[2]) /* 0x544B0100 */

/*******************************************************************************
*                                     U55
*******************************************************************************/

#define U550_BASE                               0x54600000UL
#define U550                                    ((U55_Type*) U550_BASE)                                           /* 0x54600000 */
#define U550_BASE_1_0                           ((U55_BASE_1_0_Type*) &U550->BASE_1_0)                            /* 0x54600000 */
#define U550_BASE_POINTERS_1_0                  ((U55_BASE_POINTERS_1_0_Type*) &U550->BASE_POINTERS_1_0)          /* 0x54600080 */
#define U550_PAGE_PMU_1_0                       ((U55_PAGE_PMU_1_0_Type*) &U550->PAGE_PMU_1_0)                    /* 0x54600100 */
#define U550_PAGE_ID_1_0                        ((U55_PAGE_ID_1_0_Type*) &U550->PAGE_ID_1_0)                      /* 0x54600F00 */
#define U550_MXU55_CTL_1_0                      ((U55_MXU55_CTL_1_0_Type*) &U550->MXU55_CTL_1_0)                  /* 0x54601000 */
#define U550_MXU55_PPU                          ((U55_MXU55_PPU_Type*) &U550->MXU55_PPU)                          /* 0x54602000 */
#define U550_PD                                 ((U55_PD_Type*) &U550->PD)                                        /* 0x54603000 */

/*******************************************************************************
*                                    SOCMEM
*******************************************************************************/

#define SOCMEM_BASE                             0x54640000UL
#define SOCMEM                                  ((SOCMEM_Type*) SOCMEM_BASE)                                      /* 0x54640000 */
#define SOCMEM_SRAM                             ((SOCMEM_SRAM_Type*) &SOCMEM->SRAM)                               /* 0x54642000 */
#define SOCMEM_SRAM_MPC0                        ((SOCMEM_SRAM_MPC_Type*) &SOCMEM->SRAM.MPC[0])                    /* 0x54642000 */
#define SOCMEM_PORT_STRUCT0                     ((SOCMEM_PORT_STRUCT_Type*) &SOCMEM->PORT_STRUCT[0])              /* 0x54650000 */
#define SOCMEM_PORT_STRUCT1                     ((SOCMEM_PORT_STRUCT_Type*) &SOCMEM->PORT_STRUCT[1])              /* 0x54651000 */
#define SOCMEM_PORT_STRUCT2                     ((SOCMEM_PORT_STRUCT_Type*) &SOCMEM->PORT_STRUCT[2])              /* 0x54652000 */
#define SOCMEM_PORT_STRUCT3                     ((SOCMEM_PORT_STRUCT_Type*) &SOCMEM->PORT_STRUCT[3])              /* 0x54653000 */
#define SOCMEM_PORT_STRUCT4                     ((SOCMEM_PORT_STRUCT_Type*) &SOCMEM->PORT_STRUCT[4])              /* 0x54654000 */
#define SOCMEM_PPU_SOCMEM                       ((SOCMEM_PPU_SOCMEM_Type*) &SOCMEM->PPU_SOCMEM)                   /* 0x54660000 */
#define SOCMEM_SOCMEM                           ((SOCMEM_SOCMEM_Type*) &SOCMEM->SOCMEM)                           /* 0x54661000 */
#define SOCMEM_SOCMEM_PD                        ((SOCMEM_SOCMEM_PD_Type*) &SOCMEM->SOCMEM.PD)                     /* 0x54661000 */

/*******************************************************************************
*                                    GFXSS
*******************************************************************************/

#define GFXSS_BASE                              0x54800000UL
#define GFXSS                                   ((GFXSS_Type*) GFXSS_BASE)                                        /* 0x54800000 */
#define GFXSS_GFXSS_GPU                         ((GFXSS_GPU_Type*) &GFXSS->GFXSS_GPU)                             /* 0x54800000 */
#define GFXSS_GFXSS_GPU_MXGPU                   ((GFXSS_GPU_MXGPU_Type*) &GFXSS->GFXSS_GPU.MXGPU)                 /* 0x54800000 */
#define GFXSS_GFXSS_GPU_GCNANO                  ((GFXSS_GPU_GCNANO_Type*) &GFXSS->GFXSS_GPU.GCNANO)               /* 0x54800800 */
#define GFXSS_GFXSS_DC                          ((GFXSS_DC_Type*) &GFXSS->GFXSS_DC)                               /* 0x54801000 */
#define GFXSS_GFXSS_DC_MXDC                     ((GFXSS_DC_MXDC_Type*) &GFXSS->GFXSS_DC.MXDC)                     /* 0x54801000 */
#define GFXSS_GFXSS_DC_DCNANO                   ((GFXSS_DC_DCNANO_Type*) &GFXSS->GFXSS_DC.DCNANO)                 /* 0x54801800 */
#define GFXSS_GFXSS_MIPIDSI                     ((GFXSS_MIPIDSI_Type*) &GFXSS->GFXSS_MIPIDSI)                     /* 0x54802000 */
#define GFXSS_GFXSS_MIPIDSI_MXMIPIDSI           ((GFXSS_MIPIDSI_MXMIPIDSI_Type*) &GFXSS->GFXSS_MIPIDSI.MXMIPIDSI) /* 0x54802000 */
#define GFXSS_GFXSS_MIPIDSI_DWCMIPIDSI          ((GFXSS_MIPIDSI_DWCMIPIDSI_Type*) &GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI) /* 0x54803000 */

/*******************************************************************************
*                                     SDHC
*******************************************************************************/

#define SDHC0_BASE                              0x54810000UL
#define SDHC1_BASE                              0x54820000UL
#define SDHC0                                   ((SDHC_Type*) SDHC0_BASE)                                         /* 0x54810000 */
#define SDHC1                                   ((SDHC_Type*) SDHC1_BASE)                                         /* 0x54820000 */
#define SDHC0_WRAP                              ((SDHC_WRAP_Type*) &SDHC0->WRAP)                                  /* 0x54810000 */
#define SDHC1_WRAP                              ((SDHC_WRAP_Type*) &SDHC1->WRAP)                                  /* 0x54820000 */
#define SDHC0_CORE                              ((SDHC_CORE_Type*) &SDHC0->CORE)                                  /* 0x54811000 */
#define SDHC1_CORE                              ((SDHC_CORE_Type*) &SDHC1->CORE)                                  /* 0x54821000 */

/*******************************************************************************
*                                    USBHS
*******************************************************************************/

#define USBHS_BASE                              0x54900000UL
#define USBHS                                   ((USBHS_Type*) USBHS_BASE)                                        /* 0x54900000 */
#define USBHS_DWC_OTG_INTREG                    ((USBHS_DWC_OTG_INTREG_Type*) &USBHS->DWC_OTG_INTREG)             /* 0x54900000 */
#define USBHS_SS                                ((USBHS_SS_Type*) &USBHS->SS)                                     /* 0x54940000 */

/** \} PSE846GPS2DBZC4A */

#endif /* _PSE846GPS2DBZC4A_S_H_ */


/* [] END OF FILE */
