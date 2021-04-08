#/usr/bin/env bash

function output_info () {
    echo -e "\033[1;32;40m$1\033[0:39m"
}

EDK2_DIR="$(cd $(dirname $0); pwd)/edk2"

if [ ! -e $EDK2_DIR ]; then
    output_info "Installing EDK2"
    git -c advice.detachedHead=false clone https://github.com/tianocore/edk2 -b edk2-stable202102

    cd $EDK2_DIR
    output_info "Updating submodules"
    git submodule update --init --recursive

    output_info "Building BaseTools"
    make -C BaseTools
fi

if [ ! -e "${EDK2_DIR}/Conf/target.txt" ]; then
    cd $EDK2_DIR
    output_info "Copying ./target.txt to ./edk2/Conf"
    cp ../target.txt ./Conf
fi

if [ ! -e "${EDK2_DIR}/MikanLoaderPkg" ]; then
    cd $EDK2_DIR
    output_info "Creating symbolic link in ./edk2"
    ln -s ../MikanLoaderPkg ./
fi
