
# This script is used to calculate values for the MXS22 ECO.

# Usage:
# - Call this script with the required input arguments to calculate the ECO clock values.
#    Arguments: freq esr cshunt ctrace cmotional drive_level ext_cap cload c1 c2

proc read_binary_file {file} {
    set fp [open $file r]
    fconfigure $fp -translation binary
    set binary_data [read $fp]
    close $fp
    set data {}
    binary scan $binary_data S* data
    return $data
}

proc decode_cdac_value {row} {
    set index [expr {int($row) % 32}]  ;# Ensure integer for modulo
    set raw [lindex $::cdac_data $index]
    set result [expr {double($raw & 0xffff) / 1000}]
    #puts "cdac = $index     $raw    $result"
    return $result
}

proc decode_table_value {row column} {
    set index [expr {int($row) * 16 + int($column)}]  ;# Ensure integer for indexing
    set raw [lindex $::table_data $index]
    return $raw
}

# NOTE: This should be able to just find the min value among the 32 cdac values without needing the start & end values
proc get_cdac_min_row {start end dac_cap} {
    set row 0
    set min 1000
    set start_int [expr {int($start)}]
    set end_int [expr {int($end)}]
    for {set index $start_int} {$index <= $end_int} {incr index} {
        set real_val [decode_cdac_value $index]
        set temp [expr {$real_val - $dac_cap}]
        set cdac [expr abs($temp)]
        if {$cdac < $min} {
            set min $cdac
            set row $index
        }
    }
    return $row
}

proc get_cload_min_value {start end cpad ctrace cload_total} {
    set row 0
    set min 1000
    set cload 0
    set start_int [expr {int($start)}]
    set end_int [expr {int($end)}]
    for {set index $start_int} {$index <= $end_int} {incr index} {
        set real_val [decode_cdac_value $index]
        set temp [expr {($real_val + $ctrace + $cpad) / 2}]
        set temp2 [expr {$temp - $cload_total}]
        set val [expr abs($temp2)]
        #puts "val  = $val   $temp2  $temp   $real_val"
        if {$val < $min} {
            set row $index
            set min $val
            set cload $temp
        }
    }
    return [list $row $min $cload]
}

proc get_table_gtrim_col {row rneg_min} {
    for {set index 0} {$index < 16} {incr index} {
        set real_val [decode_table_value $row $index]
        if {$real_val > $rneg_min} {
            return $index
        }
    }
    return -1
}

proc get_table_max_rneg {row} {
    set max -1000
    for {set index 0} {$index < 16} {incr index} {
        set real_val [decode_table_value $row $index]
        #puts "$real_val"
        if {$real_val > $max} {
            set max $real_val
        }
    }
    return $max
}

