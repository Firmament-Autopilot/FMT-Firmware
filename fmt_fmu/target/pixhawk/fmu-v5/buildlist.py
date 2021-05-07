# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    # 'gpio/*.c',
    # 'systick/st/stm32f7_systick.c',
    #'usart/st/stm32f7_usart.c',
    'icm20689/icm20689.c',
    'ms5611/ms5611.c',
    'bmi055/bmi055.c',
    'ist8310/ist8310.c',
    'rgb_led/ncp5623c.c',
]

DRIVERS_CPPPATH = []

HAL = [
    'pin/*.c',
    'serial/*.c',
    'systick/*.c',
    'sd/*.c',
    'usb/usbd_cdc.c',
    'spi/spi_core.c',
    'spi/spi_dev.c',
    'i2c/*.c',
    'gyro/*.c',
    'accel/*.c',
    'mag/*.c',
    'barometer/*.c',
]

HAL_CPPPATH = []

MODULES = [
    'Calibration/*.c',
    'Console/*.c',
    'System/*.c',
    'IPC/*.c',
    'SysCmd/syscmd.c',
    'SysCmd/cmd_sys.c',
    'SysCmd/cmd_mcn.c',
    'SysCmd/cmd_param.c',
    'SysCmd/cmd_test.c',
    'SysCmd/cmd_reboot.c',
    'File_Manager/*.c',
    'FTP/*.c',
    'Plant/*.c',
    'Plant/lib/*.c',
    'INS/*.c',
    'INS/lib/*.c',
    'Controller/*.c',
    'Controller/lib/*.c',
    'FMS/*.c',
    'FMS/lib/*.c',
    "Log/*.c",
    "Parameter/*.c",
    'Utils/*.c',
    'Mavproxy/*.c',
    'Sensor/*.c',
    'SysIO/*.c',
    'TOML/*.c',
    'WorkQueue/*.c',
    'Math/*.c',
    'Filter/*.c',
]

MODULES_CPPPATH = [
    'Calibration',
    'INS/lib',
    'Plant/lib',
    'Controller/lib',
    'FMS/lib',
]

TASKS = [
    'simple/*.c',
    'comm/*.c',
    'vehicle/multicopter/*.c',
]

TASKS_CPPPATH = []

LIBS = [
    'cm_backtrace',
    'mavlink',
    'printf',
]
