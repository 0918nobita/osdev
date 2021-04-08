#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

typedef struct MemoryMap {
    UINTN buffer_size;
    VOID *buffer;
    UINTN map_size;
    UINTN map_key;
    UINTN descriptor_size;
    UINT32 descriptor_version;
} MemoryMap;

EFI_STATUS GetMemoryMap(MemoryMap *map) {
    if (map->buffer == NULL) return EFI_BUFFER_TOO_SMALL;

    map->map_size = map->buffer_size;

    return gBS->GetMemoryMap(
        &map->map_size,          // IN: メモリマップ書き込み用のメモリ領域の大きさ, OUT: 実際のメモリマップの大きさ
        map->buffer,             // IN: メモリマップ書き込み用のメモリ領域の先頭アドレス, OUT: メモリマップを指定されたアドレスに書き込む
        &map->map_key,           // OUT: メモリマップを識別するための値
        &map->descriptor_size,   // OUT: メモリディスクリプタ (メモリマップの各行) のサイズ
        &map->descriptor_version // OUT: メモリディスクリプタの構造体のバージョン
    );
}

EFI_STATUS EFIAPI UefiMain(
    EFI_HANDLE image_handle,
    EFI_SYSTEM_TABLE *system_table
) {
    CHAR8 mem_map_buf[4096 * 4]; // 4ページ (1ページあたり 4096 byte (= 4KiB))
    MemoryMap mem_map;
    mem_map.buffer_size = sizeof(mem_map_buf);
    mem_map.buffer = mem_map_buf;
    GetMemoryMap(&mem_map);

    Print(L"Hello, world!\n");

    while (1);

    return EFI_SUCCESS;
}
