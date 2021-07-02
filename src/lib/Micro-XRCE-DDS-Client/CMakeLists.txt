# Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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
## CMake build rules for Micro XRCE-DDS Client
################################################################################
cmake_minimum_required(VERSION 3.5.0 FATAL_ERROR)

###############################################################################
# Build options
###############################################################################
option(UCLIENT_SUPERBUILD "Enable superbuild compilation." ON)
option(UCLIENT_BUILD_TESTS "Build tests." OFF)
option(UCLIENT_BUILD_EXAMPLES "Build examples." OFF)
option(UCLIENT_INSTALL_EXAMPLES "Install examples." OFF)
option(UCLIENT_VERBOSE_SERIALIZATION "Build with serialization verbosity." OFF)
option(UCLIENT_VERBOSE_MESSAGE "Build with message verbosity." OFF)
option(UCLIENT_PIC "Control Position Independent Code." ON)
option(UCLIENT_ISOLATED_INSTALL "Install the project and dependencies into separeted folders with version control." OFF)
option(BUILD_SHARED_LIBS "Control shared/static library building." OFF)

option(UCLIENT_BUILD_CI_TESTS "Build CI test cases." OFF)
if(UCLIENT_BUILD_CI_TESTS)
    set(UCLIENT_BUILD_TESTS ON)
    set(UCLIENT_BUILD_EXAMPLES ON)
endif()

