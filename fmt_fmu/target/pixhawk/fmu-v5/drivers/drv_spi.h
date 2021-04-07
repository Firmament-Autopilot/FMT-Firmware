#ifndef __DRV_SPI_H__
#define __DRV_SPI_H__

#include <firmament.h>
#include "bsp.h"


#ifdef __cplusplus
extern "C" {
#endif


#define SPI1_CS1_Pin LL_GPIO_PIN_2
#define SPI1_CS1_GPIO_Port GPIOF

#define SPI1_CS2_Pin LL_GPIO_PIN_3
#define SPI1_CS2_GPIO_Port GPIOF

#define SPI1_CS3_Pin LL_GPIO_PIN_4
#define SPI1_CS3_GPIO_Port GPIOF

#define SPI1_CS4_Pin LL_GPIO_PIN_10
#define SPI1_CS4_GPIO_Port GPIOG

#define SPI1_CS5_Pin LL_GPIO_PIN_5
#define SPI1_CS5_GPIO_Port GPIOH

#define SPI2_CS1_Pin LL_GPIO_PIN_5
#define SPI2_CS1_GPIO_Port GPIOF

#define SPI4_CS1_Pin LL_GPIO_PIN_10
#define SPI4_CS1_GPIO_Port GPIOF

#define SPI4_CS2_Pin LL_GPIO_PIN_11
#define SPI4_CS2_GPIO_Port GPIOF

rt_err_t spi_drv_init(void);
void MX_GPIO_Init(void);


void MX_SPI1_Init(void);
#ifdef __cplusplus
}
#endif

#endif