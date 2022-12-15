#include <firmament.h>

#include "hal/mtd/mtd.h"
#include "hal/spi/spi.h"

#define SECTOR_SIZE 4096
#define PAGE_SIZE   256

#define W25QXX_CMD_PAGE_PROGRAM       0x02
#define W25QXX_CMD_PAGE_READ          0x03
#define W25QXX_CMD_WRITE_DISABLE      0x04
#define W25QXX_CMD_READ_STATUS1       0x05
#define W25QXX_CMD_WRITE_ENABLE       0x06
#define W25QXX_CMD_SECTOR_ERASE       0x20
#define W25QXX_CMD_READ_STATUS2       0x35
#define W25QXX_CMD_RELEASE_PWOER_DOWN 0xAB

#define LOAD_CMD(a, cmd, addr)              \
    do {                                    \
        (a)[0U] = (cmd);                    \
        (a)[1U] = (uint8_t)((addr) >> 16U); \
        (a)[2U] = (uint8_t)((addr) >> 8U);  \
        (a)[3U] = (uint8_t)(addr);          \
    } while (0U)

static rt_device_t mtd_spi_dev;

static rt_err_t probe(mtd_dev_t mtd_dev)
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

    /* manufacture id should be 0xEF */
    if (id[0] != 0xEF) {
        return RT_ERROR;
    }

    mtd_dev->blk_geometry.bytes_per_sector = SECTOR_SIZE;
    mtd_dev->blk_geometry.block_size = SECTOR_SIZE;

    switch (id[1]) {
    case 0x13:
        /* W25Q80 */
        mtd_dev->blk_geometry.sector_count = 1 * 1024 * 1024 / SECTOR_SIZE;
        break;
    case 0x14:
        /* W25Q16 */
        mtd_dev->blk_geometry.sector_count = 2 * 1024 * 1024 / SECTOR_SIZE;
        break;
    case 0x15:
        /* W25Q32 */
        mtd_dev->blk_geometry.sector_count = 4 * 1024 * 1024 / SECTOR_SIZE;
        break;
    case 0x16:
        /* W25Q64 */
        mtd_dev->blk_geometry.sector_count = 8 * 1024 * 1024 / SECTOR_SIZE;
        break;
    case 0x17:
        /* W25Q128 */
        mtd_dev->blk_geometry.sector_count = 16 * 1024 * 1024 / SECTOR_SIZE;
        break;
    case 0x18:
        /* W25Q256 */
        mtd_dev->blk_geometry.sector_count = 32 * 1024 * 1024 / SECTOR_SIZE;
        //TODO, 32-bit address
        printf("W25QXX driver dn not support 32-bit address yet\n");
        return RT_ENOSYS;
        break;
    case 0x19:
        /* W25Q512 */
        mtd_dev->blk_geometry.sector_count = 64 * 1024 * 1024 / SECTOR_SIZE;
        //TODO, 32-bit address
        printf("W25QXX driver dn not support 32-bit address yet\n");
        return RT_ENOSYS;
        break;
    }

    return RT_EOK;
}

static rt_err_t wait_no_busy(void)
{
    uint8_t status = 0;
    uint8_t cmd = W25QXX_CMD_READ_STATUS1;
    volatile uint32_t timeout_cnt = 100000UL;

    while (timeout_cnt-- != 0) {
        // status = rt_spi_sendrecv8((struct rt_spi_device*)mtd_spi_dev, W25QXX_CMD_READ_STATUS1);

        RT_TRY(rt_spi_send_then_recv((struct rt_spi_device*)mtd_spi_dev, &cmd, 1, &status, 1));
        if ((status & 0x01) == 0) {
            break;
        }
    }

    return RT_EOK;
}

static rt_err_t release_powerdown(void)
{
    struct rt_spi_message message1;
    uint8_t cmd = W25QXX_CMD_RELEASE_PWOER_DOWN;

    /* send op-code */
    message1.send_buf = &cmd;
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
    systime_udelay(100);

    return RT_EOK;
}

