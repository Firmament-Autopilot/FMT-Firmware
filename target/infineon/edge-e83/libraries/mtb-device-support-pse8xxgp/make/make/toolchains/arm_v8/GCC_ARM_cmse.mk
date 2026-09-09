###############################################################################
# \file GCC_ARM_cmse.mk
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

include $(MTB_TOOLS__RECIPE_DIR)/make/toolchains/arm_v8/cmse.mk

ifeq ($(WHICHFILE),true)
$(info Processing $(lastword $(MAKEFILE_LIST)))
endif

ifneq ($(filter SECURE,$(VCORE_ATTRS)),)
MTB_TOOLCHAIN_GCC_ARM__CFLAGS+=-mcmse
MTB_TOOLCHAIN_GCC_ARM__CXXFLAGS+=-mcmse

ifneq ($(NSC_VENEER),)
MTB_TOOLCHAIN_GCC_ARM__LDFLAGS+=-Wl,--cmse-implib
ifeq ($(NSC_VENEER),$(filter $(NSC_VENEER),$(wildcard $(NSC_VENEER))))
MTB_TOOLCHAIN_GCC_ARM__LDFLAGS+=-Wl,--in-implib -Wl,$(NSC_VENEER)
endif
MTB_TOOLCHAIN_GCC_ARM__LDFLAGS+=-Wl,--out-implib -Wl,$(NSC_VENEER).tmp
endif
endif
