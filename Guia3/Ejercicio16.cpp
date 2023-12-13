#include<iostream>
using namespace std;

int main(){
    int numero;
    char caracter;
    cout<<"Ingrese un numero: ";cin>>numero;
    cout<<"Ingrese un caracter: ";cin>>caracter;
    for(int i = 0; i < numero; i++){
        cout<<caracter;
    }
    return 0;
}