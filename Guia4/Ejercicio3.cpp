#include<iostream>
using namespace std;

int cantDigitos(int);

int main(){
    int numero;
    cout<<"Ingresa un numero para saber la cantidad de digitos: ";cin>>numero;
    cout<<cantDigitos(numero);
    return 0;
}

int cantDigitos(int numero){
    int contador = 0;
    while(numero > 0){
        contador++;
        numero/=10;
    }
    return contador;
}