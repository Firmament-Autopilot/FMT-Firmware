# Modify this file to decide which drivers are compiled

DRIVERS = [
    'imu/bmi088.c',
    'imu/icm42688p.c',
    'imu/icm20948.c',
    'mag/bmm150.c',
    'barometer/spl06.c',
    'barometer/ms5611.c',
    'gps/gps_ubx.c',
    'rgb_led/aw2023.c',
    'mtd/w25qxx.c',
    'vision_flow/mtf_01.c',
    'airspeed/ms4525.c',
    'uwb/nlink_linktrack/*.c',
]

DRIVERS_CPPPATH = []