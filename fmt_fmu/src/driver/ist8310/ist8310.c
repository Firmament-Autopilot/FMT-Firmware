#include "driver/ist8310.h"
#include "hal/i2c.h"
#include "hal/i2c_dev.h"
#include <firmament.h>

rt_device_t i2c_dev;

#define REG_WHOAMI       0x00
#define REG_STAT1        0x02
#define REG_DATA_OUT_X_L 0x03
#define REG_DATA_OUT_X_H 0x04
#define REG_DATA_OUT_Y_L 0x05
#define REG_DATA_OUT_Y_H 0x06
#define REG_DATA_OUT_Z_L 0x07
#define REG_DATA_OUT_Z_H 0x08
#define REG_STAT2        0x09
#define REG_CTRL1        0x0a
#define REG_CTRL2        0x0b
#define REG_TEMP_L       0x1c
#define REG_TEMP_H       0x1d
#define REG_CTRL3        0x41
#define REG_CTRL4        0x42

#define CTRL3_SAMPLEAVG_16 0x24 /* Sample Averaging 16 */
#define CTRL3_SAMPLEAVG_8  0x1b /* Sample Averaging 8 */
#define CTRL3_SAMPLEAVG_4  0x12 /* Sample Averaging 4 */
#define CTRL3_SAMPLEAVG_2  0x09 /* Sample Averaging 2 */
#define CTRL4_SRPD         0xC0 /* Set Reset Pulse Duration */

rt_err_t drv_ist8310_init(const char* device_name)
{
    i2c_dev = rt_device_find(device_name);
    RT_ASSERT(i2c_dev != NULL);

    RT_CHECK_RETURN(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    uint8_t device_id;
    RT_CHECK_RETURN(i2c_read_reg(i2c_dev, REG_WHOAMI, &device_id));
    if (device_id != 0x10) {
        console_printf("ist8310 unmatched id: 0x%x\n", device_id);
        return RT_ERROR;
    }

    /* software reset */
    RT_CHECK_RETURN(i2c_write_reg(i2c_dev, REG_CTRL2, 1 << 0));

    sys_msleep(10);

    /* configure control register 3 */
    RT_CHECK_RETURN(i2c_write_reg(i2c_dev, REG_CTRL3, CTRL3_SAMPLEAVG_16));

    /* configure control register 4 */
    RT_CHECK_RETURN(i2c_write_reg(i2c_dev, REG_CTRL3, CTRL4_SRPD));

    RT_CHECK_RETURN(i2c_write_reg(i2c_dev, IST8310_REG_CNTRL1, IST8310_ODR_100_HZ));
    // RT_CHECK_RETURN(i2c_write_reg(i2c_dev, IST8310_REG_CNTRL1, 0x01));
    console_printf("test id:%x\n", device_id);

    return RT_EOK;
}

void rotateMag(enum Rotation rot, int16_t* v)
{
    int16_t tmp;

    switch (rot) {
    case ROTATION_NONE:
        return;

    case ROTATION_ROLL_270: {
        tmp = v[2];
        v[2] = -v[1];
        v[1] = tmp;
        return;
    }

    case ROTATION_PITCH_270: {
        tmp = v[2];
        v[2] = v[0];
        v[0] = -tmp;
        return;
    }
    }
}

void ist8310_read_raw_data(float* mag)
{
    uint8_t buffer[6];
    int16_t magRaw[3] = { 0 };

    // i2c_write_reg(i2c_dev, IST8310_REG_CNTRL1, 0x01);

    if(i2c_read_regs(i2c_dev, IST8310_REG_HX_L, buffer, 6) != RT_EOK){
        console_printf("read ist8310 fail\n");
    }
    magRaw[0] = (int16_t)buffer[1] << 8 | buffer[0];
    magRaw[1] = (int16_t)buffer[3] << 8 | buffer[2];
    magRaw[2] = (int16_t)buffer[5] << 8 | buffer[4];

    //roll 270°
    rotateMag(ROTATION_ROLL_270, magRaw);
    //pitch 270°
    rotateMag(ROTATION_PITCH_270, magRaw);

    mag[0] = magRaw[0] * IST8310_MAG_TO_GAUSS;
    mag[1] = magRaw[1] * IST8310_MAG_TO_GAUSS;
    mag[2] = magRaw[2] * IST8310_MAG_TO_GAUSS;

    // console_printf("mag %d %d %d\n", magRaw[0], magRaw[1], magRaw[2]);
}