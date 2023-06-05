if [ ! -f "sd.bin" ]; then
qemu-img create -f raw sd.bin 64M
mkfs.vfat sd.bin
fi

qemu-system-arm -M vexpress-a9 -kernel build/fmt_qemu-vexpress-a9.bin -display none -device sd-card,drive=sdcard_drive -drive file=sd.bin,format=raw,id=sdcard_drive -serial stdio -serial udp:localhost:14550 -serial udp:localhost:14551
