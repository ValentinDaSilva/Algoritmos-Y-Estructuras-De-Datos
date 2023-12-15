#include<iostream>
using namespace std;

int maxDigito(int);

int main(){
    int numero;
    cout<<"Ingrese un numero para calcular su maximo digito: ";cin>>numero;
    cout<<"El digito mas alto es: "<<maxDigito(numero)<<endl;
    return 0;
}

int maxDigito(int numero){
    if(numero<10) return numero;
    int x = maxDigito(numero/10);
    if(x > numero%10) return x;
    return numero%10;
}