if((CMAKE_SYSTEM_NAME STREQUAL "") AND (CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux"))
    option(UCLIENT_MEMORY_TESTS "Build memory tests." OFF)
    option(UCLIENT_PERFORMANCE_TESTS "Build performance tests." OFF)
endif()

option(UCLIENT_BIG_ENDIANNESS "Set the machine endianness to big endianness (by default is little endianness)." OFF)
option(UCLIENT_PROFILE_DISCOVERY "Enable discovery profile." ON)
option(UCLIENT_PROFILE_UDP "Enable UDP transport." ON)
option(UCLIENT_PROFILE_TCP "Enable TCP transport." ON)
option(UCLIENT_PROFILE_SERIAL "Enable Serial transport." ON)
set(UCLIENT_MAX_OUTPUT_BEST_EFFORT_STREAMS 1 CACHE STRING "Set the maximum number of output best-effort streams for session.")
set(UCLIENT_MAX_OUTPUT_RELIABLE_STREAMS 1 CACHE STRING "Set the maximum number of output reliable streams for session.")
set(UCLIENT_MAX_INPUT_BEST_EFFORT_STREAMS 1 CACHE STRING "Set the maximum number of input best-effort streams for session.")
set(UCLIENT_MAX_INPUT_RELIABLE_STREAMS 1 CACHE STRING "Set the maximum number of input reliable streams for session.")
set(UCLIENT_MAX_SESSION_CONNECTION_ATTEMPTS 10 CACHE STRING "Set the number of connection attemps.")
set(UCLIENT_MIN_SESSION_CONNECTION_INTERVAL 25 CACHE STRING "Set the connection interval in milliseconds.")
set(UCLIENT_MIN_HEARTBEAT_TIME_INTERVAL 1 CACHE STRING "Set the time interval between heartbeats in milliseconds.")
set(UCLIENT_UDP_TRANSPORT_MTU 512 CACHE STRING "Set the UDP transport MTU.")
set(UCLIENT_TCP_TRANSPORT_MTU 512 CACHE STRING "Set the TCP transport MTU.")
set(UCLIENT_SERIAL_TRANSPORT_MTU 512 CACHE STRING "Set the Serial transport MTU.")

###############################################################################
# Dependencies
###############################################################################
set(_microcdr_version 1.2.0)
set(_microcdr_tag develop)

set(_deps "")
list(APPEND _deps "microcdr\;${_microcdr_version}")

###############################################################################
# Project
###############################################################################
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
if(NOT UCLIENT_SUPERBUILD)
    project(microxrcedds_client VERSION "1.2.5" LANGUAGES C)
else()
    project(uclient_superbuild NONE)
    include(${PROJECT_SOURCE_DIR}/cmake/SuperBuild.cmake)
    return()
endif()

# Set CMAKE_BUILD_TYPE to Release by default.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

###############################################################################
# Check MSVC architecture
###############################################################################
include(${PROJECT_SOURCE_DIR}/cmake/common/check_configuration.cmake)
if(MSVC OR MSVC_IDE)
    check_msvc_arch()
endif()

###############################################################################
# Load external eProsima projects.
###############################################################################
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${PROJECT_BINARY_DIR}/temp_install)

foreach(d ${_deps})
    list(GET d 0 _name)
    list(GET d 1 _version)
    find_package(${_name} ${_version} EXACT REQUIRED)
endforeach()

###############################################################################
# Sources
###############################################################################
# Check platform.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(UCLIENT_PLATFORM_LINUX ON)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(UCLIENT_PLATFORM_WINDOWS ON)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Generic")
    if(PLATFORM_NAME STREQUAL "nuttx")
        set(UCLIENT_PLATFORM_NUTTX ON)
    elseif(PLATFORM_NAME STREQUAL "zephyr")
        set(UCLIENT_PLATFORM_ZEPHYR ON)
    elseif(PLATFORM_NAME STREQUAL "LwIP")
        set(UCLIENT_PLATFORM_POSIX_NOPOLL ON)
    elseif(PLATFORM_NAME STREQUAL "FreeRTOS_Plus_TCP")
        set(UCLIENT_PLATFORM_FREERTOS_PLUS_TCP ON)
    endif()
endif()

if(UCLIENT_PLATFORM_LINUX OR UCLIENT_PLATFORM_NUTTX OR UCLIENT_PLATFORM_ZEPHYR)
    set(UCLIENT_PLATFORM_POSIX ON)
endif()

# Check external transport.
option(UCLIENT_EXTERNAL_TCP "Enable external serial transport." OFF)
option(UCLIENT_EXTERNAL_UDP "Enable external serial transport." OFF)
option(UCLIENT_EXTERNAL_SERIAL "Enable external serial transport." OFF)

# Transport sources.
set(_transport_src)

if(UCLIENT_PROFILE_UDP)
    list(APPEND _transport_src src/c/profile/transport/ip/udp/udp_transport.c)
    if(UCLIENT_EXTERNAL_UDP)
        list(APPEND _transport_src src/c/profile/transport/ip/udp/udp_transport_external.c)
    else()
        if(UCLIENT_PLATFORM_POSIX)
            list(APPEND _transport_src src/c/profile/transport/ip/udp/udp_transport_posix.c)
        elseif(UCLIENT_PLATFORM_POSIX_NOPOLL)
            list(APPEND _transport_src src/c/profile/transport/ip/udp/udp_transport_posix_nopoll.c)
        elseif(UCLIENT_PLATFORM_WINDOWS)
            list(APPEND _transport_src src/c/profile/transport/ip/udp/udp_transport_windows.c)
        elseif(UCLIENT_PLATFORM_FREERTOS_PLUS_TCP)
            list(APPEND _transport_src src/c/profile/transport/ip/udp/udp_transport_freertos_plus_tcp.c)
        endif()
    endif()
endif()

if(UCLIENT_PROFILE_TCP)
    list(APPEND _transport_src src/c/profile/transport/ip/tcp/tcp_transport.c)
    if(UCLIENT_EXTERNAL_TCP)
        list(APPEND _transport_src src/c/profile/transport/ip/tcp/tcp_transport_external.c)
    else()
        if(UCLIENT_PLATFORM_POSIX)
            list(APPEND _transport_src src/c/profile/transport/ip/tcp/tcp_transport_posix.c)
        elseif(UCLIENT_PLATFORM_WINDOWS)
            list(APPEND _transport_src src/c/profile/transport/ip/tcp/tcp_transport_windows.c)
        elseif(UCLIENT_PLATFORM_FREERTOS_PLUS_TCP)
            list(APPEND _transport_src src/c/profile/transport/ip/tcp/tcp_transport_freertos_plus_tcp.c)
        endif()
    endif()
endif()

if(UCLIENT_PROFILE_SERIAL)
    list(APPEND _transport_src src/c/profile/transport/serial/serial_transport.c)
    list(APPEND _transport_src src/c/profile/transport/serial/serial_protocol.c)
    if(UCLIENT_EXTERNAL_SERIAL)
        list(APPEND _transport_src src/c/profile/transport/serial/serial_transport_external.c)
    else()
        if(UCLIENT_PLATFORM_POSIX)
            list(APPEND _transport_src src/c/profile/transport/serial/serial_transport_posix.c)
        endif()
    endif()
endif()

if(UCLIENT_PROFILE_DISCOVERY OR UCLIENT_PROFILE_UDP OR UCLIENT_PROFILE_TCP)
    if(UCLIENT_PLATFORM_POSIX)
        list(APPEND _transport_src src/c/profile/transport/ip/ip_posix.c)
    elseif(UCLIENT_PLATFORM_POSIX_NOPOLL)
        list(APPEND _transport_src src/c/profile/transport/ip/ip_posix.c)
    elseif(UCLIENT_PLATFORM_WINDOWS)
        list(APPEND _transport_src src/c/profile/transport/ip/ip_windows.c)
    elseif(UCLIENT_PLATFORM_FREERTOS_PLUS_TCP)
        list(APPEND _transport_src src/c/profile/transport/ip/ip_freertos_plus_tcp.c)
    endif()
endif()

if(UCLIENT_PROFILE_DISCOVERY)
    list(APPEND _transport_src src/c/profile/discovery/discovery.c)
    list(APPEND _transport_src src/c/profile/transport/ip/udp/udp_transport.c)
    if(UCLIENT_PLATFORM_POSIX)
        list(APPEND _transport_src src/c/profile/discovery/transport/udp_transport_datagram_posix.c)
    elseif(UCLIENT_PLATFORM_POSIX_NOPOLL)
        list(APPEND _transport_src src/c/profile/discovery/transport/udp_transport_datagram_posix_nopoll.c)
    elseif(UCLIENT_PLATFORM_WINDOWS)
        list(APPEND _transport_src src/c/profile/discovery/transport/udp_transport_datagram_windows.c)
    elseif(UCLIENT_PLATFORM_FREERTOS_PLUS_TCP)
        list(APPEND _transport_src src/c/profile/discovery/transport/udp_transport_datagram_freertos_plus_tcp.c)
    endif()
endif()

# Other sources
set(SRCS
    src/c/core/session/stream/input_best_effort_stream.c
    src/c/core/session/stream/input_reliable_stream.c
    src/c/core/session/stream/output_best_effort_stream.c
    src/c/core/session/stream/output_reliable_stream.c
    src/c/core/session/stream/stream_storage.c
    src/c/core/session/stream/stream_id.c
    src/c/core/session/stream/seq_num.c
    src/c/core/session/session.c
    src/c/core/session/session_info.c
    src/c/core/session/submessage.c
    src/c/core/session/object_id.c
    src/c/core/serialization/xrce_types.c
    src/c/core/serialization/xrce_header.c
    src/c/core/serialization/xrce_subheader.c
    src/c/util/time.c
    src/c/core/session/common_create_entities.c
    src/c/core/session/create_entities_ref.c
    src/c/core/session/create_entities_xml.c
    src/c/core/session/read_access.c
    src/c/core/session/write_access.c
    $<$<OR:$<BOOL:${UCLIENT_VERBOSE_MESSAGE}>,$<BOOL:${UCLIENT_VERBOSE_SERIALIZATION}>>:src/c/core/log/log.c>
    ${_transport_src}
    )

###############################################################################
# Set install directories
###############################################################################
if(UCLIENT_ISOLATED_INSTALL)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}-${PROJECT_VERSION}")
endif()

