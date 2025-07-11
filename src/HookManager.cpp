#include "HookManager.h"
#include <iostream>
/**
 * @fn KeyBoardProcedure
 * @brief Proporciona un procedimiento de llamada para el hook del teclado para el mapeo de teclas.
 * @param nCode Código de la llamada al hook.
 * @param wParam Parámetro adicional que indica el tipo de evento del teclado.
 * @param lParam Parámetro adicional que contiene información sobre el evento del teclado.
 */
LRESULT CALLBACK KeyBoardProcedure(int nCode, WPARAM wParam, LPARAM lParam){
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* puntero = (KBDLLHOOKSTRUCT*)lParam;
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            DWORD key = puntero->vkCode;
            if (key == 0x41) {
                INPUT input[2] = {};
                input[0].type = INPUT_KEYBOARD;
                input[0].ki.wVk = 0x42;

                input[1].type = INPUT_KEYBOARD;
                input[1].ki.wVk = 0x42;
                input[1].ki.dwFlags = KEYEVENTF_KEYUP;

                SendInput(2, input, sizeof(INPUT));

                return 1;
            }
            
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}