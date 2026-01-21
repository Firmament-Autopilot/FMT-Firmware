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

#define EXAMPLE_PERIPH_WE               (LL_PERIPH_GPIO | LL_PERIPH_EFM | LL_PERIPH_FCG | \
    LL_PERIPH_PWC_CLK_RMU | LL_PERIPH_SRAM)
#define EXAMPLE_PERIPH_WP               (LL_PERIPH_EFM | LL_PERIPH_FCG | LL_PERIPH_SRAM)

#define EXAMPLE_SPI_BUF_LEN             (128UL)
//static char u8TxBuf[EXAMPLE_SPI_BUF_LEN] = "SPI Master/Slave example: Communication between two boards!";
//static char u8RxBuf[EXAMPLE_SPI_BUF_LEN];

/* SPI communication timeout */
#define SPI_COMM_TIMEOUT_VAL            (0x20000000UL)
#define SPI_CLK_BASE    (120000UL)


struct wl32_spi_bus {
    struct rt_spi_bus parent;
    CM_SPI_TypeDef * spi_periph;
    struct rt_spi_configuration bus_config;
#ifdef SPI_USE_DMA
    //TODO
#endif
};

struct wl32_spi_cs {
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
    stc_spi_init_t stcSpiInit;
    struct wl32_spi_bus* wl32_spi_bus = (struct wl32_spi_bus*)device->bus;
    SPI_StructInit(&stcSpiInit);

    if (wl32_spi_bus->bus_config.mode == configuration->mode
        && wl32_spi_bus->bus_config.data_width == configuration->data_width
        && wl32_spi_bus->bus_config.max_hz == configuration->max_hz) {
        /* same configuration, do not need re-configure */
        return RT_EOK;
    }
    
    if (configuration->data_width <= 8) {
        stcSpiInit.u32DataBits          = SPI_DATA_SIZE_8BIT;
        //spi_init_struct.frame_size = SPI_FRAMESIZE_8BIT;
    } else if (configuration->data_width <= 16) {
        stcSpiInit.u32DataBits          = SPI_DATA_SIZE_16BIT;
    } else {
        return RT_EIO;
    }

    
    /* CPOL */
    if (configuration->mode & RT_SPI_CPOL) {
        /* CPHA */
        if (configuration->mode & RT_SPI_CPHA) {
            stcSpiInit.u32SpiMode           = SPI_MD_3;
            //spi_init_struct.clock_polarity_phase = SPI_CK_PL_HIGH_PH_2EDGE;
        } else {
            stcSpiInit.u32SpiMode           = SPI_MD_2;
            //spi_init_struct.clock_polarity_phase = SPI_CK_PL_HIGH_PH_1EDGE;
        }
    } else {
        /* CPHA */
        if (configuration->mode & RT_SPI_CPHA) {
            stcSpiInit.u32SpiMode           = SPI_MD_1;
            //spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_2EDGE;
        } else {
            stcSpiInit.u32SpiMode           = SPI_MD_0;
            //spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_1EDGE;
        }
    }

