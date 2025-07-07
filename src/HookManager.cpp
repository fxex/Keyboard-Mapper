#include "HookManager.h"
#include <iostream>

LRESULT CALLBACK KeyBoardProcedure(int nCode, WPARAM wParam, LPARAM lParam){
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* puntero = (KBDLLHOOKSTRUCT*)lParam;
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            BYTE keyState[256];
            GetKeyboardState(keyState);

            WCHAR buffer[4];

            int result = ToUnicode(
                puntero->vkCode,
                puntero->scanCode,
                keyState,
                buffer,
                4,
                0
            );

            if (result > 0) {
                buffer[result] = '\0';
                std::wcout << L"Tecla Presionada: " << buffer << std::endl;
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}