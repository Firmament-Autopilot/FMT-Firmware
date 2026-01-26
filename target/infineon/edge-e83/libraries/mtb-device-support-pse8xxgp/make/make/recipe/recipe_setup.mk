################################################################################
# \file recipe_setup.mk
#
# \brief
# Standardized recipe / toolchain variable setup.
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
# Final variables that will control the build process
################################################################################

# Elf to bin conversion tool
MTB_RECIPE__ELF2BIN:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__ELF2BIN)

# Run ELF2BIN conversion
# $(1) : artifact elf
# $(2) : artifact bin
mtb_recipe__elf2bin=$(mtb_toolchain_$(TOOLCHAIN)__elf2bin)

# Compilers, assembler, linker, etc.
CC:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__CC)
CXX:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__CXX)
AS:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__AS)
AS_UC:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__AS_UC)
AS_LC:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__AS_LC)
AR:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__AR)
LD:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__LD)

ifeq ($(AS_UC),)
AS_UC:=$(AS)
endif
ifeq ($(AS_LC),)
AS_LC:=$(AS)
endif
ifeq ($(AS),)
ifeq ($(TOOLCHAIN),ARM)
AS:=$(AS_LC)
else
AS:=$(AS_UC)
endif
endif

# Toolchain specific flags
MTB_RECIPE__OUTPUT_OPTION:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__OUTPUT_OPTION)
MTB_RECIPE__ARCHIVE_LIB_OUTPUT_OPTION:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__ARCHIVE_LIB_OUTPUT_OPTION)
MTB_RECIPE__MAPFILE:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__MAPFILE)
MTB_RECIPE__STARTGROUP:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__STARTGROUP)
MTB_RECIPE__ENDGROUP:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__ENDGROUP)
MTB_RECIPE__LSFLAGS:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__LSFLAGS)
MTB_RECIPE__INCRSPFILE:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__INCRSPFILE)
MTB_RECIPE__OBJRSPFILE:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__OBJRSPFILE)

ifneq ($(APPNAME),)

# LS provided by the user's app
ifneq ($(LINKER_SCRIPT),)
_MTB_RECIPE__LINKER_SCRIPT_USER:=$(LINKER_SCRIPT)
ifeq ($(MTB_RECIPE__LINKER_SCRIPT),)
ifneq ($(wildcard $(call mtb_core__escaped_path,$(_MTB_RECIPE__LINKER_SCRIPT_USER))),)
MTB_RECIPE__LINKER_SCRIPT:=$(_MTB_RECIPE__LINKER_SCRIPT_USER)
else
$(call mtb__error,Unable to find linker script '$(LINKER_SCRIPT)'.)
endif
endif # ($(_MTB_RECIPE__LINKER_SCRIPT_USER),)
endif # ($(LINKER_SCRIPT),)

# LS provided by custom BSP logic.
ifneq ($(MTB_BSP__LINKER_SCRIPT),)
_MTB_RECIPE__LINKER_SCRIPT_BSP:=$(MTB_BSP__LINKER_SCRIPT)
ifeq ($(MTB_RECIPE__LINKER_SCRIPT),)
ifneq ($(wildcard $(call mtb_core__escaped_path,$(_MTB_RECIPE__LINKER_SCRIPT_BSP))),)
MTB_RECIPE__LINKER_SCRIPT:=$(_MTB_RECIPE__LINKER_SCRIPT_BSP)
else
$(call mtb__error,Unable to find linker script '$(MTB_BSP__LINKER_SCRIPT)'.)
endif
endif # ($(_MTB_RECIPE__LINKER_SCRIPT_BSP),)
endif # ($(MTB_BSP__LINKER_SCRIPT),)

# LS provided by the user's BSP (complex multi-core type)
_MTB_RECIPE__LINKER_SCRIPT_MC1:=$(MTB_TOOLS__TARGET_DIR)/COMPONENT_$(MTB_RECIPE__CORE)/TOOLCHAIN_$(TOOLCHAIN)/linker.$(MTB_RECIPE__SUFFIX_LS)
ifeq ($(MTB_RECIPE__LINKER_SCRIPT),)
ifneq ($(wildcard $(call mtb_core__escaped_path,$(_MTB_RECIPE__LINKER_SCRIPT_MC1))),)
MTB_RECIPE__LINKER_SCRIPT:=$(_MTB_RECIPE__LINKER_SCRIPT_MC1)
endif
endif

# LS provided by the user's BSP (simple multi-core)
_MTB_RECIPE__LINKER_SCRIPT_MC2:=$(MTB_TOOLS__TARGET_DIR)/COMPONENT_$(MTB_RECIPE__CORE_NAME)/TOOLCHAIN_$(TOOLCHAIN)/linker.$(MTB_RECIPE__SUFFIX_LS)
ifeq ($(MTB_RECIPE__LINKER_SCRIPT),)
ifneq ($(wildcard $(call mtb_core__escaped_path,$(_MTB_RECIPE__LINKER_SCRIPT_MC2))),)
MTB_RECIPE__LINKER_SCRIPT:=$(_MTB_RECIPE__LINKER_SCRIPT_MC2)
endif
endif

# LS provided by the user's BSP (single-core)
_MTB_RECIPE__LINKER_SCRIPT_SC:=$(MTB_TOOLS__TARGET_DIR)/TOOLCHAIN_$(TOOLCHAIN)/linker.$(MTB_RECIPE__SUFFIX_LS)
ifeq ($(MTB_RECIPE__LINKER_SCRIPT),)
ifneq ($(wildcard $(call mtb_core__escaped_path,$(_MTB_RECIPE__LINKER_SCRIPT_SC))),)
MTB_RECIPE__LINKER_SCRIPT:=$(_MTB_RECIPE__LINKER_SCRIPT_SC)
endif
endif

