#include<iostream>
#include<iomanip>
using namespace std;

const int filas = 3, columnas = 3;
void mostrarMatriz(int[][columnas]);
void random(int[][columnas]);
bool diagonSecundariaEnAlgunaCelda(int[][columnas],int[][columnas],int[]);
bool diagonalSecundariaEnPrincipal(int[][columnas],int[][columnas],int[]);
bool diagonalSecundariaEnSecundaria(int[][columnas],int[][columnas],int[]);
bool buscarEnElVector(int[],int);

int main(){
    int M[filas][columnas] = {{1,2,3},{4,5,6},{7,8,9}}, N[filas][columnas] = {{3,2,1},{1,5,7},{7,8,7}};
    int diagonalSegcundariaM[filas] = {0};
    // random(M);
    // random(N);
    mostrarMatriz(M);
    mostrarMatriz(N);
    cout<<"Esta la diagonal secundaria de A en alguna celda: "<<boolalpha<<diagonSecundariaEnAlgunaCelda(M,N,diagonalSegcundariaM)<<endl;
    cout<<"Esta la diagonal secundaria de A en la principal de B: "<<boolalpha<<diagonalSecundariaEnPrincipal(M,N,diagonalSegcundariaM)<<endl;
    cout<<"Esta la diagonal secundaria de A en la secundaria de B: "<<boolalpha<<diagonalSecundariaEnSecundaria(M,N,diagonalSegcundariaM)<<endl;
    
    return 0;
}

bool diagonalSecundariaEnSecundaria(int M[][columnas],int N[][columnas],int diagonalSecundaria[]){
    int diagonalSecundariaB[filas];
    bool encontrada = true;
    for(int i = 0, j = columnas - 1; i < filas; i++, j--){
        diagonalSecundariaB[i] = N[i][j];
    }
    int i = 0;
    while(encontrada and i < filas){
        if(!buscarEnElVector(diagonalSecundariaB,diagonalSecundaria[i])) encontrada = false;
        i++;
    }
    return encontrada;
}

bool diagonalSecundariaEnPrincipal(int M[][columnas],int N[][columnas],int diagonalSecundaria[]){
    int diagonalPrincipalB[filas];
    bool encontrada = true;
    for(int i = 0; i < filas; i++){
        diagonalPrincipalB[i] = N[i][i];
    }
    int i = 0;
    while(encontrada and i < filas){
        if(!buscarEnElVector(diagonalPrincipalB,diagonalSecundaria[i])) encontrada = false;
        i++;
    }
    return encontrada;
}

bool buscarEnElVector(int v[],int elem){
    bool encontrado = false;
    int i = 0;
    while(!encontrado and i < filas){
        if(v[i] == elem) encontrado = true;
        i++;
    }
    return encontrado;
}

bool diagonSecundariaEnAlgunaCelda(int M[][columnas],int N[][columnas], int diagonalSegcundariaM[]){
    bool diagonalEncontrada = true, returnEncontrada = false;
    for(int i = 0, j = columnas - 1; i < filas; i++, j--){
        diagonalSegcundariaM[i] = M[i][j];
    }
    int i = 0;
    while(!returnEncontrada and i < filas){
        int j = 0;
        while(diagonalEncontrada and j < columnas){
            if(diagonalSegcundariaM[j] != N[i][j]) {
                diagonalEncontrada = false;
            }
            j++;
        }
        if(diagonalEncontrada) returnEncontrada = true;
        else diagonalEncontrada = true;
        i++;
    }
    return returnEncontrada;
}

void random(int M[][columnas]){
    srand(time(NULL));
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            M[i][j] = rand()%5;
        }
    }
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