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

    for (int vkcode = 0x01; vkcode < 0xFE; vkcode++) {
        archivo << vkcode << " " << vkcode << endl;
    }
    
    archivo.close();
}

/**
 * @fn cargarMapeoTeclas
 * @brief Carga el mapeo de teclas desde un archivo.
 * @param nombreArchivo Nombre del archivo que contiene el mapeo de teclas.
 * @return Un mapa que relaciona las teclas originales con las teclas mapeadas.
 */
map<int, int> cargarMapeoTeclas(const string& nombreArchivo){
    map<int, int> mapeo;
    ifstream archivo(nombreArchivo);
    int from, to;
    while (archivo >> from >> to) {
        mapeo[from] = to;
    }
    return mapeo;
}

// /**
//  * @fn modificarMapeoTecla
//  * @brief Modifica el mapeo de teclas cargado en memoria
//  * @param mapeo Estructura de datos map<int, int> del mapeo de teclas.
//  * @param teclaOriginal tecla que se encuentra cargada en el mapeo.
//  * @param teclaNueva tecla que se presionara en vez de la tecla original
//  */
// void modificarMapeoTecla(map<int, int>& mapeo, int teclaOriginal, int teclaNueva){
//     mapeo[teclaOriginal] = teclaNueva;
// }

// /**
//  * @fn actualizarArchivo
//  * @brief Actualiza el archivo de mapeo de teclas
//  * @param mapeo Estructura de datos map<int, int> del mapeo de teclas
//  * @param nombreArchivo Nombre del archivo de mapeo
// */
// void actualizarArchivo(map<int, int>& mapeo, const string& nombreArchivo){
//     ofstream archivo(nombreArchivo, ios::trunc);
//     for (auto const& teclado : mapeo){
//         // cout<< teclado.first << " " << teclado.second << endl;
//         archivo << teclado.first << " " << teclado.second << endl;
//     }
//     archivo.close();
// }