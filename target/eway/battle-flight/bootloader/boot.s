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

.global boot_g_pfnVectors
.global boot.Default_Handler

.extern g_pfnVectors

// Vector Table
.section .boot.isr_vector,"a",%progbits
boot_g_pfnVectors:
  .word  _estack
  .word  Boot_Handler
  .word  NMI_Handler
  .word  HardFault_Handler
  .word  MemManage_Handler
  .word  BusFault_Handler
  .word  UsageFault_Handler
  .word  0
  .word  0
  .word  0
  .word  0
  .word  SVC_Handler
  .word  DebugMon_Handler
  .word  0
  .word  PendSV_Handler
  .word  SysTick_Handler
  
.type  boot_g_pfnVectors, %object
.size  boot_g_pfnVectors, .-boot_g_pfnVectors

.equ UART7_BASE ,  0x40015400
.equ UART7_STS  ,  0x00
.equ UART7_DAT  ,  0x04
.equ UART7_BRCF ,  0x08
.equ UART7_CTRL0,  0x0C

.equ RCC_BASE   , 0x40021000
.equ RCC_APB2ENR, 0x18
.equ RCC_APB1ENR, 0x1C

.equ PWR_BASE   , 0x40007000
.equ PWR_CTRL3  , 0x0C

.equ GPIOC_BASE , 0x40011000
.equ GPIO_PL    , 0x00

.equ FLASH_BASE , 0x40022000
.equ FLASH_KEYR , 0x04
.equ FLASH_STS  , 0x0C
.equ FLASH_CTRL , 0x10
.equ FLASH_ADDR , 0x14

// Ymodem 常量定义
.equ SOH, 0x01     // 数据包开始 (128字节)
.equ STX, 0x02     // 数据包开始（1024字节）
.equ EOT, 0x04     // 传输结束
.equ ACK, 0x06     // 确认
.equ NAK, 0x15     // 否定确认
.equ CAN, 0x18     // 取消传输
.equ CRC16, 0x43   // 'C' - CRC16模式

