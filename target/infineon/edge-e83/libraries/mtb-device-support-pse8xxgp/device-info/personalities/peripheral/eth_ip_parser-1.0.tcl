# Copyright (c) (2024), Cypress Semiconductor Corporation (an Infineon company) or
# an affiliate of Cypress Semiconductor Corporation.
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

# From https://wiki.tcl-lang.org/page/constants
proc const {name value} {
    uplevel 1 [list set $name $value]
    uplevel 1 [list trace var $name w {error constant;} ]
}

const ARG_IDX_IN_IP 0

const SUCCESS 0
const ERROR_ARG_COUNT 1
const ERROR_ID 2
const ERROR_ARG_VALUE 3

set channelName stdout

if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

proc parse_ip {} {
    if {$::argc != $::ARG_IDX_IN_IP + 1} {
        error "IP Parser requires 1 argument:
\tstring inIPaddr - The input IP address in the format 00.00.00.00"
        return $::ERROR_ARG_COUNT
    }

    set inIPaddr [lindex $::argv $::ARG_IDX_IN_IP]

    if {![regexp {([0-999]{3}[.])} $inIPaddr]} {
        error "Unable to parse the IP address, because it does not match the hexadecimal format 00.00.00.00"
        return $::ERROR_ARG_VALUE
    }
    set inIPaddr [split $inIPaddr "."]
    return [parse_ip_internal $inIPaddr]
}

proc parse_ip_internal {inIPaddr} {
    set counter 0
    foreach idx $inIPaddr {
        puts $::channelName "param:ipField$counter=$idx"
        incr counter
    }
    return $::SUCCESS
}
parse_ip
