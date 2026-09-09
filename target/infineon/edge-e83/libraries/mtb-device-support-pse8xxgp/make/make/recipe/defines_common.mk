################################################################################
# \file defines_common.mk
#
# \brief
# Common variables and targets for defines.mk
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

MTB_RECIPE__MEMREPORT_SUPPORT:=1

################################################################################
# BSP
################################################################################

ifneq (1,$(words $(DEVICE_$(DEVICE)_CORES)))
_MTB_RECIPE__IS_MULTI_CORE_DEVICE:=true
endif

ifneq (,$(filter StandardSecure,$(DEVICE_$(DEVICE)_FEATURES)))
_MTB_RECIPE__IS_SECURE_DEVICE:=true
endif
ifneq (,$(filter SecureBoot,$(DEVICE_$(DEVICE)_FEATURES)))
_MTB_RECIPE__IS_SECURE_DEVICE:=true
endif

_MTB_RECIPE__DEVICE_DIE:=$(DEVICE_$(DEVICE)_DIE)

_MTB_RECIPE__DEVICE_FLASH_KB:=$(DEVICE_$(DEVICE)_FLASH_KB)

ifeq ($(MTB_RECIPE__CORE),CM55)
MTB_RECIPE__VFP_SELECT_DEFAULT=hardfp
endif

ifneq ($(filter $(_MTB_RECIPE__DEVICE_DIE)_PSVP,$(DEFINES)),)
_MTB_RECIPE__OPENOCD_BOARD=set BOARD psvp
endif