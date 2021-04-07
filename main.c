typedef unsigned short Char16;
typedef unsigned long long EfiStatus;
typedef void *EfiHandle;

typedef EfiStatus (*EfiTextString) (struct EfiSimpleTextOutputProtocol *This, Char16 *String);

struct EfiSimpleTextOutputProtocol;
typedef struct EfiSimpleTextOutputProtocol {
    void *dummy;
    EfiTextString outputString;
} EfiSimpleTextOutputProtocol;

typedef struct {
    char dummy[52];
    EfiHandle consoleOutHandle;
    EfiSimpleTextOutputProtocol *conOut;
} EfiSystemTable;

EfiStatus EfiMain(EfiHandle imageHandle, EfiSystemTable *systemTable) {
    systemTable->conOut->outputString(systemTable->conOut, L"Hello, world!\n");
    while (1);
    return 0;
}
