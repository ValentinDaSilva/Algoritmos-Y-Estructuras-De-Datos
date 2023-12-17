#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
int posicion(int[],int,int);
void intercambia(int[],int,int,int);

int main(){
    int TL = 10, v[TL], pos1, pos2;
    random(v,TL);
    mostrarVector(v,TL);
    cout<<"Ingrese las dos posiciones a intercambiar: ";cin>>pos1>>pos2;
    intercambia(v,TL,pos1,pos2);
    mostrarVector(v,TL);
    return 0;
}

void intercambia(int v[], int TL, int pos1, int pos2){
    int aux = posicion(v,TL,pos1);
    v[pos1] = posicion(v,TL,pos2);
    v[pos2] = aux;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%10;
    }
}

int posicion(int v[],int TL,int indice){
    int posicion = -1;
    for(int i = 0; i < TL; i++){
        if(i == indice) posicion = v[i];
    }
    return posicion;
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}