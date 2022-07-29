import os

# board options
BOARD = 'pixhawk4'

# toolchains options
ARCH = 'arm'
CPU = 'cortex-m7'
CROSS_TOOL = 'gcc'
# build version: debug or release
BUILD = 'release'
from kconfig import BUILD

if os.getenv('RTT_CC'):
    CROSS_TOOL = os.getenv('RTT_CC')

# cross_tool provides the cross compiler
# EXEC_PATH is the compiler execute path, for example, CodeSourcery, Keil MDK, IAR
if CROSS_TOOL == 'gcc':
    PLATFORM = 'gcc'
    EXEC_PATH = 'your-compiler-path'
else:
    print('================ERROR============================')
    print('Not support %s yet!' % CROSS_TOOL)
    print('=================================================')
    exit(0)

if os.getenv('RTT_EXEC_PATH'):
    EXEC_PATH = os.getenv('RTT_EXEC_PATH')

if PLATFORM == 'gcc':
    # toolchains
    PREFIX = 'arm-none-eabi-'
    CC = PREFIX + 'gcc'
    AS = PREFIX + 'gcc'
    AR = PREFIX + 'ar'
    CXX = PREFIX + 'g++'
    LINK = PREFIX + 'gcc'
    TARGET_EXT = 'elf'
    SIZE = PREFIX + 'size'
    OBJDUMP = PREFIX + 'objdump'
    OBJCPY = PREFIX + 'objcopy'

    DEVICE = ' -mcpu=' + CPU + \
        ' -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections'
    DEFINES = ' -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32F765xx -D__VFP_FP__ -DARM_MATH_MATRIX_CHECK -DARM_MATH_CM7 -DARM_MATH_ROUNDING -D__FPU_PRESENT="1"'
    CFLAGS = DEVICE + \
        ' -g -Wall -Wstrict-aliasing=0 -Wno-uninitialized -Wno-unused-function -Wno-switch' + DEFINES
    AFLAGS = ' -c' + DEVICE + ' -x assembler-with-cpp -Wa,-mimplicit-it=thumb '
    LFLAGS = DEVICE + ' -lm -lgcc -lc' + \
        ' -nostartfiles -Wl,--gc-sections,-Map=build/fmt_fmuv5.map,-cref,-u,Reset_Handler -T link.lds'

    CPATH = ''
    LPATH = ''

    if BUILD == 'debug':
        CFLAGS += ' -O0 -gdwarf-2'
        AFLAGS += ' -gdwarf-2'
    else:
        CFLAGS += ' -O2'

    CXXFLAGS = CFLAGS
    CFLAGS += ' -std=c99'
    CXXFLAGS += ' -std=c++14'

    POST_ACTION = OBJCPY + ' -O binary $TARGET build/fmt_fmuv5.bin\n' + SIZE + ' $TARGET \n'
