################################################################################
# \file recipe_common.mk
#
# \brief
# Common variables and targets for recipe.mk
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

ifeq ($(MTB_TYPE),PROJECT)
_MTB_RECIPE__APPLICATION_RELATIVE=..
else
_MTB_RECIPE__APPLICATION_RELATIVE=.
endif

# Determine programming interface. Use BSP_PROGRAM_INTERFACE if it is set,
# otherwise use the default one
_MTB_RECIPE__DEFAULT_PROGRAM_INTERFACE?=KitProg3
ifeq (,$(BSP_PROGRAM_INTERFACE))
_MTB_RECIPE__PROGRAM_INTERFACE_SUBDIR:=$(_MTB_RECIPE__DEFAULT_PROGRAM_INTERFACE)
else
_MTB_RECIPE__PROGRAM_INTERFACE_SUBDIR:=$(BSP_PROGRAM_INTERFACE)
endif

ifeq (KitProg3,$(_MTB_RECIPE__PROGRAM_INTERFACE_SUBDIR))
_MTB_RECIPE__PROGRAM_INTERFACE_LAUNCH_SUFFIX:=(KitProg3_MiniProg4)
else ifeq (JLink,$(_MTB_RECIPE__PROGRAM_INTERFACE_SUBDIR))
_MTB_RECIPE__PROGRAM_INTERFACE_LAUNCH_SUFFIX:=(JLink)
else ifeq (FTDI,$(_MTB_RECIPE__PROGRAM_INTERFACE_SUBDIR))
_MTB_RECIPE__PROGRAM_INTERFACE_LAUNCH_SUFFIX:=(FTDI)
endif

# debug interface validation
debug_interface_check:
ifeq ($(filter $(_MTB_RECIPE__PROGRAM_INTERFACE_SUBDIR), $(_MTB_RECIPE__PROGRAM_INTERFACE_SUPPORTED)),)
	$(error "$(_MTB_RECIPE__PROGRAM_INTERFACE_SUBDIR)" interface is not supported for this device. \
	Supported interfaces are "$(_MTB_RECIPE__PROGRAM_INTERFACE_SUPPORTED)")
endif

################################################################################
# Application hex file paths
################################################################################

# Application build output is one level up relative to the project directory
_MTB_RECIPE__APP_HEX_DIR:=$(_MTB_RECIPE__APPLICATION_RELATIVE)/build
_MTB_RECIPE__PRJ_HEX_DIR:=$(_MTB_RECIPE__APP_HEX_DIR)/project_hex

# Override the hex path for qprogram_proj target
ifeq ($(MTB_TYPE),PROJECT)
ifneq ($(MTB_APPLICATION_SUBPROJECTS),)
_MTB_RECIPE__APP_HEX_FILE:=$(call mtb__path_normalize,$(_MTB_RECIPE__APP_HEX_DIR)/app_combined.$(MTB_RECIPE__SUFFIX_PROGRAM))
endif
endif

_MTB_RECIPE__PROJECT_DIR_NAME:=$(notdir $(realpath $(MTB_TOOLS__PRJ_DIR)))

################################################################################
# Compiler and linker arguments
################################################################################

#
# Defines construction
#
ifneq ($(DEFINES),)
_MTB_RECIPE__USER_DEFINES=$(addprefix -D,$(DEFINES))
endif
ifneq ($(LIBNAME),)
_MTB_RECIPE__USER_NAME=-DCY_LIBNAME_$(subst -,_,$(LIBNAME))
else
_MTB_RECIPE__USER_NAME=-DCY_APPNAME_$(subst -,_,$(APPNAME))
endif

ifneq (,$(MTB_RECIPE__CORE_NAME))
_MTB_RECIPE__CORE_NAME_DEFINES=-DCORE_NAME_$(MTB_RECIPE__CORE_NAME)=1
endif

# Note: _MTB_RECIPE__DEFAULT_COMPONENT is needed as DISABLE_COMPONENTS cannot be empty
_MTB_RECIPE__COMPONENT_LIST=$(filter-out $(DISABLE_COMPONENTS) _MTB_RECIPE__DEFAULT_COMPONENT,$(MTB_CORE__FULL_COMPONENT_LIST))

