#include<iostream>
using namespace std;

void invertir(string&);

int main(){
    string cadena;
    getline(cin,cadena);
    invertir(cadena);
    cout<<cadena<<endl;
    return 0;
}

void invertir(string& cadena){
    char* inicio = &cadena[0];
    char* final = &cadena[cadena.length()-1];
    char aux;
    while(inicio < final){
        aux = *inicio;
        *inicio = *final;
        *final = aux;
        inicio = inicio + 1;
        final = final -1;
    }
}