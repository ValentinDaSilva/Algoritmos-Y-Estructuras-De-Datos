#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
int buscarMayorEnrango(int[],int,int,int);
int main(){
    int TL = 10, v[TL],inf,sup;
    random(v,TL);
    mostrarVector(v,TL);
    cout<<"Ingrese un rango para buscar el mayor: ";cin>>inf>>sup;
    cout<<buscarMayorEnrango(v,TL,inf,sup)<<endl;
    return 0;
}


int buscarMayorEnrango(int v[],int TL,int inf,int sup){
    int mayor;
    for(int i = inf; i < sup; i++){
        if(i == inf) mayor = v[i];
        else{
            if(v[i] > mayor) mayor = v[i];
        } 
    }
    return mayor;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%100;
    }
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}