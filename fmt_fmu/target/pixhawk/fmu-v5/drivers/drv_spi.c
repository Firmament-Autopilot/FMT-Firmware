#include "drv_spi.h"
#include "driver/spi_drv.h"
#include "stm32f7xx_ll_spi.h"
#include "hal/spi.h"

static rt_err_t configure(struct rt_spi_device* device,
                          struct rt_spi_configuration* configuration)
{
    struct stm32_spi_bus* stm32_spi_bus = (struct stm32_spi_bus*)device->bus;

    LL_SPI_InitTypeDef SPI_InitStruct = {0};
    LL_SPI_StructInit(&SPI_InitStruct);

    LL_RCC_ClocksTypeDef rcc_clocks;
    LL_RCC_GetSystemClocksFreq(&rcc_clocks);

    if(configuration->data_width <= 8) {
		SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	} else if(configuration->data_width <= 16) {
		SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_16BIT;
	} else {
		return RT_EIO;
	}

    /* baudrate */
	{
		uint32_t stm32_spi_max_clock;
		uint32_t max_hz;
		uint32_t PCLK2 = rcc_clocks.PCLK2_Frequency;

		//stm32f4xx SPI max_clock=PCLK2/2;
		stm32_spi_max_clock = PCLK2 / 2;
		max_hz = configuration->max_hz;

		if(max_hz > stm32_spi_max_clock) {
			max_hz = stm32_spi_max_clock;
		}

		if(max_hz >= PCLK2 / 2) {
			SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
		} else if(max_hz >= PCLK2 / 4) {
			SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV4;
		} else if(max_hz >= PCLK2 / 8) {
			SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV8;
		} else if(max_hz >= PCLK2 / 16) {
			SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV16;
		} else if(max_hz >= PCLK2 / 32) {
			SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV32;
		} else if(max_hz >= PCLK2 / 64) {
			SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV64;
		} else if(max_hz >= PCLK2 / 128) {
			SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV128;
		} else {
			/*  min prescaler 256 */
			SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV256;
		}
	} /* baudrate */

    /* CPOL */
	if(configuration->mode & RT_SPI_CPOL) {
		SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_HIGH;
	} else {
		SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
	}

	/* CPHA */
	if(configuration->mode & RT_SPI_CPHA) {
		SPI_InitStruct.ClockPhase = LL_SPI_PHASE_2EDGE;
	} else {
		SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
	}

	/* MSB or LSB */
	if(configuration->mode & RT_SPI_MSB) {
		SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
	} else {
		SPI_InitStruct.BitOrder = LL_SPI_LSB_FIRST;
	}

    SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
    SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
    SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
    SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
    SPI_InitStruct.CRCPoly = 7;

    LL_SPI_DeInit(stm32_spi_bus->SPI);
    LL_SPI_Init(stm32_spi_bus->SPI, &SPI_InitStruct);
    LL_SPI_SetStandard(stm32_spi_bus->SPI, LL_SPI_PROTOCOL_MOTOROLA);
    LL_SPI_DisableNSSPulseMgt(stm32_spi_bus->SPI);
    LL_SPI_Enable(stm32_spi_bus->SPI);

    return RT_EOK;
}

static rt_uint32_t xfer(struct rt_spi_device* device, struct rt_spi_message* message)
{
    struct stm32_spi_bus* stm32_spi_bus = (struct stm32_spi_bus*)device->bus;
	struct rt_spi_configuration* config = &device->config;
	SPI_TypeDef* SPI = stm32_spi_bus->SPI;
	struct stm32_spi_cs* stm32_spi_cs = device->parent.user_data;
	rt_uint32_t size = message->length;

    /* take CS */
	if(message->cs_take) {
		LL_GPIO_ResetOutputPin(stm32_spi_cs->GPIOx, stm32_spi_cs->GPIO_Pin);
	}

    #ifdef SPI_USE_DMA

    #endif
    
    {
        if(config->data_width <= 8) {
			const rt_uint8_t* send_ptr = message->send_buf;
			rt_uint8_t* recv_ptr = message->recv_buf;

			while(size--) {
				rt_uint8_t data = 0xFF;

				if(send_ptr != RT_NULL) {
					data = *send_ptr++;
				}

                //Wait until the transmit buffer is empty
				while(LL_SPI_IsActiveFlag_TXE(SPI) == RESET);

				// Send the byte
				LL_SPI_TransmitData8(SPI, data);

				//Wait until a data is received
				while(LL_SPI_IsActiveFlag_RXNE(SPI) == RESET);

				// Get the received data
				data = LL_SPI_ReceiveData8(SPI);

				if(recv_ptr != RT_NULL) {
					*recv_ptr++ = data;
				}
            }
        }else if(config->data_width <= 16) {
			const rt_uint16_t* send_ptr = message->send_buf;
			rt_uint16_t* recv_ptr = message->recv_buf;

			while(size--) {
				rt_uint16_t data = 0xFF;

				if(send_ptr != RT_NULL) {
					data = *send_ptr++;
				}

				//Wait until the transmit buffer is empty
				while(LL_SPI_IsActiveFlag_TXE(SPI) == RESET);

				// Send the byte
				LL_SPI_TransmitData16(SPI, data);

				//Wait until a data is received
				while(LL_SPI_IsActiveFlag_RXNE(SPI) == RESET);

				// Get the received data
				data = LL_SPI_ReceiveData16(SPI);

				if(recv_ptr != RT_NULL) {
					*recv_ptr++ = data;
				}
			}
        }
    }

    /* release CS */
	if(message->cs_release) {
		LL_GPIO_SetOutputPin(stm32_spi_cs->GPIOx, stm32_spi_cs->GPIO_Pin);
	}

    return message->length;
}


