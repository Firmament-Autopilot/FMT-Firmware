/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2022-07-1      Rbb666            first version
 */


#include "drv_gpio.h"


#ifdef RT_USING_PIN
#define CYHAL_GET_PIN(pin)          ((uint8_t)(((uint8_t)pin) & 0x07U))
/** Macro that, given a gpio, will extract the port number */
#define CYHAL_GET_PORT(pin)         ((uint8_t)(((uint8_t)pin) >> 3U))
#define INT_PRIORITY        7u

#if defined(SOC_XMC7200D_E272K8384AA)
    #define __IFX_PORT_MAX      35u
#elif defined(SOC_SERIES_IFX_PSOCE84)
    #define __IFX_PORT_MAX      22u
#else
    #define __IFX_PORT_MAX      14u
#endif

#define PIN_IFXPORT_MAX     __IFX_PORT_MAX

mtb_hal_gpio_t mtb_gpio_irq;

static struct pin_irq_map pin_irq_map[] =
{
#if defined(SOC_CY8C6245LQI_S3D72) || defined(SOC_CY8C6244LQI_S4D92)
    {CYHAL_PORT_0,  ioss_interrupts_gpio_0_IRQn},
    {CYHAL_PORT_2,  ioss_interrupts_gpio_2_IRQn},
    {CYHAL_PORT_3,  ioss_interrupts_gpio_3_IRQn},
    {CYHAL_PORT_5,  ioss_interrupts_gpio_5_IRQn},
    {CYHAL_PORT_6,  ioss_interrupts_gpio_6_IRQn},
    {CYHAL_PORT_7,  ioss_interrupts_gpio_7_IRQn},
    {CYHAL_PORT_8,  ioss_interrupts_gpio_8_IRQn},
    {CYHAL_PORT_9,  ioss_interrupts_gpio_9_IRQn},
    {CYHAL_PORT_10,  ioss_interrupts_gpio_10_IRQn},
    {CYHAL_PORT_11,  ioss_interrupts_gpio_11_IRQn},
    {CYHAL_PORT_12,  ioss_interrupts_gpio_12_IRQn},
    {CYHAL_PORT_14,  ioss_interrupts_gpio_14_IRQn},
#elif defined(SOC_XMC7200D_E272K8384AA)
    {CYHAL_PORT_0,  ioss_interrupts_gpio_0_IRQn},
    {CYHAL_PORT_1,  ioss_interrupts_gpio_1_IRQn},
    {CYHAL_PORT_2,  ioss_interrupts_gpio_2_IRQn},
    {CYHAL_PORT_3,  ioss_interrupts_gpio_3_IRQn},
    {CYHAL_PORT_4,  ioss_interrupts_gpio_4_IRQn},
    {CYHAL_PORT_5,  ioss_interrupts_gpio_5_IRQn},
    {CYHAL_PORT_6,  ioss_interrupts_gpio_6_IRQn},
    {CYHAL_PORT_7,  ioss_interrupts_gpio_7_IRQn},
    {CYHAL_PORT_8,  ioss_interrupts_gpio_8_IRQn},
    {CYHAL_PORT_9,  ioss_interrupts_gpio_9_IRQn},
    {CYHAL_PORT_10,  ioss_interrupts_gpio_10_IRQn},
    {CYHAL_PORT_11,  ioss_interrupts_gpio_11_IRQn},
    {CYHAL_PORT_12,  ioss_interrupts_gpio_12_IRQn},
    {CYHAL_PORT_13,  ioss_interrupts_gpio_13_IRQn},
    {CYHAL_PORT_14,  ioss_interrupts_gpio_14_IRQn},
    {CYHAL_PORT_15,  ioss_interrupts_gpio_15_IRQn},
    {CYHAL_PORT_16,  ioss_interrupts_gpio_16_IRQn},
    {CYHAL_PORT_17,  ioss_interrupts_gpio_17_IRQn},
    {CYHAL_PORT_18,  ioss_interrupts_gpio_18_IRQn},
    {CYHAL_PORT_19,  ioss_interrupts_gpio_19_IRQn},
    {CYHAL_PORT_20,  ioss_interrupts_gpio_20_IRQn},
    {CYHAL_PORT_21,  ioss_interrupts_gpio_21_IRQn},
    {CYHAL_PORT_22,  ioss_interrupts_gpio_23_IRQn},
    {CYHAL_PORT_24,  ioss_interrupts_gpio_24_IRQn},
    {CYHAL_PORT_25,  ioss_interrupts_gpio_25_IRQn},
    {CYHAL_PORT_26,  ioss_interrupts_gpio_26_IRQn},
    {CYHAL_PORT_27,  ioss_interrupts_gpio_27_IRQn},
    {CYHAL_PORT_28,  ioss_interrupts_gpio_28_IRQn},
    {CYHAL_PORT_29,  ioss_interrupts_gpio_29_IRQn},
    {CYHAL_PORT_30,  ioss_interrupts_gpio_30_IRQn},
    {CYHAL_PORT_31,  ioss_interrupts_gpio_31_IRQn},
    {CYHAL_PORT_32,  ioss_interrupts_gpio_32_IRQn},
    {CYHAL_PORT_33,  ioss_interrupts_gpio_33_IRQn},
    {CYHAL_PORT_34,  ioss_interrupts_gpio_34_IRQn},
#elif defined(SOC_SERIES_IFX_PSOCE84)
    {CYHAL_PORT_0,  ioss_interrupts_gpio_0_IRQn},
    {CYHAL_PORT_1,  ioss_interrupts_gpio_1_IRQn},
    {CYHAL_PORT_2,  ioss_interrupts_gpio_2_IRQn},
    {CYHAL_PORT_3,  ioss_interrupts_gpio_3_IRQn},
    {CYHAL_PORT_4,  ioss_interrupts_gpio_4_IRQn},
    {CYHAL_PORT_5,  ioss_interrupts_gpio_5_IRQn},
    {CYHAL_PORT_6,  ioss_interrupts_gpio_6_IRQn},
    {CYHAL_PORT_7,  ioss_interrupts_gpio_7_IRQn},
    {CYHAL_PORT_8,  ioss_interrupts_gpio_8_IRQn},
    {CYHAL_PORT_9,  ioss_interrupts_gpio_9_IRQn},
    {CYHAL_PORT_10,  ioss_interrupts_gpio_10_IRQn},
    {CYHAL_PORT_11,  ioss_interrupts_gpio_11_IRQn},
    {CYHAL_PORT_12,  ioss_interrupts_gpio_12_IRQn},
    {CYHAL_PORT_13,  ioss_interrupts_gpio_13_IRQn},
    {CYHAL_PORT_14,  ioss_interrupts_gpio_14_IRQn},
    {CYHAL_PORT_15,  ioss_interrupts_gpio_15_IRQn},
    {CYHAL_PORT_16,  ioss_interrupts_gpio_16_IRQn},
    {CYHAL_PORT_17,  ioss_interrupts_gpio_17_IRQn},
    {CYHAL_PORT_18,  ioss_interrupts_gpio_18_IRQn},
    {CYHAL_PORT_19,  ioss_interrupts_gpio_19_IRQn},
    {CYHAL_PORT_20,  ioss_interrupts_gpio_20_IRQn},
    {CYHAL_PORT_21,  ioss_interrupts_gpio_21_IRQn},
#else
    {CYHAL_PORT_0,  ioss_interrupts_gpio_0_IRQn},
    {CYHAL_PORT_1,  ioss_interrupts_gpio_1_IRQn},
    {CYHAL_PORT_2,  ioss_interrupts_gpio_2_IRQn},
    {CYHAL_PORT_3,  ioss_interrupts_gpio_3_IRQn},
    {CYHAL_PORT_4,  ioss_interrupts_gpio_4_IRQn},
    {CYHAL_PORT_5,  ioss_interrupts_gpio_5_IRQn},
    {CYHAL_PORT_6,  ioss_interrupts_gpio_6_IRQn},
    {CYHAL_PORT_7,  ioss_interrupts_gpio_7_IRQn},
    {CYHAL_PORT_8,  ioss_interrupts_gpio_8_IRQn},
    {CYHAL_PORT_9,  ioss_interrupts_gpio_9_IRQn},
    {CYHAL_PORT_10,  ioss_interrupts_gpio_10_IRQn},
    {CYHAL_PORT_11,  ioss_interrupts_gpio_11_IRQn},
    {CYHAL_PORT_12,  ioss_interrupts_gpio_12_IRQn},
    {CYHAL_PORT_13,  ioss_interrupts_gpio_13_IRQn},
    {CYHAL_PORT_14,  ioss_interrupts_gpio_14_IRQn},
#endif
};

