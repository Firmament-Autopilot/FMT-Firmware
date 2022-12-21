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
#include "ar1002_hal.h"
#include "hal/spi/spi.h"

#define SPI0_CS1_Pin  HAL_GPIO_NUM70
#define SPI0_SCK_Pin  HAL_GPIO_NUM66
#define SPI0_MOSI_Pin HAL_GPIO_NUM62
#define SPI0_MISO_Pin HAL_GPIO_NUM58

#define SPI1_CS1_Pin  HAL_GPIO_NUM71
#define SPI1_SCK_Pin  HAL_GPIO_NUM67
#define SPI1_MOSI_Pin HAL_GPIO_NUM63
#define SPI1_MISO_Pin HAL_GPIO_NUM59

#define SPI2_CS1_Pin  HAL_GPIO_NUM72
#define SPI2_CS2_Pin  HAL_GPIO_NUM101
#define SPI2_CS3_Pin  HAL_GPIO_NUM102
#define SPI2_SCK_Pin  HAL_GPIO_NUM68
#define SPI2_MOSI_Pin HAL_GPIO_NUM64
#define SPI2_MISO_Pin HAL_GPIO_NUM60

#define SPI3_CS1_Pin  HAL_GPIO_NUM73
#define SPI3_CS2_Pin  HAL_GPIO_NUM100
#define SPI3_SCK_Pin  HAL_GPIO_NUM69
#define SPI3_MOSI_Pin HAL_GPIO_NUM65
#define SPI3_MISO_Pin HAL_GPIO_NUM61

#define SPI6_CS1_Pin  HAL_GPIO_NUM46
#define SPI6_SCK_Pin  HAL_GPIO_NUM47
#define SPI6_MOSI_Pin HAL_GPIO_NUM48
#define SPI6_MISO_Pin HAL_GPIO_NUM49

struct ar1002_spi_bus {
    struct rt_spi_bus parent;
    ENUM_SPI_COMPONENT SPI;
};

struct ar1002_spi_cs {
    ENUM_HAL_GPIO_NUM GPIO_Pin;
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

    struct ar1002_spi_bus* spi_bus = (struct ar1002_spi_bus*)device->bus;

    STRU_HAL_SPI_INIT st_spiInitInfo = {
        .u32_halSpiBaudr_Hz = 10 * 1000000,
        .e_halSpiPolarity = HAL_SPI_POLARITY_HIGH,
        .e_halSpiPhase = HAL_SPI_PHASE_2EDGE,
    };

    if (configuration->data_width > 8) {
        console_println("!!Error: config spi data width > 8, width=%d", configuration->data_width);
        return RT_EIO;
    }

    /* baudrate */
    {
        st_spiInitInfo.u32_halSpiBaudr_Hz = configuration->max_hz;
    } /* baudrate */

    /* CPOL */
    if (configuration->mode & RT_SPI_CPOL) {
        st_spiInitInfo.e_halSpiPolarity = HAL_SPI_POLARITY_HIGH;
        /* CPHA */
        if (configuration->mode & RT_SPI_CPHA) {
            st_spiInitInfo.e_halSpiPhase = HAL_SPI_PHASE_2EDGE;
        } else {
            st_spiInitInfo.e_halSpiPhase = HAL_SPI_PHASE_1EDGE;
        }
    } else {
        st_spiInitInfo.e_halSpiPolarity = HAL_SPI_POLARITY_LOW;
        /* CPHA */
        if (configuration->mode & RT_SPI_CPHA) {
            st_spiInitInfo.e_halSpiPhase = HAL_SPI_PHASE_2EDGE;
        } else {
            st_spiInitInfo.e_halSpiPhase = HAL_SPI_PHASE_1EDGE;
        }
    }

    /* MSB or LSB */

    // printf("SPI config, devName: %s, max_hz=%d, ", device->parent.parent.name, configuration->max_hz);

    /* configure SPI parameter */
    HAL_SPI_MasterInit(spi_bus->SPI, &st_spiInitInfo);

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
    struct ar1002_spi_bus* ar1002_spi_bus = (struct ar1002_spi_bus*)device->bus;
    ENUM_SPI_COMPONENT SPI = ar1002_spi_bus->SPI;
    struct rt_spi_configuration* config = &device->config;
    struct ar1002_spi_cs* ar1002_spi_cs = device->parent.user_data;

