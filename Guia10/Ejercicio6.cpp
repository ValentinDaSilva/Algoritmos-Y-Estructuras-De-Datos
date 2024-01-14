#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int tamanio;

struct LIBRO {
    char titulo[50];
    char autor[50];
    char ISBN[50];
    double precio;
    int cantidadEnExistencia;
    int cantidadVendida;
};
typedef LIBRO* Libro;

void mostrarDatos(ifstream&,Libro);
void mostrarPosicion(Libro);
void modificarPosicion(ofstream&,int);
Libro buscarPosicion(fstream&,int);

int main(){
    Libro inventario = NULL;
    ifstream inventarioArchivo("inventario.bin",ios::binary);
    int opcion;
    int posicion; 
    do{
        cout<<"1. Ver Categalo"<<endl;
        cout<<"2. Mostrar una posicion especifica"<<endl;
        cout<<"3. Modificar Posicion"<<endl;
        cin>>opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1: //cargarDatos(inventario);
                mostrarDatos(inventarioArchivo,inventario);
                break;
        case 2: 
                cout<<"Ingrese la posicion: "; cin>>posicion;
                mostrarPosicion(buscarPosicion(inventarioArchivo,posicion));
                break;
        case 3: 
                fstream inventarioArchivoEscritura("inventario.bin",ios::in | ios::out | ios::binary);
                cout<<"Ingrese la posicion: "; cin>>posicion; cin.ignore();
                modificarPosicion(inventarioArchivoEscritura,posicion);
                break;
        }
        cout<<endl;
    }while(opcion!=4);
    // inventarioArchivo.close(); inventarioArchivoEscritura.close();
    return 0;
}

void modificarPosicion(fstream& archivo,int posicion){
    Libro libro = new LIBRO;
    cout<<"Titulo: ";cin.getline(libro->titulo,50);
    cout<<"Autor: ";cin.getline(libro->autor,50);
    cout<<"ISBN: ";cin.getline(libro->ISBN,50);
    cout<<"Precio: ";cin>>libro->precio;
    cout<<"cantidadEnExistencia: ";cin>>libro->cantidadEnExistencia;
    cout<<"cantidadVendida: ";cin>>libro->cantidadVendida;
    cin.ignore();
    int bytePosicion = (posicion - 1) * sizeof(LIBRO);
    archivo.seekp(bytePosicion,ios::beg);
    if(archivo.write((char*)libro,sizeof(LIBRO))) cout<<"Modificada con exito"<<endl;
    else cout<<"Ocurrio un error"<<endl;
}

void mostrarDatos(ifstream& inventarioArchivo,Libro inventario){
    if(inventarioArchivo.fail()){
        cout<<"No se pudo leer el archivo"<<endl;
        return;
    }
    Libro nuevo_libro; 
    inventarioArchivo.seekg(0,ios::end);
    tamanio = inventarioArchivo.tellg() / sizeof(LIBRO);
    inventarioArchivo.seekg(0,ios::beg);
    cout<<tamanio<<endl;
    int i = 0;
    while(i < tamanio){
        cout<<endl;
        inventarioArchivo.read((char*)nuevo_libro,sizeof(LIBRO));
        mostrarPosicion(nuevo_libro);
        i++;
    }
    return;
}

void mostrarPosicion(Libro libro){
    cout<<endl;
    cout<<"Titulo: "<<libro->titulo<<endl;
    cout<<"Autor: "<<libro->autor<<endl;
    cout<<"ISBN: "<<libro->ISBN<<endl;
    cout<<"Precio: "<<libro->precio<<endl;
    cout<<"cantidadEnExistencia: "<<libro->cantidadEnExistencia<<endl;
    cout<<"cantidadVendida: "<<libro->cantidadVendida<<endl;
    return;
}

Libro buscarPosicion(ifstream& inventarioArchivo,int posicion){
    Libro libroBuscado;
    int bytePosicion = (posicion - 1) * sizeof(LIBRO);
    inventarioArchivo.seekg(bytePosicion,ios::beg);
    inventarioArchivo.read((char*)libroBuscado,sizeof(LIBRO));
    return libroBuscado;
}

//    libros.push_back({"The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 12.75, 40, 8});