static struct rt_pin_irq_hdr pin_irq_handler_tab[] =
{
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
    {-1, 0, RT_NULL, RT_NULL},
};

void gpio_interrupt_handler()
{
    //Todo:Interrupt Callback Function
    mtb_hal_gpio_process_interrupt(&mtb_gpio_irq);
}
void gpio_event_handler(void* handler_arg, mtb_hal_gpio_event_t event)
{
    //Todo:Interrupt Callback Function
}

static void ifx_pin_mode(rt_device_t dev, rt_base_t pin, rt_uint8_t mode)
{
    mtb_hal_gpio_t mtb_gpio;
    if (CYHAL_GET_PORT(pin) >= PIN_IFXPORT_MAX)
    {
        return;
    }
    switch (mode)
    {
    case PIN_MODE_OUTPUT:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_STRONG, 1U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;

    case PIN_MODE_INPUT:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_HIGHZ, 1U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;

    case PIN_MODE_INPUT_PULLUP:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_PULLUP, 1U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;

    case PIN_MODE_INPUT_PULLDOWN:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_PULLDOWN, 0U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;

    case PIN_MODE_OUTPUT_OD:
        Cy_GPIO_Pin_FastInit(Cy_GPIO_PortToAddr(CYHAL_GET_PORT(pin)), CYHAL_GET_PIN(pin), CY_GPIO_DM_OD_DRIVESLOW, 0U, HSIOM_SEL_GPIO);
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        break;
    }
}

