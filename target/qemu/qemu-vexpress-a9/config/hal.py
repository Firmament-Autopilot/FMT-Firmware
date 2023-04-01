# Modify this file to decide which hal device are compiled

HAL = [
    'serial/*.c',
    'systick/*.c',
    'sd/*.c',
    'usb/usbd_cdc.c',
    'actuator/actuator.c',
]

HAL_CPPPATH = []