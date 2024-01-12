#include <fstream>
#include <iostream>
using namespace std;
int main() {
  ofstream archivo;
  string nombre;
  cout<<"Ingrese el nombre del archivo: ";getline(cin,nombre);
  archivo.open(nombre.c_str(),ios::app);
  archivo<<"Hola Como Estas"<<endl;
  archivo.close();
  archivo.clear();
  return 0;
}
