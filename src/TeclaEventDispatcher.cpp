// TeclaEventDispatcher.cpp
#include "TeclaEventDispatcher.h"

// Definición de la variable estática declarada en el .h
std::function<void(int)> TeclaEventDispatcher::callback = nullptr;

void TeclaEventDispatcher::setCallback(std::function<void(int)> cb) {
    callback = cb;
}

void TeclaEventDispatcher::dispatch(int vkCode) {
    if (callback) {
        callback(vkCode); // ejecuta la función registrada si existe
    }
}