static void ifx_pin_write(rt_device_t dev, rt_base_t pin, rt_uint8_t value)
{
    mtb_hal_gpio_t mtb_gpio;
    if (CYHAL_GET_PORT(pin) < PIN_IFXPORT_MAX)
    {
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        mtb_hal_gpio_write(&mtb_gpio, value);
    }
    else
    {
        return;
    }
}

static rt_int8_t ifx_pin_read(struct rt_device *device, rt_base_t pin)
{
    mtb_hal_gpio_t mtb_gpio;
    if (CYHAL_GET_PORT(pin) < PIN_IFXPORT_MAX)
    {
        mtb_hal_gpio_setup(&mtb_gpio, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
        return mtb_hal_gpio_read(&mtb_gpio);
    }
    else
    {
        return -RT_EINVAL;
    }
}

static rt_err_t ifx_pin_attach_irq(struct rt_device *device, rt_base_t pin,
                                   rt_uint8_t mode, void (*hdr)(void *args), void *args)
{
    rt_uint16_t gpio_port;
    rt_base_t level;

    if (CYHAL_GET_PORT(pin) < PIN_IFXPORT_MAX)
    {
        gpio_port = CYHAL_GET_PORT(pin);
    }
    else
    {
        return -RT_ERROR;
    }
    level = rt_hw_interrupt_disable();
    if (pin_irq_handler_tab[gpio_port].pin == pin &&
            pin_irq_handler_tab[gpio_port].hdr == hdr &&
            pin_irq_handler_tab[gpio_port].mode == mode &&
            pin_irq_handler_tab[gpio_port].args == args)
    {
        rt_hw_interrupt_enable(level);
        return RT_EOK;
    }

    if (pin_irq_handler_tab[gpio_port].pin != -1)
    {
        rt_hw_interrupt_enable(level);
        return -RT_EBUSY;
    }

    pin_irq_handler_tab[gpio_port].pin = pin;
    pin_irq_handler_tab[gpio_port].hdr = hdr;
    pin_irq_handler_tab[gpio_port].mode = mode;
    pin_irq_handler_tab[gpio_port].args = args;
    rt_hw_interrupt_enable(level);

    return RT_EOK;
}

static rt_err_t ifx_pin_dettach_irq(struct rt_device *device, rt_base_t pin)
{
    rt_uint16_t gpio_port;
    rt_base_t level;

    if (CYHAL_GET_PORT(pin) < PIN_IFXPORT_MAX)
    {
        gpio_port = CYHAL_GET_PORT(pin);
    }
    else
    {
        return -RT_ERROR;
    }

    level = rt_hw_interrupt_disable();

    if (pin_irq_handler_tab[gpio_port].pin == -1)
    {
        rt_hw_interrupt_enable(level);
        return RT_EOK;
    }

    pin_irq_handler_tab[gpio_port].pin = -1;
    pin_irq_handler_tab[gpio_port].hdr = RT_NULL;
    pin_irq_handler_tab[gpio_port].mode = 0;
    pin_irq_handler_tab[gpio_port].args = RT_NULL;
    rt_hw_interrupt_enable(level);

    return RT_EOK;
}

static void ifx_gpio_event_callback(void *handler_arg, mtb_hal_gpio_event_t event)
{
    rt_uint16_t port = (rt_uint32_t)handler_arg;
    if (port < PIN_IFXPORT_MAX && pin_irq_handler_tab[port].hdr != RT_NULL)
    {
        pin_irq_handler_tab[port].hdr(pin_irq_handler_tab[port].args);
    }
}


static rt_err_t ifx_pin_irq_enable(struct rt_device *device, rt_base_t pin,
                                   rt_uint8_t enabled)
{
    rt_base_t level;
    rt_uint8_t pin_irq_mode = -1;
    const struct pin_irq_map *irqmap;

    if (CYHAL_GET_PORT(pin) < PIN_IFXPORT_MAX)
    {
        mtb_hal_gpio_setup(&mtb_gpio_irq, CYHAL_GET_PORT(pin), CYHAL_GET_PIN(pin));
    }
    else
    {
        return -RT_ERROR;
    }

    irqmap = &pin_irq_map[mtb_gpio_irq.port_num];
    cy_stc_sysint_t         intr_cfg;
    intr_cfg.intrSrc = irqmap->irqno;
    intr_cfg.intrPriority = INT_PRIORITY;
    Cy_SysInt_Init(&intr_cfg, gpio_interrupt_handler);
    NVIC_EnableIRQ(irqmap->irqno);

    if (enabled == PIN_IRQ_ENABLE)
    {
        level = rt_hw_interrupt_disable();

        if (pin_irq_handler_tab[mtb_gpio_irq.port_num].pin == -1)
        {
            rt_hw_interrupt_enable(level);
            return -RT_EINVAL;
        }

        irqmap = &pin_irq_map[mtb_gpio_irq.port_num];

#if !defined(COMPONENT_CAT1C)

#endif
        switch (pin_irq_handler_tab[mtb_gpio_irq.port_num].mode)
        {
        case PIN_IRQ_MODE_RISING:
            pin_irq_mode = MTB_HAL_GPIO_IRQ_RISE;
            break;

        case PIN_IRQ_MODE_FALLING:
            pin_irq_mode = MTB_HAL_GPIO_IRQ_FALL;
            break;

        case PIN_IRQ_MODE_RISING_FALLING:
            pin_irq_mode = MTB_HAL_GPIO_IRQ_BOTH;
            break;

        default:
            break;
        }
        mtb_hal_gpio_register_callback(&mtb_gpio_irq,
                                       ifx_gpio_event_callback,
                                       (void *)(uintptr_t)mtb_gpio_irq.port_num);
        mtb_hal_gpio_enable_event(&mtb_gpio_irq, pin_irq_mode, RT_TRUE);
        rt_hw_interrupt_enable(level);
    }
    else if (enabled == PIN_IRQ_DISABLE)
    {
        level = rt_hw_interrupt_disable();
        Cy_GPIO_Port_Deinit(Cy_GPIO_PortToAddr(mtb_gpio_irq.port_num));

#if !defined(COMPONENT_CAT1C)
        NVIC_DisableIRQ(irqmap->irqno);
#endif
        rt_hw_interrupt_enable(level);
    }
    else
    {
        return -RT_EINVAL;
    }

    return RT_EOK;
}

const static struct rt_pin_ops _ifx_pin_ops =
{
    ifx_pin_mode,
    ifx_pin_write,
    ifx_pin_read,
    ifx_pin_attach_irq,
    ifx_pin_dettach_irq,
    ifx_pin_irq_enable,
    RT_NULL,
};

int rt_hw_pin_init(void)
{
    return rt_device_pin_register("pin", &_ifx_pin_ops, RT_NULL);
}

#endif /* RT_USING_PIN */
