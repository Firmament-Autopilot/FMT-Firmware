#
# Copyright (C) <2019-2021>
#   <Cypress Semiconductor Corporation (an Infineon company)>
#

###############################################################################
#
# sflash_write.tcl
#
# This TCL OpenOCD script runs on a PC and communicates with the embedded
# sflash_write app to allow the PC to write data into a serial flash chip
# attached to the target processor
#
# Usage example:
#
# source [find mfg_spi_flash/write_sflash.tcl]
# sflash_init "BCMUSI11-SDIO-debug"
# sflash_write_file "example.bin" 0x10 "BCMUSI11-SDIO-debug" 1
# shutdown
#
###############################################################################

# CHIP_RAM_START must be supplied by target specific TCL script
set MemoryStart $CHIP_RAM_START

###############################################################################
#
# These variables must match the ones in Apps/waf/sflash_write/sflash_write.c
#
# They rely on the linker script placing the data_config_area_t and
# data_transfer_area_t structures at the start of RAM
#
###############################################################################

# This must match data_config_area_t
set entry_address_loc  [expr {$MemoryStart + 0x00} ]
set stack_address_loc  [expr {$MemoryStart + 0x04} ]
set buffer_size_loc    [expr {$MemoryStart + 0x08} ]

# This must match data_transfer_area_t
set data_size_loc      [expr {$MemoryStart + 0x0C} ]
set dest_address_loc   [expr {$MemoryStart + 0x10} ]
set command_loc        [expr {$MemoryStart + 0x14} ]
set result_loc         [expr {$MemoryStart + 0x18} ]
set data_loc           [expr {$MemoryStart + 0x1C} ]


# These must match the MFG_SPI_FLASH_COMMAND defines
set COMMAND_INITIAL_VERIFY            0x01
set COMMAND_ERASE                     0x02
set COMMAND_WRITE                     0x04
set COMMAND_POST_WRITE_VERIFY         0x08
set COMMAND_VERIFY_CHIP_ERASURE       0x10
set COMMAND_WRITE_DCT                 0x20
set COMMAND_READ                      0x40
set COMMAND_WRITE_ERASE_IF_NEEDED     0x80

# These must match the mfg_spi_flash_result_t enum
set RESULT(0xffffffff)      "In Progress"
set RESULT(4294967295)      "In Progress"
set RESULT(0)               "OK"
set RESULT(1)               "Erase Failed"
set RESULT(2)               "Verify after write failed"
set RESULT(3)               "Size too big for buffer"
set RESULT(4)               "Size too big for chip"
set RESULT(5)               "DCT location not found - has factory reset app been written?"
set RESULT(6)               "Error during Write"
set RESULT(7)               "Error during Read"

# For handling big single file
set MAX_SINGLE_FILE_SIZE    "4194304"

###############################################################################
# memread32
#
# Helper function that reads a 32 bit value from RAM and returns it
#
# address - the RAM address to read from
###############################################################################
proc memread32 {address resume_required} {
	if { $resume_required == 1 } {
		halt
	}
	set mem [format %d [read_memory $address 32 1]]
	if { $resume_required == 1} {
		resume
	}
	return $mem
}

###############################################################################
# load_image_bin
#
# Loads part of a binary file into RAM
#
# fname   - filename of binary image file
# foffset - offset from the start of the binary file where data will be read
# address - the destination RAM address
# length  - number of bytes to transfer
###############################################################################
proc load_image_bin {fname foffset address length } {
  # Load data from fname filename at foffset offset to
  # target at address. Load at most length bytes.
  puts "loadimage address $address foffset $foffset $length"
  load_image $fname [expr {$address - $foffset}] bin $address $length
}


proc target_not_supported {} {
	puts stderr "Target is not currently supported by sflash_write.tcl"
	shutdown
}

proc post_init_43909_setup { } {
	reset init
	cortex_r4 maskisr on

	# Go to Supervisor ARM mode
	reg cpsr 0xd3
	reg lr   0x0
}

proc post_init_psoc6_setup { } {
	reset init
	psoc6 reset_halt sysresetreq

	# Switch to cm4 since that is target for sflash_write
	targets psoc6.cpu.cm4
}

