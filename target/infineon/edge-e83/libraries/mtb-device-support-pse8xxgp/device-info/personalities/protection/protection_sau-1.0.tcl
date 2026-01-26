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

const SUCCESS 0
const ERROR_ARG_COUNT 1
const ERROR_ARG_VALUE 2

set param_dict_string [lindex $argv 0]
set param_dict [dict create {*}$param_dict_string]

set channelName stdout

if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

proc sort_hexes {regionStarts regionEnds regionAttributes} {
    # Split the comma-separated lists
    set startList [split $regionStarts ","]
    set endList [split $regionEnds ","]
    set attrList [split $regionAttributes ","]
    # Build a list of {sortValue start end attribute}
    set combined {}
    set count [llength $startList]
    for {set i 0} {$i < $count} {incr i} {
        set start [string trim [lindex $startList $i]]
        set end [string trim [lindex $endList $i]]
        set attr [string trim [lindex $attrList $i]]
        if {$start eq ""} { continue }
        lappend combined [list $start $start $end $attr]
    }
    # Sort by the numeric value
    set sorted [lsort -integer -index 0 $combined]
    # Build the sorted start end and attribute lists
    set sortedStartList {}
    set sortedEndList {}
    set sortedAttrList {}
    foreach entry $sorted {
        lappend sortedStartList [lindex $entry 1]
        lappend sortedEndList [lindex $entry 2]
        lappend sortedAttrList [lindex $entry 3]
    }
    # Return as a dict for clarity
    return [dict create starts [join $sortedStartList ","] ends [join $sortedEndList ","] attrs [join $sortedAttrList ","]]
}

proc merge_adjacent_nsc {sortedMapping} {
    set unmergedStarts [split [dict get $sortedMapping starts] ","]
    set unmergedEnds [split [dict get $sortedMapping ends] ","]
    set unmergedAttrs [split [dict get $sortedMapping attrs] ","]

    set mergedStarts {}
    set mergedEnds {}
    set mergedAttrs {}

    set i 0
    while {$i < [llength $unmergedStarts]} {
        set currStart [lindex $unmergedStarts $i]
        set currEnd [lindex $unmergedEnds $i]
        set currAttr [lindex $unmergedAttrs $i]

        # If current is NON_SECURE_CALLABLE, check for adjacent NON_SECURE_CALLABLE regions
        if {$currAttr eq "NON_SECURE_CALLABLE"} {
            set j [expr {$i + 1}]
            set lastEnd $currEnd
            while {($j < [llength $unmergedStarts]) &&
              ([lindex $unmergedAttrs $j] eq "NON_SECURE_CALLABLE") &&
              [expr {[lindex $unmergedStarts $j]}] == $lastEnd} {
                set lastEnd [lindex $unmergedEnds $j]
                incr j
            }
            lappend mergedStarts $currStart
            lappend mergedEnds $lastEnd
            lappend mergedAttrs "NON_SECURE_CALLABLE"
            set i $j
        } else {
            # Not NON_SECURE_CALLABLE, just append as is
            lappend mergedStarts $currStart
            lappend mergedEnds $currEnd
            lappend mergedAttrs $currAttr
            incr i
        }
    }

    return [dict create starts [join $mergedStarts ","] ends [join $mergedEnds ","] attrs [join $mergedAttrs ","]]
}

