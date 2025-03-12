# Modify this file to decide which drivers are compiled

DRIVERS = [
    'barometer/spl06.c',
    'gps/gps_ubx.c',
    'imu/bmi088.c',
    'imu/icm42688p.c',
    'mag/ist8310.c',
    'mtd/ramtron.c',
    'range_finder/tofsense.c',
]

DRIVERS_CPPPATH = []