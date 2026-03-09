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
    mtb_hal_spi_t spi_obj;

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

static rt_err_t ifx_spi_set_cs(struct ifx_spi* spi, rt_base_t level)
{
    RT_ASSERT(spi);
    RT_ASSERT(pin_dev != RT_NULL);

    struct device_pin_status pin_sta = { spi->cs_pin, (uint16_t)level };
    pin_dev->write(pin_dev, 0, &pin_sta, sizeof(pin_sta));

    return RT_EOK;
}

static void ifx_spi_irq_handler_generic(struct ifx_spi* spi)
{
    rt_interrupt_enter();

    mtb_hal_spi_process_interrupt(&spi->spi_obj);

    if (!mtb_hal_spi_is_busy(&spi->spi_obj)) {
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

    if (pin_dev == RT_NULL) {
        pin_dev = rt_device_find("pin");
        if (pin_dev == RT_NULL)
            return -RT_ERROR;

        if (rt_device_open(pin_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK)
            return -RT_ERROR;
    }

    struct device_pin_mode pin_mode = { spi->cs_pin, PIN_MODE_OUTPUT, PIN_OUT_TYPE_PP };
    if (pin_dev->control(pin_dev, 0, &pin_mode) != RT_EOK)
        return -RT_ERROR;
    ifx_spi_set_cs(spi, PIN_HIGH);

    spi->runtime_cfg = *spi->default_cfg;
    if (Cy_SCB_SPI_Init(spi->base, &spi->runtime_cfg, spi->context) != CY_SCB_SPI_SUCCESS)
        return -RT_ERROR;
    Cy_SCB_SPI_Enable(spi->base);

    if (mtb_hal_spi_setup(&spi->spi_obj, spi->hal_cfg, spi->context, NULL) != CY_RSLT_SUCCESS)
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
    if (mtb_hal_spi_set_frequency(&spi->spi_obj, spi->freq) != CY_RSLT_SUCCESS)
        return -RT_ERROR;

    return RT_EOK;
}

static rt_err_t spi_configure(struct rt_spi_device* device, struct rt_spi_configuration* cfg)
{
    RT_ASSERT(device);
    RT_ASSERT(cfg);

    struct ifx_spi* spi = rt_container_of(device->bus, struct ifx_spi, spi_bus);

    if (cfg->data_width == 0 || cfg->data_width > 16)
        return -RT_EINVAL;

    spi->spi_obj.data_bits = (cfg->data_width <= 8) ? 8 : 16;
    spi->freq = cfg->max_hz;
    if (mtb_hal_spi_set_frequency(&spi->spi_obj, spi->freq) != CY_RSLT_SUCCESS)
        return -RT_ERROR;

    spi->runtime_cfg.enableMsbFirst = ((cfg->mode & RT_SPI_MSB) == RT_SPI_MSB) ? true : false;

    switch (cfg->mode & RT_SPI_MODE_3) {
    case RT_SPI_MODE_0:
        spi->runtime_cfg.sclkMode = CY_SCB_SPI_CPHA0_CPOL0;
        break;
    case RT_SPI_MODE_1:
        spi->runtime_cfg.sclkMode = CY_SCB_SPI_CPHA1_CPOL0;
        break;
    case RT_SPI_MODE_2:
        spi->runtime_cfg.sclkMode = CY_SCB_SPI_CPHA0_CPOL1;
        break;
    case RT_SPI_MODE_3:
        spi->runtime_cfg.sclkMode = CY_SCB_SPI_CPHA1_CPOL1;
        break;
    }

    Cy_SCB_SPI_Disable(spi->base, spi->context);
    if (Cy_SCB_SPI_Init(spi->base, &spi->runtime_cfg, spi->context) != CY_SCB_SPI_SUCCESS) {
        rt_kprintf("Cy_SCB_SPI_Init fail!!\n");
        return -RT_ERROR;
    }

    Cy_SCB_SPI_Enable(spi->base);

    return RT_EOK;
}

static rt_uint32_t spixfer(struct rt_spi_device* device, struct rt_spi_message* message)
{
    RT_ASSERT(device);
    RT_ASSERT(message);

    struct ifx_spi* spi = rt_container_of(device->bus, struct ifx_spi, spi_bus);
    cy_rslt_t result = CY_RSLT_SUCCESS;
    rt_err_t wait_ret = RT_EOK;

    if (message->cs_take && !(device->config.mode & RT_SPI_NO_CS)) {
        ifx_spi_set_cs(spi, (device->config.mode & RT_SPI_CS_HIGH) ? PIN_HIGH : PIN_LOW);
    }

    if (message->length > 0) {
        if (message->send_buf == RT_NULL && message->recv_buf == RT_NULL) {
            result = (cy_rslt_t)-RT_EINVAL;
            goto __exit;
        }

        mtb_hal_spi_clear(&spi->spi_obj);
        rt_completion_init(&spi->cpt);

        if (message->send_buf == RT_NULL && message->recv_buf != RT_NULL) {
            result = mtb_hal_spi_transfer(&spi->spi_obj, RT_NULL, 0x00, message->recv_buf, message->length, 0x00);
        } else if (message->send_buf != RT_NULL && message->recv_buf == RT_NULL) {
            result = mtb_hal_spi_transfer(&spi->spi_obj, message->send_buf, message->length, RT_NULL, 0x00, 0x00);
        } else if (message->send_buf != RT_NULL && message->recv_buf != RT_NULL) {
            result = mtb_hal_spi_transfer(&spi->spi_obj, message->send_buf, message->length, message->recv_buf, message->length, 0x00);
        }
        if (result == CY_RSLT_SUCCESS) {
            wait_ret = rt_completion_wait(&spi->cpt, RT_WAITING_FOREVER);
        }
    }

__exit:
    if (message->cs_release && !(device->config.mode & RT_SPI_NO_CS)) {
        ifx_spi_set_cs(spi, (device->config.mode & RT_SPI_CS_HIGH) ? PIN_LOW : PIN_HIGH);
    }

    if (result != CY_RSLT_SUCCESS || wait_ret != RT_EOK)
        return 0;

    return message->length;
}

static const struct rt_spi_ops ifx_spi_ops = {
    .configure = spi_configure,
    .xfer = spixfer,
};
#ifdef BSP_USING_SPI1
static struct rt_spi_device spi1_dev;
#endif
rt_err_t drv_spi_init(void)
{
    for (int i = 0; i < sizeof(ifx_spi_obj) / sizeof(ifx_spi_obj[0]); i++) {
        struct ifx_spi* obj = &ifx_spi_obj[i];

        if (ifx_hw_spi_init(obj) == RT_EOK) {
            if (rt_spi_bus_register(&obj->spi_bus, obj->name, &ifx_spi_ops) != RT_EOK)
                return -RT_ERROR;
        } else {
            return -RT_ERROR;
        }
    }
#ifdef BSP_USING_SPI1
    if (rt_spi_bus_attach_device(&spi1_dev, "spi1_dev1", "spi1", (void*)GET_PIN(16, 3)) != RT_EOK)
        return -RT_ERROR;
#endif

    return RT_EOK;
}
