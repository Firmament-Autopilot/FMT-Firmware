################################################################################
# \file defines.mk
#
# \brief
# Defines, needed for the PSOC(TM) Edge build recipe.
#
################################################################################
# \copyright
# (c) 2021-2025, Cypress Semiconductor Corporation (an Infineon company) or
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

_MTB_RECIPE__NOT_SUPPORT_LEGACY_MEMCALC:=1

include $(MTB_TOOLS__RECIPE_DIR)/make/recipe/defines_common.mk

ifneq ($(OTA_SUPPORT),)
# OTA post-build script needs python.
CY_PYTHON_REQUIREMENT=true
endif

################################################################################
# General
################################################################################
_MTB_RECIPE__PROGRAM_INTERFACE_SUPPORTED:=KitProg3 JLink
#
# Compatibility interface for this recipe make
#
MTB_RECIPE__INTERFACE_VERSION:=2
MTB_RECIPE__EXPORT_INTERFACES:=4 5

MTB_RECIPE__NINJA_SUPPORT:=1 2

ifeq ($(MTB_TYPE),PROJECT)
_MTB_RECIPE__IS_MULTI_CORE_APPLICATION:=true
endif

#
# List the supported toolchains
#
ifdef CY_SUPPORTED_TOOLCHAINS
MTB_SUPPORTED_TOOLCHAINS?=$(CY_SUPPORTED_TOOLCHAINS)
else
MTB_SUPPORTED_TOOLCHAINS?=GCC_ARM IAR ARM LLVM_ARM
endif

ifeq ($(TOOLCHAIN),ARM)
PC_SYMBOL=__main
SP_SYMBOL=Image$$$$ARM_LIB_STACK$$$$ZI$$$$Limit
else ifeq ($(TOOLCHAIN),IAR)
PC_SYMBOL=Reset_Handler
SP_SYMBOL=CSTACK$$$$Limit
else ifeq ($(TOOLCHAIN),GCC_ARM)
PC_SYMBOL=Reset_Handler
SP_SYMBOL=__StackTop
endif

#
# Define the default device mode
#
VCORE_ATTRS?=SECURE

# MVE support
# If MVE is not available on device then MVE_SELECT=NO_MVE.
# If MVE is available on device and VFP_SELECT=softfloat, then MVE_SELECT=MVE-I,
# else MVE_SELECT=<empty> (MVE-F mode).
ifeq ($(filter $(CORE_NAME)_MVE_PRESENT,$(DEVICE_$(DEVICE)_FEATURES)),)
MVE_SELECT?=NO_MVE
else
ifeq ($(VFP_SELECT),softfloat)
MVE_SELECT?=MVE-I
else
MVE_SELECT?=
endif
endif

include $(MTB_TOOLS__RECIPE_DIR)/make/recipe/defines_pse8xxgp.mk
