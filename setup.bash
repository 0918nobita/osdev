#/usr/env/bin bash

if [ ! -e "OVMF_CODE.fd" ]; then
    wget "https://github.com/uchan-nos/mikanos-build/raw/master/devenv/OVMF_CODE.fd"
fi

if [ ! -e "OVMF_VARS.fd" ]; then
    wget 'https://github.com/uchan-nos/mikanos-build/raw/master/devenv/OVMF_VARS.fd'
fi
