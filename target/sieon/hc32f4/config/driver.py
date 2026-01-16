# Modify this file to decide which drivers are compiled

DRIVERS = [
    # 'barometer/spl06.c',
    # 'gps/gps_ubx.c',
    # 'imu/bmi088.c',
    # 'imu/icm42688p.c',
    # 'mag/bmm150.c',
    'mag/qmc5883p.c',
    # 'airspeed/ms4525.c',
    'mtd/gd25qxx.c',
    'mtd/spi_tfcard.c',
    # 'range_finder/tofsense.c',
]

DRIVERS_CPPPATH = []