#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void ordenamientoSeleccion(int[],int);
void intercambiarPosiciones(int[],int,int);

int main(){
    int TL = 10, v[TL];
    random(v,TL);
    mostrarVector(v,TL);
    ordenamientoSeleccion(v,TL);
    mostrarVector(v,TL);
    return 0;
}

void ordenamientoSeleccion(int v[],int TL){
    int k = 0, menor;
    while(k < TL){
        for(int i = k; i < TL ; i++ ){
            if(i == k) menor = i;
            else if(v[i] < v[menor]) menor = i;
        }
        intercambiarPosiciones(v,k,menor);
        k++;
    }
}

void intercambiarPosiciones(int v[],int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
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