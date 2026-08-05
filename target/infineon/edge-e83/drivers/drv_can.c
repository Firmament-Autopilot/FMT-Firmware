/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#include <firmament.h>
#include <string.h>

#include "drv_can.h"
#include "cy_canfd.h"
#include "cy_sysint.h"
#include "cycfg_peripherals.h"
#include "hal/can/can.h"

// #define CAN_DRV_DBG(...) rt_kprintf(__VA_ARGS__)
#define CAN_DRV_DBG(...)

#define IFX_CANFD_TX_BUFFER_INDEX 0U
#define IFX_CANFD_MRAM_DELAY      6U
#define IFX_CANFD_RX_CACHE_SIZE   16U

#define IFX_CANFD_CH_MASK(ch) (1UL << (ch))

struct ifx_canfd {
    can_device can_dev;
    const char* name;
    CANFD_Type* base;
    uint32_t channel;

    cy_stc_sysint_t irq_cfg;
    cy_stc_canfd_context_t context;

    cy_stc_canfd_config_t config;
    cy_stc_canfd_bitrate_t nominal_bitrate;
    cy_stc_canfd_bitrate_t data_bitrate;

    cy_stc_id_filter_t sid_filter;

    cy_stc_canfd_t0_t tx_t0;
    cy_stc_canfd_t1_t tx_t1;
    uint32_t tx_data_words[2];
    cy_stc_canfd_tx_buffer_t tx_buffer;

    can_msg rx_cache[IFX_CANFD_RX_CACHE_SIZE];
    volatile uint8_t rx_head;
    volatile uint8_t rx_tail;

    volatile bool initialized;
};

static rt_err_t ifx_canfd_configure(can_dev_t can, struct can_configure* cfg);
static rt_err_t ifx_canfd_control(can_dev_t can, int cmd, void* arg);
static int ifx_canfd_sendmsg(can_dev_t can, const can_msg_t msg);
static int ifx_canfd_recvmsg(can_dev_t can, can_msg_t msg);

static const struct can_ops ifx_canfd_ops = {
    .configure = ifx_canfd_configure,
    .control = ifx_canfd_control,
    .sendmsg = ifx_canfd_sendmsg,
    .recvmsg = ifx_canfd_recvmsg,
};

static struct ifx_canfd ifx_canfd0 = {
    .can_dev = {
        .ops = &ifx_canfd_ops,
        .config = CAN_DEFAULT_CONFIG,
    },
    .name = "can0",
    .base = CYBSP_CAN_FD_CH_0_HW,
    .channel = CYBSP_CAN_FD_CH_0_CHANNEL_NUM,
    .irq_cfg = { .intrSrc = CYBSP_CAN_FD_CH_0_IRQ_0, .intrPriority = 3U },
};

static uint8_t ifx_canfd_dlc_to_len(uint32_t dlc)
{
    static const uint8_t dlc_len_map[] = { 12U, 16U, 20U, 24U, 32U, 48U, 64U };

    if (dlc <= 8U) {
        return (uint8_t)dlc;
    }

    if (dlc <= 15U) {
        return dlc_len_map[dlc - 9U];
    }

    return 8U;
}

static inline struct ifx_canfd* ifx_canfd_from_dev(can_dev_t can)
{
    return (struct ifx_canfd*)can->parent.user_data;
}

static void ifx_canfd_rx_cache_push(struct ifx_canfd* can, const can_msg* msg)
{
    rt_base_t level;
    uint8_t next;

    RT_ASSERT(can != RT_NULL);
    RT_ASSERT(msg != RT_NULL);

    level = rt_hw_interrupt_disable();

    next = (uint8_t)((can->rx_head + 1U) % IFX_CANFD_RX_CACHE_SIZE);
    if (next != can->rx_tail) {
        can->rx_cache[can->rx_head] = *msg;
        can->rx_head = next;
    }

    rt_hw_interrupt_enable(level);
}

static int ifx_canfd_rx_cache_pop(struct ifx_canfd* can, can_msg_t msg)
{
    rt_base_t level;

    RT_ASSERT(can != RT_NULL);
    RT_ASSERT(msg != RT_NULL);

    level = rt_hw_interrupt_disable();

    if (can->rx_head == can->rx_tail) {
        rt_hw_interrupt_enable(level);
        return 0;
    }

    *msg = can->rx_cache[can->rx_tail];
    can->rx_tail = (uint8_t)((can->rx_tail + 1U) % IFX_CANFD_RX_CACHE_SIZE);

    rt_hw_interrupt_enable(level);

    return 1;
}

