#include <firmament.h>

#include "hal/mtd/mtd.h"
#include "hal/spi/spi.h"

static rt_device_t mtd_spi_dev;

static void test(void)
{
    struct rt_spi_message message1, message2, message3;

    uint8_t addr = 0xAB;
    uint8_t id;
    uint8_t dummy[3] = { 0xFF };

    /* send op-code */
    message1.send_buf = &addr;
    message1.recv_buf = RT_NULL;
    message1.length = 1;
    message1.cs_take = 1;
    message1.cs_release = 0;
    message1.next = &message2;
    /* send address */
    message2.send_buf = dummy;
    message2.recv_buf = RT_NULL;
    message2.length = 3;
    message2.cs_take = 0;
    message2.cs_release = 0;
    message2.next = &message3;
    /* read data */
    message3.send_buf = RT_NULL;
    message3.recv_buf = &id;
    message3.length = 1;
    message3.cs_take = 0;
    message3.cs_release = 1;
    message3.next = RT_NULL;

    if (rt_spi_transfer_message((struct rt_spi_device*)mtd_spi_dev, &message1) != RT_EOK) {
        return;
    }

    printf("id:%x\n", id);
}

rt_err_t drv_w25q16_init(const char* spi_device_name, const char* mtd_device_name)
{
    mtd_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(mtd_spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)mtd_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* init spi bus */
    RT_TRY(rt_device_open(mtd_spi_dev, RT_DEVICE_OFLAG_RDWR));

    test();

    return RT_EOK;
}