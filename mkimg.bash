#/usr/bin/env bash

if [ ! -e "disk.img" ]; then
    qemu-img create -f raw disk.img 200M
    mkfs.fat -n "MIKAN OS" -s 2 -f 2 -R 32 -F 32 disk.img
fi

if [ -e "disk.img" ] && [ -e "main.efi" ]; then
    sudo mount -o loop disk.img mnt
    sudo mkdir -p mnt/EFI/BOOT
    sudo cp main.efi mnt/EFI/BOOT/BOOTX64.EFI
    sudo umount mnt
fi