    /* MSB or LSB */
    if (configuration->mode & RT_SPI_MSB) {
        stcSpiInit.u32FirstBit          = SPI_FIRST_MSB;
        //spi_init_struct.endian = SPI_ENDIAN_MSB;
    } else {
        stcSpiInit.u32FirstBit          = SPI_FIRST_LSB;
        //spi_init_struct.endian = SPI_ENDIAN_LSB;
    }
    stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV32;//SPI_BR_CLK_DIV64;//SPI_BR_CLK_DIV32;//SPI_BR_CLK_DIV256;//
    if(wl32_spi_bus->spi_periph == CM_SPI6)
    {
        SPI_Cmd(CM_SPI6, DISABLE);
        /* Configuration SPI */
        FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI6, ENABLE);
        stcSpiInit.u32WireMode          = SPI_3_WIRE;//SPI_4_WIRE;
        stcSpiInit.u32TransMode         = SPI_FULL_DUPLEX;
        stcSpiInit.u32MasterSlave       = SPI_MASTER;
        stcSpiInit.u32Parity            = SPI_PARITY_INVD;
        //stcSpiInit.u32SpiMode           = SPI_MD_1;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV32;
        //stcSpiInit.u32FirstBit          = SPI_FIRST_MSB;
        stcSpiInit.u32FrameLevel        = SPI_1_FRAME;
        (void)SPI_Init(CM_SPI6, &stcSpiInit);
        SPI_Cmd(CM_SPI6, ENABLE);
    }
    else if(wl32_spi_bus->spi_periph == CM_SPI1)
    {
        SPI_Cmd(CM_SPI1, DISABLE);
        /* Configuration SPI */
        FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI1, ENABLE);
        stcSpiInit.u32WireMode          = SPI_3_WIRE;//SPI_4_WIRE;
        stcSpiInit.u32TransMode         = SPI_FULL_DUPLEX;
        stcSpiInit.u32MasterSlave       = SPI_MASTER;
        stcSpiInit.u32Parity            = SPI_PARITY_INVD;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV256;//
        //stcSpiInit.u32SpiMode           = SPI_MD_1;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV32;
        //stcSpiInit.u32DataBits          = SPI_DATA_SIZE_8BIT;
        //stcSpiInit.u32FirstBit          = SPI_FIRST_MSB;
        stcSpiInit.u32FrameLevel        = SPI_1_FRAME;
        (void)SPI_Init(CM_SPI1, &stcSpiInit);
        SPI_Cmd(CM_SPI1, ENABLE);

    }else if(wl32_spi_bus->spi_periph == CM_SPI2)
    {
        SPI_Cmd(CM_SPI2, DISABLE);
        /* Configuration SPI */
        FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI2, ENABLE);
        stcSpiInit.u32WireMode          = SPI_3_WIRE;//SPI_4_WIRE;
        stcSpiInit.u32TransMode         = SPI_FULL_DUPLEX;
        stcSpiInit.u32MasterSlave       = SPI_MASTER;
        stcSpiInit.u32Parity            = SPI_PARITY_INVD;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV256;//
        //stcSpiInit.u32SpiMode           = SPI_MD_1;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV32;
        //stcSpiInit.u32DataBits          = SPI_DATA_SIZE_8BIT;
        //stcSpiInit.u32FirstBit          = SPI_FIRST_MSB;
        stcSpiInit.u32FrameLevel        = SPI_1_FRAME;
        (void)SPI_Init(CM_SPI2, &stcSpiInit);
        SPI_Cmd(CM_SPI2, ENABLE);

    }else if(wl32_spi_bus->spi_periph == CM_SPI3)
    {
        SPI_Cmd(CM_SPI3, DISABLE);
        /* Configuration SPI */
        FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI3, ENABLE);
        stcSpiInit.u32WireMode          = SPI_3_WIRE;//SPI_4_WIRE;
        stcSpiInit.u32TransMode         = SPI_FULL_DUPLEX;
        stcSpiInit.u32MasterSlave       = SPI_MASTER;
        stcSpiInit.u32Parity            = SPI_PARITY_INVD;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV256;//
        //stcSpiInit.u32SpiMode           = SPI_MD_1;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV32;
        //stcSpiInit.u32DataBits          = SPI_DATA_SIZE_8BIT;
        //stcSpiInit.u32FirstBit          = SPI_FIRST_MSB;
        stcSpiInit.u32FrameLevel        = SPI_1_FRAME;
        (void)SPI_Init(CM_SPI3, &stcSpiInit);
        SPI_Cmd(CM_SPI3, ENABLE);

    }else if(wl32_spi_bus->spi_periph == CM_SPI4)
    {
        SPI_Cmd(CM_SPI4, DISABLE);
        /* Configuration SPI */
        FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI4, ENABLE);
        stcSpiInit.u32WireMode          = SPI_3_WIRE;//SPI_4_WIRE;
        stcSpiInit.u32TransMode         = SPI_FULL_DUPLEX;
        stcSpiInit.u32MasterSlave       = SPI_MASTER;
        stcSpiInit.u32Parity            = SPI_PARITY_INVD;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV256;//
        //stcSpiInit.u32SpiMode           = SPI_MD_1;
        //stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV32;
        //stcSpiInit.u32DataBits          = SPI_DATA_SIZE_8BIT;
        //stcSpiInit.u32FirstBit          = SPI_FIRST_MSB;
        stcSpiInit.u32FrameLevel        = SPI_1_FRAME;
        (void)SPI_Init(CM_SPI4, &stcSpiInit);
        SPI_Cmd(CM_SPI4, ENABLE);

    }
    /* update SPI bus configuration */
    wl32_spi_bus->bus_config = *configuration;
    
    return RT_EOK;
}
uint32_t spi_flag_get(CM_SPI_TypeDef * spix, uint32_t u32FlagMask) 
{
    return READ_REG32_BIT(spix->SR, u32FlagMask);
}

void spi_data_write(CM_SPI_TypeDef * spix, rt_uint8_t data)
{
    WRITE_REG32(spix->DR, data);
}

