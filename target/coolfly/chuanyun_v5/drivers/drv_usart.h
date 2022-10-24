/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef DRV_USART_H__
#define DRV_USART_H__

#include <firmament.h>
#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AR_UART0_BASE       0x40500000      /* 0x40500000-0x4050ffff: UART0 */
#define AR_UART1_BASE       0x40510000      /* 0x40500000-0x4051ffff: UART1 */
#define AR_UART2_BASE       0x40520000      /* 0x40500000-0x4052ffff: UART2 */
#define AR_UART3_BASE       0x40530000      /* 0x40500000-0x4053ffff: UART3 */
#define AR_UART4_BASE       0x40540000      /* 0x40500000-0x4054ffff: UART4 */
#define AR_UART5_BASE       0x40550000      /* 0x40500000-0x4055ffff: UART5 */
#define AR_UART6_BASE       0x40560000      /* 0x40500000-0x4056ffff: UART6 */
#define AR_UART7_BASE       0x40570000      /* 0x40570000-0x4057ffff: UART6 */



#define ARCFG_UART_RXBUFF_SIZE      600
#define ARCFG_UART_TXBUFF_SIZE      1000

#define ARCFG_UART0_RXBUFF      ARCFG_UART_RXBUFF_SIZE
#define ARCFG_UART0_TXBUFF      ARCFG_UART_TXBUFF_SIZE

#define AR_UART_RBR_OFFSET        0x0000
#define AR_UART_THR_OFFSET        0x0000
#define AR_UART_DLL_OFFSET        0x0000
#define AR_UART_DLH_OFFSET        0x0004
#define AR_UART_IER_OFFSET        0x0004
#define AR_UART_IIR_OFFSET        0x0008
#define AR_UART_FCR_OFFSET        0x0008
#define AR_UART_LCR_OFFSET        0x000c
#define AR_UART_MCR_OFFSET        0x0010
#define AR_UART_LSR_OFFSET        0x0014
#define AR_UART_MSR_OFFSET        0x0018
#define AR_UART_SCR_OFFSET        0x001c
#define AR_UART_LPDLL_OFFSET      0x0020
#define AR_UART_LPDLH_OFFSET      0x0024


#define AR_UART_USR_OFFSET        0x007c

/* Register bit definitions *********************************************************/
/* RBR (DLAB =0) Receiver Buffer Register (all) */

#define UART_RBR_MASK                (0xff)    /* Bits 0-7: Oldest received byte in RX FIFO */
                                               /* Bits 8-31: Reserved */

/* THR (DLAB =0) Transmit Holding Register (all) */

#define UART_THR_MASK                (0xff)    /* Bits 0-7: Adds byte to TX FIFO */
                                               /* Bits 8-31: Reserved */

/* DLL (DLAB =1) Divisor Latch LSB (all) */

#define UART_DLL_MASK                (0xff)    /* Bits 0-7: DLL */
                                               /* Bits 8-31: Reserved */

/* DLM (DLAB =1) Divisor Latch MSB (all) */

#define UART_DLH_MASK                (0xff)    /* Bits 0-7: DLH */
                                               /* Bits 8-31: Reserved */


/* IER (DLAB =0) Interrupt Enable Register (all) */

#define UART_IER_ERBFI               (1 << 0)  /* Bit 0: RBR Interrupt Enable */
#define UART_IER_ETBEI               (1 << 1)  /* Bit 1: THRE Interrupt Enable */
#define UART_IER_ELSI                (1 << 2)  /* Bit 2: RX Line Status Interrupt Enable */
#define UART_IER_EDSSI               (1 << 3)  /* Bit 3: Modem Status Interrupt Enable */
                                               /* Bits 4-6: Reserved */
#define UART_IER_PTIME               (1 << 7)  /* Bit 7: Programmable THRE Interrupt Mode Enable */

#define UART_IER_ALLIE               (0x008f)



// /* IIR Interrupt ID Register (all) */

#define UART_IIR_INTID_SHIFT         (0)       /* Bits 0-3: Interrupt identification */
#define UART_IIR_INTID_MASK          (15 << UART_IIR_INTID_SHIFT)

#define UART_IIR_INTID_MSI           (0 << UART_IIR_INTID_SHIFT) /* Modem Status  */
#define UART_IIR_INTID_NIP           (1 << UART_IIR_INTID_SHIFT) /* no interrupt pending */
#define UART_IIR_INTID_THRE          (2 << UART_IIR_INTID_SHIFT) /* THR empty */
#define UART_IIR_INTID_RDA           (4 << UART_IIR_INTID_SHIFT) /* Receive Data Available (RDA) */
#define UART_IIR_INTID_RLS           (6 << UART_IIR_INTID_SHIFT) /* Receive Line Status (RLS) */
// #define UART_IIR_INTID_BUSY          (7 << UART_IIR_INTID_SHIFT) /* busy detect */
#define UART_IIR_INTID_CTI           (12 << UART_IIR_INTID_SHIFT) /* 2b - Character Time-out Indicator (CTI) */
                                               /* Bits 4-5: Reserved */

