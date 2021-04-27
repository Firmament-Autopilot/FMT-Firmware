#ifndef __IST8310_H
#define __IST8310_H

#include <rtthread.h>

// IST8310 internal reg addr

#define IST8310_ADDRESS                 0x0E
#define IST8310_DEVICE_ID_A             0x10

#define IST8310_REG_HX_L                0x03
#define IST8310_REG_HX_H                0x04
#define IST8310_REG_HY_L                0x05
#define IST8310_REG_HY_H                0x06
#define IST8310_REG_HZ_L                0x07
#define IST8310_REG_HZ_H                0x08
#define IST8310_REG_WHOAMI              0x00
#define IST8310_REG_CNTRL1              0x0A
#define IST8310_REG_CNTRL2              0x0B
#define IST8310_REG_AVERAGE             0x41
#define IST8310_REG_PDCNTL              0x42
#define IST8310_ODR_SINGLE              0x01
#define IST8310_ODR_10_HZ               0x03
#define IST8310_ODR_20_HZ               0x05
#define IST8310_ODR_50_HZ               0x07
#define IST8310_ODR_100_HZ              0x06
#define IST8310_ODR_200_HZ              0x0B
#define IST8310_CHIP_ID                 0x10
#define IST8310_AVG_16                  0x24
#define IST8310_PULSE_DURATION_NORMAL   0xC0
#define IST8310_CNTRL2_RESET            0x01
#define IST8310_CNTRL2_DRPOL            0x04
#define IST8310_CNTRL2_DRENA            0x08

#define IST8310_MAG_TO_GAUSS            0.0015f

enum Rotation
{
    ROTATION_NONE                = 0,
    ROTATION_ROLL_270            = 20,
    ROTATION_PITCH_270           = 25,
};

int rt_ist8310_init(char* i2c_device_name); 


#endif