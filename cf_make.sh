cd target/coolfly/chuanyun_f2s/
scons
cp build/fmt_chuanyun_f2s.bin ../../../chuanyun_bin/
cd ../../../chuanyun_bin/
./joint2flash_cf.sh
cp -f FMT_chuanyun_sky.bin ../