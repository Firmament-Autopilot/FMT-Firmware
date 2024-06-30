# Modify this file to decide which hal device are compiled

HAL = [
    'serial/*.c',
    'systick/*.c',
    'sd/*.c',
    'usb/usbd_cdc.c',
    'pin/*.c',
    'spi/*.c',
    'gyro/*.c',
    'accel/*.c',
    'mag/*.c',
    'barometer/*.c',
]

HAL_CPPPATH = []