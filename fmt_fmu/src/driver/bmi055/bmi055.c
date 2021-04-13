#include <firmament.h>

#include "driver/bmi055.h"
#include "hal/accel.h"
#include "hal/gyro.h"
#include "hal/spi.h"
#include "module/math/conversion.h"
#include "stm32f7xx_ll_spi.h"

#define DRV_DBG(...)

#define CHECK_RETURN(__func)  \
    if ((__func) != RT_EOK) { \
        return RT_ERROR;      \
    }

#define DIR_READ     0x80
#define DIR_WRITE    0x00
#define M_PI_F       3.1415926f
#define BMI055_ONE_G 9.80665f

static rt_device_t gyro_spi_dev;
static rt_device_t accel_spi_dev;
uint8_t _acc_id;

static float __gyro_range_scale;
static float __accel_range_scale;

static rt_err_t __write_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t send_buffer[2];
    rt_size_t w_byte;

    send_buffer[0] = DIR_WRITE | reg;
    send_buffer[1] = val;
    w_byte = rt_device_write(spi_device, 0, send_buffer, sizeof(send_buffer));

    return w_byte == sizeof(send_buffer) ? RT_EOK : RT_ERROR;
}

static rt_err_t __read_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t* buff)
{
    rt_uint8_t send_val, recv_val;

    send_val = DIR_READ | reg;

    CHECK_RETURN(rt_spi_send_then_recv((struct rt_spi_device*)spi_device,
        (void*)&send_val, 1, (void*)&recv_val, 1));

    *buff = recv_val;

    return RT_EOK;
}

static rt_err_t __read_multi_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t* buff, uint8_t len)
{
    rt_uint8_t cmd;

    cmd = DIR_READ | reg;

    CHECK_RETURN(rt_spi_send_then_recv((struct rt_spi_device*)spi_device,
        (void*)&cmd, 1, (void*)buff, len));

    return RT_EOK;
}

static rt_err_t __write_checked_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t r_val;

    CHECK_RETURN(__write_reg(spi_device, reg, val));
    CHECK_RETURN(__read_reg(spi_device, reg, &r_val));

    if (r_val == val) {
        return RT_EOK;
    } else {
        return RT_ERROR;
    }
}

static rt_err_t __modify_reg(rt_device_t spi_device, rt_uint8_t reg, reg_val_t reg_val)
{
    uint8_t value;

    CHECK_RETURN(__read_reg(spi_device, reg, &value));

    value &= ~reg_val.clearbits;
    value |= reg_val.setbits;

    CHECK_RETURN(__write_checked_reg(spi_device, reg, value));

    return RT_EOK;
}

static void rotate_to_ned(int16_t val[3])
{
    int16_t temp = val[0];
    val[0] = val[1];
    val[1] = temp;
    val[2] = -val[2];
}

static rt_err_t gyro_set_sample_rate(uint32_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz <= 100) {
        reg_val = BMI055_GYRO_RATE_100;
    } else if (frequency_hz <= 200) {
        reg_val = BMI055_GYRO_RATE_200;
    } else if (frequency_hz <= 400) {
        reg_val = BMI055_GYRO_RATE_400;
    } else if (frequency_hz <= 1000) {
        reg_val = BMI055_GYRO_RATE_1000;
    } else if (frequency_hz <= 2000) {
        reg_val = BMI055_GYRO_RATE_2000;
    } else {
        return RT_EINVAL;
    }

    CHECK_RETURN(__modify_reg(gyro_spi_dev, BMI055_BW_ADDR, reg_val));

    return RT_EOK;
}

static rt_err_t gyro_set_dlpf_filter(uint16_t frequency_hz)
{
    /* lpf bw is set by BMI055_BW_ADDR */
    return RT_EOK;
}

static rt_err_t gyro_set_range(unsigned max_dps)
{
    reg_val_t reg_val;
    float lsb_per_dps;

    if (max_dps == 0) {
        max_dps = 2000;
    }

    if (max_dps <= 125) {
        reg_val = BMI055_GYRO_RANGE_125_DPS;
        lsb_per_dps = 262.4;
    } else if (max_dps <= 250) {
        reg_val = BMI055_GYRO_RANGE_250_DPS;
        lsb_per_dps = 131.2;
    } else if (max_dps <= 500) {
        reg_val = BMI055_GYRO_RANGE_500_DPS;
        lsb_per_dps = 65.6;
    } else if (max_dps <= 1000) {
        reg_val = BMI055_GYRO_RANGE_1000_DPS;
        lsb_per_dps = 32.8;
    } else if (max_dps <= 2000) {
        reg_val = BMI055_GYRO_RANGE_2000_DPS;
        lsb_per_dps = 16.4;
    } else {
        return RT_EINVAL;
    }

    CHECK_RETURN(__modify_reg(gyro_spi_dev, BMI055_RANGE_ADDR, reg_val));

    __gyro_range_scale = (M_PI_F / (180.0f * lsb_per_dps));

    return RT_EOK;
}

