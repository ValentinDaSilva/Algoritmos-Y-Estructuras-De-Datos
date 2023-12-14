#include<iostream>
using namespace std;

int potencia(int,int);

int main(){
    int numeroBase,numeroPotencia;
    cout<<"Ingrese un numero y la potencia la cual lo quiere elevar: ";cin>>numeroBase>>numeroPotencia;
    cout<<potencia(numeroBase,numeroPotencia)<<endl;
    return 0;
}

int potencia(int numeroBase,int numeroPotencia){
    int resultado = 1;
    for(int i = numeroPotencia; i > 0 ; i--){
        resultado *= numeroBase;
    }
    return resultado;
}