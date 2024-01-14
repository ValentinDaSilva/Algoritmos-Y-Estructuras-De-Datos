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

void cargarDatosPorTeclado(Libro&);
void agregarLibro(Libro&,Libro);
void guardarEnArchivo(Libro);
Libro cargarDatos(Libro&);
void mostrarDatos(ifstream&,Libro);

int main(){
    Libro inventario = NULL;
    ifstream inventarioArchivo("inventario.bin",ios::binary);
    int opcion;
    do{
        cout<<"1. Ver Categalo"<<endl;
        cout<<"2. Cargar nuevo libro"<<endl;
        cout<<"3. Guardar y Salir"<<endl;
        cin>>opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1: //cargarDatos(inventario);
                mostrarDatos(inventarioArchivo,inventario);
                break;
        case 2: cargarDatosPorTeclado(inventario);break;
        case 3: guardarEnArchivo(inventario);break;
        }
        cout<<endl;
    }while(opcion!=3);
    return 0;
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
        cout<<"Titulo: "<<nuevo_libro->titulo<<endl;
        cout<<"Autor: "<<nuevo_libro->autor<<endl;
        cout<<"ISBN: "<<nuevo_libro->ISBN<<endl;
        cout<<"Precio: "<<nuevo_libro->precio<<endl;
        cout<<"cantidadEnExistencia: "<<nuevo_libro->cantidadEnExistencia<<endl;
        cout<<"cantidadVendida: "<<nuevo_libro->cantidadVendida<<endl;
        i++;
    }
    return;
}

Libro cargarDatos(Libro& inventario){
    Libro nuevo_libro = NULL;
    ifstream archivo("inventario.bin", ios::app|ios::binary);
    if(archivo.fail()) cout<<"No se puede abrir el archivo"<<endl;
    else{
        archivo.seekg(0,ios::end);
        tamanio = archivo.tellg() / sizeof(LIBRO);
        archivo.seekg(0,ios::beg);
        nuevo_libro = new LIBRO[tamanio];
        int i = 0;
        while( i < tamanio ){
            archivo.read((char*)nuevo_libro,sizeof(LIBRO)*tamanio);
            i++;
        }
        archivo.close(); 
    }
    return nuevo_libro;
}

void guardarEnArchivo(Libro inventario){
    if(inventario != NULL){
        ofstream archivo("inventario.bin",ios::app|ios::binary);
        archivo.write((char*)inventario,sizeof(LIBRO));
        archivo.close();
    }
}

void cargarDatosPorTeclado(Libro& inventario){
    cout<<"Ingrese los datos de los libros que desea registrar: (Finalice con titulo: 0)"<<endl ;
    Libro libro = NULL;
    do{
        libro = new LIBRO;
        cout<<"Titulo: ";cin.getline(libro->titulo,50);
        if(strcmp(libro->titulo,"0")){
            cout<<"Autor: ";cin.getline(libro->autor,50);
            cout<<"ISBN: ";cin.getline(libro->ISBN,50);
            cout<<"Precio: ";cin>>libro->precio;
            cout<<"cantidadEnExistencia: ";cin>>libro->cantidadEnExistencia;
            cout<<"cantidadVendida: ";cin>>libro->cantidadVendida;
            cin.ignore();
            guardarEnArchivo(libro);
        }
    }while(strcmp(libro->titulo,"0"));
}

/* 
libros.push_back({"Cien años de soledad", "Gabriel García Márquez", "9780141184999", 19.99, 50, 10});
    libros.push_back({"To Kill a Mockingbird", "Harper Lee", "9780061120084", 15.50, 30, 5});
    libros.push_back({"The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 12.75, 40, 8});
    libros.push_back({"1984", "George Orwell", "9780451524935", 14.99, 60, 12});
    libros.push_back({"The Catcher in the Rye", "J.D. Salinger", "9780241950425", 11.25, 25, 3});
    libros.push_back({"The Hobbit", "J.R.R. Tolkien", "9780547928227", 22.00, 20, 6});
    libros.push_back({"Pride and Prejudice", "Jane Austen", "9780141199078", 16.50, 35, 7});
    libros.push_back({"Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "9780590353427", 27.99, 55, 15});
    libros.push_back({"The Lord of the Rings", "J.R.R. Tolkien", "9780618640157", 45.00, 15, 2});
    libros.push_back({"The Da Vinci Code", "Dan Brown", "9780307474278", 18.75, 48, 9});
 */