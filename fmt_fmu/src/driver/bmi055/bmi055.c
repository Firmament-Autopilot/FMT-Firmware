#include <firmament.h>

#include "driver/bmi055.h"
#include "hal/accel.h"
#include "hal/gyro.h"
#include "hal/spi.h"
#include "module/math/conversion.h"
#include "stm32f7xx_ll_spi.h"

#define DRV_DBG(...)

#define BMI055_ACCEL_DEFAULT_RANGE_G            8
#define BMI055_ACCEL_DEFAULT_RATE               1000
#define BMI055_ACCEL_DEFAULT_DRIVER_FILTER_FREQ 30

#define BMI055_GYRO_DEFAULT_RANGE_G            8
#define BMI055_GYRO_DEFAULT_RATE               400
#define BMI055_GYRO_DEFAULT_DRIVER_FILTER_FREQ 30

static rt_device_t spi_device_gyro;
static rt_device_t spi_device_acc;
uint8_t _gyro_id;
uint8_t _acc_id;

static float _gyro_range_scale;
static float _accel_range_scale;

#define DIR_READ  0x80
#define DIR_WRITE 0x00

static rt_err_t _write_reg(rt_device_t spi_device,rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t send_buffer[2];
    rt_size_t w_byte;

    send_buffer[0] = DIR_WRITE | reg;
    send_buffer[1] = val;
    w_byte = rt_device_write(spi_device, 0, send_buffer, sizeof(send_buffer));

    return w_byte == sizeof(send_buffer) ? RT_EOK : RT_ERROR;
}

static rt_err_t _read_reg(rt_device_t spi_device,rt_uint8_t reg, rt_uint8_t* buff)
{
    rt_uint8_t send_val, recv_val;
    rt_err_t res;

    send_val = DIR_READ | reg;

    res = rt_spi_send_then_recv((struct rt_spi_device*)spi_device, (void*)&send_val, 1, (void*)&recv_val, 1);
    *buff = recv_val;

    return res;
}

static rt_err_t read_multi_reg(rt_device_t spi_device,rt_uint8_t reg, rt_uint8_t* buff, uint8_t len)
{
    rt_uint8_t cmd;
    rt_err_t res;

    cmd = DIR_READ | reg;

    res = rt_spi_send_then_recv((struct rt_spi_device*)spi_device, (void*)&cmd, 1, (void*)buff, len);

    return res;
}

static rt_err_t _write_checked_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t r_buff;
    rt_err_t res = RT_EOK;

    res |= _write_reg(spi_device,reg, val);
    res |= _read_reg(spi_device,reg, &r_buff);

    if (r_buff != val || res != RT_EOK) {
        return RT_ERROR;
    }

    return RT_EOK;
}


static rt_err_t _gyro_set_sample_rate(unsigned desired_sample_rate_hz)
{
    rt_err_t res;

    return res;
}

static rt_err_t _gyro_set_dlpf_filter(uint16_t frequency_hz)
{
    uint8_t filter = 0;

      return _write_checked_reg(spi_device_gyro,BMI055_BW_ADDR, filter);
}  

static rt_err_t _set_gyro_range(unsigned max_dps)
{
    uint8_t value;

    return _write_checked_reg(spi_device_gyro,BMI055_RANGE_ADDR, value);
}

static rt_err_t _acc_set_sample_rate(unsigned desired_sample_rate_hz)
{
    rt_err_t res;

    return res;
}

static rt_err_t _acc_set_dlpf_filter(uint16_t frequency_hz)
{
    uint8_t filter = 0;

      return _write_checked_reg(spi_device_acc,BMI055_BW_ADDR, filter);
}  

static rt_err_t _set_accel_range(unsigned max_g_in)
{
    uint8_t value;

    return _write_checked_reg(spi_device_acc,BMI055_PMU_RANGE, value);
}

static rt_err_t _gyro_init(void)
{
    rt_err_t res = RT_EOK;
    uint8_t value;

    /* init spi bus */
    res =  rt_device_open(spi_device_gyro, RT_DEVICE_OFLAG_RDWR);

    if(res == RT_EOK)
    {
        /* initialize BMI055  gyro*/
        _write_reg(spi_device_gyro,BMI055_MODE_LPM1_ADDR, 0x00);			/* normal mode 						*/
	    _write_reg(spi_device_gyro,BMI055_MODE_LPM2_ADDR, 0x80);			/* fast powerup 					*/
        _write_reg(spi_device_gyro,BMI055_BW_ADDR,        0x03);			/* ODR:400Hz Filter Bandwidth:47Hz	*/
	    _write_reg(spi_device_gyro,BMI055_RANGE_ADDR,     0x00);			/* 2000dps                          */

        _read_reg(spi_device_gyro,BMI055_CHIP_ID_ADDR, &_gyro_id); 
        if (_gyro_id != BMI055_GRRO_CHIP_ID)
        {
            //printf("Warning: not found BMI055 id: %02x\n", id);
            res = RT_ERROR;
        }

        /* enable gyroscope */
		_read_reg(spi_device_gyro,BMI055_MODE_LPM1_ADDR, &value);   
		value &= ~(0x1010 << 4);					//{0; 0}  NORMAL mode
		_write_reg(spi_device_gyro,BMI055_MODE_LPM1_ADDR, value);	//P101 NORMAL mode
    }

    return res;
}

