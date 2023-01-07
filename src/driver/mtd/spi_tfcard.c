#include <firmament.h>

#include "hal/spi/spi.h"
#include "hal/spi_msd/spi_msd.h"

static rt_device_t tfcard_spi_dev;

rt_err_t drv_spi_tfcard_init(const char* spi_device_name, const char* tfcard_device_name)
{
    tfcard_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(tfcard_spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_0 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 10 * 1000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)tfcard_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* init spi bus */
    RT_TRY(rt_device_open(tfcard_spi_dev, RT_DEVICE_OFLAG_RDWR));

    return hal_spi_msd_register(tfcard_device_name, spi_device_name);
}
