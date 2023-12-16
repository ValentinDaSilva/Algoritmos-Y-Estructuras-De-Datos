#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void ordenamientoInsercion(int[],int);
void intercambiarPosiciones(int[],int,int);

int main(){
    int TL = 10, v[TL];
    random(v,TL);
    mostrarVector(v,TL);
    ordenamientoInsercion(v,TL);
    mostrarVector(v,TL);
    return 0;
}

void ordenamientoInsercion(int v[],int TL){
    int i;
    for(int k = 1; k < TL; k++){
        i=k;  
        while(i > 0 and (v[i]<v[i-1])){
            intercambiarPosiciones(v,i,i-1);
            i--;
        }
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