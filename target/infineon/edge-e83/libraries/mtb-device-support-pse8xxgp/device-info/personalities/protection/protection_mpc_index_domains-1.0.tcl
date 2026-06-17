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

const ARG_IDX_DOMAINS_SHIFT_ENTRY 0

set channelName stdout

if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

proc create_indexed_list {unsplitDomains} {
    set domains [split $unsplitDomains ","]
    set result {}
    set idx 0
    foreach domain $domains {
        if {$domain eq "reserved"} {
            # Set the reserved to -1, invalid index
            lappend result -1
        } else {
            # Set the others to be autoincremeted
            lappend result $idx
            incr idx
        }
    }
    return $result
}


set unsplitDomains [lindex $::argv $::ARG_IDX_DOMAINS_SHIFT_ENTRY]
set indexedDomains [create_indexed_list $unsplitDomains]
puts $::channelName [format "param:mpc_indexed_domains=%s" [join $indexedDomains ","]]
