# Modify this file to decide which module are compiled

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
    'filter/*.c',
    'toml/*.c',
    'workqueue/*.c',
    'task_manager/*.c',
    'pmu/*.c',
]

MODULES_CPPPATH = [
    'calibration',
]