proc strip_non_nsc {sortedMapping} {
    set unmergedStarts [split [dict get $sortedMapping starts] ","]
    set unmergedEnds [split [dict get $sortedMapping ends] ","]
    set unmergedAttrs [split [dict get $sortedMapping attrs] ","]

    set mergedStarts {}
    set mergedEnds {}
    set mergedAttrs {}

    set i 0
    while {$i < [llength $unmergedStarts]} {
        set currStart [lindex $unmergedStarts $i]
        set currEnd [lindex $unmergedEnds $i]
        set currAttr [lindex $unmergedAttrs $i]

        # If current is NON_SECURE_CALLABLE, check for adjacent NON_SECURE_CALLABLE regions
        if {$currAttr eq "NON_SECURE_CALLABLE"} {
            # NON_SECURE_CALLABLE, just append as is
            lappend mergedStarts [format "0x%08x" $currStart]
            lappend mergedEnds [format "0x%08x" [expr {$currEnd - 1}]]
            lappend mergedAttrs $currAttr
            incr i
        } else {
            # Merge all consecutive non-NSC regions
            set mergeStart [lindex $unmergedStarts $i]
            set mergeEnd [lindex $unmergedEnds $i]
            set j [expr {$i + 1}]
            while {$j < [llength $unmergedStarts] && [lindex $unmergedAttrs $j] ne "NON_SECURE_CALLABLE"} {
                set mergeEnd [lindex $unmergedEnds $j]
                incr j
            }
            lappend mergedStarts [format "0x%08x" $mergeStart]
            lappend mergedEnds [format "0x%08x" [expr {$mergeEnd - 1}]]
            lappend mergedAttrs "NON_SECURE"
            set i $j
        }
    }

    # Ensure first start is 0x00000000 and last end is 0xffffffff
    if {[llength $mergedStarts] > 0} {
        set mergedStarts [lreplace $mergedStarts 0 0 "0x00000000"]
    }
    # Checks if the last entry in the mergedEnds list is not 0xffffffff and the corresponding attribute in mergedAttrs is "NON_SECURE_CALLABLE".
    # If so, appends a new region starting at (last mergedEnds + 1) and ending at 0xffffffff with the attribute "NON_SECURE".
    # Otherwise, if the last mergedEnds is not 0xffffffff, updates the last entry to 0xffffffff.
    # This ensures that the merged region list is properly terminated and attributes are set correctly for non-secure callable regions.
    if {[lindex $mergedEnds end] ne "0xffffffff" && [lindex $mergedAttrs end] eq "NON_SECURE_CALLABLE"} {
        # Append new start as (last mergedEnds + 1)
        set lastEnd [lindex $mergedEnds end]
        set lastEndDec [expr {$lastEnd}]
        set newStart [format "0x%08x" [expr {$lastEndDec + 1}]]
        lappend mergedStarts $newStart
        lappend mergedEnds "0xffffffff"
        lappend mergedAttrs "NON_SECURE"
    } else {
        if {[lindex $mergedEnds end] ne "0xffffffff"} {
            set mergedEnds [lreplace $mergedEnds end end "0xffffffff"]
        }
    }

    return [dict create starts [join $mergedStarts ","] ends [join $mergedEnds ","] attrs [join $mergedAttrs ","]]
}

proc calculate_sau_regions {} {
    # Filter valid regions based on the region being valid
    set filteredAttrs {}
    set filteredStarts {}
    set filteredEnds {}

    set memreg_count [dict get $::param_dict "memreg_count"]
    for {set idx 0} {$idx < $memreg_count} {incr idx} {
        set mem_reg_phys [dict get $::param_dict "mem_reg_phys$idx"]
        if {$mem_reg_phys ne "0xFFFFFFFF"} {
            set attrs [dict get $::param_dict "mem_reg_attr$idx"]
            set phys_start [dict get $::param_dict "mem_reg_phys_offset$idx"]
            set phys_size [dict get $::param_dict "mem_reg_phys_size$idx"]
            set phys_end [expr {$phys_start + $phys_size}]

            lappend filteredAttrs $attrs
            lappend filteredStarts [format "%#08X" $phys_start]
            lappend filteredEnds [format "%#08X" $phys_end]
        }
    }

    set sauRegionAttributes [join $filteredAttrs ","]
    set sauRegionStarts [join $filteredStarts ","]
    set sauRegionEnds [join $filteredEnds ","]

    # Combine individual lists into combined list for relation
    set sortedMapping [sort_hexes $sauRegionStarts $sauRegionEnds $sauRegionAttributes]

    # Combine Non-Secure-Callable regions that are memory-adjacent
    set nscMapping [merge_adjacent_nsc $sortedMapping]

    # Combine any non Non-Secure-Callable regions
    set trimmedMapping [strip_non_nsc $nscMapping]
    return [dict create starts [dict get $trimmedMapping starts] ends [dict get $trimmedMapping ends] attrs [dict get $trimmedMapping attrs]]
}

