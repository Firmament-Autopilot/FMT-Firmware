# Modify this file to decide which module are compiled

MODULES = [
    'console/*.c',
    'system/*.c',
    'toml/*.c',
    'task_manager/*.c',
    'file_manager/*.c',
]

MODULES += [
    'syscmd/optparse.c',
    'syscmd/syscmd.c',
    'syscmd/cmd_ps.c',
]

MODULES_CPPPATH = [
]