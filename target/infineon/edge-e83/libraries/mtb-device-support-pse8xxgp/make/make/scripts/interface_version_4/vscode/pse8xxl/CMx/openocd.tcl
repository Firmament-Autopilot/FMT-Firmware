&&_MTB_RECIPE__QSPI_FLASHLOADER&&
source [find interface/kitprog3.cfg]
&&_MTB_RECIPE__OPENOCD_BOARD&&
&&_MTB_RECIPE__VSCODE_OPENOCD_PROBE_SERIAL2_CMD&&
transport select &&_MTB_RECIPE__PROBE_INTERFACE&&
set ENABLE_ACQUIRE 0
set ENABLE_CM55 1//CM55 Only//
source [find target/&&_MTB_RECIPE__OPEN_OCD_FILE&&]
&&_MTB_RECIPE__OPENOCD_CHIP&&.cm33 configure -rtos auto -rtos-wipe-on-reset-halt 1
&&_MTB_RECIPE__OPENOCD_CHIP&&.cm55 configure -rtos auto -rtos-wipe-on-reset-halt 1//CM55 Only//
gdb_breakpoint_override hard
init
if {$ENABLE_ATTACH == 0} {
    reset init
}