proc remove_nsc_from_sau {sauAttrs sauStarts sauEnds} {
    set sauAttrsList [split $sauAttrs ","]
    set sauStartsList [split $sauStarts ","]
    set sauEndsList [split $sauEnds ","]
    set idauAttrsList {}
    set idauStartsList {}
    set idauEndsList {}

    set idauCnt [dict get $::param_dict "idauCnt"]
    for {set idx 0} {$idx < $idauCnt} {incr idx} {
        set start [dict get $::param_dict "IDAUstart$idx"]
        set size [dict get $::param_dict "IDAUsize$idx"]
        set end [expr {$start + $size - 1}]
        set attrs [dict get $::param_dict "IDAUattribute$idx"]

        lappend idauAttrsList $attrs
        lappend idauStartsList [format "%#08X" $start]
        lappend idauEndsList [format "%#08X" $end]
    }

    # Build a set of NSC regions from IDAU
    set nscStartsSet {}
    set nscEndsSet {}
    for {set i 0} {$i < [llength $idauAttrsList]} {incr i} {
        if {[string trim [lindex $idauAttrsList $i]] eq "NSC"} {
            lappend nscStartsSet [string trim [lindex $idauStartsList $i]]
            lappend nscEndsSet [string trim [lindex $idauEndsList $i]]
        }
    }

    # Adapt SAU regions to exclude NSC regions from IDAU only if SAU attr is NON_SECURE
    set newSauAttrs {}
    set newSauStarts {}
    set newSauEnds {}

    for {set i 0} {$i < [llength $sauAttrsList]} {incr i} {
        set sauStart [string trim [lindex $sauStartsList $i]]
        set sauEnd [string trim [lindex $sauEndsList $i]]
        set sauAttr [lindex $sauAttrsList $i]

        if {$sauAttr eq "NON_SECURE"} {
            set regionsToAdd [list [list $sauStart $sauEnd]]

            # Check for overlap with each NSC region
            for {set j 0} {$j < [llength $nscStartsSet]} {incr j} {
                set nscStart [lindex $nscStartsSet $j]
                set nscEnd [lindex $nscEndsSet $j]
                set updatedRegions {}

                foreach region $regionsToAdd {
                    set rStart [lindex $region 0]
                    set rEnd [lindex $region 1]

                    # If no overlap, keep region as is
                    if {$rEnd < $nscStart || $rStart > $nscEnd} {
                        lappend updatedRegions [list $rStart $rEnd]
                    } else {
                        # Overlap: split region if needed
                        if {$rStart < $nscStart} {
                            lappend updatedRegions [list $rStart [expr {$nscStart - 1}]]
                        }
                        if {$rEnd > $nscEnd} {
                            lappend updatedRegions [list [expr {$nscEnd + 1}] $rEnd]
                        }
                    }
                }
                set regionsToAdd $updatedRegions
            }

            # Add resulting regions to new lists (in 8-digit Hex form)
            foreach region $regionsToAdd {
                set rStart [lindex $region 0]
                set rEnd [lindex $region 1]
                if {$rStart <= $rEnd} {
                    lappend newSauAttrs $sauAttr
                    lappend newSauStarts [format "0x%08X" $rStart]
                    lappend newSauEnds [format "0x%08X" $rEnd]
                }
            }
        } else {
            # For other attrs, just copy as is
            lappend newSauAttrs $sauAttr
            lappend newSauStarts $sauStart
            lappend newSauEnds $sauEnd
        }
    }

    return [dict create attrs [join $newSauAttrs ","] starts [join $newSauStarts ","] ends [join $newSauEnds ","]]
}

set sau_regions_results [calculate_sau_regions]
set sauRegionAttributes [dict get $sau_regions_results attrs]
set sauRegionStarts [dict get $sau_regions_results starts]
set sauRegionEnds [dict get $sau_regions_results ends]
set result [remove_nsc_from_sau $sauRegionAttributes $sauRegionStarts $sauRegionEnds]

puts $::channelName [format "param:sau_starts=%s" $sauRegionStarts]
puts $::channelName [format "param:sau_ends=%s" $sauRegionEnds]
puts $::channelName [format "param:attrs=%s" [dict get $result attrs]]
puts $::channelName [format "param:starts=%s" [dict get $result starts]]
puts $::channelName [format "param:ends=%s" [dict get $result ends]]
