/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#ifndef SERIAL_H__
#define SERIAL_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* serial configuration */
#define BAUD_RATE_2400    2400
#define BAUD_RATE_4800    4800
#define BAUD_RATE_9600    9600
#define BAUD_RATE_19200   19200
#define BAUD_RATE_38400   38400
#define BAUD_RATE_57600   57600
#define BAUD_RATE_115200  115200
#define BAUD_RATE_230400  230400
#define BAUD_RATE_460800  460800
#define BAUD_RATE_921600  921600
#define BAUD_RATE_2000000 2000000
#define BAUD_RATE_3000000 3000000

#define DATA_BITS_5 5
#define DATA_BITS_6 6
#define DATA_BITS_7 7
#define DATA_BITS_8 8
#define DATA_BITS_9 9

#define STOP_BITS_1 0
#define STOP_BITS_2 1
#define STOP_BITS_3 2
#define STOP_BITS_4 3

#ifdef _WIN32
    #include <windows.h>
#else
    #define PARITY_NONE 0
    #define PARITY_ODD  1
    #define PARITY_EVEN 2
#endif

#define BIT_ORDER_LSB 0
#define BIT_ORDER_MSB 1

#define NRZ_NORMAL   0 /* Non Return to Zero : normal mode */
#define NRZ_INVERTED 1 /* Non Return to Zero : inverted mode */

#ifndef SERIAL_RB_BUFSZ
    #define SERIAL_RB_BUFSZ 256
#endif

/* serial isr event */
#define SERIAL_EVENT_RX_IND     0x01 /* Rx indication */
#define SERIAL_EVENT_TX_DONE    0x02 /* Tx complete   */
#define SERIAL_EVENT_RX_DMADONE 0x03 /* Rx DMA transfer done */
#define SERIAL_EVENT_TX_DMADONE 0x04 /* Tx DMA transfer done */
#define SERIAL_EVENT_RX_TIMEOUT 0x05 /* Rx timeout    */

/* serial dma transfer direction */
#define SERIAL_DMA_RX 0x01
#define SERIAL_DMA_TX 0x02

#define SERIAL_RX_INT 0x01
#define SERIAL_TX_INT 0x02

#define SERIAL_ERR_OVERRUN 0x01
#define SERIAL_ERR_FRAMING 0x02
#define SERIAL_ERR_PARITY  0x03

/* Default config for serial_configure structure */
#define SERIAL_DEFAULT_CONFIG                     \
    {                                             \
        BAUD_RATE_57600,     /* 57600 bits/s */   \
            DATA_BITS_8,     /* 8 databits */     \
            STOP_BITS_1,     /* 1 stopbit */      \
            PARITY_NONE,     /* No parity  */     \
            BIT_ORDER_LSB,   /* LSB first sent */ \
            NRZ_NORMAL,      /* Normal mode */    \
            SERIAL_RB_BUFSZ, /* Buffer size */    \
            0                                     \
    }

struct serial_configure {
    rt_uint32_t baud_rate;

    rt_uint32_t data_bits : 4;
    rt_uint32_t stop_bits : 2;
    rt_uint32_t parity : 2;
    rt_uint32_t bit_order : 1;
    rt_uint32_t invert : 1;
    rt_uint32_t bufsz : 16;
    rt_uint32_t reserved : 4;
};

/*
 * Serial FIFO mode
 */
struct serial_rx_fifo {
    /* software fifo */
    rt_uint8_t* buffer;

    rt_uint16_t put_index, get_index;

    rt_bool_t is_full;
};

struct serial_tx_fifo {
    struct rt_completion completion;
};

/*
 * Serial DMA mode
 */
struct serial_rx_dma {
    rt_bool_t activated;
};

struct serial_tx_dma {
    rt_bool_t activated;
    struct rt_data_queue data_queue;
};

struct serial_device {
    struct rt_device parent;

    const struct usart_ops* ops;
    struct serial_configure config;

    void* serial_rx;
    void* serial_tx;
};
typedef struct serial_device* serial_dev_t;

/**
 * uart operators
 */
struct usart_ops {
    /**
     * @brief uart configure function
     * @param dev uart device
     * @param cfg uart configuration
     */
    rt_err_t (*configure)(struct serial_device* dev, struct serial_configure* cfg);
    /**
     * @brief uart control function (optional)
     * @param dev uart device
     * @param cmd operation command
     * @param arg command argument
    */
    rt_err_t (*control)(struct serial_device* dev, int cmd, void* arg);
    /**
     * @brief write a character to uart
     * @param dev uart device
     * @param c character to write
    */
    int (*putc)(struct serial_device* dev, char c);
    /**
     * @brief read a character from uart
     * @param dev uart device
    */
    int (*getc)(struct serial_device* dev);
    /**
     * @brief transfer function with uart using DMA (read/write)
     * @param dev uart device
     * @param buf data buffer
     * @param size data size
     * @param direction SERIAL_DMA_TX or SERIAL_DMA_RX
    */
    rt_size_t (*dma_transmit)(struct serial_device* dev, rt_uint8_t* buf, rt_size_t size, int direction);
};

void hal_serial_isr(struct serial_device* serial, int event);
rt_err_t hal_serial_register(struct serial_device* serial, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
