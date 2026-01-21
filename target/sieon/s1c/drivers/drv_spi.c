/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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
#include "hal/spi/spi.h"
#include "wl32_ll_spi.h"

struct wl32_spi_bus {
    struct rt_spi_bus parent;
    CM_SPI_TypeDef* spi_periph;
    struct rt_spi_configuration bus_config;
#ifdef SPI_USE_DMA
    // TODO
#endif
};

struct wl32_spi_cs {
    uint32_t gpio_port;
    uint32_t pin;
};

rt_inline uint32_t spi_flag_get(CM_SPI_TypeDef* spix, uint32_t u32FlagMask)
{
    return READ_REG32_BIT(spix->SR, u32FlagMask);
}

rt_inline void spi_data_write(CM_SPI_TypeDef* spix, uint32_t data)
{
    WRITE_REG32(spix->DR, data);
}

rt_inline uint32_t spd_data_read(CM_SPI_TypeDef* spix)
{
    return READ_REG32(spix->DR);
}

/**
 * @brief Configure spi device
 *
 * @param device SPI device
 * @param configuration SPI device configuration
 * @return rt_err_t RT_EOK for success
 */
static rt_err_t configure(struct rt_spi_device* device,
                          struct rt_spi_configuration* configuration)
{
    stc_spi_init_t stcSpiInit;
    struct wl32_spi_bus* wl32_spi_bus = (struct wl32_spi_bus*)device->bus;

    if (wl32_spi_bus->bus_config.mode == configuration->mode
        && wl32_spi_bus->bus_config.data_width == configuration->data_width
        && wl32_spi_bus->bus_config.max_hz == configuration->max_hz) {
        /* same configuration, do not need re-configure */
        return RT_EOK;
    }

    SPI_StructInit(&stcSpiInit);

    if (configuration->data_width <= 8) {
        stcSpiInit.u32DataBits = SPI_DATA_SIZE_8BIT;
    } else if (configuration->data_width <= 16) {
        stcSpiInit.u32DataBits = SPI_DATA_SIZE_16BIT;
    } else {
        return RT_EIO;
    }

    /* baudrate */
    {
        uint32_t spi_clock;
        uint32_t max_hz = configuration->max_hz;

        stc_clock_freq_t pstcClockFreq;
        CLK_GetClockFreq(&pstcClockFreq);
        spi_clock = pstcClockFreq.u32Pclk1Freq;

        if (max_hz > spi_clock) {
            max_hz = spi_clock;
        }

        if (max_hz >= spi_clock / 2) {
            stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV2;
        } else if (max_hz >= spi_clock / 4) {
            stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV4;
        } else if (max_hz >= spi_clock / 8) {
            stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV8;
        } else if (max_hz >= spi_clock / 16) {
            stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV16;
        } else if (max_hz >= spi_clock / 32) {
            stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV32;
        } else if (max_hz >= spi_clock / 64) {
            stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV64;
        } else if (max_hz >= spi_clock / 128) {
            stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV128;
        } else {
            /*  min prescaler 256 */
            stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV256;
        }
    }

    /* CPOL */
    if (configuration->mode & RT_SPI_CPOL) {
        /* CPHA */
        if (configuration->mode & RT_SPI_CPHA) {
            stcSpiInit.u32SpiMode = SPI_MD_3;
        } else {
            stcSpiInit.u32SpiMode = SPI_MD_2;
        }
    } else {
        /* CPHA */
        if (configuration->mode & RT_SPI_CPHA) {
            stcSpiInit.u32SpiMode = SPI_MD_1;
        } else {
            stcSpiInit.u32SpiMode = SPI_MD_0;
        }
    }

    /* MSB or LSB */
    if (configuration->mode & RT_SPI_MSB) {
        stcSpiInit.u32FirstBit = SPI_FIRST_MSB;
    } else {
        stcSpiInit.u32FirstBit = SPI_FIRST_LSB;
    }

