/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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

#ifndef BB_COM_H__
#define BB_COM_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BB_COM_BUFSZ 1024

/* bb_com isr event */
#define BB_COM_EVENT_RX_IND     0x01 /* Rx indication */
#define BB_COM_EVENT_TX_DONE    0x02 /* Tx complete   */
#define BB_COM_EVENT_RX_DMADONE 0x03 /* Rx DMA transfer done */
#define BB_COM_EVENT_TX_DMADONE 0x04 /* Tx DMA transfer done */
#define BB_COM_EVENT_RX_TIMEOUT 0x05 /* Rx timeout    */

#define BB_COM_RX_INT 0x01
#define BB_COM_TX_INT 0x02

#define BB_COM_ERR_OVERRUN 0x01
#define BB_COM_ERR_FRAMING 0x02
#define BB_COM_ERR_PARITY  0x03

/*
 * Bb_com FIFO mode
 */
struct bb_com_rx_fifo {
    /* software fifo */
    rt_uint8_t* buffer;

    rt_uint16_t put_index, get_index;

    rt_bool_t is_full;
};

struct bb_com_tx_fifo {
    struct rt_completion completion;
};

struct bb_com_device {
    struct rt_device parent;

    const struct bb_com_ops* ops;
    void* bb_com_rx;
    void* bb_com_tx;
};
typedef struct bb_com_device* bb_com_dev_t;

/**
 * uart operators
 */
struct bb_com_ops {
    int (*putc)(struct bb_com_device* bb_com, char c);
    int (*getc)(struct bb_com_device* bb_com);
};

void hal_bb_com_isr(struct bb_com_device* bb_com, int event);
rt_err_t hal_bb_com_register(struct bb_com_device* bb_com, const char* name, rt_uint32_t flag, void* data);

rt_err_t register_bb_com(void);

#ifdef __cplusplus
}
#endif

#endif
