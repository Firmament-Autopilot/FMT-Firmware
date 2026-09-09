################################################################################
# \file A_Clang.mk
#
# \brief
# A_Clang toolchain configuration
#
################################################################################
# \copyright
# (c) 2018-2025, Cypress Semiconductor Corporation (an Infineon company) or
# an affiliate of Cypress Semiconductor Corporation. All rights reserved.
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
################################################################################

ifeq ($(WHICHFILE),true)
$(info Processing $(lastword $(MAKEFILE_LIST)))
endif


################################################################################
# Tools
################################################################################

# The base path to the ARM cross compilation executables
ifneq ($(CY_COMPILER_A_Clang_DIR),)
MTB_TOOLCHAIN_A_Clang__BASE_DIR:=$(CY_COMPILER_A_Clang_DIR)
else
ifneq ($(CY_COMPILER_PATH),)
MTB_TOOLCHAIN_A_Clang__BASE_DIR:=$(CY_COMPILER_PATH)
else
MTB_TOOLCHAIN_A_Clang__BASE_DIR:=/Library/Developer/CommandLineTools/usr/lib/clang/10.0.0
endif
endif


# The base path to the GCC cross compilation executables
ifeq ($(CY_COMPILER_PATH),)
MTB_TOOLCHAIN_A_Clang__BASE_DIR:=$(CY_COMPILER_A_Clang_DIR)
else
MTB_TOOLCHAIN_A_Clang__BASE_DIR:=$(CY_COMPILER_PATH)
endif

# The base path to the Clang cross compilation executables
ifeq ($(TOOLCHAIN),A_Clang)
CY_CROSSPATH:=$(MTB_TOOLCHAIN_A_Clang__BASE_DIR)
endif

# Build tools
MTB_TOOLCHAIN_A_Clang__CC=clang
MTB_TOOLCHAIN_A_Clang__CXX=$(CC)
MTB_TOOLCHAIN_A_Clang__AS=$(CC)
MTB_TOOLCHAIN_A_Clang__AR=libtool
MTB_TOOLCHAIN_A_Clang__LD=ld


################################################################################
# Macros
################################################################################

# Elf to bin conversion tool
MTB_TOOLCHAIN_A_Clang__ELF2BIN=

# Run ELF2BIN conversion
# $(1) : artifact elf
# $(2) : artifact bin
mtb_toolchain_A_Clang__elf2bin=$(error Mach-O to bin not implemented. Cannot convert $1 to $2)


################################################################################
# Options
################################################################################

# DEBUG/NDEBUG selection
ifeq ($(CONFIG),Debug)
_MTB_TOOLCHAIN_A_Clang__DEBUG_FLAG=-DDEBUG
_MTB_TOOLCHAIN_A_Clang__OPTIMIZATION=-Og
else ifeq ($(CONFIG),Release)
_MTB_TOOLCHAIN_A_Clang__DEBUG_FLAG=-DNDEBUG
_MTB_TOOLCHAIN_A_Clang__OPTIMIZATION=-Os
else
_MTB_TOOLCHAIN_A_Clang__DEBUG_FLAG=
_MTB_TOOLCHAIN_A_Clang__OPTIMIZATION=
endif

# Flags common to compile and link
_MTB_TOOLCHAIN_A_Clang__COMMON_FLAGS=\
	-mthumb\
	-ffunction-sections\
	-fdata-sections\
	-g\
	-Wall

# CPU core specifics
ifeq ($(MTB_RECIPE__CORE),CM0)
# Arm Cortex-M0 CPU
_MTB_TOOLCHAIN_A_Clang__FLAGS_CORE=\
	-arch armv6m\
	-mcpu=cortex-m0\
	--target=arm-none-macho

_MTB_TOOLCHAIN_A_Clang__LDFLAGS_CORE=\
	-arch armv6m\
	-lclang_rt.soft_static

_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS=
endif

ifeq ($(MTB_RECIPE__CORE),CM0P)
# Arm Cortex-M0+ CPU
_MTB_TOOLCHAIN_A_Clang__FLAGS_CORE=\
	-arch armv6m\
	-mcpu=cortex-m0plus\
	--target=arm-none-macho

_MTB_TOOLCHAIN_A_Clang__LDFLAGS_CORE=\
	-arch armv6m\
	-lclang_rt.soft_static

_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS=
endif