    HAL_RET_T ret = HAL_OK;

    if (config->data_width > 8) {
        console_println("-----------------SPI!!!! %D BIT---------------------", config->data_width);
    }

    /* take CS */
    if (message->cs_take) {
        HAL_GPIO_SetPin(ar1002_spi_cs->GPIO_Pin, HAL_GPIO_PIN_RESET);
    }

    if ((message->send_buf != NULL) && (message->recv_buf == NULL)) // write
    {
        // console_println("only write");
        ret = HAL_SPI_MasterWriteRead(SPI,
                                      (uint8_t*)message->send_buf,
                                      message->length,
                                      NULL,
                                      0,
                                      100);

        if (ret != HAL_OK) {
            console_println(" SPI WRITE FAILED!!!");
        }
    } else if ((message->send_buf == NULL) && (message->recv_buf != NULL)) // read
    {
        // console_println("only read");
        HAL_SPI_MasterWriteRead(SPI,
                                NULL,
                                0,
                                message->recv_buf,
                                message->length,
                                100);
        if (ret != HAL_OK) {
            console_println(" SPI READ FAILED!!!");
        }
    } else if ((message->send_buf != NULL) && (message->recv_buf != NULL)) // read
    {
        console_println("write & read");
        console_println(" SPI write & read FAILED!!!");
    } else {
        // console_println("(message->send_buf == NULL) && (message->recv_buf == NULL)");
    }
    /* release CS */
    if (message->cs_release) {
        HAL_GPIO_SetPin(ar1002_spi_cs->GPIO_Pin, HAL_GPIO_PIN_SET);
    }

    return message->length;
}

static struct rt_spi_ops ar1002_spi_ops = {
    configure,
    transfer
};

/** \brief init and register ar1002 spi bus.
 *
 * \param SPI: AR1002 SPI, e.g: SPI_1,SPI_2,SPI_3.
 * \param ar1002_spi: ar1002 spi bus struct.
 * \param spi_bus_name: spi bus name, e.g: "spi1"
 * \return rt_err_t RT_EOK for success
 */

static rt_err_t ar1002_spi_register(ENUM_SPI_COMPONENT SPI,
                                    struct ar1002_spi_bus* ar1002_spi,
                                    const char* spi_bus_name)
{
    if (SPI == SPI_1) {
        ar1002_spi->SPI = SPI_1;

        /* SPI1 configure */
        STRU_HAL_SPI_INIT st_spiInitInfo = {
            .u32_halSpiBaudr_Hz = 10 * 1000000, // 10MHz
            .e_halSpiPolarity = HAL_SPI_POLARITY_LOW,
            .e_halSpiPhase = HAL_SPI_PHASE_1EDGE,
        };

        HAL_SPI_MasterInit(SPI_1, &st_spiInitInfo);

    } else if (SPI == SPI_2) {
        ar1002_spi->SPI = SPI_2;

        /* SPI2 configure */
        STRU_HAL_SPI_INIT st_spiInitInfo = {
            .u32_halSpiBaudr_Hz = 10 * 1000000,
            .e_halSpiPolarity = HAL_SPI_POLARITY_HIGH,
            .e_halSpiPhase = HAL_SPI_PHASE_2EDGE,
        };

        HAL_SPI_MasterInit(SPI_2, &st_spiInitInfo);

    } else if (SPI == SPI_3) {
        ar1002_spi->SPI = SPI_3;

        /* SPI3 configure */
        STRU_HAL_SPI_INIT st_spiInitInfo = {
            .u32_halSpiBaudr_Hz = 9 * 1000000,
            .e_halSpiPolarity = HAL_SPI_POLARITY_HIGH,
            .e_halSpiPhase = HAL_SPI_PHASE_2EDGE,
        };

        HAL_SPI_MasterInit(SPI_3, &st_spiInitInfo);

    } else if (SPI == SPI_6) {

        ar1002_spi->SPI = SPI_6;

        /* SPI6 configure */
        STRU_HAL_SPI_INIT st_spiInitInfo = {
            .u32_halSpiBaudr_Hz = 9 * 1000000,
            .e_halSpiPolarity = HAL_SPI_POLARITY_HIGH,
            .e_halSpiPhase = HAL_SPI_PHASE_2EDGE,
        };

        HAL_SPI_MasterInit(SPI_6, &st_spiInitInfo);

    } else {
        return RT_ENOSYS;
    }
    return rt_spi_bus_register(&ar1002_spi->parent, spi_bus_name, &ar1002_spi_ops);
}

