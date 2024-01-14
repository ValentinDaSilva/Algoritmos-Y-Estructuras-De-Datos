#include<iostream>
using namespace std;

struct LIBRO{
    string titulo;
    string autor;
    int ISBN;
    double precio;
    int cantidadEnExistencia;
    int cantidadVendida;
    LIBRO* siguiente;
};
typedef LIBRO* Libro;

int main(){
    Libro inventario;
    int* numero = new int;
    *numero = 5;
    cout<<*numero<<endl;
    return 0;
}