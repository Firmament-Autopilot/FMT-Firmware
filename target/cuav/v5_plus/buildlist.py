# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    'imu/icm20689/*.c',
    'imu/bmi055/*.c',
    'mag/ist8310/*.c',
    'barometer/ms5611/*.c',
    'gps/m8n/*.c',
    'rgb_led/ncp5623c/*.c',
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
    'plant/multicopter/*.c',
    'plant/multicopter/lib/*.c',
    'ins/base_ins/*.c',
    'ins/base_ins/lib/*.c',
    'control/base_controller/*.c',
    'control/base_controller/lib/*.c',
    'fms/base_fms/*.c',
    'fms/base_fms/lib/*.c',
    "log/*.c",
    "param/*.c",
    'utils/*.c',
    'mavproxy/*.c',
    'sensor/*.c',
    'sysio/*.c',
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
    'ins/base_ins/lib',
    'plant/multicopter/lib',
    'control/base_controller/lib',
    'fms/base_fms/lib',
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
