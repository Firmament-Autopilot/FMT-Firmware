# Modify this file to decide which drivers are compiled

DRIVERS = [
    'imu/bmi088.c',
    'imu/icm42688.c',
    'imu/icm20948.c',
    'mag/bmm150.c',
    'barometer/spl06.c',
    'barometer/ms5611.c',
    'gps/gps_m8n.c',
    # 'rgb_led/ncp5623c.c',
    'mtd/w25q16.c',
]

DRIVERS_CPPPATH = []