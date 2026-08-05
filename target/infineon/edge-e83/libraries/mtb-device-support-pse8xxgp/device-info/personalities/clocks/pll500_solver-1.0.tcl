# Copyright 2022-2025 Cypress Semiconductor Corporation
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

const ARG_IDX_SRC_FREQ 0
const ARG_IDX_TARGET_FREQ 1
const ARG_IDX_LF_MODE 2
const ARG_IDX_MIN_POWER 3

const P_DIV_KEY "pDiv"
const N_DIV_KEY "nDiv"
const K_DIV_KEY "kDiv"
const FRAC_DIV_KEY "fracDiv"
const FMODE_DIV_KEY "fMode"
const FTH_DIV_KEY "fTh"
const LFBETA_DIV_KEY "lfBeta"

const MIN_IN_FREQ 4
const MAX_IN_FREQ 50

# DPLL-HP NDIV bitfield allowable range
const NDIV_MIN   8
const NDIV_MAX   250

# DPLL-HP PDIV bitfield allowable range
const PDIV_MIN   1
const PDIV_MAX   8

# DPLL-HP KDIV bitfield allowable range
const KDIV_MIN   2
const KDIV_MAX   8

const FPDF_MIN 17
const FPDF_MAX 50

const FDCO_MIN 400
const FDCO_MAX 1000

const SUCCESS 0
const ERROR_ARG_COUNT 1
const ERROR_ID 2
const ERROR_ARG_VALUE 3

set channelName stdout

if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

proc solve_pll {} {
    if {$::argc != $::ARG_IDX_MIN_POWER + 1} {
        error "PLL Solver requires 4 arguments:
\tdouble srcFreqMHz - Source clock frequency for the PLL in MHz.
\tdouble targetFreqMHz - Output frequency of the PLL in MHz.
\tboolean lfMode - CLK_PLL_CONFIG register, PLL_LF_MODE bit.
\tboolean minPower - Optimize for min power rather min jitter."
        return $::ERROR_ARG_COUNT
    }
    set srcFreqMHz [lindex $::argv $::ARG_IDX_SRC_FREQ]
    set targetFreqMHz [lindex $::argv $::ARG_IDX_TARGET_FREQ]
    set lfMode [string is true [lindex $::argv $::ARG_IDX_LF_MODE]]
    set minPower [string is true [lindex $::argv $::ARG_IDX_MIN_POWER]]
    if {![string is double $srcFreqMHz] || ![string is double $targetFreqMHz]} {
        error "Unable to parse argument values: either $srcFreqMHz or $targetFreqMHz is not a floating-point number."
        return $::ERROR_ARG_VALUE
    }
    set srcFreqMHz [expr {double($srcFreqMHz)}]
    set targetFreqMHz [expr {double($targetFreqMHz)}]
    if {$srcFreqMHz < $::MIN_IN_FREQ || $::MAX_IN_FREQ < $srcFreqMHz} {
        error "Invalid PLL input frequency '$srcFreqMHz'. Must be within the range $::MIN_IN_FREQ-$::MAX_IN_FREQ."
        return $::ERROR_ARG_VALUE
    }
    return [solve_pll_internal $srcFreqMHz $targetFreqMHz $lfMode $minPower]
}

proc solve_pll_internal {srcFreqMHz targetFreqMHz lfMode minPower} {
    set pDivider $::PDIV_MIN
    set nDivider $::NDIV_MIN
    set kDivider $::KDIV_MIN
    set fracDiv 0
    set foutBest 0
    set fMode 0
    set fTh   0
    set lfBeta 0

    for {set p $::PDIV_MIN} {$p <= $::PDIV_MAX} {incr p} {
        for {set n $::NDIV_MIN} {$n <= $::NDIV_MAX} {incr n} {

            set pfd [expr {($srcFreqMHz)/ ($p)}]
            set fdco [expr {($pfd * ($n))}]


            if {![is_pfdref_in_range $pfd]} {
                continue
            }

            if {![is_dco_in_range $fdco]} {
                continue
            }

            for {set k $::KDIV_MIN} {$k <= $::KDIV_MAX} {incr k} {
                set tempVco [expr { $targetFreqMHz * $k}]
                set tempFeedBackDivLeftShifted [expr { ((($tempVco) * pow (2, 21)) * $p) / $srcFreqMHz }]
                set feedBackFracDiv [expr { (int($tempFeedBackDivLeftShifted) & (( 1 << 21 ) - 1)) }]
                set fout [expr {($srcFreqMHz * ( ($n << 21) + $feedBackFracDiv) / ($p * $k)) / pow (2, 21)}]


                if {(abs($fout - $targetFreqMHz) < abs($foutBest - $targetFreqMHz)) && ($fout <= $targetFreqMHz) } {
                    if {round($foutBest) == round($targetFreqMHz)} {
                           break;
                    }
                    set foutBest $fout
                    set pDivider $p
                    set nDivider $n
                    set kDivider $k
                    set fracDiv  $feedBackFracDiv
                    set fMode  [get_fmode_value $srcFreqMHz]
                    set fTh    [get_fth_value $nDivider]
                    set lfBeta [get_lfbeta_value $pfd]
                }
            }
        }
    }

    puts $::channelName "param:$::P_DIV_KEY=$pDivider"
    puts $::channelName "param:$::N_DIV_KEY=$nDivider"
    puts $::channelName "param:$::K_DIV_KEY=$kDivider"
    puts $::channelName "param:$::FRAC_DIV_KEY=$fracDiv"
    puts $::channelName "param:$::FMODE_DIV_KEY=$fMode"
    puts $::channelName "param:$::FTH_DIV_KEY=$fTh"
    puts $::channelName "param:$::LFBETA_DIV_KEY=$lfBeta"

    return $::SUCCESS
}
proc is_pfdref_in_range {pfd} {
    return [expr {$::FPDF_MIN <= $pfd && $pfd <= $::FPDF_MAX}]
}

proc is_dco_in_range {fdco} {
    return [expr {$::FDCO_MIN <= $fdco && $fdco <= $::FDCO_MAX}]
}

proc get_fmode_value {fref} {
    if { ($fref > 45) && ($fref <= 50)} {
        set retval 7
    } elseif { ($fref > 40) && ($fref <= 45)} {
        set retval 6
    } elseif { ($fref > 32) && ($fref <= 40)} {
        set retval 5
    } elseif { ($fref > 25) && ($fref <= 32)} {
        set retval 4
    } elseif { ($fref > 16) && ($fref <= 25)} {
        set retval 3
    } elseif { ($fref > 10) && ($fref <= 16)} {
        set retval 2
    } elseif { ($fref > 6) && ($fref <= 10)} {
        set retval 1
    } elseif { ($fref > 4) && ($fref <= 6)} {
        set retval 0
    } else {
        set retval 7
    }
    return $retval
}

proc get_fth_value {ndiv} {
    if { $ndiv < 20} {
        set retval 3
    } else {
        set retval 7
    }

    return $retval
}

proc get_lfbeta_value {pfd} {
    if { $pfd < 25} {
        set retval 16
    } else {
        set retval 20
    }

    return $retval
}

solve_pll
