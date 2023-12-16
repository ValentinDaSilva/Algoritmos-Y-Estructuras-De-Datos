#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void eliminarImparesEntreParesAdyacentes(int[],int&);
void eliminarPosicion(int[],int&,int);

int main(){
    int TL = 10, v[] = {1, 2, 3, 4, 7, 9, 12, 14, 15, 20};
    eliminarImparesEntreParesAdyacentes(v,TL);
    mostrarVector(v,TL);
    return 0;
}

void eliminarPosicion(int v[], int& TL, int posicion){
    for(int i = 0; i < TL; i++){
        if(i >= posicion) v[i] = v[i+1];
    }
    TL--;
}

void eliminarImparesEntreParesAdyacentes(int v[],int& TL){
    int cantidadImparesEliminados = 0, mayorDiferencia = 0, diferencia;
    for(int i = 0; i < (TL - 2); i++){
        if(v[i]%2 == 0 and v[i+2]%2 == 0 and v[i+1]%2!=0){
            diferencia = v[i+2] - v[i];
            eliminarPosicion(v,TL,i+1);
            cantidadImparesEliminados++;
            if (diferencia > mayorDiferencia) mayorDiferencia = diferencia;
        }
    }
    cout<<"Cantidad de impares eliminados: "<<cantidadImparesEliminados<<endl;
    cout<<"Mayor diferencia entre dos pares sucesivos: "<<mayorDiferencia<<endl;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%10;
    }
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}