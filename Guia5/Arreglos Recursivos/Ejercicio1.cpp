#include<iostream>
using namespace std;

void inicializar_teclado(int[],int);

int main(){
    int TL = 5,v[TL];
    inicializar_teclado(v,TL);
    return 0;
}

void inicializar_teclado(int v[],int TL){
    if(TL == 0) return;
    cin >> v[0];
    inicializar_teclado(&v[1],TL-1);
}