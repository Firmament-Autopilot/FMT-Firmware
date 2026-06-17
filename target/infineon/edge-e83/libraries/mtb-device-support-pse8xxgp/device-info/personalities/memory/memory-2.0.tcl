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

const CAPABILITES_NONE 0
const CAPABILITES_ICACHE 1
const CAPABILITES_SECURE 2
const CAPABILITES_BOTH 3

set param_dict_string [lindex $argv 0]
set param_dict [dict create {*}$param_dict_string]

set channelName stdout
if {[chan names ModusToolbox] eq "ModusToolbox"} {
  set channelName ModusToolbox
}

proc generate_shift_array_entries {memViewAddresses memViewCapabilities memViewSize} {
  # Split the semicolon-separated strings into lists
  set addressList [split $memViewAddresses ";"]
  set capabilityList [split $memViewCapabilities ";"]

  # Verify we have the same number of addresses and capabilities
  if {[llength $addressList] != [llength $capabilityList]} {
      error "Error: Address and capability lists must have the same length"
      return $::ERROR_ARG_VALUE
  }

  # Create maps to find addresses by capability
  array set capabilityToAddress {}

  # Build the mapping from capability to address
  for {set i 0} {$i < [llength $addressList]} {incr i} {
      set address [lindex $addressList $i]
      set capability [lindex $capabilityList $i]
      set capabilityToAddress($capability) $address
  }

  # Initialize output variables
  set nonSecureOutput ""
  set secureOutput ""

  # Generate non-secure shift (ICACHE -> NONE: capability 1 -> 0)
  if {[info exists capabilityToAddress($::CAPABILITES_ICACHE)] &&
      [info exists capabilityToAddress($::CAPABILITES_NONE)]} {
      set startAddr $capabilityToAddress($::CAPABILITES_ICACHE)
      set destAddr $capabilityToAddress($::CAPABILITES_NONE)
      set nonSecureOutput "start = $startAddr, size = $memViewSize, dest = $destAddr"
  }

  # Generate secure shift (BOTH -> SECURE: capability 3 -> 2)
  if {[info exists capabilityToAddress($::CAPABILITES_BOTH)] &&
      [info exists capabilityToAddress($::CAPABILITES_SECURE)]} {
      set startAddr $capabilityToAddress($::CAPABILITES_BOTH)
      set destAddr $capabilityToAddress($::CAPABILITES_SECURE)
      set secureOutput "start = $startAddr, size = $memViewSize, dest = $destAddr"
  }

  return [dict create non_secure $nonSecureOutput secure $secureOutput]
}

proc trim_shift_array_entries {untrimmedEntries} {
  # Split the semicolon-separated string into a list
  set entryList [split $untrimmedEntries ";"]

  # Convert each entry to JSON format
  set convertedList {}
  foreach entry $entryList {
    # Convert "start = 0x02000000, size = 0x00080000, dest = 0x22000000"
    # to "start" : "0x02000000", "size" : "0x00080000", "dest" : "0x22000000"
    # Split by commas and process each key=value pair
    set pairs [split $entry ","]
    set convertedPairs {}
    foreach pair $pairs {
        set pair [string trim $pair]
        if {[regexp {^(\w+) = (.+)$} $pair -> key value]} {
            lappend convertedPairs "\"$key\" : \"$value\""
        }
    }
    set convertedEntry [join $convertedPairs ", "]
    lappend convertedList $convertedEntry
  }

  # Remove duplicates using lsort -unique
  set uniqueList [lsort -unique $convertedList]

  # Join the unique entries back with semicolons
  set trimmedEntries [join $uniqueList ";"]

  return $trimmedEntries
}

