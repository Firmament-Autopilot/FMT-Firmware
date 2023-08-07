# Modify this file to decide which drivers are compiled

DRIVERS = [
    'imu/icm20649.c',
    'imu/icm20948.c',
    'imu/bmi055.c',
    'mag/ist8310.c',
    'barometer/ms5611.c',
    'gps/gps_ubx.c',
    'gps/gps_dronecan.c',
    'rgb_led/rgb_dronecan.c',
    'mtd/ramtron.c',
]

DRIVERS_CPPPATH = []