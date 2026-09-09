#
# Copyright (C) <2019-2021>
#   <Cypress Semiconductor Corporation (an Infineon company)>
#
# Example implementation of secure JTAG unlock script
#

if { [adapter name] eq "undefined" } then {
	source [find interface/kitprog3.cfg]
	transport select swd
}

#################################################################################################
### USER CONFIGURATION SECTION
#################################################################################################
adapter speed 1000

set UNLOCK_REQUEST   { 0x55000000 0x00112233 0x44556677 0x8899AABB 0xCCDDEEFF }
set RAM_SCRATCH_ADDR 0x08001000
set MEM_IPC_BASE     0x40220040
set IPC_NOTIFY_NO    4

set STATUS_MASK      0xFF000000
set STATUS_SUCCESS   0xAA000000

#################################################################################################
### SYSTEM CONFIGURATION SECTION - DO NOT EDIT
#################################################################################################
source [find target/swj-dp.tcl]
source [find mem_helper.tcl]

swj_newdap traveo2 cpu -irlen 4 -ircapture 0x1 -irmask 0xf
dap create traveo2.dap -chain-position traveo2.cpu
target create traveo2.sysap mem_ap -dap traveo2.dap -ap-num 0

if {[using_jtag]} {
	jtag newtap traveo2 bs -irlen 4 -expected-id 0
}

#################################################################################################
### UNLOCK PROCEDURES
#################################################################################################

# Reads SCS.CPUID register via different DAP Access Ports in range min_ap..max_ap and match
# the IMPLEMENTER field with 0x41 (ARM). Returns the number of discovered ARM cores.
proc check_for_open_aps { min_ap max_ap } {
	puts "-- Scanning for APs ($min_ap..$max_ap) with ARM CPU behind them..."
	set dap [[target current] cget -dap]
	set cpus_found 0

	for { set ap $min_ap } { $ap <= $max_ap } { incr ap } {
		local_echo off
		set is_err [catch {
			$dap apreg $ap 0x00 0xAB000002
			$dap apreg $ap 0x04 0xE000ED00
			$dap apreg $ap 0x0C
		} value]
		local_echo on

		if { $is_err == 0 && [expr {$value & 0xFF000000}] == 0x41000000 } then {
			puts "--   Found ARM Core behind AP #$ap, CPUID = [format 0x%08X $value]"
			incr cpus_found
		}
	}

	if { $cpus_found == 0} then {
		puts "--   No ARM Cores were discovered"
	}
	return $cpus_found
}

# Polls given memory location waiting for specified bit combination to match expected value
# C pseudo-code: while (read32(address) & mask != expected) {}
# Default timeout is 1 second
proc poll_memory { address mask expected {timeout 1000} } {
	set t_end [expr {[clock milliseconds] + $timeout}]
	while { [clock milliseconds] < $t_end } {
		set val [mrw $address]
		if { [expr {$val & $mask}] == $expected} then {
			return 1
		}
	}
	return 0
}

# Performs unlock procedure. Returns:
#  1 - in case of success
#  0 - otherwise
proc unlock_aps { } {
	set req_status "Unknown"

	catch {
		set MEM_IPC_ACQUIRE     [expr {$::MEM_IPC_BASE + 0x00}]
		set MEM_IPC_NOTIFY      [expr {$::MEM_IPC_BASE + 0x08}]
		set MEM_IPC_DATA        [expr {$::MEM_IPC_BASE + 0x0C}]
		set MEM_IPC_LOCK_STATUS [expr {$::MEM_IPC_BASE + 0x1C}]

		puts "-- Acquiring IPC structure... "
		mww $MEM_IPC_ACQUIRE 0x80000000
		if { [poll_memory $MEM_IPC_LOCK_STATUS 0x80000000 0x80000000] == 0 } then {
			error "Failed to acquire IPC structure"
		}

		puts "-- Writing unlock request..."
		mww $MEM_IPC_DATA $::RAM_SCRATCH_ADDR
		set start_addr $::RAM_SCRATCH_ADDR
		foreach value $::UNLOCK_REQUEST {
			puts [format "--   0x%08X <- 0x%08X" $start_addr $value]
			mww $start_addr $value
			incr start_addr 4
		}

		puts "-- Generating request..."
		mww $MEM_IPC_NOTIFY $::IPC_NOTIFY_NO

		puts "-- Waiting for request completion... "
		if { [poll_memory $MEM_IPC_LOCK_STATUS 0x80000000 0x00000000] == 0 } then {
			error "Timeout waiting for IPC unlock"
		}

		set req_status [mrw $::RAM_SCRATCH_ADDR]
		if { [expr {$req_status & $::STATUS_MASK}] == $::STATUS_SUCCESS } then {
			puts "-- Unlock SUCCEDED!"
		} else {
			error "-- Unlock FAILED!"
		}
	} err_msg

	if { $err_msg ne "" } then {
		puts stderr "Error: $err_msg, status: [format 0x%08X $req_status]"
		return 0
	}

	return 1
}

#################################################################################################
### ENTRY POINT
#################################################################################################
init

check_for_open_aps 1 3
unlock_aps
check_for_open_aps 1 3

exit
