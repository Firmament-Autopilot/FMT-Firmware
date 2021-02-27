# Build Lists
# Modify this file to control which files/modules should be built

DRIVERS = [
    # 'gpio/*.c',
    # 'systick/st/stm32f7_systick.c',
    #'usart/st/stm32f7_usart.c',
]

DRIVERS_CPPPATH = []

HAL = [
    'pin/*.c',
    'serial/*.c',
    'systick/*.c',
]

HAL_CPPPATH = []

MODULES = [
    'Console/*.c',
    'System/*.c',
    'IPC/*.c',
    'SysCmd/syscmd.c',
    'SysCmd/cmd_sys.c',
    'SysCmd/cmd_mcn.c',
]

MODULES_CPPPATH = []

LIBS = [
    'stm_lib/stm32f7',
    'cm_backtrace',
]
