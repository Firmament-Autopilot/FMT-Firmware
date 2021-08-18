# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    'gps/*.c',
    'hmc5883/*.c',
    'hw_timer/*.c',
    'l3gd20h/*.c',
    'lidar/*.c',
    'lsm303d/*.c',
    'mpu6000/*.c',
    'ms5611/*.c',
    'tca62724/*.c',
    'mateksys/*.c',
]

DRIVERS_CPPPATH = []

HAL = [
    '*.c',
    'mag/*.c',
    'accel/*.c',
    'barometer/*.c',
    'gps/*.c',
    'fmtio_dev/*.c',
    'gyro/*.c',
    'i2c/*.c',
    'actuator/*.c',
    'pin/*.c',
    'rc/*.c',
    'serial/*.c',
    'systick/*.c',
    'usb/*.c',
    'optical_flow/*.c',
    'spi/*.c',
    'adc/*.c',
]

HAL_CPPPATH = []

MODULES = [
    'calibration/*.c',
    'console/*.c',
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
    'ipc/*.c',
    'led/*.c',
    'log/*.c',
    'math/*.c',
    'mavproxy/*.c',
    'param/*.c',
    'sensor/*.c',
    'fmtio/*.c',
    'sysio/*.c',
    'syscmd/*.c',
    'system/*.c',
    'utils/*.c',
    'buzzer/*.c',
    'filter/*.c',
    'toml/*.c',
    'workqueue/*.c',
    'task_manager/*.c',
    'pmu/*.c',
]

MODULES_CPPPATH = [
    'calibration',
    'ins/lib',
    'plant/lib',
    'control/lib',
    'fms/lib',
    'buzzer',
]

TASKS = [
    'vehicle/multicopter/*.c',
    'comm/*.c',
    'logger/*.c',
    'fmtio/*.c',
    'status/*.c',
]

TASKS_CPPPATH = []

LIBS = [
    'cm_backtrace',
    'mavlink',
    'Micro-XRCE-DDS-Client',
]
