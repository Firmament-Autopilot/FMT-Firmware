/*
 * Author: Pedro Pereira
 */

#ifndef CANARD_GD32F4XX_BXCAN_H
#define CANARD_GD32F4XX_BXCAN_H

#include <stdint.h>
#include <gd32f4xx.h>// TODO: substitute include for independent variable and macro declaration

typedef struct
{
    volatile uint32_t TMI0;
    volatile uint32_t TMP0;
    volatile uint32_t TMDATA00;
    volatile uint32_t TMDATA10;
} CanardGD32TxMailboxType;

typedef struct
{
    volatile uint32_t RFIFOMI0;
    volatile uint32_t RFIFOMP0;
    volatile uint32_t RFIFOMDATA00;
    volatile uint32_t RFIFOMDATA10;
} CanardGD32RxMailboxType;

typedef struct
{
    CanardGD32TxMailboxType TxMailbox[3];
    CanardGD32RxMailboxType RxMailbox[2];
} CanardGD32MailboxType;    

typedef struct
{
    volatile uint32_t RFIFO[2];    ///< CAN receive FIFO 0 register 0x00C , CAN receive FIFO 1 register         0x010
} CanardGD32RxFIFOType;

typedef struct
{
    uint32_t fdcan_base;
    uint64_t error_cnt;
    uint32_t served_aborts_cnt;
    uint64_t rx_overflow_count;
} FdCANIface;

typedef enum {
    can1 = 0,
    can2 = 1
} FDCanID;
#endif                                 // CANARD_GD32F4XX_BXCAN_H
