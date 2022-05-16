# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    'imu/l3gd20h.c',
    'imu/lsm303d.c',
    'imu/mpu6000.c',
    'mag/hmc5883.c',
    'barometer/ms5611.c',
    'gps/gps_m8n.c',
    'vision_flow/pmw3901_l0x.c',
    'rgb_led/tca62724.c',
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
