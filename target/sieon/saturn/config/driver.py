# Modify this file to decide which drivers are compiled

DRIVERS = [
    # 'imu/icm20649.c',
    # 'imu/icm20948.c',
    # 'imu/bmi055.c',
    'barometer/spl06.c',
    'gps/gps_ubx.c',
    # 'gps/gps_dronecan.c',
    # 'rgb_led/rgb_dronecan.c',
    # 'mtd/ramtron.c',
    'imu/bmi088.c',
    'imu/icm42688p.c',
    'mag/bmm150.c',
    'mtd/w25qxx.c',
]

DRIVERS_CPPPATH = []