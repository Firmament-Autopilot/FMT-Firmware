# Modify this file to decide which drivers are compiled

DRIVERS = [
    'imu/l3gd20h.c',
    'imu/lsm303d.c',
    'imu/mpu6000.c',
    'mag/hmc5883.c',
    'barometer/ms5611.c',
    'gps/gps_ubx.c',
    'vision_flow/mtf_01.c',
    'rgb_led/tca62724.c',
    'uwb/nlink_linktrack/*.c',
]

DRIVERS_CPPPATH = []