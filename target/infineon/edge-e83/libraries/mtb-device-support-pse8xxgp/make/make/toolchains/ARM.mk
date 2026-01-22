############################################################################### 
# \file ARM.mk
#
# \brief
# ARM Compiler (Clang) toolchain configuration.
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
ifneq ($(CY_COMPILER_ARM_DIR),)
MTB_TOOLCHAIN_ARM__BASE_DIR:=$(call mtb_core__escaped_path,$(CY_COMPILER_ARM_DIR))
else
ifneq ($(CY_COMPILER_PATH),)
MTB_TOOLCHAIN_ARM__BASE_DIR:=$(call mtb_core__escaped_path,$(CY_COMPILER_PATH))
else
MTB_TOOLCHAIN_ARM__BASE_DIR:=C:/Program\ Files/ARMCompiler6.16
ifneq ($(filter $(MAKECMDGOALS), build build_proj qbuild qbuild_proj all program program_proj uvision uvision5),)
$(info Note: The CY_COMPILER_ARM_DIR is not set. The default path of the ARM toolchain is $(MTB_TOOLCHAIN_ARM__BASE_DIR).\
If it is not correct, set the CY_COMPILER_ARM_DIR variable to the location of the ARM toolchain directory.)
$(info Note: The feature of setting the default location of the ARM toolchain has been deprecated.\
It will be removed in the next minor release. Set the CY_COMPILER_ARM_DIR variable to the location\
of the ARM toolchain directory.)
endif
endif
endif

# The base path to the Clang cross compilation executables
ifeq ($(TOOLCHAIN),ARM)
CY_CROSSPATH:=$(MTB_TOOLCHAIN_ARM__BASE_DIR)
endif

# Build tools
MTB_TOOLCHAIN_ARM__CC :=$(MTB_TOOLCHAIN_ARM__BASE_DIR)/bin/armclang
MTB_TOOLCHAIN_ARM__CXX:=$(MTB_TOOLCHAIN_ARM__CC)
MTB_TOOLCHAIN_ARM__AS_LC :=$(MTB_TOOLCHAIN_ARM__BASE_DIR)/bin/armasm
MTB_TOOLCHAIN_ARM__AS_UC :=$(MTB_TOOLCHAIN_ARM__BASE_DIR)/bin/armclang
MTB_TOOLCHAIN_ARM__AR :=$(MTB_TOOLCHAIN_ARM__BASE_DIR)/bin/armar
MTB_TOOLCHAIN_ARM__LD :=$(MTB_TOOLCHAIN_ARM__BASE_DIR)/bin/armlink

################################################################################
# Macros
################################################################################

# Elf to bin conversion tool
MTB_TOOLCHAIN_ARM__ELF2BIN:=$(MTB_TOOLCHAIN_ARM__BASE_DIR)/bin/fromelf

# Run ELF2BIN conversion
# $(1) : artifact elf
# $(2) : artifact bin
mtb_toolchain_ARM__elf2bin=$(MTB_TOOLCHAIN_ARM__ELF2BIN) --output $2 --bin $1


################################################################################
# Options
################################################################################

# DEBUG/NDEBUG selection
ifeq ($(CONFIG),Debug)
_MTB_TOOLCHAIN_ARM__DEBUG_FLAG:=-DDEBUG
_MTB_TOOLCHAIN_ARM__OPTIMIZATION:=-O1 -fno-omit-frame-pointer
else
ifeq ($(CONFIG),Release)
_MTB_TOOLCHAIN_ARM__DEBUG_FLAG:=-DNDEBUG
_MTB_TOOLCHAIN_ARM__OPTIMIZATION:=-Oz
else
_MTB_TOOLCHAIN_ARM__DEBUG_FLAG:=
_MTB_TOOLCHAIN_ARM__OPTIMIZATION:=
endif
endif

# Flags common to compile and link
_MTB_TOOLCHAIN_ARM__COMMON_FLAGS:=--target=arm-arm-none-eabi

# CPU core specifics
ifeq ($(MTB_RECIPE__CORE),CM0)
# Arm Cortex-M0 CPU
_MTB_TOOLCHAIN_ARM__CFLAGS_CORE:=-mcpu=cortex-m0
_MTB_TOOLCHAIN_ARM__FLAGS_CORE:=--cpu=Cortex-M0
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=
endif

ifeq ($(MTB_RECIPE__CORE),CM0P)
# Arm Cortex-M0+ CPU
_MTB_TOOLCHAIN_ARM__CFLAGS_CORE:=-mcpu=cortex-m0plus
_MTB_TOOLCHAIN_ARM__FLAGS_CORE:=--cpu=Cortex-M0plus
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=
endif

