#include<iostream>
#include<iomanip>
using namespace std;
typedef int** PMatriz; 

int filas, columnas;
void mostrarMatriz(int**);
void random(int**);
void crearMatriz(int**&);

int main(){
    cout<<"Ingrese la cantidad de filas y columnas: ";cin>>filas>>columnas;
    PMatriz M;
    crearMatriz(M);
    random(M);
    mostrarMatriz(M);
    return 0;
}

void crearMatriz(int**& M){
    M = new int* [filas];
    for(int i = 0; i < filas ; i ++){
        M[i] = new int[columnas];
    }
}

void random(int** M){
    srand(time(NULL));
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            M[i][j] = rand()%40+10;
        }
    }
}

void mostrarMatriz(int** M){
    for(int i = 0; i < filas; i++){
        cout<<"[ ";
        for(int j = 0; j < columnas; j++){
            cout<<setw(2)<<M[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;
}