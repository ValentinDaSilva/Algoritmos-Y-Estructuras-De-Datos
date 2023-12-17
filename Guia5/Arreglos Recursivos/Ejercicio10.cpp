#include<iostream>
using namespace std;

void random(int[],int);
void mostrarVector(int[],int);
void rotarIzquierda(int[],int);
void rotarIzquierdaAux(int[],int,int);

int main(){
    int TL = 10, v[TL];
    random(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    rotarIzquierda(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    return 0;
}

void rotarIzquierda(int v[],int TL){
    rotarIzquierdaAux(v,TL,v[0]);
}

void rotarIzquierdaAux(int v[],int TL, int elem1){
    if(TL == 1) v[0] = elem1 ;
    else{
        v[0] = v[1];
        rotarIzquierdaAux(&v[1],TL-1,elem1);
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
