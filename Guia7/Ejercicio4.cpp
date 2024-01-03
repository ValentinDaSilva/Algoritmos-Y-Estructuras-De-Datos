#include<iostream>
using namespace std;

const int filas = 4, columnas = filas;
void mostrarMatriz(int[][columnas]);
void random(int[][columnas]);
bool esDiagonal(int[][columnas]);

int main(){
int matriz[filas][columnas] = {
        {1, 0, 0, 0},
        {0, 5, 0, 0},
        {0, 0, 8, 0},
        {0, 0, 0, 4}
    };
    mostrarMatriz(matriz);
    cout<<boolalpha<<esDiagonal(matriz)<<endl;
    return 0;
}

bool esDiagonal(int M[][columnas]){
    bool diagonal = true;
    for(int i = 0; i < filas; i++){
        for(int j = 0 ; j < columnas; j++){
            if(i != j and M[i][j] != 0){
                diagonal = false;
            }
        }
    }
    return diagonal;
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
    cout<<endl;
}