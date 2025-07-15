// TeclaEventDispatcher.h
#pragma once
#include <functional>

class TeclaEventDispatcher {
public:
    static void setCallback(std::function<void(int)> callback); // registra la función
    static void dispatch(int vkCode); // ejecuta la función si está definida

private:
    static std::function<void(int)> callback; // variable estática que guarda la función
};