    if (wl32_spi_bus->spi_periph == CM_SPI1) {
        SPI_Cmd(CM_SPI1, DISABLE);
        /* Configuration SPI */
        FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI1, ENABLE);
        stcSpiInit.u32WireMode = SPI_3_WIRE;
        stcSpiInit.u32TransMode = SPI_FULL_DUPLEX;
        stcSpiInit.u32MasterSlave = SPI_MASTER;
        stcSpiInit.u32Parity = SPI_PARITY_INVD;
        stcSpiInit.u32FrameLevel = SPI_1_FRAME;
        (void)SPI_Init(CM_SPI1, &stcSpiInit);
        SPI_Cmd(CM_SPI1, ENABLE);

    } else if (wl32_spi_bus->spi_periph == CM_SPI2) {
        SPI_Cmd(CM_SPI2, DISABLE);
        /* Configuration SPI */
        FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI2, ENABLE);
        stcSpiInit.u32WireMode = SPI_3_WIRE;
        stcSpiInit.u32TransMode = SPI_FULL_DUPLEX;
        stcSpiInit.u32MasterSlave = SPI_MASTER;
        stcSpiInit.u32Parity = SPI_PARITY_INVD;
        stcSpiInit.u32FrameLevel = SPI_1_FRAME;
        (void)SPI_Init(CM_SPI2, &stcSpiInit);
        SPI_Cmd(CM_SPI2, ENABLE);
    } else if (wl32_spi_bus->spi_periph == CM_SPI4) {
        SPI_Cmd(CM_SPI2, DISABLE);
        /* Configuration SPI */
        FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI4, ENABLE);
        stcSpiInit.u32WireMode = SPI_3_WIRE;
        stcSpiInit.u32TransMode = SPI_FULL_DUPLEX;
        stcSpiInit.u32MasterSlave = SPI_MASTER;
        stcSpiInit.u32Parity = SPI_PARITY_INVD;
        stcSpiInit.u32FrameLevel = SPI_1_FRAME;
        (void)SPI_Init(CM_SPI4, &stcSpiInit);
        SPI_Cmd(CM_SPI4, ENABLE);
    } else {
        return RT_EINVAL;
    }

    /* update SPI bus configuration */
    wl32_spi_bus->bus_config = *configuration;

    return RT_EOK;
}

/**
 * @brief SPI transfer function
 *
 * @param device SPI device instance
 * @param message SPI message to be transfered
 * @return rt_uint32_t bytes have been transfered
 */
static rt_uint32_t transfer(struct rt_spi_device* device, struct rt_spi_message* message)
{
    struct wl32_spi_bus* wl32_spi_bus = (struct wl32_spi_bus*)device->bus;
    struct rt_spi_configuration* config = &device->config;
    struct wl32_spi_cs* wl32_spi_cs = (struct wl32_spi_cs*)device->parent.user_data;
    rt_uint32_t size = message->length;

    /* take CS */
    if (message->cs_take) {
        GPIO_ResetPins(wl32_spi_cs->gpio_port, wl32_spi_cs->pin);
    }

#ifdef SPI_USE_DMA
    #error Not support SPI DMA.
#endif

    {
        if (config->data_width <= 8) {
            const rt_uint8_t* send_ptr = message->send_buf;
            rt_uint8_t* recv_ptr = message->recv_buf;

            while (size--) {
                rt_uint8_t data = 0xFF;

                if (send_ptr != RT_NULL) {
                    data = *send_ptr++;
                }

                /* Wait until the transmit buffer is empty */
                while (spi_flag_get(wl32_spi_bus->spi_periph, SPI_FLAG_TX_BUF_EMPTY) != SPI_FLAG_TX_BUF_EMPTY)
                    ;

                /* Send the byte */
                spi_data_write(wl32_spi_bus->spi_periph, data);

                /* Wait until a data is received */
                while (spi_flag_get(wl32_spi_bus->spi_periph, SPI_FLAG_RX_BUF_FULL) != SPI_FLAG_RX_BUF_FULL)
                    ;

                /* Get the received data */
                data = spd_data_read(wl32_spi_bus->spi_periph);

                if (recv_ptr != RT_NULL) {
                    *recv_ptr++ = data;
                }
            }
        } else if (config->data_width <= 16) {
            const rt_uint16_t* send_ptr = message->send_buf;
            rt_uint16_t* recv_ptr = message->recv_buf;

            while (size--) {
                rt_uint16_t data = 0xFFFF;

                if (send_ptr != RT_NULL) {
                    data = *send_ptr++;
                }

                /* Wait until the transmit buffer is empty */
                while (spi_flag_get(wl32_spi_bus->spi_periph, SPI_FLAG_TX_BUF_EMPTY) != SPI_FLAG_TX_BUF_EMPTY)
                    ;

                /* Send the byte */
                spi_data_write(wl32_spi_bus->spi_periph, data);

                /* Wait until a data is received */
                while (spi_flag_get(wl32_spi_bus->spi_periph, SPI_FLAG_RX_BUF_FULL) != SPI_FLAG_RX_BUF_FULL)
                    ;

                /* Get the received data */
                data = spd_data_read(wl32_spi_bus->spi_periph);

                if (recv_ptr != RT_NULL) {
                    *recv_ptr++ = data;
                }
            }
        }
    }

    /* release CS */
    if (message->cs_release) {
        GPIO_SetPins(wl32_spi_cs->gpio_port, wl32_spi_cs->pin);
    }

    return message->length;
}