include(GNUInstallDirs)
set(BIN_INSTALL_DIR     ${CMAKE_INSTALL_BINDIR}     CACHE PATH "Installation directory for binaries")
set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_INCLUDEDIR} CACHE PATH "Installation directory for C headers")
set(LIB_INSTALL_DIR     ${CMAKE_INSTALL_LIBDIR}     CACHE PATH "Installation directory for libraries")
set(DATA_INSTALL_DIR    ${CMAKE_INSTALL_DATADIR}    CACHE PATH "Installation directory for data")
if(WIN32)
    set(LICENSE_INSTALL_DIR . CACHE PATH "Installation directory for licenses")
else()
    set(LICENSE_INSTALL_DIR ${DATA_INSTALL_DIR}/${PROJECT_NAME} CACHE PATH "Installation directory for licenses")
endif()

###############################################################################
# Targets
###############################################################################
# Library
add_library(${PROJECT_NAME} ${SRCS})

set_common_compile_options(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION
        ${PROJECT_VERSION}
    SOVERSION
        ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    C_STANDARD
        99
    C_STANDARD_REQUIRED
        YES
    POSITION_INDEPENDENT_CODE
	    ${UCLIENT_PIC}
    )

target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-fdata-sections -ffunction-sections>
    )

# Set Windows shared libraries name
get_target_property(UCLIENT_TARGET_TYPE ${PROJECT_NAME} TYPE)
if((CMAKE_SYSTEM_NAME STREQUAL "Windows") AND (UCLIENT_TARGET_TYPE STREQUAL "SHARED_LIBRARY"))
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RELEASE_POSTFIX
            -${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        RELWITHDEBINFO_POSTFIX
            -${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        DEBUG_POSTFIX
            d-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        )

    target_compile_definitions(${PROJECT_NAME}
        PUBLIC
            ${PROJECT_NAME}_SHARED
        )
endif()

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        microcdr
        $<$<BOOL:$<PLATFORM_ID:Windows>>:ws2_32>
    PRIVATE
        $<$<BOOL:$<PLATFORM_ID:Linux>>:rt>
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>
    PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/c>
    )

