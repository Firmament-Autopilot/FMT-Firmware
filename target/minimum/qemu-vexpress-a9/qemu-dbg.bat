if exist sd.bin goto run
qemu-img create -f raw sd.bin 64M

:run
qemu-system-arm -M vexpress-a9 -S -s -kernel build/fmt_qemu-vexpress-a9.bin -nographic -sd sd.bin