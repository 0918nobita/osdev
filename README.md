# 自作OS

## 準備

```bash
bash ./setup.bash
```

## ブートローダのビルド

```bash
cd ./edk2
source edksetup.sh
build
```

## USB メモリへの書き込み

```bash
sudo mount /dev/sdb1 /mnt/usbmem
sudo cp edk2/Build/MikanLoaderX64/DEBUG_CLANG38/X64/Loader.efi /mnt/usbmem/EFI/BOOT/BOOTX64.EFI
sudo umount /dev/sdb1
```