uint8_t spd_data_read(CM_SPI_TypeDef * spix)
{
    return (uint8_t)spix->DR;
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
        GPIO_ResetPins(wl32_spi_cs->gpio_periph, wl32_spi_cs->pin);
        //gpio_bit_reset(wl32_spi_cs->gpio_periph, wl32_spi_cs->pin);
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
                // while (RESET == spi_i2s_flag_get(gd32_spi_bus->spi_periph, SPI_FLAG_TBE))
                //     ;
                    
                while (spi_flag_get(wl32_spi_bus->spi_periph,SPI_FLAG_TX_BUF_EMPTY) != SPI_FLAG_TX_BUF_EMPTY)
                    ;

                /* Send the byte */
                // spi_i2s_data_transmit(gd32_spi_bus->spi_periph, data);
                spi_data_write(wl32_spi_bus->spi_periph, data);

                /* Wait until a data is received */
                // while (RESET == spi_i2s_flag_get(gd32_spi_bus->spi_periph, SPI_FLAG_RBNE))
                //     ;
                while (spi_flag_get(wl32_spi_bus->spi_periph,SPI_FLAG_RX_BUF_FULL) != SPI_FLAG_RX_BUF_FULL)
                    ;

                /* Get the received data */
                // data = spi_i2s_data_receive(wl32_spi_bus->spi_periph);
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
                // while (RESET == spi_i2s_flag_get(gd32_spi_bus->spi_periph, SPI_FLAG_TBE))
                //     ;
                while (spi_flag_get(wl32_spi_bus->spi_periph,SPI_FLAG_TX_BUF_EMPTY) != SPI_FLAG_TX_BUF_EMPTY)
                    ;

                /* Send the byte */
                // spi_i2s_data_transmit(gd32_spi_bus->spi_periph, data);
                spi_data_write(wl32_spi_bus->spi_periph, data);

                /* Wait until a data is received */
                // while (RESET == spi_i2s_flag_get(gd32_spi_bus->spi_periph, SPI_FLAG_RBNE))
                //     ;
                while (spi_flag_get(wl32_spi_bus->spi_periph,SPI_FLAG_RX_BUF_FULL) != SPI_FLAG_RX_BUF_FULL)
                    ;

                /* Get the received data */
                // data = spi_i2s_data_receive(gd32_spi_bus->spi_periph);
                data = spd_data_read(wl32_spi_bus->spi_periph);

                if (recv_ptr != RT_NULL) {
                    *recv_ptr++ = data;
                }
            }
        }
    }

    /* release CS */
    if (message->cs_release) {
        //gpio_bit_set(gd32_spi_cs->gpio_periph, gd32_spi_cs->pin);
        GPIO_SetPins(wl32_spi_cs->gpio_periph, wl32_spi_cs->pin);
    }

    return message->length;
}