static void ifx_canfd_fill_msg_from_rx(const cy_stc_canfd_rx_buffer_t* rx, can_msg_t msg)
{
    const uint8_t* payload;

    RT_ASSERT(rx != RT_NULL);
    RT_ASSERT(msg != RT_NULL);

    msg->id_type = (rx->r0_f->xtd == CY_CANFD_XTD_EXTENDED_ID) ? CAN_ID_EXTENDED : CAN_ID_STANDARD;
    msg->frame_type = (rx->r0_f->rtr == CY_CANFD_RTR_REMOTE_FRAME) ? CAN_FRAME_REMOTE : CAN_FRAME_DATA;

    if (msg->id_type == CAN_ID_EXTENDED) {
        msg->ext_id = rx->r0_f->id & 0x1FFFFFFFUL;
        msg->std_id = 0U;
    } else {
        msg->std_id = rx->r0_f->id & 0x7FFUL;
        msg->ext_id = 0U;
    }

    msg->data_len = ifx_canfd_dlc_to_len(rx->r1_f->dlc);
    if (msg->data_len > 8U) {
        msg->data_len = 8U;
    }

    payload = (const uint8_t*)rx->data_area_f;
    if (msg->data_len > 0U) {
        rt_memcpy(msg->data, payload, msg->data_len);
    }
    if (msg->data_len < sizeof(msg->data)) {
        rt_memset(&msg->data[msg->data_len], 0, sizeof(msg->data) - msg->data_len);
    }
}

static void ifx_canfd_tx_callback(void)
{
    hal_can_notify(&ifx_canfd0.can_dev, CAN_EVENT_TX_DONE, RT_NULL);
}

static void ifx_canfd_error_callback(uint32_t error_mask)
{
    (void)error_mask;
    CAN_DRV_DBG("CANFD error: 0x%08lx\n", (unsigned long)error_mask);

    /* Notify once on error to avoid write-side blocking forever. */
    hal_can_notify(&ifx_canfd0.can_dev, CAN_EVENT_TX_DONE, RT_NULL);
}

void canfd0_rx_callback(bool rxFIFOMsg, uint8_t msgBufOrRxFIFONum, cy_stc_canfd_rx_buffer_t* basemsg)
{
    can_msg msg;

    (void)rxFIFOMsg;
    (void)msgBufOrRxFIFONum;

    if (basemsg == RT_NULL) {
        return;
    }

    ifx_canfd_fill_msg_from_rx(basemsg, &msg);
    ifx_canfd_rx_cache_push(&ifx_canfd0, &msg);

    hal_can_notify(&ifx_canfd0.can_dev, CAN_EVENT_RX_IND, &msg);
}

static void canfd0_isr_callback(void)
{
    rt_interrupt_enter();
    Cy_CANFD_IrqHandler(ifx_canfd0.base, ifx_canfd0.channel, &ifx_canfd0.context);
    rt_interrupt_leave();
}

static rt_err_t ifx_canfd_apply_baudrate(struct ifx_canfd* can, uint32_t baud_rate)
{
    uint32_t scale = 1U;

    switch (baud_rate) {
    case CAN_BAUD_RATE_1000K:
        scale = 1U;
        break;
    case CAN_BAUD_RATE_500K:
        scale = 2U;
        break;
    case CAN_BAUD_RATE_250K:
        scale = 4U;
        break;
    case CAN_BAUD_RATE_125K:
        scale = 8U;
        break;
    default:
        return -RT_EINVAL;
    }

    can->nominal_bitrate.prescaler = (uint16_t)(((CYBSP_CAN_FD_CH_0_nominalBitrateConfig.prescaler + 1U) * scale) - 1U);
    can->nominal_bitrate.timeSegment1 = CYBSP_CAN_FD_CH_0_nominalBitrateConfig.timeSegment1;
    can->nominal_bitrate.timeSegment2 = CYBSP_CAN_FD_CH_0_nominalBitrateConfig.timeSegment2;
    can->nominal_bitrate.syncJumpWidth = CYBSP_CAN_FD_CH_0_nominalBitrateConfig.syncJumpWidth;

    can->data_bitrate.prescaler = (uint16_t)(((CYBSP_CAN_FD_CH_0_dataBitrateConfig.prescaler + 1U) * scale) - 1U);
    can->data_bitrate.timeSegment1 = CYBSP_CAN_FD_CH_0_dataBitrateConfig.timeSegment1;
    can->data_bitrate.timeSegment2 = CYBSP_CAN_FD_CH_0_dataBitrateConfig.timeSegment2;
    can->data_bitrate.syncJumpWidth = CYBSP_CAN_FD_CH_0_dataBitrateConfig.syncJumpWidth;

    return RT_EOK;
}