static rt_err_t write_disable(void)
{
    struct rt_spi_message message1;
    uint8_t cmd = W25QXX_CMD_WRITE_DISABLE;

    /* send op-code */
    message1.send_buf = &cmd;
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
    uint8_t cmd = W25QXX_CMD_WRITE_ENABLE;

    /* send op-code */
    message1.send_buf = &cmd;
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

static rt_err_t page_read(uint32_t addr, uint8_t* buffer, uint32_t len)
{
    uint8_t cmd[4];
    struct rt_spi_message message1, message2;

    LOAD_CMD(cmd, W25QXX_CMD_PAGE_READ, addr);

    /* send instruction */
    message1.send_buf = cmd;
    message1.recv_buf = RT_NULL;
    message1.length = sizeof(cmd);
    message1.cs_take = 1;
    message1.cs_release = 0;
    message1.next = &message2;
    /* read page data */
    message2.send_buf = RT_NULL;
    message2.recv_buf = buffer;
    message2.length = PAGE_SIZE;
    message2.cs_take = 0;
    message2.cs_release = 1;
    message2.next = RT_NULL;

    if (rt_spi_transfer_message((struct rt_spi_device*)mtd_spi_dev, &message1) != RT_NULL) {
        /* transfer failed */
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t page_write(uint32_t addr, const uint8_t* buffer, uint32_t len)
{
    rt_err_t res = RT_EOK;
    uint8_t cmd[4];
    struct rt_spi_message message1, message2;

    LOAD_CMD(cmd, W25QXX_CMD_PAGE_PROGRAM, addr);

    RT_TRY(wait_no_busy());
    RT_TRY(write_enable());

    /* send instruction */
    message1.send_buf = cmd;
    message1.recv_buf = RT_NULL;
    message1.length = sizeof(cmd);
    message1.cs_take = 1;
    message1.cs_release = 0;
    message1.next = &message2;
    /* write page data */
    message2.send_buf = buffer;
    message2.recv_buf = RT_NULL;
    message2.length = PAGE_SIZE;
    message2.cs_take = 0;
    message2.cs_release = 1;
    message2.next = RT_NULL;

    if (rt_spi_transfer_message((struct rt_spi_device*)mtd_spi_dev, &message1) != RT_NULL) {
        /* transfer failed */
        res = RT_ERROR;
    }
    RT_TRY(wait_no_busy());
    RT_TRY(write_disable());
    return res;
}

static rt_err_t sector_erase(uint32_t addr)
{
    uint8_t cmd[4];
    rt_size_t cnt;
    LOAD_CMD(cmd, W25QXX_CMD_SECTOR_ERASE, addr);

    RT_TRY(wait_no_busy());
    RT_TRY(write_enable());
    cnt = rt_spi_send((struct rt_spi_device*)mtd_spi_dev, cmd, 4);
    RT_TRY(wait_no_busy());
    RT_TRY(write_disable());

    return (cnt == 4) ? RT_EOK : RT_ERROR;
}

static rt_err_t w25qxx_read(mtd_dev_t mtd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    uint32_t addr = sector * SECTOR_SIZE;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < SECTOR_SIZE / PAGE_SIZE; j++) {
            RT_TRY(page_read(addr + i * SECTOR_SIZE + j * PAGE_SIZE, &buffer[i * SECTOR_SIZE + j * PAGE_SIZE], PAGE_SIZE));
        }
    }
    return RT_EOK;
}

static rt_err_t w25qxx_write(mtd_dev_t mtd, const rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    uint32_t addr = sector * SECTOR_SIZE;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < SECTOR_SIZE / PAGE_SIZE; j++) {
            RT_TRY(page_write(addr + i * SECTOR_SIZE + j * PAGE_SIZE, &buffer[i * SECTOR_SIZE + j * PAGE_SIZE], PAGE_SIZE));
        }
    }
    return RT_EOK;
}

static rt_err_t w25qxx_erase(mtd_dev_t mtd, rt_uint32_t sector, rt_uint32_t count)
{
    return sector_erase(sector * SECTOR_SIZE);
}

static rt_err_t w25qxx_control(mtd_dev_t mtd, int cmd, void* arg)
{
    switch (cmd) {
    case RT_DEVICE_CTRL_BLK_GETGEOME: {
        *(struct rt_device_blk_geometry*)arg = mtd->blk_geometry;
    } break;
    case RT_DEVICE_CTRL_BLK_SYNC: {
        RT_TRY(wait_no_busy());
    } break;
    case RT_DEVICE_CTRL_BLK_ERASE: {
        uint32_t* sectors = (uint32_t*)arg;
        uint32_t count = (sectors[1] - sectors[0]) > 0 ? (sectors[1] - sectors[0]) : 0;

        RT_TRY(w25qxx_erase(mtd, sectors[0], count));
    } break;
    default: {
        printf("unknown mtd control cmd:%d\n", cmd);
        return RT_EINVAL;
    } break;
    }

    return RT_EOK;
}

const static struct mtd_ops dev_ops = {
    .init = RT_NULL,
    .read = w25qxx_read,
    .write = w25qxx_write,
    .erase = w25qxx_erase,
    .control = w25qxx_control
};

rt_err_t drv_w25qxx_init(const char* spi_device_name, const char* mtd_device_name)
{
    static struct mtd_device w25qxx_dev;

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
    RT_TRY(probe(&w25qxx_dev));
    /* power-on the device and disable write by default */
    RT_TRY(release_powerdown());
    RT_TRY(write_disable());

    w25qxx_dev.ops = &dev_ops;
    return hal_mtd_register(&w25qxx_dev, mtd_device_name, RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE, RT_NULL);
}