MTB_RECIPE__DEFINES=$(sort \
	$(_MTB_RECIPE__USER_DEFINES)\
	$(_MTB_RECIPE__USER_NAME)\
	-DTARGET_$(subst -,_,$(TARGET))\
	-DCY_TARGET_BOARD=$(subst -,_,$(TARGET))\
	$(addprefix -DCOMPONENT_,$(subst .,_,$(subst -,_,$(_MTB_RECIPE__COMPONENT_LIST))))\
	$(MTB_RECIPE__TOOLCHAIN_DEFINES)\
	-DCY_SUPPORTS_DEVICE_VALIDATION\
	$(_MTB_RECIPE__CORE_NAME_DEFINES)\
	$(addprefix -D, $(subst -,_,$(DEVICE)) $(BSP_DEFINES) $(DEVICE_DEFINES)))

#
# Includes construction
#
MTB_RECIPE__INCLUDES=\
	$(addprefix -I,$(INCLUDES))\
	$(addprefix -I,$(MTB_CORE__SEARCH_APP_INCLUDES))\
	$(addprefix -I,$(MTB_RECIPE__TOOLCHAIN_INCLUDES))

#
# Sources construction
#
MTB_RECIPE__SOURCE=$(MTB_CORE__SEARCH_APP_SOURCE)

#
# Libraries construction
#
MTB_RECIPE__LIBS=$(LDLIBS) $(MTB_CORE__SEARCH_APP_LIBS)

#
# Prebuild step
#
recipe_prebuild:

#
# Postbuild step
#
ifeq ($(LIBNAME),)

_MTB_RECIPE__PROG_FILE:=$(MTB_TOOLS__OUTPUT_CONFIG_DIR)/$(APPNAME)$(_MTB_RECIPE__PROG_FILE_SUFFIX).$(MTB_RECIPE__SUFFIX_PROGRAM)
_MTB_RECIPE__TARG_FILE:=$(MTB_TOOLS__OUTPUT_CONFIG_DIR)/$(APPNAME).$(MTB_RECIPE__SUFFIX_TARGET)
ifneq (,$(MTB_IDE__TARG_FILE))
_MTB_RECIPE__TARG_DEPENDENCY_FILE:=$(call mtb__path_normalize,$(MTB_IDE__TARG_FILE))
else
_MTB_RECIPE__TARG_DEPENDENCY_FILE:=$(_MTB_RECIPE__TARG_FILE)
endif

recipe_postbuild: $(_MTB_RECIPE__PROG_FILE)

$(_MTB_RECIPE__PROG_FILE): $(_MTB_RECIPE__TARG_DEPENDENCY_FILE)
ifeq ($(TOOLCHAIN),A_Clang)
	$(_MTB_RECIPE__ACLANG_POSTBUILD)
endif
ifeq ($(TOOLCHAIN),ARM)
	$(MTB_TOOLCHAIN_ARM__BASE_DIR)/bin/fromelf --output $@ --i32combined $<
endif
ifeq ($(TOOLCHAIN),IAR)
	$(MTB_TOOLCHAIN_GCC_ARM__OBJCOPY) -O ihex $< $@
endif
ifeq ($(TOOLCHAIN),GCC_ARM)
	$(MTB_TOOLCHAIN_GCC_ARM__OBJCOPY) -O ihex $< $@
endif
ifeq ($(TOOLCHAIN),LLVM_ARM)
	$(MTB_TOOLCHAIN_GCC_ARM__OBJCOPY) -O ihex $< $@
endif

cpy_recipe_trg:
ifneq (,$(MTB_IDE__TARG_FILE))
	$(MTB__NOISE)rm -f $(_MTB_RECIPE__TARG_FILE)
	$(MTB__NOISE)cp -f $(call mtb__path_normalize,$(MTB_IDE__TARG_FILE)) $(_MTB_RECIPE__TARG_FILE)
endif

# There are 2 dependencies on this file.
# The first is from build_proj and qbuild_proj. In ths case, we are promoting. We add project_postbuild as a dependency becase that could modify the file.
# The second is when generating the combined hex file or fist stage build. In this case, we are not promoting and cannot depend on project_postbuild as that is only defined in second stage.
_MTB_RECIPE__PROMOTE=false

MTB_RECIPE__LAST_CONFIG_DIR:=$(MTB_TOOLS__OUTPUT_BASE_DIR)/last_config
$(MTB_RECIPE__LAST_CONFIG_DIR):|
	$(MTB__NOISE)mkdir -p $(MTB_RECIPE__LAST_CONFIG_DIR)

