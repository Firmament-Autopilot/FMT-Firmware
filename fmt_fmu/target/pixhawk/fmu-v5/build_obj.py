# Build object lists

DRIVERS = [
    # 'gpio/*.c',
    # 'systick/st/stm32f7_systick.c',
    #'usart/st/stm32f7_usart.c',
]

DRIVERS_CPPPATH = []

HAL = [
    'pin/*.c',
    'serial/*.c',
    # 'systick/*.c',
]

HAL_CPPPATH = []

MODULES = [
    'Console/*.c',
    'System/*.c',
]

MODULES_CPPPATH = []

LIBS = [
    'stm_lib/stm32f7'
]
