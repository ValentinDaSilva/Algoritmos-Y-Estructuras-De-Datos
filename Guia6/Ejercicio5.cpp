#include<iostream>
using namespace std;

const int filas = 3, columnas = 3;
void mostrarMatriz(int[][columnas]);
void random(int[][columnas]);
bool es_magico(int[][columnas]);

int main(){
    int M[filas][columnas] = {{2,7,6},{9,5,1},{4,3,8}};
    cout<<boolalpha<<es_magico(M)<<endl;
    return 0;
}

bool es_magico(int M[][columnas]){
    bool esMagico = true;
    int sumaDiagonal = 0, sumaFilas = 0, sumaColumnas = 0;
    int sumaColumnasAux = 0, sumaFilasAux = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            sumaFilas += M[i][j];
            if(i == j) sumaDiagonal += M[i][j];
        }
        if(i == 0) sumaFilasAux = sumaFilas;
        else {
            if(sumaFilasAux != sumaFilas) esMagico = false;
        }
        sumaFilas = 0;
    }
    cout<<sumaFilasAux<<endl;
    if(esMagico){
        for(int i = 0; i < columnas; i++){
            for(int j = 0; j < filas; j++){
                sumaColumnas += M[j][i]; 
            }
            if(i == 0) sumaColumnasAux = sumaColumnas;
            else {
                if(sumaColumnasAux != sumaColumnas) esMagico = false;
            }
            sumaColumnas = 0;
        }   
    }
    cout<<sumaColumnasAux<<endl;
    if(esMagico){
        if(!(sumaColumnas == sumaDiagonal == sumaFilas)) esMagico = false;
    }
    return esMagico;
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
        cout<<endl;
    }
}