static struct rt_spi_ops wl32_spi_ops = {
    configure,
    transfer
};

/** \brief init and register wl32 spi bus.
 *
 * \param SPI: WL32 SPI, e.g: SPI1,SPI2,SPI3.
 * \param stm32_spi: stm32 spi bus struct.
 * \param spi_bus_name: spi bus name, e.g: "spi1"
 * \return rt_err_t RT_EOK for success
 */

static rt_err_t wl32_spi_register(CM_SPI_TypeDef* spi_periph,
                                  struct wl32_spi_bus* wl32_spi,
                                  const char* spi_bus_name)
{

    stc_gpio_init_t stcGpioInit;

    if (spi_periph == CM_SPI1) {

        wl32_spi->spi_periph = CM_SPI1;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDrv = PIN_HIGH_DRV;
        stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
        (void)GPIO_Init(GPIO_PORT_D, GPIO_PIN_13, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_D, GPIO_PIN_14, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_D, GPIO_PIN_15, &stcGpioInit);

        /* Configure Port */
        GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_13, GPIO_FUNC_40); // SPI1-SCK
        GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_14, GPIO_FUNC_41); // SPI1-MOSI
        GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_15, GPIO_FUNC_42); // SPI1-MISO

    } else if (spi_periph == CM_SPI2) {

        wl32_spi->spi_periph = CM_SPI2;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDrv = PIN_HIGH_DRV;
        stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
        (void)GPIO_Init(GPIO_PORT_H, GPIO_PIN_13, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_H, GPIO_PIN_14, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_H, GPIO_PIN_15, &stcGpioInit);

        /* Configure Port */
        GPIO_SetFunc(GPIO_PORT_H, GPIO_PIN_13, GPIO_FUNC_43); // SPI2-SCK
        GPIO_SetFunc(GPIO_PORT_H, GPIO_PIN_15, GPIO_FUNC_44); // SPI2-MOSI
        GPIO_SetFunc(GPIO_PORT_H, GPIO_PIN_14, GPIO_FUNC_45); // SPI2-MISO
    } else if (spi_periph == CM_SPI4) {

        wl32_spi->spi_periph = CM_SPI4;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDrv = PIN_HIGH_DRV;
        stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
        (void)GPIO_Init(GPIO_PORT_E, GPIO_PIN_10, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_E, GPIO_PIN_11, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_E, GPIO_PIN_12, &stcGpioInit);

        /* Configure Port */
        GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_11, GPIO_FUNC_43); // SPI4-SCK
        GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_12, GPIO_FUNC_44); // SPI4-MOSI
        GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_10, GPIO_FUNC_45); // SPI4-MISO
    } else {
        return RT_ENOSYS;
    }

    return rt_spi_bus_register(&wl32_spi->parent, spi_bus_name, &wl32_spi_ops);
}

/**
 * @brief Initialize spi bus and device
 *
 * @return rt_err_t RT_EOK for success
 */
