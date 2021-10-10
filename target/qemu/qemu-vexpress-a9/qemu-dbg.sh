if [ ! -f "sd.bin" ]; then
qemu-img create -f raw sd.bin 64M
mkfs.vfat sd.bin
fi

qemu-system-arm -M vexpress-a9 -S -s -kernel build/fmt_fmu.bin -nographic -sd sd.bin