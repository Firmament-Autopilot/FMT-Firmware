scons
cp build/fmt_chuanyun_f2s.bin package_bin/
cd package_bin/
./joint2flash_cf.sh
cp -f fmt_chuangyun_f2s_pkg.bin ../../../../