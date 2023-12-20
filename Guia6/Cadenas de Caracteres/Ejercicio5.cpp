#include<iostream>
using namespace std;

int main(){
    char texto[100];
    cout<<"Ingrese el texto para contar palabras y caracteres: ";cin.getline(texto,100);
    cout<<"Caracteres: "<<cantidadCaracteres(texto)<<endl;
    cout<<"Palabras: "<<cantidadPalabras(texto)<<endl;
    return 0;
}

int cantidadCaracteres(char v[]){
    if(v[0] = '\0') return 0;
    return 1 + cantidadCaracteres(&v[1]);
}

int cantidadPalabras(char v[]){
    if(v[0] = '\0') return 1;
    if(v[0] == ' ') return 1 + cantidadCaracteres(&v[1]);
    return cantidadCaracteres(&v[1]);
}