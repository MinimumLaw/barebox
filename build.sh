#!/bin/bash

export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-

if [ -f .config ]; then
	make $*
else
	make ravion_ravion200_defconfig
	make $*
fi

#if [ -f u-boot.imx ]; then
#	cp -f u-boot.imx /cimc/exporttftp/u-boot-ravion.imx
#fi
