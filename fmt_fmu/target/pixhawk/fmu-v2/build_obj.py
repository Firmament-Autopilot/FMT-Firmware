# Build object lists

DRIVERS = [
    '*.c',
    'buzzer/*.c',
    'gpio/*.c',
    'gps/*.c',
    'hmc5883/*.c',
    'hw_timer/*.c',
    'i2c/*.c',
    'l3gd20h/*.c',
    'lidar/*.c',
    'lsm303d/*.c',
    'mpu6000/*.c',
    'ms5611/*.c',
    'pwm/*.c',
    'rtc/*.c',
    'sdio/*.c',
    'spi/*.c',
    'systick/st/f4_systick.c',
    'tca62724/*.c',
    'usart/*.c',
    'utils/*.c',
    'mateksys/*.c',
    'usb/src/usb_bsp.c',
    'usb/src/usb_core.c',
    'usb/src/usb_dcd.c',
    'usb/src/usb_dcd_int.c',
    'usb/src/usbd_cdc_core_loopback.c',
    'usb/src/usbd_core.c',
    'usb/src/usbd_desc.c',
    'usb/src/usbd_ioreq.c',
    'usb/src/usbd_req.c',
    'usb/src/usbd_usr.c',
]

DRIVERS_CPPPATH = [
    'usb/inc'
]

HAL = [
    '*.c',
    'mag/*.c',
    'accel/*.c',
    'barometer/*.c',
    'gps/*.c',
    'fmtio_dev/*.c',
    'gyro/*.c',
    'i2c/*.c',
    'motor/*.c',
    'pin/*.c',
    'rc/*.c',
    'serial/*.c',
    'systick/*.c',
    'tools/*.c',
    'usb/*.c',
    'optical_flow/*.c',
    'spi/spi_core.c',
    'spi/spi_dev.c',
]

HAL_CPPPATH = []

MODULES = [
    '*.c',
    'Calibration/*.c',
    'Console/*.c',
    'FS_Manager/*.c',
    'FTP/*.c',
    'Plant/*.c',
    'Plant/lib/*.c',
    'INS/*.c',
    'INS/lib/*.c',
    'Controller/*.c',
    'Controller/lib/*.c',
    'FMS/*.c',
    'FMS/lib/*.c',
    'IPC/*.c',
    'LED/*.c',
    'Log/*.c',
    'Math/*.c',
    'Mavproxy/*.c',
    'Parameter/*.c',
    'Sensor/*.c',
    'FMTIO/*.c',
    'SysIO/*.c',
    'SysCmd/*.c',
    'System/*.c',
    'Unit_Test/*.c',
    'Utils/*.c',
    'Vehicle/*.c',
    'BuzzerTune/*.c',
    'Filter/*.c',
    'TOML/*.c',
]

MODULES_CPPPATH = [
    'Calibration',
    'INS/lib',
    'Plant/lib',
    'Controller/lib',
    'FMS/lib',
    'FS_Manager',
    'BuzzerTune'
]

TASKS = [
    'vehicle/multicopter/*.c',
    'comm/*.c',
    'logger/*.c',
    'fmtio/*.c',
    'status/*.c'
]

TASKS_CPPPATH = []