proc process_memory_data {} {
  set numCores [dict get $::param_dict "numCores"]
# for {set coreIdx 0} {$coreIdx < $numCores} {incr coreIdx} {
#   set key_coreId "coreId$coreIdx"
#   set coreId [dict get $::param_dict $key_coreId]
#   set key_coreShortName "coreShortName$coreIdx"
#   set coreShortName [dict get $::param_dict $key_coreShortName]
# }

  set usedPysMemIds [dict create]

  # Build mapping of physical memory IDs to their start addresses
  # This is used later to create entries for the memReport JSON
  set physMemStartAddresses [dict create]
  set numMemories [dict get $::param_dict "numMemories"]
  for {set memIdx 0} {$memIdx < $numMemories} {incr memIdx} {
    set memoryId [dict get $::param_dict "memoryId$memIdx"]
    set uniqueAddresses {}
    for {set coreIdx 0} {$coreIdx < $numCores} {incr coreIdx} {
      set numViewMaps [dict get $::param_dict [format "numMemoryViewMaps%d_%d" $memIdx $coreIdx]]
      for {set viewIdx 0} {$viewIdx < $numViewMaps} {incr viewIdx} {
        set address [dict get $::param_dict [format "memoryViewAddress%d_%d_%d" $memIdx $coreIdx $viewIdx]]
        if {[lsearch -exact $uniqueAddresses $address] == -1} {
          lappend uniqueAddresses $address
        }
      }
    }
    dict set physMemStartAddresses $memoryId $uniqueAddresses
  }

  set numRegionsDefined [dict get $::param_dict "numRegionsDefined"]
  set reservedDomain [dict get $::param_dict "domain_reserved"]
  set memReportRegionEntries 0
  for {set regIdx 0} {$regIdx < $numRegionsDefined} {incr regIdx} {
    set key_regionPhysMemId "regionPhysMemId_$regIdx"
    set regionPhysMemId [dict get $::param_dict $key_regionPhysMemId]
    set key_regionOffset "regionOffset_$regIdx"
    set regionOffset [dict get $::param_dict $key_regionOffset]
    set key_regionSize "regionSize_$regIdx"
    set regionSize [dict get $::param_dict $key_regionSize]
    set key_regionId "regionId_$regIdx"
    set regionId [dict get $::param_dict $key_regionId]
    set key_regionDomain "regionDomain_$regIdx"
    set regionDomain [dict get $::param_dict $key_regionDomain]
#   set key_regionEndOffset "regionEndOffset_$regIdx"
#   set regionEndOffset [dict get $::param_dict $key_regionEndOffset]

    # Calculate region start addresses by adding offset to physical memory base addresses
    set regionStartAddresses {}
    if {[dict exists $physMemStartAddresses $regionPhysMemId]} {
      set physMemAddresses [dict get $physMemStartAddresses $regionPhysMemId]
      foreach baseAddr $physMemAddresses {
        # Convert hex strings to integers, add offset, convert back to hex
        set baseInt [expr $baseAddr]
        set offsetInt [expr $regionOffset]
        set regionAddr [format "0x%08X" [expr $baseInt + $offsetInt]]
        lappend regionStartAddresses $regionAddr
      }
    }

    # Create JSON entry for memory report relating to the regions
    set jsonAddresses [join [lmap addr $regionStartAddresses {format "\"%s\"" $addr}] ", "]

    # Filter out reserved domain regions
    if {$regionDomain ne $reservedDomain} {
      set jsonRegionEntry "\{ \"name\" : \"$regionId\", \"size\" : \"$regionSize\", \"start\" : \[ $jsonAddresses \] \}"
    } else {
      set jsonRegionEntry "\{ \"name\" : \"$regionId\", \"size\" : \"$regionSize\", \"start\" : \[ $jsonAddresses \], \"reserved\" : true \}"
    }
    puts $::channelName [format "param:memReportRegionEntry%d=%s" $regIdx $jsonRegionEntry]

    # Increment counter for valid memory report entries
    incr memReportRegionEntries

    # The value doesn't matter here (so 1 is used). Just need the keys.
    dict set usedPysMemIds $regionPhysMemId 1

    for {set coreIdx 0} {$coreIdx < $numCores} {incr coreIdx} {
      set key_regionCoreIsAccessible [format "regionCoreIsAccessible%d_%d" $coreIdx $regIdx]
      set regionCoreIsAccessible [dict get $::param_dict $key_regionCoreIsAccessible]
      if {$regionCoreIsAccessible} {
#       set key_regionViewMapsForCore [format "regionViewMapsForCore%d_%d" $coreIdx $regIdx]
#       set regionViewMapsForCore [dict get $::param_dict $key_regionViewMapsForCore]
        set key_numRegionViewMapsForCore [format "numRegionViewMapsForCore%d_%d" $coreIdx $regIdx]
        set numRegionViewMapsForCore [dict get $::param_dict $key_numRegionViewMapsForCore]

        set regionHasEmptyCapability -1
        set regionHasCacheCapability -1
        set regionHasSecureCapability -1
        set regionHasCacheSecureCapability -1

        for {set viewIdx 0} {$viewIdx < $numRegionViewMapsForCore} {incr viewIdx} {
#         set key_regionViewMap [format "regionViewMap%dId_%d_%d" $viewIdx $coreIdx $regIdx]
#         set regionViewMap [dict get $::param_dict $key_regionViewMap]
#         set key_regionViewMapSuffix [format "regionViewMapSuffix%dId_%d_%d" $viewIdx $coreIdx $regIdx]
#         set regionViewMapSuffix [dict get $::param_dict $key_regionViewMapSuffix]
          set key_regionViewMapIsICache [format "regionViewMapIsICache%dId_%d_%d" $viewIdx $coreIdx $regIdx]
          set regionViewMapIsICache [dict get $::param_dict $key_regionViewMapIsICache]
          set key_regionViewMapIsSecure [format "regionViewMapIsSecure%dId_%d_%d" $viewIdx $coreIdx $regIdx]
          set regionViewMapIsSecure [dict get $::param_dict $key_regionViewMapIsSecure]

          #<!--The curent map in the memory view has no cache capability and no secure capability-->
          if {!$regionViewMapIsICache && !$regionViewMapIsSecure} {
            set regionHasEmptyCapability $viewIdx
          }

          #<!--The curent map in the memory view has cache capability and no secure capability-->
          if {$regionViewMapIsICache && !$regionViewMapIsSecure} {
            set regionHasCacheCapability $viewIdx
          }

          #<!--The curent map in the memory view has no cache capability and secure capability-->
          if {!$regionViewMapIsICache && $regionViewMapIsSecure} {
            set regionHasSecureCapability $viewIdx
          }

          #<!--The curent map in the memory view has cache capability and secure capability-->
          if {$regionViewMapIsICache && $regionViewMapIsSecure} {
            set regionHasCacheSecureCapability $viewIdx
          }

        }

        puts $::channelName [format "param:regionHasEmptyCapability%d_%d=%s" $coreIdx $regIdx $regionHasEmptyCapability]
        puts $::channelName [format "param:regionHasCacheCapability%d_%d=%s" $coreIdx $regIdx $regionHasCacheCapability]
        puts $::channelName [format "param:regionHasSecureCapability%d_%d=%s" $coreIdx $regIdx $regionHasSecureCapability]
        puts $::channelName [format "param:regionHasCacheSecureCapability%d_%d=%s" $coreIdx $regIdx $regionHasCacheSecureCapability]

        set regionSelectedSuffix ""
        if {$regionHasCacheCapability >= 0} {
          # regionHasCacheCapability contains the viewIdx
          set key_regionViewMapSuffix [format "regionViewMapSuffix%dId_%d_%d" $regionHasCacheCapability $coreIdx $regIdx]
          set regionSelectedSuffix [dict get $::param_dict $key_regionViewMapSuffix]
        } elseif {$regionHasEmptyCapability >= 0} {
          # regionHasEmptyCapability contains the viewIdx
          set key_regionViewMapSuffix [format "regionViewMapSuffix%dId_%d_%d" $regionHasEmptyCapability $coreIdx $regIdx]
          set regionSelectedSuffix [dict get $::param_dict $key_regionViewMapSuffix]
        }
        puts $::channelName [format "param:regionSelectedSuffix%d_%d=%s" $coreIdx $regIdx $regionSelectedSuffix]

        set regionSelectedSecureSuffix ""
        if {$regionHasCacheSecureCapability >= 0} {
          # regionHasCacheSecureCapability contains the viewIdx
          set key_regionViewMapSuffix [format "regionViewMapSuffix%dId_%d_%d" $regionHasCacheSecureCapability $coreIdx $regIdx]
          set regionSelectedSecureSuffix [dict get $::param_dict $key_regionViewMapSuffix]
        } elseif {$regionHasSecureCapability >= 0} {
          # regionHasSecureCapability contains the viewIdx
          set key_regionViewMapSuffix [format "regionViewMapSuffix%dId_%d_%d" $regionHasSecureCapability $coreIdx $regIdx]
          set regionSelectedSecureSuffix [dict get $::param_dict $key_regionViewMapSuffix]
        }
        puts $::channelName [format "param:regionSelectedSecureSuffix%d_%d=%s" $coreIdx $regIdx $regionSelectedSecureSuffix]

        set key_coreShortName "coreShortName$coreIdx"
        set coreShortName [dict get $::param_dict $key_coreShortName]
        set regionBaseName [format "%s_%s" $coreShortName $regionId]
        puts $::channelName [format "param:regionBaseName%d_%d=%s" $coreIdx $regIdx $regionBaseName]
        puts $::channelName [format "param:regionSelectedFullName%d_%d=%s%s" $coreIdx $regIdx $regionBaseName $regionSelectedSuffix]
        puts $::channelName [format "param:regionSelectedSecureFullName%d_%d=%s%s" $coreIdx $regIdx $regionBaseName $regionSelectedSecureSuffix]

      }
    }
  }
  # Report the number of valid memory regions (i.e. not associated with reserved domain)
  puts $::channelName [format "param:memReportRegionCount=%d" $memReportRegionEntries]

  set memNonSecureOutputs {}
  set memSecureOutputs {}

  set validMemoryIds [dict create]
  set numMemories [dict get $::param_dict "numMemories"]
  for {set memIdx 0} {$memIdx < $numMemories} {incr memIdx} {
    set memoryId [dict get $::param_dict "memoryId$memIdx"]
    set memorySize [dict get $::param_dict "memorySize$memIdx"]

    # The value doesn't matter here (so 1 is used). Just need the keys.
    dict set validMemoryIds $memoryId 1

    # Generate JSON physical memory entry using pre-computed addresses
    set uniqueAddresses [dict get $physMemStartAddresses $memoryId]
    set jsonAddresses [join [lmap addr $uniqueAddresses {format "\"%s\"" $addr}] ", "]
    set jsonPhysEntry "\{ \"name\" : \"$memoryId\", \"size\" : \"$memorySize\", \"start\" : \[ $jsonAddresses \] \}"
    puts $::channelName [format "param:memReportPhysEntry%d=%s" $memIdx $jsonPhysEntry]

    for {set coreIdx 0} {$coreIdx < $numCores} {incr coreIdx} {
#     set key_memoryViewMaps [format "memoryViewMaps%d_%d" $memIdx $coreIdx]
#     set memoryViewMaps [dict get $::param_dict $key_memoryViewMaps]
      set key_numMemoryViewMaps [format "numMemoryViewMaps%d_%d" $memIdx $coreIdx]
      set numMemoryViewMaps [dict get $::param_dict $key_numMemoryViewMaps]

      set memViewAddresses {}
      set memViewCapabilities {}

      for {set viewIdx 0} {$viewIdx < $numMemoryViewMaps} {incr viewIdx} {
#       set key_memoryViewMap [format "memoryViewMap%d_%d_%d" $memIdx $coreIdx $viewIdx]
#       set memoryViewMap [dict get $::param_dict $key_memoryViewMap]
        set key_memoryViewAddress [format "memoryViewAddress%d_%d_%d" $memIdx $coreIdx $viewIdx]
        set memoryViewAddress [dict get $::param_dict $key_memoryViewAddress]
        set key_memoryViewMapIsICache [format "memoryViewMapIsICache%d_%d_%d" $memIdx $coreIdx $viewIdx]
        set memoryViewMapIsICache [dict get $::param_dict $key_memoryViewMapIsICache]
        set key_memoryViewMapIsSecure [format "memoryViewMapIsSecure%d_%d_%d" $memIdx $coreIdx $viewIdx]
        set memoryViewMapIsSecure [dict get $::param_dict $key_memoryViewMapIsSecure]

        set capability $::CAPABILITES_NONE
        if {$memoryViewMapIsICache && !$memoryViewMapIsSecure} {
          set capability $::CAPABILITES_ICACHE
        } elseif {!$memoryViewMapIsICache && $memoryViewMapIsSecure} {
          set capability $::CAPABILITES_SECURE
        } elseif {$memoryViewMapIsICache && $memoryViewMapIsSecure} {
          set capability $::CAPABILITES_BOTH
        }

        lappend memViewAddresses $memoryViewAddress
        lappend memViewCapabilities $capability

      }

      set accumulatedMemViewAddresses [join $memViewAddresses ";"]
      set accumulatedMemViewCapabilities [join $memViewCapabilities ";"]
      set shift_results [generate_shift_array_entries $accumulatedMemViewAddresses $accumulatedMemViewCapabilities $memorySize]
      set nonSecureOutputs [dict get $shift_results non_secure]
      set secureOutputs [dict get $shift_results secure]

      if {$nonSecureOutputs ne ""} {
        lappend memNonSecureOutputs $nonSecureOutputs
      }
      if {$secureOutputs ne ""} {
        lappend memSecureOutputs $secureOutputs
      }

    }

  }

  set usedMemories [dict keys $usedPysMemIds]
  set invalidMemories {}
  foreach key $usedMemories {
      if {![dict exists $validMemoryIds $key]} {
          lappend invalidMemories $key
      }
  }

  puts $::channelName [format "param:invalidUsedMemoryIdsCnt=%d" [llength $invalidMemories]]
  puts $::channelName [format "param:invalidUsedMemoryIds=%s" [join $invalidMemories ";"]]

  set accumulatedMemNonSecureOutputs [join $memNonSecureOutputs ";"]
  set accumulatedMemSecureOutputs [join $memSecureOutputs ";"]
  set shiftArrayEntriesNonSecure [trim_shift_array_entries $accumulatedMemNonSecureOutputs]
  set shiftArrayEntriesSecure [trim_shift_array_entries $accumulatedMemSecureOutputs]

  set shiftArrayEntriesTotal {}
  if {$shiftArrayEntriesNonSecure ne "" && $shiftArrayEntriesSecure ne ""} {
    set shiftArrayEntriesTotal [format "%s;%s" $shiftArrayEntriesNonSecure $shiftArrayEntriesSecure]
  } elseif {$shiftArrayEntriesNonSecure ne ""} {
    set shiftArrayEntriesTotal $shiftArrayEntriesNonSecure
  } else {
    set shiftArrayEntriesTotal $shiftArrayEntriesSecure
  }

  set numShiftArrayEntries [llength [split $shiftArrayEntriesTotal ";"]]

  puts $::channelName [format "param:shiftArrayEntriesTotal=%s" $shiftArrayEntriesTotal]
  puts $::channelName [format "param:numShiftArrayEntries=%s" $numShiftArrayEntries]
}

process_memory_data
