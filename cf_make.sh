cd target/coolfly/coolfly_v2/
scons
cp build/fmt_coolfly_v2.bin ../../../chuanyun_bin/
cd ../../../chuanyun_bin/
./joint2flash_cf.sh
cp -f FMT_chuanyun_sky.bin ../