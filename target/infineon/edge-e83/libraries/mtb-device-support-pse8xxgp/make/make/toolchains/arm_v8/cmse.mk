###############################################################################
# \file cmse.mk
#
# \brief
# ARM_v8 cmse Compiler toolchain configuration.
#
################################################################################
# \copyright
# (c) 2023-2025, Cypress Semiconductor Corporation (an Infineon company) or
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

ifneq ($(NSC_VENEER),)
clean_proj: _print_clean_nsc_veneer

_print_clean_nsc_veneer:
	$(info )
	$(info NOTE: This secure project uses a non-secure callable veneer object file: $(NSC_VENEER).)
	$(info This file is not automatically cleaned by the 'make clean'. It is recommended that you save this file into version control.)
	$(info )

ifneq ($(filter SECURE,$(VCORE_ATTRS)),)
# The veneer files need to be copy back from the temp file back into the none temp version.
# The linker generate an error if the input veneer file is the same as output veneer.
# Generate a temp veneer and replace the original as a post build step.
_mtb_cmse_post_build_copy:| $(_MTB_RECIPE__TARG_FILE)
	$(MTB__NOISE)[ ! -f $(NSC_VENEER).tmp ] || cmp -s $(NSC_VENEER).tmp $(NSC_VENEER) || mv -f $(NSC_VENEER).tmp $(NSC_VENEER);\
	rm -f $(NSC_VENEER).tmp

ifeq (,$(filter ide_postbuild,$(MAKECMDGOALS)))
# If running ide_postbuild, don't create veneers. Both UV and EW have GUI settings for trustzone veneer, it managed by the IDE.
recipe_postbuild:_mtb_cmse_post_build_copy
endif

_RECIPE__VENEER_DIR:=$(dir $(NSC_VENEER))

ifneq (,$(_RECIPE__VENEER_DIR))
$(_MTB_RECIPE__TARG_FILE):| $(_RECIPE__VENEER_DIR)
$(_RECIPE__VENEER_DIR):
	$(MTB__NOISE)mkdir -p $(_RECIPE__VENEER_DIR)
endif

.PHONY:_mtb_cmse_post_build_copy

CY_IGNORE+=$(NSC_VENEER)
endif #ifneq ($(filter SECURE,$(VCORE_ATTRS)),)

ifneq ($(filter NON_SECURE,$(VCORE_ATTRS)),)
MTB_RECIPE__LIBS+=$(NSC_VENEER)
endif
endif #ifneq ($(NSC_VENEER),)

################################################################################
# Vulnerabilities check
################################################################################
ifneq ($(filter SECURE,$(VCORE_ATTRS)),)
ifneq ($(VFP_SELECT),softfloat)
$(info Use of the FPU on a secure project may be susceptible to an VLLDM Instruction Security\
Vulnerability (CVE-2021-35465). Verify the toolchain you are using already provides a workaround\
or use VFP_SELECT=softfloat instead of VFP_SELECT=$(VFP_SELECT). For more information see\
https://developer.arm.com/Arm%20Security%20Center/VLLDM%20Instruction%20Security%20Vulnerability)
endif # ($(VFP_SELECT),softfloat)
endif # ($(filter SECURE,$(VCORE_ATTRS)),)
