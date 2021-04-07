using Char16 = unsigned short;
using EfiStatus = unsigned long long;
using EfiHandle = void*;
using EfiTextString = EfiStatus (*) (struct EfiSimpleTextOutputProtocol *This, Char16 *string);

struct EfiSimpleTextOutputProtocol {
    void *dummy;
    EfiTextString outputString;
};

struct EfiSystemTable {
    char dummy[52];
    EfiHandle consoleOutHandle;
    EfiSimpleTextOutputProtocol *conOut;
};

EfiStatus EfiMain(EfiHandle imageHandle, EfiSystemTable *systemTable) {
    (void) imageHandle;
    systemTable->conOut->outputString(systemTable->conOut, (unsigned short *) L"Hello, world!\n");
    while (1);
    return 0;
}
