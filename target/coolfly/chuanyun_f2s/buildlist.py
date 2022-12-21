# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    'imu/icm20600.c',
    # 'imu/icm20689.c',
    # 'imu/bmi055.c',
    'imu/bmi088.c',
    # 'mag/ist8310.c',
    'mag/mmc5983ma.c',
    # 'barometer/ms5611.c',
    'barometer/spl06.c',
    'gps/gps_m8n.c',
    'rgb_led/ncp5623c.c',
    'mtd/ramtron.c',
    'vision_flow/pmw3901_fl04.c',
    # 'vision_flow/lc307.c',
    'range_finder/tfmini_s.c',
    'airspeed/ms4525.c',
    'tfcard/spi_tfcard.c',
]

DRIVERS_CPPPATH = []

HAL = [
    'pin/*.c',
    'serial/*.c',
    'systick/*.c',
    # 'sd/*.c',
    'usb/usbd_cdc.c',
    'spi/spi_core.c',
    'spi/spi_dev.c',
    'spi/spi_msd.c',
    'i2c/*.c',
    'gyro/*.c',
    'accel/*.c',
    'mag/*.c',
    'barometer/*.c',
    # 'fmtio_dev/*.c',
    'motor/*.c',
    'actuator/*.c',
    'rc/*.c',
    'gps/*.c',
    'adc/*.c',
    'mtd/*.c',
    'airspeed/*.c',
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
    # 'fmtio/*.c',
    'task_manager/*.c',
    'pmu/*.c',
]

MODULES_CPPPATH = [
    'calibration',
]

TASKS = [
    'simple/*.c',
    'comm/*.c',
    'logger/*.c',
    # 'fmtio/*.c',
    'status/*.c',
    'vehicle/multicopter/*.c',
]

TASKS_CPPPATH = []

MODELS = [
    'plant/multicopter',
    'ins/base_ins',
    'fms/base_fms',
    'control/base_controller',
]

LIBS = [
    'cm_backtrace',
    'mavlink',
]
