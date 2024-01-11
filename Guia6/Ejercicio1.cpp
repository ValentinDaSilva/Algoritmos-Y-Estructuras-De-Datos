#include<iostream>
using namespace std;

const int filas = 5, columnas = filas;
void mostrarMatriz(int[][columnas]);
void random(int[][columnas]);
void kbenviados(int[][columnas],int);

int main(){
    int M[filas][columnas], limite;
    random(M);
    mostrarMatriz(M);
    cout<<"Ingrese el limite de kbrecibidos de cada servidor: ";cin>>limite;
    cout<<"Total de kb enviados por cada servidor: "<<endl;
    kbenviados(M,limite);
    return 0;
}

void kbenviados(int M[][columnas], int limiteRecibidos){
    int suma = 0,mayor = 0,indiceMayor, kbrecibidos = 0, superoKbRecibidos[filas] = {0};
    for(int i = 0 ; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            suma+=M[i][j];
            kbrecibidos += M[j][i];
        }
        if(kbrecibidos > limiteRecibidos) superoKbRecibidos[i] = 1; 
        if(suma > mayor){
            mayor = suma;
            indiceMayor = i + 1;
        }
        cout<<"Servidor "<<i+1<<": "<<suma<<endl;
        suma = 0;
        kbrecibidos = 0;
    }
    cout<<endl;
    cout<<"El servidor que mas kbs de correos mando fue el n"<<indiceMayor<<endl;
    cout<<endl;
    for(int i = 0; i < filas; i++){
        if(superoKbRecibidos[i] == 1) cout<<"El servidor "<<i+1<<" supero el limite de correos recibidos"<<endl;
    }
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