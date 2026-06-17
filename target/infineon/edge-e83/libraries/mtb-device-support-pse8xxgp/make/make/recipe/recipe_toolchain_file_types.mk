################################################################################
# \file recipe_toolchain_file_types.mk
#
# \brief
# Standard recipe setup of toolchain specific file suffixes.
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

# Compiler, assember, linker, etc. file extensions.
MTB_RECIPE__SUFFIX_S  :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_S)
MTB_RECIPE__SUFFIX_s  :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_s)
MTB_RECIPE__SUFFIX_C  :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_C)
MTB_RECIPE__SUFFIX_H  :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_H)
MTB_RECIPE__SUFFIX_CPP:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_CPP)
MTB_RECIPE__SUFFIX_CXX:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_CXX)
MTB_RECIPE__SUFFIX_CC :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_CC)
MTB_RECIPE__SUFFIX_HPP:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_HPP)
MTB_RECIPE__SUFFIX_O  :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_O)
MTB_RECIPE__SUFFIX_A  :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_A)
MTB_RECIPE__SUFFIX_AR :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_AR)
MTB_RECIPE__SUFFIX_D  :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_D)
MTB_RECIPE__SUFFIX_LS :=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_LS)
MTB_RECIPE__SUFFIX_MAP:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_MAP)
MTB_RECIPE__SUFFIX_TARGET:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_TARGET)
MTB_RECIPE__SUFFIX_PROGRAM:=$(MTB_TOOLCHAIN_$(TOOLCHAIN)__SUFFIX_PROGRAM)
