#include <iostream>
#include <fstream>

int main() {
    std::ifstream archivo("archivo.txt");

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl; // Imprimir cada línea del archivo
        }
        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo.\n";
    }

    return 0;
}