###############################################################################
# sflash_init
#
# Prepares for writing to serial flashby loading the sflash_write app into
# memory and setting it running.
# This function assumes the following target has already been built:
#      waf.sflash_write-NoOS-<PlatBusDebug>
#
# PlatBusDebug   - The platform, bus and debug part of the build target
# init4390       - run initialisation for the 4390
###############################################################################
proc sflash_init { PlatBusDebug init4390 } {
	global entry_address_loc
	global stack_address_loc
	global buffer_size_loc
	global entry_address
	global stack_address
	global buffer_size

	init

	if { $init4390 == 4390 } {
		target_not_supported
	} elseif { $init4390 == 43909 } {
		post_init_43909_setup
	} elseif { $init4390 == 6 } {
		post_init_psoc6_setup
	}

	load_image $PlatBusDebug

	set entry_address [memread32 $entry_address_loc 0]
	set stack_address [memread32 $stack_address_loc 0]
	set buffer_size   [memread32 $buffer_size_loc 0]

	puts "entry_address= $entry_address"
	puts "stack_address= $stack_address"
	puts "buffer_size= $buffer_size"
	if { $buffer_size == 0 } {
		puts "Error: Buffer size read from address $buffer_size_loc on target is zero"
		exit -1;
	}


	# Setup start address
	resume $entry_address
}


###############################################################################
# program_sflash
#
# Executes a serial command by communicating to the sflash_write app
#
# fname    - filename of binary image file (if command requires it)
# foffset  - offset from the start of the binary file where data will be read  (if command requires it)
# dataSize - number of bytes to transfer (if command requires it)
# destaddr - the destination serial flash address (if command requires it)
# cmd      - The commmand to execute (see list above)
###############################################################################
proc program_sflash { filename foffset dataSize destaddr cmd } {
	global PlatBusDebug MemoryStart data_size_loc data_loc dest_address_loc command_loc result_loc entry_address RESULT  entry_address_loc

	halt
	# Load the binary data into the RAM
	if { ( $dataSize != 0 ) && ( $filename != "" ) } {
		load_image_bin $filename $foffset $data_loc $dataSize
	}

	# Write the details of the data
	mww $data_size_loc    $dataSize
	mww $dest_address_loc $destaddr
	mww $result_loc       0xffffffff

	# Write the command - This causes the writing to start
	mww $command_loc      $cmd
	resume

	set resultval 0xffffffff
	set loops  0
	while { ($resultval == 0xffffffff) && ( $loops < 1500 ) } {
		sleep 100
		set resultval [memread32 $result_loc 1]
		incr loops
	}

	puts "****************** Result: $RESULT($resultval)"

	if { $resultval != 0 } {
		halt
		reg
		exit -1;
	}

}


###############################################################################
# sflash_write_file
#
# Writes an entire binary image file to a serial flash address
# This function assumes the following target has already been built:
#      waf.sflash_write-NoOS-<PlatBusDebug>
#
# filename     - filename of binary image file
# destAddress  - the destination serial flash address
# PlatBusDebug - The platform, bus and debug part of the build target
# erasechip    - If 1, Erase the chip before writing.
# init4390     - run initialisation for the 4390
###############################################################################
proc sflash_write_file { filename destAddress PlatBusDebug erasechip init4390 } {
	global COMMAND_ERASE COMMAND_INITIAL_VERIFY COMMAND_WRITE COMMAND_POST_WRITE_VERIFY buffer_size COMMAND_WRITE_ERASE_IF_NEEDED MAX_SINGLE_FILE_SIZE

	sflash_init $PlatBusDebug $init4390

	set binDataSize [file size $filename]

	set write_command_val [expr {$COMMAND_WRITE_ERASE_IF_NEEDED | $COMMAND_POST_WRITE_VERIFY} ]
	set pos 0

	# if { $erasechip } {
		# puts "Erasing Chip"
		# program_sflash $filename $pos 0 $destAddress $erase_command_val
		# puts "Chip Erase Done"
	# }

	if { $binDataSize < $MAX_SINGLE_FILE_SIZE } {
		puts "Total write size is $binDataSize."
		while { $pos < $binDataSize } {
			if { ($binDataSize - $pos) <  $buffer_size } {
				set writesize [expr {$binDataSize - $pos}]
			} else {
				set writesize $buffer_size
			}
			puts "writing $writesize bytes at [expr {$destAddress + $pos}]"
			program_sflash $filename $pos $writesize [expr {$destAddress + $pos}] $write_command_val
			set pos [expr {$pos + $writesize}]
		}
	} else {
		puts "The file size was too big ($binDataSize), will split it into small size before write to sflash."
		set fd_pos 0
		set tmpfilename_count 0

		###Read FILE in binary###
		set fd_binDataSize $binDataSize
		set fd [open $filename rb]
		fconfigure $fd -translation binary

		while { $fd_pos < $fd_binDataSize } {
			if { ($fd_binDataSize - $fd_pos) <  $MAX_SINGLE_FILE_SIZE } {
				set fd_writesize [expr {$fd_binDataSize - $fd_pos}]
			} else {
				set fd_writesize $MAX_SINGLE_FILE_SIZE
			}
			set data [read $fd $fd_writesize]

			###Write data to temp file in binary###
			set tmpfilename $filename\_part\_$tmpfilename_count\.txt
			set tmp_fd [open $tmpfilename wb]
			puts -nonewline $tmp_fd $data
			close $tmp_fd

			###Write temp file into sflash###
			puts "Partially, write size is $fd_writesize."
			set pos 0
			while { $pos < $fd_writesize } {
				if { ($fd_writesize - $pos) <  $buffer_size } {
					set writesize [expr {$fd_writesize - $pos}]
				} else {
					set writesize $buffer_size
				}
				puts "writing $writesize bytes at [expr {$destAddress + $pos}]"
				program_sflash $tmpfilename $pos $writesize [expr {$destAddress + $pos}] $write_command_val
				set pos [expr {$pos + $writesize}]
			}

			file delete $tmpfilename
			set destAddress [ expr {$destAddress + $fd_writesize} ]
			set fd_pos [expr {$fd_pos + $fd_writesize}]
			seek $fd $fd_pos
			set tmpfilename_count [expr {$tmpfilename_count + 1}]
	   }
	   close $fd
	}
}



