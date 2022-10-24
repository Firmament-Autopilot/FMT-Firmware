/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

// #define SPI_USE_DMA

struct gd32_spi_bus {
    struct rt_spi_bus parent;
    uint32_t spi_periph;
#ifdef SPI_USE_DMA
    //TODO
#endif
};

struct gd32_spi_cs {
    uint32_t gpio_periph;
    uint32_t pin;
};

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
    struct gd32_spi_bus* gd32_spi_bus = (struct gd32_spi_bus*)device->bus;
    spi_parameter_struct spi_init_struct;

    if (configuration->data_width <= 8) {
        spi_init_struct.frame_size = SPI_FRAMESIZE_8BIT;
    } else if (configuration->data_width <= 16) {
        spi_init_struct.frame_size = SPI_FRAMESIZE_16BIT;
    } else {
        return RT_EIO;
    }

    /* baudrate */
    {
        uint32_t max_hz;
        uint32_t PCLK;

        if (gd32_spi_bus->spi_periph == SPI1 || gd32_spi_bus->spi_periph == SPI2) {
            /* PCLK1 50MHz max. we assume the max frequency used */
            PCLK = 50000000;
        } else {
            /* PCLK2 100MHz max. we assume the max frequency used */
            PCLK = 100000000;
        }

        max_hz = configuration->max_hz;

        if (max_hz >= PCLK / 2) {
            spi_init_struct.prescale = SPI_PSC_2;
        } else if (max_hz >= PCLK / 4) {
            spi_init_struct.prescale = SPI_PSC_4;
        } else if (max_hz >= PCLK / 8) {
            spi_init_struct.prescale = SPI_PSC_8;
        } else if (max_hz >= PCLK / 16) {
            spi_init_struct.prescale = SPI_PSC_16;
        } else if (max_hz >= PCLK / 32) {
            spi_init_struct.prescale = SPI_PSC_32;
        } else if (max_hz >= PCLK / 64) {
            spi_init_struct.prescale = SPI_PSC_64;
        } else if (max_hz >= PCLK / 128) {
            spi_init_struct.prescale = SPI_PSC_128;
        } else {
            /*  min prescaler 256 */
            spi_init_struct.prescale = SPI_PSC_256;
        }
    } /* baudrate */

    /* CPOL */
    if (configuration->mode & RT_SPI_CPOL) {
        /* CPHA */
        if (configuration->mode & RT_SPI_CPHA) {
            spi_init_struct.clock_polarity_phase = SPI_CK_PL_HIGH_PH_2EDGE;
        } else {
            spi_init_struct.clock_polarity_phase = SPI_CK_PL_HIGH_PH_1EDGE;
        }
    } else {
        /* CPHA */
        if (configuration->mode & RT_SPI_CPHA) {
            spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_2EDGE;
        } else {
            // SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
            spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_1EDGE;
        }
    }

    /* MSB or LSB */
    if (configuration->mode & RT_SPI_MSB) {
        spi_init_struct.endian = SPI_ENDIAN_MSB;
    } else {
        spi_init_struct.endian = SPI_ENDIAN_LSB;
    }

    /* configure SPI parameter */
    spi_init_struct.trans_mode = SPI_TRANSMODE_FULLDUPLEX;
    spi_init_struct.device_mode = SPI_MASTER;
    spi_init_struct.nss = SPI_NSS_SOFT;
    spi_init(gd32_spi_bus->spi_periph, &spi_init_struct);

    spi_enable(gd32_spi_bus->spi_periph);

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
    struct gd32_spi_bus* gd32_spi_bus = (struct gd32_spi_bus*)device->bus;
    struct rt_spi_configuration* config = &device->config;
    struct gd32_spi_cs* gd32_spi_cs = (struct gd32_spi_cs*)device->parent.user_data;
    rt_uint32_t size = message->length;

    /* take CS */
    if (message->cs_take) {
        gpio_bit_reset(gd32_spi_cs->gpio_periph, gd32_spi_cs->pin);
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
                while (RESET == spi_i2s_flag_get(gd32_spi_bus->spi_periph, SPI_FLAG_TBE))
                    ;

                /* Send the byte */
                spi_i2s_data_transmit(gd32_spi_bus->spi_periph, data);

                /* Wait until a data is received */
                while (RESET == spi_i2s_flag_get(gd32_spi_bus->spi_periph, SPI_FLAG_RBNE))
                    ;

                /* Get the received data */
                data = spi_i2s_data_receive(gd32_spi_bus->spi_periph);

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
                while (RESET == spi_i2s_flag_get(gd32_spi_bus->spi_periph, SPI_FLAG_TBE))
                    ;

                /* Send the byte */
                spi_i2s_data_transmit(gd32_spi_bus->spi_periph, data);

                /* Wait until a data is received */
                while (RESET == spi_i2s_flag_get(gd32_spi_bus->spi_periph, SPI_FLAG_RBNE))
                    ;

                /* Get the received data */
                data = spi_i2s_data_receive(gd32_spi_bus->spi_periph);

                if (recv_ptr != RT_NULL) {
                    *recv_ptr++ = data;
                }
            }
        }
    }

    /* release CS */
    if (message->cs_release) {
        gpio_bit_set(gd32_spi_cs->gpio_periph, gd32_spi_cs->pin);
    }

    return message->length;
}

