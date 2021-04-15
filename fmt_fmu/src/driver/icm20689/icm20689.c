#include <firmament.h>

#include "driver/icm20689.h"
#include "hal/accel.h"
#include "hal/gyro.h"
#include "hal/spi.h"
#include "module/math/conversion.h"
#include "stm32f7xx_ll_spi.h"
#include "board_device.h"

#define DRV_DBG(...)

#define DIR_READ  0x80
#define DIR_WRITE 0x00

#define SELF_TEST_X_GYRO 0x00
#define SELF_TEST_Y_GYRO 0x01
#define SELF_TEST_Z_GYRO 0x02

#define SELF_TEST_X_ACCEL 0x0D
#define SELF_TEST_Y_ACCEL 0x0E
#define SELF_TEST_Z_ACCEL 0x0F

#define XG_OFFS_USRH 0x13
#define XG_OFFS_USRL 0x14
#define YG_OFFS_USRH 0x15
#define YG_OFFS_USRL 0x16
#define ZG_OFFS_USRH 0x17
#define ZG_OFFS_USRL 0x18

#define SMPLRT_DIV 0x19

#define MPUREG_CONFIG  0x1A
#define GYRO_CONFIG    0x1B
#define ACCEL_CONFIG   0x1C
#define ACCEL_CONFIG_2 0x1D

#define LOW_POWER_MODE 0x1E

#define MPU_FIFO_EN_REG 0X23

#define MPU_INTBP_CFG_REG 0X37
#define MPU_INT_EN_REG    0X38
#define MPU_INT_STA_REG   0X3A

#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define TEMP_OUT_H   0x41
#define TEMP_OUT_L   0x42
#define GYRO_XOUT_H  0x43
#define GYRO_XOUT_L  0x44
#define GYRO_YOUT_H  0x45
#define GYRO_YOUT_L  0x46
#define GYRO_ZOUT_H  0x47
#define GYRO_ZOUT_L  0x48

#define PWR_MGMT_1 0x6B
#define PWR_MGMT_2 0x6C
#define WHO_AM_I   0x75

#define ICM20689_ACCEL_DEFAULT_RANGE_G            8
#define ICM20689_ACCEL_DEFAULT_RATE               1000
#define ICM20689_ACCEL_DEFAULT_DRIVER_FILTER_FREQ 30

#define ICM20689_GYRO_DEFAULT_RANGE_G            8
#define ICM20689_GYRO_DEFAULT_RATE               1000
#define ICM20689_GYRO_DEFAULT_DRIVER_FILTER_FREQ 30

#define BITS_FS_250DPS             0x00
#define BITS_FS_500DPS             0x08
#define BITS_FS_1000DPS            0x10
#define BITS_FS_2000DPS            0x18
#define BIT_SLEEP                  0x40
#define BIT_H_RESET                0x80
#define BITS_CLKSEL                0x07
#define MPU_CLK_SEL_PLLGYROX       0x01
#define MPU_CLK_SEL_PLLGYROZ       0x03
#define MPU_EXT_SYNC_GYROX         0x02
#define BITS_FS_MASK               0x18
#define BITS_DLPF_CFG_256HZ_NOLPF2 0x00
#define BITS_DLPF_CFG_188HZ        0x01
#define BITS_DLPF_CFG_98HZ         0x02
#define BITS_DLPF_CFG_42HZ         0x03
#define BITS_DLPF_CFG_20HZ         0x04
#define BITS_DLPF_CFG_10HZ         0x05
#define BITS_DLPF_CFG_5HZ          0x06
#define BITS_DLPF_CFG_2100HZ_NOLPF 0x07
#define BITS_DLPF_CFG_MASK         0x07

#define ICM20689_ONE_G 9.80665f

#define M_PI_F 3.1415926f

static unsigned _sample_rate = 0;
static unsigned _dlpf_freq;
uint8_t _product;
static float _gyro_range_scale;
static float _gyro_range_rad_s;
static float _accel_range_scale;
static float _accel_range_m_s2;
static rt_device_t spi_device;

static rt_err_t _write_reg(rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t send_buffer[2];
    rt_size_t w_byte;

    send_buffer[0] = DIR_WRITE | reg;
    send_buffer[1] = val;
    w_byte = rt_device_write(spi_device, 0, send_buffer, sizeof(send_buffer));

    return w_byte == sizeof(send_buffer) ? RT_EOK : RT_ERROR;
}

