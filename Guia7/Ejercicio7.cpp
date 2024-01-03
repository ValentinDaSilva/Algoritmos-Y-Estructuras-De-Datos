#include<iostream>
using namespace std;

const int filas = 3, columnas = 3;
void mostrarMatriz(int[][columnas]);
void rellenar(int[][columnas]);

int main(){
    int M[filas][columnas] = {0};
    rellenar(M);
    mostrarMatriz(M);
    return 0;
}

void rellenar(int M[][columnas]){
    int numero = 1;
    int columnaInicio = 0, columnaFin = columnas-1 , fila = 0;
    for(int j = columnaInicio; j <= columnaFin; j++, numero++){
        M[fila][j] = numero;
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
    cout<<endl;
}