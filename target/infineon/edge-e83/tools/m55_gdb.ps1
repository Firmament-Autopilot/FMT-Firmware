param (
    [string]$scriptPath = $MyInvocation.MyCommand.Path,
    [string]$scriptDir  = $(Convert-Path (Split-Path -Path $scriptPath -Parent)),

    # ARM GNU Toolchain 根目录
    [string]$toolchain_dir = "E:\SomeIDE\RT-ThreadStudio\repo\Extract\ToolChain_Support_Packages\ARM\GNU_Tools_for_ARM_Embedded_Processors\13.3",

    [string]$elf_file = "$scriptDir/../m55/rt-thread.elf"
)

$toolchain_dir = (Resolve-Path $toolchain_dir).Path -replace '\\', '/'

$arm_gdb     = "$toolchain_dir/bin/arm-none-eabi-gdb.exe"
$arm_objdump= "$toolchain_dir/bin/arm-none-eabi-objdump.exe"

# 检查
if (-not (Test-Path $arm_gdb)) {
    Write-Error "找不到 arm-none-eabi-gdb: $arm_gdb"
    exit 1
}

# 反汇编
& $arm_objdump -d -S $elf_file > "$scriptDir/../m55/rtthread.asm"

# 启动 GDB
& $arm_gdb -x m55_gdb_script.gdb $elf_file
