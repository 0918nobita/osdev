#/usr/bin/env bash

clang++ -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar -mno-red-zone -Wall -Wextra -c main.cc
lld-link /subsystem:efi_application /entry:EfiMain /out:main.efi main.o
