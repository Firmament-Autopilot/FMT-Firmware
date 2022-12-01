# Modify this file to decide which drivers are compiled

DRIVERS = [
    'imu/bmi088.c',
    'imu/icm42688.c',
    'imu/icm20948.c',
    'mag/bmm150.c',
    'barometer/spl06.c',
    'barometer/ms5611.c',
    'gps/gps_m8n.c',
    'rgb_led/aw2023.c',
    'mtd/w25qxx.c',
]

DRIVERS_CPPPATH = []