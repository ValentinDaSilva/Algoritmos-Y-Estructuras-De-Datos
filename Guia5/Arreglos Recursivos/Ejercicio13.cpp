#include<iostream>
using namespace std;

void insertarElemento(int[],int);
void inicializar_teclado(int[],int);
void mostrarVector(int[],int);
void random(int[],int);
int buscarMultiplos(int[],int);

int main(){
    int TL = 9, v[20];
    inicializar_teclado(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    TL += buscarMultiplos(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    return 0;
}

int buscarMultiplos(int v[],int TL){
    if(TL == 0) return 0;
    if(v[0]%100 == 0){
        insertarElemento(v,TL);
        v[0]+=1;
        return 1 + buscarMultiplos(&v[2],--TL);
    }else {
        return buscarMultiplos(&v[1],--TL);
    }
}

void insertarElemento(int v[],int TL){
    if(TL == 0) return;
    v[TL] = v[TL-1];
    insertarElemento(v,TL-1);
}

void random(int v[],int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++)
        v[i] = rand()%45;
}

void inicializar_teclado(int v[],int TL){
    if(TL == 0) return;
    cin >> v[0];
    inicializar_teclado(&v[1],TL-1);
}

void mostrarVector(int v[],int TL){
    if(TL == 0) cout<<"]"<<endl;
    else{
        cout<<v[0]<<" ";
        mostrarVector(&v[1],TL-1);
    }
}