# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
]

DRIVERS_CPPPATH = []

HAL = [
    'serial/*.c',
    'systick/*.c',
    'sd/*.c',
    'usb/usbd_cdc.c',
]

HAL_CPPPATH = []

MODULES = [
    'calibration/*.c',
    'console/*.c',
    'system/*.c',
    'ipc/*.c',
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
    'task_manager/*.c',
    'file_manager/*.c',
    'pmu/*.c',
    'syscmd/optparse.c',
    'syscmd/syscmd.c',
    'syscmd/cmd_mlog.c',
    'syscmd/cmd_boot_log.c',
    'syscmd/cmd_mcn.c',
    'syscmd/cmd_param.c',
    'syscmd/cmd_ps.c',
    'syscmd/cmd_test.c',
]

MODULES_CPPPATH = [
    'calibration',
]

TASKS = [
    'comm/*.c',
    'logger/*.c',
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
    'mavlink',
]
