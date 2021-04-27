#include "driver/ist8310.h"
#include "hal/i2c.h"
#include "hal/i2c_dev.h"
#include <firmament.h>

uint8_t ist8310_id;

rt_device_t i2c_dev;

int16_t magRaw[3] = { 0 };


int rt_ist8310_init(char* i2c_device_name)
{
    i2c_dev = rt_device_find(i2c_device_name);
    RT_ASSERT(i2c_dev != NULL);
    rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR);

    i2c_read_reg(i2c_dev, IST8310_REG_WHOAMI, &ist8310_id);

    console_printf("ist8310 id:%x\n", ist8310_id);

    i2c_write_reg(i2c_dev, IST8310_REG_CNTRL1, IST8310_ODR_200_HZ);

    return 0;
}

void rotateMag(enum Rotation rot, int16_t* v)
{
    float tmp;

    switch (rot)
    {
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

void ist8310_read_raw_data(void)
{
    uint8_t buffer[6];

    i2c_read_regs(i2c_dev, IST8310_REG_HX_L, buffer, 6);
    magRaw[0] = (int16_t)buffer[1] << 8 | buffer[0];
    magRaw[1] = (int16_t)buffer[3] << 8 | buffer[2];
    magRaw[2] = (int16_t)buffer[5] << 8 | buffer[4];

    //roll 270°
    rotateMag(ROTATION_ROLL_270,magRaw);
    //pitch 270°
    rotateMag(ROTATION_PITCH_270,magRaw);

    console_printf("mag %d %d %d\n", magRaw[0], magRaw[1], magRaw[2]);
}