/**
 * @brief Initialize spi bus and device
 * 
 * @return rt_err_t RT_EOK for success
 */
rt_err_t drv_spi_init(void)
{

    /* init SPI gpio */
    // HAL_GPIO_SetMode(SPI0_CS1_Pin, HAL_GPIO_PIN_MODE0);

    HAL_GPIO_OutPut(SPI0_CS1_Pin);
    HAL_GPIO_SetPin(SPI0_CS1_Pin, HAL_GPIO_PIN_SET);
    HAL_GPIO_SetMode(SPI0_SCK_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI0_MOSI_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI0_MISO_Pin, HAL_GPIO_PIN_MODE0);

    HAL_GPIO_OutPut(SPI1_CS1_Pin);
    HAL_GPIO_SetPin(SPI1_CS1_Pin, HAL_GPIO_PIN_SET);
    HAL_GPIO_SetMode(SPI1_SCK_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI1_MOSI_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI1_MISO_Pin, HAL_GPIO_PIN_MODE0);

    HAL_GPIO_OutPut(SPI2_CS1_Pin);
    HAL_GPIO_SetPin(SPI2_CS1_Pin, HAL_GPIO_PIN_SET);
    HAL_GPIO_OutPut(SPI2_CS2_Pin);
    HAL_GPIO_SetPin(SPI2_CS2_Pin, HAL_GPIO_PIN_SET);
    HAL_GPIO_OutPut(SPI2_CS3_Pin);
    HAL_GPIO_SetPin(SPI2_CS3_Pin, HAL_GPIO_PIN_SET);
    HAL_GPIO_SetMode(SPI2_SCK_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI2_MOSI_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI2_MISO_Pin, HAL_GPIO_PIN_MODE0);

    HAL_GPIO_OutPut(SPI3_CS1_Pin);
    HAL_GPIO_SetPin(SPI3_CS1_Pin, HAL_GPIO_PIN_SET);
    HAL_GPIO_OutPut(SPI3_CS2_Pin);
    HAL_GPIO_SetPin(SPI3_CS2_Pin, HAL_GPIO_PIN_SET);
    HAL_GPIO_SetMode(SPI3_SCK_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI3_MOSI_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI3_MISO_Pin, HAL_GPIO_PIN_MODE0);

    HAL_GPIO_OutPut(SPI6_CS1_Pin);
    HAL_GPIO_SetPin(SPI6_CS1_Pin, HAL_GPIO_PIN_SET);
    HAL_GPIO_SetMode(SPI6_SCK_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI6_MOSI_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(SPI6_MISO_Pin, HAL_GPIO_PIN_MODE0);

    rt_err_t ret;

    /* register SPI bus */
    static struct ar1002_spi_bus ar1002_spi1;

    /* register SPI2 bus */
    ret = ar1002_spi_register(SPI_1, &ar1002_spi1, "spi1");
    if (ret != RT_EOK) {
        return ret;
    }

    /* attach spi1_device_1 to spi1 */
    {
        static struct rt_spi_device rt_spi1_device_1;
        static struct ar1002_spi_cs ar1002_spi1_cs_1;
        ar1002_spi1_cs_1.GPIO_Pin = SPI1_CS1_Pin;

        HAL_GPIO_OutPut(ar1002_spi1_cs_1.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi1_cs_1.GPIO_Pin, HAL_GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi1_device_1, "spi1_dev1", "spi1", (void*)&ar1002_spi1_cs_1);
        if (ret != RT_EOK) {
            return ret;
        }
    }

    /* register SPI bus */
    static struct ar1002_spi_bus ar1002_spi2;

    /* register SPI2 bus */
    ret = ar1002_spi_register(SPI_2, &ar1002_spi2, "spi2");
    if (ret != RT_EOK) {
        return ret;
    }

    /* attach spi_device_1 to spi2 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct ar1002_spi_cs ar1002_spi_cs_1;
        ar1002_spi_cs_1.GPIO_Pin = SPI2_CS1_Pin;

        HAL_GPIO_OutPut(ar1002_spi_cs_1.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi_cs_1.GPIO_Pin, HAL_GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_1, "spi2_dev1", "spi2", (void*)&ar1002_spi_cs_1);
        if (ret != RT_EOK) {
            return ret;
        }
    }

    /* attach spi_device_2 to spi2 */
    {
        static struct rt_spi_device rt_spi_device_2;
        static struct ar1002_spi_cs ar1002_spi_cs_2;
        ar1002_spi_cs_2.GPIO_Pin = SPI2_CS2_Pin;

        HAL_GPIO_OutPut(ar1002_spi_cs_2.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi_cs_2.GPIO_Pin, HAL_GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_2, "spi2_dev2", "spi2", (void*)&ar1002_spi_cs_2);
        if (ret != RT_EOK) {
            return ret;
        }
    }

    /* attach spi_device_3 to spi2 */
    {
        static struct rt_spi_device rt_spi_device_3;
        static struct ar1002_spi_cs ar1002_spi_cs_3;
        ar1002_spi_cs_3.GPIO_Pin = SPI2_CS3_Pin;

        HAL_GPIO_OutPut(ar1002_spi_cs_3.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi_cs_3.GPIO_Pin, HAL_GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_3, "spi2_dev3", "spi2", (void*)&ar1002_spi_cs_3);
        if (ret != RT_EOK) {
            return ret;
        }
    }

    /* register SPI bus */
    static struct ar1002_spi_bus ar1002_spi3;

    /* register SPI3 bus */
    ret = ar1002_spi_register(SPI_3, &ar1002_spi3, "spi3");
    if (ret != RT_EOK) {
        return ret;
    }

    /* attach spi_device_1 to spi3 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct ar1002_spi_cs ar1002_spi_cs_1;
        ar1002_spi_cs_1.GPIO_Pin = SPI3_CS1_Pin;

        HAL_GPIO_OutPut(ar1002_spi_cs_1.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi_cs_1.GPIO_Pin, HAL_GPIO_PIN_SET);
        ret = rt_spi_bus_attach_device(&rt_spi_device_1, "spi3_dev1", "spi3", (void*)&ar1002_spi_cs_1);
        if (ret != RT_EOK) {
            return ret;
        }
    }

    /* attach spi_device_2 to spi3 */
    {
        static struct rt_spi_device rt_spi_device_2;
        static struct ar1002_spi_cs ar1002_spi_cs_2;
        ar1002_spi_cs_2.GPIO_Pin = SPI3_CS2_Pin;

        HAL_GPIO_OutPut(ar1002_spi_cs_2.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi_cs_2.GPIO_Pin, HAL_GPIO_PIN_SET);
        ret = rt_spi_bus_attach_device(&rt_spi_device_2, "spi3_dev2", "spi3", (void*)&ar1002_spi_cs_2);
        if (ret != RT_EOK) {
            return ret;
        }
    }

    /* register SPI bus */
    static struct ar1002_spi_bus ar1002_spi6;

    /* register SPI6 bus */
    ret = ar1002_spi_register(SPI_6, &ar1002_spi6, "spi6");
    if (ret != RT_EOK) {
        return ret;
    }

    /* attach spi_device_1 to spi6 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct ar1002_spi_cs ar1002_spi_cs_1;
        ar1002_spi_cs_1.GPIO_Pin = SPI6_CS1_Pin;

        HAL_GPIO_OutPut(ar1002_spi_cs_1.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi_cs_1.GPIO_Pin, HAL_GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_1, "spi6_dev1", "spi6", (void*)&ar1002_spi_cs_1);
        if (ret != RT_EOK) {
            return ret;
        }
    }

    return RT_EOK;
}
