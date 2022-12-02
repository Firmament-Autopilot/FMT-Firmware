#include <firmament.h>

#include "hal/mtd/mtd.h"
#include "hal/spi/spi.h"

#define W25QXX_CMD_PAGE_PROGRAM       0x02
#define W25QXX_CMD_WRITE_DISABLE      0x04
#define W25QXX_CMD_READ_STATUS1       0x05
#define W25QXX_CMD_READ_STATUS2       0x35
#define W25QXX_CMD_WRITE_ENABLE       0x06
#define W25QXX_CMD_RELEASE_PWOER_DOWN 0xAB

#define LOAD_CMD(a, cmd, addr)              \
    do {                                    \
        (a)[0U] = (cmd);                    \
        (a)[1U] = (uint8_t)((addr) >> 16U); \
        (a)[2U] = (uint8_t)((addr) >> 8U);  \
        (a)[3U] = (uint8_t)(addr);          \
    } while (0U)

static rt_device_t mtd_spi_dev;

static rt_err_t probe(void)
{
    struct rt_spi_message message1, message2, message3;

    uint8_t addr = 0x90;
    uint8_t id[2] = { 0 };
    uint8_t dummy[3] = { 0 };

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
    message3.recv_buf = id;
    message3.length = 2;
    message3.cs_take = 0;
    message3.cs_release = 1;
    message3.next = RT_NULL;

    if (rt_spi_transfer_message((struct rt_spi_device*)mtd_spi_dev, &message1) != RT_NULL) {
        /* transfer failed */
        return RT_ERROR;
    }

    printf("w25qxx man_id:%x dev_id:%x\n", id[0], id[1]);

    /* manufacture id should be 0xEF */
    if (id[0] != 0xEF) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static bool is_busy(void)
{
    uint8_t status;

    if (spi_read_reg8(mtd_spi_dev, W25QXX_CMD_READ_STATUS1, &status) != RT_EOK) {
        /* read fail */
        return true;
    }

    return (status & 0x01) ? true : false;
}

static rt_err_t release_powerdown(void)
{
    struct rt_spi_message message1;
    uint8_t addr = W25QXX_CMD_RELEASE_PWOER_DOWN;

    /* send op-code */
    message1.send_buf = &addr;
    message1.recv_buf = RT_NULL;
    message1.length = 1;
    message1.cs_take = 1;
    message1.cs_release = 1;
    message1.next = RT_NULL;

    if (rt_spi_transfer_message((struct rt_spi_device*)mtd_spi_dev, &message1) != RT_NULL) {
        /* transfer failed */
        return RT_ERROR;
    }

    /* wait for tRES1(3us) */
    systime_udelay(5);

    return RT_EOK;
}

static rt_err_t write_disable(void)
{
    struct rt_spi_message message1;
    uint8_t addr = W25QXX_CMD_WRITE_DISABLE;

    /* send op-code */
    message1.send_buf = &addr;
    message1.recv_buf = RT_NULL;
    message1.length = 1;
    message1.cs_take = 1;
    message1.cs_release = 1;
    message1.next = RT_NULL;

    if (rt_spi_transfer_message((struct rt_spi_device*)mtd_spi_dev, &message1) != RT_NULL) {
        /* transfer failed */
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t write_enable(void)
{
    struct rt_spi_message message1;
    uint8_t addr = W25QXX_CMD_WRITE_ENABLE;

    /* send op-code */
    message1.send_buf = &addr;
    message1.recv_buf = RT_NULL;
    message1.length = 1;
    message1.cs_take = 1;
    message1.cs_release = 1;
    message1.next = RT_NULL;

    if (rt_spi_transfer_message((struct rt_spi_device*)mtd_spi_dev, &message1) != RT_NULL) {
        /* transfer failed */
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t page_write(uint32_t addr, const uint8_t* buffer, uint32_t len)
{
    uint8_t cmd[4];
    rt_size_t cnt;
    LOAD_CMD(cmd, W25QXX_CMD_PAGE_PROGRAM, addr);

    RT_TRY(write_enable());
    cnt = rt_spi_send((struct rt_spi_device*)mtd_spi_dev, cmd, 4);
    cnt += rt_spi_send((struct rt_spi_device*)mtd_spi_dev, buffer, len);
    RT_TRY(write_disable());

    return (cnt == len + 4) ? RT_EOK : RT_ERROR;
}

rt_err_t drv_w25qxx_init(const char* spi_device_name, const char* mtd_device_name)
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
    /* probe the device */
    RT_TRY(probe());
    /* power-on the device and disable write by default */
    RT_TRY(release_powerdown());
    RT_TRY(write_disable());

    return RT_EOK;
}