static struct rt_spi_ops wl32_spi_ops = {
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

static rt_err_t wl32_spi_register(uint32_t spi_periph,
                                  struct wl32_spi_bus* wl32_spi,
                                  const char* spi_bus_name)
{

    stc_gpio_init_t stcGpioInit;
    
    LL_PERIPH_WE(EXAMPLE_PERIPH_WE);
    if (spi_periph == (uint32_t)CM_SPI6)
    {
        wl32_spi->spi_periph = CM_SPI6;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDrv       = PIN_HIGH_DRV;
        stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
    //(void)GPIO_Init(GPIO_PORT_E,   GPIO_PIN_06,   &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_E,  GPIO_PIN_03,  &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_E, GPIO_PIN_04, &stcGpioInit);
        //stcGpioInit.u16PullUp = PIN_PU_ON;
        (void)GPIO_Init(GPIO_PORT_E, GPIO_PIN_05, &stcGpioInit);
        

        /* Configure Port */
    //GPIO_SetFunc(GPIO_PORT_E,   GPIO_PIN_06,   GPIO_FUNC_49);
        GPIO_SetFunc(GPIO_PORT_E,  GPIO_PIN_03,  GPIO_FUNC_46);
        GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_04, GPIO_FUNC_47);
        GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_05, GPIO_FUNC_48);

    }
    else if(spi_periph == (uint32_t)CM_SPI1)
    {

        wl32_spi->spi_periph = CM_SPI1;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDrv       = PIN_HIGH_DRV;
        stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
    //(void)GPIO_Init(GPIO_PORT_E,   GPIO_PIN_06,   &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_D, GPIO_PIN_13, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_D, GPIO_PIN_14, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_D, GPIO_PIN_15, &stcGpioInit);
        

        /* Configure Port */
    //GPIO_SetFunc(GPIO_PORT_E,   GPIO_PIN_06,   GPIO_FUNC_49);
        GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_13, GPIO_FUNC_40);
        GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_14, GPIO_FUNC_41);
        GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_15, GPIO_FUNC_42);

    }else if(spi_periph == (uint32_t)CM_SPI2)
    {

        wl32_spi->spi_periph = CM_SPI2;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDrv       = PIN_HIGH_DRV;
        stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
    //(void)GPIO_Init(GPIO_PORT_E,   GPIO_PIN_06,   &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_H,  GPIO_PIN_15,  &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_H, GPIO_PIN_14, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_H, GPIO_PIN_13, &stcGpioInit);
        

        /* Configure Port */
    //GPIO_SetFunc(GPIO_PORT_E,   GPIO_PIN_06,   GPIO_FUNC_49);
        GPIO_SetFunc(GPIO_PORT_H,  GPIO_PIN_15,  GPIO_FUNC_44);
        GPIO_SetFunc(GPIO_PORT_H, GPIO_PIN_14, GPIO_FUNC_45);
        GPIO_SetFunc(GPIO_PORT_H, GPIO_PIN_13, GPIO_FUNC_43);

    }else if(spi_periph == (uint32_t)CM_SPI3)
    {

        wl32_spi->spi_periph = CM_SPI3;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDrv       = PIN_HIGH_DRV;
        stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
    //(void)GPIO_Init(GPIO_PORT_E,   GPIO_PIN_06,   &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_D,  GPIO_PIN_11,  &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_D, GPIO_PIN_10, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_D, GPIO_PIN_09, &stcGpioInit);
        

        /* Configure Port */
    //GPIO_SetFunc(GPIO_PORT_E,   GPIO_PIN_06,   GPIO_FUNC_49);
        GPIO_SetFunc(GPIO_PORT_D,  GPIO_PIN_11,  GPIO_FUNC_46);
        GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_10, GPIO_FUNC_48);
        GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_09, GPIO_FUNC_47);

    }else if(spi_periph == (uint32_t)CM_SPI4)
    {

        wl32_spi->spi_periph = CM_SPI4;

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDrv       = PIN_HIGH_DRV;
        stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
    //(void)GPIO_Init(GPIO_PORT_E,   GPIO_PIN_06,   &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_E, GPIO_PIN_12, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_E, GPIO_PIN_11, &stcGpioInit);
        (void)GPIO_Init(GPIO_PORT_E, GPIO_PIN_10, &stcGpioInit);
        

        /* Configure Port */
    //GPIO_SetFunc(GPIO_PORT_E,   GPIO_PIN_06,   GPIO_FUNC_49);
        GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_12, GPIO_FUNC_44);
        GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_11, GPIO_FUNC_43);
        GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_10, GPIO_FUNC_45);

    }

    LL_PERIPH_WP(EXAMPLE_PERIPH_WP);
    return rt_spi_bus_register(&wl32_spi->parent, spi_bus_name, &wl32_spi_ops);
}

/**
 * @brief Initialize spi bus and device
 * 
 * @return rt_err_t RT_EOK for success
 */
