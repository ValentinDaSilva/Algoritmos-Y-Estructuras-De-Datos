#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void rotarDerecha(int[],int);

int main(){
    int TL = 10, v[TL];
    random(v,TL);
    mostrarVector(v,TL);
    rotarDerecha(v,TL);
    mostrarVector(v,TL);
    return 0;
}

void rotarDerecha(int v[],int TL){
    int aux = v[TL - 1];
    for(int i = (TL -1); i > 0; i--){
        v[i] = v[i-1];
    }
    v[0]= aux;
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