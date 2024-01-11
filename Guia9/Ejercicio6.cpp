#define SIZE 100
#define SIZE_NAME 100


struct picture_info {
    char name[SIZE_NAME];
    int date_time;
} pictures[SIZE];


int main (){
    // Declaración de la segunda tabla que contiene punteros a picture_info
    picture_info* pointers[SIZE];

    // Rellenar la tabla de punteros con direcciones de las estructuras en la tabla 'pictures'
    for (int i = 0; i < SIZE; ++i) {
        pointers[i] = &pictures[i];
    }
    return 0;
}