static rt_err_t _read_reg(rt_uint8_t reg, rt_uint8_t* buff)
{
    rt_uint8_t send_val, recv_val;
    rt_err_t res;

    send_val = DIR_READ | reg;

    res = rt_spi_send_then_recv((struct rt_spi_device*)spi_device, (void*)&send_val, 1, (void*)&recv_val, 1);
    *buff = recv_val;

    return res;
}

static rt_err_t read_multi_reg(rt_uint8_t reg, rt_uint8_t* buff, uint8_t len)
{
    rt_uint8_t cmd;
    rt_err_t res;

    cmd = DIR_READ | reg;

    res = rt_spi_send_then_recv((struct rt_spi_device*)spi_device, (void*)&cmd, 1, (void*)buff, len);

    return res;
}

static rt_err_t _write_checked_reg(rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t r_buff;
    rt_err_t res = RT_EOK;

    res |= _write_reg(reg, val);
    res |= _read_reg(reg, &r_buff);

    if (r_buff != val || res != RT_EOK) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t _set_sample_rate(unsigned desired_sample_rate_hz)
{
    rt_err_t res;

    if (desired_sample_rate_hz == 0) {
        desired_sample_rate_hz = ICM20689_GYRO_DEFAULT_RATE;
    }

    /* if DLPF is disabled, the output rate is 8K, otherwise is 1K */
    uint8_t div = 1000 / desired_sample_rate_hz;

    if (div > 200) {
        div = 200;
    }

    if (div < 1) {
        div = 1;
    }

    res = _write_checked_reg(SMPLRT_DIV, div - 1);
    _sample_rate = 1000 / div;

    return res;
}

static rt_err_t _set_dlpf_filter(uint16_t frequency_hz)
{
    uint8_t filter;

    /*
	   choose next highest filter frequency available
	 */
    if (frequency_hz == 0) {
        _dlpf_freq = 0;
        filter = BITS_DLPF_CFG_2100HZ_NOLPF;

    } else if (frequency_hz <= 5) {
        _dlpf_freq = 5;
        filter = BITS_DLPF_CFG_5HZ;

    } else if (frequency_hz <= 10) {
        _dlpf_freq = 10;
        filter = BITS_DLPF_CFG_10HZ;

    } else if (frequency_hz <= 21) {
        _dlpf_freq = 21;
        filter = BITS_DLPF_CFG_20HZ;

    } else if (frequency_hz <= 44) {
        _dlpf_freq = 44;
        filter = BITS_DLPF_CFG_42HZ;

    } else if (frequency_hz <= 98) {
        _dlpf_freq = 98;
        filter = BITS_DLPF_CFG_98HZ;

    } else if (frequency_hz <= 188) {
        _dlpf_freq = 188;
        filter = BITS_DLPF_CFG_188HZ;

    } else if (frequency_hz <= 260) {
        _dlpf_freq = 260;
        filter = BITS_DLPF_CFG_256HZ_NOLPF2;

    } else {
        _dlpf_freq = 0;
        filter = BITS_DLPF_CFG_2100HZ_NOLPF;
    }

    return _write_checked_reg(MPUREG_CONFIG, filter);
}

static rt_err_t _set_accel_range(unsigned max_g_in)
{
#if 0
    /*
    TO DO
    */
    // workaround for bugged versions of MPU6k (rev C)
    switch (_product) {
    case MPU6000ES_REV_C4:
    case MPU6000ES_REV_C5:
    case MPU6000_REV_C4:
    case MPU6000_REV_C5:
        _write_checked_reg(ACCEL_CONFIG, 1 << 3);
        _accel_range_scale = (ICM20689_ONE_G / 4096.0f);
        _accel_range_m_s2 = 8.0f * ICM20689_ONE_G;
        return RT_EOK;
    }
#endif

    uint8_t afs_sel;
    float lsb_per_g;
    float max_accel_g;

    if (max_g_in > 8) { // 16g - AFS_SEL = 3
        afs_sel = 3;
        lsb_per_g = 2048;
        max_accel_g = 16;

    } else if (max_g_in > 4) { //  8g - AFS_SEL = 2
        afs_sel = 2;
        lsb_per_g = 4096;
        max_accel_g = 8;

    } else if (max_g_in > 2) { //  4g - AFS_SEL = 1
        afs_sel = 1;
        lsb_per_g = 8192;
        max_accel_g = 4;

    } else { //  2g - AFS_SEL = 0
        afs_sel = 0;
        lsb_per_g = 16384;
        max_accel_g = 2;
    }

    _accel_range_scale = (ICM20689_ONE_G / lsb_per_g);
    _accel_range_m_s2 = max_accel_g * ICM20689_ONE_G;

    return _write_checked_reg(ACCEL_CONFIG, afs_sel << 3);
}

static rt_err_t _set_gyro_range(unsigned max_dps)
{
    rt_uint8_t fs_sel;

    if (max_dps <= 250) {
        fs_sel = BITS_FS_250DPS;
    } else if (max_dps <= 500) {
        fs_sel = BITS_FS_500DPS;
    } else if (max_dps <= 1000) {
        fs_sel = BITS_FS_1000DPS;
    } else {
        fs_sel = BITS_FS_2000DPS;
    }

    _gyro_range_scale = (M_PI_F / 180.0f) / (32768.0f / (float)max_dps);
    _gyro_range_rad_s = (float)max_dps * (M_PI_F / 180.0f);

    return _write_checked_reg(GYRO_CONFIG, fs_sel);
}

static rt_err_t _init(void)
{
    rt_err_t res = RT_EOK;

    /* init spi bus */
    res = rt_device_open(spi_device, RT_DEVICE_OFLAG_RDWR);

    if (res == RT_EOK) {
        _write_reg(PWR_MGMT_1, 0X80); //复位
        LL_mDelay(100);
        _write_reg(PWR_MGMT_1, 0x00); //解除休眠状态
        LL_mDelay(100);
        _read_reg(WHO_AM_I, &_product);

        if (_product != 0x98) {
            return RT_ERROR;
        }
    }

    _write_reg(GYRO_CONFIG, 3 << 3);  //设置陀螺仪满量程范围
    _write_reg(ACCEL_CONFIG, 0 << 3); //加速度计工作范围 2G
    _write_reg(ACCEL_CONFIG_2, 0x08); //加速计高通滤波频率 典型值 ：0x08  （1.13kHz）

    _write_reg(SMPLRT_DIV, 19);
    _write_reg(MPUREG_CONFIG, 4); //低通滤波频率，典型值：0x07(3600Hz)此寄存器内决定Internal_Sample_Rate==8K

    _write_reg(MPU_INT_EN_REG, 0X00);  //关闭所有中断
    _write_reg(MPU_FIFO_EN_REG, 0X00); //关闭FIFO

    _write_reg(PWR_MGMT_1, 0X01); //设置CLKSEL,PLL X轴为参考
    _write_reg(PWR_MGMT_2, 0X00); //加速度与陀螺仪都工作

    return res;
}

static void rotate_to_ned(int16_t val[3])
{
    uint16_t temp = val[0];
    val[0] = val[1];
    val[1] = temp;
    val[2] = -val[2];
}

static rt_err_t icm20689_gyr_read_raw(int16_t gyr[3])
{
    rt_err_t res;
    uint16_t raw[3];
    res = read_multi_reg(GYRO_XOUT_H, (uint8_t*)raw, 6);
    // big-endian to little-endian
    gyr[0] = int16_t_from_bytes((uint8_t*)&raw[0]);
    gyr[1] = int16_t_from_bytes((uint8_t*)&raw[1]);
    gyr[2] = int16_t_from_bytes((uint8_t*)&raw[2]);
    // change to NED coordinate
    rotate_to_ned(gyr);

    return res;
}

static rt_err_t icm20689_gyr_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];
    rt_err_t res;
    res = icm20689_gyr_read_raw(gyr_raw);

    gyr[0] = _gyro_range_scale * gyr_raw[0];
    gyr[1] = _gyro_range_scale * gyr_raw[1];
    gyr[2] = _gyro_range_scale * gyr_raw[2];

    return res;
}

