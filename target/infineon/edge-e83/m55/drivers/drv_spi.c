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

#include "drv_spi.h"
#include "cy_scb_spi.h"
#include "cy_sysint.h"
#include "hal/pin/pin.h"
#include "hal/spi/spi.h"

#define GET_PIN(PORTx, PIN) ((((uint8_t)(PORTx)) << 3U) + ((uint8_t)(PIN)))
#define INT_PRIORITY        7u

struct ifx_spi {
    struct rt_spi_bus spi_bus;
    const char* name;

    CySCB_Type* base;
    cy_stc_scb_spi_config_t runtime_cfg;
    const cy_stc_scb_spi_config_t* default_cfg;
    const mtb_hal_spi_configurator_t* hal_cfg;
    cy_stc_scb_spi_context_t* context;
    mtb_hal_spi_t* spi_obj;

    uint16_t cs_pin;

    cy_stc_sysint_t intr_cfg;

    uint32_t freq;
    struct rt_completion cpt;
};

#ifdef BSP_USING_SPI1
static cy_stc_scb_spi_context_t scb_10_spi_context;

extern const cy_stc_scb_spi_config_t scb_10_config;
extern const mtb_hal_spi_configurator_t scb_10_hal_config;

    #define scb_10_HW  SCB10
    #define scb_10_IRQ scb_10_interrupt_IRQn
#endif

static struct ifx_spi ifx_spi_obj[] = {
#ifdef BSP_USING_SPI1
    {
        .name = "spi1",
        .base = scb_10_HW,
        .default_cfg = &scb_10_config,
        .hal_cfg = &scb_10_hal_config,
        .context = &scb_10_spi_context,
        .cs_pin = GET_PIN(16, 3),
        .intr_cfg = { .intrSrc = scb_10_IRQ, .intrPriority = INT_PRIORITY },
    },
#endif
};

static rt_device_t pin_dev;

static void ifx_spi_irq_handler_generic(struct ifx_spi* spi)
{
    rt_interrupt_enter();

    mtb_hal_spi_process_interrupt(spi->spi_obj);

    if (!mtb_hal_spi_is_busy(spi->spi_obj)) {
        rt_completion_done(&spi->cpt);
    }

    rt_interrupt_leave();
}

#ifdef BSP_USING_SPI1
static void ifx_spi1_irq_handler(void)
{
    ifx_spi_irq_handler_generic(&ifx_spi_obj[0]);
}
#endif

static rt_err_t ifx_hw_spi_init(struct ifx_spi* spi)
{
    RT_ASSERT(spi);

    pin_dev = rt_device_find("pin");
    RT_ASSERT(pin_dev != RT_NULL);
    RT_CHECK(rt_device_open(pin_dev, RT_DEVICE_OFLAG_RDWR));

    struct device_pin_mode pin_mode = { spi->cs_pin, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };
    pin_dev->control(pin_dev, 0, &pin_mode);

    spi->runtime_cfg = *spi->default_cfg;
    spi->spi_obj = rt_malloc(sizeof(mtb_hal_spi_t));
    if (!spi->spi_obj)
        return -RT_ENOMEM;

    if (Cy_SCB_SPI_Init(spi->base, &spi->runtime_cfg, spi->context) != CY_SCB_SPI_SUCCESS)
        return -RT_ERROR;
    Cy_SCB_SPI_Enable(spi->base);

    if (mtb_hal_spi_setup(spi->spi_obj, spi->hal_cfg, spi->context, NULL) != CY_RSLT_SUCCESS)
        return -RT_ERROR;

    cy_israddress isr_func = RT_NULL;
    if (rt_strcmp(spi->name, "spi1") == 0)
        isr_func = ifx_spi1_irq_handler;

    if (isr_func) {
        Cy_SysInt_Init(&spi->intr_cfg, isr_func);
        NVIC_EnableIRQ(spi->intr_cfg.intrSrc);
    }

    rt_completion_init(&spi->cpt);
    spi->freq = 1000000;
    mtb_hal_spi_set_frequency(spi->spi_obj, spi->freq);

    return RT_EOK;
}

static rt_err_t spi_configure(struct rt_spi_device* device, struct rt_spi_configuration* cfg)
{
    struct ifx_spi* spi = rt_container_of(device->bus, struct ifx_spi, spi_bus);

    spi->spi_obj->data_bits = (cfg->data_width <= 8) ? 8 : 16;
    spi->freq = cfg->max_hz;
    mtb_hal_spi_set_frequency(spi->spi_obj, spi->freq);

    switch (cfg->mode & RT_SPI_MODE_3) {
    case RT_SPI_MODE_0:
        spi->runtime_cfg.sclkMode = CY_SCB_SPI_CPHA0_CPOL0;
        break;
    case RT_SPI_MODE_1:
        spi->runtime_cfg.sclkMode = CY_SCB_SPI_CPHA0_CPOL1;
        break;
    case RT_SPI_MODE_2:
        spi->runtime_cfg.sclkMode = CY_SCB_SPI_CPHA1_CPOL0;
        break;
    case RT_SPI_MODE_3:
        spi->runtime_cfg.sclkMode = CY_SCB_SPI_CPHA1_CPOL1;
        break;
    }

    Cy_SCB_SPI_Disable(spi->base, spi->context);
    Cy_SCB_SPI_Init(spi->base, &spi->runtime_cfg, spi->context);
    Cy_SCB_SPI_Enable(spi->base);

    return RT_EOK;
}

static rt_uint32_t spixfer(struct rt_spi_device* device, struct rt_spi_message* message)
{
    struct ifx_spi* spi = rt_container_of(device->bus, struct ifx_spi, spi_bus);
    rt_err_t result = RT_EOK;

    if (message->cs_take && !(device->config.mode & RT_SPI_NO_CS)) {
        struct device_pin_status pin_sta = { spi->cs_pin, (device->config.mode & RT_SPI_CS_HIGH) ? PIN_HIGH : PIN_LOW };
        pin_dev->write(pin_dev, 0, &pin_sta, sizeof(pin_sta));
    }

    if (message->length > 0) {
        const void* tx_buf = message->send_buf;
        void* rx_buf = message->recv_buf;
        size_t len = message->length;
        uint8_t dummy_fill = 0x00; 
        if (mtb_hal_spi_transfer(spi->spi_obj,
                                 tx_buf ? tx_buf : &dummy_fill,
                                 len,
                                 rx_buf,
                                 rx_buf ? len : 0,
                                 dummy_fill)
            == CY_RSLT_SUCCESS) {
            rt_completion_wait(&spi->cpt, RT_WAITING_FOREVER);
        } else {
            result = -RT_ERROR;
        }
    }

    if (message->cs_release && !(device->config.mode & RT_SPI_NO_CS)) {
        struct device_pin_status pin_sta = { spi->cs_pin, (device->config.mode & RT_SPI_CS_HIGH) ? PIN_LOW : PIN_HIGH };
        pin_dev->write(pin_dev, 0, &pin_sta, sizeof(pin_sta));
    }

    return (result == RT_EOK) ? message->length : result;
}

static const struct rt_spi_ops ifx_spi_ops = {
    .configure = spi_configure,
    .xfer = spixfer,
};

rt_err_t drv_spi_init(void)
{
    for (int i = 0; i < sizeof(ifx_spi_obj) / sizeof(ifx_spi_obj[0]); i++) {
        struct ifx_spi* obj = &ifx_spi_obj[i];

        if (ifx_hw_spi_init(obj) == RT_EOK) {
            rt_spi_bus_register(&obj->spi_bus, obj->name, &ifx_spi_ops);
        }
    }
    return RT_EOK;
}
