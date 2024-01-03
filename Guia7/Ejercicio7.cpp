#include<iostream>
#include<iomanip>
using namespace std;

const int filas = 5, columnas = 5;
void mostrarMatriz(int[][columnas]);
void rellenarNoOptimizado(int[][columnas]);
void rellenarOptimizado(int[][columnas]);

int main(){
    int M[filas][columnas] = {0};
    rellenarOptimizado(M);
    //rellenarNoOptimizado(M)
    mostrarMatriz(M);
    return 0;
}

void rellenarNoOptimizado(int M[][columnas]){
    int numero = 1, limite = columnas * filas;
    int inicioArriba = 0, finArriba = columnas-1, filaArriba = 0;
    int inicioDerecha = 1,finDerecha = filas - 1, columnaDerecha = columnas - 1;
    int inicioAbajo = columnas - 2,finAbajo = 0, filaAbajo = filas - 1;
    int inicioIzquierda = filas -2 ,finIzquierda = 1, columnaIzquierda = 0;
    do{
        for(int i = inicioArriba; i <= finArriba and numero <= limite; i++, numero++){
            M[filaArriba][i] = numero;
        }
        for(int i = inicioDerecha; i <= finDerecha and numero <= limite; i++, numero++){
            M[i][columnaDerecha] = numero;
        }
        for(int i = inicioAbajo; i >= finAbajo and numero <= limite; i--, numero++){
            M[filaAbajo][i] = numero;
        }
        for(int i = inicioIzquierda; i >= finIzquierda and numero <= limite; i--, numero++){
            M[i][columnaIzquierda] = numero;
        }
        inicioArriba++; finArriba--; filaArriba++;
        inicioDerecha++; finDerecha--; columnaDerecha--;
        inicioAbajo--; finAbajo++; filaAbajo--;
        inicioIzquierda--; finIzquierda++; columnaIzquierda++;
    }while(numero <= limite);
}

void rellenarOptimizado(int M[][columnas]){
    int numero = 1, limite = columnas*filas;
    int filaInicio = 0, filaFin = filas - 1;
    int columnaInicio = 0, columnaFin = columnas - 1;
    do{
        for(int i = columnaInicio; i <= columnaFin; i++, numero++){
            M[filaInicio][i] = numero;
        }
        filaInicio++;
        for(int i = filaInicio; i <= filaFin; i++, numero++){
            M[i][columnaFin] = numero;
        }
        columnaFin--;
        for(int i = columnaFin; i >= columnaInicio; i--, numero++){
            M[filaFin][i] = numero;
        }
        filaFin--;
        for(int i = filaFin; i >= filaInicio; i--, numero++){
            M[i][columnaInicio] = numero;
        }
        columnaInicio++;
    }while(numero <= limite);
}

void mostrarMatriz(int M[][columnas]){
    for(int i = 0; i < filas; i++){
        cout<<"[ ";
        for(int j = 0; j < columnas; j++){
            cout<<setw(2)<<M[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;
}