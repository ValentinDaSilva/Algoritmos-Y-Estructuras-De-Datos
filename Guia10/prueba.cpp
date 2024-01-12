#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream usuarios;
    usuarios.open("Guia10/archivo.txt");
    if(usuarios.fail()) cout << "No se pudo abrir el archivo"<<endl;
    if(usuarios.eof()) cout<<"Se intento leer mas halla del final del archivo"<<endl;
    if(usuarios.good()) cout<<"Puede escribir en el archivo"<<endl;
    usuarios.close();
    return 0;
}