#!/bin/bash
set -x -e

################################################################################
# Usage example:
# ./build_all.sh PKG_LVERSION=4.0.0-123
################################################################################
OPENOCD_REPO="${CI_PROJECT_URL:-https://github.com/cypresssemiconductorco/openocd.git}"
OPENOCD_BRANCH="${CI_COMMIT_BRANCH:-cypress}"

for cmd in "${@}"; do
	eval "${cmd}"
done

################################################################################
STATIC="${STATIC:-0}"
OPENOCD_BRANCH="${OPENOCD_BRANCH:-develop}"
PKG_LVERSION="${PKG_LVERSION:-${OPENOCD_BRANCH}-latest}"
LIBUSB_BRANCH=master
LIBUSB_COMMIT=HEAD
HIDAPI_BRANCH=master
HIDAPI_COMMIT=HEAD
CAPSTONE_BRANCH=master
CAPSTONE_COMMIT=tags/4.0.2

################################################################################
HIDAPI_REPO="https://github.com/libusb/hidapi.git"
LIBUSB_REPO="https://github.com/libusb/libusb.git"
CAPSTONE_REPO="https://github.com/aquynh/capstone.git"
SOURCE_PREFIX="$(pwd)/build/_src"
BUILD_PREFIX="$(pwd)/build/_libs"
INSTALL_PREFIX="$(pwd)/install"
BIN_PREFIX="${INSTALL_PREFIX}/openocd/bin"
CONTRIB_PREFIX="${INSTALL_PREFIX}/openocd/contrib"
#-------------------------------------------------------------------------------

export MAKEFLAGS=${MAKEFLAGS:=-j8}
XTRA_CFLAGS+=" -O2 -URELSTR -DRELSTR=\\\"-${PKG_LVERSION}\\\""

case "$OSTYPE" in
    darwin*)
        if [ ${STATIC} -eq 1 ]; then
            echo "Static build is not supported on Mac OS"
            STATIC=0
        fi
        export XTRA_CFLAGS+=" -Qunused-arguments"
        ;;
    linux*)
        XTRA_CFLAGS+=" -Wl,-rpath,XORIGIN"
        ;;
    msys*)
        if [ ${STATIC} -eq 1 ]; then
            XTRA_CFLAGS+=" -Wl,-static"
        fi
        ;;
    *)	echo "Unknown operating system: $OSTYPE"
        exit 1
        ;;
esac

if [ ${STATIC} -eq 1 ]; then
    XTRA_CFLAGS+=" -static -static-libgcc"
    XTRA_LDFLAGS+=" -static"
    LIBUSB_BUILD_TYPE="--enable-shared=no"
else
    LIBUSB_BUILD_TYPE="--enable-static=no"
fi

if [ "$CONFIG" == "Coverage" ]; then
    XTRA_CFLAGS+=" --coverage -finstrument-functions-exclude-file-list=msys64,jimtcl,src/jtag,src/helper,src/pld,src/rtos,src/server,src/svf,src/target,src/transport,src/xsvf,src/flash/hand"
fi

function maybe_fetch_package {
    if [ ! -d "${SOURCE_PREFIX}/${1}" ]; then
        git clone --branch "${3}" "${2}" "${SOURCE_PREFIX}/${1}"
    fi

    (cd "${SOURCE_PREFIX}/${1}" && {
        git reset --hard "origin/${3}"
        git clean -fd
        [ -z "$4" ] || git checkout --quiet "$4"
        git show --oneline -s
    })
}

function maybe_build_library {
    (cd "${SOURCE_PREFIX}/${1}" && {
        if [ ! -f Makefile ]; then
            ./bootstrap || ./autogen.sh
            ./configure --prefix="${BUILD_PREFIX}" --enable-silent-rules "${@:2}"
        fi
        make
        make install
    })
}

############################
# change dynamic shared library install names
#
function patch_macos_lib_path {
    local victim=$1
    local lib_name=$2
    local rel_lib_path="${3:-@executable_path}"
    
    local path_regex="^(.*[\/]?)($lib_name.*\.dylib)"

    otool -L "$victim" | grep "$lib_name" | while read -r line ; do  
        if [[ ${line} =~ ${path_regex} ]]; then
            lib_dir=${BASH_REMATCH[1]}
            lib=${BASH_REMATCH[2]}

            install_name_tool -change "${lib_dir}${lib}" "$rel_lib_path/${lib}" "$victim"
        fi
    done
}

