#!/usr/bin/env bash

if [ -e "disk.img" ] && [ -e "OVMF_CODE.fd" ] && [ -e "OVMF_VARS.fd" ]; then
    qemu-system-x86_64 \
        -drive if=pflash,file=./OVMF_CODE.fd \
        -drive if=pflash,file=./OVMF_VARS.fd \
        -hda disk.img
fi
