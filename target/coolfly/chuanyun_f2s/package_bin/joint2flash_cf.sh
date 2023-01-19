#!/bin/bash


#####################
###  FMT_CHUANYUN_SKY.BIN
###
###
###  4  byte    length all
###  16 byte    MD5
###  16 byte    MD5
###
###  256 byte   image head
###  4 byte     cpu0 length
###  N byte     cpu0image
###  4 byte     cpu1 length
###  N byte     cpu1image
###  4 byte     cpu2 length
###  N byte     cpu3image


function dec2hex()
{
    printf "%x" $1
}
outputtxt=fmt_chuangyun_f2s_pkg.bin

outputtmp=apptmp.bin
outcfgbin=cfgdata.bin

outputtmp_head=app_head_tmp.bin

skycpu0=fmt_chuanyun-f2s.bin
skycpu1=ar8020_skycpu1.bin
skycpu2=ar8020_skycpu2.bin

ve=imageinfo

echo "Making the image package, please wait ..."

imagedate=`date "+%Y%m%d%H%M%S"`

skycpu0length=`stat --format=%s $skycpu0`
skycpu1length=`stat --format=%s $skycpu1`
skycpu2length=`stat --format=%s $skycpu2`

#90112 = 64K ITCM2 + 0x6000 (ITCM2 extension)
skycpu2strlength=$((90112 - $skycpu2length))


#12 = cpu image size(4 byte) * 3
skyapplengthhead=$((256+12+$skycpu0length+$skycpu1length+$skycpu2length+$skycpu2strlength))

replenishskyapp=$((4-$skyapplengthhead%4))
skyapplengthhead=$(($skyapplengthhead+$replenishskyapp))

tmplength=`stat --format=%s $outcfgbin`
skyapplengthhead=$(($skyapplengthhead+$tmplength))

replenishskyimage=$((4-$skyapplengthhead%4))
skyapplengthhead=$(($skyapplengthhead+$replenishskyimage))


######################################################


######################################################
######################################################
##  get the app_part
###  4 byte     cpu0 length
###  N byte     cpu0image
###  4 byte     cpu1 length
###  N byte     cpu1image
###  4 byte     cpu2 length
###  N byte     cpu2image
###  N byte     outcfgbin

for i in {0..3}
do
        shiftlen=$[ i * 8 ]
        tmp=`echo $skycpu0length $shiftlen | awk '{print rshift($1,$2)}'`
        tmp=`echo $tmp | awk '{print and($1,255)}'`
        tmphex=$(dec2hex $tmp)
        echo -n -e \\x$tmphex >> $outputtmp
done

cat $skycpu0 >> $outputtmp

for i in {0..3}
do
        shiftlen=$[ i * 8 ]
        tmp=`echo $skycpu1length $shiftlen | awk '{print rshift($1,$2)}'`
        tmp=`echo $tmp | awk '{print and($1,255)}'`
        tmphex=$(dec2hex $tmp)
        echo -n -e \\x$tmphex >> $outputtmp
done

cat $skycpu1 >> $outputtmp

#add size of skycpu2 to ar8020.bin
#65536: 64K ITCM2
skycpu2length=65536

for i in {0..3}
do
        shiftlen=$[ i * 8 ]
        tmp=`echo $skycpu2length $shiftlen | awk '{print rshift($1,$2)}'`
        tmp=`echo $tmp | awk '{print and($1,255)}'`
        tmphex=$(dec2hex $tmp)
        echo -n -e \\x$tmphex >> $outputtmp
done

cat $skycpu2 >> $outputtmp
for((a=0;a<=(($replenishskyapp-1));a++))
do
        echo -n -e \\x0 >> $outputtmp
done

dd if=/dev/zero of=zero.image bs=$skycpu2strlength count=1
cat zero.image >> $outputtmp

cat $outcfgbin >> $outputtmp


############################################################################
############################################################################
############################################################################
###  get add head  => outputtmp_head
###  256 byte   image head
###  4 byte     cpu0 length
###  N byte     cpu0image
###  4 byte     cpu1 length
###  N byte     cpu1image
###  4 byte     cpu2 length
###  N byte     cpu3image