ifeq ($(MTB_RECIPE__CORE),CM4)
# Arm Cortex-M4 CPU
_MTB_TOOLCHAIN_ARM__CFLAGS_CORE:=-mcpu=cortex-m4
_MTB_TOOLCHAIN_ARM__FLAGS_CORE:=--cpu=Cortex-M4
ifeq ($(VFP_SELECT),hardfp)
# FPv4 FPU, hardfp, single-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=hard -mfpu=fpv4-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=FPv4-SP
else ifeq ($(VFP_SELECT),softfloat)
# Software FP
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=
else
# FPv4 FPU, softfp, single-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=softfp -mfpu=fpv4-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP+FPv4-SP
endif
endif

ifeq ($(MTB_RECIPE__CORE),CM7)
# Arm Cortex-M7 CPU
_MTB_TOOLCHAIN_ARM__CFLAGS_CORE:=-mcpu=cortex-m7
_MTB_TOOLCHAIN_ARM__FLAGS_CORE:=--cpu=Cortex-M7
ifeq ($(VFP_SELECT),hardfp)
ifeq ($(VFP_SELECT_PRECISION),singlefp)
# FPv5 FPU, hardfp, single-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=hard -mfpu=fpv5-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=FPv5-SP
else
# FPv5 FPU, hardfp, double-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=hard -mfpu=fpv5-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=FPv5_D16
endif
else ifeq ($(VFP_SELECT),softfloat)
# Software FP
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=soft
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP
else
ifeq ($(VFP_SELECT_PRECISION),singlefp)
# FPv5 FPU, softfp, single-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=softfp -mfpu=fpv5-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP+FPv5-SP
else
# FPv5 FPU, softfp, double-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=softfp -mfpu=fpv5-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP+FPv5_D16
endif
endif
endif

ifeq ($(MTB_RECIPE__CORE),CM33)
ifeq ($(filter $(MTB_RECIPE__CORE_NAME)_DSP_PRESENT,$(DEVICE_$(DEVICE)_FEATURES)),)
_MTB_TOOLCHAIN_ARM__DSP_CFLAG_SUFFIX=+nodsp
_MTB_TOOLCHAIN_ARM__DSP_FLAG_SUFFIX=.no_dsp
else
_MTB_TOOLCHAIN_ARM__DSP_CFLAG_SUFFIX=
_MTB_TOOLCHAIN_ARM__DSP_FLAG_SUFFIX=
endif
# Arm Cortex-M33 CPU
_MTB_TOOLCHAIN_ARM__CFLAGS_CORE:=-mcpu=cortex-m33$(_MTB_TOOLCHAIN_ARM__DSP_CFLAG_SUFFIX)
_MTB_TOOLCHAIN_ARM__FLAGS_CORE:=--cpu=Cortex-M33$(_MTB_TOOLCHAIN_ARM__DSP_FLAG_SUFFIX)
ifeq ($(filter $(MTB_RECIPE__CORE_NAME)_FPU_PRESENT,$(DEVICE_$(DEVICE)_FEATURES)),)
# Software FP
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=soft
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP
else
ifeq ($(VFP_SELECT),hardfp)
# FPv5 FPU, hardfp, single-precision only
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=hard -mfpu=fpv5-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=FPv5-SP
else ifeq ($(VFP_SELECT),softfloat)
# Software FP
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=soft
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP
else
# FPv5 FPU, softfp, single-precision only
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=softfp -mfpu=fpv5-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP+FPv5-SP
endif
endif
endif