ifeq ($(MTB_RECIPE__CORE),CM4)
# Arm Cortex-M4 CPU
ifeq ($(VFP_SELECT),hardfp)
_MTB_TOOLCHAIN_A_Clang__LD_VFP_FLAGS=-lclang_rt.hard_static
_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS=-mfloat-abi=hard -mfpu=fpv4-sp-d16
else
_MTB_TOOLCHAIN_A_Clang__LD_VFP_FLAGS=-lclang_rt.soft_static
_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS=-mfloat-abi=softfp -mfpu=fpv4-sp-d16
endif # ($(VFP_SELECT),hardfp)
_MTB_TOOLCHAIN_A_Clang__FLAGS_CORE=\
	-arch armv7em\
	-mcpu=cortex-m4\
	--target=armv7m-none-macho

_MTB_TOOLCHAIN_A_Clang__LDFLAGS_CORE=\
	-arch armv7em\
	$(MTB_TOOLCHAIN_LD_VFP_FLAGS)
endif

ifeq ($(MTB_RECIPE__CORE),CM7)
# Arm Cortex-M7 CPU
ifeq ($(VFP_SELECT),hardfp)
# Hardware fp
_MTB_TOOLCHAIN_A_Clang__LD_VFP_FLAGS=-lclang_rt.hard_static
ifeq ($(VFP_SELECT_PRECISION),singlefp)
# FPv5 FPU, hardfp, single-precision
_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS=-mfloat-abi=hard -mfpu=fpv5-sp-d16
else
# FPv5 FPU, hardfp, double-precision
_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS=-mfloat-abi=hard -mfpu=fpv5-d16
endif
else
# Software fp
_MTB_TOOLCHAIN_A_Clang__LD_VFP_FLAGS=-lclang_rt.soft_static
ifeq ($(VFP_SELECT_PRECISION),singlefp)
# FPv5 FPU, softfp, single-precision
_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS=-mfloat-abi=softfp -mfpu=fpv5-sp-d16
else
# FPv5 FPU, softfp, double-precision
_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS=-mfloat-abi=softfp -mfpu=fpv5-d16
endif
endif # ($(VFP_SELECT),hardfp)
_MTB_TOOLCHAIN_A_Clang__FLAGS_CORE=\
	-arch armv7em\
	-mcpu=cortex-m7\
	--target=armv7m-none-macho
_MTB_TOOLCHAIN_A_Clang__LDFLAGS_CORE=\
	-arch armv7em\
	$(MTB_TOOLCHAIN_LD_VFP_FLAGS)
endif

ifeq ($(TOOLCHAIN),A_Clang)
ifeq ($(MTB_RECIPE__CORE),CM33)
# Arm Cortex-M33 CPU
$(call mtb__error, CPU core-specific flags are not defined for the "$(MTB_RECIPE__CORE)" CPU)
endif

ifeq ($(MTB_RECIPE__CORE),CM55)
# Arm Cortex-M55 CPU
$(call mtb__error, CPU core-specific flags are not defined for the "$(MTB_RECIPE__CORE)" CPU)
endif
endif

# Command line flags for c-files
MTB_TOOLCHAIN_A_Clang__CFLAGS=\
	-c\
	$(_MTB_TOOLCHAIN_A_Clang__FLAGS_CORE)\
	$(_MTB_TOOLCHAIN_A_Clang__OPTIMIZATION)\
	$(_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS)\
	$(_MTB_TOOLCHAIN_A_Clang__COMMON_FLAGS)\
	--no-standard-includes\
	-fasm-blocks\
	-integrated-as\
	-Wall\
	-Wno-int-to-pointer-cast\
	-static\
	-fno-stack-protector\
	-fno-common\
	-ffreestanding\
	-mlong-calls

# Command line flags for cpp-files
MTB_TOOLCHAIN_A_Clang__CXXFLAGS=$(MTB_TOOLCHAIN_A_Clang__CFLAGS)

# Command line flags for s-files
MTB_TOOLCHAIN_A_Clang__ASFLAGS=\
	-c\
	$(_MTB_TOOLCHAIN_A_Clang__FLAGS_CORE)\
	$(_MTB_TOOLCHAIN_A_Clang__VFP_FLAGS)\
	$(_MTB_TOOLCHAIN_A_Clang__COMMON_FLAGS)\
	-fasm-blocks\
	-integrated-as\
	-Wall\
	-Wno-int-to-pointer-cast\
	-static\
	-fno-stack-protector\
	-fno-common\
	-ffreestanding\
	-mlong-calls

# Command line flags for linking
MTB_TOOLCHAIN_A_Clang__LDFLAGS=\
	$(_MTB_TOOLCHAIN_A_Clang__LDFLAGS_CORE)\
	$(_MTB_TOOLCHAIN_A_Clang__LD_VFP_FLAGS)\
	-static\
	-e Reset_Handler\
	-merge_zero_fill_sections\
	-pagezero_size 0\
	-ios_version_min 4.3\
	-preload\
	-v\
	-read_only_relocs suppress\
	-dead_strip\
	-dead_strip_dylibs\
	-no_branch_islands\
	-no_zero_fill_sections\
	-L$(MTB_TOOLCHAIN_A_Clang__BASE_DIR)/lib/macho_embedded

