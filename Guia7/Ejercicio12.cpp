#include<iostream>
#include<iomanip>
using namespace std;

const int filas = 6, columnas = 5;
void mostrarMatriz(int[][columnas]);
void matrizCaracolInvertida(int[][columnas]);

int main(){
    if(columnas%2 != 0 and filas%2!= 0){
        int M[filas][columnas] = {0};
        matrizCaracolInvertida(M);
        mostrarMatriz(M);
    }
    else {
        cout<<"Las columnas y filas deben ser impares."<<endl;
    }
    return 0;
}

void matrizCaracolInvertida(int M[][columnas]){
    // 0 izquierda, 1 abajo, 2 derecha , 3 arriba
    int valor = 1,
        pasos = 1,
        dir = 0,
        x = columnas / 2,
        y = filas / 2;
    M[y][x] = valor;
    valor++;
    while(valor <= filas * columnas){
        for(int i = 0; i < pasos and valor <= filas * columnas; i++, valor++){
            if(dir == 0) --x;
            else if( dir == 1) ++y;
            else if( dir == 2) ++x; 
            else --y; 
            M[y][x] = valor;
        }
        dir++;
        if(dir == 4) dir = 0;  
        if(dir == 0 or dir == 2) pasos++;
    }  
}

void mostrarMatriz(int M[][columnas]){
    for(int i = 0; i < filas; i++){
        cout<<"[ ";
        for(int j = 0; j < columnas; j++)
            cout<<setw(2)<<M[i][j]<<" ";
        cout<<"]"<<endl;
    }
    cout<<endl;
}