if [ -f $outputtmp_head ]; then
    rm $outputtmp_head
fi

imageheadlength=0
echo -n -e \\x0 >> $outputtmp_head
for i in {0..6}
do
        shiftlen=$[ i * 2 + 1]
        tmp=`expr substr "$imagedate" $shiftlen 2`
        echo -n -e \\x$tmp >> $outputtmp_head
done
imageheadlength=$((8+$imageheadlength))


#SDK image version
versioninfo=`sed -n 1p $ve`
versioninfo=${versioninfo##*:}
echo -n -e \\x00 >> $outputtmp_head
echo -n -e \\x${versioninfo:0:2} >> $outputtmp_head
echo -n -e \\x${versioninfo:3:2} >> $outputtmp_head
echo -n -e \\x${versioninfo:6:2} >> $outputtmp_head
imageheadlength=$((4+$imageheadlength))



bootmode=`sed -n 2p $ve`
bootmode=${bootmode##*:}
echo -n -e \\x${bootmode:0:2} >> $outputtmp_head
echo -n -e \\x${bootmode:3:2} >> $outputtmp_head

echo --------------------------------------------------------
test_length=`stat --format=%s $outputtmp_head`
echo $bootmode
echo $test_length
echo --------------------------------------------------------



imageheadlength=$((2+$imageheadlength))






#echo $skyapplengthhead
#image length
for i in {0..3}
do
        shiftlen=$[ i * 8 ]
        tmp=`echo $skyapplengthhead $shiftlen | awk '{print rshift($1,$2)}'`
        tmp=`echo $tmp | awk '{print and($1,255)}'`
        tmphex=$(dec2hex $tmp)
        echo -n -e \\x$tmphex >> $outputtmp_head
done
imageheadlength=$((4+$imageheadlength))


md5=`md5sum $outputtmp | cut -d ' ' -f 1`
for i in {0..15}
do
        shiftlen=$[ i * 2 + 1]
        tmp=`expr substr "$md5" $shiftlen 2`
        echo -n -e \\x$tmp >> $outputtmp_head
done
imageheadlength=$((16+$imageheadlength))



zerolength=$((256 - $imageheadlength))

echo $imageheadlength
echo $zerolength

#add "0" to the 256byte for image head
dd if=/dev/zero of=zero.image bs=$zerolength count=1
cat zero.image >> $outputtmp_head

echo --------------------------------------------------------
test_length=`stat --format=%s $outputtmp_head`
echo $test_length
echo --------------------------------------------------------


cat $outputtmp >> $outputtmp_head

for((a=0;a<=(($replenishskyimage-1));a++))
do
        echo -n -e \\x0 >> $outputtmp_head
done


###################################################################
###################################################################
###################################################################

if [ -f $outputtxt ]; then
    rm $outputtxt
fi

outputtmp_head_length=`stat --format=%s $outputtmp_head`

decryptapplengthhead=$(($outputtmp_head_length+36))
echo $decryptapplengthhead
for i in {0..3}
do
        shiftlen=$[ i * 8 ]
        tmp=`echo $decryptapplengthhead $shiftlen | awk '{print rshift($1,$2)}'`
        tmp=`echo $tmp | awk '{print and($1,255)}'`
        tmphex=$(dec2hex $tmp)
        echo -n -e \\x$tmphex >> $outputtxt
done

enmd5=`md5sum $outputtmp_head | cut -d ' ' -f 1`
for i in {0..15}
do
        shiftlen=$[ i * 2 + 1]
        tmp=`expr substr "$enmd5" $shiftlen 2`
        echo -n -e \\x$tmp >> $outputtxt
done

enmd5=`md5sum $outputtmp_head | cut -d ' ' -f 1`
for i in {0..15}
do
        shiftlen=$[ i * 2 + 1]
        tmp=`expr substr "$enmd5" $shiftlen 2`
        echo -n -e \\x$tmp >> $outputtxt
done

echo --------------------------------------------------------
test_length=`stat --format=%s $outputtxt`
echo $test_length
echo --------------------------------------------------------


cat $outputtmp_head >> $outputtxt

rm zero.image
rm $outputtmp
rm $outputtmp_head








