# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    'icm20689/icm20689.c',
    'ms5611/ms5611.c',
    'bmi055/bmi055.c',
    'ist8310/ist8310.c',
    'rgb_led/ncp5623c.c',
    'gps/*.c',
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
    'fmtio_dev/*.c',
    'motor/*.c',
    'actuator/*.c',
    'rc/*.c',
    'gps/*.c',
    'adc/*.c',
]

HAL_CPPPATH = []

MODULES = [
    'calibration/*.c',
    'console/*.c',
    'system/*.c',
    'ipc/*.c',
    'syscmd/*.c',
    'file_manager/*.c',
    'ftp/*.c',
    'plant/*.c',
    'plant/lib/*.c',
    'ins/*.c',
    'ins/lib/*.c',
    'control/*.c',
    'control/lib/*.c',
    'fms/*.c',
    'fms/lib/*.c',
    "log/*.c",
    "param/*.c",
    'utils/*.c',
    'mavproxy/*.c',
    'sensor/*.c',
    'sysIO/*.c',
    'toml/*.c',
    'workqueue/*.c',
    'math/*.c',
    'filter/*.c',
    'fmtio/*.c',
    'task_manager/*.c',
    'pmu/*.c',
]

MODULES_CPPPATH = [
    'calibration',
    'ins/lib',
    'plant/lib',
    'control/lib',
    'fms/lib',
]

TASKS = [
    'simple/*.c',
    'comm/*.c',
    'logger/*.c',
    'fmtio/*.c',
    'status/*.c',
    'vehicle/multicopter/*.c',
]

TASKS_CPPPATH = []

LIBS = [
    'cm_backtrace',
    'mavlink',
]
