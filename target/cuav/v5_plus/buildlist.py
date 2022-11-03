# Build Lists
# Modify this file to control which files/modules should be built
from building import *

DRIVERS = [
    'imu/icm20689.c',
    'imu/bmi055.c',
    'mag/ist8310.c',
    'barometer/ms5611.c',
    'gps/gps_m8n.c',
    'rgb_led/ncp5623c.c',
    'mtd/ramtron.c',
    'vision_flow/pmw3901_fl04.c',
    'airspeed/ms4525.c',
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
    'fmtio/*.c',
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
    'fmtio/*.c',
    'status/*.c',
    'vehicle/multicopter/*.c',
]

TASKS_CPPPATH = []

vehicle_type = GetConfigValue('VEHICLE_TYPE')
if vehicle_type == '"Quadcopter"':
    MODELS = [
        'plant/multicopter',
        'ins/base_ins',
        'fms/base_fms',
        'control/base_controller',
    ]
elif vehicle_type == '"Fixwing"':
    MODELS = [
        'plant/template_plant',
        'ins/base_ins',
        'fms/fw_fms',
        'control/fw_controller',
    ]
elif vehicle_type == '"Template"':
    MODELS = [
        'plant/template_plant',
        'ins/template_ins',
        'fms/template_fms',
        'control/template_controller',
    ]
else:
    raise Exception("Wrong VEHICLE_TYPE %s defined" % vehicle_type)

LIBS = [
    'cm_backtrace',
    'mavlink',
]