_MTB_RECIPE__LAST_CONFIG_PROG_FILE:=$(MTB_RECIPE__LAST_CONFIG_DIR)/$(APPNAME).$(MTB_RECIPE__SUFFIX_PROGRAM)
_MTB_RECIPE__LAST_CONFIG_TARG_FILE:=$(MTB_RECIPE__LAST_CONFIG_DIR)/$(APPNAME).$(MTB_RECIPE__SUFFIX_TARGET)
_MTB_RECIPE__LAST_CONFIG_PROG_FILE_D:=$(_MTB_RECIPE__LAST_CONFIG_PROG_FILE).d

build_proj qbuild_proj: $(_MTB_RECIPE__LAST_CONFIG_PROG_FILE)

$(_MTB_RECIPE__LAST_CONFIG_PROG_FILE_D): | $(MTB_RECIPE__LAST_CONFIG_DIR)
	$(MTB__NOISE)echo $(_MTB_RECIPE__PROG_FILE) > $@.tmp
	$(MTB__NOISE)if ! cmp -s "$@" "$@.tmp"; then \
		mv -f "$@.tmp" "$@" ; \
	else \
		rm -f "$@.tmp"; \
	fi

$(_MTB_RECIPE__LAST_CONFIG_PROG_FILE): $(_MTB_RECIPE__PROG_FILE) $(_MTB_RECIPE__LAST_CONFIG_PROG_FILE_D) | mtb_conditional_postbuild
	$(MTB__NOISE)cp -f $(_MTB_RECIPE__PROG_FILE) $@
	$(MTB__NOISE)cp -f $(_MTB_RECIPE__TARG_DEPENDENCY_FILE) $(_MTB_RECIPE__LAST_CONFIG_TARG_FILE)

ifeq ($(MTB_APPLICATION_PROMOTE),true)
_MTB_RECIPE__PROMOTE=true
endif
ifneq ($(COMBINE_SIGN_JSON),)
_MTB_RECIPE__PROMOTE=true
endif

_MTB_RECIPE__COPIED_PROJECT_PROG_FILE=$(_MTB_RECIPE__PRJ_HEX_DIR)/$(_MTB_RECIPE__PROJECT_DIR_NAME).$(MTB_RECIPE__SUFFIX_PROGRAM)

ifeq ($(_MTB_RECIPE__PROMOTE),true)
build_proj qbuild_proj: $(_MTB_RECIPE__COPIED_PROJECT_PROG_FILE) $(_MTB_RECIPE__LAST_CONFIG_PROG_FILE)
$(_MTB_RECIPE__COPIED_PROJECT_PROG_FILE) : | mtb_conditional_postbuild
endif

$(_MTB_RECIPE__PRJ_HEX_DIR):
	$(MTB__NOISE)mkdir -p $(_MTB_RECIPE__PRJ_HEX_DIR)

$(_MTB_RECIPE__COPIED_PROJECT_PROG_FILE).d : | $(_MTB_RECIPE__PRJ_HEX_DIR)
	$(MTB__NOISE)echo $(_MTB_RECIPE__PROG_FILE) > $@.tmp
	$(MTB__NOISE)if ! cmp -s "$@" "$@.tmp"; then \
		mv -f "$@.tmp" "$@" ; \
	else \
		rm -f "$@.tmp"; \
	fi

# Copy project-specific program image to the application directory
$(_MTB_RECIPE__COPIED_PROJECT_PROG_FILE): $(_MTB_RECIPE__PROG_FILE) $(_MTB_RECIPE__COPIED_PROJECT_PROG_FILE).d
	$(MTB__NOISE)cp -f $(_MTB_RECIPE__PROG_FILE) $@
	$(MTB__NOISE)cp -f $(_MTB_RECIPE__TARG_DEPENDENCY_FILE) $(_MTB_RECIPE__PRJ_HEX_DIR)/$(_MTB_RECIPE__PROJECT_DIR_NAME).$(MTB_RECIPE__SUFFIX_TARGET)

ifeq ($(COMBINE_SIGN_JSON),)
ifneq ($(MTB_APPLICATION_SUBPROJECTS),)
# Multi-core application build/qbuild targets run application_postbuild
# for the first project in the MTB_PROJECTS list
application_postbuild: $(_MTB_RECIPE__APP_HEX_FILE)

