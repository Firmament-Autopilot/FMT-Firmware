import os

# board options
BOARD = 'pixhawk4'

# toolchains options
ARCH = 'arm'
CPU = 'cortex-m7'
CROSS_TOOL = 'gcc'

# TARGET='fmt_fmu.elf'

if os.getenv('RTT_CC'):
    CROSS_TOOL = os.getenv('RTT_CC')

# cross_tool provides the cross compiler
# EXEC_PATH is the compiler execute path, for example, CodeSourcery, Keil MDK, IAR
if CROSS_TOOL == 'gcc':
    PLATFORM = 'gcc'
    EXEC_PATH = r'D:\gcc-arm-none-eabi-7-2018-q2-update-win32\bin'
elif CROSS_TOOL == 'keil':
    PLATFORM = 'armcc'
    EXEC_PATH = r'C:/Keil'
elif CROSS_TOOL == 'iar':
    print '================ERROR============================'
    print 'Not support iar yet!'
    print '================================================='
    exit(0)

if os.getenv('RTT_EXEC_PATH'):
    EXEC_PATH = os.getenv('RTT_EXEC_PATH')

print EXEC_PATH
BUILD = ''
# BUILD = 'debug'

if PLATFORM == 'gcc':
    # toolchains
    PREFIX = 'arm-none-eabi-'
    CC = PREFIX + 'gcc'
    AS = PREFIX + 'gcc'
    AR = PREFIX + 'ar'
    LINK = PREFIX + 'gcc'
    TARGET_EXT = 'elf'
    SIZE = PREFIX + 'size'
    OBJDUMP = PREFIX + 'objdump'
    OBJCPY = PREFIX + 'objcopy'

    DEVICE = ' -mcpu=' + CPU + ' -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections'
    # DEFINES = ' -DUSE_HAL_DRIVER -DSTM32F765xx -D__VFP_FP__ -DARM_MATH_MATRIX_CHECK -DARM_MATH_CM7 -DARM_MATH_ROUNDING -D__FPU_PRESENT="1"'
    DEFINES = ' -DUSE_FULL_LL_DRIVER -DSTM32F765xx -D__VFP_FP__ -DARM_MATH_MATRIX_CHECK -DARM_MATH_CM7 -DARM_MATH_ROUNDING -D__FPU_PRESENT="1"'
    CFLAGS = DEVICE + ' -g -Wall -Wstrict-aliasing=0 -Wno-uninitialized -Wno-unused-function' + DEFINES
    CFLAGS += ' -std=c99'
    AFLAGS = ' -c' + DEVICE + ' -x assembler-with-cpp -Wa,-mimplicit-it=thumb '
    LFLAGS = DEVICE + ' -lm -lgcc -lc' + \
        ' -nostartfiles -Wl,--gc-sections,-Map=build/fmt_fmu.map,-cref,-u,Reset_Handler -T link.lds'

    CPATH = ''
    LPATH = ''

    if BUILD == 'debug':
        CFLAGS += ' -O0 -gdwarf-2'
        AFLAGS += ' -gdwarf-2'
    else:
        CFLAGS += ' -O2'

    POST_ACTION = OBJCPY + ' -O binary $TARGET build/fmt_fmu.bin\n' + SIZE + ' $TARGET \n'
    # POST_ACTION += 'python px_mkfw.py --prototype px4fmu-v2.prototype --git_identity ../../.. --image fmt_fmu.bin \n'

elif PLATFORM == 'armcc':
    # toolchains
    CC = 'armcc'
    AS = 'armasm'
    AR = 'armar'
    LINK = 'armlink'
    TARGET_EXT = 'axf'

    DEVICE = ' --cpu=cortex-m4.fp'
    CFLAGS = DEVICE + ' --apcs=interwork -DUSE_STDPERIPH_DRIVER -DSTM32F40_41xxx'
    AFLAGS = DEVICE
    LFLAGS = DEVICE + ' --info sizes --info totals --info unused --info veneers --list starry_fmu.map --scatter stm32_rom.sct'

    CFLAGS += ' -I' + EXEC_PATH + '/ARM/RV31/INC'
    LFLAGS += ' --libpath ' + EXEC_PATH + '/ARM/RV31/LIB'

    EXEC_PATH += '/arm/bin40/'

    if BUILD == 'debug':
        CFLAGS += ' -g -O0'
        AFLAGS += ' -g'
    else:
        CFLAGS += ' -O2'

    POST_ACTION = 'fromelf --bin $TARGET --output starry_fmu.bin \nfromelf -z $TARGET'

elif PLATFORM == 'iar':
    print '================ERROR============================'
    print 'Not support iar yet!'
    print '================================================='
    exit(0)
