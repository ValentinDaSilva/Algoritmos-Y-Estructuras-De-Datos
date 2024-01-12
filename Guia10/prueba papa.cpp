#include <fstream>
#include <iostream>
using namespace std;
int main() {
  ifstream archivo;
  string nombre;
  cout<<"Ingrese el nombre del archivo: ";getline(cin,nombre);
  nombre = "/home/valedasilvacatelavdc/Algoritmos-Y-Estructuras-De-Datos/Guia10/" + nombre;
  archivo.open(nombre.c_str(),ios::app);
  if(archivo.fail()) cout<<"error al abrir el archivo."<<endl;
  char caracter;
  do{
    archivo >> caracter;
    cout<<caracter;
  }while(!archivo.eof());
  cout<<endl;
  archivo.close();
  return 0;
}
