#include <fstream>
#include <iostream>
using namespace std;
int main() {
  ifstream archivo;
  string nombre;
  cout<<"Ingrese el nombre del archivo: ";getline(cin,nombre);
  archivo.open(nombre.c_str());
if(archivo.fail()) cout<<"fallo en abrir el archivo"<<endl;
  // Leer el archivo
  char caracter;
  while (archivo.get(caracter)) {
    cout << caracter;
  }

  archivo.close();

  return 0;
}
