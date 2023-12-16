#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
int cantRepetidosMas10(int[],int);


int main(){
    int TL = 100, v[TL];
    random(v,TL);
    mostrarVector(v,TL);
    cantRepetidosMas10(v,TL);
    return 0;
}

int cantRepetidosMas10(int v[],int TL){
    int cantRepetidos, cantRepetidosAux;
    for(int i = 0; i < TL; i++){
        if(v[i] == v[i+1]) cantRepetidosAux++;
        else{
            cantRepetidosAux++;
            if(cantRepetidosAux > 10) cantRepetidos++;
            cantRepetidosAux = 0;
        }
    }
    return cantRepetidos;
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