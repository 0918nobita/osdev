using EfiStatus = unsigned long long;
using EfiHandle = void*;

using EfiTextString = EfiStatus (*) (struct EfiSimpleTextOutputProtocol *This, const char *string);

struct EfiSimpleTextOutputProtocol {
    void *dummy;
    EfiTextString outputString;
};

struct EfiSystemTable {
    char dummy[25];
    EfiHandle consoleOutHandle;
    EfiSimpleTextOutputProtocol *conOut;
};

EfiStatus EfiMain(EfiHandle imageHandle, EfiSystemTable *systemTable) {
    (void) imageHandle;
    systemTable->conOut->outputString(systemTable->conOut, "Hello, world!\n");
    while (1);
    return 0;
}
