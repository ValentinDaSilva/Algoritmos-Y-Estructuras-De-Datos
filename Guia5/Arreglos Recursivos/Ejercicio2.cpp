#include<iostream>
using namespace std;

void inicializar_teclado(int[],int);
void mostrarVector(int[],int);

int main(){
    int TL = 5,v[TL];
    inicializar_teclado(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    return 0;
}

void mostrarVector(int v[],int TL){
    if(TL == 0) cout<<"]"<<endl;
    else{
        cout<<v[0]<<" ";
        mostrarVector(&v[1],TL-1);
    }
}

void inicializar_teclado(int v[],int TL){
    if(TL == 0) return;
    cin >> v[0];
    inicializar_teclado(&v[1],TL-1);
}