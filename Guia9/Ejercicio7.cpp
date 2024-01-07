#define ANCHO 640
#define ALTO 480

struct Imagen {
    unsigned char Fila[ALTO][ANCHO];
};

int main(){
    
    return 0;
}

void ingresarFilasIniciales(Imagen& img) {
    // Inicializar las primeras 100 filas con un tono de gris medio (128)
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < ANCHO; ++j) {
            img.Fila[i][j] = 128;
        }
    }
}
