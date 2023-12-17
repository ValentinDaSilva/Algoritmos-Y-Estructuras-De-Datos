#include<iostream>
using namespace std;

void inicializar_teclado(int[],int);
bool todosIguales(int[],int);

int main(){
    int TL = 5,v[TL] = {2,2,2,2,2};
    inicializar_teclado(v,TL);
    cout<<todosIguales(v,TL)<<endl;
    return 0;
}

bool todosIguales(int v[],int TL){
    if(TL == 1 || TL == 0) return true;
    if(v[0] != v[1]) return false;
    else return todosIguales(&v[1],TL-1);
}

void inicializar_teclado(int v[],int TL){
    if(TL == 0) return;
    cin >> v[0];
    inicializar_teclado(&v[1],TL-1);
}