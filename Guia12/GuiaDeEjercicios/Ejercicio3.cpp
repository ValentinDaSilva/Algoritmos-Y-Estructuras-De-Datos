#include<iostream>
#include<ctime>
using namespace std;

struct Punto{
    double x;
    double y;
};

struct Nodo
{
    string nombre = "Sin identificar";
    Punto punto = {0,0};
    int registro = rand()%100;
    Nodo* siguiente = nullptr;
};
typedef Nodo* Ciudad;

void cargarCiudades(Ciudad&);
void mostrarLista(Ciudad);
Ciudad ciudadConMenorRegistro(Ciudad);
bool estaOrdenada(Ciudad);
void eliminar(Ciudad&,Ciudad);
void eliminarCoordenadasNegativas(Ciudad&);

int main(){
    srand(time(NULL));
    Ciudad ciudad = nullptr;
    cargarCiudades(ciudad);
    mostrarLista(ciudad);
    cout<<ciudadConMenorRegistro(ciudad)->nombre<<endl;
    (estaOrdenada(ciudad))? cout<<"Esta ordenada alfabeticamente"<<endl : cout<<"No esta ordenada alfabeticamente"<<endl;
    eliminarCoordenadasNegativas(ciudad);
    mostrarLista(ciudad);
    return 0;
}

void eliminarCoordenadasNegativas(Ciudad& ciudad){
    if(ciudad == nullptr) return;
    if(ciudad->punto.x < 0 or ciudad->punto.y < 0) eliminar(ciudad,ciudad);
    eliminarCoordenadasNegativas(ciudad->siguiente);
}

void eliminar(Ciudad& ciudad, Ciudad nodo){
    if(ciudad == nodo){
        Ciudad aux = ciudad;
        ciudad = ciudad->siguiente;
        delete aux;
        return;
    }
    eliminar(ciudad->siguiente, nodo);

}

bool estaOrdenada(Ciudad ciudad){
    if(ciudad->siguiente == nullptr) return true;
    if(ciudad->nombre > ciudad->siguiente->nombre) return false;
    return estaOrdenada(ciudad->siguiente);
}

Ciudad ciudadConMenorRegistro(Ciudad ciudad){
    if(ciudad->siguiente == nullptr) return ciudad;
    Ciudad nodo = (ciudadConMenorRegistro(ciudad->siguiente));
    if(ciudad->registro < nodo->registro){
        return ciudad;
    }
    return nodo;
}

void cargarCiudades(Ciudad& ciudad){
    int i = 0;
    string ciudades[] = {
        "Venado Tuerto", "Santa Fe","San Lorenzo", "Rosario","Rafaela",
        "Granadero Baigorria","Galvez", "Firmat", "Esperanza", "Capitan Bermúdez"
    };
    for(int i = 0; i < 10; i++){
        Ciudad nuevo_nodo = new Nodo;
        nuevo_nodo->nombre = ciudades[i];
        nuevo_nodo->punto = {double(rand()%10 - 1),double(rand()%15 - 2)};
        nuevo_nodo->siguiente = ciudad;
        ciudad = nuevo_nodo;
    };
}

void mostrarLista(Ciudad lista){
    if(lista == nullptr){
         cout<<endl;
         return ;
    }
    cout<<lista->nombre<<" "<<lista->registro<<" Puntos: "<<lista->punto.x<<" "<<lista->punto.y<<endl;
    mostrarLista(lista->siguiente);
}