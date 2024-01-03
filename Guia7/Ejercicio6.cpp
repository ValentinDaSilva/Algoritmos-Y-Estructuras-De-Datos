#include<iostream>
using namespace std;

const int filas = 10, columnas = 12;
void mostrarMatriz(int[][columnas]);
void random(int[][columnas]);
void jugada(int[][columnas]);

int main(){
    int M[filas][columnas];
    random(M);
    mostrarMatriz(M);
    jugada(M);
    mostrarMatriz(M);
    return 0;
}

void jugada(int M[][columnas]){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas - 3; j++){
            if(M[i][j] == 2 and M[i][j+1] == 2 and M[i][j+2] == 2){
                M[i][j] = 0;
                M[i][j+2] = 0;
            }
            if(M[i][j] == 2){
                if(i != 0 and i!=filas-1 and j!=0 and j!=columnas-1){
                    if(M[i-1][j-1] == 1 and M[i-1][j] == 1 and M[i-1][j+1] == 1){
                        if(M[i][j-1] == 1 and M[i][j+1] == 1){
                            if(M[i+1][j-1] == 1 and M[i+1][j] == 1 and M[i+1][j+1] == 1){
                                M[i][j] = 1;
                                M[i-1][j-1] = 0; 
                                M[i-1][j] = 0; 
                                M[i-1][j+1] = 0; 
                                M[i][j-1] = 0; 
                                M[i][j+1] = 0; 
                                M[i+1][j-1] = 0; 
                                M[i+1][j] = 0; 
                                M[i+1][j+1] = 0; 
                            }
                        }
                    }
                }
            }
        }
    }
}

void random(int M[][columnas]){
    srand(time(NULL));
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            M[i][j] = rand()%3;
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