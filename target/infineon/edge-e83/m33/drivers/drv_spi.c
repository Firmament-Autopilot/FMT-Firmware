/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-18     Rbb666       first version
 * 2023-03-30     Rbb666       update spi driver
 */

#include <drv_spi.h>

#ifdef RT_USING_SPI


//#define DRV_DEBUG
#define DBG_TAG              "drv.spi"
#ifdef DRV_DEBUG
    #define DBG_LVL               DBG_LOG
#else
    #define DBG_LVL               DBG_INFO
#endif /* DRV_DEBUG */
#include <rtdbg.h>

#ifdef BSP_USING_SPI0
    static struct rt_spi_bus spi_bus0;
#endif
#ifdef BSP_USING_SPI1
    static struct rt_spi_bus spi_bus1;
    cy_stc_scb_spi_context_t   scb_9_spi_context;
#endif
#ifdef BSP_USING_SPI3
    static struct rt_spi_bus spi_bus3;
#endif
#ifdef BSP_USING_SPI6
    static struct rt_spi_bus spi_bus6;
#endif

static struct ifx_spi_handle spi_bus_obj[] =
{
#if defined(BSP_USING_SPI0)
    {
        .bus_name = "spi0",
        .sck_pin = GET_PIN(15, 0),
        .miso_pin = GET_PIN(15, 2),
        .mosi_pin = GET_PIN(15, 1),
    },
#endif
#if defined(BSP_USING_SPI1)
    {

        .bus_name = "spi1",
        .sck_pin = GET_PIN(15, 0),
        .miso_pin = GET_PIN(15, 2),
        .mosi_pin = GET_PIN(15, 1),

        .base = scb_9_HW,
        .cy_stc_scb_spi_config = &scb_9_config,
        .mtb_hal_spi_configurator = &scb_9_hal_config,
        .context = &scb_9_spi_context,
        .intr_cfg = {.intrSrc = scb_9_IRQ, .intrPriority = INT_PRIORITY },
    },
#endif
#if defined(BSP_USING_SPI2)
    {
        .bus_name = "spi2",
        .sck_pin = GET_PIN(8, 0),
        .miso_pin = GET_PIN(8, 4),
        .mosi_pin = GET_PIN(8, 1),
    },
#endif
#if defined(BSP_USING_SPI3)
    {
        .bus_name = "spi3",
        .sck_pin = GET_PIN(6, 2),
        .miso_pin = GET_PIN(6, 1),
        .mosi_pin = GET_PIN(6, 0),
    },
#endif
#if defined(BSP_USING_SPI6)
    {
        .bus_name = "spi6",
        .sck_pin = GET_PIN(12, 2),
        .miso_pin = GET_PIN(12, 1),
        .mosi_pin = GET_PIN(12, 0),
    },
#endif
};

static struct ifx_spi spi_config[sizeof(spi_bus_obj) / sizeof(spi_bus_obj[0])] = {0};

/* private rt-thread spi ops function */
static rt_err_t spi_configure(struct rt_spi_device *device, struct rt_spi_configuration *configuration);
static rt_ssize_t spixfer(struct rt_spi_device *device, struct rt_spi_message *message);

static struct rt_spi_ops ifx_spi_ops =
{
    .configure = spi_configure,
    .xfer = spixfer,
};


static void spi_interrupt_callback()
{
    rt_interrupt_enter();

    mtb_hal_spi_process_interrupt(spi_bus_obj[0].spi_obj);

    rt_interrupt_leave();
}


static void spi_event_handler(void* handler_arg, mtb_hal_spi_event_t event)
{
    rt_kprintf("spi event handler\n");
}


static void ifx_spi_init(struct ifx_spi *spi_device)
{
    RT_ASSERT(spi_device != RT_NULL);

    rt_err_t result = RT_EOK;

    static uint8_t init_flag = 1;

    if (init_flag)
    {

        result = Cy_SCB_SPI_Init(spi_device->spi_handle_t->base, spi_device->spi_handle_t->cy_stc_scb_spi_config, spi_device->spi_handle_t->context);
        Cy_SCB_SPI_Enable(spi_device->spi_handle_t->base);
        result = mtb_hal_spi_setup(spi_device->spi_handle_t->spi_obj, spi_device->spi_handle_t->mtb_hal_spi_configurator, spi_device->spi_handle_t->context, NULL);
        Cy_SCB_SPI_SetActiveSlaveSelect(spi_device->spi_handle_t->base, CY_SCB_SPI_SLAVE_SELECT0);

        if (result != RT_EOK)
        {
            LOG_E("spi%s init fail", spi_device->spi_handle_t->bus_name);
            return;
        }

        Cy_SysInt_Init(&(spi_device->spi_handle_t->intr_cfg), spi_interrupt_callback);
        NVIC_EnableIRQ(spi_device->spi_handle_t->intr_cfg.intrSrc);

        result = mtb_hal_spi_set_frequency(spi_device->spi_handle_t->spi_obj, spi_device->spi_handle_t->freq);
        if (result != CY_RSLT_SUCCESS)
        {
            LOG_E("%s set frequency fail", spi_device->spi_handle_t->bus_name);
            return;
        }
        LOG_I("[%s] freq:[%d]HZ", spi_device->spi_handle_t->bus_name, spi_device->spi_handle_t->freq);

        /* Register a callback function to be called when the interrupt fires */
        mtb_hal_spi_register_callback(spi_device->spi_handle_t->spi_obj, (mtb_hal_spi_event_callback_t)spi_event_handler, NULL);

        /* Enable the events that will trigger the call back function */
        mtb_hal_spi_enable_event(spi_device->spi_handle_t->spi_obj, MTB_HAL_SPI_IRQ_DONE, true);
    }

    init_flag = 0;
}