$(_MTB_RECIPE__APP_HEX_FILE): $(foreach project,$(MTB_APPLICATION_SUBPROJECTS),$(_MTB_RECIPE__PRJ_HEX_DIR)/$(project).$(MTB_RECIPE__SUFFIX_PROGRAM) $(_MTB_RECIPE__PRJ_HEX_DIR)/$(project).$(MTB_RECIPE__SUFFIX_PROGRAM).d)
ifeq ($(CY_TOOL_srec_cat_EXE_ABS),)
	$(call mtb__error,Unable to proceed. srec_cat executable not found)
endif
	$(info Generating combined hex file: $(_MTB_RECIPE__APP_HEX_FILE))
	$(MTB__NOISE)$(CY_TOOL_srec_cat_EXE_ABS) $(foreach project,$(MTB_APPLICATION_SUBPROJECTS),$(_MTB_RECIPE__PRJ_HEX_DIR)/$(project).$(MTB_RECIPE__SUFFIX_PROGRAM) -intel) -o $(_MTB_RECIPE__APP_HEX_FILE) -intel --Output_Block_Size 16

endif #($(MTB_APPLICATION_SUBPROJECTS),)
else #($(COMBINE_SIGN_JSON),)

# use ?= as default
_MTB_RECIPE__COMBINE_SIGN_INTERFACE_VERSION?=1
_MTB_RECIPE__COMBINE_SIGN_VERSION:=$(lastword $(filter $(CY_TOOL_signcombinemkgen_SUPPORTED_INTERFACES),$(_MTB_RECIPE__COMBINE_SIGN_INTERFACE_VERSION)))

ifneq ($(CY_TOOL_signcombinemkgen_EXE_ABS),)
_MTB_RECIPE__NORMALIZED_COMBINE_SIGN_JSON=$(_MTB_RECIPE__APPLICATION_RELATIVE)/$(COMBINE_SIGN_JSON)
_MTB_RECIPE__COMBINE_SIGN_MK_FILE:=$(_MTB_RECIPE__APP_HEX_DIR)/$(notdir $(COMBINE_SIGN_JSON)).mk

$(_MTB_RECIPE__COMBINE_SIGN_MK_FILE): $(_MTB_RECIPE__NORMALIZED_COMBINE_SIGN_JSON)
	$(MTB__NOISE)$(CY_TOOL_signcombinemkgen_EXE_ABS) -i $(_MTB_RECIPE__NORMALIZED_COMBINE_SIGN_JSON) -o $(_MTB_RECIPE__COMBINE_SIGN_MK_FILE).tmp -v $(_MTB_RECIPE__COMBINE_SIGN_VERSION)
	$(MTB__NOISE)if ! cmp -s "$@" "$@.tmp"; then \
		mv -f "$@.tmp" "$@" ; \
	else \
		rm -f "$@.tmp"; \
	fi

recipe_prebuild: $(_MTB_RECIPE__COMBINE_SIGN_MK_FILE)

include $(_MTB_RECIPE__COMBINE_SIGN_MK_FILE)
endif #($(CY_TOOL_signcombinemkgen_EXE_ABS),)

# override the default app_combine.hex as the file being programmed.
ifneq ($(MTB_COMBINE_SIGN_DEFAULT)$(MTB_COMBINE_SIGN_$(MTB_COMBINE_SIGN_DEFAULT)_HEX_PATH),)
# Used the hex file from combiner-signer.json
_MTB_RECIPE__APP_HEX_FILE:=$(call mtb__path_normalize,$(MTB_COMBINE_SIGN_$(MTB_COMBINE_SIGN_DEFAULT)_HEX_PATH))
endif

application_postbuild: sign_combine
ifeq ($(MTB_TYPE),COMBINED)
build_proj qbuild_proj: sign_combine
endif
# Running "make build_proj" not as part of an application "make build". In this case, also run sign_combine step.
ifeq ($(MTB_APPLICATION_SUBPROJECTS),)
build_proj qbuild_proj: sign_combine sign_combine_check_inputs
sign_combine: sign_combine_check_inputs
sign_combine_check_inputs : | $(_MTB_RECIPE__COPIED_PROJECT_PROG_FILE) $(_MTB_RECIPE__LAST_CONFIG_PROG_FILE)
endif

endif #($(COMBINE_SIGN_JSON),)
endif #($(LIBNAME),)

include $(MTB_TOOLS__RECIPE_DIR)/make/recipe/memcalc.mk

#
# Identify the phony targets
#
.PHONY: sign_combine recipe_postbuild application_postbuild cpy_recipe_target
