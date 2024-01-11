#include <iostream>
using namespace std;
const int FILAS = 480;
const int COLUMNAS = 640;

// Definición de la estructura
struct Imagen {
    int** pixels; // Puntero a un array de punteros (filas)
};

// Módulo para ingresar las primeras 100 filas
void ingresarPrimeras100Filas(Imagen& imagen) {
    imagen.pixels = new int*[100]; // Reservar memoria para 100 filas

    for (int i = 0; i < 100; ++i) {
        imagen.pixels[i] = new int[COLUMNAS]; // Reservar memoria para 640 puntos en cada fila

        // Lógica para ingresar los valores (tonos de gris) de cada punto en la fila i
        for (int j = 0; j < COLUMNAS; ++j) {
            // Aquí puedes pedir al usuario que ingrese los valores o asignar valores de prueba
            imagen.pixels[i][j] = i * COLUMNAS + j; // Ejemplo: Asignar un valor creciente para cada punto
        }
    }
}

// Módulo para liberar la memoria
void liberarMemoria(Imagen& imagen) {
    for (int i = 0; i < 100; ++i) {
        delete[] imagen.pixels[i]; // Liberar memoria de cada fila
    }

    delete[] imagen.pixels; // Liberar memoria del array de punteros (filas)
}

int main() {
    Imagen imagen;

    // Calcular el tamaño de la estructura al principio
    size_t tamanoInicial = sizeof(Imagen);
    cout << "Tamaño inicial de la estructura: " << tamanoInicial << " bytes\n";

    // Ingresar las primeras 100 filas
    ingresarPrimeras100Filas(imagen);

    // Calcular el tamaño de la estructura después de ingresar las primeras 100 filas
    size_t tamanoDespuesDeIngresar = sizeof(Imagen);
    cout << "Tamaño después de ingresar las primeras 100 filas: " << tamanoDespuesDeIngresar << " bytes\n";

    // Liberar la memoria al finalizar el programa
    liberarMemoria(imagen);

    return 0;
}
