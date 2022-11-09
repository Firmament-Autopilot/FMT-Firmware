#include <firmament.h>

#include "hal/mtd/mtd.h"
#include "hal/spi/spi.h"

#define RAMTRON_WREN  0x06 /* Write Enable */
#define RAMTRON_WRDI  0x04 /* Write Disable */
#define RAMTRON_RDSR  0x05 /* Read Status Register */
#define RAMTRON_WRSR  0x01 /* Write Status Register */
#define RAMTRON_READ  0x03 /* Read Data Bytes */
#define RAMTRON_FSTRD 0x0b /* Fast Read Memory Data */
#define RAMTRON_WRITE 0x02 /* Write */
#define RAMTRON_SLEEP 0xb9 /* Enter Sleep Mode */
#define RAMTRON_RDID  0x9f /* Read Device ID */
#define RAMTRON_SN    0xc3 /* Read S/N */

/* Status register bit definitions */
#define RAMTRON_SR_WIP          (1 << 0) /* Bit 0: Write in progress bit */
#define RAMTRON_SR_WEL          (1 << 1) /* Bit 1: Write enable latch bit */
#define RAMTRON_SR_BP_SHIFT     (2)      /* Bits 2-4: Block protect bits */
#define RAMTRON_SR_BP_MASK      (7 << RAMTRON_SR_BP_SHIFT)
#define RAMTRON_SR_BP_NONE      (0 << RAMTRON_SR_BP_SHIFT) /* Unprotected */
#define RAMTRON_SR_BP_UPPER64th (1 << RAMTRON_SR_BP_SHIFT) /* Upper 64th */
#define RAMTRON_SR_BP_UPPER32nd (2 << RAMTRON_SR_BP_SHIFT) /* Upper 32nd */
#define RAMTRON_SR_BP_UPPER16th (3 << RAMTRON_SR_BP_SHIFT) /* Upper 16th */
#define RAMTRON_SR_BP_UPPER8th  (4 << RAMTRON_SR_BP_SHIFT) /* Upper 8th */
#define RAMTRON_SR_BP_UPPERQTR  (5 << RAMTRON_SR_BP_SHIFT) /* Upper quarter */
#define RAMTRON_SR_BP_UPPERHALF (6 << RAMTRON_SR_BP_SHIFT) /* Upper half */
#define RAMTRON_SR_BP_ALL       (7 << RAMTRON_SR_BP_SHIFT) /* All sectors */
#define RAMTRON_SR_SRWD         (1 << 7)                   /* Bit 7: Status register write protect */

static rt_device_t ramtron_spi_dev;
static struct mtd_device ramtron_dev;
static struct rt_device_blk_geometry geometry;

static void ramtron_wren(void)
{
    uint8_t code = RAMTRON_WREN;

    rt_spi_send((struct rt_spi_device*)ramtron_spi_dev, &code, 1);
}

static int ramtron_wait_writecplt(void)
{
    uint8_t sr;
    int retries = 100;

    do {
        sr = rt_spi_sendrecv8((struct rt_spi_device*)ramtron_spi_dev, RAMTRON_RDSR);
    } while ((sr & RAMTRON_SR_WIP) != 0 && retries-- > 0);

    return retries;
}

static rt_err_t ramtron_read_devinfo(void)
{
    uint8_t id[9];
    uint8_t density;
    rt_size_t bulk_size;

    RT_TRY(spi_read_multi_reg8(ramtron_spi_dev, RAMTRON_RDID, id, 9));

    /* JEDEC assigned Ramtron C2h in bank 7 */
    if (id[6] != 0xC2) {
        printf("INVALID ramtron ID!\n");
        printf("id[6] = %02x \n", id[6]);
        return RT_EINVAL;
    }

    density = id[7] & 0x1F;

    switch (density) {
    case 0x01:
        /* 128 kilobits */
        bulk_size = 128 * 1024 / 8;
        break;
    case 0x02:
        /* 256 kilobits */
        bulk_size = 256 * 1024 / 8;
        break;
    case 0x03:
        /* 512 kilobits */
        bulk_size = 512 * 1024 / 8;
        break;
    case 0x04:
        /* 1024 kilobits */
        bulk_size = 1024 * 1024 / 8;
        break;
    case 0x05:
        /* 2048 kilobits */
        bulk_size = 2048 * 1024 / 8;
        break;
    default:
        /* unknown density */
        return RT_EINVAL;
    }

    /* fram can be read/write in byte, howeber, the minimum
     * supported sector size for fatfs is 512*/
    geometry.bytes_per_sector = 512;
    geometry.block_size = geometry.bytes_per_sector;
    geometry.sector_count = bulk_size / geometry.bytes_per_sector;

    return RT_EOK;
}