###############################################################################
# Compile setting
###############################################################################
# Definitions
target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        $<$<BOOL:${UCLIENT_PERFORMANCE_TESTS}>:PERFORMANCE_TESTING>
    PRIVATE
        $<$<BOOL:${UCLIENT_VERBOSE_SERIALIZATION}>:UXR_SERIALIZATION_LOGS>
        $<$<BOOL:${UCLIENT_VERBOSE_MESSAGE}>:UXR_MESSAGE_LOGS>
    )

get_target_property(TARGET_TYPE ${PROJECT_NAME} TYPE)
if(MSVC OR MSVC_IDE)
    target_compile_options(${PROJECT_NAME} PRIVATE /wd4996)
    if(TARGET_TYPE STREQUAL "SHARED_LIBRARY")
        target_compile_definitions(${PROJECT_NAME}
        PUBLIC
            ${PROJECT_NAME}_SHARED
        )
    endif()
endif()

###############################################################################
# Examples
###############################################################################
if(UCLIENT_BUILD_EXAMPLES)
    add_subdirectory(examples/Deployment)
    add_subdirectory(examples/Discovery)
    add_subdirectory(examples/MultiSessionHelloWorld)
    add_subdirectory(examples/PublishHelloWorld)
    add_subdirectory(examples/PublishHelloWorldP2P)
    add_subdirectory(examples/ReplyAdder)
    add_subdirectory(examples/RequestAdder)
    add_subdirectory(examples/ShapesDemo)
    add_subdirectory(examples/SubscribeHelloWorld)
    add_subdirectory(examples/SubscribeHelloWorldP2P)
    add_subdirectory(examples/TimeSync)
