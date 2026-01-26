# Copyright 2024-2025 Cypress Semiconductor Corporation
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
    uplevel 1 [list trace var $name w {error constant} ]
}

const ARG_IDX_MPC_MAPPINGS 0
const ARG_IDX_MPC_REGION_STARTS 1
const ARG_IDX_MPC_REGION_ENDS 2
const ARG_IDX_OTHER_NAME 3
const ARG_IDX_OTHER_STARTS 4
const ARG_IDX_OTHER_ENDS 5

const SUCCESS 0
const ERROR_ARG_COUNT 1
const ERROR_ARG_VALUE 2

set mpcRegionStarts {}
set mpcRegionEnds {}
set otherName ""
set otherRegionStarts {}
set otherRegionEnds {}

set channelName stdout

if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

proc all_region_mappings {mappings regions} {
    set result {}
    foreach mapping $mappings {
        if {$mapping == ""} {
            continue
        }
        foreach region $regions {
            if {$region == ""} {
                continue
            }
            lappend result [expr $mapping + $region]
        }
    }
    return $result
}

proc is_address_legal {address type} {
    for {set i 0} {$i < [llength $::mpcRegionStarts]} {incr i} {
        set mpcStart [lindex $::mpcRegionStarts $i]
        set mpcEnd [lindex $::mpcRegionEnds $i]
        if {($mpcStart < $address) && ($address < $mpcEnd)} {
            return [format "%s %s address 0x%x is between 0x%x and 0x%x." $::otherName $type $address $mpcStart $mpcEnd]
        }
    }
    return ""
}

proc check_addresses {addresses type} {
    set result {}
    foreach address $addresses {
        if {$address == ""} {
            continue
        }
        if {$::otherName == "SAU"} {
            continue
        }
        set error [is_address_legal $address $type]
        if {$error != ""} {
            lappend result $error
        }
    }
    return $result
}

proc generate_mpc_drcs {} {
    if {$::argc < $::ARG_IDX_OTHER_ENDS + 1} {
        error "Not enough base arguments."
        return $::ERROR_ARG_COUNT
    }
    set mpcMappings [split [lindex $::argv $::ARG_IDX_MPC_MAPPINGS] ";"]
    foreach mapping $mpcMappings {
        if {![string is integer $mapping]} {
            error "Mapping argument contained the non-integer $mapping."
            return $::ERROR_ARG_VALUE
        }
    }

    set mpcStartOffsets [split [lindex $::argv $::ARG_IDX_MPC_REGION_STARTS] ";"]
    foreach startOffset $mpcStartOffsets {
        if {![string is integer $startOffset]} {
            error "MPC region start argument contained the non-integer $startOffset."
            return $::ERROR_ARG_VALUE
        }
    }
    set ::mpcRegionStarts [all_region_mappings $mpcMappings $mpcStartOffsets]

    set mpcEndOffsets [split [lindex $::argv $::ARG_IDX_MPC_REGION_ENDS] ";"]
    foreach endOffset $mpcEndOffsets {
        if {![string is integer $endOffset]} {
            error "MPC region end argument contained the non-integer $endOffset."
            return $::ERROR_ARG_VALUE
        }
    }
    set ::mpcRegionEnds [all_region_mappings $mpcMappings $mpcEndOffsets]

    if {[llength $::mpcRegionStarts] != [llength $::mpcRegionEnds]} {
        error "The MPC region start and region end lists have different lengths."
        return $::ERROR_ARG_VALUE
    }

    set ::otherName [lindex $::argv $::ARG_IDX_OTHER_NAME]

    set ::otherRegionStarts [split [lindex $::argv $::ARG_IDX_OTHER_STARTS] ","]
    foreach startAddress $::otherRegionStarts {
        if {![string is integer $startAddress]} {
            error "Other region start argument contained the non-integer $startAddress."
            return $::ERROR_ARG_VALUE
        }
    }

    set ::otherRegionEnds [split [lindex $::argv $::ARG_IDX_OTHER_ENDS] ","]
    foreach endAddress $::otherRegionEnds {
        if {![string is integer $endAddress]} {
            error "Other region end argument contained the non-integer $endAddress."
            return $::ERROR_ARG_VALUE
        }
    }

    if {[llength $::otherRegionStarts] != [llength $::otherRegionEnds]} {
        error "The MPC region start and region end lists have different lengths."
        return $::ERROR_ARG_VALUE
    }

    set errors [check_addresses $::otherRegionStarts "start"]
    set errors [list {*}$errors {*}[check_addresses $::otherRegionEnds "end"]]

    puts $::channelName [format "param:drc_count=%d" [llength $errors]]
    set i 0
    foreach drc $errors {
        puts $::channelName [format "param:drc%d=%s" $i [lindex $errors $i]]
        incr i
    }

    return $::SUCCESS
}

generate_mpc_drcs
