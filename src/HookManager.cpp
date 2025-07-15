#include "HookManager.h"
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
        // Mostrar información de la tecla presionada
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            cout << "Tecla presionada:"
                      << "\n  - vkCode: " << puntero->vkCode
                      << "\n  - Flags: " << puntero->flags
                      << "\n  - ScanCode: " << puntero->scanCode
                      << std::endl;
        }

    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}