static struct rt_spi_ops stm32_spi_ops = {
	configure,
	xfer
};

/** \brief init and register stm32 spi bus.
 *
 * \param SPI: STM32 SPI, e.g: SPI1,SPI2,SPI3.
 * \param stm32_spi: stm32 spi bus struct.
 * \param spi_bus_name: spi bus name, e.g: "spi1"
 * \return
 *
 */
static rt_err_t stm32_spi_register(SPI_TypeDef* SPI,
                                   struct stm32_spi_bus* stm32_spi,
                                   const char* spi_bus_name)
{
    if(SPI == SPI1) {
         stm32_spi->SPI = SPI1;   

        /* Peripheral clock enable */
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

    #ifdef SPI_USE_DMA


    #endif


    }else if(SPI == SPI2) {
		stm32_spi->SPI = SPI2;

		/* Peripheral clock enable */
		LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);

    #ifdef SPI_USE_DMA


    #endif
	}else if(SPI == SPI4) {
		stm32_spi->SPI = SPI4;

		/* Peripheral clock enable */
		LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI4);

    }else {
		return RT_ENOSYS;
	}
    return rt_spi_bus_register(&stm32_spi->parent, spi_bus_name, &stm32_spi_ops);

}

rt_err_t spi_drv_init(void)
{
	rt_err_t ret = RT_EOK;

    /* register SPI bus */
	static struct stm32_spi_bus stm32_spi1;
	static struct stm32_spi_bus stm32_spi2;
	static struct stm32_spi_bus stm32_spi4;

    /* SPI1 configure */
	{
        LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
        /**SPI1 GPIO Configuration
        PD7   ------> SPI1_MOSI
        PG11   ------> SPI1_SCK
        PA6   ------> SPI1_MISO
        */
        
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;

        GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
        LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
        LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
        LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    } /* SPI1 configuration */

    /* register SPI1 bus */
	ret |= stm32_spi_register(SPI1, &stm32_spi1, "spi1");

	/* attach spi_device_1 to spi1 */
	{
        static struct rt_spi_device rt_spi_device_1;
		static struct stm32_spi_cs  stm32_spi_cs_1;

        stm32_spi_cs_1.GPIOx = SPI1_CS1_GPIO_Port;
		stm32_spi_cs_1.GPIO_Pin = SPI1_CS1_Pin;

        LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);

        /**/
        GPIO_InitStruct.Pin = SPI1_CS1_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(SPI1_CS1_GPIO_Port, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(SPI1_CS1_GPIO_Port, SPI1_CS1_Pin);

        ret |= rt_spi_bus_attach_device(&rt_spi_device_1, "spi1_dev1", "spi1", (void*)&stm32_spi_cs_1);
    }    
		/* attach spi_device_2 to spi1 */
	{
		static struct rt_spi_device rt_spi_device_2;
		static struct stm32_spi_cs  stm32_spi_cs_2;

		stm32_spi_cs_2.GPIOx = SPI1_CS2_GPIO_Port;
		stm32_spi_cs_2.GPIO_Pin = SPI1_CS2_Pin;

		LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);

        /**/
        GPIO_InitStruct.Pin = SPI1_CS2_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(SPI1_CS2_GPIO_Port, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(SPI1_CS2_GPIO_Port, SPI1_CS2_Pin);

		ret |= rt_spi_bus_attach_device(&rt_spi_device_2, "spi1_dev2", "spi1", (void*)&stm32_spi_cs_2);
	} 

	/* attach spi_device_3 to spi1 */
	{
		static struct rt_spi_device rt_spi_device_3;
		static struct stm32_spi_cs  stm32_spi_cs_3;

		stm32_spi_cs_3.GPIOx = SPI1_CS3_GPIO_Port;
		stm32_spi_cs_3.GPIO_Pin = SPI1_CS3_Pin;

		LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);

        /**/
        GPIO_InitStruct.Pin = SPI1_CS3_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(SPI1_CS3_GPIO_Port, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(SPI1_CS3_GPIO_Port, SPI1_CS3_Pin);

		ret |= rt_spi_bus_attach_device(&rt_spi_device_3, "spi1_dev3", "spi1", (void*)&stm32_spi_cs_3);
	}

	/* attach spi_device_4 to spi1 */
	{
		static struct rt_spi_device rt_spi_device_4;
		static struct stm32_spi_cs  stm32_spi_cs_4;

		stm32_spi_cs_4.GPIOx = SPI1_CS4_GPIO_Port;
		stm32_spi_cs_4.GPIO_Pin = SPI1_CS4_Pin;

		LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
		LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);

        /**/
        GPIO_InitStruct.Pin = SPI1_CS4_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(SPI1_CS4_GPIO_Port, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(SPI1_CS4_GPIO_Port, SPI1_CS4_Pin);


		ret |= rt_spi_bus_attach_device(&rt_spi_device_4, "spi1_dev4", "spi1", (void*)&stm32_spi_cs_4);
	}

	/* attach spi_device_5 to spi1 */
	{
		static struct rt_spi_device rt_spi_device_5;
		static struct stm32_spi_cs  stm32_spi_cs_5;

		stm32_spi_cs_5.GPIOx = SPI1_CS5_GPIO_Port;
		stm32_spi_cs_5.GPIO_Pin = SPI1_CS5_Pin;

		LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
		LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);

        /**/
        GPIO_InitStruct.Pin = SPI1_CS5_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(SPI1_CS5_GPIO_Port, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(SPI1_CS5_GPIO_Port, SPI1_CS5_Pin);


		ret |= rt_spi_bus_attach_device(&rt_spi_device_5, "spi1_dev5", "spi1", (void*)&stm32_spi_cs_5);
	}

	/* SPI2 configure */
	{
		LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

		/* Peripheral clock enable */
		LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);

		LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOI);
		/**SPI2 GPIO Configuration
		PI3   ------> SPI2_MOSI
		PI2   ------> SPI2_MISO
		PI1   ------> SPI2_SCK
		*/
		
		GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
		GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
		GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
		GPIO_InitStruct.Alternate = LL_GPIO_AF_5;

		GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
		LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
		LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
		LL_GPIO_Init(GPIOI, &GPIO_InitStruct);
	}

	/* register SPI2 bus */
	ret |= stm32_spi_register(SPI2, &stm32_spi2, "spi2");

	/* attach spi_device_1 to spi2 */
	{
        static struct rt_spi_device rt_spi_device_1;
		static struct stm32_spi_cs  stm32_spi_cs_1;

        stm32_spi_cs_1.GPIOx = SPI2_CS1_GPIO_Port;
		stm32_spi_cs_1.GPIO_Pin = SPI2_CS1_Pin;

        LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);

        /**/
        GPIO_InitStruct.Pin = SPI1_CS1_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(SPI1_CS1_GPIO_Port, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(SPI1_CS1_GPIO_Port, SPI1_CS1_Pin);

        ret |= rt_spi_bus_attach_device(&rt_spi_device_1, "spi2_dev1", "spi2", (void*)&stm32_spi_cs_1);
    } 

	/* SPI4 configure */
	{
        LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

		/* Peripheral clock enable */
		LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI4);

		LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
		/**SPI4 GPIO Configuration
		 PE2   ------> SPI4_SCK
		PE6   ------> SPI4_MOSI
		PE13   ------> SPI4_MISO
		*/
		
		GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
		GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
		GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
		GPIO_InitStruct.Alternate = LL_GPIO_AF_5;

		GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
		LL_GPIO_Init(GPIOE, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
		LL_GPIO_Init(GPIOE, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
		LL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    } /* SPI4 configuration */

    /* register SPI4 bus */
	ret |= stm32_spi_register(SPI4, &stm32_spi4, "spi4");

	/* attach spi_device_1 to spi4 */
	{
        static struct rt_spi_device rt_spi_device_1;
		static struct stm32_spi_cs  stm32_spi_cs_1;

        stm32_spi_cs_1.GPIOx = SPI4_CS1_GPIO_Port;
		stm32_spi_cs_1.GPIO_Pin = SPI4_CS1_Pin;

        LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);

        /**/
        GPIO_InitStruct.Pin = SPI4_CS1_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(SPI4_CS1_GPIO_Port, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(SPI4_CS1_GPIO_Port, SPI4_CS1_Pin);

        ret |= rt_spi_bus_attach_device(&rt_spi_device_1, "spi4_dev1", "spi4", (void*)&stm32_spi_cs_1);
    }    
		/* attach spi_device_2 to spi4 */
	{
		static struct rt_spi_device rt_spi_device_2;
		static struct stm32_spi_cs  stm32_spi_cs_2;

		stm32_spi_cs_2.GPIOx = SPI4_CS2_GPIO_Port;
		stm32_spi_cs_2.GPIO_Pin = SPI4_CS2_Pin;

		LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
        LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);

        /**/
        GPIO_InitStruct.Pin = SPI4_CS2_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(SPI4_CS2_GPIO_Port, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(SPI4_CS2_GPIO_Port, SPI4_CS2_Pin);

		ret |= rt_spi_bus_attach_device(&rt_spi_device_2, "spi4_dev2", "spi4", (void*)&stm32_spi_cs_2);
	} 

	return ret;
}