endif()

###############################################################################
# Tests
###############################################################################
if(UCLIENT_BUILD_CI_TESTS)
    include(CTest)
    add_subdirectory(test/case)
endif()

if(UCLIENT_BUILD_TESTS)
    include(${PROJECT_SOURCE_DIR}/cmake/common/gtest.cmake)
    find_package(GTest REQUIRED)
    find_package(GMock REQUIRED)
    find_package(Threads REQUIRED)
    enable_testing()
    include(CTest)

    add_subdirectory(test/unitary)
    if(UCLIENT_PLATFORM_LINUX)
        add_subdirectory(test/transport/serial_comm)
    endif()
endif()

if(UCLIENT_PLATFORM_LINUX AND UCLIENT_MEMORY_TESTS)
    add_subdirectory(test/memory/consumption)
endif()

###############################################################################
# Packaging
###############################################################################
# Install library
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}Targets
    RUNTIME DESTINATION
        ${BIN_INSTALL_DIR}
    LIBRARY DESTINATION
        ${LIB_INSTALL_DIR}
    ARCHIVE DESTINATION
        ${LIB_INSTALL_DIR}
    COMPONENT libraries
    )

# Install includes
install(
    DIRECTORY
        ${PROJECT_SOURCE_DIR}/include/uxr/client/
    DESTINATION
        ${INCLUDE_INSTALL_DIR}/uxr/client
    FILES_MATCHING
        PATTERN "*.h"
    )

# Generate config.h
configure_file(${PROJECT_SOURCE_DIR}/include/uxr/client/config.h.in
    ${PROJECT_BINARY_DIR}/include/uxr/client/config.h
    )

# Install config.h
install(
    FILES
        ${PROJECT_BINARY_DIR}/include/uxr/client/config.h
    DESTINATION
        ${INCLUDE_INSTALL_DIR}/uxr/client
    )

# Export library
install(
    EXPORT
        ${PROJECT_NAME}Targets
    DESTINATION
        ${DATA_INSTALL_DIR}/${PROJECT_NAME}/cmake
    )

# Package configuration
include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/packaging/Config.cmake.in
        ${PROJECT_BINARY_DIR}/cmake/config/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION
        ${DATA_INSTALL_DIR}/${PROJECT_NAME}/cmake
    PATH_VARS
        BIN_INSTALL_DIR
        INCLUDE_INSTALL_DIR
        LIB_INSTALL_DIR
        DATA_INSTALL_DIR
    )

write_basic_package_version_file(
    ${PROJECT_BINARY_DIR}/cmake/config/${PROJECT_NAME}ConfigVersion.cmake
    VERSION
        ${PROJECT_VERSION}
    COMPATIBILITY
        SameMajorVersion
    )

install(
    FILES
        ${PROJECT_BINARY_DIR}/cmake/config/${PROJECT_NAME}Config.cmake
        ${PROJECT_BINARY_DIR}/cmake/config/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION
        ${DATA_INSTALL_DIR}/${PROJECT_NAME}/cmake
    )

# Install dependencies.
if(EXISTS ${CMAKE_BINARY_DIR}/temp_install/)
    file(GLOB _deps RELATIVE ${CMAKE_BINARY_DIR}/temp_install ${CMAKE_BINARY_DIR}/temp_install/*)
    foreach(_d ${_deps})
        install(
            DIRECTORY
                ${CMAKE_BINARY_DIR}/temp_install/${_d}$<IF:$<BOOL:${UCLIENT_ISOLATED_INSTALL}>,,/>
            DESTINATION
                ${CMAKE_INSTALL_PREFIX}$<IF:$<BOOL:${UCLIENT_ISOLATED_INSTALL}>,/../,>
            COMPONENT
                ${_d}
            USE_SOURCE_PERMISSIONS
        )
    endforeach()
endif()