static rt_err_t _acc_init(void)
{
    rt_err_t res = RT_EOK;
    uint8_t value;

    /* init spi bus */
    res =  rt_device_open(spi_device_acc, RT_DEVICE_OFLAG_RDWR);

    if(res == RT_EOK)
    {
        /* initialize BMI055  accel*/
        _write_reg(spi_device_acc, BMI055_BGW_SOFTRESET, 0xB6);			/* reset of the sensor  P57							*/
        _write_reg(spi_device_acc, BMI055_PMU_LPW, 0x00);				/* PMU_LPW   NORMAL mode P55						*/
        _write_reg(spi_device_acc, BMI055_PMU_BW, 0x0A);					/* 01010b  31.25 Hz P55								*/
        _write_reg(spi_device_acc, BMI055_PMU_RANGE, 0x05);				/* 0101b  ±4g range PMU_RANGE set acc +-4g/s  P54	*/

        _read_reg(spi_device_acc, BMI055_ACC_BGW_CHIPID, &_acc_id);
        if (_acc_id != BMI055_ACC_BGW_CHIPID_VALUE)
        {
            //printf("Warning: not found BMI055 id: %02x\n", id);
            res = RT_ERROR;
        }

        /* enable accelerometer */
		_read_reg(spi_device_acc, BMI055_PMU_LPW, &value); 	/* P55 */
		value &= ~(0x07 << 7);
		_write_reg(spi_device_acc, BMI055_PMU_LPW, value);

    }

    return res;
}

static void rotate_to_ned(int16_t val[3])
{
    uint16_t temp = val[0];
    val[0] = val[1];
    val[1] = temp;
    val[2] = -val[2];
}

static rt_err_t bmi055_gyr_read_raw(int16_t gyr[3])
{
    rt_err_t res;
    uint16_t raw[3];
    res = read_multi_reg(spi_device_gyro, BMI055_ACCD_X_LSB, (uint8_t*)raw, 6);
    // big-endian to little-endian
    gyr[0] = int16_t_from_bytes((uint8_t*)&raw[0]);
    gyr[1] = int16_t_from_bytes((uint8_t*)&raw[1]);
    gyr[2] = int16_t_from_bytes((uint8_t*)&raw[2]);
    // change to NED coordinate
    rotate_to_ned(gyr);

    return res;
}

static rt_err_t bmi055_gyr_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];
    rt_err_t res;
    res = bmi055_gyr_read_raw(gyr_raw);

    gyr[0] = _gyro_range_scale * gyr_raw[0];
    gyr[1] = _gyro_range_scale * gyr_raw[1];
    gyr[2] = _gyro_range_scale * gyr_raw[2];

    return res;
}

static rt_err_t bmi055_acc_read_raw(int16_t acc[3])
{
    int16_t raw[3];
    rt_err_t res;
    res = read_multi_reg(spi_device_acc, BMI055_ACCD_X_LSB, (rt_uint8_t*)raw, 6);
    // big-endian to little-endian
    acc[0] = int16_t_from_bytes((uint8_t*)&raw[0]);
    acc[1] = int16_t_from_bytes((uint8_t*)&raw[1]);
    acc[2] = int16_t_from_bytes((uint8_t*)&raw[2]);
    // change to NED coordinate
    rotate_to_ned(acc);

    return res;
}

static rt_err_t bmi055_acc_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];
    rt_err_t res;
    res = bmi055_acc_read_raw(acc_raw);

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

    ret |= _gyro_set_sample_rate(cfg->sample_rate_hz);

    ret |= _gyro_set_dlpf_filter(cfg->dlpf_freq_hz);

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
        if (bmi055_gyr_read_raw(((int16_t*)data)) != RT_EOK) {
            return 0;
        }
    } else if (pos == GYRO_RD_SCALE) {
        if (bmi055_gyr_read_rad(((float*)data)) != RT_EOK) {
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

    ret |= _acc_set_sample_rate(cfg->sample_rate_hz);

    ret |= _acc_set_dlpf_filter(cfg->dlpf_freq_hz);

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
        if (bmi055_acc_read_raw(((int16_t*)data)) != RT_EOK) {
            return 0;
        }
    } else if (pos == ACCEL_RD_SCALE) {
        if (bmi055_acc_read_m_s2(((float*)data)) != RT_EOK) {
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
        .ops = &_gyro_ops,
        .config = GYRO_CONFIG_DEFAULT,
        .bus_type = GYRO_SPI_BUS_TYPE
    };

    spi_device_gyro = rt_device_find(spi_device_name);

    if (spi_device_gyro == RT_NULL) {
        //console_printf("spi device %s not found!\r\n", spi_device_name);
        return RT_EEMPTY;
    }
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 3000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_device_gyro;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        ret |= rt_spi_configure(spi_device_t, &cfg);
    }

    /* driver internal init */
    ret |= _gyro_init();

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

    spi_device_acc = rt_device_find(spi_device_name);

    if (spi_device_acc == RT_NULL) {
        //console_printf("spi device %s not found!\r\n", spi_device_name);
        return RT_EEMPTY;
    }
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 3000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_device_acc;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        ret |= rt_spi_configure(spi_device_t, &cfg);
    }

    /* driver internal init */
    ret |= _acc_init();

    /* register accel hal device */
    ret |= hal_accel_register(&accel_dev, "accel1", RT_DEVICE_FLAG_RDWR, RT_NULL);

    return ret;

}

