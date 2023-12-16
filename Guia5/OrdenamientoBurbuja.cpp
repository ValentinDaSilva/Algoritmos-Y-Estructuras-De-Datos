#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void ordenamientoBurbuja(int[],int);
void intercambiarPosiciones(int[],int,int);

int main(){
    int TL = 10, v[TL];
    random(v,TL);
    mostrarVector(v,TL);
    ordenamientoBurbuja(v,TL);
    mostrarVector(v,TL);
    return 0;
}

void ordenamientoBurbuja(int v[],int TL){
    int intercambios, k = 0;
    while(k < TL and intercambios != 0){
        intercambios = 0;
        for(int i = 0; i < TL - (k + 1); i++){
            if(v[i] > v[i+1]){
                 intercambiarPosiciones(v,i,i+1);
                intercambios++;
            }
        }
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