ifeq ($(MTB_RECIPE__CORE),CM55)
# Check if MVE is supported
ifeq ($(filter $(MTB_RECIPE__CORE_NAME)_MVE_PRESENT,$(DEVICE_$(DEVICE)_FEATURES)),)
ifneq ($(MVE_SELECT),NO_MVE)
$(call mtb__error, "MVE_SELECT=$(MVE_SELECT)" but "$(MTB_RECIPE__CORE)" core does not support MVE. Set "MVE_SELECT=NO_MVE" to disable MVE support for "$(MTB_RECIPE__CORE)" core.)
endif
endif
ifeq ($(MVE_SELECT),NO_MVE)
# Disable MVE
_MTB_TOOLCHAIN_ARM__MVE_CFLAGS=+nomve
_MTB_TOOLCHAIN_ARM__MVE_FLAGS=.no_mve
else ifeq ($(MVE_SELECT),MVE-I)
ifeq ($(filter $(MTB_RECIPE__CORE_NAME)_FPU_PRESENT,$(DEVICE_$(DEVICE)_FEATURES)),)
# Force switch to softfloat mode if FPU is not available
_MTB_TOOLCHAIN_ARM__MVE_CFLAGS=+nofp
_MTB_TOOLCHAIN_ARM__MVE_FLAGS=.no_fp
else
ifeq ($(VFP_SELECT),softfloat)
# Enable MVE-I and disable FPU
_MTB_TOOLCHAIN_ARM__MVE_CFLAGS=+nofp
_MTB_TOOLCHAIN_ARM__MVE_FLAGS=.no_fp
else
# Integer precision MVE
_MTB_TOOLCHAIN_ARM__MVE_CFLAGS=+nomve.fp
_MTB_TOOLCHAIN_ARM__MVE_FLAGS=.no_mvefp
endif
endif
else
ifeq ($(filter $(MTB_RECIPE__CORE_NAME)_FPU_PRESENT,$(DEVICE_$(DEVICE)_FEATURES)),)
$(info INFO: MVE_SELECT=MVE-F is set but FPU is not available on $(MTB_RECIPE__CORE) core. Valid options for $(MTB_RECIPE__CORE) core are MVE_SELECT=MVE-I or MVE_SELECT=NO_MVE.)
else ifeq ($(VFP_SELECT),softfloat)
$(info INFO: MVE_SELECT=MVE-F is set but VFP_SELECT=softfloat. Set VFP_SELECT=softfp or VFP_SELECT=hardfp to enable MVE-F support.)
endif
# Integer, half-, and single-precision floating-point MVE
_MTB_TOOLCHAIN_ARM__MVE_CFLAGS=
_MTB_TOOLCHAIN_ARM__MVE_FLAGS=
endif
# Arm Cortex-M55 CPU + extensions
_MTB_TOOLCHAIN_ARM__CFLAGS_CORE:=-mcpu=cortex-m55$(_MTB_TOOLCHAIN_ARM__MVE_CFLAGS)
_MTB_TOOLCHAIN_ARM__FLAGS_CORE:=--cpu=Cortex-M55$(_MTB_TOOLCHAIN_ARM__MVE_FLAGS)
ifeq ($(filter $(MTB_RECIPE__CORE_NAME)_FPU_PRESENT,$(DEVICE_$(DEVICE)_FEATURES)),)
# Software FP
ifeq ($(MVE_SELECT),MVE-I)
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=
_MTB_TOOLCHAIN_ARM__VFP_FLAGS=
else
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=soft
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP
endif
else
ifeq ($(VFP_SELECT),softfp)
ifeq ($(VFP_SELECT_PRECISION),singlefp)
# FPv5 FPU, softfp, single-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=softfp -mfpu=fpv5-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP+FPv5-SP
else
# FPv5 FPU, softfp, double-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=softfp
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP+FPv5_D16
endif
else ifeq ($(VFP_SELECT),softfloat)
# Software FP
ifeq ($(MVE_SELECT),MVE-I)
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=
_MTB_TOOLCHAIN_ARM__VFP_FLAGS=
else
# ARM CM55 need to have same precision flags for softfp and softfloat.
# Otherwise, it generates an incompactiblity error.
ifeq ($(VFP_SELECT_PRECISION),singlefp)
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=soft
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP+FPv5-SP
else
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=soft -mfpu=fpv5-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=SoftVFP+FPv5_D16
endif
endif
else
ifeq ($(VFP_SELECT_PRECISION),singlefp)
# FPv5 FPU, hardfp, single-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=hard -mfpu=fpv5-sp-d16
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=FPv5-SP
else
# FPv5 FPU, hardfp, double-precision
_MTB_TOOLCHAIN_ARM__VFP_CFLAGS:=-mfloat-abi=hard
_MTB_TOOLCHAIN_ARM__VFP_FLAGS:=--fpu=FPv5_D16
endif
endif
endif
endif

# Command line flags for c-files
MTB_TOOLCHAIN_ARM__CFLAGS:=\
	-c\
	$(_MTB_TOOLCHAIN_ARM__CFLAGS_CORE)\
	$(_MTB_TOOLCHAIN_ARM__OPTIMIZATION)\
	$(_MTB_TOOLCHAIN_ARM__VFP_CFLAGS)\
	$(_MTB_TOOLCHAIN_ARM__COMMON_FLAGS)\
	-g\
	-fshort-enums\
	-fshort-wchar\
	-fdiagnostics-absolute-paths

# Command line flags for cpp-files
MTB_TOOLCHAIN_ARM__CXXFLAGS:=$(MTB_TOOLCHAIN_ARM__CFLAGS) -fno-rtti -fno-exceptions

