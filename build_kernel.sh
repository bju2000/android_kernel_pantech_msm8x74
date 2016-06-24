#!/bin/bash
###############################################################################
#
#                           Kernel Build Script 
#
###############################################################################
# 2011-10-24 effectivesky : modified
# 2010-12-29 allydrop     : created
###############################################################################
##############################################################################
# set toolchain
##############################################################################
# export PATH=$(pwd)/$(your tool chain path)/bin:$PATH
# export CROSS_COMPILE=$(your compiler prefix)
#export PATH=$(pwd)/../../toolchain_arm-eabi-4.6/arm-eabi-4.6/bin:$PATH

export ARCH=arm
export PATH=/home/chautruongthinh/cm13/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin:$PATH
export CROSS_COMPILE=arm-eabi-

##############################################################################
# make zImage
##############################################################################
mkdir -p ./obj/KERNEL_OBJ/
#make O=./obj/KERNEL_OBJ/ 
make ARCH=arm O=./obj/KERNEL_OBJ/ A910L_defconfig
make -j4 ARCH=arm O=./obj/KERNEL_OBJ/ 2>&1 | tee kernel_log.txt

##############################################################################
# Copy Kernel Image
##############################################################################
cp -f ./obj/KERNEL_OBJ/arch/arm/boot/zImage .
