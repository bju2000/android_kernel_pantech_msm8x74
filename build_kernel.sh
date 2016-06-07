#!/bin/bash
export ARCH=arm
export CROSS_COMPILE=/home/chautruongthinh/cm13/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi-
make cyanogenmod_a910_defconfig
make -j4 zImage 
