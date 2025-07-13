#include <fstream>
#include <iostream>
#include <map>

using namespace std;

bool archivoExiste (const string& nombreArchivo);
void crearArchivoDefecto(const string& nombreArchivo);
map<char, char> cargarMapeoTeclas(const string& nombreArchivo);
void modificarMapeoTecla(map<char, char>& mapeo, char teclaOriginal, char teclaNueva);