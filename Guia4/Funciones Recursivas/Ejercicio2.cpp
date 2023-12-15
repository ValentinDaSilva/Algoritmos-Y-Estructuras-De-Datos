#include<iostream>
using namespace std;

int suma(int);
int sumaPares(int);

int main(){
    int numero;
    cout<<"Ingrese los primeros N enteros a sumar: ";cin>>numero;
    cout<<"Suma de los primeros N numeros: "<<suma(numero)<<endl;
    cout<<"Suma de positivos pares desde N hasta 2: "<<sumaPares(numero)<<endl;
    return 0;
}

int suma(int numero){
    if(numero == 1) return 1;
    return numero + suma(numero-1);
}

int sumaPares(int numero){
    if(numero < 2) return 0;
    if(numero == 2) return 2;
    if(numero%2 == 0) return numero + sumaPares(numero-2);
    return sumaPares(numero-1);
}
