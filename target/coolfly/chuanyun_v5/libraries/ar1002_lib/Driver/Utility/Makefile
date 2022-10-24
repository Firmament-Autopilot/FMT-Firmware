# top file directory
TOP_DIR ?= ../../..

# build file directory
BUILD_DIR ?= $(TOP_DIR)/Build

# binary file director
OUTPUT_DIR ?= $(TOP_DIR)/Output
OUTPUT_HEADER_STAGING_DIR ?= $(OUTPUT_DIR)/Staging/Inc
OUTPUT_LIB_STAGING_DIR ?= $(OUTPUT_DIR)/Staging/Lib

# current directory
CURDIR ?= $(shell pwd)

include $(BUILD_DIR)/config.mk

###############################################################################
# static library name
LIB = libutility.a

ifeq ($(CPU_NUMBER), cpu0)
    CFLAGS += $(CPU0_COMPILE_FLAGS)
    # LD_LIBS += -lfreertos
endif

ifeq ($(CPU_NUMBER), cpu1)
    CFLAGS += $(CPU1_COMPILE_FLAGS)
    # LD_LIBS += -lfreertos
endif

ifeq ($(CPU_NUMBER), cpu2)
    CFLAGS += $(CPU2_COMPILE_FLAGS)
    # LD_LIBS += -lfreertos
endif

# source file(s), including c file(s)
SRC_C   := Src/wireless_interface.c \
		   Src/upgrade.c \
		   Src/factory_load.c \
		   Src/factory_save.c \
		   Src/image.c

INCDIRS :=  -IInc \
            -I$(TOP_DIR)/Configure/Include \
            -I$(TOP_DIR)/Driver/HAL/Inc \
            -I$(TOP_DIR)/Library/Artosyn/Common/Inc \
            -I$(TOP_DIR)/Driver/Chip/AR8020/BB/Inc \
            -I$(TOP_DIR)/Driver/Chip/AR8020/SPI/Inc \
            -I$(TOP_DIR)/Driver/Chip/AR8020/QuadSPI/Inc \
            -I$(TOP_DIR)/Driver/Chip/AR8020/SysCtl/Inc \
            -I$(TOP_DIR)/Driver/Chip/AR8020/EFUSE/Inc \
            -I$(TOP_DIR)/Kernel/FreeRTOS/CMSIS_RTOS \
            -I$(TOP_DIR)/Library/ThirdParty/CMSIS/Include \
            -I$(TOP_DIR)/Library/ThirdParty/FatFs/Inc/ \
            -I$(TOP_DIR)/Kernel/FreeRTOS/include \
            -I$(TOP_DIR)/Kernel/FreeRTOS/portable/GCC/ARM_CM7/r0p1 \
            -I$(TOP_DIR)/Driver/Board/Common/NORFlash/Inc \
            -I$(TOP_DIR)/Driver/Board/Common/WatchDog/Inc \
            -I$(TOP_DIR)/Driver/Board \
            -I$(OUTPUT_HEADER_STAGING_DIR)




# object file(s)
OBJ_C   := $(patsubst %.c,%.o,$(SRC_C))

all: .depend $(LIB) install

$(LIB):  $(OBJ_C) 
	@echo "Generating static library: $(CPU_NUMBER) " $(notdir $@)
	@$(AR) $(ARFLAGS) $@ $^

install:
	@mkdir -p $(OUTPUT_LIB_STAGING_DIR)/$(CPU_NUMBER)
	@mkdir -p $(OUTPUT_HEADER_STAGING_DIR)
	@cp -f $(LIB) $(OUTPUT_LIB_STAGING_DIR)/$(CPU_NUMBER)
	@cp -f Inc/wireless_interface.h $(OUTPUT_HEADER_STAGING_DIR)
	@cp -f Inc/upgrade.h $(OUTPUT_HEADER_STAGING_DIR)
	@cp -f Inc/factory.h $(OUTPUT_HEADER_STAGING_DIR)

clean:
	@echo "Cleaning..."
	@$(RM) $(LIB) $(OBJ_C) $(OBJ_CPP) .depend $(OUTPUT_LIB_STAGING_DIR)/$(CPU_NUMBER)/$(LIB) $(OUTPUT_HEADER_STAGING_DIR)/wireless_interface.h

.PHONY: all clean install
#########################################################################

include $(BUILD_DIR)/rules.mk

sinclude .depend

#########################################################################