static rt_err_t spi_configure(struct rt_spi_device *device,
                              struct rt_spi_configuration *configuration)
{
    RT_ASSERT(device != RT_NULL);
    RT_ASSERT(configuration != RT_NULL);

    struct ifx_spi *spi_device = rt_container_of(device->bus, struct ifx_spi, spi_bus);

    /* data_width */
    if (configuration->data_width <= 8)
    {
        spi_device->spi_handle_t->spi_obj->data_bits = 8;
    }
    else if (configuration->data_width <= 16)
    {
        spi_device->spi_handle_t->spi_obj->data_bits = 16;
    }
    else
    {
        return -RT_EIO;
    }

    uint32_t max_hz;
    max_hz = configuration->max_hz;
    spi_device->spi_handle_t->freq = max_hz;

    /* MSB or LSB */
    switch (configuration->mode & RT_SPI_MODE_3)
    {
    case RT_SPI_MODE_0:
        spi_device->spi_handle_t->cy_stc_scb_spi_config->sclkMode = CY_SCB_SPI_CPHA0_CPOL0;
        break;
    case RT_SPI_MODE_1:
        spi_device->spi_handle_t->cy_stc_scb_spi_config->sclkMode = CY_SCB_SPI_CPHA0_CPOL1;
        break;
    case RT_SPI_MODE_2:
        spi_device->spi_handle_t->cy_stc_scb_spi_config->sclkMode = CY_SCB_SPI_CPHA1_CPOL0;
        break;
    case RT_SPI_MODE_3:
        spi_device->spi_handle_t->cy_stc_scb_spi_config->sclkMode = CY_SCB_SPI_CPHA1_CPOL1;
        break;
    }
    ifx_spi_init(spi_device);

    return RT_EOK;
}

static rt_ssize_t spixfer(struct rt_spi_device *device, struct rt_spi_message *message)
{
    struct ifx_spi *spi_device = rt_container_of(device->bus, struct ifx_spi, spi_bus);

    if (message->cs_take && !(device->config.mode & RT_SPI_NO_CS) && (device->cs_pin != PIN_NONE))
    {
        rt_pin_write(device->cs_pin, (device->config.mode & RT_SPI_CS_HIGH) ? PIN_HIGH : PIN_LOW);
    }

    int result = RT_EOK;
    if (message->length > 0)
    {
        result = mtb_hal_spi_transfer(spi_device->spi_handle_t->spi_obj, message->send_buf, message->length, message->recv_buf, message->length, 0);
        if (result != RT_EOK)
        {
            rt_kprintf("spi transfer failed.\n");
        }
    }

    if (message->cs_release && !(device->config.mode & RT_SPI_NO_CS) && (device->cs_pin != PIN_NONE))
    {
        rt_pin_write(device->cs_pin, (device->config.mode & RT_SPI_CS_HIGH) ? PIN_LOW : PIN_HIGH);
    }
    return (result == RT_EOK) ? message->length : -RT_ERROR;
}

/**
  * Attach the spi device to SPI bus, this function must be used after initialization.
  */
rt_err_t rt_hw_spi_device_attach(const char *bus_name, const char *device_name, rt_base_t cs_pin)
{
    RT_ASSERT(bus_name != RT_NULL);
    RT_ASSERT(device_name != RT_NULL);

    rt_err_t result;
    struct rt_spi_device *spi_device;

    /* attach the device to spi bus*/
    spi_device = (struct rt_spi_device *)rt_malloc(sizeof(struct rt_spi_device));
    RT_ASSERT(spi_device != RT_NULL);

    result = rt_spi_bus_attach_device_cspin(spi_device, device_name, bus_name, cs_pin, RT_NULL);
    if (result != RT_EOK)
    {
        LOG_E("%s attach to %s faild, %d\n", device_name, bus_name, result);
    }

    RT_ASSERT(result == RT_EOK);

    LOG_D("%s attach to %s done", device_name, bus_name);

    return result;
}

int rt_hw_spi_init(void)
{
    int result = RT_EOK;

    for (int spi_index = 0; spi_index < sizeof(spi_bus_obj) / sizeof(spi_bus_obj[0]); spi_index++)
    {
        spi_bus_obj[spi_index].spi_obj = rt_malloc(sizeof(mtb_hal_spi_t));
        RT_ASSERT(spi_bus_obj[spi_index].spi_obj != RT_NULL);

        spi_config[spi_index].spi_handle_t = &spi_bus_obj[spi_index];

        rt_err_t err = rt_spi_bus_register(&spi_config[spi_index].spi_bus, spi_bus_obj[spi_index].bus_name, &ifx_spi_ops);
        if (RT_EOK != err)
        {
            LOG_E("%s bus register failed.", spi_config[spi_index].spi_handle_t->bus_name);
            return -RT_ERROR;
        }

        LOG_D("MOSI PIN:[%d], MISO PIN[%d], CLK PIN[%d]\n",
              spi_bus_obj[spi_index].mosi_pin, spi_bus_obj[spi_index].miso_pin,
              spi_bus_obj[spi_index].sck_pin);

        /* initialize completion object */
        rt_completion_init(&spi_config[spi_index].cpt);
    }

    return result;
}
INIT_BOARD_EXPORT(rt_hw_spi_init);
#endif /* RT_USING_SPI */
