#include<iostream>
using namespace std;

struct LIBRO {
    char titulo[50];
    char autor[50];
    char ISBN[50];
    double precio;
    int cantidadEnExistencia;
    int cantidadVendida;
    LIBRO* siguiente;
};
typedef LIBRO* Libro;



int main(){
    Libro inventario = NULL;
    cargarDatos(inventario);
    int opcion;
    do{
        cout<<"1. Ver Categalo Completo"<<endl;
        cout<<"2. Mostrar una posicion en especifico"<<endl;
        cout<<"3. Reemplazar datos de un posicion"<<endl;
        cout<<"4. Guardar y Salir"<<endl;
        cin>>opcion;
        cin.ignore();
        switch (opcion)
        {
            case 1: mostrarDatos(inventario);
                    break;
            case 2: cargarDatosPorTeclado(inventario);break;
            case 3: guardarEnArchivo(inventario);break;
        }
    }while(opcion!=3);
    return 0;
}

void mostrarDatos(Libro inventario){
    if(inventario == NULL){
        cout<<endl;
        return;
    }
    cout<<endl;
    cout<<"Titulo: "<<inventario->titulo<<endl;
    cout<<"Autor: "<<inventario->autor<<endl;
    cout<<"ISBN: "<<inventario->ISBN<<endl;
    cout<<"Precio: "<<inventario->precio<<endl;
    cout<<"cantidadEnExistencia: "<<inventario->cantidadEnExistencia<<endl;
    cout<<"cantidadVendida: "<<inventario->cantidadVendida<<endl;
    mostrarDatos(inventario->siguiente);
}