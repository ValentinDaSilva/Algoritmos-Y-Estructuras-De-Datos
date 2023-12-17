#include<iostream>
#include "Ejercicio5.h"
using namespace std;

void inicializar_teclado(int[],int);
void sumaDigitosIgualAElemento(int[],int);
bool sumaDigitosAlgunElemento(int[],int,int);
int sumaDigitos(int);

int main(){
    int TL = 10 , v[TL];
    inicializar_teclado(v,TL);
    sumaDigitosIgualAElemento(v,TL);
    return 0;
}

void sumaDigitosIgualAElemento(int v[],int TL){
    int numero;
    cin>>numero;
    if(sumaDigitosAlgunElemento(v,TL,numero)) cout<<numero<<endl;
    else{
        sumaDigitosIgualAElemento(v,TL);
    }
}

bool sumaDigitosAlgunElemento(int v[],int TL, int numero){
    if(TL == 0) return false;
    if(v[0] == sumaDigitos(numero)) return true;
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