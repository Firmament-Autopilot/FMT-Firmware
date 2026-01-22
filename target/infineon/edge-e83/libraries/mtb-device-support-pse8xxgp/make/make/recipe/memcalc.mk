################################################################################
# \file memcalc.mk
#
# \brief
# Defines the public facing build targets common to all recipes and includes
# the core makefiles.
#
################################################################################
# \copyright
# (c) 2025, Cypress Semiconductor Corporation (an Infineon company) or
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

# memcalc version
_MTB_RECIPE__MEMREPORT_VERSIONS_SUPPORTED:=$(filter $(MTB_RECIPE__MEMREPORT_SUPPORT),$(CY_TOOL_memory_report_SUPPORTED_INTERFACES))
_MTB_RECIPE__MEMREPORT_VERSION:=$(lastword $(strip $(_MTB_RECIPE__MEMREPORT_VERSIONS_SUPPORTED)))

ifeq (,$(_MTB_RECIPE__MEMREPORT_VERSION))
ifeq (,$(_MTB_RECIPE__NOT_SUPPORT_LEGACY_MEMCALC))

ifeq ($(TOOLCHAIN),A_Clang)
_MTB_RECIPE__GEN_READELF=
_MTB_RECIPE__MEMORY_CAL=
else
ifeq ($(TOOLCHAIN),LLVM_ARM)
_MTB_RECIPE__READELF=$(MTB_TOOLCHAIN_LLVM_ARM__READELF)
else
_MTB_RECIPE__READELF=$(MTB_TOOLCHAIN_GCC_ARM__READELF)
endif
_MTB_RECIPE__GEN_READELF=$(_MTB_RECIPE__READELF) -Sl $(_MTB_RECIPE__TARG_FILE) > $(MTB_TOOLS__OUTPUT_CONFIG_DIR)/$(APPNAME).readelf
_MTB_RECIPE__MEM_CALC=\
	bash --norc --noprofile\
	$(MTB_TOOLS__CORE_DIR)/make/scripts/memcalc.bash\
	$(MTB_TOOLS__OUTPUT_CONFIG_DIR)/$(APPNAME).readelf\
	$(_MTB_RECIPE__DEVICE_FLASH_KB)\
	$(_MTB_RECIPE__START_FLASH)
endif

_MTB_RECIPE__MEMCALC_CACHE=$(MTB_TOOLS__OUTPUT_CONFIG_DIR)/memcalc_cache.txt

ifeq ($(LIBNAME),)
$(_MTB_RECIPE__MEMCALC_CACHE): $(_MTB_RECIPE__TARG_FILE) | app
	$(MTB__NOISE)echo Calculating memory consumption: $(DEVICE) $(TOOLCHAIN) $(MTB_TOOLCHAIN_OPTIMIZATION)
	$(MTB__NOISE)echo
	$(MTB__NOISE)$(_MTB_RECIPE__GEN_READELF)
	$(MTB__NOISE)$(_MTB_RECIPE__MEM_CALC) > $@
	$(MTB__NOISE)echo

memcalc: $(_MTB_RECIPE__MEMCALC_CACHE)
	$(MTB__NOISE)cat $(_MTB_RECIPE__MEMCALC_CACHE)
else
memcalc:
	@:
endif

endif #ifneq (,$(_MTB_RECIPE__NOT_SUPPORT_LEGACY_MEMCALC))
else #ifeq (,$(_MTB_RECIPE__MEMREPORT_VERSION))

ifeq (PROJECT,$(MTB_TYPE))
_MTB_RECIPE__MEMREPORT_OUT_DIR:=$(_MTB_RECIPE__APP_HEX_DIR)
else
_MTB_RECIPE__MEMREPORT_OUT_DIR:=$(MTB_TOOLS__OUTPUT_CONFIG_DIR)
endif
_MTB_RECIPE__MEMREPORT_USAGE_OUT:=$(_MTB_RECIPE__MEMREPORT_OUT_DIR)/memreport.txt
_MTB_RECIPE__MEMREPORT_JSON_OUT:=$(_MTB_RECIPE__MEMREPORT_OUT_DIR)/memreport.json

ifeq (,$(MTB_APPLICATION_SUBPROJECTS))
memcalc : application_memcalc
application_memcalc : $(_MTB_RECIPE__TARG_FILE) | app
# Just building the current project with build_proj. In this case run memory report on the current project's elf file.
_MTB_RECIPE__MEMREPORT_ELF_FILES:=$(_MTB_RECIPE__TARG_FILE)
else #ifeq (,$(MTB_APPLICATION_SUBPROJECTS))
# Building the application. In this case run memory report on the entire application.
application_postbuild: application_memcalc
_MTB_RECIPE__MEMREPORT_ELF_FILES:=$(foreach project,$(MTB_APPLICATION_SUBPROJECTS),$(_MTB_RECIPE__PRJ_HEX_DIR)/$(project).$(MTB_RECIPE__SUFFIX_TARGET))
ifeq ($(COMBINE_SIGN_JSON),)
application_memcalc: $(_MTB_RECIPE__APP_HEX_FILE)
else
application_memcalc: sign_combine
endif

endif #ifeq (,$(MTB_APPLICATION_SUBPROJECTS))


ifneq (,$(_MTB_RECIPE__START_FLASH))
ifneq (,$(_MTB_RECIPE__DEVICE_FLASH_KB))
_MTB_RECIPE__MEMCALC_LEGACY_ARGS+=--legacy_memory FLASH,$(_MTB_RECIPE__START_FLASH),$(_MTB_RECIPE__DEVICE_FLASH_KB)
endif
endif

application_memcalc:
ifneq (,$(_MTB_RECIPE__MEMREPORT_ELF_FILES))
	$(MTB__NOISE)mkdir -p $(_MTB_RECIPE__MEMREPORT_OUT_DIR)
	$(MTB__NOISE)$(CY_TOOL_memory_report_EXE_ABS) --bsp_dir $(SEARCH_TARGET_$(TARGET)) $(foreach f,$(_MTB_RECIPE__MEMREPORT_ELF_FILES),--elf $(f)) --out_usage $(_MTB_RECIPE__MEMREPORT_USAGE_OUT) --out_json $(_MTB_RECIPE__MEMREPORT_JSON_OUT) $(_MTB_RECIPE__MEMCALC_LEGACY_ARGS)
	$(MTB__NOISE)cat $(_MTB_RECIPE__MEMREPORT_USAGE_OUT)
endif

endif #ifeq (,$(_MTB_RECIPE__MEMREPORT_VERSION))

.PHONY: application_memcalc memcalc