rt_err_t drv_spi_init(void)
{
    static struct wl32_spi_bus wl32_spi0;
    static struct wl32_spi_bus wl32_spi1;
    static struct wl32_spi_bus wl32_spi2;
    stc_gpio_init_t stcGpioInit;

    LL_PERIPH_WE(EXAMPLE_PERIPH_WE);

    RT_TRY(wl32_spi_register((uint32_t)CM_SPI4, &wl32_spi0, "spi0"));

 /* attach spi_device_0 (BMI088 ACCEL) to spi0 */
    {
        static struct rt_spi_device rt_spi0_dev0;
        static struct wl32_spi_cs spi0_cs0 = { .gpio_periph = GPIO_PORT_E, .pin = GPIO_PIN_15 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        //stcGpioInit.u16PinDrv         = PIN_HIGH_DRV;
        GPIO_Init(GPIO_PORT_E, GPIO_PIN_15, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi0_cs0.gpio_periph, spi0_cs0.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi0_dev0, "spi0_dev0", "spi0", (void*)&spi0_cs0));
    }
/* attach spi_device_1 (BMI088 GYRO) to spi0 */
    {
        static struct rt_spi_device rt_spi0_dev1;
        static struct wl32_spi_cs spi0_cs1 = { .gpio_periph = GPIO_PORT_E, .pin = GPIO_PIN_13 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        //stcGpioInit.u16PinDrv         = PIN_HIGH_DRV;
        GPIO_Init(GPIO_PORT_E, GPIO_PIN_13, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi0_cs1.gpio_periph, spi0_cs1.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi0_dev1, "spi0_dev1", "spi0", (void*)&spi0_cs1));
    }

    /* attach spi_device_2 (BMM150 MAG) to spi0 */
    {
        static struct rt_spi_device rt_spi0_dev2;
        static struct wl32_spi_cs spi0_cs2 = { .gpio_periph = GPIO_PORT_B, .pin = GPIO_PIN_12 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(GPIO_PORT_B, GPIO_PIN_12, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi0_cs2.gpio_periph, spi0_cs2.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi0_dev2, "spi0_dev2", "spi0", (void*)&spi0_cs2));
    }

    /* attach spi_device_3 (SPL06 Baro) to spi0 */
    {
        static struct rt_spi_device rt_spi0_dev3;
        static struct wl32_spi_cs spi0_cs3 = { .gpio_periph = GPIO_PORT_E, .pin = GPIO_PIN_14 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(GPIO_PORT_E, GPIO_PIN_14, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi0_cs3.gpio_periph, spi0_cs3.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi0_dev3, "spi0_dev3", "spi0", (void*)&spi0_cs3));
    }
#if 0
    /* attach spi_device_4 (ICM42688 IMU) to spi0 */
    {
        static struct rt_spi_device rt_spi0_dev4;
        static struct wl32_spi_cs spi0_cs4 = { .gpio_periph = GPIO_PORT_E, .pin = GPIO_PIN_13 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        //GPIO_Init(GPIO_PORT_E, GPIO_PIN_10, &stcGpioInit);
        GPIO_Init(GPIO_PORT_E, GPIO_PIN_13, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi0_cs4.gpio_periph, spi0_cs4.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi0_dev4, "spi0_dev4", "spi0", (void*)&spi0_cs4));
    }
#endif
    RT_TRY(wl32_spi_register((uint32_t)CM_SPI1, &wl32_spi1, "spi1"));

    /* attach spi_device_2 (MS5611 Barometer) to spi1 */
    {
        static struct rt_spi_device rt_spi1_dev2;
        static struct wl32_spi_cs spi1_cs2 = { .gpio_periph = GPIO_PORT_D, .pin = GPIO_PIN_12 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(GPIO_PORT_D, GPIO_PIN_12, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi1_cs2.gpio_periph, spi1_cs2.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi1_dev2, "spi1_dev0", "spi1", (void*)&spi1_cs2));
    }

    /* attach spi_device_3 (SPI1 CS1) to spi1 */
    {
        static struct rt_spi_device rt_spi1_dev3;
        static struct wl32_spi_cs spi1_cs3 = { .gpio_periph = GPIO_PORT_C, .pin = GPIO_PIN_07 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(GPIO_PORT_C, GPIO_PIN_07, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi1_cs3.gpio_periph, spi1_cs3.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi1_dev3, "spi1_dev3", "spi1", (void*)&spi1_cs3));
    }

    /* attach spi_device_4 (SPI1 CS2) to spi1 */
    {
        static struct rt_spi_device rt_spi1_dev4;
        static struct wl32_spi_cs spi1_cs4 = { .gpio_periph = GPIO_PORT_C, .pin = GPIO_PIN_08 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(GPIO_PORT_C, GPIO_PIN_08, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi1_cs4.gpio_periph, spi1_cs4.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi1_dev4, "spi1_dev4", "spi1", (void*)&spi1_cs4));
    }

    
    RT_TRY(wl32_spi_register((uint32_t)CM_SPI2, &wl32_spi2, "spi2"));
    /* attach spi_device_0 (SPI1 FRAM) to spi1 */
    {
        static struct rt_spi_device rt_spi2_dev0;
        static struct wl32_spi_cs spi2_cs0 = { .gpio_periph = GPIO_PORT_H, .pin = GPIO_PIN_12 };

        (void)GPIO_StructInit(&stcGpioInit);
        stcGpioInit.u16PinDir        = PIN_DIR_OUT;
        stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_CMOS;
        GPIO_Init(GPIO_PORT_H, GPIO_PIN_12, &stcGpioInit);
        
        /* set CS pin by default */
        GPIO_SetPins(spi2_cs0.gpio_periph, spi2_cs0.pin);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi2_dev0, "spi2_dev0", "spi2", (void*)&spi2_cs0));
    }

    return RT_EOK;
}
