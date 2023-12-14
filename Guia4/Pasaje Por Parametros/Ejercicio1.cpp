#include<iostream>
using namespace std;

void linea(int,char);

int main(){
    int numero;
    char caracter;
    cout<<"Ingrese un numero: ";cin>>numero;
    cout<<"Ingrese un caracter: ";cin>>caracter;
    linea(numero,caracter);
    return 0;
}

void linea(int numero, char caracter){
    for(int i = 0; i < numero; i++){
        cout<<caracter;
    }
}