static rt_err_t gyro_read_raw(int16_t gyr[3])
{
    CHECK_RETURN(__read_multi_reg(gyro_spi_dev, BMI055_RATE_X_LSB_ADDR, (uint8_t*)gyr, 6));
    rotate_to_ned(gyr);

    return RT_EOK;
}

static rt_err_t gyro_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];

    CHECK_RETURN(gyro_read_raw(gyr_raw));

    gyr[0] = __gyro_range_scale * gyr_raw[0];
    gyr[1] = __gyro_range_scale * gyr_raw[1];
    gyr[2] = __gyro_range_scale * gyr_raw[2];

    return RT_EOK;
}

static rt_err_t gyroscope_init(void)
{
    uint8_t gyro_id;

    /* init spi bus */
    CHECK_RETURN(rt_device_open(gyro_spi_dev, RT_DEVICE_OFLAG_RDWR));

    __read_reg(gyro_spi_dev, BMI055_CHIP_ID_ADDR, &gyro_id);
    if (gyro_id != BMI055_GRRO_CHIP_ID) {
        DRV_DBG("Warning: not found BMI055 gyro id: %02x\n", gyro_id);
        return RT_ERROR;
    }

    /* soft reset */
    CHECK_RETURN(__write_reg(gyro_spi_dev, BMI055_BGW_SOFT_RST_ADDR, 0xB6));
    systime_udelay(5000);

    CHECK_RETURN(gyro_set_range(2000));       /* 2000dps */
    CHECK_RETURN(gyro_set_sample_rate(1000)); /* OSR 1000KHz, Filter BW: 116Hz */

    /* enable gyroscope */
    CHECK_RETURN(__modify_reg(gyro_spi_dev, BMI055_MODE_LPM1_ADDR, REG_VAL(0, BIT(7) | BIT(5)))); /* {0; 0}  NORMAL mode */
    systime_udelay(1000);

    return RT_EOK;
}

static rt_err_t gyro_config(gyro_dev_t gyro, const struct gyro_configure* cfg)
{
    RT_ASSERT(cfg != RT_NULL);

    CHECK_RETURN(gyro_set_range(cfg->gyro_range_dps));

    CHECK_RETURN(gyro_set_sample_rate(cfg->sample_rate_hz));

    CHECK_RETURN(gyro_set_dlpf_filter(cfg->dlpf_freq_hz));

    gyro->config = *cfg;

    return RT_EOK;
}

static rt_err_t gyro_control(gyro_dev_t gyro, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t gyro_read(gyro_dev_t gyro, rt_off_t pos, void* data, rt_size_t size)
{
    RT_ASSERT(data != RT_NULL);

    if (pos == GYRO_RD_RAW) {
        if (gyro_read_raw(((int16_t*)data)) != RT_EOK) {
            return 0;
        }
    } else if (pos == GYRO_RD_SCALE) {
        if (gyro_read_rad(((float*)data)) != RT_EOK) {
            return 0;
        }
    } else {
        DRV_DBG("gyro unknow read pos:%d\n", pos);
        return 0;
    }

    return size;
}

const static struct gyro_ops __gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

static rt_err_t accel_set_sample_rate(uint32_t frequency_hz)
{
    return RT_EOK;
}

static rt_err_t accel_set_dlpf_filter(uint16_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz <= (781 / 100)) {
        reg_val = BMI055_ACCEL_BW_7_81;
    } else if (frequency_hz <= (1563 / 100)) {
        reg_val = BMI055_ACCEL_BW_15_63;
    } else if (frequency_hz <= (3125 / 100)) {
        reg_val = BMI055_ACCEL_BW_31_25;
    } else if (frequency_hz <= 6250 / 100) {
        reg_val = BMI055_ACCEL_BW_62_5;
    } else if (frequency_hz <= 125) {
        reg_val = BMI055_ACCEL_BW_125;
    } else if (frequency_hz <= 250) {
        reg_val = BMI055_ACCEL_BW_250;
    } else if (frequency_hz <= 500) {
        reg_val = BMI055_ACCEL_BW_500;
    } else if (frequency_hz <= 1000) {
        reg_val = BMI055_ACCEL_BW_1000;
    } else {
        return -EINVAL;
    }

    CHECK_RETURN(__modify_reg(accel_spi_dev, BMI055_PMU_BW, reg_val));

    return RT_EOK;
}

static rt_err_t accel_set_range(uint32_t max_g)
{
    reg_val_t reg_val;
    float lsb_per_g;

    if (max_g == 0) {
        max_g = 16;
    }

    if (max_g <= 2) {
        reg_val = BMI055_ACCEL_RANGE_2_G;
        lsb_per_g = 1024;
    } else if (max_g <= 4) {
        reg_val = BMI055_ACCEL_RANGE_4_G;
        lsb_per_g = 512;
    } else if (max_g <= 8) {
        reg_val = BMI055_ACCEL_RANGE_8_G;
        lsb_per_g = 256;
    } else if (max_g <= 16) {
        reg_val = BMI055_ACCEL_RANGE_16_G;
        lsb_per_g = 128;
    } else {
        return RT_EINVAL;
    }

    CHECK_RETURN(__modify_reg(accel_spi_dev, BMI055_PMU_RANGE, reg_val));

    __accel_range_scale = (BMI055_ONE_G / lsb_per_g);

    return RT_EOK;
}