# Command line flags for s-files
MTB_TOOLCHAIN_ARM__ASFLAGS_LC:=\
	$(_MTB_TOOLCHAIN_ARM__FLAGS_CORE)\
	$(_MTB_TOOLCHAIN_ARM__VFP_FLAGS)\
	--diag_suppress=1950

# Command line flags for S-files
MTB_TOOLCHAIN_ARM__ASFLAGS_UC:=\
	-c\
	$(_MTB_TOOLCHAIN_ARM__CFLAGS_CORE)\
	$(_MTB_TOOLCHAIN_ARM__VFP_CFLAGS)\
	$(_MTB_TOOLCHAIN_ARM__COMMON_FLAGS)

# Command line flags for linking
MTB_TOOLCHAIN_ARM__LDFLAGS:=\
	$(_MTB_TOOLCHAIN_ARM__FLAGS_CORE)\
	$(_MTB_TOOLCHAIN_ARM__VFP_FLAGS)\
	--info=totals\
	--stdlib=libc++\
	--dangling_debug_address=0xF0000000

# Command line flags for archiving
MTB_TOOLCHAIN_ARM__ARFLAGS:=-s --create

# Toolchain-specific suffixes
MTB_TOOLCHAIN_ARM__SUFFIX_S  :=S
MTB_TOOLCHAIN_ARM__SUFFIX_s  :=s
MTB_TOOLCHAIN_ARM__SUFFIX_C  :=c
MTB_TOOLCHAIN_ARM__SUFFIX_H  :=h
MTB_TOOLCHAIN_ARM__SUFFIX_CPP:=cpp
MTB_TOOLCHAIN_ARM__SUFFIX_CXX:=cxx
MTB_TOOLCHAIN_ARM__SUFFIX_CC :=cc
MTB_TOOLCHAIN_ARM__SUFFIX_HPP:=hpp
MTB_TOOLCHAIN_ARM__SUFFIX_O  :=o
MTB_TOOLCHAIN_ARM__SUFFIX_A  :=a
MTB_TOOLCHAIN_ARM__SUFFIX_AR :=ar
MTB_TOOLCHAIN_ARM__SUFFIX_D  :=d
MTB_TOOLCHAIN_ARM__SUFFIX_LS :=sct
MTB_TOOLCHAIN_ARM__SUFFIX_MAP:=map
MTB_TOOLCHAIN_ARM__SUFFIX_TARGET:=elf
MTB_TOOLCHAIN_ARM__SUFFIX_PROGRAM:=hex

# Toolchain specific flags
MTB_TOOLCHAIN_ARM__OUTPUT_OPTION:=-o
MTB_TOOLCHAIN_ARM__ARCHIVE_LIB_OUTPUT_OPTION:=
MTB_TOOLCHAIN_ARM__MAPFILE:=--map --list$(MTB__SPACE)
MTB_TOOLCHAIN_ARM__LSFLAGS:=--scatter$(MTB__SPACE)
MTB_TOOLCHAIN_ARM__INCRSPFILE:=@
MTB_TOOLCHAIN_ARM__INCRSPFILE_ASM_UC:=@
MTB_TOOLCHAIN_ARM__INCRSPFILE_ASM_LC:=--via$(MTB__SPACE)
MTB_TOOLCHAIN_ARM__OBJRSPFILE:=--via$(MTB__SPACE)

# Produce a makefile dependency rule for each input file
MTB_TOOLCHAIN_ARM__DEPENDENCIES=-MMD -MP -MF "$(@:.$(MTB_TOOLCHAIN_ARM__SUFFIX_O)=.$(MTB_TOOLCHAIN_ARM__SUFFIX_D))" -MT "$@"
MTB_TOOLCHAIN_ARM__EXPLICIT_DEPENDENCIES=-MMD -MP -MF "$$(@:.$(MTB_TOOLCHAIN_ARM__SUFFIX_O)=.$(MTB_TOOLCHAIN_ARM__SUFFIX_D))" -MT "$$@"

# Additional includes in the compilation process based on this toolchain
MTB_TOOLCHAIN_ARM__INCLUDES:=

# Additional libraries in the link process based on this toolchain
MTB_TOOLCHAIN_ARM__DEFINES:=$(_MTB_TOOLCHAIN_ARM__DEBUG_FLAG)

MTB_TOOLCHAIN_ARM__VSCODE_INTELLISENSE_MODE:=clang-arm
# ARM clang has the the same error syntax as GCC.
MTB_TOOLCHAIN_ARM__VSCODE_PROBLEM_MATCHER:=gcc
