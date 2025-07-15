#pragma once

#include <fstream>
#include <iostream>
#include <map>

using namespace std;

bool archivoExiste (const string& nombreArchivo);
void crearArchivoDefecto(const string& nombreArchivo);
map<int, int> cargarMapeoTeclas(const string& nombreArchivo);
// void modificarMapeoTecla(map<int, int>& mapeo, int teclaOriginal, int teclaNueva);
// void actualizarArchivo(map<int, int>& mapeo, const string& nombreArchivo);