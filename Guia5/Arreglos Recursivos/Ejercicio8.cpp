#include<iostream>
using namespace std;

void inicializar_teclado(int[],int);
bool todosDistintos(int[],int);
bool distintoATodos(int[],int,int);

int main(){
    int TL = 5,v[TL];
    inicializar_teclado(v,TL);
    cout<<todosDistintos(v,TL)<<endl;
    return 0;
}

bool todosDistintos(int v[],int TL){
    if(TL == 0) return true;
    if(!distintoATodos(&v[1],TL-1,v[0])) return false;
    return todosDistintos(&v[1],TL-1);
}

bool distintoATodos(int v[],int TL,int elemento){
    if(TL == 0) return true;
    if(v[0] == elemento) return false;
    return distintoATodos(&v[1],TL-1,elemento);
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