param (
    [string]$scriptPath = $MyInvocation.MyCommand.Path,
    [string]$scriptDir = $(Convert-Path (Split-Path -Path $scriptPath -Parent)),
    [string]$tools_dir_path = "./OpenOCD-Infineon",
    [string]$target_lib_dir = "$scriptDir/../libs/TARGET_APP_KIT_PSE84_EVAL_EPC2",
    [string]$hex_file = "$scriptDir/../m55/rtthread.hex"
)


function Resolve-UnixPath {
    param ([string]$path)
    if (-not (Test-Path -Path $path)) {
        Write-Error "'$path' does not exist."
        exit -1
    }
    return (Resolve-Path -Path $path).Path -replace '\\', '/'
}

$tools_dir_path = Resolve-UnixPath $tools_dir_path
$target_lib_dir = Resolve-UnixPath $target_lib_dir
$hex_file = Resolve-UnixPath $hex_file

# Define OpenOCD command parameters
$openocd_executable = "$tools_dir_path/bin/openocd.exe"
$openocd_scripts_dir = "$tools_dir_path/openocd/scripts"
$openocd_target_dir = "$target_lib_dir/config/GeneratedSource"
$qspi_flashloader_file = "$target_lib_dir/config/GeneratedSource/PSE84_SMIF.FLM"

& "$openocd_executable" `
    -s "$openocd_scripts_dir" `
    -s "$openocd_target_dir" `
    -c "set QSPI_FLASHLOADER $qspi_flashloader_file" `
    -c "source [find interface/kitprog3.cfg]" `
    -c "source [find target/infineon/pse84xgxs2.cfg]" `
    -c "init; reset halt; program $hex_file verify reset exit;"