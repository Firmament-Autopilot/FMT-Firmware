#include <firmament.h>
#include <stdio.h>
#include "board.h"
#include "hal/can/can.h"
#include "canard_gd32f4xx.h"
#include "../../../src/module/console/console.h"

/* gd32 can device */
struct gd32_can {
    FDCanID canid;
};

static can_device can_dev[FDCAN_NUM_IFACES];
struct gd32_can _gd32_can[FDCAN_NUM_IFACES] = {
    [0].canid = 0,
#if FDCAN_NUM_IFACES >= 2    
    [1].canid = 1
#endif    
};

////////////////////////////////////////////////////////////////////////////////////
/*!
    \brief      configure GPIO
    \param[in]  none
    \param[out] none
    \retval     none
*/
static void gpio_config(void)
{
    /* enable can clock */
    rcu_periph_clock_enable(RCU_CAN0);
    rcu_periph_clock_enable(RCU_GPIOD);
    
    /* configure CAN0 GPIO */
    gpio_output_options_set(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    gpio_mode_set(GPIOD, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_af_set(GPIOD, GPIO_AF_9, GPIO_PIN_0);
    
    gpio_output_options_set(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
    gpio_mode_set(GPIOD, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_1);
    gpio_af_set(GPIOD, GPIO_AF_9, GPIO_PIN_1);
}

/*!
    \brief      initialize CAN and filter
    \param[in]  can_parameter
      \arg        can_parameter_struct
    \param[in]  can_filter
      \arg        can_filter_parameter_struct
    \param[out] none
    \retval     none
*/
static void can_networking_init(void)
{
    can_parameter_struct            can_parameter;
    can_filter_parameter_struct     can_filter;
    
    /* initialize CAN register */
    can_deinit(CAN0);
    
    /* initialize CAN */
    can_parameter.time_triggered = DISABLE;
    can_parameter.auto_bus_off_recovery = ENABLE;
    can_parameter.auto_wake_up = DISABLE;
    can_parameter.auto_retrans = ENABLE;
    can_parameter.rec_fifo_overwrite = DISABLE;
    can_parameter.trans_fifo_order = DISABLE;
    can_parameter.working_mode = CAN_NORMAL_MODE;
    can_parameter.resync_jump_width = CAN_BT_SJW_1TQ;
    can_parameter.time_segment_1 = CAN_BT_BS1_5TQ;
    can_parameter.time_segment_2 = CAN_BT_BS2_4TQ;
    /* baudrate 1Mbps */
    can_parameter.prescaler = 6;
    can_init(CAN0, &can_parameter);
    can_interrupt_disable(CAN0, 0);  // We need no interrupts
    printf("can init \n");
    /* initialize filter */
    /* CAN1 filter number */
    can_filter.filter_number = 0;

    /* initialize filter */
    can_filter.filter_mode = CAN_FILTERMODE_MASK;
    can_filter.filter_bits = CAN_FILTERBITS_32BIT;
    can_filter.filter_list_high = 0x0000;
    can_filter.filter_list_low = 0x0000;
    can_filter.filter_mask_high = 0x0000;
    can_filter.filter_mask_low = 0x0000;
    can_filter.filter_fifo_number = CAN_FIFO0;
    can_filter.filter_enable = ENABLE;
    can_filter_init(&can_filter);

    /* enable CAN receive FIFO0 not empty interrupt */
    can_interrupt_enable(CAN0, CAN_INTEN_RFFIE0);
    nvic_irq_enable(CAN0_RX0_IRQn,0,1);
    printf("can filter init \n");
}

static int can_sendmsg(can_dev_t can_dev, const void* buf)
{
    struct gd32_can* gd32_can_x = (struct gd32_can*)can_dev->parent.user_data;
    RT_ASSERT(gd32_can_x != RT_NULL);

    CanardCANFrame* out_frame = (CanardCANFrame*)buf;

    canardGD32Transmit(gd32_can_x->canid, out_frame);

    return out_frame->data_len;
}

static int can_recvmsg(can_dev_t can_dev, void* buf)
{
    struct gd32_can* gd32_can_x = (struct gd32_can*)can_dev->parent.user_data;
    RT_ASSERT(gd32_can_x != RT_NULL);

    CanardCANFrame* out_frame = (CanardCANFrame*)buf;

    canardGD32Receive(gd32_can_x->canid, out_frame);

    return out_frame->data_len;
}

static rt_err_t can_configure(can_dev_t can_dev, struct can_configure* cfg)
{
    struct gd32_can* gd32_can_x = (struct gd32_can*)can_dev->parent.user_data;

    RT_ASSERT(gd32_can_x != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    // can_baud_rate_configure(gd32_can_x->can_handler, cfg->baud_rate);

    // #endif
    return RT_EOK;
}

static const struct can_ops _can_ops = {
    .configure = can_configure,
    .sendmsg = can_sendmsg,
    .recvmsg = can_recvmsg,
};

static rt_err_t gd32_msp_can_init(void)
{
#if FDCAN_NUM_IFACES >= 1
    gpio_config();

    can_deinit(CAN0); // 先清除以前的设置
    can_networking_init();

    FdCANTimings can_timing;
    fdCANComputeTimings(BSP_CLOCK_SYSTEM_FREQ_HZ, 1000000, &can_timing);
    canardGD32Init(can_timing, can1);

#elif FDCAN_NUM_IFACES >= 2
    FdCANTimings can2_timing;
    fdCANComputeTimings(FDCAN_CLOCK, FDCAN_TARGET_CLOCK, &can2_timing);
    canardGD32Init(can2_timing, can2);
#endif
    return RT_EOK;
}

rt_err_t drv_can_init(void)
{
    char canname[5] = "can";

    RT_CHECK(gd32_msp_can_init());

    rt_thread_delay(200);
    struct can_configure config = CAN_DEFAULT_CONFIG;

    for(uint8_t i=0; i<FDCAN_NUM_IFACES; i++)
    {
        can_dev[i].ops = &_can_ops;
        can_dev[i].config = config;

        snprintf(canname, 5, "can%u", i);
        hw_can_register(&can_dev[i], canname, 0, &_gd32_can[i]);
    }

    return RT_EOK;
}

extern void receiveCanard(void);
/*!
    \brief      this function handles CAN0 RX0 exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
// can_receive_message_struct receive_message;
void CAN0_RX0_IRQHandler(void)
{
    /* check the receive message */
    receiveCanard();
}