#define UART_IIR_FIFOEN_SHIFT        (6)       /* Bits 6-7: Copies of FCR bit 0 */
#define UART_IIR_FIFOEN_MASK         (3 << UART_IIR_FIFOEN_SHIFT)

#define UART_IIR_FIFOEN_ENABLE       (0 << UART_IIR_FIFOEN_SHIFT) /* ENABLE Status  */
#define UART_IIR_FIFOEN_DISABLE      (3 << UART_IIR_FIFOEN_SHIFT) /* DISABLE Status  */
                                               /* Bits 8-31: Reserved */


/* FCR FIFO Control Register (all) */

#define UART_FCR_FIFOEN              (1 << 0)  /* Bit 0:  Enable FIFOs */

#define UART_FCR_RXRST               (1 << 1)  /* Bit 1:  RX FIFO Reset */
#define UART_FCR_TXRST               (1 << 2)  /* Bit 2:  TX FIFO Reset */

// #define UART_FCR_DMAMODE             (1 << 3)  /* Bit 3:  DMA Mode Select */


// #define UART_FCR_TXTRIGGER_SHIFT     (4)       /* Bits 4-5:TX Empty Trigger */
// #define UART_FCR_TXTRIGGER_MASK      (3 << UART_FCR_TXTRIGGER_SHIFT)
// #define UART_FCR_TXTRIGGER_0         (0 << UART_FCR_TXTRIGGER_SHIFT) /* Trigger level 0 (empty) */
// #define UART_FCR_TXTRIGGER_4         (1 << UART_FCR_TXTRIGGER_SHIFT) /* Trigger level 1 (2 characters) */
// #define UART_FCR_TXTRIGGER_8         (2 << UART_FCR_TXTRIGGER_SHIFT) /* Trigger level 2 (1/4) */
// #define UART_FCR_TXTRIGGER_14        (3 << UART_FCR_TXTRIGGER_SHIFT) /* Trigger level 3 (1/2) */

#define UART_FCR_RXTRIGGER_SHIFT     (6)       /* Bits 6-7: RX Trigger Level */
#define UART_FCR_RXTRIGGER_MASK      (3 << UART_FCR_RXTRIGGER_SHIFT)
#define UART_FCR_RXTRIGGER_0         (0 << UART_FCR_RXTRIGGER_SHIFT) /* Trigger level 0 (1 character) */
#define UART_FCR_RXTRIGGER_4         (1 << UART_FCR_RXTRIGGER_SHIFT) /* Trigger level 1 (4 characters) */
#define UART_FCR_RXTRIGGER_8         (2 << UART_FCR_RXTRIGGER_SHIFT) /* Trigger level 2 (8 characters) */
#define UART_FCR_RXTRIGGER_14        (3 << UART_FCR_RXTRIGGER_SHIFT) /* Trigger level 3 (14 characters) */
//                                                /* Bits 8-31: Reserved */

// /* LCR Line Control Register (all) */

#define UART_LCR_DLS_SHIFT           (0)       /* Bit 0-1: Word Length Select */
#define UART_LCR_DLS_MASK            (3 << UART_LCR_DLS_SHIFT)

#define UART_LCR_DLS_5BIT            (0 << UART_LCR_DLS_SHIFT)
#define UART_LCR_DLS_6BIT            (1 << UART_LCR_DLS_SHIFT)
#define UART_LCR_DLS_7BIT            (2 << UART_LCR_DLS_SHIFT)
#define UART_LCR_DLS_8BIT            (3 << UART_LCR_DLS_SHIFT)

// #define UART_LCR_STOP                (1 << 2)  /* Bit 2:  Stop Bit Select */

#define UART_LCR_PE                  (1 << 3)  /* Bit 3:  Parity Enable */

#define UART_LCR_PS_SHIFT            (4)       /* Bits 4-5: Parity Select */
#define UART_LCR_PS_MASK             (3 << UART_LCR_PS_SHIFT)
#define UART_LCR_PS_ODD              (0 << UART_LCR_PS_SHIFT) /* Odd parity */
#define UART_LCR_PS_EVEN             (1 << UART_LCR_PS_SHIFT) /* Even Parity */
#define UART_LCR_PS_STICK1           (2 << UART_LCR_PS_SHIFT) /* Forced "1" stick parity */
#define UART_LCR_PS_STICK0           (3 << UART_LCR_PS_SHIFT) /* Forced "0" stick parity */



                                               
rt_err_t drv_usart_init(void);

void ar_uart_init(unsigned char index, unsigned int baud_rate);
int BOOT_Printf(const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* __DRV_USART_H__ */