# Command line flags for archiving
MTB_TOOLCHAIN_A_Clang__ARFLAGS=rvs

# Toolchain-specific suffixes
MTB_TOOLCHAIN_A_Clang__SUFFIX_S  :=S
MTB_TOOLCHAIN_A_Clang__SUFFIX_s  :=s
MTB_TOOLCHAIN_A_Clang__SUFFIX_C  :=c
MTB_TOOLCHAIN_A_Clang__SUFFIX_H  :=h
MTB_TOOLCHAIN_A_Clang__SUFFIX_CPP:=cpp
MTB_TOOLCHAIN_A_Clang__SUFFIX_CXX:=cxx
MTB_TOOLCHAIN_A_Clang__SUFFIX_CC :=cc
MTB_TOOLCHAIN_A_Clang__SUFFIX_HPP:=hpp
MTB_TOOLCHAIN_A_Clang__SUFFIX_O  :=o
MTB_TOOLCHAIN_A_Clang__SUFFIX_A  :=a
MTB_TOOLCHAIN_A_Clang__SUFFIX_D  :=d
MTB_TOOLCHAIN_A_Clang__SUFFIX_LS :=mk
MTB_TOOLCHAIN_A_Clang__SUFFIX_MAP:=map
MTB_TOOLCHAIN_A_Clang__SUFFIX_TARGET:=mach_o
MTB_TOOLCHAIN_A_Clang__SUFFIX_PROGRAM:=hex

# Toolchain specific flags
MTB_TOOLCHAIN_A_Clang__OUTPUT_OPTION:=-o
MTB_TOOLCHAIN_A_Clang__ARCHIVE_LIB_OUTPUT_OPTION:=-o
MTB_TOOLCHAIN_A_Clang__MAPFILE:=-map$(MTB__SPACE)
MTB_TOOLCHAIN_A_Clang__LSFLAGS:=
MTB_TOOLCHAIN_A_Clang__INCRSPFILE:=@
MTB_TOOLCHAIN_A_Clang__INCRSPFILE_ASM:=@
MTB_TOOLCHAIN_A_Clang__OBJRSPFILE:=-filelist$(MTB__SPACE)

#
# Produce a makefile dependency rule for each input file
#
MTB_TOOLCHAIN_A_Clang__DEPENDENCIES=-MMD -MP -MF "$(@:.$(MTB_TOOLCHAIN_A_Clang__SUFFIX_O)=.$(MTB_TOOLCHAIN_A_Clang__SUFFIX_D))" -MT "$@"
MTB_TOOLCHAIN_A_Clang__EXPLICIT_DEPENDENCIES=-MMD -MP -MF "$$(@:.$(MTB_TOOLCHAIN_A_Clang__SUFFIX_O)=.$(MTB_TOOLCHAIN_A_Clang__SUFFIX_D))" -MT "$$@"

#
# Additional includes in the compilation process based on this
# toolchain
# NOTE: This includes support for the versions of GCC shipped with ModusToolbox 2.0-2.4
#
MTB_TOOLCHAIN_A_Clang__INCLUDES:=\
	$(MTB_TOOLCHAIN_GCC_ARM__BASE_DIR)/arm-none-eabi/include\
	$(MTB_TOOLCHAIN_GCC_ARM__BASE_DIR)/lib/gcc/arm-none-eabi/7.2.1/include\
	$(MTB_TOOLCHAIN_GCC_ARM__BASE_DIR)/lib/gcc/arm-none-eabi/7.2.1/include-fixed\
	$(MTB_TOOLCHAIN_GCC_ARM__BASE_DIR)/lib/gcc/arm-none-eabi/9.3.1/include\
	$(MTB_TOOLCHAIN_GCC_ARM__BASE_DIR)/lib/gcc/arm-none-eabi/9.3.1/include-fixed\
	$(MTB_TOOLCHAIN_GCC_ARM__BASE_DIR)/lib/gcc/arm-none-eabi/11.3.1/include\
	$(MTB_TOOLCHAIN_GCC_ARM__BASE_DIR)/lib/gcc/arm-none-eabi/11.3.1/include-fixed

#
# Additional libraries in the link process based on this toolchain
#
MTB_TOOLCHAIN_A_Clang__DEFINES:=$(_MTB_TOOLCHAIN_A_Clang__DEBUG_FLAG)

MTB_TOOLCHAIN_A_Clang__VSCODE_INTELLISENSE_MODE:=gcc-arm
MTB_TOOLCHAIN_A_Clang__VSCODE_PROBLEM_MATCHER:=gcc
