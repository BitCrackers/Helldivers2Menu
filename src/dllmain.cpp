#include "version.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        HANDLE moduleHandle = CreateThread(NULL, 0, Load, hModule, NULL, NULL);
    }
    break;
    case DLL_PROCESS_DETACH:
        FreeLibrary(version_dll);
        break;
    }
    return TRUE;
}
