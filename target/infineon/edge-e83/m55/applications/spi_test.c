#include "hal/pin/pin.h"
#include "hal/spi/spi.h"
#include <firmament.h>

#define GET_PIN(PORTx, PIN) ((((uint8_t)(PORTx)) << 3U) + ((uint8_t)(PIN)))
char rx_buf[4] = { 0 };
static struct rt_spi_device spi1_dev;

void drv_spi_device_attach(void)
{
    rt_spi_bus_attach_device(&spi1_dev, "spi1_dev", "spi1", (void*)GET_PIN(16, 3));
}

static void spi_test_sample(void)
{
    struct rt_spi_device* spi_dev;
    const char tx_buf[] = "abc";
    drv_spi_device_attach();
    spi_dev = (struct rt_spi_device*)rt_device_find("spi1_dev");
    if (!spi_dev) {
        rt_kprintf("spi device not found!\n");
        return;
    }

    struct rt_spi_configuration spi_cfg;
    spi_cfg.data_width = 8;
    spi_cfg.max_hz = 10000000; // 10 MHz
    spi_cfg.mode = RT_SPI_MODE_0;
    rt_spi_configure(spi_dev, &spi_cfg);
    rt_spi_transfer(spi_dev, tx_buf, rx_buf, 3);
    rt_kprintf("send: %s, recv: %s\n", tx_buf, rx_buf);
}

MSH_CMD_EXPORT(spi_test_sample, SPI send abc and receive test);
