# Copyright (c) 2024 Qualcomm Innovation Center, Inc. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 

################################################################################
#             change the IN_* paramater if needed
################################################################################
export IN_COMPILE=aarch64-openwrt-linux-musl-
export IN_ARCH="arm64"
export IN_CHIP_TYPE_DEFAULT="APPE" #support changing by scripts parameter


################################################################################
#               don't change those functions
################################################################################
action=$1
chip_type=$2
export SSDK_PATH=$(pwd)/../
export QSDK_DIR=${SSDK_PATH}/../../../
export STAGING_DIR=${QSDK_DIR}/staging_dir
TOOL_PATH=$(ls -d ${QSDK_DIR}/staging_dir/toolchain*/bin | head -n 1)
SYS_PATH=$(ls -d ${QSDK_DIR}/qca/src/linux* | head -n 1)
export PATH=${PATH}:${TOOL_PATH}

check_soc () {
    if [ "$1" = "" ];then
        export IN_SOC=ipq95xx
        export IN_CHIP_TYPE=${IN_CHIP_TYPE_DEFAULT}
        return
    fi

    case $1 in
        'APPE')
            IN_SOC=ipq95xx
            ;;
        'HPPE')
            IN_SOC=ipq807x
            ;;
        'CPPE')
            IN_SOC=ipq60xx
            ;;
        'MPPE')
            IN_SOC=ipq53xx
            ;;
        'MRPPE')
            IN_SOC=ipq54xx
            ;;
         *)
            IN_SOC=ipq95xx
            ;;
    esac
    export IN_CHIP_TYPE=$1
    export IN_SOC
}

ssdk_compile() {
    echo "-----------------------------------------------------------------------------"
    echo "       Start to Compile SSDK $IN_SOC $IN_CHIP_TYPE with $IN_COMPILE          "
    echo "-----------------------------------------------------------------------------"

    make -C ${SSDK_PATH}/mk MODULE_TYPE=KSLIB modules \
    TOOL_PATH=${TOOL_PATH} SYS_PATH=${SYS_PATH} TOOLPREFIX=${IN_COMPILE} KVER=${SYS_PATH##*-} \
    ARCH=${IN_ARCH} TARGET_SUFFIX="musl" SoC=${IN_SOC} CHIP_TYPE=${IN_CHIP_TYPE} \
    \
    LNX_MAKEOPTS='-C ${SYS_PATH} KCFLAGS="-fno-caller-saves" HOSTCFLAGS="-O2 \
    -Wall -Wmissing-prototypes -Wstrict-prototypes" CROSS_COMPILE="${IN_COMPILE}" ARCH="arm64" \
    KBUILD_HAVE_NLS=no KBUILD_BUILD_USER="" KBUILD_BUILD_HOST="" KBUILD_BUILD_VERSION="0" \
    CONFIG_SHELL="bash" V=''  cmd_syscalls= KBUILD_EXTRA_SYMBOLS="" MYSOC=${IN_SOC}'

    echo "-----------------------------------------------------------------------------"
    echo "       SSDK Compile Done!                                                    "
    echo "-----------------------------------------------------------------------------"
}

ssdk_strip() {
    CONFIG_STRIP_ARGS="--strip-unneeded --remove-section=.comment --remove-section=.note"
    ${TOOL_PATH}/${IN_COMPILE}strip ${CONFIG_STRIP_ARGS} qca-ssdk.ko

    echo "-----------------------------------------------------------------------------"
    echo "       SSDK Strip Done!                                                      "
    echo "-----------------------------------------------------------------------------"
}

ssdk_clean() {
    find ../ -regextype posix-extended -regex ".*\.(o|ko|cmd|mod|mod\.c|symvers|order)" -delete

    echo "-----------------------------------------------------------------------------"
    echo "       SSDK Clean Done!                                                      "
    echo "-----------------------------------------------------------------------------"
}

ssdk_usage() {
    echo "-----------------------------------------------------------------------------"
    echo "       Usage                                                                 "
    echo "-----------------------------------------------------------------------------"

    echo "run ./make.sh compile to compile qca-ssdk.ko"
    echo "run ./make.sh compile APPE/HPPE/CPPE to compile for different chip"
    echo "run ./make.sh clean to clean target"
}

ssdk_main (){
    if [ "$1" = "" ] || [ "$1" = "compile" ];then
        ssdk_compile
        ssdk_strip
    elif [ "$1" = "clean" ];then
        ssdk_clean
    else
        ssdk_usage
    fi
}

check_soc $chip_type
ssdk_main $action

