# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    # 'gpio/*.c',
    # 'systick/st/stm32f7_systick.c',
    #'usart/st/stm32f7_usart.c',
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
    "Log/boot_log.c",
    "Parameter/*.c",
    'Utils/*.c',
    'Mavproxy/*.c',
    'Sensor/*.c',
    'SysIO/*.c',
    'TOML/*.c',
    'WorkQueue/*.c',
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
]

TASKS_CPPPATH = []

LIBS = [
    'cm_backtrace',
    'mavlink'
]
