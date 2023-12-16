#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void eliminarRepetidos(int[],int&);
int estaEnElVector(int[],int,int,int);
void eliminarElemento(int[],int&,int);

int main(){
    int TL = 15, v[TL]={1,2,3,4,5,1,6,7,1,8,2,9,10,10,3};
    // random(v,TL);
    mostrarVector(v,TL);
    eliminarRepetidos(v,TL);
    mostrarVector(v,TL);
    return 0;
}

void eliminarRepetidos(int v[],int& TL){
    int cantidadParesEliminados = 0, suma = 0;
    //puse para que los elimine del ultimo hacia el inicio
    for(int i = TL - 1; i >= 0; i--){
        if(estaEnElVector(v,TL,v[i],i)){
            if(v[i]%2 == 0) cantidadParesEliminados++;
            eliminarElemento(v,TL,i);
            i--;
        }
    }
    cout<<"Cantidad de elementos pares eliminados: "<<cantidadParesEliminados<<endl;
    for(int i = 0 ; i < TL; i++) suma += v[i];
    cout<<"Los el promedio de elementos es de: "<<suma/(float)TL<<endl;
}
void eliminarElemento(int v[],int& TL, int posicion){
    for(int i = 0; i < TL; i++){
        if(i >= posicion) v[i] = v[i+1]; 
    }
    TL--;
}

int estaEnElVector(int v[], int TL, int elemento, int posicion){
    int i = 0;
    bool encontrado = false;
    while(!encontrado and i < TL){
        if(v[i] == elemento and i!=posicion) encontrado = true;
        i++;
    }
    return encontrado;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%50;
    }
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}