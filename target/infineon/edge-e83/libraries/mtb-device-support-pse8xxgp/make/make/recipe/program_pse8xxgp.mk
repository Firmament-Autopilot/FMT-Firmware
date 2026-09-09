################################################################################
# \file program_pse8xxgp.mk
#
# \brief
# This make file is called recursively and is used to build the
# resources file system. It is expected to be run from the example directory.
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

ifeq ($(BITFILE_PROVISIONED),true) # BITFILE_PROVISIONED=true for provisioned PSVP/MCU
_MTB_RECIPE__OPENOCD_ERASE=exit;
_MTB_RECIPE__OPENOCD_DEBUG=$(_MTB_RECIPE__OPENOCD_DEBUG_PREFIX) init; $(_MTB_RECIPE__REGISTERS_CONFIGS); halt;
_MTB_RECIPE__OPENOCD_PROGRAM=init; $(_MTB_RECIPE__REGISTERS_CONFIGS); halt; flash write_image erase $(_MTB_RECIPE__OPENOCD_PROGRAM_IMG); load_image $(_MTB_RECIPE__OPENOCD_PROGRAM_IMG); mww 0x52261000 0x34000400; mww 0x52260004 0x05FA0000; exit;
else ifeq ($(BITFILE_PROVISIONED),false) # BITFILE_PROVISIONED=false for bare bitfile with MVP bootrom
_MTB_RECIPE__APP_LOAD_ADDR=0x24080000
_MTB_RECIPE__APP_SP=$(_MTB_RECIPE__APP_LOAD_ADDR)
_MTB_RECIPE__APP_PC=$(shell printf "0x%x" $$(($(_MTB_RECIPE__APP_LOAD_ADDR) + 0x04)))
_MTB_RECIPE__OPENOCD_PREPARE_APP=init; reset init; load_image $(_MTB_RECIPE__OPENOCD_PROGRAM_IMG);
_MTB_RECIPE__OPENOCD_DEBUG=$(_MTB_RECIPE__OPENOCD_DEBUG_PREFIX) $(_MTB_RECIPE__OPENOCD_PREPARE_APP)
_MTB_RECIPE__OPENOCD_PROGRAM=$(_MTB_RECIPE__OPENOCD_PREPARE_APP); reg sp [mrw $(_MTB_RECIPE__APP_SP)]; reg pc [mrw $(_MTB_RECIPE__APP_PC)]; reg xPSR 0x01000000; resume; exit;
else # default case for Virgin Si
_MTB_RECIPE__OPENOCD_ERASE=init; reset init; $(_MTB_RECIPE__OPENOCD_PROBE_FREQUENCY)erase_all; exit;
_MTB_RECIPE__OPENOCD_DEBUG=$(_MTB_RECIPE__OPENOCD_DEBUG_PREFIX) init; reset init;
_MTB_RECIPE__OPENOCD_PROGRAM=init; reset init; $(_MTB_RECIPE__OPENOCD_PROBE_FREQUENCY)flash write_image erase $(_MTB_RECIPE__OPENOCD_PROGRAM_IMG); verify_image $(_MTB_RECIPE__OPENOCD_PROGRAM_IMG); reset run; shutdown;
endif #($(BITFILE_PROVISIONED),true)
