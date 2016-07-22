#!/bin/bash

export ARCH=arm
export CROSS_COMPILE=armv7a-neon-linux-gnueabi-
# export CROSS_COMPILE=armv7a-hardfloat-linux-gnueabi-
# export CROSS_COMPILE=arm-fsl-linux-gnueabi-

if [ -z ${1} ]; then
    if [ -f .config ]; then
	make -j5
    else
	make clean distclean
	make imx_utsvu_defconfig
	make -j5
    fi
#    if [ -f ./u-boot.imx ]; then
#	echo Update TFTP u-boot.imx
#	cp -f ./u-boot.imx /cimc/exporttftp/
#	md5sum ./u-boot.imx /cimc/exporttftp/u-boot.imx
#    fi
#    if [ -f ./u-boot.bin ]; then
#	echo Update TFTP u-boot.bin
#	cp -f ./u-boot.bin /cimc/exporttftp/
#	md5sum ./u-boot.bin /cimc/exporttftp/u-boot.bin
#    fi
else
    make $*
fi
