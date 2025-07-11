#include "KeyboardMapper.h"
/**
 * @fn archivoExiste
 * @brief Verifica si un archivo existe.
 * @param nombreArchivo Nombre del archivo a verificar.
 */
bool archivoExiste (const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    return archivo.good();
}

/**
 * @fn crearArchivoDefecto
 * @brief Crea un archivo con un mapeo de teclas por defecto de teclado latinoamericano.
 * @param nombreArchivo Nombre del archivo a crear.
 */
void crearArchivoDefecto(const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cout << "No se pudo crear el archivo: " << nombreArchivo << endl;
        return;
    }

    archivo << "a a\n";
    archivo << "b b\n";
    archivo << "c c\n";
    archivo << "d d\n";
    archivo << "e e\n";
    archivo << "f f\n";
    archivo << "g g\n";
    archivo << "h h\n";
    archivo << "i i\n";
    archivo << "j j\n";
    archivo << "k k\n";
    archivo << "l l\n";
    archivo << "m m\n";
    archivo << "n n\n";
    archivo << "ñ ñ\n";
    archivo << "o o\n";
    archivo << "p p\n";
    archivo << "q q\n";
    archivo << "r r\n";
    archivo << "s s\n";
    archivo << "t t\n";
    archivo << "u u\n";
    archivo << "v v\n";
    archivo << "w w\n";
    archivo << "x x\n";
    archivo << "y y\n";
    archivo << "z z\n";  
    archivo.close();
}

/**
 * @fn cargarMapeoTeclas
 * @brief Carga el mapeo de teclas desde un archivo.
 * @param nombreArchivo Nombre del archivo que contiene el mapeo de teclas.
 * @return Un mapa que relaciona las teclas originales con las teclas mapeadas.
 */
map<char, char> cargarMapeoTeclas(const string& nombreArchivo){
    map<char, char> mapeo;
    ifstream archivo(nombreArchivo);
    char from, to;
    while (archivo >> from >> to) {
        mapeo[from] = to;
    }
    return mapeo;
}