# fetch and build hidapi
maybe_fetch_package "hidapi" "${HIDAPI_REPO}" "${HIDAPI_BRANCH}" "${HIDAPI_COMMIT}"
maybe_build_library "hidapi" "--enable-shared=no" \
    LD_LIBRARY_PATH=":${BUILD_PREFIX}/lib" \
    PKG_CONFIG_PATH="${BUILD_PREFIX}/lib/pkgconfig"

# fetch and build libusb
libusb_exists=$(find "${BUILD_PREFIX}/lib/" -maxdepth 1 -type f -name "libusb-*" -print -quit)
if [ -z "$libusb_exists" ]; then
    maybe_fetch_package "libusb" "${LIBUSB_REPO}" "${LIBUSB_BRANCH}" "${LIBUSB_COMMIT}"
    maybe_build_library "libusb" "${LIBUSB_BUILD_TYPE}"
fi

maybe_fetch_package "capstone" "${CAPSTONE_REPO}" "${CAPSTONE_BRANCH}" "${CAPSTONE_COMMIT}"
cd "${SOURCE_PREFIX}/capstone"
make CAPSTONE_ARCHS="arm" CAPSTONE_BUILD_CORE_ONLY=yes CAPSTONE_SHARED=no PREFIX=${BUILD_PREFIX} install

# fetch openocd
maybe_fetch_package "openocd" "${OPENOCD_REPO}" "${OPENOCD_BRANCH}"

rm -rf "${INSTALL_PREFIX}"

(cd "${SOURCE_PREFIX}/openocd" && {
    if [ -f Makefile ]; then
        make distclean
    fi

    ./bootstrap
    ./configure --enable-internal-libjaylink --enable-jtag_vpi --enable-silent-rules --disable-werror --enable-remote-bitbang \
        --disable-ulink --disable-usbprog --disable-rlink --disable-armjtagew --disable-angie \
        CFLAGS="${CFLAGS} ${XTRA_CFLAGS}" LDFLAGS="${LDFLAGS} ${XTRA_LDFLAGS}" \
        LD_LIBRARY_PATH=":${BUILD_PREFIX}/lib:${BUILD_PREFIX}/bin:${LD_LIBRARY_PATH}" \
        PKG_CONFIG_PATH="${BUILD_PREFIX}/lib/pkgconfig" \
        CC="gcc" \
        --prefix="${BUILD_PREFIX}" \
        --mandir="${BUILD_PREFIX}/share/man" \
        --infodir="${BUILD_PREFIX}/share/info" \
        --bindir="${BIN_PREFIX}" \
        --datarootdir="${INSTALL_PREFIX}"

    make
    make install-strip
})

mkdir -p "${INSTALL_PREFIX}/openocd/source"
cp -av "${SOURCE_PREFIX}/openocd/build"/*.sh "${INSTALL_PREFIX}/openocd/source/"

mkdir -p "${INSTALL_PREFIX}/openocd/docs"
cp -av "${SOURCE_PREFIX}/openocd/doc/third_party_licenses" "${INSTALL_PREFIX}/openocd/docs/"
cp -av "${SOURCE_PREFIX}/openocd/doc"/*.pdf "${INSTALL_PREFIX}/openocd/docs/" || true

rm -rf "${CONTRIB_PREFIX}"

case "$OSTYPE" in
    darwin*)
        if [ ${STATIC} -eq 0 ]; then
            cp "${BUILD_PREFIX}/lib/libusb-1.0.0.dylib" "${BIN_PREFIX}/"
            patch_macos_lib_path "${BIN_PREFIX}/openocd" "libusb-"
        fi
        ;;
    msys*)
        if [ ${STATIC} -eq 0 ]; then
#          cp /mingw64/bin/libwinpthread-1.dll ${BIN_PREFIX}/
#          cp -a "/c/msys64/mingw32/bin/libgcc_s_dw2-1.dll" "${BIN_PREFIX}/"
#          cp -a "/c/msys64/mingw32/bin/libwinpthread-1.dll" "${BIN_PREFIX}/"
            cp -a "${BUILD_PREFIX}/bin/libusb-1.0.dll" "${BIN_PREFIX}/"
            strip "${BIN_PREFIX}"/*.dll
        fi
        ;;
    linux*)
        cp -av "${SOURCE_PREFIX}/openocd/udev_rules" "${INSTALL_PREFIX}/openocd/"
        if [ ${STATIC} -eq 0 ]; then
            find "${BUILD_PREFIX}/lib/" -maxdepth 1 -type f -name "libusb*.so.*" \
                -exec cp -av {} "${BIN_PREFIX}/libusb-1.0.so.0" \;
            strip "${BIN_PREFIX}/libusb-1.0.so.0"
            chrpath -r '$ORIGIN' "${BIN_PREFIX}/openocd"
        fi
        ;;
esac

