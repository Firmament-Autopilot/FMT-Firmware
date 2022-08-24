# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    # 'imu/icm20689.c',
    # 'imu/bmi055.c',
    # 'mag/ist8310.c',
    # 'barometer/ms5611.c',
    # 'gps/gps_m8n.c',
    # 'rgb_led/ncp5623c.c',
    # 'mtd/ramtron.c',
]

DRIVERS_CPPPATH = []

HAL = [
    # 'pin/*.c',
    'serial/*.c',
    'systick/*.c',
    'sd/*.c',
    'usb/usbd_cdc.c',
    'spi/*.c',
    'i2c/*.c',
    # 'gyro/*.c',
    # 'accel/*.c',
    # 'mag/*.c',
    # 'barometer/*.c',
    # 'fmtio_dev/*.c',
    'actuator/*.c',
    'rc/*.c',
    # 'gps/*.c',
    # 'adc/*.c',
    # 'mtd/*.c',
]

HAL_CPPPATH = []

MODULES = [
    'calibration/*.c',
    'console/*.c',
    'system/*.c',
    'ipc/*.c',
    # 'syscmd/*.c',
    'syscmd/optparse.c',
    'syscmd/syscmd.c',
    'syscmd/cmd_ps.c',
    'syscmd/cmd_test.c',
    'syscmd/cmd_param.c',
    'syscmd/cmd_boot_log.c',
    'syscmd/cmd_mcn.c',
    'syscmd/cmd_act.c',
    # 'syscmd/cmd_mlog.c',
    'file_manager/*.c',
#     'ftp/*.c',
    "log/*.c",
    "param/*.c",
    'utils/*.c',
    'mavproxy/*.c',
#     'sensor/*.c',
    'sysio/*.c',
    'toml/*.c',
    'workqueue/*.c',
    'math/*.c',
#     'filter/*.c',
#     'fmtio/*.c',
    'task_manager/*.c',
#     'pmu/*.c',
]

MODULES_CPPPATH = [
    'calibration',
]

TASKS = [
    # 'simple/*.c',
    # 'comm/*.c',
    # 'logger/*.c',
    # 'fmtio/*.c',
    # 'status/*.c',
    # 'vehicle/multicopter/*.c',
]

TASKS_CPPPATH = []

MODELS = [
    # 'plant/multicopter',
    'ins/template_ins',
    'fms/template_fms',
    'control/template_controller',
]

LIBS = [
    # 'cm_backtrace',
    'mavlink',
]
