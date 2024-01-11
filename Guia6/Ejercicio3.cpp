#include<iostream>
using namespace std;

const int filas = 4, columnas = filas;
void mostrarMatriz(int[][columnas]);
void random(int[][columnas]);
bool esTriangularSuperior(int[][columnas]);

int main(){
int matriz[filas][columnas] = {
        {1, 2, 3, 4},
        {0, 5, 6, 7},
        {0, 0, 8, 9},
        {0, 0, 0, 4}
    };
    mostrarMatriz(matriz);
    cout<<boolalpha<<esTriangularSuperior(matriz)<<endl;
    return 0;
}

bool esTriangularSuperior(int M[][columnas]){
    int cantidad = 0;
    bool diagonal_superior = true;
    for(int i = 0; i < filas; i++){
        for(int j = 0 ; j < cantidad; j++){
            if(M[i][j] != 0) diagonal_superior = false;
        }
        cantidad++;
    }
    return diagonal_superior;
}

void random(int M[][columnas]){
    srand(time(NULL));
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            M[i][j] = rand()%40+10;
        }
    }
}

void mostrarMatriz(int M[][columnas]){
    for(int i = 0; i < filas; i++){
        cout<<"[ ";
        for(int j = 0; j < columnas; j++){
            cout<<M[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}