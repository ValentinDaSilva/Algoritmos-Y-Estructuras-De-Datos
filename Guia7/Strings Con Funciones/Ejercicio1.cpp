#include<iostream>
using namespace std;

void eliminarEspacios(string&);
void pasarAMinusculas(string&);

int main(){
    string nombre, correo;
    int posicionComa;
    cout<<"Ingrese su apellido, seguido de una coma y su nombre"<<endl;
    cout<<"Ejemplo: Da Silva Catela, Valentin"<<endl;
    getline(cin,nombre);
    eliminarEspacios(nombre);
    pasarAMinusculas(nombre);
    posicionComa = nombre.find(',');
    correo = correo + nombre[posicionComa + 1];
    correo = correo + nombre.substr(0,posicionComa);
    correo += "@frsf.utn.edu.ar";
    cout<<correo<<endl;
    return 0;
}

void pasarAMinusculas(string& nombre){
    int i = 0;
    while(nombre[i] != '\0'){
        if(isupper(nombre[i])) nombre[i] = tolower(nombre[i]);
        i++;
    }
}

void eliminarEspacios(string& nombre){
    int indice;
    do{
        indice = nombre.find(' ');
        if(indice >= 0 and indice < nombre.length()) nombre.erase(indice,1);
    }while(indice >= 0 and indice < nombre.length());
}