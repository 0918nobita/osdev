#/usr/bin/env bash

EDK2_DIR="$(cd $(dirname $0); pwd)/edk2"

if [ ! -e $EDK2_DIR ]; then
    git clone https://github.com/tianocore/edk2
    cd $EDK2_DIR
    git submodule update --init --recursive
    make -C BaseTools
fi

if [ ! -e "${EDK2_DIR}/Conf/target.txt" ]; then
    cd $EDK2_DIR
    cp ../target.txt ./Conf
fi

if [ ! -e "${EDK2_DIR}/MikanLoaderPkg" ]; then
    cd $EDK2_DIR
    ln -s ../MikanLoaderPkg ./
fi
