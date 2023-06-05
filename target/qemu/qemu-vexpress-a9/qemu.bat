if exist sd.bin goto run
qemu-img create -f raw sd.bin 64M

:run
qemu-system-arm -M vexpress-a9 -kernel build/fmt_qemu-vexpress-a9.bin -display none -device sd-card,drive=sdcard_drive -drive file=sd.bin,format=raw,id=sdcard_drive -serial stdio -serial udp:127.0.0.1:14550 -serial udp:127.0.0.1:14551