#pragma once
#include <windows.h>
#include <iostream>
#include <map>

using namespace std;

LRESULT CALLBACK KeyBoardProcedure(int nCode, WPARAM wParam, LPARAM lParam);
void modificarTeclaMapeo(map<int, int>& mapeo);