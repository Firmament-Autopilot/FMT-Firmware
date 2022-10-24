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
#include "ar1002_hal.h"

#define SPI0_CS1_Pin       HAL_GPIO_NUM70
#define SPI2_CS1_Pin       HAL_GPIO_NUM72

#define SPI5_CS1_Pin       HAL_GPIO_NUM50


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
    // TODO
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

    if(config->data_width > 8) 
    {
        console_println("-----------------SPI!!!! %D BIT---------------------",config->data_width);
    }


    /* take CS */
    if (message->cs_take) {
        HAL_GPIO_SetPin(ar1002_spi_cs->GPIO_Pin, HAL_GPIO_PIN_RESET);
    }

    if((message->send_buf != NULL) && (message->recv_buf == NULL))  // write 
    {
        // console_println("only write");
        ret = HAL_SPI_MasterWriteRead(SPI, 
                (uint8_t *)message->send_buf,
                message->length,
                NULL,
                0,
                100);

        if(ret != HAL_OK)
        {
            console_println(" SPI WRITE FAILED!!!");
        }
    }
    else if((message->send_buf == NULL) && (message->recv_buf != NULL))  // read 
    {
        // console_println("only read");
        HAL_SPI_MasterWriteRead(SPI, 
                NULL,
                0,
                message->recv_buf,
                message->length,
                100);
        if(ret != HAL_OK)
        {
            console_println(" SPI READ FAILED!!!");
        }
    }
    else if((message->send_buf != NULL) && (message->recv_buf != NULL))  // read 
    {
        console_println("write & read");
        console_println(" SPI write & read FAILED!!!");
    }
    else
    {
        console_println("(message->send_buf == NULL) && (message->recv_buf == NULL)");    
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
    if (SPI == SPI_0) {
        ar1002_spi->SPI = SPI_0;

        /* SPI2 configure */
    	STRU_HAL_SPI_INIT st_spiInitInfo = {
    		.u16_halSpiBaudr = 9,
    		.e_halSpiPolarity = HAL_SPI_POLARITY_HIGH,
    		.e_halSpiPhase = HAL_SPI_PHASE_2EDGE,
    	};

    	HAL_SPI_MasterInit(SPI_0, &st_spiInitInfo);

    } else if (SPI == SPI_2) {
        ar1002_spi->SPI = SPI_2;

        /* SPI2 configure */
    	STRU_HAL_SPI_INIT st_spiInitInfo = {
    		.u16_halSpiBaudr = 9,
    		.e_halSpiPolarity = HAL_SPI_POLARITY_HIGH,
    		.e_halSpiPhase = HAL_SPI_PHASE_2EDGE,
    	};

    	HAL_SPI_MasterInit(SPI_2, &st_spiInitInfo);

    } else if (SPI == SPI_5) {

        ar1002_spi->SPI = SPI_5;

        /* SPI2 configure */
    	STRU_HAL_SPI_INIT st_spiInitInfo = {
    		.u16_halSpiBaudr = 9,
    		.e_halSpiPolarity = HAL_SPI_POLARITY_HIGH,
    		.e_halSpiPhase = HAL_SPI_PHASE_2EDGE,
    	};

    	HAL_SPI_MasterInit(SPI_5, &st_spiInitInfo);

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
    rt_err_t ret;


    /* register SPI bus */
    static struct ar1002_spi_bus ar1002_spi0;

    /* register SPI0 bus */
    ret = ar1002_spi_register(SPI_0, &ar1002_spi0, "spi0");
    if (ret != RT_EOK) {
        return ret;
    }

    /* attach spi_device_1 to spi0 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct ar1002_spi_cs ar1002_spi_cs_1;
        ar1002_spi_cs_1.GPIO_Pin = SPI0_CS1_Pin;

        HAL_GPIO_OutPut(ar1002_spi_cs_1.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi_cs_1.GPIO_Pin, HAL_GPIO_PIN_SET);
        ret = rt_spi_bus_attach_device(&rt_spi_device_1, "spi0_dev1", "spi0", (void*)&ar1002_spi_cs_1);
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

    /* register SPI bus */
    static struct ar1002_spi_bus ar1002_spi5;

    /* register SPI5 bus */
    ret = ar1002_spi_register(SPI_5, &ar1002_spi5, "spi5");
    if (ret != RT_EOK) {
        return ret;
    }

    /* attach spi_device_1 to spi5 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct ar1002_spi_cs ar1002_spi_cs_1;
        ar1002_spi_cs_1.GPIO_Pin = SPI5_CS1_Pin;

        HAL_GPIO_OutPut(ar1002_spi_cs_1.GPIO_Pin);
        HAL_GPIO_SetPin(ar1002_spi_cs_1.GPIO_Pin, HAL_GPIO_PIN_SET);
        
        ret = rt_spi_bus_attach_device(&rt_spi_device_1, "spi5_dev1", "spi5", (void*)&ar1002_spi_cs_1);
        if (ret != RT_EOK) {
            return ret;
        }
    }


    return RT_EOK;
}
