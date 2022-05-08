import os
from SCons.Script.Main import *

# board options
BOARD = 'qemu-vexpress-a9'

# toolchains options
ARCH = 'arm'
CPU='cortex-a'
CROSS_TOOL = 'gcc'
# build version: debug or release
BUILD = 'debug'

if os.getenv('RTT_CC'):
    CROSS_TOOL = os.getenv('RTT_CC')

# only support GNU GCC compiler.
PLATFORM    = 'gcc'
EXEC_PATH   = 'your-compiler-path'

if os.getenv('RTT_EXEC_PATH'):
    EXEC_PATH = os.getenv('RTT_EXEC_PATH')

if PLATFORM == 'gcc':
    # toolchains
    PREFIX = 'arm-none-eabi-'
    CC = PREFIX + 'gcc'
    CXX = PREFIX + 'g++'
    AS = PREFIX + 'gcc'
    AR = PREFIX + 'ar'
    LINK = PREFIX + 'gcc'
    TARGET_EXT = 'elf'
    SIZE = PREFIX + 'size'
    OBJDUMP = PREFIX + 'objdump'
    OBJCPY = PREFIX + 'objcopy'
    STRIP = PREFIX + 'strip'

    DEVICE = ' -march=armv7-a -marm -msoft-float'
    CFLAGS = DEVICE + ' -Wall -Wno-switch'
    AFLAGS = ' -c' + DEVICE + ' -x assembler-with-cpp -D__ASSEMBLY__ -I.'
    LINK_SCRIPT = 'link.lds'
    LFLAGS = DEVICE + ' -nostartfiles -Wl,--gc-sections,-Map=build/fmt_fmu.map,-cref,-u,system_vectors'+\
                      ' -T %s' % LINK_SCRIPT

    CPATH = ''
    LPATH = ''

    if BUILD == 'debug':
        CFLAGS += ' -O0 -gdwarf-2'
        AFLAGS += ' -gdwarf-2'
    else:
        CFLAGS += ' -O2'

    if GetOption('PX4_ECL'):
        CFLAGS += ' -DFMT_USING_PX4_ECL'
        CXXFLAGS = CFLAGS + ' -fno-exceptions -fno-rtti' #-Woverloaded-virtual
    else:
        CXXFLAGS = CFLAGS + ' -Woverloaded-virtual -fno-exceptions -fno-rtti'

    # CXXFLAGS = CFLAGS + ' -Woverloaded-virtual -fno-exceptions -fno-rtti'

    M_CFLAGS = CFLAGS + ' -mlong-calls -fPIC '
    M_CXXFLAGS = CXXFLAGS + ' -mlong-calls -fPIC'
    M_LFLAGS = DEVICE + CXXFLAGS + ' -Wl,--gc-sections,-z,max-page-size=0x4' +\
                                    ' -shared -fPIC -nostartfiles -nostdlib -static-libgcc'
    M_POST_ACTION = STRIP + ' -R .hash $TARGET\n' + SIZE + ' $TARGET \n'

    POST_ACTION = OBJCPY + ' -O binary $TARGET build/fmt_fmu.bin\n' +\
                  SIZE + ' $TARGET \n'
