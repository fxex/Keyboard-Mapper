#include <windows.h>
#include <iostream>
#include <HookManager.h>
#include <KeyboardMapper.h>

using namespace std;
int main(int, char**){
    string nombreArchivo = "mapeo.txt";
    if (!archivoExiste(nombreArchivo)) {
        crearArchivoDefecto(nombreArchivo);
    }

    map<char, char> mapeoTeclas = cargarMapeoTeclas(nombreArchivo);
    

    // HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardProcedure, NULL, 0);
    // if (hHook == NULL) {
    //     std::cerr << "Error al instalar el hook: " << GetLastError();
    // }

    // MSG msg;
    // while (GetMessage(&msg, NULL, 0, 0)) {
    //     TranslateMessage(&msg);
    //     DispatchMessage(&msg);
    // }

    // UnhookWindowsHookEx(hHook);

    return 0;    
}