ifeq ($(wildcard $(call mtb_core__escaped_path,$(MTB_RECIPE__LINKER_SCRIPT))),)
$(call mtb__error,Unable to find linker.$(MTB_RECIPE__SUFFIX_LS) in $(_MTB_RECIPE__LINKER_SCRIPT_MC1)$(MTB__COMMA) $(_MTB_RECIPE__LINKER_SCRIPT_MC2)$(MTB__COMMA) or $(_MTB_RECIPE__LINKER_SCRIPT_SC).)
endif

ifeq ($(TOOLCHAIN),A_Clang)
include $(MTB_RECIPE__LINKER_SCRIPT)
endif

else # ($(APPNAME),)
MTB_RECIPE__LINKER_SCRIPT=
endif # ($(APPNAME),)


# Compiler, assember, linker, etc. arguments.
MTB_RECIPE__CFLAGS=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__CFLAGS) $(CFLAGS)
MTB_RECIPE__CXXFLAGS=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__CXXFLAGS) $(CXXFLAGS)
ifneq ($(MTB_TOOLCHAIN_$(TOOLCHAIN)__ASFLAGS_UC),)
MTB_RECIPE__ASFLAGS_UC=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__ASFLAGS_UC) $(ASFLAGS)
else
MTB_RECIPE__ASFLAGS_UC=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__ASFLAGS) $(ASFLAGS)
endif
ifneq ($(MTB_TOOLCHAIN_$(TOOLCHAIN)__ASFLAGS_LC),)
MTB_RECIPE__ASFLAGS_LC=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__ASFLAGS_LC) $(ASFLAGS)
else
MTB_RECIPE__ASFLAGS_LC=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__ASFLAGS) $(ASFLAGS)
endif
ifneq ($(MTB_TOOLCHAIN_$(TOOLCHAIN)__INCRSPFILE_ASM_UC),)
MTB_RECIPE__INCRSPFILE_ASM_UC=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__INCRSPFILE_ASM_UC)
else
MTB_RECIPE__INCRSPFILE_ASM_UC=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__INCRSPFILE_ASM)
endif
ifneq ($(MTB_TOOLCHAIN_$(TOOLCHAIN)__INCRSPFILE_ASM_LC),)
MTB_RECIPE__INCRSPFILE_ASM_LC=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__INCRSPFILE_ASM_LC)
else
MTB_RECIPE__INCRSPFILE_ASM_LC=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__INCRSPFILE_ASM)
endif
# intentionally does not have $(ARFLAGS).
# ARFLAGS have a non-empty default value. See https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# Add ARFLAGS will cause BWC issues.
MTB_RECIPE__ARFLAGS=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__ARFLAGS)
ifneq ($(APPNAME),)
MTB_RECIPE__LDFLAGS=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__LDFLAGS) $(LDFLAGS)
else
MTB_RECIPE__LDFLAGS=
endif # ($(APPNAME),)

ifneq ($(APPNAME),)
ifeq ($(TOOLCHAIN),A_Clang)
MTB_RECIPE__LDFLAGS+=$(ACLANG_MEM_LDFLAGS)
else
MTB_RECIPE__LDFLAGS+=$(MTB_RECIPE__LSFLAGS)"$(MTB_RECIPE__LINKER_SCRIPT)"
endif # ($(TOOLCHAIN),A_Clang)
endif # ($(APPNAME),)

# For BWC, be careful with _ [legacy] vs __ [new/standard]
ifneq ($(MTB_RECIPE_CFLAGS),)
MTB_RECIPE__CFLAGS:=$(MTB_RECIPE_CFLAGS)
endif

ifneq ($(MTB_RECIPE_CXXFLAGS),)
MTB_RECIPE__CXXFLAGS:=$(MTB_RECIPE_CXXFLAGS)
endif

ifneq ($(MTB_RECIPE_ASFLAGS),)
MTB_RECIPE__ASFLAGS:=$(MTB_RECIPE_ASFLAGS)
endif

ifneq ($(MTB_RECIPE_ARFLAGS),)
MTB_RECIPE__ARFLAGS:=$(MTB_RECIPE_ARFLAGS)
endif

ifneq ($(APPNAME),)
ifneq ($(MTB_RECIPE_LDFLAGS),)
MTB_RECIPE__LDFLAGS:=$(MTB_RECIPE_LDFLAGS)
endif # ($(MTB_RECIPE_LDFLAGS),)
endif # ($(APPNAME),)

# N.B., can't use := because it may references $@
MTB_RECIPE__DEPENDENCIES=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__DEPENDENCIES)
MTB_RECIPE__EXPLICIT_DEPENDENCIES=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__EXPLICIT_DEPENDENCIES)

MTB_RECIPE__TOOLCHAIN_INCLUDES:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__INCLUDES)
MTB_RECIPE__TOOLCHAIN_DEFINES:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__DEFINES)

MTB_RECIPE__TOOLCHAIN_VSCODE_INTELLISENSE_MODE:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__VSCODE_INTELLISENSE_MODE)
MTB_RECIPE__TOOLCHAIN_VSCODE_PROBLEM_MATCHER:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__VSCODE_PROBLEM_MATCHER)
