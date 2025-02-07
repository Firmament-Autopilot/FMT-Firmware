# Modify this file to decide which drivers are compiled

DRIVERS = [
    'barometer/spl06.c',
    'gps/gps_ubx.c',
    'imu/bmi088.c',
    'imu/icm42688p.c',
    'mag/bmm150.c',
    'mag/qmc5883l.c',
    'mtd/gd25qxx.c',
]

DRIVERS_CPPPATH = []