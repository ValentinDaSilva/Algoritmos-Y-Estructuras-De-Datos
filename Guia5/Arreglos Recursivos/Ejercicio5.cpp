#include<iostream>
using namespace std;

void inicializar_teclado(int[],int);

int main(){
    int TL = 10 , v[TL];
    inicializar_teclado(v,TL);
    
    return 0;
}

void sumaDigitosIgualAElemento(int v[],int TL){
    int numero;
    cin>>numero;
    if(numero)
}

bool sumaDigitosAlgunElemento(int v[],int TL, int numero){
    if(TL == 0) return false;
    if(v[0] = sumaDigitos(numero)) return true;
    return sumaDigitosAlgunElemento(&v[1],TL-1,numero);
}

void inicializar_teclado(int v[],int TL){
    if(TL == 0) return;
    cin >> v[0];
    inicializar_teclado(&v[1],TL-1);
}

int sumaDigitos (int numero){
    if(numero < 10) return numero;
    return numero%10+sumaDigitos(numero/10);
}