static rt_err_t icm20689_acc_read_raw(int16_t acc[3])
{
    int16_t raw[3];
    rt_err_t res;
    res = read_multi_reg(ACCEL_XOUT_H, (rt_uint8_t*)raw, 6);
    // big-endian to little-endian
    acc[0] = int16_t_from_bytes((uint8_t*)&raw[0]);
    acc[1] = int16_t_from_bytes((uint8_t*)&raw[1]);
    acc[2] = int16_t_from_bytes((uint8_t*)&raw[2]);
    // change to NED coordinate
    rotate_to_ned(acc);

    return res;
}

static rt_err_t icm20689_acc_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];
    rt_err_t res;
    res = icm20689_acc_read_raw(acc_raw);

    acc[0] = _accel_range_scale * acc_raw[0];
    acc[1] = _accel_range_scale * acc_raw[1];
    acc[2] = _accel_range_scale * acc_raw[2];

    return res;
}

static rt_err_t gyro_config(gyro_dev_t gyro, const struct gyro_configure* cfg)
{
    rt_err_t ret = RT_EOK;

    if (cfg == RT_NULL) {
        return RT_EINVAL;
    }

    ret |= _set_gyro_range(cfg->gyro_range_dps);

    ret |= _set_sample_rate(cfg->sample_rate_hz);

    ret |= _set_dlpf_filter(cfg->dlpf_freq_hz);

    gyro->config = *cfg;

    return ret;
}

