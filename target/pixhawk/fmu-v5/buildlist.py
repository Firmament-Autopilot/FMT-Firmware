# Build Lists
# Modify this file to control which files/modules should be built

from SCons.Script.Main import *

DRIVERS = [
    'imu/icm20689.c',
    'imu/bmi055.c',
    'mag/ist8310.c',
    'barometer/ms5611.c',
    'gps/gps_m8n.c',
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

MODELS = [
    'plant/multicopter/*.c',
    'plant/multicopter/lib/*.c',
    'ins/base_ins/*.c',
    'ins/base_ins/lib/*.c',
    'fms/base_fms/*.c',
    'fms/base_fms/lib/*.c',
    'control/base_controller/*.c',
    'control/base_controller/lib/*.c',
]

MODELS_CPPPATH = [
    'plant/multicopter/lib',
    'ins/base_ins/lib',
    'fms/base_fms/lib',
    'control/base_controller/lib',
]

if GetOption('PX4_ECL'):
    MODELS_PX4_ECL =['px4_ecl/PX4_ECL/airdata/*.cpp',
                    'px4_ecl/PX4_ECL/AlphaFilter/*.cpp',
                    'px4_ecl/PX4_ECL/EKF/*.cpp',
                    'px4_ecl/PX4_ECL/geo/*.cpp',
                    'px4_ecl/PX4_ECL/geo_lookup/*.cpp',
                    'px4_ecl/PX4_ECL/mathlib/*.cpp',
                    'px4_ecl/PX4_ECL/matrix/*.cpp',
                    'px4_ecl/interface/*.cpp',
                    'px4_ecl/interface/*.c']
    MODELS_CPPPATH_PX4_ECL = ['px4_ecl/PX4_ECL',
                            'px4_ecl/PX4_ECL/airdata',
                            'px4_ecl/PX4_ECL/AlphaFilter',
                            'px4_ecl/PX4_ECL/EKF',
                            'px4_ecl/PX4_ECL/geo',
                            'px4_ecl/PX4_ECL/geo_lookup',
                            'px4_ecl/PX4_ECL/mathlib',
                            'px4_ecl/PX4_ECL/matrix',
                            'px4_ecl/interface']

if GetOption('clean'):
    MODELS +=['px4_ecl/PX4_ECL/airdata/*.cpp',
             'px4_ecl/PX4_ECL/AlphaFilter/*.cpp',
             'px4_ecl/PX4_ECL/EKF/*.cpp',
             'px4_ecl/PX4_ECL/geo/*.cpp',
             'px4_ecl/PX4_ECL/geo_lookup/*.cpp',
             'px4_ecl/PX4_ECL/mathlib/*.cpp',
             'px4_ecl/PX4_ECL/matrix/*.cpp',
             'px4_ecl/interface/*.cpp',
             'px4_ecl/interface/*.c']
    MODELS_CPPPATH += ['px4_ecl/PX4_ECL',
                      'px4_ecl/PX4_ECL/airdata',
                      'px4_ecl/PX4_ECL/AlphaFilter',
                      'px4_ecl/PX4_ECL/EKF',
                      'px4_ecl/PX4_ECL/geo',
                      'px4_ecl/PX4_ECL/geo_lookup',
                      'px4_ecl/PX4_ECL/mathlib',
                      'px4_ecl/PX4_ECL/matrix',
                      'px4_ecl/interface']

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
