#include<iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

typedef Nodo* Pila; 

void inicializarPila(Pila&);
bool estaVacia(Pila);
void apilar(Pila&,int);
void desapilar(Pila&);
int tope(Pila);
int tamanioPila(Pila);

int main(){
    Pila miPila;
    inicializarPila(miPila);
    apilar(miPila,5);
    apilar(miPila,10);
    apilar(miPila,15);

    cout<<tope(miPila)<<endl;
    desapilar(miPila);
    cout<<tope(miPila)<<endl;

    return 0;
}

void inicializarPila(Pila& miPila){
    miPila = nullptr;
}

bool estaVacia(Pila miPila){
    return miPila == nullptr;
}

void apilar(Pila& miPila, int elemento){
    Pila nuevo_elemento = new Nodo;
    nuevo_elemento->dato = elemento;
    nuevo_elemento->siguiente = miPila;
    miPila = nuevo_elemento;
}

void desapilar(Pila& miPila){
    Pila aux = miPila;
    miPila = miPila->siguiente;
    delete aux;
}

int tope(Pila miPila){
    return miPila->dato;
}

int tamanioPila(Pila miPila){
    if(estaVacia(miPila)) return 0;
    return 1 + tamanioPila(miPila->siguiente);
}