static rt_err_t gyro_control(gyro_dev_t gyro, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t gyro_read(gyro_dev_t gyro, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (pos == GYRO_RD_RAW) {
        if (icm20689_gyr_read_raw(((int16_t*)data)) != RT_EOK) {
            return 0;
        }
    } else if (pos == GYRO_RD_SCALE) {
        if (icm20689_gyr_read_rad(((float*)data)) != RT_EOK) {
            return 0;
        }
    } else {
        DRV_DBG("gyro unknow read pos:%d\n", pos);
        return 0;
    }

    return size;
}

const static struct gyro_ops _gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{
    rt_err_t ret = RT_EOK;

    if (cfg == RT_NULL) {
        return RT_EINVAL;
    }

    ret |= _set_accel_range(cfg->acc_range_g);

    ret |= _set_sample_rate(cfg->sample_rate_hz);

    ret |= _set_dlpf_filter(cfg->dlpf_freq_hz);

    accel->config = *cfg;

    return ret;
}

static rt_err_t accel_control(accel_dev_t accel, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t accel_read(accel_dev_t accel, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (pos == ACCEL_RD_RAW) {
        if (icm20689_acc_read_raw(((int16_t*)data)) != RT_EOK) {
            return 0;
        }
    } else if (pos == ACCEL_RD_SCALE) {
        if (icm20689_acc_read_m_s2(((float*)data)) != RT_EOK) {
            return 0;
        }
    } else {
        DRV_DBG("accel unknow read pos:%d\n", pos);
        return 0;
    }

    return size;
}

const static struct accel_ops _accel_ops = {
    accel_config,
    accel_control,
    accel_read,
};

rt_err_t icm20689_drv_init(char* spi_device_name)
{
    rt_err_t ret = RT_EOK;

    static struct accel_device accel_dev = {
        .ops = &_accel_ops,
        .config = ACCEL_CONFIG_DEFAULT,
        .bus_type = GYRO_SPI_BUS_TYPE
    };
    static struct gyro_device gyro_dev = {
        .ops = &_gyro_ops,
        .config = GYRO_CONFIG_DEFAULT,
        .bus_type = GYRO_SPI_BUS_TYPE
    };

    spi_device = rt_device_find(spi_device_name);

    if (spi_device == RT_NULL) {
        //console_printf("spi device %s not found!\r\n", spi_device_name);
        return RT_EEMPTY;
    }

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = SPI1_SPEED_HZ;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_device;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        ret |= rt_spi_configure(spi_device_t, &cfg);
    }

    /* driver internal init */
    ret |= _init();

    /* register gyro hal device */
    ret |= hal_gyro_register(&gyro_dev, "gyro0", RT_DEVICE_FLAG_RDWR, RT_NULL);

    /* register accel hal device */
    ret |= hal_accel_register(&accel_dev, "accel0", RT_DEVICE_FLAG_RDWR, RT_NULL);

    return ret;
}

void icm20689_test(int16_t acc_test[], int16_t gyr_test[])
{
    icm20689_acc_read_raw(acc_test);

    icm20689_gyr_read_raw(gyr_test);
}