proc eco_solver {argc argv} {

    if { $argc != 11 } {
        puts "Invalid number of arguments. Expected 11:"
        puts "    freq esr cshunt ctrace cmotional drive_level ext_cap cload c1 c2 eco_solver_path"
    }

    # INPUT ARGUMENTS
    set freq         [expr {double([lindex $argv 0])}]  ;# Always treat as float
    set esr         [lindex $argv 1]
    set cshunt      [lindex $argv 2]
    set ctrace      [lindex $argv 3]
    set cmotional   [lindex $argv 4]
    set drive_level [lindex $argv 5]
    set ext_cap     [lindex $argv 6]
    set cload       [lindex $argv 7]
    set c1          [lindex $argv 8]
    set c2          [lindex $argv 9]
    set path        [lindex $argv 10]

    #puts "$::cdac_data"

    # CALCULATIONS
    set iboost                      [expr {$freq < 17 ? 0 : 1}]
    set rneg                        [expr {$freq < 13 ? 5 : $freq < 19 ? 6 : 7}]
    set cpad                        3
    set effective_esr               [expr {$esr * (1 + double($cshunt) / $cload) * (1 + double($cshunt) / $cload)}]
    set required_rneg               [expr {$rneg * $esr}]
    set dac_cap                     [expr {2 * $cload - $ctrace - $cpad}]
    set required_dac_cap            [expr {$dac_cap < [decode_cdac_value 0] ? -1 : $dac_cap > [decode_cdac_value 31] ? -1 : $dac_cap}]
    set freq_match_starting_row     [expr {int(($freq - 4) * 10 * 32 * 7)}]  ;# Ensure integer for row
    set cshunt_match_starting_row   [expr {int($freq_match_starting_row + 32 * ($cshunt - 1))}]
    set cshunt_match_ending_row     [expr {int($cshunt_match_starting_row + 32 - 1)}]
    set cdac_match_row              [get_cdac_min_row $cshunt_match_starting_row $cshunt_match_ending_row $required_dac_cap]
#   set cdac_closest_match_min      [decode_cdac_value $cdac_match_row] #FIXME: This needs to min value from get_cdac_min_row if actually used anywhere
    set matched_ctrim               [expr {int($cdac_match_row) % 32}]
    set matched_cdac                [decode_cdac_value $matched_ctrim]
    set matched_gtrim_col           [get_table_gtrim_col $cdac_match_row $required_rneg]
    set matched_rneg                [decode_table_value $cdac_match_row $matched_gtrim_col]
    set max_available_rneg          [get_table_max_rneg $cdac_match_row]
    set lmotional                   [expr {1000000 / ($cmotional * (2 * 3.1415 * $freq) * (2 * 3.1415 * $freq))}]
    set tau1                        [expr {double(2000 * $lmotional) / ($matched_rneg - $effective_esr)}]
    set vi                          1
    set vf                          200
    set tpulse                      50
    set tamp1                       [expr {$tau1 * log($vf / $vi)}]
    set twd                         [expr {1024.0 / $freq}]
    set tstartup_total              [expr {($tpulse + $tamp1 + $twd) / 1000}]
    set vpp                         300
    set dl1                         [expr {2 * $effective_esr * (3.1415 * $freq * $cload * $vpp) * (3.1415 * $freq * $cload * $vpp) / 1000000000000}]

    set ctrim2                      0
    set cdac0                       [decode_cdac_value 0]
    set cload_total                 [expr {double($c1 * $c2) / ($c1 + $c2) + double($ctrace + $cpad + $cdac0) / 2}]
    set cload_min_data              [get_cload_min_value $cshunt_match_starting_row $cshunt_match_ending_row $cpad $ctrace $cload_total]
    set cload_match_row             [lindex $cload_min_data 0]
    set cload_closest_match_min     [lindex $cload_min_data 1]
    set matched_cload2              [lindex $cload_min_data 2]
    set matched_gtrim_col2          [get_table_gtrim_col $cload_match_row $required_rneg]
    set matched_rneg2               [decode_table_value $cload_match_row $matched_gtrim_col2]
    set max_available_rneg2         [get_table_max_rneg $cload_match_row]
    set tau2                        [expr {double(2000 * $lmotional) / ($matched_rneg2 - $effective_esr)}]
    set tamp2                       [expr {$tau2 * log($vf / $vi)}]
    set tstartup_total2             [expr {($tpulse + $tamp2 + $twd) / 1000}]
    set dl2                         [expr {2 * $effective_esr * (3.1415 * $freq * $cload_total / 2 * $vpp) * (3.1415 * $freq * $cload_total / 2 * $vpp) / 1000000000000}]

    # OUTPUTS
    set ctrim                       [expr {$ext_cap ? $ctrim2 : $matched_ctrim}]
    set gtrim                       [expr {$ext_cap ? $matched_gtrim_col2 : $matched_gtrim_col}]
    set drive_level_estimate        [expr {$ext_cap ? $dl2 : $dl1}]


    #puts "54 = $iboost"
    #puts "55 = $rneg"
    #puts "56 = $cpad"
    #puts "57 = $effective_esr"
    #puts "58 = $required_rneg"
    #puts "59 = $required_dac_cap"
#    #puts "60 = $freq_min"
    #puts "61 = $freq_match_starting_row"
#   #puts "62 = $freq_match_ending_row"
    #puts "63 = $cshunt_match_starting_row"
    #puts "64 = $cshunt_match_ending_row"
#   #puts "65 = $cdac_closest_match_min"
    #puts "66 = $cdac_match_row"
    #puts "67 = $matched_ctrim"
    #puts "68 = $matched_cdac"
    #puts "69 = $matched_gtrim_col"
    #puts "70 = $matched_rneg"
    #puts "71 = $max_available_rneg"
#    puts "72 = $freq_matched"
    #puts "73 = $lmotional"
    #puts "74 = $tau1"
    #puts "75 = $vi"
    #puts "76 = $vf"
    #puts "77 = $tpulse"
    #puts "78 = $tamp1"
    #puts "79 = $twd"
    #puts "80 = $tstartup_total"
    #puts "81 = $vpp"
    #puts "82 = $dl1"

    #puts "84 = $ctrim2"
    #puts "85 = $cdac0"
    #puts "86 = $cload_total"
    #puts "87 = $cload_closest_match_min"
    #puts "88 = $cload_match_row"
    #puts "89 = $matched_cload2"
    #puts "90 = $matched_gtrim_col2"
    #puts "91 = $matched_rneg2"
    #puts "92 = $max_available_rneg2"
    #puts "93 = $tau2"
    #puts "94 = $tamp2"
    #puts "95 = $tstartup_total2"
    #puts "96 = $dl2"


    # ------------- OUTPUT -------------
    #puts "ctrim=$ctrim"
    #puts "gtrim=$gtrim"
    #puts "iboost=$iboost"
    #puts "dle=$drive_level_estimate"

    puts ModusToolbox param:ctrim=$ctrim
    puts ModusToolbox param:gtrim=$gtrim
    puts ModusToolbox param:iboost=$iboost
    puts ModusToolbox param:drive_level_estimate=$drive_level_estimate
}

# Read binary data from companion files
# cdata is a vector of unsigned 2-byte values that have each been multiplied by 1000 from their original value in s22srssa_ECO_Calculator_v2.xlsx
set path        [lindex $argv 10]
set cdac_data [read_binary_file [file join $path "mxs22eco-1.0_cdac.dat"]]
# table is a 16 column matrix of signed 2-byte values from s22srssa_ECO_Calculator_v2.xlsx
set table_data [read_binary_file [file join $path "mxs22eco-1.0_table.dat"]]

eco_solver $argc $argv