static rt_err_t accelerometer_init(void)
{
    uint8_t accel_id;

    /* init spi bus */
    CHECK_RETURN(rt_device_open(accel_spi_dev, RT_DEVICE_OFLAG_RDWR));

    __read_reg(accel_spi_dev, BMI055_ACC_BGW_CHIPID, &accel_id);
    if (accel_id != BMI055_ACC_BGW_CHIPID_VALUE) {
        DRV_DBG("Warning: not found BMI055 accel id: %02x\n", accel_id);
        return RT_ERROR;
    }

    /* soft reset */
    CHECK_RETURN(__write_reg(accel_spi_dev, BMI055_BGW_SOFTRESET, 0xB6));
    systime_udelay(5000);

    CHECK_RETURN(accel_set_range(2));          /* 2g */
    CHECK_RETURN(accel_set_dlpf_filter(1000)); /* 1000Hz BW */

    /* enable gyroscope */
    CHECK_RETURN(__modify_reg(accel_spi_dev, BMI055_PMU_LPW, REG_VAL(0, BIT(7) | BIT(6) | BIT(5)))); /* {0; 0; 0}  NORMAL mode */
    systime_udelay(1000);

    return RT_EOK;
}

static rt_err_t accel_read_raw(int16_t acc[3])
{
    uint8_t buffer[6];
    int16_t msblsb;
    
    CHECK_RETURN(__read_multi_reg(accel_spi_dev, BMI055_ACCD_X_LSB, buffer, 6));

    msblsb = buffer[1] << 8 | buffer[0];
    acc[0] = msblsb >> 4;
    msblsb = buffer[3] << 8 | buffer[2];
    acc[1] = msblsb >> 4;
    msblsb = buffer[5] << 8 | buffer[4];
    acc[2] = msblsb >> 4;

    rotate_to_ned(acc);

    return RT_EOK;
}

static rt_err_t accel_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];

    CHECK_RETURN(accel_read_raw(acc_raw));

    acc[0] = __accel_range_scale * acc_raw[0];
    acc[1] = __accel_range_scale * acc_raw[1];
    acc[2] = __accel_range_scale * acc_raw[2];

    return RT_EOK;
}

static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{
    rt_err_t ret = RT_EOK;

    if (cfg == RT_NULL) {
        return RT_EINVAL;
    }

    ret |= accel_set_range(cfg->acc_range_g);

    ret |= accel_set_sample_rate(cfg->sample_rate_hz);

    ret |= accel_set_dlpf_filter(cfg->dlpf_freq_hz);

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
        if (accel_read_raw(((int16_t*)data)) != RT_EOK) {
            return 0;
        }
    } else if (pos == ACCEL_RD_SCALE) {
        if (accel_read_m_s2(((float*)data)) != RT_EOK) {
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

rt_err_t bmi055_gyro_drv_init(char* spi_device_name)
{
    rt_err_t ret = RT_EOK;

    static struct gyro_device gyro_dev = {
        .ops = &__gyro_ops,
        .config = GYRO_CONFIG_DEFAULT,
        .bus_type = GYRO_SPI_BUS_TYPE
    };

    gyro_spi_dev = rt_device_find(spi_device_name);

    if (gyro_spi_dev == RT_NULL) {
        //console_printf("spi device %s not found!\r\n", spi_device_name);
        return RT_EEMPTY;
    }
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 3000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)gyro_spi_dev;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        ret |= rt_spi_configure(spi_device_t, &cfg);
    }

    /* driver internal init */
    RTT_CHECK(gyroscope_init());

    /* register gyro hal device */
    ret |= hal_gyro_register(&gyro_dev, "gyro1", RT_DEVICE_FLAG_RDWR, RT_NULL);

    return ret;
}

rt_err_t bmi055_acc_drv_init(char* spi_device_name)
{
    rt_err_t ret = RT_EOK;

    static struct accel_device accel_dev = {
        .ops = &_accel_ops,
        .config = ACCEL_CONFIG_DEFAULT,
        .bus_type = GYRO_SPI_BUS_TYPE
    };

    accel_spi_dev = rt_device_find(spi_device_name);

    if (accel_spi_dev == RT_NULL) {
        //console_printf("spi device %s not found!\r\n", spi_device_name);
        return RT_EEMPTY;
    }
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 3000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)accel_spi_dev;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        ret |= rt_spi_configure(spi_device_t, &cfg);
    }

    /* driver internal init */
    ret |= accelerometer_init();

    /* register accel hal device */
    ret |= hal_accel_register(&accel_dev, "accel1", RT_DEVICE_FLAG_RDWR, RT_NULL);

    return ret;
}