static rt_err_t ifx_canfd_configure(can_dev_t can, struct can_configure* cfg)
{
    struct ifx_canfd* obj;
    cy_en_canfd_status_t status;
    uint32_t intr_mask;

    RT_ASSERT(can != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    obj = ifx_canfd_from_dev(can);
    RT_ASSERT(obj != RT_NULL);

    if (ifx_canfd_apply_baudrate(obj, cfg->baud_rate) != RT_EOK) {
        return -RT_EINVAL;
    }

    obj->config = CYBSP_CAN_FD_CH_0_config;
    obj->config.txCallback = ifx_canfd_tx_callback;
    obj->config.rxCallback = canfd0_rx_callback;
    obj->config.errorCallback = ifx_canfd_error_callback;
    obj->config.bitrate = &obj->nominal_bitrate;
    obj->config.fastBitrate = &obj->data_bitrate;

    obj->rx_head = 0U;
    obj->rx_tail = 0U;

    Cy_CANFD_EnableMRAM(obj->base, IFX_CANFD_CH_MASK(obj->channel), IFX_CANFD_MRAM_DELAY);

    status = Cy_CANFD_Init(obj->base, obj->channel, &obj->config, &obj->context);
    if (status != CY_CANFD_SUCCESS) {
        CAN_DRV_DBG("Cy_CANFD_Init failed: %ld\n", (long)status);
        return -RT_ERROR;
    }

    Cy_SysInt_Init(&obj->irq_cfg, canfd0_isr_callback);
    NVIC_ClearPendingIRQ(obj->irq_cfg.intrSrc);
    NVIC_EnableIRQ(obj->irq_cfg.intrSrc);

    intr_mask = CY_CANFD_RX_FIFO_0_NEW_MESSAGE
                | CY_CANFD_TRANSMISSION_COMPLETE
                | CY_CANFD_BUS_OFF_STATUS
                | CY_CANFD_PROTOCOL_ERROR_ARB_PHASE
                | CY_CANFD_PROTOCOL_ERROR_DATA_PHASE;

    Cy_CANFD_SetInterruptMask(obj->base, obj->channel, intr_mask);
    Cy_CANFD_SetInterruptLine(obj->base, obj->channel, 0U);
    Cy_CANFD_EnableInterruptLine(obj->base, obj->channel, CY_CANFD_INTERRUPT_LINE_0_EN);

    if (Cy_CANFD_ConfigChangesEnable(obj->base, obj->channel) == CY_CANFD_SUCCESS) {
        Cy_CANFD_TestModeConfig(obj->base, obj->channel, CY_CANFD_TEST_MODE_DISABLE);
        (void)Cy_CANFD_ConfigChangesDisable(obj->base, obj->channel);
    }

    obj->tx_t0.id = 0x123U;
    obj->tx_t0.rtr = CY_CANFD_RTR_DATA_FRAME;
    obj->tx_t0.xtd = CY_CANFD_XTD_STANDARD_ID;
    obj->tx_t0.esi = CY_CANFD_ESI_ERROR_ACTIVE;

    obj->tx_t1.dlc = 0U;
    obj->tx_t1.brs = false;
    obj->tx_t1.fdf = CY_CANFD_FDF_STANDARD_FRAME;
    obj->tx_t1.efc = false;
    obj->tx_t1.mm = 0U;

    obj->tx_data_words[0] = 0U;
    obj->tx_data_words[1] = 0U;

    obj->tx_buffer.t0_f = &obj->tx_t0;
    obj->tx_buffer.t1_f = &obj->tx_t1;
    obj->tx_buffer.data_area_f = obj->tx_data_words;

    obj->initialized = true;

    return RT_EOK;
}

static rt_err_t ifx_canfd_control(can_dev_t can, int cmd, void* arg)
{
    struct ifx_canfd* obj;

    RT_ASSERT(can != RT_NULL);

    obj = ifx_canfd_from_dev(can);
    RT_ASSERT(obj != RT_NULL);

    switch (cmd) {
    case CAN_OPEN_DEVICE:
        if (!obj->initialized) {
            return -RT_ERROR;
        }
        NVIC_ClearPendingIRQ(obj->irq_cfg.intrSrc);
        NVIC_EnableIRQ(obj->irq_cfg.intrSrc);
        break;

    case CAN_CLOSE_DEVICE:
        NVIC_DisableIRQ(obj->irq_cfg.intrSrc);
        break;

    case CAN_SET_RX_FILTER: {
        struct can_filter* filter = (struct can_filter*)arg;
        uint32_t id1;
        uint32_t id2;

        if (filter == RT_NULL) {
            return -RT_EINVAL;
        }

        id1 = filter->filter_id1 & 0x7FFUL;
        id2 = filter->filter_id2 & 0x7FFUL;

        obj->sid_filter.sfec = CY_CANFD_SFEC_STORE_RX_FIFO_0;
        if (filter->filter_type == CAN_FILTER_TYPE_MASK) {
            obj->sid_filter.sft = CY_CANFD_SFT_CLASSIC_FILTER;
            obj->sid_filter.sfid1 = id1;
            obj->sid_filter.sfid2 = id2;
        } else {
            obj->sid_filter.sft = CY_CANFD_SFT_RANGE_SFID1_SFID2;
            obj->sid_filter.sfid1 = id1 < id2 ? id1 : id2;
            obj->sid_filter.sfid2 = id1 < id2 ? id2 : id1;
        }

        if (Cy_CANFD_ConfigChangesEnable(obj->base, obj->channel) != CY_CANFD_SUCCESS) {
            return -RT_ERROR;
        }

        Cy_CANFD_SidFilterSetup(obj->base, obj->channel, &obj->sid_filter, 0U, &obj->context);

        if (Cy_CANFD_ConfigChangesDisable(obj->base, obj->channel) != CY_CANFD_SUCCESS) {
            return -RT_ERROR;
        }

        break;
    }

    default:
        break;
    }

    return RT_EOK;
}

static int ifx_canfd_sendmsg(can_dev_t can, const can_msg_t msg)
{
    struct ifx_canfd* obj;
    cy_en_canfd_status_t status;
    uint32_t id;
    uint32_t i;

    RT_ASSERT(can != RT_NULL);
    RT_ASSERT(msg != RT_NULL);

    obj = ifx_canfd_from_dev(can);
    RT_ASSERT(obj != RT_NULL);

    if (!obj->initialized) {
        return 0;
    }

    obj->tx_t0.xtd = (msg->id_type == CAN_ID_EXTENDED) ? CY_CANFD_XTD_EXTENDED_ID : CY_CANFD_XTD_STANDARD_ID;
    obj->tx_t0.rtr = (msg->frame_type == CAN_FRAME_REMOTE) ? CY_CANFD_RTR_REMOTE_FRAME : CY_CANFD_RTR_DATA_FRAME;

    if (msg->id_type == CAN_ID_EXTENDED) {
        id = msg->ext_id & 0x1FFFFFFFUL;
    } else {
        id = msg->std_id & 0x7FFUL;
    }
    obj->tx_t0.id = id;

    obj->tx_t1.dlc = msg->data_len > 8U ? 8U : msg->data_len;
    obj->tx_t1.brs = false;
    obj->tx_t1.fdf = CY_CANFD_FDF_STANDARD_FRAME;

    obj->tx_data_words[0] = 0U;
    obj->tx_data_words[1] = 0U;

    for (i = 0U; i < obj->tx_t1.dlc; i++) {
        obj->tx_data_words[i >> 2U] |= ((uint32_t)msg->data[i]) << ((i & 0x3U) * 8U);
    }

    status = Cy_CANFD_UpdateAndTransmitMsgBuffer(obj->base,
                                                  obj->channel,
                                                  &obj->tx_buffer,
                                                  IFX_CANFD_TX_BUFFER_INDEX,
                                                  &obj->context);

    if (status != CY_CANFD_SUCCESS) {
        CAN_DRV_DBG("Cy_CANFD_UpdateAndTransmitMsgBuffer failed: %ld\n", (long)status);
        return 0;
    }

    return 1;
}

static int ifx_canfd_recvmsg(can_dev_t can, can_msg_t msg)
{
    struct ifx_canfd* obj;

    RT_ASSERT(can != RT_NULL);
    RT_ASSERT(msg != RT_NULL);

    obj = ifx_canfd_from_dev(can);
    RT_ASSERT(obj != RT_NULL);

    return ifx_canfd_rx_cache_pop(obj, msg);
}

rt_err_t drv_can_init(void)
{
    return hal_can_register(&ifx_canfd0.can_dev,
                            ifx_canfd0.name,
                            RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX,
                            &ifx_canfd0);
}
