# Modify this file to decide which drivers are compiled

DRIVERS = [
    'barometer/ms5611.c',
    'gps/gps_ubx.c',
    'gps/gps_nmea.c',
    'imu/bmi088.c',
    'imu/bmi055.c',
    'imu/icm42688p.c',
    'mag/ist8310.c',
    'mtd/ramtron.c',
]

DRIVERS_CPPPATH = []