###############################################################################
# sflash_read_file
#
# Reads data from a serial flash address
# This function assumes the following target has already been built:
#      waf.sflash_write-NoOS-<PlatBusDebug>
#
# filename     - output filename for binary image file
# srcAddress   - the destination serial flash address
# PlatBusDebug - The platform, bus and debug part of the build target
# length       - number of bytes to read
# init4390     - run initialisation for the 4390
###############################################################################
proc sflash_read_file { filename srcAddress PlatBusDebug length init4390 } {
	global COMMAND_ERASE COMMAND_INITIAL_VERIFY COMMAND_WRITE COMMAND_POST_WRITE_VERIFY buffer_size COMMAND_READ data_loc

	puts ""
	puts "--> save to         $filename"
	puts "--> SFLASH address  $srcAddress"
	puts "--> length          $length"
	puts ""

	sflash_init $PlatBusDebug $init4390
	set temp_file [file dirname $filename]
	append temp_file "/temp.bin"

	# open the output file and set into binary mode
	set fd_out [open $filename "wb"]
	fconfigure $fd_out -translation binary

	set read_command_val [expr {$COMMAND_READ} ]
	set pos 0

	while { $pos < $length } {
		if { ($length - $pos) <  $buffer_size } {
			set readsize [expr {$length - $pos}]
		} else {
			set readsize $buffer_size
		}

		puts "reading $readsize bytes from [expr {$srcAddress + $pos}]"
		program_sflash "" $pos $readsize [expr {$srcAddress + $pos}] $read_command_val
		halt
		dump_image  $temp_file $data_loc $readsize

		set fd_in_size [ file size $temp_file ]
		puts "temp size: $fd_in_size"

		# get the output file position for reporting
		set curr_pos [ tell $fd_out ]

		# concatenate temp_file to filename
		# open temp_file in binary mode and read in the data
		set fd_in [open $temp_file "rb"]
		fconfigure $fd_in -translation binary
		set file_data [read $fd_in ]
		close $fd_in

		puts -nonewline $fd_out $file_data
		flush $fd_out

		# get current positioin of output for reporting
		seek $fd_out 0 end
		set new_pos [ tell $fd_out ]
		set written_amount [expr {$new_pos - $curr_pos}]
		puts " wrote $written_amount from $curr_pos to $new_pos"

		#update the SFLASH read position
		set pos [expr {$pos + $readsize}]
	}
	close $fd_out

	file delete $temp_file
}


proc sflash_erase { PlatBusDebug init4390 } {
	global COMMAND_ERASE COMMAND_INITIAL_VERIFY COMMAND_WRITE COMMAND_POST_WRITE_VERIFY buffer_size COMMAND_WRITE_ERASE_IF_NEEDED

	sflash_init $PlatBusDebug $init4390

	set erase_command_val [expr {$COMMAND_ERASE} ]

	puts "Erasing Chip"
	set start_milliseconds [clock milliseconds]
	program_sflash "" 0 0 0 $erase_command_val
	set end_milliseconds [clock milliseconds]
	puts [format "Chip Erase Done (in %d ms)" [expr {$end_milliseconds - $start_milliseconds}]]
}
