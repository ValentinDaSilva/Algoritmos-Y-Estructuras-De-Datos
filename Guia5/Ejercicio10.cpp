#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void rotarIzquierda(int[],int);

int main(){
    int TL = 10, v[TL];
    random(v,TL);
    mostrarVector(v,TL);
    rotarIzquierda(v,TL);
    mostrarVector(v,TL);
    return 0;
}

void rotarIzquierda(int v[],int TL){
    int aux = v[0];
    for(int i = 1; i < TL; i++){
        v[i-1] = v[i];
    }
    v[TL-1]= aux;
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