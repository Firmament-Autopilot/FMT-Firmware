cd target/coolfly/chuanyun_v5/
scons
cp build/fmt_chuanyun_v5.bin ../../../chuanyun_bin/
cd ../../../chuanyun_bin/
./joint2flash_cf.sh
cp -f FMT_chuanyun_sky.bin ../