// 复位处理程序
.section .boot.text,"ax",%progbits
.weak Boot_Handler
.type Boot_Handler, %function
Boot_Handler:
    // 设置栈指针
    ldr sp, =_estack
    
    // 初始化时钟和外设
    @ bl SystemInit
    
    // 主BootLoader循环
    @ bl Ymodem_Receive
    
    // 如果返回，跳转到应用程序
    ldr r0, =g_pfnVectors
    ldr r1, [r0]        // 加载栈指针
    ldr r2, [r0, #4]    // 加载复位向量
    
    // 设置新的栈指针
    mov sp, r1
    
    // 跳转到应用程序
    bx r2
    
    // 无限循环（永不执行到这里）
    b .

.type SystemInit, %function
// 系统初始化
SystemInit:
    // 启用GPIOC和UART7时钟
    ldr r0, =RCC_BASE
    ldr r1, =0x10000000    // PWR使能
    str r1, [r0, #RCC_APB1ENR]

    ldr r0, =PWR_BASE
    ldr r1, [r0, #PWR_CTRL3]
    orr r1, r1, #0x00000001    // 置位BKPM
    str r1, [r0, #PWR_CTRL3]

    ldr r0, =RCC_BASE
    ldr r1, =0             // PWR时钟关闭
    str r1, [r0, #RCC_APB1ENR]
    ldr r1, =0x00040011    // GPIOC,AFIO和UART7使能
    str r1, [r0, #RCC_APB2ENR]
    
    // 配置PC4为TX，PC5为RX
    ldr r0, =GPIOC_BASE
    // PC4 (TX) - AF推挽输出，2MHz
    // PC5 (RX) - 浮空输入
    ldr r1, =0x00490000    // PC4: AF推挽，PC5: 浮空输入
    str r1, [r0, #GPIO_PL]

    // 设置波特率 (115200 @ 8MHz PCLK1 = 8MHz)
    ldr r0, =UART7_BASE
    ldr r1, =0x00000045    // 115200: 8MHz/115200/16 = 4.3125
    str r1, [r0, #UART7_BRCF]
    
    // 启用UART，8位数据，无奇偶校验，1停止位
    ldr r1, =0x200C        // UE = 1, TE = 1, RE = 1
    str r1, [r0, #UART7_CTRL0]
    
    bx lr

.type UART7_SendChar, %function
// 发送一个字符
UART7_SendChar:
    push {r1-r2, lr}
    
    ldr r1, =UART7_BASE
wait_txe:
    ldr r2, [r1, #UART7_STS]
    tst r2, #0x80     // 检查TXE位
    beq wait_txe
    
    strb r0, [r1, #UART7_DAT]
    
    pop {r1-r2, pc}

.type UART7_ReceiveChar, %function
// 接收一个字符（带超时）
UART7_ReceiveChar:
    push {r1-r3, lr}
    
    ldr r1, =UART7_BASE
    ldr r2, =0xFFFF       // 超时计数
    
receive_timeout:
    ldr r3, [r1, #UART7_STS]
    tst r3, #0x20     // 检查RXNE位
    bne char_received
    
    subs r2, r2, #1
    bne receive_timeout
    
    // 超时
    ldr r0, =0xFFFF        // 超时返回0xFFFF
    b receive_done
    
char_received:
    ldrb r0, [r1, #UART7_DAT]
    
receive_done:
    pop {r1-r3, pc}

.type Calc_CRC16, %function
// 计算CRC16
// 输入: r0 = 数据地址, r1 = 数据长度
// 输出: r0 = CRC16值
Calc_CRC16:
    push {r1-r5, lr}
    
    // YMODEM CRC-16参数:
    // 多项式: 0x1021 (x^16 + x^12 + x^5 + 1)
    // 初始值: 0x0000
    // 输出异或: 0x0000
    // 输入反转: false
    // 输出反转: false
    
    mov r2, #0             // crc = 0
    ldr r3, =0x1021        // 多项式
    
crc_loop:
    cmp r1, #0
    beq crc_done
    
    ldrb r4, [r0], #1      // 读取数据字节
    eor r2, r2, r4, lsl #8 // crc ^= (data << 8)
    
    mov r5, #8             // 处理8位
    
crc_bit_loop:
    lsl r4, r2, #1         // crc <<= 1
    ands r2, #0x8000       // 检查最高位
    beq crc_no_xor         // 如果最高位为0，跳过异或
    
    eor r4, r4, r3         // crc ^= poly
    
crc_no_xor:
    mov r2, r4
    subs r5, r5, #1
    bne crc_bit_loop
    
    subs r1, r1, #1
    b crc_loop
    
crc_done:
    // 确保只返回16位
    ldr r0, =0x0000FFFF
    and r2, r2, r0
    mov r0, r2
    
    pop {r1-r5, pc}

.type Ymodem_Receive, %function
// Ymodem接收主函数
Ymodem_Receive:
    push {lr}
    
    mov r4, #0             // 包序号
    ldr r5, =g_pfnVectors  // 目标地址
    ldr r6, =0x20000000    // 接收缓冲区
    
    // 发送'C'开始CRC16模式传输
    mov r0, #CRC16
    bl UART7_SendChar
    
    mov r7, #3            // 重试计数
    
ymodem_loop:
    // 接收包起始字节
    bl UART7_ReceiveChar
    cmp r0, #0xFF
    bgt timeout

    mov r12, r0             // 保存起始字节
    
    // 检查包类型
    cmp r12, #SOH
    beq receive_data_packet
    cmp r12, #STX
    beq receive_data_packet
    cmp r12, #EOT
    beq receive_eot
    cmp r12, #CAN
    beq receive_cancel
    
    // 无效包，发送NAK重试
    b send_nak

receive_data_packet:
    // 接收包序号
    bl UART7_ReceiveChar
    mov r8, r0             // 包序号
    
    // 接收包序号补码
    bl UART7_ReceiveChar
    mov r9, r0             // 包序号补码
    
    // 验证包序号
    add r0, r8, r9
    cmp r0, #0xFF
    bne bad_packet
    
    mov r10, r6             // 缓冲区指针
    cmp r12, #SOH
    ite eq
    moveq r11, #130          // SOH字节计数
    movne r11, #1026         // STX字节计数
    
receive_data_loop:
    bl UART7_ReceiveChar
    cmp r0, #0xFF
    bgt timeout
    
    strb r0, [r10], #1
    subs r11, r11, #1
    bne receive_data_loop
    
    // 验证包序号
    cmp r8, r4
    bne bad_packet_seq
    
    // 计算CRC16
    mov r0, r6              // 数据地址
    cmp r12, #SOH
    ite eq
    moveq r1, #128          // SOH数据长度
    movne r1, #1024         // STX数据长度

    bl Calc_CRC16
    
    // 比较CRC
    cmp r12, #SOH
    ite eq
    ldrbeq r1, [r6, #129]   // SOH接收的CRC高字节
    ldrbne r1, [r6, #1025]   // STX接收的CRC高字节
    cmp r12, #SOH
    ite eq
    ldrbeq r2, [r6, #128]   // SOH接收的CRC低字节
    ldrbne r2, [r6, #1024]   // STX接收的CRC低字节
    orr r1, r1, r2, lsl #8
    
    cmp r0, r1
    bne bad_packet

    cmp r8, #0
    beq pass              // 包序号为0，直接ACK

    ldr r8, =0x07FF
    tst r5, r8            // 2K为一个扇区
    bne no_erase          // 不是扇区开头，直接复制数据

    ldr r0, =FLASH_BASE    // FLASH基地址
    ldr r1, [r0, #FLASH_STS]
wait_flash_ready:
    tst r1, #0x01    // 检查BUSY位
    bne wait_flash_ready

    ldr r1, [r0, #FLASH_CTRL]
    tst r1, #0x80    // 检查LOCK位
    beq flash_unlocked

    ldr r1, =0x45670123
    str r1, [r0, #FLASH_KEYR]
    ldr r1, =0xCDEF89AB
    str r1, [r0, #FLASH_KEYR]

    ldr r1, [r0, #FLASH_CTRL]
    tst r1, #0x80    // 检查LOCK位
    bne ymodem_failed

flash_unlocked:
    ldr r1, [r0, #FLASH_CTRL]
    orr r1, r1, #0x02     // 设置PER位
    str r1, [r0, #FLASH_CTRL]

    str r5, [r0, #FLASH_ADDR] // 设置擦除页起始地址

    ldr r1, [r0, #FLASH_CTRL]
    orr r1, r1, #0x40     // 设置START位
    str r1, [r0, #FLASH_CTRL]

    // 等待擦除完成
wait_erase:
    ldr r1, [r0, #FLASH_STS]
    tst r1, #0x60    // 检查EOP和EVERR位
    beq wait_erase

    tst r1, #0x40    // 检查EVERR位
    bne ymodem_failed

    ldr r1, [r0, #FLASH_CTRL]
    and r1, r1, #0xFFFFFFFD     // 清除PER位
    str r1, [r0, #FLASH_CTRL]

    ldr r1, [r0, #FLASH_STS]
    orr r1, r1, #0x20     // 清除EOP位
    str r1, [r0, #FLASH_STS]
    
no_erase:
    ldr r0, =FLASH_BASE    // FLASH基地址
    ldr r1, [r0, #FLASH_STS]
wait_flash_ready2:
    tst r1, #0x01    // 检查BUSY位
    bne wait_flash_ready2

    orr r1, r1, #0x01     // 设置PG位
    str r1, [r0, #FLASH_CTRL]

    mov r8, r0
    mov r9, r1

    // 复制数据到目标地址
    mov r0, r6            // 源地址
    mov r1, r5            // 目标地址
    cmp r12, #SOH
    ite eq
    moveq r2, #128        // SOH数据长度
    movne r2, #1024       // STX数据长度

copy_loop:
    ldr r3, [r0], #4
    str r3, [r1], #4
wait_program:
    ldr r9, [r8, #FLASH_STS]
    tst r9, #0x2C    // 检查EOP,PGERR和PVERR位
    bne wait_program

    tst r9, #0x0C    // 检查PGERR和PVERR位
    bne ymodem_failed

    orr r9, r9, #0x20     // 清除EOP位
    str r9, [r8, #FLASH_STS]
    subs r2, r2, #4
    bne copy_loop

    ldr r9, [r8, #FLASH_CTRL]
    and r9, r9, #0xFFFFFFFE     // 清除PG位
    str r9, [r8, #FLASH_CTRL]
    
    mov r5, r1            // 更新目标地址
    
pass:
    // 发送ACK
    mov r0, #ACK
    bl UART7_SendChar

    cmp r8, #0
    bne pass1              // 包序号为0，直接ACK

    // 延时确保ACK发送完成
    ldr r0, =0xFFF
pass_delay:
    subs r0, r0, #1
    bne pass_delay

    mov r0, #CRC16
    bl UART7_SendChar
    
pass1:
    // 递增包序号
    add r4, r4, #1
    
    // 重置重试计数
    mov r7, #3
    b ymodem_loop

bad_packet_seq:
    // 包序号错误，可能是重复包
    // 如果是重复包，发送ACK
    sub r0, r8, #1
    cmp r0, r4
    beq send_ack_dup
    
    b bad_packet

send_ack_dup:
    mov r0, #ACK
    bl UART7_SendChar
    b ymodem_loop

bad_packet:
    // 发送NAK
send_nak:
    mov r0, #NAK
    bl UART7_SendChar
    
    // 减少重试计数
    subs r7, r7, #1
    bne ymodem_loop
    
    // 重试次数耗尽
    b ymodem_failed

timeout:
    // 发送NAK继续等待
    mov r0, #NAK
    bl UART7_SendChar
    
    subs r7, r7, #1
    bne ymodem_loop
    
    b ymodem_failed

receive_eot:
    // 接收完成
    mov r0, #ACK
    bl UART7_SendChar
    
    // 延时确保ACK发送完成
    ldr r0, =0xFFFF
delay_loop:
    subs r0, r0, #1
    bne delay_loop
    
    // 再发送一个ACK
    mov r0, #ACK
    bl UART7_SendChar
    
    mov r0, #0            // 成功
    b ymodem_exit

receive_cancel:
    // 发送方取消传输
    mov r0, #1            // 失败
    b ymodem_exit

ymodem_failed:
    // 传输失败，发送CAN
    mov r0, #CAN
    bl UART7_SendChar
    mov r0, #CAN
    bl UART7_SendChar
    mov r0, #CAN
    bl UART7_SendChar
    mov r0, #CAN
    bl UART7_SendChar
    mov r0, #CAN
    bl UART7_SendChar
    
    mov r0, #2            // 失败

ymodem_exit:
    pop {pc}

// Default exception handlers
.type Default_Handler, %function
Default_Handler:
    Infinite_Loop:
        b Infinite_Loop
    .size Default_Handler, .-Default_Handler

// Provide weak aliases for each exception handler
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
