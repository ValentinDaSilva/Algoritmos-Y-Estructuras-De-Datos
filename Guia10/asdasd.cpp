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
    Libro inventario = NULL;


    return 0;
}

void cargarDatosPorTeclado(Libro& inventario){
    Libro nuevo_libro = new LIBRO;
    cout<<"Ingrese el titulo: "; getline(cin,nuevo_libro->titulo);
    if(nuevo_libro->titulo != "0"){
        cout<<"Ingrese el autor: "; getline(cin,nuevo_libro->autor);
        cout<<"Ingrese el ISBN: "; cin>>nuevo_libro->ISBN;
        cout<<"Ingrese la Cantidad De ejemplares existentes: "; cin>>nuevo_libro->cantidadEnExistencia;
        cout<<"Ingrese la cantidad vendida del libro: "; cin>>nuevo_libro->cantidadVendida;
        agregarLibro(inventario,nuevo_libro);
    }
    if(nuevo_libro->titulo != "0") cargarDatosPorTeclado(inventario);
}

void mostrarInventario(Libro inventario){
    if(inventario == NULL){
        cout<<endl;
        return;
    }
    mostrarInventario(inventario);
}

void agregarLibro(Libro& inventario, Libro nuevo_libro){
    Libro aux1 = inventario;
    Libro aux2;

    while(aux1 != NULL and nuevo_libro->titulo > inventario->titulo){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(aux1 == inventario) inventario = nuevo_libro;
    else aux2->siguiente = nuevo_libro;
    nuevo_libro->siguiente = aux1;
}