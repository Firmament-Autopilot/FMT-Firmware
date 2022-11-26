#ifndef _DRIVER_MODULE_INIT
#define _DRIVER_MODULE_INIT
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    uint32_t uart;
    uint32_t spi;
    uint32_t can;
    uint32_t i2c;
    uint32_t timer;
    uint32_t nor_flash;
}DRIVER_INIT_DATA;

typedef enum _emu_driver_init
{
    INITED_UART = 0,
    INITED_SPI,
    INITED_CAN,
    INITED_I2C,
    INITED_TIMER,
    INITED_NOR_FLASH
}emu_driver_init;

void COMMON_driverInitSet(emu_driver_init e_driver, uint32_t u32_channel);
int8_t COMMON_driverInitGet(emu_driver_init e_driver, uint32_t u32_channel);

#ifdef __cplusplus
}
#endif
#endif
