# Modify this file to decide which drivers are compiled

DRIVERS = [
    'imu/icm20689.c',
    'imu/bmi055.c',
    'mag/ist8310.c',
    'barometer/ms5611.c',
    'gps/gps_ubx.c',
    'rgb_led/ncp5623c.c',
    'mtd/ramtron.c',
    'vision_flow/mtf_01.c',
]

DRIVERS_CPPPATH = []