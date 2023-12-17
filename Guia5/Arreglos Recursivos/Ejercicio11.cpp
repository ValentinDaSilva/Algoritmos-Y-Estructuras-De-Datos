#include<iostream>
using namespace std;

void random(int[],int);
void mostrarVector(int[],int);
void rotarDerecha(int[],int);
void rotarDerechaAux(int[],int,int);

int main(){
    int TL = 10, v[TL];
    random(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    rotarDerecha(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    return 0;
}

void rotarDerecha(int v[],int TL){
    rotarDerechaAux(v,TL,v[TL-1]);
}

void rotarDerechaAux(int v[],int TL, int elem1){
    if(TL == 1) v[0] = elem1;
    else{
        v[TL - 1] = v[TL - 2];
        rotarDerechaAux(v,TL-1,elem1);
    }
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
