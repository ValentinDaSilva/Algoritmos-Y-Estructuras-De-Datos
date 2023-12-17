#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void intercambia(int[],int,int,int);
int estaEnElVector(int[],int,int);

int main(){
    int TL = 10, v[TL], elem1, elem2;
    random(v,TL);
    mostrarVector(v,TL);
    cout<<"Ingrese las dos elementos a intercambiar: ";cin>>elem1>>elem2;
    intercambiarElementos(v,TL,elem1,elem2);
    mostrarVector(v,TL);
    return 0;
}

void intercambiarElementos(int v[],int TL, int elem1, int elem2){
    int pos1 = estaEnElVector(v,TL,elem1),
        pos2 = estaEnElVector(v,TL,elem2);
    
    if(pos1 != -1 and pos2 != -1){
        intercambiarElementos(v,TL,pos1,pos2);
    }else{
        cout<<"Uno de los elementos no pertenece al vector"<<endl;
    }

}

int estaEnElVector(int v[],int TL,int elemento){
    int i = 0;
    bool encontrado = false;
    while(!encontrado and i < TL){
        if(v[i] == elemento) encontrado = true;
        i++;
    }
    (encontrado)? i-- : i = -1;
    return i;
}

void intercambia(int v[], int TL, int pos1, int pos2){
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