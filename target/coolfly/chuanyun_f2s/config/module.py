# Modify this file to decide which module are compiled

MODULES = [
    # 'calibration/*.c',
    'console/*.c',
    'system/*.c',
    'ipc/*.c',
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
    'task_manager/*.c',
    'pmu/*.c',
]

MODULES += [
    'syscmd/optparse.c',
    'syscmd/syscmd.c',
    'syscmd/cmd_act.c',
    'syscmd/cmd_adc.c',
    'syscmd/cmd_boot_log.c',
    'syscmd/cmd_mcn.c',
    'syscmd/cmd_mlog.c',
    'syscmd/cmd_param.c',
    'syscmd/cmd_ps.c',
    'syscmd/cmd_calib.c',
    'syscmd/cmd_rc.c',
    'syscmd/cmd_task.c',
    'syscmd/cmd_test.c',
]

MODULES_CPPPATH = [
    'calibration',
]
