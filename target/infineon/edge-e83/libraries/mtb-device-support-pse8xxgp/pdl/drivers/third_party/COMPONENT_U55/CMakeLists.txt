#
# SPDX-FileCopyrightText: Copyright 2019-2021, 2023-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the License); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an AS IS BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.15.6)

project(ethosu_core_driver VERSION 0.0.1)

#
# Build options
#

option(DRIVER_PMU_AUTOINIT "Enable PMU boot auto-initialization" OFF)

set(CMSIS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmsis" CACHE PATH "Path to CMSIS.")

set(LOG_NAMES err warning info debug)
set(ETHOSU_LOG_ENABLE ON CACHE BOOL "Toggle driver logs on/off (Defaults to ON)")
set(ETHOSU_LOG_SEVERITY "warning" CACHE STRING "Driver log severity level ${LOG_NAMES} (Defaults to 'warning')")
set(ETHOSU_TARGET_NPU_CONFIG "ethos-u55-128" CACHE STRING "Default NPU configuration")
set(ETHOSU_INFERENCE_TIMEOUT "" CACHE STRING "Inference timeout (unit is implementation defined)")
set_property(CACHE ETHOSU_LOG_SEVERITY PROPERTY STRINGS ${LOG_NAMES})

#
# Global settings
#

# Check that ETHOSU_LOG_SEVERITY has one of the supported levels
list(FIND LOG_NAMES ${ETHOSU_LOG_SEVERITY} LOG_SEVERITY)
if (${LOG_SEVERITY} EQUAL -1)
    message(FATAL_ERROR "Unsupported log level ${ETHOSU_LOG_SEVERITY}")
endif()

# Make include directories available for current- and sub projects
include_directories(include src)
include_directories(${CMSIS_PATH}/CMSIS/Core/Include)

#
# Build libraries
#

# Build driver library
add_library(ethosu_core_driver STATIC)
target_include_directories(ethosu_core_driver PUBLIC include)
target_sources(ethosu_core_driver PRIVATE src/ethosu_driver.c src/ethosu_pmu.c)

string(TOLOWER ${ETHOSU_TARGET_NPU_CONFIG} ETHOSU_TARGET_NPU_CONFIG)
if(ETHOSU_TARGET_NPU_CONFIG MATCHES "^ethos-(u[0-9]+)-([0-9]+$)")
    set(ETHOSU_ARCH ${CMAKE_MATCH_1})
    set(ETHOSU_MACS ${CMAKE_MATCH_2})
else()
    message(FATAL_ERROR "Invalid Ethos-U target configuration '${ETHOSU_TARGET_NPU_CONFIG}")
endif()

target_compile_definitions(ethosu_core_driver PUBLIC
    ETHOSU_ARCH=${ETHOSU_ARCH}
    ETHOS$<UPPER_CASE:${ETHOSU_ARCH}>)

if (ETHOSU_ARCH STREQUAL "u55" OR ETHOSU_ARCH STREQUAL "u65")
    target_sources(ethosu_core_driver PRIVATE src/ethosu_device_u55_u65.c)
elseif (ETHOSU_ARCH STREQUAL "u85")
    target_sources(ethosu_core_driver PRIVATE src/ethosu_device_u85.c)
else()
    message(FATAL_ERROR "Invalid NPU configuration")
endif()

if(NOT "${ETHOSU_INFERENCE_TIMEOUT}" STREQUAL "")
    target_compile_definitions(ethosu_core_driver PRIVATE
        ETHOSU_SEMAPHORE_WAIT_INFERENCE=${ETHOSU_INFERENCE_TIMEOUT})
    set(ETHOSU_INFERENCE_TIMEOUT_TEXT ${ETHOSU_INFERENCE_TIMEOUT})
else()
    set(ETHOSU_INFERENCE_TIMEOUT_TEXT "Default (no timeout)")
endif()
# Set the log level for the target
target_compile_definitions(ethosu_core_driver PRIVATE
    ETHOSU_LOG_SEVERITY=${LOG_SEVERITY}
    ETHOSU_LOG_ENABLE=$<BOOL:${ETHOSU_LOG_ENABLE}>)

# Install library and include files
install(TARGETS ethosu_core_driver LIBRARY DESTINATION "lib")
install(FILES include/ethosu_device.h include/ethosu_driver.h include/pmu_ethosu.h
        DESTINATION "include")

# Define ETHOSU macro
target_compile_definitions(ethosu_core_driver PUBLIC ETHOSU)

# Print build status
message(STATUS "*******************************************************")
message(STATUS "PROJECT_NAME                           : ${PROJECT_NAME}")
message(STATUS "ETHOSU_TARGET_NPU_CONFIG               : ${ETHOSU_TARGET_NPU_CONFIG}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR                 : ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMSIS_PATH                             : ${CMSIS_PATH}")
message(STATUS "ETHOSU_LOG_ENABLE                      : ${ETHOSU_LOG_ENABLE}")
message(STATUS "ETHOSU_LOG_SEVERITY                    : ${ETHOSU_LOG_SEVERITY}")
message(STATUS "ETHOSU_INFERENCE_TIMEOUT               : ${ETHOSU_INFERENCE_TIMEOUT_TEXT}")
message(STATUS "*******************************************************")
