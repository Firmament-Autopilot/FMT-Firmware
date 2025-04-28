# Modify this file to decide which hal device are compiled

HAL = [
    'serial/*.c',
    'systick/*.c',
    'sd/*.c',
    'mtd/*.c',
    'usb/usbd_cdc.c',
    'pin/*.c',
    'spi/*.c',
    'gyro/*.c',
    'accel/*.c',
    'mag/*.c',
    'barometer/*.c',
    'gps/*.c',
    'i2c/*.c',
    'actuator/*.c',
    'rc/*.c',
    'can/*.c',
    'adc/*.c',
    'fmtio_dev/*.c',
]

HAL_CPPPATH = []