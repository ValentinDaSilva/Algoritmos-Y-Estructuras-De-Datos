#include<iostream>
using namespace std;

void random(int[],int);
void mostrarVector(int[],int);

int main(){
    int TL = 10, v[TL], elem1, elem2;
    random(v,TL);
    mostrarVector(v,TL);
    cout<<"Ingrese los dos elementos que quiere intercambiar: ";cin>>elem1>>elem2;
    intercambiarElementos(v,TL,elem1,elem2);
    mostrarVector(v,TL);
    return 0;
}

void intercambiarElementos(int v[],int TL, int elem1, int elem2){
    int pos1 = estaEnElVector(v,TL,elem1),
        pos2 = estaEnElVector(v,TL,elem2);
    if(pos1 < TL and pos2 < TL) intercambiaPosiciones(v,TL,pos1,pos2);
    else{
        cout<<"Uno de los elementos no pertenece al vector"<<endl;
    }
}

int estaEnElVector(int v[],int TL, int elemento){
    if(TL == 0) return 1;
    else{
        if(v[0] == elemento) return 1;
        else return 1 + estaEnElVector(&v[1],TL-1,elemento);
    }
}

void intercambiaPosiciones(int v[],int TL, int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}

void random(int v[],int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++)
        v[i] = rand()%50;
}

void mostrarVector(int v[],int TL){
    if(TL == 0) cout<<"]"<<endl;
    else{
        cout<<v[0]<<" ";
        mostrarVector(&v[1],TL-1);
    }
}