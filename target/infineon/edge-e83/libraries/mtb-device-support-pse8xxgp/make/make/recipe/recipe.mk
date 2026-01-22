################################################################################
# \file recipe.mk
#
# \brief
# Set up a set of defines, includes, software components, linker script,
# Pre and Post build steps and call a macro to create a specific ELF file.
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

include $(MTB_TOOLS__RECIPE_DIR)/make/recipe/recipe_common.mk

include $(MTB_TOOLS__RECIPE_DIR)/make/toolchains/arm_v8/$(TOOLCHAIN)_cmse.mk

#
# Postbuild step
#
ifeq ($(LIBNAME),)

_MTB_RECIPE__BIN_FILE:=$(MTB_TOOLS__OUTPUT_CONFIG_DIR)/$(APPNAME).bin

recipe_postbuild: $(_MTB_RECIPE__BIN_FILE)

$(_MTB_RECIPE__BIN_FILE): $(_MTB_RECIPE__TARG_DEPENDENCY_FILE)
ifeq ($(TOOLCHAIN),ARM)
	$(MTB_TOOLCHAIN_ARM__BASE_DIR)/bin/fromelf --output=$@ --bincombined $<
else
	$(MTB_TOOLCHAIN_GCC_ARM__BASE_DIR)/bin/arm-none-eabi-objcopy -O binary $< $@
endif

_MTB_RECIPE__LAST_CONFIG_BIN_FILE:=$(MTB_RECIPE__LAST_CONFIG_DIR)/$(APPNAME).bin
_MTB_RECIPE__LAST_CONFIG_BIN_FILE_D:=$(_MTB_RECIPE__LAST_CONFIG_BIN_FILE).d

build_proj qbuild_proj: $(_MTB_RECIPE__LAST_CONFIG_BIN_FILE)

$(_MTB_RECIPE__LAST_CONFIG_BIN_FILE_D): | $(MTB_RECIPE__LAST_CONFIG_DIR)
	$(MTB__NOISE)echo $(_MTB_RECIPE__BIN_FILE) > $@.tmp
	$(MTB__NOISE)if ! cmp -s "$@" "$@.tmp"; then \
		mv -f "$@.tmp" "$@" ; \
	else \
		rm -f "$@.tmp"; \
	fi

$(_MTB_RECIPE__LAST_CONFIG_BIN_FILE): $(_MTB_RECIPE__BIN_FILE) $(_MTB_RECIPE__LAST_CONFIG_BIN_FILE_D) | mtb_conditional_postbuild
	$(MTB__NOISE)cp -f $(_MTB_RECIPE__BIN_FILE) $@

_MTB_RECIPE__COPIED_PROJECT_TARG_FILE=$(_MTB_RECIPE__PRJ_HEX_DIR)/$(_MTB_RECIPE__PROJECT_DIR_NAME).$(MTB_RECIPE__SUFFIX_TARGET)
_MTB_RECIPE__COPIED_PROJECT_BIN_FILE=$(_MTB_RECIPE__PRJ_HEX_DIR)/$(_MTB_RECIPE__PROJECT_DIR_NAME).bin

ifeq ($(_MTB_RECIPE__PROMOTE),true)
build_proj qbuild_proj: $(_MTB_RECIPE__COPIED_PROJECT_BIN_FILE) $(_MTB_RECIPE__LAST_CONFIG_BIN_FILE)
$(_MTB_RECIPE__COPIED_PROJECT_BIN_FILE) : | mtb_conditional_postbuild
endif

$(_MTB_RECIPE__COPIED_PROJECT_BIN_FILE).d : | $(_MTB_RECIPE__PRJ_HEX_DIR)
	$(MTB__NOISE)echo $(_MTB_RECIPE__BIN_FILE) > $@.tmp
	$(MTB__NOISE)if ! cmp -s "$@" "$@.tmp"; then \
		mv -f "$@.tmp" "$@" ; \
	else \
		rm -f "$@.tmp"; \
	fi

# Copy project-specific program image to the application directory
$(_MTB_RECIPE__COPIED_PROJECT_BIN_FILE): $(_MTB_RECIPE__BIN_FILE) $(_MTB_RECIPE__COPIED_PROJECT_BIN_FILE).d
	$(MTB__NOISE)cp -f $(_MTB_RECIPE__BIN_FILE) $@

ifneq ($(COMBINE_SIGN_JSON),)
# Running "make build_proj" not as part of an application "make build". In this case, also run sign_combine step.
ifeq ($(MTB_APPLICATION_SUBPROJECTS),)
sign_combine_check_inputs : | $(_MTB_RECIPE__COPIED_PROJECT_BIN_FILE) $(_MTB_RECIPE__LAST_CONFIG_BIN_FILE)
endif
endif #($(COMBINE_SIGN_JSON),)
endif #($(LIBNAME),)

ifeq ($(APPTYPE),flash)
MTB_RECIPE__DEFINES+=-DFLASH_BOOT -DCY_PDL_FLASH_BOOT
endif

# Legacy memory reporting for GCC_ARM and LLVM_ARM toolchains
ifeq (,$(CY_TOOL_memory_report_SUPPORTED_INTERFACES))
ifneq (,$(filter GCC_ARM LLVM_ARM,$(TOOLCHAIN)))
MTB_TOOLCHAIN_$(TOOLCHAIN)__LDFLAGS+=-Wl,--print-memory-usage
endif
endif

include $(MTB_TOOLS__RECIPE_DIR)/make/recipe/recipe_pse8xxgp.mk

################################################################################
# Programmer tool
################################################################################

CY_PROGTOOL_FW_LOADER=$(CY_TOOL_fw-loader_EXE_ABS)
progtool:
	$(MTB__NOISE)echo;\
	echo ==============================================================================;\
	echo "Available commands";\
	echo ==============================================================================;\
	echo;\
	"$(CY_PROGTOOL_FW_LOADER)" --help | sed s/'	'/' '/g;\
	echo ==============================================================================;\
	echo "Connected device(s)";\
	echo ==============================================================================;\
	echo;\
	deviceList=$$("$(CY_PROGTOOL_FW_LOADER)" --device-list | grep "FW Version" | sed s/'	'/' '/g);\
	if [[ ! -n "$$deviceList" ]]; then\
		echo "ERROR: Could not find any connected devices";\
		echo;\
		exit 1;\
	else\
		echo "$$deviceList";\
		echo;\
	fi;\
	echo ==============================================================================;\
	echo "Input command";\
	echo ==============================================================================;\
	echo;\
	echo " Specify the command (and optionally the device name).";\
	echo " E.g. --mode kp3-daplink KitProg3 CMSIS-DAP HID-0123456789ABCDEF";\
	echo;\
	read -p " > " -a params;\
	echo;\
	echo ==============================================================================;\
	echo "Run command";\
	echo ==============================================================================;\
	echo;\
	paramsSize=$${#params[@]};\
	if [[ $$paramsSize > 2 ]]; then\
		if [[ $${params[1]} == "kp3-"* ]]; then\
			deviceName="$${params[@]:2:$$paramsSize}";\
			"$(CY_PROGTOOL_FW_LOADER)" $${params[0]} $${params[1]} "$$deviceName" | sed s/'	'/' '/g;\
		else\
			deviceName="$${params[@]:1:$$paramsSize}";\
			"$(CY_PROGTOOL_FW_LOADER)" $${params[0]} "$$deviceName" | sed s/'	'/' '/g;\
		fi;\
	else\
		"$(CY_PROGTOOL_FW_LOADER)" "$${params[@]}" | sed s/'	'/' '/g;\
	fi;

.PHONY: progtool
