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

# The script parses the parameters and generates two types of data. The first is a JSON
# result that can be passed back to ModusToolbox for connectivity DRC processing.
# The second is a set of PPC locations that are assigned to each domain.

set param_dict_string [lindex $argv 0]
set param_dict [dict create {*}$param_dict_string]

set regCnt [dict get $param_dict "regCnt"]
set locationCnt [dict get $param_dict "locationCnt"]

# Create JSON object with all the resources and their associated domains.
# This is used for DRC processing to make sure connected items are not being
# driven by less secure items.
set objs {}
for {set idx 0} {$idx < $locationCnt} {incr idx} {

    set valid [dict get $param_dict [format "valid_%d" $idx]]

    if {$valid} {
        set id "parent_$idx"
        set name [dict get $param_dict [format "location_%d" $idx]]
        set domain [dict get $param_dict $id]
        set associated [dict get $param_dict [format "associated_%d" $idx]]

        # Build JSON array
        set obj " {"
        append obj " \"paramId\": \"$id\","
        append obj " \"paramDisplay\": \"$name\","
        append obj " \"domain\": \"$domain\","
        append obj " \"associated\": \"$associated\""
        append obj " }"
        lappend objs $obj
    }
}

# Create mapping of each domain to all the PPC regions that need to be
# configured for it.
array set domainToRegions {}

for {set idx 0} {$idx < $regCnt} {incr idx} {

    set valid [dict get $param_dict [format "reg%d_valid" $idx]]

    if {$valid} {
        set id "reg$idx"
        set domain [dict get $param_dict $id]
        set region [dict get $param_dict [format "reg%d_enum_name" $idx]]

        # Create dictionary of unique domains with their associated regions
        # Filter out regions beforehand that initialization should not touch:
        # Filter if peri 0 and access to PC0 or if PPC1_PPC_PPC_SECURE/PPC1_PPC_PPC_NONSECURE
        # Regions that meet that criteria will break functionality if configured at runtime initialization
        set peri [dict get $param_dict "peri"]
        set pcMask [dict get $param_dict [format "reg%d_pcMask" $idx]]

        set shouldFilter [expr { ( ($peri == 0) && ( ($pcMask & 0x01) != 0 ) ) || ( $region eq "PROT_PERI1_PPC1_PPC_PPC_SECURE" || $region eq "PROT_PERI1_PPC1_PPC_PPC_NONSECURE" ) }]

        if {$domain ne "" && $region ne "" && !$shouldFilter} {
            if {[info exists domainToRegions($domain)]} {
                lappend domainToRegions($domain) $region
            } else {
                set domainToRegions($domain) [list $region]
            }
        }
    }
}

set json "{"
append json " \"parameters\": \["
append json [join $objs ", "]
append json " ]"
append json "}"

# Output the JSON
puts ModusToolbox param:json=$json

foreach {key value} [array get domainToRegions] {
    puts ModusToolbox param:$key=$value
}