rt_err_t ramtron_read(mtd_dev_t mtd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    uint8_t code = RAMTRON_READ;
    uint32_t addr = sector * geometry.bytes_per_sector;
    struct rt_spi_message message1, message2, message3;

    uint8_t addr_length = (geometry.sector_count < 512) ? 2 : 3;

    /* send MSB first */
    Msb2Lsb((uint8_t*)&addr, addr_length);

    /* send op-code */
    message1.send_buf = &code;
    message1.recv_buf = RT_NULL;
    message1.length = 1;
    message1.cs_take = 1;
    message1.cs_release = 0;
    message1.next = &message2;
    /* send address */
    message2.send_buf = &addr;
    message2.recv_buf = RT_NULL;
    message2.length = addr_length;
    message2.cs_take = 0;
    message2.cs_release = 0;
    message2.next = &message3;
    /* read data */
    message3.send_buf = RT_NULL;
    message3.recv_buf = buffer;
    message3.length = count * geometry.bytes_per_sector;
    message3.cs_take = 0;
    message3.cs_release = 1;
    message3.next = RT_NULL;

    rt_spi_transfer_message((struct rt_spi_device*)ramtron_spi_dev, &message1);

    return RT_EOK;
}

rt_err_t ramtron_write(mtd_dev_t mtd, const rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    uint8_t code = RAMTRON_WRITE;
    uint32_t addr = sector * geometry.bytes_per_sector;
    struct rt_spi_message message1, message2, message3;

    uint8_t addr_length = (geometry.sector_count < 512) ? 2 : 3;

    /* send MSB first */

    Msb2Lsb((uint8_t*)&addr, addr_length);

    /* write enable */
    ramtron_wren();

    /* send op-code */
    message1.send_buf = &code;
    message1.recv_buf = RT_NULL;
    message1.length = 1;
    message1.cs_take = 1;
    message1.cs_release = 0;
    message1.next = &message2;
    /* send address */
    message2.send_buf = &addr;
    message2.recv_buf = RT_NULL;

    message2.length = addr_length;

    message2.cs_take = 0;
    message2.cs_release = 0;
    message2.next = &message3;
    /* write data */
    message3.send_buf = buffer;
    message3.recv_buf = RT_NULL;
    message3.length = count * geometry.bytes_per_sector;
    message3.cs_take = 0;
    message3.cs_release = 1;
    message3.next = RT_NULL;

    rt_spi_transfer_message((struct rt_spi_device*)ramtron_spi_dev, &message1);

    ramtron_wait_writecplt();

    return RT_EOK;
}

rt_err_t ramtron_control(mtd_dev_t mtd, int cmd, void* arg)
{
    switch (cmd) {
    case RT_DEVICE_CTRL_BLK_GETGEOME: {
        *(struct rt_device_blk_geometry*)arg = geometry;
    } break;
    case RT_DEVICE_CTRL_BLK_SYNC: {
        ramtron_wait_writecplt();
    } break;
    case RT_DEVICE_CTRL_BLK_ERASE: {
        /* no need to erase */
    } break;
    default: {
        printf("unknown mtd control cmd:%d\n", cmd);
    } break;
    }

    return RT_EOK;
}

const static struct mtd_ops dev_ops = {
    .init = RT_NULL,
    .read = ramtron_read,
    .write = ramtron_write,
    .erase = RT_NULL,
    .control = ramtron_control
};

rt_err_t drv_ramtron_init(const char* spi_device_name)
{
    ramtron_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(ramtron_spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)ramtron_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* init spi bus */
    RT_TRY(rt_device_open(ramtron_spi_dev, RT_DEVICE_OFLAG_RDWR));

    /* try read device id */
    RT_TRY(ramtron_read_devinfo());

    ramtron_dev.ops = &dev_ops;
    return hal_mtd_register(&ramtron_dev, "mtdblk0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE, RT_NULL);
}
