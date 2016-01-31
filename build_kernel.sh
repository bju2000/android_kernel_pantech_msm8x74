#!/bin/bash
export ARCH=arm
export CROSS_COMPILE=/media/diszell2008/Build_Teo/cm-13.0/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi-
make cyanogenmod_a910_defconfig
make -j16 zImage 