static struct rt_spi_ops gd32_spi_ops = {
    configure,
    transfer
};

/** \brief init and register gd32 spi bus.
 *
 * \param SPI: GD32 SPI, e.g: SPI1,SPI2,SPI3.
 * \param stm32_spi: stm32 spi bus struct.
 * \param spi_bus_name: spi bus name, e.g: "spi1"
 * \return rt_err_t RT_EOK for success
 */
static rt_err_t gd32_spi_register(uint32_t spi_periph,
                                  struct gd32_spi_bus* gd32_spi,
                                  const char* spi_bus_name)
{
    if (spi_periph == SPI0) {
        gd32_spi->spi_periph = SPI0;

        /* SPI0 configure */
        rcu_periph_clock_enable(RCU_GPIOB);
        /*  SPI0 GPIO Configuration
        PB3 ------> SPI0_SCK
        PB4 ------> SPI0_MISO
        PB5 ------> SPI0_MOSI */
        gpio_af_set(GPIOB, GPIO_AF_5, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5);
        gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5);
        gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5);

        /* Peripheral clock enable */
        rcu_periph_clock_enable(RCU_SPI0);

#ifdef SPI_USE_DMA
        //TODO
#endif
    } else {
        return RT_ENOSYS;
    }
    return rt_spi_bus_register(&gd32_spi->parent, spi_bus_name, &gd32_spi_ops);
}

/**
 * @brief Initialize spi bus and device
 * 
 * @return rt_err_t RT_EOK for success
 */
rt_err_t drv_spi_init(void)
{
    static struct gd32_spi_bus gd32_spi0;

    /* register SPI0 bus */
    RT_TRY(gd32_spi_register(SPI0, &gd32_spi0, "spi0"));

    /* attach spi_device_0 to spi0 */ // be careful if SPI0 pin would be conflict with other driver, such as pwm, rc, etc.
    {
        static struct rt_spi_device rt_spi0_dev0;
        static struct gd32_spi_cs spi0_cs0 = { .gpio_periph = GPIOE, .pin = GPIO_PIN_2 };

        /* enable cs pin clock */
        rcu_periph_clock_enable(RCU_GPIOE);
        /* configure cs pin gpio */
        gpio_mode_set(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_2);
        gpio_output_options_set(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);
        /* set CS pin by default */
        gpio_bit_set(spi0_cs0.gpio_periph, spi0_cs0.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi0_dev0, "spi0_dev0", "spi0", (void*)&spi0_cs0));
    }

    return RT_EOK;
}