rt_err_t drv_spi_init(void)
{
    static struct wl32_spi_bus wl32_spi1;
    static struct wl32_spi_bus wl32_spi2;
    static struct wl32_spi_bus wl32_spi4;
    stc_gpio_init_t stcGpioInit;

    RT_TRY(wl32_spi_register(CM_SPI1, &wl32_spi1, "spi1"));

    /* attach spi_device_0 (SPL06) to spi1 */
    {
        static struct rt_spi_device rt_spi1_dev0;
        static struct wl32_spi_cs spi1_cs0 = { .gpio_port = GPIO_PORT_D, .pin = GPIO_PIN_12 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi1_cs0.gpio_port, spi1_cs0.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi1_cs0.gpio_port, spi1_cs0.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi1_dev0, "spi1_dev0", "spi1", (void*)&spi1_cs0));
    }

    RT_TRY(wl32_spi_register(CM_SPI2, &wl32_spi2, "spi2"));

    /* attach spi_device_0 (GD25Q16 Flash) to spi2 */
    {
        static struct rt_spi_device rt_spi2_dev0;
        static struct wl32_spi_cs spi2_cs0 = { .gpio_port = GPIO_PORT_H, .pin = GPIO_PIN_12 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi2_cs0.gpio_port, spi2_cs0.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi2_cs0.gpio_port, spi2_cs0.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi2_dev0, "spi2_dev0", "spi2", (void*)&spi2_cs0));
    }

    /* attach spi_device_1 (SPI EXT1) to spi2 */
    {
        static struct rt_spi_device rt_spi2_dev1;
        static struct wl32_spi_cs spi2_cs1 = { .gpio_port = GPIO_PORT_E, .pin = GPIO_PIN_09 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi2_cs1.gpio_port, spi2_cs1.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi2_cs1.gpio_port, spi2_cs1.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi2_dev1, "spi2_dev1", "spi2", (void*)&spi2_cs1));
    }

    /* attach spi_device_2 (SPI EXT2) to spi2 */
    {
        static struct rt_spi_device rt_spi2_dev2;
        static struct wl32_spi_cs spi2_cs2 = { .gpio_port = GPIO_PORT_F, .pin = GPIO_PIN_00 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi2_cs2.gpio_port, spi2_cs2.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi2_cs2.gpio_port, spi2_cs2.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi2_dev2, "spi2_dev2", "spi2", (void*)&spi2_cs2));
    }

    /* attach spi_device_3 (SPI EXT3) to spi2 */
    {
        static struct rt_spi_device rt_spi2_dev3;
        static struct wl32_spi_cs spi2_cs3 = { .gpio_port = GPIO_PORT_F, .pin = GPIO_PIN_01 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi2_cs3.gpio_port, spi2_cs3.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi2_cs3.gpio_port, spi2_cs3.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi2_dev3, "spi2_dev3", "spi2", (void*)&spi2_cs3));
    }

    RT_TRY(wl32_spi_register(CM_SPI4, &wl32_spi4, "spi4"));

    /* attach spi_device_0 (BMI088 Gyro) to spi4 */
    {
        static struct rt_spi_device rt_spi4_dev0;
        static struct wl32_spi_cs spi4_cs0 = { .gpio_port = GPIO_PORT_E, .pin = GPIO_PIN_15 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi4_cs0.gpio_port, spi4_cs0.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi4_cs0.gpio_port, spi4_cs0.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_dev0, "spi4_dev0", "spi4", (void*)&spi4_cs0));
    }

    /* attach spi_device_1 (BMI088 Accel) to spi4 */
    {
        static struct rt_spi_device rt_spi4_dev1;
        static struct wl32_spi_cs spi4_cs1 = { .gpio_port = GPIO_PORT_E, .pin = GPIO_PIN_13 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi4_cs1.gpio_port, spi4_cs1.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi4_cs1.gpio_port, spi4_cs1.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_dev1, "spi4_dev1", "spi4", (void*)&spi4_cs1));
    }

    /* attach spi_device_2 (ICM42688) to spi4 */
    {
        static struct rt_spi_device rt_spi4_dev2;
        static struct wl32_spi_cs spi4_cs2 = { .gpio_port = GPIO_PORT_E, .pin = GPIO_PIN_14 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi4_cs2.gpio_port, spi4_cs2.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi4_cs2.gpio_port, spi4_cs2.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_dev2, "spi4_dev2", "spi4", (void*)&spi4_cs2));
    }

    /* attach spi_device_3 (BMM150) to spi4 */
    {
        static struct rt_spi_device rt_spi4_dev3;
        static struct wl32_spi_cs spi4_cs3 = { .gpio_port = GPIO_PORT_B, .pin = GPIO_PIN_12 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(spi4_cs3.gpio_port, spi4_cs3.pin, &stcGpioInit);

        /* set CS pin by default */
        GPIO_SetPins(spi4_cs3.gpio_port, spi4_cs3.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_dev3, "spi4_dev3", "spi4", (void*)&spi4_cs3));
    }

    return RT_EOK;
}
